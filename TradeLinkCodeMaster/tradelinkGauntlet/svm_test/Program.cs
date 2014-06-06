using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using MathUtilityCommon;
using svmcallcsharp;

namespace svm_test
{
    class Test
    {
        static void Main()
        {
            //test("svmguide1", "svmguide1.t", 3089, 4);  //test svmguide1
            //test("svmguide3", "svmguide3.t", 1243, 21);  //svmguide3
            test("svmguide4", "svmguide4.t", 300, 10);
            //test("svmguide2","",391, 20);
            
        }
        static void test(string Train, string Test, int _nCase, int _nfeatures)
        {
            string location_train = @"./svm/libsvm/" + Train;
            string location_test = @"./svm/libsvm/" + Test;

            SupportedVectorMachine svm = new SupportedVectorMachine(_nCase, _nfeatures, 5, true, true);
            svm._paramGS.gamma_start = 3;
            svm._paramGS.gamma_end = -15;
            svm._paramGS.gamma_step = -2;
            svm._paramGS.C_start = -5;
            svm._paramGS.C_end = 15;
            svm._paramGS.C_step = 2;

            svm.autoGridSearch = true;
            svm._param.svm_type = 0;
            svm.LowerScaleLimit = -1;
            svm.UpperScaleLimit = 1;
            //svm._debug = true;
            int y;
            List<decimal> x = new List<decimal>();


            //读入数据，并做训练
            StreamReader sr = new StreamReader(location_train);
            string line;
            line = sr.ReadLine();

            int len = line.Split(new char[2] { ' ', ':' }).Length;
            List<string> sp_line = new List<string>();

            while (line != null)
            {
                sp_line.AddRange(line.Split(new char[2] { ' ', ':' }));
                int len1 = sp_line.Count;

                y = Convert.ToInt32(sp_line[0]);
                int i, ifeature = 0;
                for (i = 2; i < len1; i = i + 2)
                {
                    decimal xi = (decimal)Convert.ToDouble(sp_line[i]);
                    int idx = (int)Convert.ToInt16(sp_line[i - 1]);
                    if (idx > i / 2) // the record in svm data file may skip index if the feature value is zero
                    {
                        for (int j = i / 2; j < idx; j++)
                        {
                            x.Add(0);
                            ifeature++;
                        }
                    }
                    x.Add(xi);
                    ifeature++;
                }
                // make up the missing features
                for (i = ifeature; i < _nfeatures; i++)
                    x.Add(0);

                svm.addCase(x, y);
                x.Clear();
                sp_line.Clear();
                line = sr.ReadLine();
            }
            Console.WriteLine("Finished traning");
            sr.Close();
            svm.do_cross_validation(5);
            Console.WriteLine("cross validation accuracy:{0}", svm.crossVldAccuracy);
            /*
            svm.do_cross_validation(5);
            Console.WriteLine("cross validation accuracy:{0}",svm.crossVldAccuracy);
            */

            if (Test != "")
            {
                //预测
                double TestAccuracy = 0;
                double Ncorrect = 0;  //测试集上预测accuracy
                double NTestCase = 0; //用来记录测试集的样本数
                int y_pred = 0;
                StreamReader srt = new StreamReader(location_test);
                line = srt.ReadLine();
                while (line != null)
                {
                    NTestCase++;
                    sp_line.AddRange(line.Split(new char[2] { ' ', ':' }));
                    y = Convert.ToInt32(sp_line[0]);
                    for (int i = 2; i < len; i = i + 2)
                    {
                        x.Add((decimal)Convert.ToDouble(sp_line[i]));
                    }
                    y_pred = svm.predict(x);
                    if (y_pred == y) Ncorrect++;
                    x.Clear();
                    sp_line.Clear();
                    line = srt.ReadLine();
                }
                srt.Close();
                TestAccuracy = Ncorrect / NTestCase;
                Console.WriteLine();
                Console.WriteLine(Train);
                Console.WriteLine("Test Accuracy:{0}", TestAccuracy);
                Console.ReadLine();
            }
        }
    }
}


