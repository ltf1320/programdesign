using System;
using System.Collections.Generic;
using System.Data;
using TradeLink.Common;
using TradeLink.API;
using System.ComponentModel;
using TicTacTec.TA.Library; // to use TA-lib indicators
using System.IO;
using ATSGlobal.API;
using ATSGlobalIndicator;
using System.Collections;
using WaveletStudio;
using WaveletStudio.Functions;
using WaveletStudio.Wavelet;
using BaseUtility;


namespace Responses
{
    public class SVMComposite : ResponseTemplate
    {
        // parameters of this system
        BarInterval _barType = BarInterval.CustomTicks;//"Time","Volume"
        [Description("BarType")]
        public BarInterval BarType { get { return _barType; } set { _barType = value; } }
        int _numTickPerBar = 4;
        [Description("NumItemPerBar")]
        public int NumItemPerBar { get { return _numTickPerBar; } set { _numTickPerBar = value; } }
        [Description("Total Profit Target")]
        public decimal TotalProfitTarget { get { return _totalprofit; } set { _totalprofit = value; } }
        [Description("Entry size when signal is found")]
        public int EntrySize { get { return _entrysize; } set { _entrysize = value; } }
        [Description("Quasi-Market Order Adjustment Size")]
        public decimal QuasiMarketOrderAdjSize { get { return _quasiMarketOrderAdjSize; } set { _quasiMarketOrderAdjSize = value; } }
        [Description("Future Contract Size")]
        public decimal ContractSize { get { return _contractSize; } set { _contractSize = value; } }
        Boolean _matchTALib = true;
        [Description("MatchTALib")]
        public Boolean MatchTALib { get { return _matchTALib; } set { _matchTALib = value; } }
        [Description("shutdown time")]
        public int Shutdown { get { return _shutdowntime; } set { _shutdowntime = value; } }       
        Boolean _useBarCloseForGInd = true;
        [Description("UseBarCloseForGInd")]
        public Boolean UseBarCloseForGInd { get { return _useBarCloseForGInd; } set { _useBarCloseForGInd = value; } }

        MACD _myMacd;
        KDJ _myKDJ;
        RSI _myRSI;
        MACD _myMacdForSVM;
        KDJ _myKDJForSVM;
        RSI _myRSIForSVM;
        CompositeSVM _myComSVM;

        Int32 aMacd;
        Int32 bMacd;
        Int32 cMacd;
        Decimal recallMacd;
        Decimal precisionMacd;
        Decimal FMeasureMacd;

        Int32 aRSI;
        Int32 bRSI;
        Int32 cRSI;
        Decimal recallRSI;
        Decimal precisionRSI;
        Decimal FMeasureRSI;

        Int32 aKDJ;
        Int32 bKDJ;
        Int32 cKDJ;
        Decimal recallKDJ;
        Decimal precisionKDJ;
        Decimal FMeasureKDJ;

        Int32 aSVM;
        Int32 bSVM;
        Int32 cSVM;
        Decimal recallSVM;
        Decimal precisionSVM;
        Decimal FMeasureSVM;

        DataTable _indicatorOutput = new DataTable(); 
        List<Decimal> _gindData = new List<Decimal>();
        double[] barCloseVec = new double[50000];

        bool _black = false;
        // this function is called the constructor, because it sets up the response
        // it is run before all the other functions, and has same name as my response.
        public SVMComposite() : this(true) { }
        
        public SVMComposite(bool prompt)
        {
            _black = !prompt;
            // handle when new symbols are added to the active tracker
            _active.NewTxt += new TextIdxDelegate(_active_NewTxt);

            // set our indicator names, in case we import indicators into R
            // or excel, or we want to view them in gauntlet or kadina
            Indicators = new string[] { "Symbol", "Date", "Time", "O", "H", "L", "C", "Vol", "CBardate", "CBCount", "MACD", "MACDBuySell", "MACDLMin", "MACDLMax", "MACDTurn", "TAlibMacd", "KDJ", "KDJBuySell", "KDJLMin", "KDJLMax", "KDJTurn", "RSI", "RSIBuySell", "RSILMin", "RSILMax", "RSITurn", "TAlibRSI", "ComSVM", "ComSVMTurnRealized", "ComSVMSignalSum", "ComSVMDataLength","aSVM","bSVM","cSVM","recallSVM","PrecisionSVM","FMeasureSVM"
            ,"aMacd","bMacd","cMacd","recallMacd","PrecisionMacd","FMeasureMacd"
            ,"aRSI","bRSI","cRSI","recallRSI","PrecisionRSI","FMeasureRSI"
            ,"aKDJ","bKDJ","cKDJ","recallKDJ","PrecisionKDJ","FMeasureKDJ"};
        }
        
        public override void Reset()
        {
            // enable prompting of system parameters to user,
            // so they do not have to recompile to change things
            ParamPrompt.Popup(this, true, _black);

            int[] customintervals = new int[1];
            customintervals[0] = NumItemPerBar;
            BarInterval[] intervaltypes = new BarInterval[1];
            intervaltypes[0] = BarType;
            // only build bars for user's interval
            blt = new BarListTracker(customintervals, intervaltypes);
            // only calculate on new bars
            blt.GotNewBar += new SymBarIntervalDelegate(blt_GotNewBar);

            // wait for fill
            _wait.Clear();
            // track whether shutdown 
            _active.Clear();
            _kt.Clear();            

            Hashtable macdInputParam = new Hashtable();
            macdInputParam["lookbackperiodlong"] = 26;
            macdInputParam["lookbackperiodlongalpha"] = -10000;
            macdInputParam["lookbackperiodshort"] = 12;
            macdInputParam["lookbackperiodshortalpha"] = -10000;
            macdInputParam["lookbackperiodave"] = 9;
            macdInputParam["lookbackperiodavealpha"] = -10000;            
            macdInputParam["calcturningpoint"] = "true";            
            if (MatchTALib)
            {
                macdInputParam["minmumsignallength"] = 9 + 26 - 2;
                macdInputParam["setemaminmumsignallength"] = "true";
            }

            _myMacd = new MACD();
            _myMacd.Param = macdInputParam;
            _myMacd.Initializatin();
            _myMacdForSVM = new MACD();
            _myMacdForSVM.Param = macdInputParam;
            _myMacdForSVM.Initializatin();

            Hashtable KDJInputParam = new Hashtable();
            KDJInputParam["lookbackperiod"] = 9;
            KDJInputParam["lowerbanddownlimit"] = -10000;
            KDJInputParam["lowerbanduplimit"] = 25;
            KDJInputParam["upperbanddownlimit"] = 75;
            KDJInputParam["upperbanduplimit"] = 10000;
            KDJInputParam["calcturningpoint"] = "true";
            KDJInputParam["minmumsignallength"] = 9;
            _myKDJ = new KDJ();
            _myKDJ.Param = KDJInputParam;
            _myKDJ.Initializatin();
            _myKDJForSVM = new KDJ();
            _myKDJForSVM.Param = KDJInputParam;
            _myKDJForSVM.Initializatin();

            Hashtable RSIInputParam = new Hashtable();
            RSIInputParam["lookbackperiod"] = 12;
            RSIInputParam["lowerbanddownlimit"] = 0;
            RSIInputParam["lowerbanduplimit"] = 20;
            RSIInputParam["upperbanddownlimit"] = 80;
            RSIInputParam["upperbanduplimit"] = 100;
            RSIInputParam["calcturningpoint"] = "true";
            RSIInputParam["minmumsignallength"] = 12;
            _myRSI = new RSI();
            _myRSI.Param = RSIInputParam;
            _myRSI.Initializatin();
            _myRSIForSVM = new RSI();
            _myRSIForSVM.Param = RSIInputParam;
            _myRSIForSVM.Initializatin();

            Hashtable ComSVMInputParam = new Hashtable();
            // SVM param
            ComSVMInputParam["c"] = 0.5;
            ComSVMInputParam["gamma"] = 0.5;
            ComSVMInputParam["casesfortraining"] = 212;
            ComSVMInputParam["featureseachcase"] = 3;
            ComSVMInputParam["retrainfreq"] = 212;
            ComSVMInputParam["svmtrainfreq"] = 212;
            // Wavelet param
            ComSVMInputParam["wtrunctionmethod"] = "heursure";
            ComSVMInputParam["wmotherfunction"] = "db4";
            ComSVMInputParam["wextensionmode"] = "ZeroPadding";
            ComSVMInputParam["wlookbckperiod"] = 16;
            ComSVMInputParam["wtransoformlevelshift"] = 0;
            // other param
            ComSVMInputParam["minmumsignallength"] = 212;
            ComSVMInputParam["calcturningpoint"] = "true";
            ComSVMInputParam["useabsturningvalue"] = "true";
            ComSVMInputParam["issingletrain"] = "true";

            _myComSVM = new CompositeSVM();
            _myComSVM.Param = ComSVMInputParam;
            _myComSVM.Initializatin();
            _myComSVM.UpdateIndicator(_myMacdForSVM);
            _myComSVM.UpdateIndicator(_myKDJForSVM);
            _myComSVM.UpdateIndicator(_myRSIForSVM);

            _gindData.Clear();

            aMacd = 0;
            bMacd = 0;
            cMacd = 0;

            recallMacd = 0;
            precisionMacd = 0;
            FMeasureMacd = 0;

            aRSI = 0;
            bRSI = 0;
            cRSI = 0;

            recallRSI = 0;
            precisionRSI = 0;
            FMeasureRSI = 0;

            aKDJ = 0;
            bKDJ = 0;
            cKDJ = 0;

            recallKDJ = 0;
            precisionKDJ = 0;
            FMeasureKDJ = 0;

            aSVM = 0;
            bSVM = 0;
            cSVM = 0;

            recallSVM = 0;
            precisionSVM = 0;
            FMeasureSVM = 0;
            
            foreach (String ss in Indicators)
            {
                _indicatorOutput.Columns.Add(ss);
            }
        }

        // wait for fill
        GenericTracker<bool> _wait = new GenericTracker<bool>();
        // track whether shutdown 
        GenericTracker<bool> _active = new GenericTracker<bool>();    
        TickTracker _kt = new TickTracker();
        void _active_NewTxt(string txt, int idx)
        {
            // go ahead and notify any other trackers about this symbol
            _wait.addindex(txt, false);
            _kt.addindex(txt);
        }

        void abcToFMeasure(decimal a, decimal b, decimal c, out decimal recall, out decimal precision, out decimal fmeasure)
        {
            recall = 0m;
            if (a + c > 0)
                recall = a / (a + c + 0m);
            precision = 0m;
            if (a + b > 0)
                precision = a / (a + b + 0m);
            fmeasure = 0m;
            if (recall + precision > 0)
                fmeasure = (2 * precision * recall) / (recall + precision);
        }

        void updateabc(ref Int32 a, ref Int32 b, ref Int32 c, string indicator, Decimal[] signalVecValue)
        { 
            Int32 nLast = _indicatorOutput.Rows.Count;
            Decimal tmpLocal = -2;
            Decimal.TryParse(_indicatorOutput.Rows[nLast - 1][indicator].ToString(), out tmpLocal);
            if (Math.Abs(tmpLocal) == Math.Abs(Decimal.MinValue) || Math.Abs(signalVecValue[1]) == Math.Abs(Decimal.MinValue))
            {
                return;
            }
            if (Math.Abs(tmpLocal) == 1)
            {
                if (Math.Abs(signalVecValue[1]) == 1)
                {
                    a++;
                }
                else
                {
                    b++;
                }
            }
            if (Math.Abs(signalVecValue[1]) == 1)
            {
                if (Math.Abs(tmpLocal) != 1)
                {
                    c++;
                }
            }
        }

        void blt_GotNewBar(string symbol, int interval)
        {
            Tick tOther = _kt[symbol];
            Decimal valueForGInd = tOther.trade;
            Bar _lastBar = blt[symbol, interval][-1];
            if (_lastBar.Close <= 0)
            {
                return;
            }
            if (UseBarCloseForGInd)
            {
                valueForGInd = _lastBar.Close;
            }
            _gindData.Add(valueForGInd);
            barCloseVec[_gindData.Count - 1] = (Double)valueForGInd;
            // calculate the buy/sell signal from  compositeSVM
            int num, si;
            
            Decimal[] valueVecKDJ = new Decimal[4];
            valueVecKDJ[0] = valueForGInd;
            valueVecKDJ[1] = _lastBar.High;
            valueVecKDJ[2] = _lastBar.Low;
            valueVecKDJ[3] = tOther.trade;

            _myMacd.UpdateValue(valueForGInd);
            _myRSI.UpdateValue(valueForGInd);
            _myKDJ.UpdateValue(ref valueVecKDJ);
            _myComSVM.UpdateValue(ref valueVecKDJ);
          
            BarList cBarList = blt[symbol];
            Boolean isLong = false;
            Boolean isShort = false;
            if (cBarList.Count > 1)
            {
                // calculator indicator using TA-lib for checking
                double[] resultMACD = new double[blt[symbol].Count];
                double[] resultMACDSignal = new double[blt[symbol].Count];
                double[] resultMACDHist = new double[blt[symbol].Count];
                Int32 optInFastPeriod = 12;
                Int32 optInSlowPeriod = 26;
                Int32 optInSignalPeriod = 9;
                Core.Macd(0, _gindData.Count - 1, barCloseVec, optInFastPeriod, optInSlowPeriod, optInSignalPeriod, out si, out num, resultMACD, resultMACDSignal, resultMACDHist);
                Double TAlibMacd = 0;
                if (num > 0)
                {
                    TAlibMacd = resultMACDHist[num - 1] * 2;
                }               
                double[] resultRSI = new double[blt[symbol].Count];
                optInSignalPeriod = 12;
                Core.Rsi(0, _gindData.Count - 1, barCloseVec, optInSignalPeriod, out si, out num, resultRSI);
                Double TAlibRSI = 0;
                if (num > 0)
                {
                    TAlibRSI = resultRSI[num - 1];
                }
                Bar lastGoodBar = cBarList[cBarList.Count - 2];
                Decimal[] signalVecValueMACD = new Decimal[_myMacd.GetSignalVecLength()];
                _myMacd.GetSignalVec(ref signalVecValueMACD);
                Decimal[] signalVecValueKDJ = new Decimal[_myMacd.GetSignalVecLength()];
                _myKDJ.GetSignalVec(ref signalVecValueKDJ);
                Decimal[] signalVecValueRSI = new Decimal[_myMacd.GetSignalVecLength()];
                _myRSI.GetSignalVec(ref signalVecValueRSI);
                Decimal[] signalVecValueComSVM = new Decimal[_myMacd.GetSignalVecLength()];
                _myComSVM.GetSignalVec(ref signalVecValueComSVM);

                abcToFMeasure(aSVM, bSVM, cSVM, out recallSVM, out precisionSVM, out FMeasureSVM);
                abcToFMeasure(aMacd, bMacd, cMacd, out recallMacd, out precisionMacd, out FMeasureMacd);
                abcToFMeasure(aRSI, bRSI, cRSI, out recallRSI, out precisionRSI, out FMeasureRSI);
                abcToFMeasure(aKDJ, bKDJ, cKDJ, out recallKDJ, out precisionKDJ, out FMeasureKDJ);

                string[] tmpStringvec =
                (new string[] { symbol, lastGoodBar.Bardate.ToString(), lastGoodBar.time.ToString() 
                ,lastGoodBar.Open.ToString("F4", System.Globalization.CultureInfo.InvariantCulture) 
                 ,lastGoodBar.High.ToString("F4", System.Globalization.CultureInfo.InvariantCulture) 
                  ,lastGoodBar.Low.ToString("F4", System.Globalization.CultureInfo.InvariantCulture) 
                   ,lastGoodBar.Close.ToString("F4", System.Globalization.CultureInfo.InvariantCulture) 
                    ,lastGoodBar.Volume.ToString("F4", System.Globalization.CultureInfo.InvariantCulture) 
                    ,cBarList.RecentBar.Bardate.ToString()
                    ,cBarList.Count.ToString()
                    ,signalVecValueMACD[0].ToString("F4", System.Globalization.CultureInfo.InvariantCulture)
                    ,signalVecValueMACD[1].ToString("F4", System.Globalization.CultureInfo.InvariantCulture)
                    ,signalVecValueMACD[2].ToString("F4", System.Globalization.CultureInfo.InvariantCulture)
                    ,signalVecValueMACD[3].ToString("F4", System.Globalization.CultureInfo.InvariantCulture)
                    ,signalVecValueMACD[4].ToString("F4", System.Globalization.CultureInfo.InvariantCulture)
                    ,TAlibMacd.ToString("F4", System.Globalization.CultureInfo.InvariantCulture)
                    ,signalVecValueKDJ[0].ToString("F4", System.Globalization.CultureInfo.InvariantCulture)
                    ,signalVecValueKDJ[1].ToString("F4", System.Globalization.CultureInfo.InvariantCulture)
                    ,signalVecValueKDJ[2].ToString("F4", System.Globalization.CultureInfo.InvariantCulture)
                    ,signalVecValueKDJ[3].ToString("F4", System.Globalization.CultureInfo.InvariantCulture)
                    ,signalVecValueKDJ[4].ToString("F4", System.Globalization.CultureInfo.InvariantCulture)
                    ,signalVecValueRSI[0].ToString("F4", System.Globalization.CultureInfo.InvariantCulture)
                    ,signalVecValueRSI[1].ToString("F4", System.Globalization.CultureInfo.InvariantCulture)
                    ,signalVecValueRSI[2].ToString("F4", System.Globalization.CultureInfo.InvariantCulture)
                    ,signalVecValueRSI[3].ToString("F4", System.Globalization.CultureInfo.InvariantCulture)
                    ,signalVecValueRSI[4].ToString("F4", System.Globalization.CultureInfo.InvariantCulture)
                    ,TAlibRSI.ToString("F4", System.Globalization.CultureInfo.InvariantCulture)
                    ,signalVecValueComSVM[0].ToString("F4", System.Globalization.CultureInfo.InvariantCulture)
                    ,signalVecValueComSVM[1].ToString("F4", System.Globalization.CultureInfo.InvariantCulture)
                    ,signalVecValueComSVM[2].ToString("F4", System.Globalization.CultureInfo.InvariantCulture)
                    ,signalVecValueComSVM[3].ToString("F4", System.Globalization.CultureInfo.InvariantCulture)
                    ,aSVM.ToString("F4", System.Globalization.CultureInfo.InvariantCulture)
                    ,bSVM.ToString("F4", System.Globalization.CultureInfo.InvariantCulture)
                    ,cSVM.ToString("F4", System.Globalization.CultureInfo.InvariantCulture)
                    ,recallSVM.ToString("F4", System.Globalization.CultureInfo.InvariantCulture)
                    ,precisionSVM.ToString("F4", System.Globalization.CultureInfo.InvariantCulture)
                    ,FMeasureSVM.ToString("F4", System.Globalization.CultureInfo.InvariantCulture)
                    ,aMacd.ToString("F4", System.Globalization.CultureInfo.InvariantCulture)
                    ,bMacd.ToString("F4", System.Globalization.CultureInfo.InvariantCulture)
                    ,cMacd.ToString("F4", System.Globalization.CultureInfo.InvariantCulture)
                    ,recallMacd.ToString("F4", System.Globalization.CultureInfo.InvariantCulture)
                    ,precisionMacd.ToString("F4", System.Globalization.CultureInfo.InvariantCulture)
                    ,FMeasureMacd.ToString("F4", System.Globalization.CultureInfo.InvariantCulture)
                    ,aRSI.ToString("F4", System.Globalization.CultureInfo.InvariantCulture)
                    ,bRSI.ToString("F4", System.Globalization.CultureInfo.InvariantCulture)
                    ,cRSI.ToString("F4", System.Globalization.CultureInfo.InvariantCulture)
                    ,recallRSI.ToString("F4", System.Globalization.CultureInfo.InvariantCulture)
                    ,precisionRSI.ToString("F4", System.Globalization.CultureInfo.InvariantCulture)
                    ,FMeasureRSI.ToString("F4", System.Globalization.CultureInfo.InvariantCulture)
                    ,aKDJ.ToString("F4", System.Globalization.CultureInfo.InvariantCulture)
                    ,bKDJ.ToString("F4", System.Globalization.CultureInfo.InvariantCulture)
                    ,cKDJ.ToString("F4", System.Globalization.CultureInfo.InvariantCulture)
                    ,recallKDJ.ToString("F4", System.Globalization.CultureInfo.InvariantCulture)
                    ,precisionKDJ.ToString("F4", System.Globalization.CultureInfo.InvariantCulture)
                    ,FMeasureKDJ.ToString("F4", System.Globalization.CultureInfo.InvariantCulture)
                    });

                Int32 nLast = _indicatorOutput.Rows.Count;
                if (nLast > 0)
                {
                    updateabc(ref aSVM, ref bSVM, ref cSVM, "ComSVM", signalVecValueComSVM);
                    updateabc(ref aMacd, ref bMacd, ref cMacd, "MACDTurn", signalVecValueComSVM);
                    updateabc(ref aKDJ, ref bKDJ, ref cKDJ, "KDJTurn", signalVecValueComSVM);
                    updateabc(ref aRSI, ref bRSI, ref cRSI, "RSITurn", signalVecValueComSVM);
                }

                MiscUtility.addRowToTable(_indicatorOutput, out _indicatorOutput, 1);
                nLast = _indicatorOutput.Rows.Count;
                _indicatorOutput.Rows[nLast-1]["Symbol"]= symbol;
                _indicatorOutput.Rows[nLast - 1]["Date"] = lastGoodBar.Bardate.ToString();
                _indicatorOutput.Rows[nLast - 1]["Time"] = lastGoodBar.time.ToString().ToString();

                _indicatorOutput.Rows[nLast - 1]["O"] = lastGoodBar.Open.ToString("F4", System.Globalization.CultureInfo.InvariantCulture);
                _indicatorOutput.Rows[nLast - 1]["H"] = lastGoodBar.High.ToString("F4", System.Globalization.CultureInfo.InvariantCulture);
                _indicatorOutput.Rows[nLast - 1]["L"] = lastGoodBar.Low.ToString("F4", System.Globalization.CultureInfo.InvariantCulture);
                _indicatorOutput.Rows[nLast - 1]["C"] = lastGoodBar.Close.ToString("F4", System.Globalization.CultureInfo.InvariantCulture);
                _indicatorOutput.Rows[nLast - 1]["Vol"] = lastGoodBar.Volume.ToString("F4", System.Globalization.CultureInfo.InvariantCulture);

                _indicatorOutput.Rows[nLast - 1]["CBardate"] = cBarList.RecentBar.Bardate.ToString();
                _indicatorOutput.Rows[nLast - 1]["CBCount"] = cBarList.Count.ToString();

                _indicatorOutput.Rows[nLast - 1]["MACD"] = signalVecValueMACD[0].ToString("F4", System.Globalization.CultureInfo.InvariantCulture);
                _indicatorOutput.Rows[nLast - 1]["MACDBuySell"] = signalVecValueMACD[1].ToString("F4", System.Globalization.CultureInfo.InvariantCulture);
                _indicatorOutput.Rows[nLast - 1]["MACDLMin"] = signalVecValueMACD[2].ToString("F4", System.Globalization.CultureInfo.InvariantCulture);
                _indicatorOutput.Rows[nLast - 1]["MACDLMax"] = signalVecValueMACD[3].ToString("F4", System.Globalization.CultureInfo.InvariantCulture);
                _indicatorOutput.Rows[nLast - 1]["MACDTurn"] = signalVecValueMACD[4].ToString("F4", System.Globalization.CultureInfo.InvariantCulture);

                _indicatorOutput.Rows[nLast - 1]["TAlibMacd"] = TAlibMacd.ToString("F4", System.Globalization.CultureInfo.InvariantCulture);

                _indicatorOutput.Rows[nLast - 1]["KDJ"] = signalVecValueKDJ[0].ToString("F4", System.Globalization.CultureInfo.InvariantCulture);
                _indicatorOutput.Rows[nLast - 1]["KDJBuySell"] = signalVecValueKDJ[1].ToString("F4", System.Globalization.CultureInfo.InvariantCulture);
                _indicatorOutput.Rows[nLast - 1]["KDJLMin"] = signalVecValueKDJ[2].ToString("F4", System.Globalization.CultureInfo.InvariantCulture);
                _indicatorOutput.Rows[nLast - 1]["KDJLMax"] = signalVecValueKDJ[3].ToString("F4", System.Globalization.CultureInfo.InvariantCulture);
                _indicatorOutput.Rows[nLast - 1]["KDJTurn"] = signalVecValueKDJ[4].ToString("F4", System.Globalization.CultureInfo.InvariantCulture);

                _indicatorOutput.Rows[nLast - 1]["RSI"] = signalVecValueRSI[0].ToString("F4", System.Globalization.CultureInfo.InvariantCulture);
                _indicatorOutput.Rows[nLast - 1]["RSIBuySell"] = signalVecValueRSI[1].ToString("F4", System.Globalization.CultureInfo.InvariantCulture);
                _indicatorOutput.Rows[nLast - 1]["RSILMin"] = signalVecValueRSI[2].ToString("F4", System.Globalization.CultureInfo.InvariantCulture);
                _indicatorOutput.Rows[nLast - 1]["RSILMax"] = signalVecValueRSI[3].ToString("F4", System.Globalization.CultureInfo.InvariantCulture);
                _indicatorOutput.Rows[nLast - 1]["RSITurn"] = signalVecValueRSI[4].ToString("F4", System.Globalization.CultureInfo.InvariantCulture);

                _indicatorOutput.Rows[nLast - 1]["TAlibRSI"] = TAlibRSI.ToString("F4", System.Globalization.CultureInfo.InvariantCulture);

                _indicatorOutput.Rows[nLast - 1]["ComSVM"] = signalVecValueComSVM[0].ToString("F4", System.Globalization.CultureInfo.InvariantCulture);
                _indicatorOutput.Rows[nLast - 1]["ComSVMTurnRealized"] = signalVecValueComSVM[1].ToString("F4", System.Globalization.CultureInfo.InvariantCulture);
                _indicatorOutput.Rows[nLast - 1]["ComSVMSignalSum"] = signalVecValueComSVM[2].ToString("F4", System.Globalization.CultureInfo.InvariantCulture);

                _indicatorOutput.Rows[nLast - 1]["aSVM"] = aSVM.ToString().ToString();
                _indicatorOutput.Rows[nLast - 1]["bSVM"] = bSVM.ToString().ToString();
                _indicatorOutput.Rows[nLast - 1]["cSVM"] = cSVM.ToString().ToString();

                for (Int32 ii = 0; ii < tmpStringvec.Length; ii++)
                {
                    tmpStringvec[ii] = tmpStringvec[ii].Replace(Decimal.MaxValue.ToString("F4", System.Globalization.CultureInfo.InvariantCulture), "NaN");
                }
                sendindicators(tmpStringvec);

                isLong = (Math.Abs(signalVecValueComSVM[0]) == 1) && (signalVecValueRSI[4] + signalVecValueKDJ[4] + signalVecValueMACD[4] > 0);
                isShort = (Math.Abs(signalVecValueComSVM[0]) == 1)&& (signalVecValueRSI[4] + signalVecValueKDJ[4] + signalVecValueMACD[4] < 0);
            }
            
            if (!_wait[symbol])
            {
                // if we're flat and not waiting
                if (pt[symbol].isFlat)
                {
                    Boolean side = true;
                    Decimal adj = 1;
                    // if we get long signal, buy
                    if (isLong)
                    {
                        side = true;
                        adj = (side ? -1 : +1) * _quasiMarketOrderAdjSize;
                        D("Long Signal, buy");
                        D("Close:" + blt[symbol].RecentBar.Close.ToString() );
                        LimitOrder lOrder = new LimitOrder(symbol, true, EntrySize, tOther.trade - adj);
                        D("Order buy:" + lOrder.ToString() + "wait:" + _wait[symbol].ToString());
                        O(lOrder);
                        // wait for fill
                        _wait[symbol] = true;
                    }
                    // otherwise if we get short signal, sell
                    if (isShort)
                    {
                        side = false;
                        adj = (side ? -1 : +1) * _quasiMarketOrderAdjSize;
                        D("Short Signal, sell");
                        D("Close:" + blt[symbol].RecentBar.Close.ToString());
                        LimitOrder lOrder = new LimitOrder(symbol, false, EntrySize, tOther.trade - adj);
                        D("Order sell:" + lOrder.ToString() + "wait:" + _wait[symbol].ToString());
                        O(lOrder);
                        // wait for fill
                        _wait[symbol] = true;
                    }
                }
                else if ((pt[symbol].isLong && isShort)
                    || (pt[symbol].isShort &&isLong))
                {
                    D("counter signal, exit.");
                    Boolean side = !pt[symbol].isLong;
                    Decimal adj = (side ? -1 : +1) * _quasiMarketOrderAdjSize;
                    LimitOrder lOrder = new LimitOrder(symbol, side, EntrySize, tOther.trade - adj);
                    D("Order close:" + lOrder.ToString() + "wait:" + _wait[symbol].ToString());
                    O(lOrder);
                    // wait for fill
                    _wait[symbol] = true;
                }
            }
        }

        // turn on bar tracking
        BarListTracker blt = new BarListTracker();
        // turn on position tracking
        PositionTracker pt = new PositionTracker();

        // got tick is called whenever this strategy receives a tick
        public override void GotTick(Tick tick)
        {
            // ignore anything that is not a trade
            if (!tick.isValid||!tick.isTrade)
            {
                return;
            }        
            // ensure response is active
            if (!isValid) return;

            // ensure we are tracking active status for this symbol
            int idx = _active.addindex(tick.symbol, true);
            // if we're not active, quit
            if (!_active[idx]) return;
            // check for shutdown time
            if (tick.time > Shutdown)
            {
                // if so shutdown
                shutdown();
                // and quit
                return;
            }
            // apply bar tracking to all ticks that enterz
            _kt.newTick(tick);
            blt.newTick(tick);
            // exits are processed first, lets see if we have our total profit
            if ((Calc.OpenPL(tick.trade, pt[tick.symbol]) + pt[tick.symbol].ClosedPL) * ContractSize > TotalProfitTarget)
            {
                // if we hit our target, shutdown trading on this symbol
                shutdown(tick.symbol);
                // don't process anything else after this (entries, etc)
                return;
            }

        }

        void shutdown()
        {
            D("shutting down everything");
            foreach (Position p in pt)
            {
                Tick tOther = _kt[p.symbol];
                Boolean side = !p.isLong;
                Decimal adj = (side ? -1 : +1) * _quasiMarketOrderAdjSize;
                LimitOrder lOrder = new LimitOrder(p.symbol, side, p.UnsignedSize, tOther.trade - adj);
                O(lOrder);
            }
            isValid = false;
        }

        void shutdown(string sym)
        {
            // notify
            D("shutting down " + sym);
            // send flat order
            Tick tOther = _kt[sym];
            Boolean side = !pt[sym].isLong;
            Decimal adj = (side ? -1 : +1) * _quasiMarketOrderAdjSize;
            LimitOrder lOrder = new LimitOrder(sym, side, pt[sym].UnsignedSize, tOther.trade - adj);
            O(lOrder);
            // set inactive
            _active[sym] = false;
        }

        public override void GotFill(Trade fill)
        {
            // make sure every fill is tracked against a position
            pt.Adjust(fill);
            // get index for this symbol
            int idx = _wait.getindex(fill.symbol);
            D("Fill:" + fill.ToString() + " idx:" + idx.ToString());
            // ignore unknown symbols
            if (idx < 0) return;
            // stop waiting
            _wait[fill.symbol] = false;
        }

        public override void GotPosition(Position p)
        {
            // make sure every position set at strategy startup is tracked
            pt.Adjust(p);
        }

        // these variables "hold" the parameters set by the user above
        // also they are the defaults that show up first       
        int _entrysize = 1;
        decimal _totalprofit = 200000*300;
        int _shutdowntime = 155000;
        decimal _quasiMarketOrderAdjSize = 100m;
        decimal _contractSize = 1;
    }


#warning If you get errors about missing references to TradeLink.Common or TradeLink.Api, choose Project->Add Reference->Browse to folder where you installed tradelink (usually Program Files) and add a reference for each dll.
}
