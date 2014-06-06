using System;
using System.Collections.Generic;
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


namespace Responses
{
    public class BarTickChecking : ResponseTemplate
    {
        // parameters of this system
        BarInterval _barType = BarInterval.CustomTicks;//"Time","Volume"
        [Description("BarType")]
        public BarInterval BarType { get { return _barType; } set { _barType = value; } }
        int _numTickPerBar = 5;
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
        [Description("shutdown time")]
        public int Shutdown { get { return _shutdowntime; } set { _shutdowntime = value; } }
        Boolean _checkTick = false;
        [Description("CheckTick")]
        public Boolean CheckTick { get { return _checkTick; } set { _checkTick = value; } }
        Boolean _swapTick = false;
        [Description("SwapTick")]
        public Boolean SwapTick { get { return _swapTick; } set { _swapTick = value; } }
        Int32 CheckTickIndex = 0;
        //String _checkTickPath = @"D:\AlbertTradingStation\AlbertTradingStationGlobalFast\TikData\WAG20070926.TIK";
        String _checkTickPath = @"D:\AlbertTradingStation\AlbertTradingStationGlobalFast\TikData\index\JqDCsSD0yHi7LLnxilNGw==0.TIK";
        [Description("CheckTickPath")]
        public String CheckTickPath { get { return _checkTickPath; } set { _checkTickPath = value; } }
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

        List<Decimal> _gindData = new List<Decimal>();
        double[] barCloseVec = new double[50000];

        bool _black = false;
        // this function is called the constructor, because it sets up the response
        // it is run before all the other functions, and has same name as my response.
        public BarTickChecking() : this(true) { }
        
        public BarTickChecking(bool prompt)
        {
            _black = !prompt;
            // handle when new symbols are added to the active tracker
            _active.NewTxt += new TextIdxDelegate(_active_NewTxt);

            // set our indicator names, in case we import indicators into R
            // or excel, or we want to view them in gauntlet or kadina
            Indicators = new string[] { "Symbol", "Date", "Time", "O", "H", "L", "C", "Vol", "CBardate", "CBCount", "MACD", "MACDBuySell", "MACDLMin", "MACDLMax", "MACDTurn", "TAlibMacd", "KDJ", "KDJBuySell", "KDJLMin", "KDJLMax", "KDJTurnx", "RSI", "RSIBuySell", "RSILMin", "RSILMax", "RSITurn", "TAlibRSI", "ComSVM", "ComSVMTurnRealized", "ComSVMSignalSum", };
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
            if (CheckTick)
            {
                CheckTickIndex = 0;
            }

            Hashtable macdInputParam = new Hashtable();
            macdInputParam["lookbackperiodlong"] = 26;
            macdInputParam["lookbackperiodlongalpha"] = -10000;
            macdInputParam["lookbackperiodshort"] = 12;
            macdInputParam["lookbackperiodshortalpha"] = -10000;
            macdInputParam["lookbackperiodave"] = 9;
            macdInputParam["lookbackperiodavealpha"] = -10000;
            macdInputParam["minmumsignallength"] = 9+26-2;
            macdInputParam["calcturningpoint"] = "true";
            macdInputParam["setemaminmumsignallength"] = "true";

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
            _myRSI = new RSI();
            _myRSI.Param = RSIInputParam;
            _myRSI.Initializatin();
            _myRSIForSVM = new RSI();
            _myRSIForSVM.Param = RSIInputParam;
            _myRSIForSVM.Initializatin();

            Hashtable ComSVMInputParam = new Hashtable();
            // SVM param
            ComSVMInputParam["casesfortraining"] = 100;
            ComSVMInputParam["featureseachcase"] = 3;
            ComSVMInputParam["retrainfreq"] = 10;
            //ComSVMInputParam["svmtrainfreq"] = 10;
            // Wavelet param
            ComSVMInputParam["wtrunctionmethod"] = "heursure";
            ComSVMInputParam["wmotherfunction"] = "db4";
            ComSVMInputParam["wextensionmode"] = "ZeroPadding";
            ComSVMInputParam["wlookbckperiod"] = 16;
            ComSVMInputParam["wtransoformlevelshift"] = 0;
            // other param
            ComSVMInputParam["minmumsignallength"] = 100;
            ComSVMInputParam["calcturningpoint"] = "true";

            _myComSVM = new CompositeSVM();
            _myComSVM.Param = ComSVMInputParam;
            _myComSVM.Initializatin();
            _myComSVM.UpdateIndicator(_myMacdForSVM);
            _myComSVM.UpdateIndicator(_myKDJForSVM);
            _myComSVM.UpdateIndicator(_myRSIForSVM);

            _gindData.Clear();
        }

        // wait for fill
        GenericTracker<bool> _wait = new GenericTracker<bool>();
        // track whether shutdown 
        GenericTracker<bool> _active = new GenericTracker<bool>();      

        TickTracker _kt = new TickTracker();
        List<Tick> _mem = new List<Tick>();

        void HistSource_gotTick(Tick tick)
        {
            _mem.Add(tick);
        }

        void _active_NewTxt(string txt, int idx)
        {
            // go ahead and notify any other trackers about this symbol
            _wait.addindex(txt, false);
            _kt.addindex(txt);
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
            
            Decimal[] valueVecKDJ = new Decimal[3];
            valueVecKDJ[0] = valueForGInd;
            valueVecKDJ[1] = _lastBar.High;
            valueVecKDJ[2] = _lastBar.Low;

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
                Decimal[] signalVecValueMACD = new Decimal[5];
                _myMacd.GetSignalVec(ref signalVecValueMACD);
                Decimal[] signalVecValueKDJ = new Decimal[5];
                _myKDJ.GetSignalVec(ref signalVecValueKDJ);
                Decimal[] signalVecValueRSI = new Decimal[5];
                _myRSI.GetSignalVec(ref signalVecValueRSI);
                Decimal[] signalVecValueComSVM = new Decimal[5];
                _myComSVM.GetSignalVec(ref signalVecValueComSVM);
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
                    });

                for (Int32 ii = 0; ii < tmpStringvec.Length; ii++)
                {
                    tmpStringvec[ii] = tmpStringvec[ii].Replace(Decimal.MaxValue.ToString("F4", System.Globalization.CultureInfo.InvariantCulture), "NaN");
                }
                sendindicators(tmpStringvec);
                isLong = signalVecValueComSVM[0] == 1;
                isShort = signalVecValueComSVM[0] == -1;
            }
            
            if (!_wait[symbol])
            {
                // if we're flat and not waiting
                if (pt[symbol].isFlat)
                {
                    Boolean side = pt[symbol].isLong;
                    Decimal adj = side ? -1 : +1;
                    adj *= _quasiMarketOrderAdjSize;
                    // if we get long signal, buy
                    if (isLong)
                    {
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
                    Decimal adj = side?-1:+1;
                    adj *= _quasiMarketOrderAdjSize;
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

        // keep track of time for use in other functions
        int time = 0;
        
        Boolean isTickSame(Tick tickFromFile, Tick tickInMemory)
        {
            Boolean sameTick = true;
            Boolean tmp = tickFromFile.trade != tickInMemory.trade;
            tmp = tmp || tickFromFile.bid != tickInMemory.bid;
            tmp = tmp || tickFromFile.bs != tickInMemory.bs;
            tmp = tmp || tickFromFile.ask != tickInMemory.ask;
            tmp = tmp || tickFromFile.AskSize != tickInMemory.AskSize;
            tmp = tmp || tickFromFile.date != tickInMemory.date;
            tmp = tmp || tickFromFile.time != tickInMemory.time;
            sameTick = !tmp;

            if (!sameTick)
            {
                D("File-" + tickFromFile.ToString() + "Mem-" + tickInMemory.ToString());
            }
            return sameTick;

        }

        // got tick is called whenever this strategy receives a tick
        public override void GotTick(Tick tick)
        {
            if (!tick.isValid)
            {
                return;
            }
            if (CheckTick)
            {
                if (_mem.Count == 0 && CheckTick)
                {
                    FileInfo fi = new FileInfo(CheckTickPath);
                    try
                    {
                        SecurityImpl saveTickSource = SecurityImpl.FromTIK(CheckTickPath);
                        saveTickSource.HistSource.gotTick += new TickDelegate(HistSource_gotTick);
                        while (saveTickSource.HistSource.NextTick()) ;
                        saveTickSource.HistSource.Close();
                    }
                    catch
                    {
                        D(CheckTickPath + " can not be read");
                    }
                }

                // compare tick first
                Tick tickFromMem = _mem[CheckTickIndex];
                if (SwapTick)
                {
                    tick = tickFromMem;
                }
                isTickSame(tickFromMem, tick);
                CheckTickIndex++;
            }
            // keep track of time from tick
            time = tick.time;
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

            // ignore anything that is not a trade
            if (!tick.isTrade) return;

            // if we made it here, we have enough bars and we have a trade.

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
                sendorder(new MarketOrderFlat(p));
            isValid = false;
        }

        void shutdown(string sym)
        {
            // notify
            D("shutting down " + sym);
            // send flat order
            sendorder(new MarketOrderFlat(pt[sym]));
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
            // chart fills
            sendchartlabel(fill.xprice, time, TradeImpl.ToChartLabel(fill), fill.side ? System.Drawing.Color.Green : System.Drawing.Color.Red);
        }

        public override void GotPosition(Position p)
        {
            // make sure every position set at strategy startup is tracked
            pt.Adjust(p);
        }

        // these variables "hold" the parameters set by the user above
        // also they are the defaults that show up first       
        int _entrysize = 1;
        decimal _totalprofit = 20*300;
        int _shutdowntime = 155000;
        decimal _quasiMarketOrderAdjSize = 1m;
        decimal _contractSize = 300;
    }


#warning If you get errors about missing references to TradeLink.Common or TradeLink.Api, choose Project->Add Reference->Browse to folder where you installed tradelink (usually Program Files) and add a reference for each dll.
}
