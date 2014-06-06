using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using TradeLink.Common;
using TradeLink.API;
using System.ComponentModel;
using MathUtilityCommon;
using System.IO;

namespace Responses
{
    class SVMResponse : ResponseTemplate
    {
        BarInterval _barinterval = BarInterval.CustomTicks;
        [Description("Bar interval for this response.")]
        public BarInterval Interval { get { return _barinterval; } set { _barinterval = value; } }
        [Description("Number of Customticks in Bar interval for this response, only used with custom ticks.")]
        public int CustomBarInterval { get { return _customBarinterval; } set { _customBarinterval = value; } }
        int _customBarinterval = 4;
        BarListTracker blt = new BarListTracker();
        bool _black = false;
        int _NBarPrd = 15;
        [Description("# of Bars in trading periods.")]
        public int TradingPeriod { get { return _NBarPrd; } set { _NBarPrd = value; } }
        int _trainSetSz = 100;
        [Description("# of Trading Periods for Training.")]
        public int TradingSetSize { get { return _trainSetSz; } set { _trainSetSz = value; } }
        int _udinterval = 5;
        [Description("# of Trading Periods between Training Update")]
        public int TrainingUpdateInterval { get { return _udinterval; } set { _udinterval = value; } }
        int _nHorizon = 5;
        [Description("# of Bars in horizon")]
        public int HorizonInterval { get { return _nHorizon; } set { _nHorizon = value; } }
        int time = 0;
        [Description("Future Contract Size")]
        public decimal ContractSize { get { return _contractSize; } set { _contractSize = value; } }
        [Description("shutdown time")]
        public int Shutdown { get { return _shutdowntime; } set { _shutdowntime = value; } }
        [Description("Total Profit Target")]
        public decimal TotalProfitTarget { get { return _totalprofit; } set { _totalprofit = value; } }
        decimal _takeProfitTrigger = 0.02m;
        [Description("TakeProfitTrigger")]
        public decimal TakeProfitTrigger { get { return _takeProfitTrigger; } set { _takeProfitTrigger = value; } }
        decimal _stopLossTrigger = -0.02m;
        [Description("StopLossTrigger")]
        public decimal StopLossTrigger { get { return _stopLossTrigger; } set { _stopLossTrigger = value; } }
        int _scaleSvmPeriods = 0;
        [Description("# of Periods for updating SVM variable Scales")]
        public int scaleSVMPeriods { get { return _scaleSvmPeriods; } set { _scaleSvmPeriods = value; } }
        [Description("Flag SVM Parameter Grid Search")]
        bool _svmpParamGridSrch = false;
        public bool svmGridSearch { get { return _svmpParamGridSrch; } set { _svmpParamGridSrch = value; } }


        struct tpVariable
        {
            public decimal rCl;
            public decimal rVlm;
            public decimal tRet;
            public decimal retstd;
            public decimal maxprc;
            public decimal minprc;
            public decimal vlm;
            public decimal close;
        }

        GenericTracker<bool> _wait = new GenericTracker<bool>();
        PositionTracker pt = new PositionTracker();
        Dictionary<string, tpVariable> tpVlist = new Dictionary<string, tpVariable>();
        Dictionary<string, SupportedVectorMachine> _mdls = new Dictionary<string, SupportedVectorMachine>();
        // number of consecutive holding periods if held position;
        Dictionary<string, int> _heldperiod = new Dictionary<string, int>();
        // track whether shutdown 
        GenericTracker<bool> _active = new GenericTracker<bool>();
        TickTracker _kt = new TickTracker();

        public override void Reset()
        {
            ParamPrompt.Popup(this, true, _black);
            int rem = 0;
            int qt = Math.DivRem(_scaleSvmPeriods, _trainSetSz, out rem);
            if (rem != 0) throw new Exception("# of periods for svm scale updates needs to be multiples of training set size");
            int[] customintervals = new int[1];
            customintervals[0] = CustomBarInterval;
            BarInterval[] intervaltypes = new BarInterval[1];
            intervaltypes[0] = Interval;
            // only build bars for user's interval
            if (Interval == BarInterval.CustomTicks)
                blt = new BarListTracker(customintervals, intervaltypes);
            else
                blt = new BarListTracker(Interval);
            // only calculate on new bars
            blt.GotNewBar += new SymBarIntervalDelegate(blt_GotNewBar);
            _active.NewTxt += new TextIdxDelegate(_active_NewTxt);
            int freq = Math.DivRem(_trainSetSz, _udinterval, out rem);
            if (rem != 0) throw new Exception("TrainingSetSize set needs to be multiple of trainingUpdateInterval");
            Indicators = new string[] { "Date", "Time", "Cross Valid Accuracy", "Prediction Accuracy" };
        }

        void _active_NewTxt(string txt, int idx)
        {
            // go ahead and notify any other trackers about this symbol
            _wait.addindex(txt, false);
            _kt.addindex(txt);
        }

        // calculate trade period variables to be used in model
        void calcTpVariables(string symbol, int interval, int barsBack, out tpVariable tpV)
        {
            decimal avgprc = 0, maxprc = 0, minprc = 0, tRet = 0, retstd = 0, ret = 0, rCl, rVlm, avgvlm = 0;
            BarList myBarList = blt[symbol, interval];
            Int32 n = myBarList.Count;
            if (n < _NBarPrd + barsBack) throw new Exception("not enough bars to perform operation");
            int nCurr = n - barsBack;
            tRet = myBarList[nCurr - 2].Close - myBarList[nCurr - _NBarPrd - 2].Close; 
            maxprc = myBarList[nCurr - 2].High;
            minprc = myBarList[nCurr - 2].Low;
            for (int i = 0; i < _NBarPrd; i++)
            {
                avgprc += myBarList[nCurr - i - 2].Close;
                avgvlm += (int)myBarList[nCurr - i - 2].Volume;
                maxprc = Math.Max(maxprc, myBarList[nCurr - i - 2].High);
                minprc = Math.Min(minprc, myBarList[nCurr - i - 2].Low);
                ret = myBarList[nCurr - i - 2].Close - myBarList[nCurr - i - 3].Close;
                retstd += (decimal)Basic.mySquare((double)(ret - tRet / _NBarPrd));
            }
            // return vol
            avgprc /= _NBarPrd;
            avgvlm /= _NBarPrd;
            retstd /= (decimal)(_NBarPrd - 1);
            retstd = (decimal)Math.Pow((double)retstd, 0.5);
            rCl = myBarList[nCurr - 2].Close / avgprc;
            rVlm = avgvlm == 0 ? 0 : myBarList[nCurr - 2].Volume / avgvlm;
            maxprc /= avgprc;
            minprc /= avgprc;
            tpVariable ltpv = new tpVariable();
            ltpv.rCl = rCl;
            ltpv.rVlm = rVlm; 
            ltpv.tRet = tRet;
            ltpv.retstd = retstd;
            ltpv.maxprc = maxprc; 
            ltpv.minprc = minprc;         
            ltpv.close = myBarList[nCurr - 2].Close;
            ltpv.vlm = myBarList[nCurr - 2].Volume;
            tpV = ltpv;
            return;
        }

        void updateSVM(string symbol, int interval)
        {
            Double barCount = blt[symbol].Count;
            String tmp = "Bar Count " + barCount.ToString();
            // update the svm data set
            BarList myBarList = blt[symbol, interval];
            Int32 n = myBarList.Count;
            if (n < _nHorizon + 1) return;
            decimal close = myBarList[n - 2].Close;
            decimal open = myBarList[n - 2 - _nHorizon].Close;
            int rem = 0,qt = 0;
            if(_scaleSvmPeriods > 0) 
                qt = Math.DivRem(n-_NBarPrd-_nHorizon, _scaleSvmPeriods, out rem);

            if (!tpVlist.ContainsKey(symbol)) return;

            // determine calss id

            int classId = 0;
            if ((close - open) / open > 0.0001m) classId = 1;
            if ((close - open) / open < -0.0001m) classId = -1;
            // this last nHorizon periods determine the class of the previous 
            // nHorizon periods  
            if (!_mdls.ContainsKey(symbol))
            {
                _mdls.Add(symbol, new SupportedVectorMachine(_trainSetSz, 8, _trainSetSz / _udinterval));
                //_mdls[symbol]._param.probability = 1;
                _mdls[symbol].autoGridSearch = svmGridSearch;

                _mdls[symbol]._paramGS.gamma_start = 3;
                _mdls[symbol]._paramGS.gamma_end = -15;
                _mdls[symbol]._paramGS.gamma_step = -2;
                _mdls[symbol]._paramGS.C_start = -5;
                _mdls[symbol]._paramGS.C_end = 15;
                _mdls[symbol]._paramGS.C_step = 2;
            }
            if (_scaleSvmPeriods > 0)
            {
                if (rem == 0) _mdls[symbol].updateScale = true;
                else _mdls[symbol].updateScale = false;
            }
            tpVariable tpv = tpVlist[symbol];
            List<decimal> features = new List<decimal>();
            features.Add(tpv.rCl); //
            features.Add(tpv.rVlm);
            features.Add(tpv.tRet);
            features.Add(tpv.retstd);
            features.Add(tpv.maxprc);//
            features.Add(tpv.minprc);//
            features.Add(tpv.close);//
            features.Add(tpv.vlm);
            // more than one current case is possible, each of them are missing class id. 
            _mdls[symbol].addCurrentCase(features);

            // current class is for the case _nHorizon periods earlier
            if (_mdls[symbol].numCurrentCases > _nHorizon) _mdls[symbol].setCurrentClass(classId);
        }

        void blt_GotNewBar(string symbol, int interval)
        {
            Tick tOther = _kt[symbol];
            Double barCount = blt[symbol].Count;
            String tmp = "Bar Count " + barCount.ToString();
            // update the svm data set
            BarList myBarList = blt[symbol, interval];
            Int32 n = myBarList.Count; 
            // we are at ntp trading periods, within which iBr bar 
            int iBr;
            int ntp = Math.DivRem(n, _NBarPrd, out iBr);
            tpVariable tpV;
            if (n < TradingPeriod + _nHorizon+1) return; 
            calcTpVariables(symbol, interval, 0, out tpV);
            if (!tpVlist.ContainsKey(symbol)) tpVlist.Add(symbol, new tpVariable());
            tpVlist[symbol] = tpV;
            updateSVM(symbol, interval); 

            // skip if model is not ready
            if (!_mdls.ContainsKey(symbol) || !_mdls[symbol].isValid()) return;
            decimal lastClose = myBarList.RecentBar.Close;
            // predict based on current case
            List<int> clss = new List<int>();
            List<double> probs = new List<double>();
            int classId = _mdls[symbol].predict(ref clss, ref probs); 
            Position pstn;
            if (_wait.getindex(symbol) < 0) _wait.addindex(symbol, false);
            if (!_wait[symbol]) // we are not waiting for fill
            {
                pstn = pt[symbol];
                if (pt[symbol].isFlat)
                {
                    if (classId > 0)
                    {
                        D("class 1 price increase over horizon, buy");
                        Decimal adj = -_quasiMarketOrderAdjSize;
                        sendorder(new BuyLimit(symbol, 1, tOther.trade - adj));
                        // wait for fill
                        _wait[symbol] = true;
                        _heldperiod.Add(symbol, 0);
                    }
                    else if (classId < 0)
                    {
                        D("class -1 price decrease over horizon, sell");
                        Decimal adj = _quasiMarketOrderAdjSize;
                        sendorder(new SellLimit(symbol, 1, tOther.trade - adj));
                        // wait for fill
                        _wait[symbol] = true;   
                        _heldperiod.Add(symbol, 0);
                    }
                }
                else if (_heldperiod.ContainsKey(symbol)) // otherwise this position should be in process of being cleared.
                {
                    // flat if pass horison
                    _heldperiod[symbol]++;
                    if (_heldperiod[symbol] >= _nHorizon)
                    {
                        D("pass horizon, flat");
                        Boolean side = !pt[symbol].isLong;
                        Decimal adj = (side ? -1 : +1) * _quasiMarketOrderAdjSize;
                        LimitOrder lorder = new LimitOrder(symbol, side, pt[symbol].UnsignedSize, tOther.trade - adj);
                        O(lorder);
                        _wait[symbol] = true;
                        _heldperiod.Remove(symbol);
                    }
                }
            }
            // report svm cross valid and prediction accuracies
            double crsacrcy = _mdls[symbol].crossVldAccuracy;
            double pacrcy = _mdls[symbol].PredictionAccuracy;

            sendindicators(new string[] { tOther.date.ToString(), time.ToString(), crsacrcy.ToString("F2", System.Globalization.CultureInfo.InvariantCulture), pacrcy.ToString("F2", System.Globalization.CultureInfo.InvariantCulture) });

            // exits are processed first, lets see if we have our total profit
            if ((Calc.OpenPL(tOther.trade, pt[tOther.symbol]) + pt[tOther.symbol].ClosedPL) * ContractSize > TotalProfitTarget)
            {
                // if we hit our target, shutdown trading on this symbol
                shutdown(tOther.symbol);
                // don't process anything else after this (entries, etc)
                return;
            }
            decimal prc = tOther.trade;
            pstn = pt[tOther.symbol];
            // check profit and loss limits and act accordingly
            decimal pl = Calc.OpenPL(prc, pstn);
            // if no hold period info, should be residual position in the middle of being cleared. 
            if (!_heldperiod.ContainsKey(tOther.symbol)) return;
            /*
            if (_heldperiod[tick.symbol] <= _nHorizon / 2) return; // hold at least till the middle of horizon  
             */
            if (!pstn.isFlat && !_wait[tOther.symbol] &&
                (pl > TakeProfitTrigger * pstn.AvgPrice * pstn.UnsignedSize || pl < StopLossTrigger * pstn.AvgPrice * pstn.UnsignedSize))
            {
                string msg = pl > TakeProfitTrigger * pstn.AvgPrice * pstn.UnsignedSize ? "profit limt" : "stop loss limimt";
                D(msg);
                Boolean side = !pstn.isLong;
                Decimal adj = (side ? -1 : +1) * _quasiMarketOrderAdjSize;
                LimitOrder lorder = new LimitOrder(tOther.symbol, side, pstn.UnsignedSize, tOther.trade - adj);
                O(lorder);
                _wait[tOther.symbol] = true;
                _heldperiod.Remove(tOther.symbol);
            }
            return;
        }

        public override void GotFill(Trade fill)
        {
            // make sure every fill is tracked against a position
            pt.Adjust(fill);
            Position pstn = (Position)pt[fill.symbol];
            // get index for this symbol
            int idx = _wait.getindex(fill.symbol);
            // ignore unknown symbols
            if (idx < 0) return;
            // stop waiting
            _wait[fill.symbol] = false;
        }

        public override void GotTick(Tick tick)
        {
            // ignore anything that is not a trade
            if (!tick.isValid || !tick.isTrade)
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
            time = tick.time;
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

        decimal _totalprofit = 200000 * 300;
        int _shutdowntime = 155000;
        decimal _quasiMarketOrderAdjSize = 100m;
        decimal _contractSize = 1;
    }

}
