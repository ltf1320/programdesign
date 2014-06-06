using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Collections;
using System.Xml;
using System.Xml.Serialization;
using MathUtilityCommon;
using WaveletStudio;
using WaveletStudio.Functions;
using WaveletStudio.Wavelet;
using svmcallcsharp;

namespace ATSGlobalIndicator
{
    [Serializable]
    public class CompositeSVM : GenericIndicatorTemplate
    {
        /// <summary>
        /// Initializatin
        /// </summary>
        public override void Initializatin()
        {
            Name = GetType().Name.ToLower();
            _mySVMTrainingFreq = 0;
            _mySVMGridSearchFreq = 0;
            _mySVMparam.C = 1;
            _mySVMparam.svm_type = 1; // NU_SVC
            _mySVMparam.kernel_type = 2;
            _mySVMparam.eps = 0.00001;
            _mySVMparam.nu = 0.5;
            _mySVMparam.cache_size = 100;
            _mySVMparam.shrinking = 1;
            _mySVMparam.probability = 1;
            _mySVMparam.nr_weight = 0;
            _numericalZeroTol = 0.000001m;
            _myWaveletTrunctionMethod = "heursure";
            _myWaveletMotherFunction = "db4";
            _myWaveletExtensionmode = SignalExtension.ExtensionMode.ZeroPadding;
            _myWaveletLookBckPeriod = 16;
            _myWaveletTransoformLevelShift = -2;
            _minmumSignalLength = 0;
            _useAbsTurningValue = false;
            isSingleTrain = false;
            _isFullFeatures = false;
            _forcastPeriod = -1;
            _forcasetTriggerUp = 0.00001m;
            _forcasetTriggerDown = -0.00001m;
            _isSVMPassThrough = false;
            _SVMPassThroughTrigger = 1.0m;
            _SVMProbabilityTrigger = 0.0m;
            _isSVMFirstOn = false;
            _turningPointValueTol = 0.01m;
            _isExtendedTurnPoint = true;
            if (_inputParam != null)
                GetParam();

            _dataLength = 0;
            _mySVMDataLength = 0;
            _genericIndicatorVector = new List<GenericIndicatorTemplate>();
            _genericIndicatorPeriods = new List<Int32>();
            _periodsValueOn = new List<Int32>();
            _periodToGIndIndex = new Dictionary<Int32, List<Int32>>();
            _valueVec = new Queue<decimal>();

            _doCalcRealizedSignalValue = false;
            _turningPointValueRealized = Decimal.MinValue; ;
            _featureValueSum = Decimal.MinValue; ;
            isRetrainStarted = false;
            _inputGIndminmumSignalLength = 0;
            _signalVecLength = 5;
            if (_nfeatures > 0)
            {
                _SVMcls = new List<int>();
                _SVMprob = new List<double>();
            }
        }
        /// <summary>
        /// Getting parameter from input
        /// </summary>
        public override void GetParam()
        {
            if (_inputParam.ContainsKey("name"))
            {
                Name = _inputParam["name"].ToString();
            }
            if (_inputParam.ContainsKey("casesfortraining"))
            {
                _nCases = Convert.ToInt32(_inputParam["casesfortraining"].ToString());
            }
            _nCasesFirst = _nCases;
            if (_inputParam.ContainsKey("casesfortrainingfirst"))
            {
                _nCasesFirst = Convert.ToInt32(_inputParam["casesfortrainingfirst"].ToString());
            }

            if (_inputParam.ContainsKey("featureseachcase"))
            {
                _nfeatures = Convert.ToInt32(_inputParam["featureseachcase"].ToString());
            }
            if (_inputParam.ContainsKey("retrainfreq"))
            {
                _retrainFreq = Convert.ToInt32(_inputParam["retrainfreq"].ToString());
            }
            if (_inputParam.ContainsKey("svmtrainfreq"))
            {
                _mySVMTrainingFreq = Convert.ToInt32(_inputParam["svmtrainfreq"].ToString());
            }
            if (_inputParam.ContainsKey("svmgridsearchfreq"))
            {
                _mySVMGridSearchFreq = Convert.ToInt32(_inputParam["svmgridsearchfreq"].ToString());
            }
            if (_inputParam.ContainsKey("c"))
            {
                Double.TryParse(_inputParam["c"].ToString(), out _mySVMparam.C);
            }
            if (_inputParam.ContainsKey("svmtype"))
            {
                Int32.TryParse(_inputParam["svmtype"].ToString(), out _mySVMparam.svm_type);
            }
            if (_inputParam.ContainsKey("kerneltype"))
            {
                Int32.TryParse(_inputParam["kerneltype"].ToString(), out _mySVMparam.kernel_type);
            }
            _mySVMparam.gamma = 1.0 / (double)_nfeatures;
            if (_inputParam.ContainsKey("gamma"))
            {
                Double.TryParse(_inputParam["gamma"].ToString(), out _mySVMparam.gamma);
            }
            if (_inputParam.ContainsKey("eps"))
            {
                Double.TryParse(_inputParam["eps"].ToString(), out _mySVMparam.eps);
            }
            if (_inputParam.ContainsKey("nu"))
            {
                Double.TryParse(_inputParam["nu"].ToString(), out _mySVMparam.nu);
            }
            if (_inputParam.ContainsKey("cachesize"))
            {
                Double.TryParse(_inputParam["cachesize"].ToString(), out _mySVMparam.cache_size);
            }
            if (_inputParam.ContainsKey("shrinking"))
            {
                Int32.TryParse(_inputParam["shrinking"].ToString(), out _mySVMparam.shrinking);
            }
            if (_inputParam.ContainsKey("probability"))
            {
                Int32.TryParse(_inputParam["probability"].ToString(), out _mySVMparam.probability);
            }
            if (_inputParam.ContainsKey("nrweight"))
            {
                Int32.TryParse(_inputParam["nrweight"].ToString(), out _mySVMparam.nr_weight);
            }
            if (_inputParam.ContainsKey("numericalzerotol"))
            {
                Decimal.TryParse(_inputParam["numericalzerotol"].ToString(), out _numericalZeroTol);
            }
            
            if (_inputParam.ContainsKey("gammastart"))
            {
                Double.TryParse(_inputParam["gammastart"].ToString(), out _mySVMGridSearchParam.gamma_start);
            }
            if (_inputParam.ContainsKey("gammaend"))
            {
                Double.TryParse(_inputParam["gammaend"].ToString(), out _mySVMGridSearchParam.gamma_end);
            }
            if (_inputParam.ContainsKey("gammastep"))
            {
                Double.TryParse(_inputParam["gammastep"].ToString(), out _mySVMGridSearchParam.gamma_step);
            }
            if (_inputParam.ContainsKey("cstart"))
            {
                Double.TryParse(_inputParam["cstart"].ToString(), out _mySVMGridSearchParam.C_start);
            }
            if (_inputParam.ContainsKey("cend"))
            {
                Double.TryParse(_inputParam["cend"].ToString(), out _mySVMGridSearchParam.C_end);
            }
            if (_inputParam.ContainsKey("cstep"))
            {
                Double.TryParse(_inputParam["cstep"].ToString(), out _mySVMGridSearchParam.C_step);
            }            
            _mySVM = new SupportedVectorMachine(_nCases, _nfeatures, _retrainFreq);
            _mySVM._param = _mySVMparam;
            _mySVM._paramGS = _mySVMGridSearchParam;            
            if (_nCasesFirst != _nCases)
            {
                _isSVMFirstOn = true;
                _mySVMFirst = new SupportedVectorMachine(_nCasesFirst, _nfeatures, _retrainFreq);
                _mySVMFirst._param = _mySVMparam;
                _mySVMFirst._paramGS = _mySVMGridSearchParam;
            }
            if (_mySVMTrainingFreq > 0)
            {
                _mySVM.autoTrain = false;
                if(_isSVMFirstOn)
                    _mySVMFirst.autoTrain = false;
            }
            if (_inputParam.ContainsKey("wtrunctionmethod"))
            {
                _myWaveletTrunctionMethod = _inputParam["wtrunctionmethod"].ToString();
            }
            if (_inputParam.ContainsKey("wmotherfunction"))
            {
                _myWaveletMotherFunction = _inputParam["wmotherfunction"].ToString();
            }
            if (_inputParam.ContainsKey("wextensionmode"))
            {
                _myWaveletExtensionmode =
                    (SignalExtension.ExtensionMode)Enum.Parse(typeof(SignalExtension.ExtensionMode), _inputParam["wextensionmode"].ToString());
            }
            if (_inputParam.ContainsKey("wlookbckperiod"))
            {
                Int32.TryParse(_inputParam["wlookbckperiod"].ToString(), out _myWaveletLookBckPeriod);
            }
            if (_inputParam.ContainsKey("wtransoformlevelshift"))
            {
                Int32.TryParse(_inputParam["wtransoformlevelshift"].ToString(), out _myWaveletTransoformLevelShift);
            }
            if (_inputParam.ContainsKey("minmumsignallength"))
            {
                Int32.TryParse(_inputParam["minmumsignallength"].ToString(), out _minmumSignalLength);
            }
            if (_inputParam.ContainsKey("calcturningpoint"))
            {
                _calcTurningPoint = Convert.ToBoolean(_inputParam["calcturningpoint"].ToString());
            }
            if (_inputParam.ContainsKey("useabsturningvalue"))
            {
                _useAbsTurningValue = Convert.ToBoolean(_inputParam["useabsturningvalue"].ToString());
            }
            if (_inputParam.ContainsKey("issingletrain"))
            {
                isSingleTrain = Convert.ToBoolean(_inputParam["issingletrain"].ToString());
            }
            if (_inputParam.ContainsKey("isfullfeatures"))
            {
                _isFullFeatures = Convert.ToBoolean(_inputParam["isfullfeatures"].ToString());
            }
            if (_inputParam.ContainsKey("forcastperiod"))
            {
                _forcastPeriod = Convert.ToInt32(_inputParam["forcastperiod"].ToString());
            }
            if (_forcastPeriod > 0)
                _featuresVec = new Queue<List<Decimal>>();
            if (_inputParam.ContainsKey("forcasetriggerup"))
            {
                _forcasetTriggerUp = Convert.ToDecimal(_inputParam["forcasetriggerup"].ToString());
            }
            if (_inputParam.ContainsKey("forcasetriggerdown"))
            {
                _forcasetTriggerDown = Convert.ToDecimal(_inputParam["forcasetriggerdown"].ToString());
            }
            if (_inputParam.ContainsKey("issvmpassthrough"))
            {
                _isSVMPassThrough = Convert.ToBoolean(_inputParam["issvmpassthrough"].ToString());
            }
            if (_inputParam.ContainsKey("svmpassthroughtrigger"))
            {
                _SVMPassThroughTrigger = Convert.ToDecimal(_inputParam["svmpassthroughtrigger"].ToString());
            }
            if (_inputParam.ContainsKey("svmprobabilitytrigger"))
            {
                _SVMProbabilityTrigger = Convert.ToDecimal(_inputParam["svmprobabilitytrigger"].ToString());
            }
            if (_inputParam.ContainsKey("turningpointvaluetol"))
            {
                _turningPointValueTol = Convert.ToDecimal(_inputParam["turningpointvaluetol"].ToString());
            }
            if (_inputParam.ContainsKey("isextendedturnpoint"))
            {
                _isExtendedTurnPoint = Convert.ToBoolean(_inputParam["isextendedturnpoint"].ToString());
            }
        }
        /// <summary>
        /// Reset indicator
        /// </summary>
        public override void Reset()
        {
            base.Reset();
            Initializatin();
        }
        /// <summary>
        /// Indicator vector update
        /// </summary>
        public override void UpdateIndicator(GenericIndicatorTemplate gInd, Int32 numTickPerBar)
        {
            _inputGIndminmumSignalLength = Math.Max(_inputGIndminmumSignalLength, gInd.MinmumSignalLength * gInd.Period/numTickPerBar);
            _genericIndicatorVector.Add(gInd);
            _genericIndicatorVectorLength = _genericIndicatorVector.Count;
            _genericIndicatorPeriods.Add(gInd.Period);
            _periodsValueOn.Add(1);
            if (!_periodToGIndIndex.ContainsKey(gInd.Period))
            {
                _periodToGIndIndex[gInd.Period] = new List<Int32>();
            }
            _periodToGIndIndex[gInd.Period].Add(_genericIndicatorVectorLength - 1);
            _signalVecLength = Math.Max(_signalVecLength, gInd.GetSignalVecLengthLocal());
        }
        /// <summary>
        /// Number of bar type at the same tick
        /// </summary>
        public Int32 calcSameTickDataLength(Int32 tickCount)
        {
            Int32 tmp = 0;
            for (Int32 i = 0; i < _genericIndicatorPeriods.Count; i++)
            {
                Int32 iRem;
                Math.DivRem(tickCount, _genericIndicatorPeriods[i], out iRem);
                if (iRem == 0)
                    tmp++;
            }
            return tmp;
        }
        /// <summary>
        /// All bars have been calculated or not
        /// </summary>
        public Boolean isLastDataOfSameTick()
        {
            return _sameTickDataLengthTotal == _sameTickDataLength;
        }
        /// <summary>
        /// Indicator value update, vector value input
        /// </summary>
        public override void UpdateValue(ref Decimal[] valueVec)
        {

            foreach (GenericIndicatorTemplate gi in _genericIndicatorVector)
            {
                gi.UpdateValue(ref valueVec);
            }
            Decimal[] valueVecCopy = (Decimal[])valueVec.Clone();
            _valueVec.Enqueue(valueVec[0]);
            if (_valueVec.Count > _myWaveletLookBckPeriod)
            {
                _valueVec.Dequeue();
            }
            if (_dataLength > _inputGIndminmumSignalLength)
                updateSVM();

            _dataLength++;
        }
        /// <summary>
        /// Indicator value update, vector value input, period input
        /// </summary>
        public override void UpdateValue(ref Decimal[] valueVec, int period)
        {

            foreach (GenericIndicatorTemplate gi in _genericIndicatorVector)
            {
                gi.UpdateValue(ref valueVec, period);
            }
            Decimal[] valueVecCopy = (Decimal[])valueVec.Clone();
            _valueVec.Enqueue(valueVec[0]);
            if (_valueVec.Count > _myWaveletLookBckPeriod)
            {
                _valueVec.Dequeue();
            }
            if (_dataLength > _inputGIndminmumSignalLength)
                updateSVM();

            _dataLength++;
        }
        /// <summary>
        /// Indicator value update, vector value input, period input, tickCount input
        /// </summary>
        public void UpdateValue(ref Decimal[] valueVec, int period, Int32 tickCount)
        {

            if (tickCount != _tickCount)
            {
                _sameTickDataLengthTotal = calcSameTickDataLength(tickCount);
                _sameTickDataLength = 0;
                _tickCount = tickCount;
                for (Int32 i = 0; i < _genericIndicatorVectorLength; i++)
                {
                    _periodsValueOn[i] = 0;
                }
            }

            foreach (Int32 ss in _periodToGIndIndex[period])
            {
                _sameTickDataLength++;
                _periodsValueOn[ss] = 1;
            }
            foreach (GenericIndicatorTemplate gi in _genericIndicatorVector)
            {
                gi.UpdateValue(ref valueVec, period);
            }
            
            if (_sameTickDataLengthTotal == _sameTickDataLength)
            {
                Decimal[] valueVecCopy = (Decimal[])valueVec.Clone();
                _valueVec.Enqueue(valueVec[0]);
                if (_valueVec.Count > _myWaveletLookBckPeriod)
                {
                    _valueVec.Dequeue();
                }
                // This will make svm lose accuracy so far
                if (_isSVMPassThrough)
                {
                    if (_dataLength > _inputGIndminmumSignalLength)
                        updateSVM();
                }
                else
                {
                    if (_dataLength > _inputGIndminmumSignalLength + _forcastPeriod - 2)
                        updateSVM();
                }
                
                _dataLength++;
            }
        }
        /// <summary>
        /// Signal vector value output
        /// </summary>
        public override void GetSignalVec(ref Decimal[] signalVecValue)
        {
            Decimal _svmProbailityLocal = 1.0m;
            if (_dataLength <= (Int64)(_minmumSignalLength))
            {
                for (Int32 i = 0; i < GetSignalVecLength(); i++)
                {
                    signalVecValue[i] = Decimal.MinValue;
                }
                return;
            }
            if (_isSVMPassThrough)
            {
                if (_featureValueSum == Decimal.MinValue)
                {
                    signalVecValue[0] = 0;
                }
                else
                {
                    if (_featureValueSum > _SVMPassThroughTrigger)
                    {
                        signalVecValue[0] = 1m;
                    }
                    else if (_featureValueSum < -_SVMPassThroughTrigger)
                    {
                        signalVecValue[0] = -1m;
                    }
                    else
                    {
                        signalVecValue[0] = 0;
                    }
                }
            }
            else
            {
                // better use an user input casefeature
                if (_mySVMDataLength < _minmumSignalLength)
                {
                    signalVecValue[0] = _signalValueNonCalc;
                }
                else
                {
                    Decimal classId = _signalValueNonCalc;
                    if (_doCalcRealizedSignalValue)
                    {
                        if (isRetrainStarted)
                        {
                            if (_isSVMFirstOn)
                            {
                                
                                if (_mySVMparam.probability == 1)
                                {
                                    Int32 cclassIndex = _mySVMFirst.predict(ref _SVMcls, ref _SVMprob);
                                    cclassIndex = _SVMcls.IndexOf(cclassIndex);
                                    _svmProbailityLocal = (Decimal)_SVMprob[cclassIndex];
                                    classId = _SVMcls[cclassIndex];
                                }
                                else
                                {
                                    if (_featuresVec != null)
                                    {
                                        classId = (Decimal)_mySVMFirst.predict(_featuresVec.ElementAt(_featuresVec.Count - 1));
                                    }
                                    else
                                    {
                                        classId = (Decimal)_mySVMFirst.predict();
                                    }
                                }
                                if (_nCases <= _mySVMDataLength)
                                    _isSVMFirstOn = false;
                            }
                            else
                            { 
                                if (_mySVMparam.probability == 1)
                                {
                                    Int32 cclassIndex = _mySVM.predict(ref _SVMcls, ref _SVMprob);
                                    cclassIndex = _SVMcls.IndexOf(cclassIndex);
                                    _svmProbailityLocal = (Decimal)_SVMprob[cclassIndex];
                                    classId = _SVMcls[cclassIndex];
                                }
                                else
                                {
                                    if (_featuresVec != null)
                                    {
                                        classId = (Decimal)_mySVM.predict(_featuresVec.ElementAt(_featuresVec.Count - 1));
                                    }
                                    else
                                    {
                                        classId = (Decimal)_mySVM.predict();
                                    }
                                }
                            }
                        }
                    }
                    signalVecValue[0] = classId;
                }
            }
            // To be update from the svm API
            
            signalVecValue[1] = _turningPointValueRealized;
            signalVecValue[2] = _featureValueSum;
            signalVecValue[3] = _mySVMDataLength;
            signalVecValue[4] = _svmProbailityLocal;
            signalVecValue[0] *= _svmProbailityLocal >= _SVMProbabilityTrigger ? 1.0m : 0.0m;
        }
        /// <summary>
        /// Signal vector value output, with tickCount input
        /// </summary>
        public void GetSignalVec(ref Decimal[] signalVecValue, Int32 tickCount)
        {
            if (_sameTickDataLengthTotal == _sameTickDataLength)
            {
                GetSignalVec(ref signalVecValue);
            }
        }
        /// <summary>
        /// Update SVM values
        /// </summary>
        void updateSVM()
        {
            Decimal[] signalVecValue = new Decimal[GetSignalVecLengthLocal()];
            List<decimal> features = new List<decimal>();
            _featureValueSum = 0.0m;
            Int32 i = 0;
            foreach (GenericIndicatorTemplate gi in _genericIndicatorVector)
            {
                gi.GetSignalVec(ref signalVecValue);
                
                if (_isFullFeatures)
                {
                    foreach (Decimal ss in signalVecValue)
                    {
                        features.Add(ss);
                    }
                }
                else
                {
                    Decimal tmpV = 0;
                    if (_calcTurningPoint)
                    {
                        tmpV = signalVecValue[4];
                    }
                    else
                    {
                        tmpV = signalVecValue[0];
                    }
                    if (_useAbsTurningValue)
                    {
                        if (tmpV < 0)
                        {
                            tmpV *= -1;
                        }
                    }
                    tmpV *= _periodsValueOn[i];
                    features.Add(tmpV);
                    _featureValueSum += tmpV;
                }
                i++;
            }
            if (_isSVMPassThrough)
            {
                return;
            }
            if (_forcastPeriod > 0)
            {
                _featuresVec.Enqueue(features);
                if (_featuresVec.Count > _forcastPeriod+1)
                {
                    _featuresVec.Dequeue();
                }

            }
            if (_doCalcRealizedSignalValue )
            {
                _mySVMDataLength++;
                Decimal classId = -100;
                if (_forcastPeriod > 0)
                {
                    if (_featuresVec.Count == _forcastPeriod + 1)
                    {
                        classId = calcRealizedSignalValueUpDown();
                    }
                    else
                    {
                        //classId = 0m;
                    }
                }
                else
                {
                    classId = calcRealizedSignalValue();
                }
                if (_useAbsTurningValue)
                {
                    if (classId < 0)
                    {
                        classId *= -1;
                    }
                }

                Boolean setCurrentClassOK = true;
                if (_forcastPeriod > 0)
                {
                    setCurrentClassOK = false;
                    if (_featuresVec.Count == _forcastPeriod + 1)
                    {
                        setCurrentClassOK = true;
                    }
                }
                if(setCurrentClassOK)
                {
                    _turningPointValueRealized = classId;
                    _mySVM.setCurrentClass((Int32)classId);
                    if(_isSVMFirstOn)
                        _mySVMFirst.setCurrentClass((Int32)classId);
                    _doCalcRealizedSignalValue = false;
                    if (_mySVMTrainingFreq > 0)
                    {
                        Int32 iRem;
                        Math.DivRem((Int32)_mySVMDataLength, _mySVMTrainingFreq, out iRem);

                        //for the first period, to be enabled when the API is ready
                        Boolean atnCasesFirst = (_nCasesFirst == _mySVMDataLength) && _isSVMFirstOn;
                        Boolean doRetrain = (iRem == 0) && _mySVM.isValid();
                        if (atnCasesFirst)
                        {
                            if (_mySVMFirst.isValid())
                            {
                                doRetrain = true;
                            }
                        }
                        else
                        {
                            if (_mySVMDataLength < _nCases)
                            {
                                if (_isSVMFirstOn)
                                {
                                    doRetrain = false;
                                }
                            }
                        }
                        if (doRetrain)
                        {
                            Boolean isAutoGridSearchLast = _mySVM.autoGridSearch;
                            if (_mySVMGridSearchFreq > 0)
                            {
                                Math.DivRem((Int32)_mySVMDataLength, _mySVMGridSearchFreq, out iRem);
                                if (iRem == 0)
                                    _mySVM.autoGridSearch = true;
                            }
                            if (atnCasesFirst)
                            {
                                Boolean isAutoGridSearchLast1 = _mySVMFirst.autoGridSearch;
                                _mySVMFirst.autoGridSearch = true;
                                _mySVMFirst.retrain(_nCasesFirst);
                                _mySVMFirst.autoGridSearch = isAutoGridSearchLast1;
                                _mySVM._param.C = _mySVMFirst._param.C;
                                _mySVM._param.gamma = _mySVMFirst._param.gamma;
                            }
                            else
                            {
                                _mySVM.retrain(_nCases);
                            }
                            _mySVM.autoGridSearch = isAutoGridSearchLast;
                            isRetrainStarted = true;
                            if (isSingleTrain)
                            {
                                Boolean firstNormalTrainDone =(_mySVMDataLength>=_nCases);
                                if(firstNormalTrainDone)
                                _mySVMTrainingFreq *= -1;
                            }
                        }
                    }
                }
            }
            else
            {
                _turningPointValueRealized = _signalValueNonCalc;
            }
            if (_forcastPeriod > 0)
            {
                // only update when there is at lease one signal value generated
                if (_featuresVec.Count >= _forcastPeriod)
                {
                    if (_featuresVec.Count == _forcastPeriod)
                        _mySVM.addCurrentCase(_featuresVec.ElementAt(0)); 
                    else
                        _mySVM.addCurrentCase(_featuresVec.ElementAt(1));
                    if (_isSVMFirstOn)
                    {
                        List<Decimal> tmpFeature = new List<Decimal>();
                        foreach (Decimal ss in _featuresVec.ElementAt(0))
                        {
                            tmpFeature.Add(ss);
                        }
                        _mySVMFirst.addCurrentCase(tmpFeature);
                    }
                    _doCalcRealizedSignalValue = true;
                }
            }
            else
            {
                if (_featureValueSum != 0.0m)
                {
                    // only update when there is at lease one signal value generated
                    _mySVM.addCurrentCase(features);
                    if (_isSVMFirstOn)
                    {
                        List<Decimal> tmpFeature = new List<Decimal>();
                        foreach (Decimal ss in features)
                        {
                            tmpFeature.Add(ss);
                        }
                        _mySVMFirst.addCurrentCase(tmpFeature);
                    }
                    _doCalcRealizedSignalValue = true;
                }
            }
        }
        /// <summary>
        /// Calculating realized signal value (turn)
        /// </summary>
        Decimal calcRealizedSignalValue()
        {
            Int32 signalLength = _valueVec.Count;
            Double[] signalTick = new Double[signalLength];
            for (Int32 i = 0; i < signalLength; i++)
            {
                signalTick[i] = (Double)_valueVec.ElementAt(i);
            }
            Int32 powerOf2 = (Int32)(Math.Log(signalLength) / Math.Log(2) + 1);
            Int32 levelOfTransform = powerOf2 + _myWaveletTransoformLevelShift;
            Boolean returnOnlyValid = false;
            if (levelOfTransform < powerOf2)
            {
                returnOnlyValid = true;
            }
            var signal = new Signal(signalTick);
            Double value_0, value_1, value_2, value_3;
            value_0 = signal[signalLength - 1];
            value_1 = signal[signalLength - 2];
            value_2 = signal[signalLength - 3];
            value_3 = signal[signalLength - 4];
            if (levelOfTransform > 0)
            {
                var wavelet = MotherWavelet.LoadFromName(_myWaveletMotherFunction);
                var output = DWT.ExecuteDWT(signal, wavelet, levelOfTransform, _myWaveletExtensionmode, ConvolutionModeEnum.ManagedFFT, true);
                output = Wavevelet.Filter(output, _myWaveletTrunctionMethod);
                var signalFiltered = DWT.ExecuteIDWT(output, wavelet, levelOfTransform, ConvolutionModeEnum.ManagedFFT, returnOnlyValid);
                var signalFilteredValid = MemoryPool.Pool.New<double>(signalTick.Length, true);
                if ((6 + signalTick.Length < signalLength) && !returnOnlyValid)
                {
                    Array.Copy(signalFiltered, 6, signalFilteredValid, 0, signalTick.Length);
                }
                else
                {
                    Array.Copy(signalFiltered, 0, signalFilteredValid, 0, signalTick.Length);
                }

                value_0 = signalFilteredValid[signalLength - 1];
                value_1 = signalFilteredValid[signalLength - 2];
                value_2 = signalFilteredValid[signalLength - 3];
                value_3 = signalFilteredValid[signalLength - 4];
            }
            Boolean isTop = isTurnPoint(value_0, value_1, value_2, value_3, 1.0, (Double)_turningPointValueTol);            
            if (isTop)
            {
                return -1m;
            }
            else
            {
                Boolean isBottom = isTurnPoint(value_0, value_1, value_2, value_3, -1.0, (Double)_turningPointValueTol); 
                if (isBottom)
                {
                    return 1m;
                }
            }
            return 0m;
        }
        /// <summary>
        /// Check if a point is top (Weight==1) or bottom (weight==-1)
        /// </summary>
        Boolean isTurnPoint(Double value_0, Double value_1, Double value_2, Double value_3, Double weight, Double turnPointTol)
        {
            Double cTmp = value_1 - (Double)_numericalZeroTol * weight;
            Boolean isTurn = cTmp * weight > value_0 * weight;
            isTurn &= cTmp * weight > value_2 * weight;
            if (turnPointTol > -(Double)_numericalZeroTol)
            {
                isTurn &= Math.Abs(value_0 - value_1) / value_1 > turnPointTol && Math.Abs(value_1 - value_2) / value_2 > turnPointTol;
            }
            if (_isExtendedTurnPoint)
            {
                Double cTmp2 = value_2 - (Double)_numericalZeroTol * weight;
                Boolean isTurne = cTmp2 * weight > value_1 * weight;
                isTurne &= cTmp2 * weight > value_3 * weight;
                if (turnPointTol > -(Double)_numericalZeroTol)
                {
                    isTurne &= Math.Abs(value_1 - value_2) / value_2 > turnPointTol && Math.Abs(value_2 - value_3) / value_3 > turnPointTol;
                }
                isTurn |= isTurne;
            }
            return isTurn;
        }
        /// <summary>
        /// Calculating realized signal value (up or down)
        /// </summary>
        Decimal calcRealizedSignalValueUpDown()
        {
            Int32 signalLength = _valueVec.Count;
            Double[] signalTick = new Double[signalLength];
            for (Int32 i = 0; i < signalLength; i++)
            {
                signalTick[i] = (Double)_valueVec.ElementAt(i);
            }
            Int32 powerOf2 = (Int32)(Math.Log(signalLength) / Math.Log(2) + 1);
            Int32 levelOfTransform = powerOf2 + _myWaveletTransoformLevelShift;
            Boolean returnOnlyValid = false;
            if (levelOfTransform < powerOf2)
            {
                returnOnlyValid = true;
            }
            var signal = new Signal(signalTick);
            Double value_0, value_1;
            value_0 = signal[signalLength - 1];
            value_1 = signal[signalLength - 1- _forcastPeriod];
            if (levelOfTransform > 0)
            {
                var wavelet = MotherWavelet.LoadFromName(_myWaveletMotherFunction);
                var output = DWT.ExecuteDWT(signal, wavelet, levelOfTransform, _myWaveletExtensionmode, ConvolutionModeEnum.ManagedFFT, true);
                output = Wavevelet.Filter(output, _myWaveletTrunctionMethod);
                var signalFiltered = DWT.ExecuteIDWT(output, wavelet, levelOfTransform, ConvolutionModeEnum.ManagedFFT, returnOnlyValid);
                var signalFilteredValid = MemoryPool.Pool.New<double>(signalTick.Length, true);
                if ((6 + signalTick.Length < signalLength) && !returnOnlyValid)
                {
                    Array.Copy(signalFiltered, 6, signalFilteredValid, 0, signalTick.Length);
                }
                else
                {
                    Array.Copy(signalFiltered, 0, signalFilteredValid, 0, signalTick.Length);
                }

                value_0 = signalFilteredValid[signalLength - 1];
                value_1 = signalFilteredValid[signalLength - 1 - _forcastPeriod];
            }
            Double returnLocal = (value_0 - value_1);
            if (!isForcasetAbs)
            {
                returnLocal /= value_1;
            }
            Boolean isUp = returnLocal > (Double)_forcasetTriggerUp;
            if (isUp)
            {
                return 1m;
            }
            else
            {
                Boolean isDown = returnLocal <= (Double)_forcasetTriggerDown;
                if (isDown)
                {
                    return -1m;
                }
            }
            return 0m;
        }
        /// <summary>
        /// Available perids for current tick
        /// </summary>
        public List<Int32> periodsValueOn()
        {
            return _periodsValueOn;
        }
        /// <summary>
        /// Current gamma value
        /// </summary>
        public Double currentGamma()
        {
            if (_isSVMFirstOn)
            {
                return _mySVMFirst._param.gamma;
            }
            else
            {
                return _mySVM._param.gamma;
            }
        }
        /// <summary>
        /// Current C value
        /// </summary>
        public Double currentC()
        {
            if (_isSVMFirstOn)
            {
                return _mySVMFirst._param.C;
            }
            else
            {
                return _mySVM._param.C;
            }
        }

        //[XmlIgnore]
        //public Queue<Decimal> _valueVec;
        [XmlIgnore]
        public List<GenericIndicatorTemplate> _genericIndicatorVector;
        public List<Decimal> _genericIndicatorVectorWeight;
        public List<Int32> _genericIndicatorPeriods;
        public List<Int32> _periodsValueOn;
        public Int32 _inputGIndminmumSignalLength;
        [XmlIgnore]
        public Dictionary<Int32, List<Int32>> _periodToGIndIndex;
        public Int32 _genericIndicatorVectorLength;
        public SupportedVectorMachine _mySVM;
        public SupportedVectorMachine _mySVMFirst;
        public svmcallcsharp.svm_parameter _mySVMparam;
        public SupportedVectorMachine.gridsearch_parameter _mySVMGridSearchParam;
        public Boolean _isSVMFirstOn;
        public Int32 _nCases, _nfeatures, _retrainFreq;
        public Int32 _nCasesFirst;
        public Int32 _mySVMTrainingFreq;
        public Int32 _mySVMGridSearchFreq;
        public Int32 _mySVMDataLength;
        public Boolean _useAbsTurningValue;
        public Decimal _signalValueNonCalc = Decimal.MinValue;
        public Decimal _numericalZeroTol;
        public Boolean _doCalcRealizedSignalValue;
        public Decimal _turningPointValueRealized;
        public Decimal _featureValueSum;
        public String _myWaveletTrunctionMethod;
        public String _myWaveletMotherFunction;
        public Int32 _myWaveletLookBckPeriod;
        public Int32 _myWaveletTransoformLevelShift;
        public SignalExtension.ExtensionMode _myWaveletExtensionmode;
        public Boolean isRetrainStarted;
        public Boolean isSingleTrain;
        public Int32 _tickCount;
        public Int32 _sameTickDataLengthTotal;
        public Int32 _sameTickDataLength;
        public Int32 _forcastPeriod;
        public Decimal _forcasetTriggerUp;
        public Decimal _forcasetTriggerDown;
        public Boolean isForcasetAbs;
        public Boolean _isFullFeatures;
        public Boolean _isSVMPassThrough;
        public Decimal _SVMPassThroughTrigger;
        public Decimal _SVMProbabilityTrigger;
        public Boolean _isExtendedTurnPoint;
        [XmlIgnore]
        public Queue<List<Decimal>> _featuresVec;
        List<int> _SVMcls;
        List<double> _SVMprob;
    }
}
