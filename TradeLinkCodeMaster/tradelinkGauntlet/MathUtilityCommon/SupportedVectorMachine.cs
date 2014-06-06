using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using svmcallcsharp;
using System.ComponentModel;
using System.Runtime.InteropServices;
using System.IO;

namespace MathUtilityCommon
{
    public class SupportedVectorMachine
    {
        svm_model _mdl;
        IntPtr _pMdl;
        // this is the full training set
        Queue< List<decimal>> _dat = new Queue<List<decimal>>();
        // native traning set used in the last retrain.
        public svm_problem _scldData;

        public svm_parameter _param;
        public gridsearch_parameter _paramGS;
        public List<svm_scale> _sclParams = new List<svm_scale>();
        [Description("most current case with unknown class attribution")]
        public List<Decimal> CurrentCase { get { int count = _currCases.Count; return _currCases.ElementAt(count-1); } }
        Queue<List<Decimal>> _currCases = new Queue<List<decimal>>();
        [Description("number of current cases with class id TBD")]
        public int numCurrentCases { get { return _currCases.Count; } }
        [Description("number of cases for traning")]
        public int nCases {get {return _nCases;} set {_nCases = value;} }
        [Description("Number of features in each case")]
        public int nFeatures {get {return _nFeatures; } set {_nFeatures = value;} }
        int _nCases;
        int _nFeatures;
        [Description("number time of retrains for each full data set replacement")]
        // this also used as cross validate folds
        public int RetrainFrequency { get { return _retrainFreq; } set { _retrainFreq = value; } }
        int _retrainFreq;
        // keep track of which case location a new case shall overide. 
        int _ovrCsIdx;
        [Description("Upper scale limit")]
        public double UpperScaleLimit { get { return _scaleUpper; } set { _scaleUpper = value; } }
        double  _scaleUpper;
        [Description("Lower scale limit")]
        public double LowerScaleLimit { get { return _scaleLower; } set { _scaleLower = value; } }
        double _scaleLower;
        string _exportDataFileName = "./TestParam/svmtest.dat";
        public string ExportFile { get { return _exportDataFileName; } set { _exportDataFileName = value; } }
        System.IO.StreamWriter _fs;
        [Description("cross validation accruracy")]
        public double crossVldAccuracy { get { return _crsVldAcrcy; } set { _crsVldAcrcy = value; } }
        double _crsVldAcrcy = 0;
        [Description("Prediction accruracy")]
        public double PredictionAccuracy { get { return _prdctAcry; } set { _prdctAcry = value; } }
        double _prdctAcry = 0;
        [Description("AutoTrain flag")]
        public bool autoTrain { get { return _autoTrn; } set { _autoTrn  = value; } }
        bool _autoTrn;
        [Description("Cross Validation flag")]
        public bool doCrossValidate { get { return _doCrossValidate ; } set { _doCrossValidate  = value; } }
        // set this true for doing cross validation
        bool _doCrossValidate;
        [Description("AutoGridSearch flag")]
        public bool autoGridSearch { get { return _autoGridSearch; } set { _autoGridSearch = value; } }
        bool _autoGridSearch;
        [Description("reset seed of random in cross validation ")]
        public bool ResetSeed { get { return _setSeed; } set { _setSeed = value; } }
        bool _setSeed;
        // set this true for writing out debug information to file
        public bool _debug;
        public double best_rate;
        public bool _udtScale = true;
        [Description("Flag for updating scales of Variables")]
        public bool updateScale { get { return _udtScale; } set { _udtScale = value; } }

        public struct gridsearch_parameter
        {
            /// double
            public double gamma_start;

            /// double
            public double gamma_end;

            /// double
            public double gamma_step;


            /// double
            public double C_start;

            /// double
            public double C_end;

            /// double
            public double C_step;
        }

        public bool isValid()
        {
            return _dat.Count >= _nCases;
        }

        public SupportedVectorMachine(int nCases, int nfeatures,int retrainFreq, bool autotrain = true,bool debug = false)
        {
            _nCases = nCases;
            _nFeatures = nfeatures;
            _retrainFreq = retrainFreq;
            _scaleLower = 0;
            _scaleUpper = 1;
            _ovrCsIdx = 0;
            _autoTrn = autotrain;
            _doCrossValidate = true;
            _debug = debug;
            _autoGridSearch = false;
            _setSeed = true;
            if(_debug)
            _fs = new System.IO.StreamWriter(_exportDataFileName);
            /*
            int rem = 0,quotient;
            quotient = Math.DivRem(_nCases, _retrainFreq, out rem);
            if (rem != 0) throw new Exception("number of cases should be multiple of training frequency");
             */
            // allocate space for data
            svm_node Nd = new svm_node();
            _scldData.y = Marshal.AllocHGlobal(sizeof(double) * 2*_nCases);
            _scldData.x = Marshal.AllocHGlobal(Marshal.SizeOf(_scldData.x) * 2 * _nCases);                
            for (int i = 0; i < 2*_nCases; i++)
            {
                IntPtr pCs = Marshal.AllocHGlobal(Marshal.SizeOf(Nd) * (_nFeatures+1));
                Marshal.WriteIntPtr(_scldData.x, i * Marshal.SizeOf(_scldData.x), pCs);
            }
            _scldData.l = 0;
            _param.C = 1;
            _param.svm_type = 1; // NU_SVC
            _param.kernel_type = 2;
            _param.gamma = 1.0/(double)_nFeatures;
            _param.eps = 0.00001;
            _param.nu = 0.5;
            _param.cache_size = 100;
            _param.shrinking = 1;
            _param.probability = 0;
            _param.nr_weight = 0;

        }

        ~SupportedVectorMachine()
        {
            if (_debug)
            _fs.Close();
            // deallocate the unmanaged memory allocated in constructor..
            svmcallcs.svm_free_and_destroy_model(ref _pMdl);
            Marshal.FreeHGlobal(_scldData.y);          
            for (int i = 0; i < 2*_nCases; i++)
            {
                IntPtr pCs = Marshal.ReadIntPtr(_scldData.x, i*Marshal.SizeOf(_scldData.x));
                Marshal.FreeHGlobal(pCs);
            }
            Marshal.FreeHGlobal(_scldData.x);
        }

        static void allocateWorkSpace(ref svm_problem data, int nCases, int nFeatures)
        {
            svm_node Nd = new svm_node();
            data.y = Marshal.AllocHGlobal(sizeof(double) * nCases);
            data.x = Marshal.AllocHGlobal(Marshal.SizeOf(data.x) * nCases);
            for (int i = 0; i < nCases; i++)
            {
                IntPtr pCs = Marshal.AllocHGlobal(Marshal.SizeOf(Nd) * (nFeatures + 1));
                Marshal.WriteIntPtr(data.x, i * Marshal.SizeOf(data.x), pCs);
            }
            return;
        }

        static void releaseWorkSpace(ref svm_problem data, int nCases = 0)
        {
            // assume
            if (nCases == 0) nCases = data.l;
            Marshal.FreeHGlobal(data.y);
            for (int i = 0; i < nCases; i++)
            {
                IntPtr pCs = Marshal.ReadIntPtr(data.x, i * Marshal.SizeOf(data.x));
                Marshal.FreeHGlobal(pCs);
            }
            Marshal.FreeHGlobal(data.x);
        }


        // this setup and add to and replace training set cases in  _data, which would be included in retrain
        public void addCase(List<decimal> features, int classId)
        {
            // last elements is the predicted class
            if (features.Count < _nFeatures) throw new Exception("encountered non compatible case with this model");
            
            if (_debug)
            {
                string line = classId.ToString();
                // debug.. logging each case
                line += " ";
                for (int i = 0; i < _nFeatures; i++)
                {
                    line += (i + 1).ToString();
                    line += ":";
                    line += features[i].ToString("F8");
                    line += " ";
                }
                _fs.WriteLine(line);
                _fs.Flush();
            }
         
            List<decimal> cs = new List<decimal>(features.Count+1);
            cs.Add((decimal)classId);
            cs.AddRange(features);
            _dat.Enqueue(cs);

            if (_dat.Count > 2*_nCases) // keep two sets of training data
                _dat.Dequeue();

            _ovrCsIdx++;
            if (_ovrCsIdx == _nCases)
            {
                _ovrCsIdx = 0;
            }
                
            int rem = 0,qt = 0;
            qt = Math.DivRem(_ovrCsIdx, _nCases/_retrainFreq, out rem);
            if (rem == 0 && _dat.Count >= _nCases && _autoTrn) retrain(_nCases);
        }

        /* this also turns the first current case into a training case and adds it to the training set, drops it from current case set.
         * class is always that of the first current case. 
         */
        public void setCurrentClass(int clslId)
        {
            List<decimal> caseFeatures = _currCases.Dequeue();
            addCase(caseFeatures, clslId);
        }
        //  input number of cases to include in retrain. cases at the head of the traning set queue, i.e., with less sequence numbers, has precedance over those at the tail 
        public void retrain(int nFirstCases)
        {
            if (nFirstCases > _nCases) throw new Exception("invalid input number of cases");
            // refresh the unmanaged memories
            svmcallcs.svm_free_and_destroy_model(ref _pMdl);
            Dictionary<int, int> clsCnt = new Dictionary<int, int>();
            svm_node Nd = new svm_node();
            svm_scale scl = new svm_scale();
            scl.upper = _scaleUpper;
            scl.lower = _scaleLower;
            if (_scldData.l > 0 && nFirstCases == _nCases)
            {
                predictionAccuracy();
                // we use the current scale factors, so prior predictions shall be repeated in cross validation
                if (_doCrossValidate)
                {
                    loadRecentData(nFirstCases + _nCases / _retrainFreq, ref clsCnt, true);
                    do_cross_validation(_retrainFreq + 1);
                }
            }
            // scale the data and update the scales.. 
            double[] cId = { 0 };
            loadRecentData(nFirstCases, ref clsCnt);
            if (_udtScale)
            {
                _sclParams.Clear();
                _sclParams.Insert(0, scl);
                svmcallcs.svm_scale(ref _scldData, ref _sclParams, false);
            }
            // debbugging info.. report the scales and dumping the scaled data
            
            string line = "Scales:";
            
            if (_debug)
            {
                _fs.WriteLine(line);
                line = "";
                for (int i = 0; i < _sclParams.Count; i++)
                {
                    line = i.ToString();
                    line += " ";
                    line += _sclParams[i].lower.ToString("F8");
                    line += " ";
                    line += _sclParams[i].upper.ToString("F8");
                    line += " ";
                    _fs.WriteLine(line);
                }
                _fs.Flush();
                line = "Scaled Data:";
                _fs.WriteLine(line);
            
                double[] clss = new double[nFirstCases];
                double[] vls = new double[_nFeatures];
                Marshal.Copy(_scldData.y,clss,0,nFirstCases);
                for (int i = 0; i < nFirstCases; i++)
                {
                    IntPtr NdPtr = Marshal.ReadIntPtr(_scldData.x, i * Marshal.SizeOf(_scldData.x));
                    Nd = (svm_node)Marshal.PtrToStructure(NdPtr, typeof(svm_node));
                    line = ((int)clss[i]).ToString();
                    line += " ";
                    while (Nd.index != -1)
                    {   
                        if (Nd.value != 0)
                        {
                            line += Nd.index.ToString();
                            line += ":";
                            line += Nd.value.ToString("F8");
                            line += " ";
                        }
                        NdPtr += Marshal.SizeOf(Nd);
                        Nd = (svm_node)Marshal.PtrToStructure(NdPtr, typeof(svm_node)); 
                    }
                    _fs.WriteLine(line);
                    _fs.Flush();
                }
            }
            
            // for nu-svc update the parameter. see http://www.csie.ntu.edu.tw/~cjlin/papers/libsvm.pdf page 4. for now we take 5/6 of the uppper bound. 
            int n1 = 0,n2 = 0;
            if (_param.svm_type == 1)
            {
                _param.nu = 0.5;
                for (int i = 0; i < clsCnt.Count; i++)
                {
                    n1 = clsCnt.ElementAt(i).Value;
                    for (int j = i + 1; j < clsCnt.Count; j++)
                    {
                        n2 = clsCnt.ElementAt(j).Value;
                        double nu1 = 5.0 * Math.Min((double)n1, (double)n2) /3.0;
                        nu1 /= (double)(n1 + n2);
                        _param.nu = Math.Min(_param.nu,nu1);
                    }
                }
            }
            if (_autoGridSearch)
            {
                grid_search();
            }
            // train
            String  errmsg = svmcallcs.svm_check_parameter(ref _scldData, ref _param);
            if (errmsg != null ) throw new Exception(errmsg);
            
            if (_debug)
            {
                line = "Training with nu = ";
                line += _param.nu.ToString();
                _fs.WriteLine(line);
                _fs.Flush();
            }
            
            _pMdl = svmcallcs.svm_train(ref _scldData, ref _param);
            _mdl = (svm_model) Marshal.PtrToStructure(_pMdl, typeof(svm_model));
             
            //save current model
            //svmcallcs.svm_save_model(_exportMdlFileName, ref _mdl);
        }
        // load soecfied number of most recent cases and return counts of cases in each class
        void loadRecentData(int nCases, ref Dictionary<int, int> clsCnt, bool scale = false)
        {
            clsCnt.Clear();
            _scldData.l = nCases;
            double[] cId = { 0 };
            svm_node Nd = new svm_node();
            IntPtr pCls = _scldData.y;
            int nTotCases = _dat.Count;
            if (nTotCases < nCases) throw new Exception("not enough data in object to load");
            for (int i = 0; i < nCases; i++)
            {
                cId[0] = (double)_dat.ElementAt(nTotCases - i - 1)[0];
                if (!clsCnt.ContainsKey((int)cId[0])) clsCnt.Add((int)cId[0], 0);
                clsCnt[(int)cId[0]]++;
                Marshal.Copy(cId, 0, pCls, 1);
                pCls += sizeof(double);
                IntPtr pFtr = Marshal.ReadIntPtr(_scldData.x, i * Marshal.SizeOf(pCls));
                svm_node[] nodes = new svm_node[_nFeatures+1];
                List<decimal> myCase = new List<decimal>();
                for (int j = 1;j < _nFeatures+1; j++) 
                    myCase.Add(_dat.ElementAt(nTotCases - i - 1)[j]);
                if (scale)
                    scaleCase(ref nodes, ref myCase);
                else
                {
                    for (int j = 0; j < _nFeatures; j++)
                    {
                        nodes[j].index = j + 1;
                        nodes[j].value = (double)myCase[j];
                    }
                }
                for (int j = 0; j < _nFeatures; j++) {
                    Marshal.StructureToPtr(nodes[j], pFtr, true);
                    pFtr += Marshal.SizeOf(nodes[j]);
                }
                Nd.index = -1;
                Nd.value = 0;
                Marshal.StructureToPtr(Nd, pFtr, true);
            }
        }

        public void predictionAccuracy()
        {
            int cid = 0, cidp = 0;
            int pcorrect = 0, np = 0; 
            // calc accuracies for the set of cases since last retrain
            string line = "Last Predictions:";
            int nTotCases = _dat.Count;
            for (int i = 0; i < (_nCases/_retrainFreq); i++)
            {
                cid = (int)_dat.ElementAt( nTotCases - 1 - i)[0];
                if (_dat.ElementAt(nTotCases - 1 - i).Count == _nFeatures + 2)
                {
                    // prediction made for this case
                    np++;
                    cidp = (int)_dat.ElementAt(nTotCases - 1 - i)[_nFeatures + 1];
                    if (cid == cidp) pcorrect++;
                    if (_debug)
                    {
                        line += cidp.ToString();
                        line += " ";
                    }
                }
            }
            //     if (np != nFold) throw new Exception("Missing predicted cases");
            if (np > 0 && _debug) _fs.WriteLine(line);
            _prdctAcry = (double)pcorrect / np;
        }

        public void do_cross_validation(int nFold) // input default to retrain frequency
        {
            int nCases = _scldData.l;
            double[] clss = new double[nCases];
            double[] cls1 = new double[nCases];
            svmcallcs.svm_cross_validation(ref _scldData, ref _param, nFold, ref cls1[0], _setSeed);
            Marshal.Copy(_scldData.y, clss, 0, nCases);
            int ncorrect = 0;
            for (int i = 0; i < nCases; i++)
            {
                if (clss[i] == cls1[i]) ncorrect++;
            }
            _crsVldAcrcy = (double)ncorrect / (double)nCases;
        }

        public void grid_search()
        {
            grid_search(_paramGS.C_start, _paramGS.C_end, _paramGS.C_step, _paramGS.gamma_start, _paramGS.gamma_end, _paramGS.gamma_step);
        }

        public void grid_search(double c_begin, double c_end, double c_step, double g_begin, double g_end, double g_step)
        {
            int len_c = (int)((c_end - c_begin) / c_step + 1);
            int len_g = (int)((g_end - g_begin) / g_step + 1);
            double[] c_seq = new double[len_c];
            double[] g_seq = new double[len_g];
            int i = 0;
            for (i = 0; i < len_c; i++)
            {
                c_seq[i] = Math.Pow(2, c_begin + i * c_step);
            }
            for (i = 0; i < len_g; i++)
            {
                g_seq[i] = Math.Pow(2, g_begin + i * g_step);
            }
            double origRate = _crsVldAcrcy;
            double best_c = 0, best_g = 0;
            best_rate = 0;
            int j = 0;
            
            for (i = 0; i < len_c; i++)
                for (j = 0; j < len_g; j++)
                {
                    _param.C = c_seq[i];
                    _param.gamma = g_seq[j];
                    do_cross_validation(_retrainFreq);
                    if (_crsVldAcrcy > best_rate)
                    {
                        best_c = _param.C;
                        best_g = _param.gamma;
                        best_rate = _crsVldAcrcy;
                    }
                }
            _param.C = best_c;
            _param.gamma = best_g;
            _crsVldAcrcy = origRate;
            
            if (_debug)
            {
                StreamWriter param_output = new StreamWriter(@"./svm/libsvm/windows/svm_parameter_choose.txt"); //把参数选取结果输出到txt文件中
                param_output.WriteLine("Best:c={0},g={1},rate={2}", best_c, best_g, best_rate);
                param_output.Close();
            }
        }
        // predict based on last current case. save the result of prediction 
        public int predict()
        {
           // use current case to predict..
            svm_node[] nodes = new svm_node[_nFeatures+1];
            scaledCurrentCase(ref nodes);
            nodes[_nFeatures].index = -1;
            nodes[_nFeatures].value = 0;
            int ret =  (int)svmcallcs.svm_predict(ref _mdl, nodes);
            // save Predicted class as last element of each case. 
            if(CurrentCase.Count == _nFeatures) CurrentCase.Add((decimal)ret);
            else CurrentCase[_nFeatures] = (decimal)ret;
            /*
            if (_debug)
            {
                string line = "prediction check:";
                line += nodes[0].value.ToString();
                line += ":";
                line += ret.ToString();
                _fs.WriteLine(line);
            }
             * */
            return ret;
        }
        // operate on last curreent case
        public void scaledCurrentCase(ref svm_node[] nds)
        {
            List<decimal> cCaseFeatures = CurrentCase;
            scaleCase(ref nds, ref cCaseFeatures);
        }
        // scale the case data with current scale parameters and return the results in the node list.
        public void scaleCase(ref svm_node[] nds, ref List<decimal> features)
        {
            if (features.Count != _nFeatures) throw new Exception("encountered non compatible case with this model");
            double value = 0, upper = 0, lower = 0;
            for (int i = 0; i < _nFeatures; i++)
            {
                nds[i].index = i + 1;
                value = (double)features[i];
                upper = _sclParams[i + 1].upper;
                lower = _sclParams[i + 1].lower;
                nds[i].value = _scaleLower + (value - lower) * (_scaleUpper - _scaleLower) / (upper - lower);
            }
        }

        // current cases have unknown class to be predicted or to be set. To be included in the svm traning each of them should be followed by setCurrentClass.  
        public void addCurrentCase(List<decimal> features)
        {
            if (features.Count != _nFeatures) throw new Exception("encountered non compatible case with this model");
            _currCases.Enqueue(features); 
        }
        // predict for a case that would have no effects on self, i.e, "this" object. 
        public int predict(List<decimal> features)
        {
            if (features.Count != _nFeatures) throw new Exception("encountered non compatible case with this model");
            svm_node[] nodes = new svm_node[_nFeatures + 1];
            scaleCase(ref nodes,ref features);
            nodes[_nFeatures].index = -1;
            nodes[_nFeatures].value = 0;
            int ret = (int)svmcallcs.svm_predict(ref _mdl, nodes);
            return ret;
        }
        // return the recent numbered case features fom the training set, i.e., lower number indicates more recent case  
        void getCaseFeatures(int i, ref List<decimal> features)
        {
            int nTotCases = _dat.Count;
            if (i >= _nCases) throw new Exception("encountered invalid case number");
            features.Clear();
            for (int ii = 0; i < _nFeatures; i++)
                features.Add(_dat.ElementAt(nTotCases - i -1)[ii + 1]); 
        }
        // return assigned class for the recent numbered traning case, i.e.,  lower number indicates more recent case 
        int getCaseClass(int i)
        {
            int nTotCases = _dat.Count;
            if (i >= _nCases) throw new Exception("encountered invalid case number");
            return (int)_dat.ElementAt(nTotCases - i - 1)[0];
        }

        public int predict(ref List<int> cls, ref List<double> prob)
        {
            // use current case to predict. returns most probable label, fill class id's and their probs
            // if model is not probility enabled just call the regular one
            cls.Clear();
            prob.Clear();
            if (_param.probability == 0) return predict();
            int nCls = svmcallcs.svm_get_nr_class(ref _mdl);
            int[] clss = new int[nCls];
            double[] probs = new double[nCls];

            svm_node[] nodes = new svm_node[_nFeatures + 1];
            scaledCurrentCase(ref nodes);
            nodes[_nFeatures].index = -1;
            nodes[_nFeatures].value = 0;
            int ret = (int)svmcallcs.svm_predict_probability(ref _mdl, ref nodes[0], ref probs[0]);
            svmcallcs.svm_get_labels(ref _mdl, ref clss[0]);
            for (int i = 0; i < nCls; i++) 
            {
                cls.Add(clss[i]);   
                prob.Add(probs[i]);
            }       
            // save Predicted class as last element of each case.
            if (CurrentCase.Count == _nFeatures) CurrentCase.Add((decimal)ret);
            else CurrentCase[_nFeatures] = (decimal)ret;
            return ret;
        }
        public int predict(List<decimal> features,ref List<int> cls, ref List<double> prob)
        {
            if (features.Count != _nFeatures) throw new Exception("encountered non compatible case with this model");
            // use given case to predict. returns most probable label, fill class id's and their probs
            // if model is not probility enabled just call the regular one
            cls.Clear();
            prob.Clear();
            if (_param.probability == 0) return predict(features);
            int nCls = svmcallcs.svm_get_nr_class(ref _mdl);
            int[] clss = new int[nCls];
            double[] probs = new double[nCls];
            svm_node[] nodes = new svm_node[_nFeatures + 1];
            scaleCase(ref nodes, ref features);
            nodes[_nFeatures].index = -1;
            nodes[_nFeatures].value = 0;
            int ret = (int)svmcallcs.svm_predict_probability(ref _mdl, ref nodes[0], ref probs[0]);
            svmcallcs.svm_get_labels(ref _mdl, ref clss[0]);
            for (int i = 0; i < nCls; i++)
            {
                cls.Add(clss[i]);
                prob.Add(probs[i]);
            }       
            return ret;
        }

        static bool Equal(ref svm_problem prblm1, ref svm_problem prblm2)
        {
            int nCases = prblm1.l;
            if (nCases != prblm2.l) return false;
            double[] clss = new double[nCases];
            double[] clss1 = new double[nCases];
            Marshal.Copy(prblm1.y, clss, 0, nCases);
            Marshal.Copy(prblm2.y, clss1, 0, nCases);
            for (int i = 0; i < nCases; i++)
                if (clss[i] != clss1[i]) return false;

            svm_node Nd = new svm_node(), Nd1 = new svm_node();
            // zero features is a erroneous condition
            for (int i = 0; i < nCases; i++)
            {
                IntPtr NdPtr = Marshal.ReadIntPtr(prblm1.x, i * Marshal.SizeOf(prblm1.x));
                Nd = (svm_node)Marshal.PtrToStructure(NdPtr, typeof(svm_node));
                IntPtr NdPtr1 = Marshal.ReadIntPtr(prblm2.x, i * Marshal.SizeOf(prblm2.x));
                Nd1 = (svm_node)Marshal.PtrToStructure(NdPtr1, typeof(svm_node));
                while (Nd.index != -1 && Nd1.index != -1)
                {
                    if (Nd.index != Nd1.index || Nd.value != Nd1.value) return false;
                    NdPtr += Marshal.SizeOf(Nd);
                    Nd = (svm_node)Marshal.PtrToStructure(NdPtr, typeof(svm_node));
                    NdPtr1 += Marshal.SizeOf(Nd1);
                    Nd1 = (svm_node)Marshal.PtrToStructure(NdPtr1, typeof(svm_node));
                }
                if (Nd1.index != -1 || Nd.index != -1) return false;
            }
            return true;
        }

        svm_problem deepCopy(ref svm_problem data)
        {
            svm_problem ret = new svm_problem();

            // assume data for all casses are homogeneous, i.e., no skiped zeroes
            int nCases = ret.l = data.l;
            if (nCases == 0) return ret; 
            IntPtr NdPtr = Marshal.ReadIntPtr(data.x,0);
            svm_node Nd = new svm_node();
            Nd = (svm_node)Marshal.PtrToStructure(NdPtr, typeof(svm_node));
            int nFeatures = 0;
            while (Nd.index != -1)
            {
                nFeatures++;
                NdPtr += Marshal.SizeOf(Nd);
                Nd = (svm_node)Marshal.PtrToStructure(NdPtr, typeof(svm_node));
            }

            allocateWorkSpace(ref ret, nCases, nFeatures);
            double[] clss = new double[nCases];
            Marshal.Copy(data.y, clss, 0, nCases);

            IntPtr pCls = ret.y;
            for (int i = 0; i < ret.l; i++)
            {
                Marshal.Copy(clss, i, pCls, 1);
                pCls += sizeof(double);
                IntPtr pFtr = Marshal.ReadIntPtr(ret.x, i * Marshal.SizeOf(pCls));
                IntPtr pFtr1 = Marshal.ReadIntPtr(data.x, i * Marshal.SizeOf(pCls));
                for (int j = 0; j < nFeatures; j++)
                {
                    Nd = (svm_node)Marshal.PtrToStructure(pFtr1, typeof(svm_node));
                    Marshal.StructureToPtr(Nd, pFtr, true);
                    pFtr += Marshal.SizeOf(Nd);
                    pFtr1 += Marshal.SizeOf(Nd);
                }
                Nd.index = -1;
                Nd.value = 0;
                Marshal.StructureToPtr(Nd, pFtr, true);
            }
            return ret;
        }
    }
}
