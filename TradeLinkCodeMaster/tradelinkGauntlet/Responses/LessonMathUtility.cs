using System;
using System.Collections;
using System.Collections.Generic;
using MathUtilityCommon;
using TradeLink.Common;
using TradeLink.API;
using System.ComponentModel;
using TicTacTec.TA.Library; // to use TA-lib indicators
using WaveletStudio;
using WaveletStudio.Functions;
using WaveletStudio.Wavelet;
using BaseUtility;
using System.IO;
using System.Data;
using System.Text;
using NSGA2Sharp; 

namespace Responses
{
    public class LessonMathUtility : ResponseTemplate
    {
        BarInterval _barinterval = BarInterval.CustomTicks;
        [Description("Default bar interval for this response.")]
        public BarInterval Interval { get { return _barinterval; } set { _barinterval = value; } }
        // project setting of working dir is tradelinkGuantlet
        string _exportFileName = "./TestParam/priceExp.dat";
        public string ExportFile { get { return _exportFileName; } set { _exportFileName = value; } }
        System.IO.StreamWriter _fs;
        int _itemPerBar = 1;
        [Description("Item per bar")]
        public int ItemPerBar { get { return _itemPerBar; } set { _itemPerBar = value; } }


        BarListTracker blt = null;
        bool _black = false;
        

        public override void Reset()
        {
            ParamPrompt.Popup(this, true, _black);

            int[] customintervals = new int[1];
            customintervals[0] = ItemPerBar;
            BarInterval[] intervaltypes = new BarInterval[1];
            intervaltypes[0] = Interval;
            blt = new BarListTracker(customintervals, intervaltypes);
            blt.GotNewBar += new SymBarIntervalDelegate(blt_GotNewBar);

            testMOO();
            TestDwt();
            TestNSGA2();
            mySquare(2);
        }


        void mySquare(Decimal x)
        {
            D("X input: " + x);
            Decimal xsquare = x * x;
            D("X^2 input: " + xsquare);

        }
        void testMOO()
        {
            Mopsocd myMopsocd = new Mopsocd();
            // project setting of working dir should be tradelinkGuantlet
            String paramFile = "./TestParam/moposcdTestKita.csv";

            myMopsocd.LoadParamFromFile(paramFile);
            myMopsocd.TestRun(myMopsocd.Param);
            D("TestMOO");
        }
        void TestDwt()
        {
            var signal = new Signal(5, 6, 7, 8, 1, 2, 3, 4);
            var wavelet = MotherWavelet.LoadFromName("haar");
            var output = DWT.ExecuteDWT(signal, wavelet, 1);
            var expectedApproximation = new[] { 7.7781745930520172, 10.606601717798206, 2.1213203435596411, 4.9497474683058291 };
            var expectedDetails = new[] { -0.707106781186547, -0.707106781186547, -0.707106781186547, -0.707106781186547 };
            D("TestDwt");

        }
        void TestNSGA2()
        {
            // project setting of working dir should be tradelinkGuantlet, and the input file should match the input function
            string filenm = "./nsga2/input_data/sch1.in";
            NSGA2 tstobj = new NSGA2(filenm,true);
            tstobj.evalFunction = NSGA2.test_problem;
            tstobj.doOptimization();
            D("TestNSGA2");
        }
        void TestDwtWithBarData(string symbol, int interval)
        {
            BarList myBarList = blt[symbol, interval];
            Int32 n = myBarList.Count;
            // once for each 5 bars...
            long rmd,dmy;
            string line = "";
//            dmy = Math.DivRem(n,6, out rmd);
            if (n >= 6)
            { 
                for (Int32 i = 0; i < 6; i++)
                {
                    if (i != 0) 
                    {
                        line += i.ToString();
                        line += ":";
                    }
                    line += myBarList[n - i - 1].Close.ToString("F2");
                    line += " ";
                }
                _fs.WriteLine(line);
                _fs.Flush();
                // write record to export file                      
            }

            Int32 powerOf2 = (Int32)(Math.Log(n) / Math.Log(2));

            n = (Int32)(Math.Exp(powerOf2 * Math.Log(2))+0.000001);
            if (n>16 &&(n==myBarList.Count-1))
            {
                Double[] signalTick = new Double[n];
                for (Int32 i = 0; i < n; i++)
                {
                    signalTick[i] = (Double)myBarList[i-n].Close;
                }
                Int32 levelOfTransform = powerOf2-1;
                var signal = new Signal(signalTick);
                var wavelet = MotherWavelet.LoadFromName("db4");
                var output = DWT.ExecuteDWT(signal, wavelet, levelOfTransform, SignalExtension.ExtensionMode.ZeroPadding);
                var signalFiltered = DWT.ExecuteIDWT(output, wavelet, levelOfTransform);

                // Output Wavelet details to a file.
                DataTable dataOutputTable = new DataTable();
                dataOutputTable.Columns.Add("level");
                for (Int32 i = 0; i < output[0].Details.Length;i++ )
                {
                    dataOutputTable.Columns.Add("coef"+i.ToString());
                }
                for (Int32 i = 0; i < output.Count; i++)
                {
                    MiscUtility.addRowToTable(dataOutputTable, out dataOutputTable, 1);
                    dataOutputTable.Rows[i][0] = i.ToString();
                    for (Int32 j = 0; j < output[i].Details.Length; j++)
                    {
                        dataOutputTable.Rows[i][j + 1] = output[i].Details[j].ToString();
                    }
                }
                String dataOutputFileName = "WaveletDetailCoff"+n.ToString()+".csv";
                StreamWriter sw = new StreamWriter(dataOutputFileName, false, Encoding.GetEncoding("GB18030"));
                CsvWriter.WriteToStream(sw, dataOutputTable, true, true);
                sw.Close();
                // Output the raw data to a file
                DataTable dataOutputTableTime = new DataTable();
                DataTable dataOutputTableValue = new DataTable();
               
                for (Int32 i = 0; i < n; i++)
                {
                    dataOutputTableTime.Columns.Add("bar" + i.ToString());
                    dataOutputTableValue.Columns.Add("bar" + i.ToString());
                }
                MiscUtility.addRowToTable(dataOutputTableTime, out dataOutputTableTime, 1);
                MiscUtility.addRowToTable(dataOutputTableValue, out dataOutputTableValue, 1);
                Int32 barDate = 0;
                for (Int32 i = 0; i < n; i++)
                {
                    double tmpValue = (Double)myBarList[i - n].Close;
                    int tmpValueInt = myBarList[i - n].time;
                    dataOutputTableTime.Rows[0][i] = tmpValueInt.ToString();
                    dataOutputTableValue.Rows[0][i] = tmpValue.ToString();
                    if (barDate == 0)
                    {
                        barDate = myBarList[i - n].Bardate;
                    }
                }
                dataOutputFileName = "WaveletDataTime_" + symbol+"_" + n.ToString() + "_" + barDate.ToString() + ".csv";
                sw = new StreamWriter(dataOutputFileName, false, Encoding.GetEncoding("GB18030"));
                CsvWriter.WriteToStream(sw, dataOutputTableTime, false, false);
                sw.Close();
                dataOutputFileName = "WaveletDataValue" + symbol + "_" + n.ToString() + "_" + barDate.ToString() + ".csv";
                sw = new StreamWriter(dataOutputFileName, false, Encoding.GetEncoding("GB18030"));
                CsvWriter.WriteToStream(sw, dataOutputTableValue, false, false);
                sw.Close();
                D("TestDwtWithBarData");
            }
        }
        void blt_GotNewBar(string symbol, int interval)
        {
            Double barCountSquare = Basic.mySquare(blt[symbol].Count);
            String tmp = "Bar Count Using mySquare " + barCountSquare.ToString();
            D(tmp);
            TestDwtWithBarData(symbol, interval);
        }

        public override void GotTick(Tick tick)
        {
            blt.newTick(tick);
        }
    }
}
