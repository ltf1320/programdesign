using System;
using System.Collections.Generic;
using System.Data;
using System.Text;
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
    public class SVMCompositeMulti : ResponseTemplate
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
        Boolean _synWithSVM = true;
        [Description("SynWithSVM")]
        public Boolean SynWithSVM { get { return _synWithSVM; } set { _synWithSVM = value; } }
        [Description("shutdown time")]
        public int Shutdown { get { return _shutdowntime; } set { _shutdowntime = value; } }       
        Boolean _useBarCloseForGInd = true;
        [Description("UseBarCloseForGInd")]
        public Boolean UseBarCloseForGInd { get { return _useBarCloseForGInd; } set { _useBarCloseForGInd = value; } }
        Boolean _isFullFeatures = false;
        [Description("IsFullFeatures")]
        public Boolean IsFullFeatures { get { return _isFullFeatures; } set { _isFullFeatures = value; } }
        String _gindPeriod = "supereight:1";
        [Description("GindPeriod")]
        public String GindPeriod { get { return _gindPeriod; } set { _gindPeriod = value; } }
        Int32 _SVMType = 1;
        [Description("SVMType")]
        public Int32 SVMType { get { return _SVMType; } set { _SVMType = value; } }
        Int32 _SVMProbability = 0;
        [Description("SVMProbability")]
        public Int32 SVMProbability { get { return _SVMProbability; } set { _SVMProbability = value; } }
        Decimal _svmCValue = 0.5m;
        [Description("SvmCValue")]
        public Decimal SvmCValue { get { return _svmCValue; } set { _svmCValue = value; } }
        Decimal _svmGammaValue = 0.5m;
        [Description("SvmGammaValue")]
        public Decimal SvmGammaValue { get { return _svmGammaValue; } set { _svmGammaValue = value; } }
        Int32 _casesfortraining = 200;
        [Description("Casesfortraining")]
        public Int32 Casesfortraining { get { return _casesfortraining; } set { _casesfortraining = value; } }
        Int32 _casesfortrainingFirst = 200;
        [Description("CasesfortrainingFirst")]
        public Int32 CasesfortrainingFirst { get { return _casesfortrainingFirst; } set { _casesfortrainingFirst = value; } }
        Int32 _featureseachcase = 1;
        [Description("Featureseachcase")]
        public Int32 Featureseachcase { get { return _featureseachcase; } set { _featureseachcase = value; } }
        Int32 _retrainfreq = 10;
        [Description("Retrainfreq")]
        public Int32 Retrainfreq { get { return _retrainfreq; } set { _retrainfreq = value; } }
        Int32 _svmtrainfreq = 10;
        [Description("Svmtrainfreq")]
        public Int32 Svmtrainfreq { get { return _svmtrainfreq; } set { _svmtrainfreq = value; } }
        Int32 _svmgridsearchfreq = 200;
        [Description("Svmgridsearchfreq")]
        public Int32 Svmgridsearchfreq { get { return _svmgridsearchfreq; } set { _svmgridsearchfreq = value; } }
        Boolean _calcturningpoint = true;
        [Description("Calcturningpoint")]
        public Boolean Calcturningpoint { get { return _calcturningpoint; } set { _calcturningpoint = value; } }
        Boolean _useabsturningvalue = false;
        [Description("Useabsturningvalue")]
        public Boolean Useabsturningvalue { get { return _useabsturningvalue; } set { _useabsturningvalue = value; } }
        Decimal _turningPointValueTol = 0.0085m;
        [Description("TurningPointValueTol")]
        public Decimal TurningPointValueTol { get { return _turningPointValueTol; } set { _turningPointValueTol = value; } }
        Decimal _realzedTurnPointTol = 0.01m;
        [Description("RealzedTurnPointTol")]
        public Decimal RealzedTurnPointTol { get { return _realzedTurnPointTol; } set { _realzedTurnPointTol = value; } }
        Boolean _isExtendedTurnPoint = true;
        [Description("IsExtendedTurnPoint")]
        public Boolean IsExtendedTurnPoint { get { return _isExtendedTurnPoint; } set { _isExtendedTurnPoint = value; } }
        Boolean _issingletrain = true;
        [Description("isSingleTrain")]
        public Boolean isSingleTrain { get { return _issingletrain; } set { _issingletrain = value; } }

        Int32 wtransoformlevelshift = -3000;
        [Description("Wtransoformlevelshift")]
        public Int32 Wtransoformlevelshift { get { return wtransoformlevelshift; } set { wtransoformlevelshift = value; } }

        decimal _takeProfitTrigger =  6m / 2300;
        [Description("TakeProfitTrigger")]
        public decimal TakeProfitTrigger { get { return _takeProfitTrigger; } set { _takeProfitTrigger = value; } }
        decimal _takeProfitTriggerShort = 6m / 2300;
        [Description("TakeProfitTriggerShort")]
        public decimal TakeProfitTriggerShort { get { return _takeProfitTriggerShort; } set { _takeProfitTriggerShort = value; } }
        decimal _stopLossTrigger = - 6m / 2300;
        [Description("StopLossTrigger")]
        public decimal StopLossTrigger { get { return _stopLossTrigger; } set { _stopLossTrigger = value; } }
        decimal _stopLossTriggerShort = -6m / 2300;
        [Description("StopLossTriggerShort")]
        public decimal StopLossTriggerShort { get { return _stopLossTriggerShort; } set { _stopLossTriggerShort = value; } }

        decimal _trailingStopExitTrigger = 6m / 2300;
        [Description("TrailingStopExitTrigger")]
        public decimal TrailingStopExitTrigger { get { return _trailingStopExitTrigger; } set { _trailingStopExitTrigger = value; } }

        decimal _trailingStopExitTriggerShort = 6m / 2300;
        [Description("TrailingStopExitTriggerShort")]
        public decimal TrailingStopExitTriggerShort { get { return _trailingStopExitTriggerShort; } set { _trailingStopExitTriggerShort = value; } }


        decimal _stopNewTradeTrigger = 0m;
        [Description("StopNewTradeTrigger")]
        public decimal StopNewTradeTrigger { get { return _stopNewTradeTrigger; } set { _stopNewTradeTrigger = value; } }
        decimal _stopNewLongTradeTrigger = -100000000m;
        [Description("StopNewLongTradeTrigger")]
        public decimal StopNewLongTradeTrigger { get { return _stopNewLongTradeTrigger; } set { _stopNewLongTradeTrigger = value; } }
        decimal _stopNewShortTradeTrigger = -100000000m;
        [Description("StopNewShortTradeTrigger")]
        public decimal StopNewShortTradeTrigger { get { return _stopNewShortTradeTrigger; } set { _stopNewShortTradeTrigger = value; } }

        Int32 _longSideTradeLimit = 2000000;
        [Description("LongSideTradeLimit")]
        public Int32 LongSideTradeLimit { get { return _longSideTradeLimit; } set { _longSideTradeLimit = value; } }
        Int32 _shortSideTradeLimit = 2000000;
        [Description("ShortSideTradeLimit")]
        public Int32 ShortSideTradeLimit { get { return _shortSideTradeLimit; } set { _shortSideTradeLimit = value; } }
        Int32 _bothSideTradeLimit = 2000000;
        [Description("ShortSideTradeLimit")]
        public Int32 BothSideTradeLimit { get { return _bothSideTradeLimit; } set { _bothSideTradeLimit = value; } }

        Int32 _tradeLife = 5;
        [Description("TradeLife")]
        public Int32 TradeLife { get { return _tradeLife; } set { _tradeLife = value; } }
        Boolean _isFixedLife = false;
        [Description("IsFixedLife")]
        public Boolean IsFixedLife { get { return _isFixedLife; } set { _isFixedLife = value; } }
        Boolean _isTrailingStop = false;
        [Description("IsTrailingStop")]
        public Boolean IsTrailingStop { get { return _isTrailingStop; } set { _isTrailingStop = value; } }
        Decimal _trailingStopOnTrigger = -10000000m;
        [Description("TrailingStopOnTrigger")]
        public Decimal TrailingStopOnTrigger { get { return _trailingStopOnTrigger; } set { _trailingStopOnTrigger = value; } }

        Decimal _trailingStopOnTriggerShort = -10000000m;
        [Description("TrailingStopOnTriggerShort")]
        public Decimal TrailingStopOnTriggerShort { get { return _trailingStopOnTriggerShort; } set { _trailingStopOnTriggerShort = value; } }

        Decimal _minimumProfitTrigger = -10000000m;
        [Description("MinimumProfitTrigger")]
        public Decimal MinimumProfitTrigger { get { return _minimumProfitTrigger; } set { _minimumProfitTrigger = value; } }

        Decimal _minimumProfitTriggerShort = -10000000m;
        [Description("MinimumProfitTriggerShort")]
        public Decimal MinimumProfitTriggerShort { get { return _minimumProfitTriggerShort; } set { _minimumProfitTriggerShort = value; } }

        Decimal _minimumProfitOnTrigger = 10000000m;
        [Description("MinimumProfitOnTrigger")]
        public Decimal MinimumProfitOnTrigger { get { return _minimumProfitOnTrigger; } set { _minimumProfitOnTrigger = value; } }

        Decimal _minimumProfitOnTriggerShort = 10000000m;
        [Description("MinimumProfitOnTriggerShort")]
        public Decimal MinimumProfitOnTriggerShort { get { return _minimumProfitOnTriggerShort; } set { _minimumProfitOnTriggerShort = value; } }

        Boolean _isMinimumProfitOn = false;
        [Description("IsMinimumProfitOn")]
        public Boolean IsMinimumProfitOn { get { return _isMinimumProfitOn; } set { _isMinimumProfitOn = value; } }

        Boolean _isMinimumProfitOnWithTrigger = false;
        [Description("IsMinimumProfitOnWithTrigger")]
        public Boolean IsMinimumProfitOnWithTrigger { get { return _isMinimumProfitOnWithTrigger; } set { _isMinimumProfitOnWithTrigger = value; } }

        Boolean _isLongOnly = false;
        [Description("IsLongOnly")]
        public Boolean IsLongOnly { get { return _isLongOnly; } set { _isLongOnly = value; } }

        Boolean _isShortOnly = false;
        [Description("IsShortOnly")]
        public Boolean IsShortOnly { get { return _isShortOnly; } set { _isShortOnly = value; } }

        Boolean _isAdjSignal = false;
        [Description("IsAdjSignal")]
        public Boolean IsAdjSignal { get { return _isAdjSignal; } set { _isAdjSignal = value; } }
        Boolean _isOpenSignalOnly = false;
        [Description("IsOpenSignalOnly")]
        public Boolean IsOpenSignalOnly { get { return _isOpenSignalOnly; } set { _isOpenSignalOnly = value; } }
        Boolean _useSVMSum = false;
        [Description("UseSVMSum")]
        public Boolean UseSVMSum { get { return _useSVMSum; } set { _useSVMSum = value; } }
        Boolean _isSVMPassThrough = false;
        [Description("IsSVMPassThrough")]
        public Boolean IsSVMPassThrough { get { return _isSVMPassThrough; } set { _isSVMPassThrough = value; } }
        Decimal _SVMPassThroughTrigger = 1.0m;
        [Description("SVMPassThroughTrigger")]
        public Decimal SVMPassThroughTrigger { get { return _SVMPassThroughTrigger; } set { _SVMPassThroughTrigger = value; } }
        Decimal _SVMProbabilityTrigger = 0.0m;
        [Description("SVMProbabilityTrigger")]
        public Decimal SVMProbabilityTrigger { get { return _SVMProbabilityTrigger; } set { _SVMProbabilityTrigger = value; } }
        Int32 _svmForcastPeriod = 5;
        [Description("SvmForcastPeriod")]
        public Int32 SvmForcastPeriod { get { return _svmForcastPeriod; } set { _svmForcastPeriod = value; } }
        Decimal _svmForcastPeriodUp = 0.000m;
        [Description("SvmForcastPeriodUp")]
        public Decimal SvmForcastPeriodUp { get { return _svmForcastPeriodUp; } set { _svmForcastPeriodUp = value; } }
        Decimal _svmForcastPeriodDown = 0.000m;
        [Description("SvmForcastPeriodDown")]
        public Decimal SvmForcastPeriodDown { get { return _svmForcastPeriodDown; } set { _svmForcastPeriodDown = value; } }
        Decimal _feeRate = 0.001m;
        [Description("FeeRate")]
        public Decimal FeeRate { get { return _feeRate; } set { _feeRate = value; } }
        Decimal _slippage = 0.002m;
        [Description("Slippage")]
        public Decimal Slippage { get { return _slippage; } set { _slippage = value; } }
        testCase _myTestCase = testCase.super8;
        [Description("MyTestCase")]
        public testCase MyTestCase { get { return _myTestCase; } set { _myTestCase = value; } }
        Boolean _useSuerp8Vector = false;
        [Description("UseSuerp8Vector")]
        public Boolean UseSuerp8Vector { get { return _useSuerp8Vector; } set { _useSuerp8Vector = value; } }
        Int32 _super8LengthPerItem = 5;
        [Description("Super8LengthPerItem")]
        public Int32 Super8LengthPerItem { get { return _super8LengthPerItem; } set { _super8LengthPerItem = value; } }
        Int32 _super8LookBackPeriod = 15;
        [Description("Super8LookBackPeriod")]
        public Int32 Super8LookBackPeriod { get { return _super8LookBackPeriod; } set { _super8LookBackPeriod = value; } }
        Int32 _highLowLookBackPeriod = 20;
        [Description("HighLowLookBackPeriod")]
        public Int32 HighLowLookBackPeriod { get { return _highLowLookBackPeriod; } set { _highLowLookBackPeriod = value; } }
        Int32 _highLowLookBackPeriodLow = 20;
        [Description("HighLowLookBackPeriodLow")]
        public Int32 HighLowLookBackPeriodLow { get { return _highLowLookBackPeriodLow; } set { _highLowLookBackPeriodLow = value; } }
        Boolean _isRelaxedHighLow = false;
        [Description("IsRelaxedHighLow")]
        public Boolean IsRelaxedHighLow { get { return _isRelaxedHighLow; } set { _isRelaxedHighLow = value; } }
        Int32 _macdLookBackPeriodLong = 26;
        [Description("MacdLookBackPeriodLong")]
        public Int32 MacdLookBackPeriodLong { get { return _macdLookBackPeriodLong; } set { _macdLookBackPeriodLong = value; } }
        Int32 _macdLookBackPeriodShort = 12;
        [Description("MacdLookBackPeriodShort")]
        public Int32 MacdLookBackPeriodShort { get { return _macdLookBackPeriodShort; } set { _macdLookBackPeriodShort = value; } }
        Int32 _macdLookBackPeriodAve = 9;
        [Description("MacdLookBackPeriodAve")]
        public Int32 MacdLookBackPeriodAve { get { return _macdLookBackPeriodAve; } set { _macdLookBackPeriodAve = value; } }
        Int32 _cciLookBackPeriod = 20;
        [Description("CciLookBackPeriod")]
        public Int32 CciLookBackPeriod { get { return _cciLookBackPeriod; } set { _cciLookBackPeriod = value; } }
        Decimal _cciLimitFactor = 100;
        [Description("CciLimitFactor")]
        public Decimal CciLimitFactor { get { return _cciLimitFactor; } set { _cciLimitFactor = value; } }
        Int32 _biasLookBackPeriod = 6;
        [Description("BiasLookBackPeriod")]
        public Int32 BiasLookBackPeriod { get { return _biasLookBackPeriod; } set { _biasLookBackPeriod = value; } }
        Decimal _biasLimitFactor = (Decimal)(2 / Math.Sqrt(4.0 * 60 + 30));
        [Description("BiasLimitFactor")]
        public Decimal BiasLimitFactor { get { return _biasLimitFactor; } set { _biasLimitFactor = value; } }
        Boolean _isHighLowLongShortTie = true;
        [Description("IsHighLowLongShortTie")]
        public Boolean IsHighLowLongShortTie { get { return _isHighLowLongShortTie; } set { _isHighLowLongShortTie = value; } }
        Int32 _bollingerBandLookBackPeriod = 20;
        [Description("BollingerBandLookBackPeriod")]
        public Int32 BollingerBandLookBackPeriod { get { return _bollingerBandLookBackPeriod; } set { _bollingerBandLookBackPeriod = value; } }
        Decimal _bollingerBandWidth = 2m;
        [Description("BollingerBandWidth")]
        public Decimal BollingerBandWidth { get { return _bollingerBandWidth; } set { _bollingerBandWidth = value; } }
        Decimal _bollingerBandWidthAbsTrigger = 5/2500m;
        [Description("BollingerBandWidthAbsTrigger")]
        public Decimal BollingerBandWidthAbsTrigger { get { return _bollingerBandWidthAbsTrigger; } set { _bollingerBandWidthAbsTrigger = value; } }
        DateTime _startDate = DateTime.Now.AddYears(-50);
        [Description("StartDate")]
        public DateTime StartDate { get { return _startDate; } set { _startDate = value; _startDateTL = Util.ToTLDate(value); } }
        Int32 _startDateTL = Util.ToTLDate(DateTime.Now.AddYears(-50));
        DateTime _endDate = DateTime.Now;
        [Description("EndDate")]
        public DateTime EndDate { get { return _endDate; } set { _endDate = value; _endDateTL = Util.ToTLDate(value); } }
        Int32 _endDateTL = Util.ToTLDate(DateTime.Now);
        Boolean _isAutoRunIndicators = false;
        [Description("IsAutoRunIndicators")]
        public Boolean IsAutoRunIndicators { get { return _isAutoRunIndicators; } set { _isAutoRunIndicators = value; } }
        Boolean _isOptRun = false;
        [Description("IsOptRun")]
        public Boolean IsOptRun { get { return _isOptRun; } set { _isOptRun = value; } }

        Boolean _isResetOnNewDay = false;
        [Description("IsResetOnNewDay")]
        public Boolean IsResetOnNewDay { get { return _isResetOnNewDay; } set { _isResetOnNewDay = value; } }

        Boolean _isBarReset = true;
        [Description("IsBarReset")]
        public Boolean IsBarReset { get { return _isBarReset; } set { _isBarReset = value; } }

        Boolean _isSkipRolloverDay = false;
        [Description("IsSkipRolloverDay")]
        public Boolean IsSkipRolloverDay { get { return _isSkipRolloverDay; } set { _isSkipRolloverDay = value; } }

        Boolean _isFastCalc = false;
        [Description("IsFastCalc")]
        public Boolean IsFastCalc { get { return _isFastCalc; } set { _isFastCalc = value; } }

        Boolean _withTickFeed = true;
        [Description("WithTickFeed")]
        public Boolean WithTickFeed { get { return _withTickFeed; } set { _withTickFeed = value; } }

        Boolean _isWrongSVMCompositeInitialization = false;
        [Description("IsWrongSVMCompositeInitialization")]
        public Boolean IsWrongSVMCompositeInitialization { get { return _isWrongSVMCompositeInitialization; } set { _isWrongSVMCompositeInitialization = value; } }

        public BasketImpl quotaBasket = new BasketImpl();
        string _quotaBasketValue = "";
        [Description("QuotaBasketValue")]
        public string QuotaBasketValue
        { get { return _quotaBasketValue; } set { _quotaBasketValue = value; } }

        Boolean _useMarketBreakSmoother = true;
        [Description("UseMarketBreakSmoother")]
        public Boolean UseMarketBreakSmoother { get { return _useMarketBreakSmoother; } set { _useMarketBreakSmoother = value; } }

        Boolean _isRamdomLongShort = false;
        [Description("IsRamdomLongShort")]
        public Boolean IsRamdomLongShort { get { return _isRamdomLongShort; } set { _isRamdomLongShort = value; } }

        public enum testCase
        {
            super8,
            turningpoint,
            custom
        }
        
        CompositeSVM _myComSVM;       

        Int32 aSVM;
        Int32 bSVM;
        Int32 cSVM;
        Decimal RecallSVM;
        Decimal precisionSVM;
        Decimal FMeasureSVM;
        Int32[] a;
        Int32[] b;
        Int32[] c;
        Decimal[] Recall;
        Decimal[] precision;
        Decimal[] FMeasure;

        List<DataTable> _confusionMatrixVec = new List<DataTable>();
        DataTable _performanceMeasure = new DataTable();
        Dictionary<Int32,Int32> _predCaseValueToColIndex = new Dictionary<Int32, Int32>();        

        List<GenericIndicatorTemplate> _gindList = null;
        List<String> _gindNameList = null;
        List<Int32> _gindPeriodList = null;
        List<Int32> _periodsValueOnLast = null;
        List<Int32> _periodsValueOnCurrent = null;

        DataTable _indicatorOutput = new DataTable();
        String[] _indicatorValueHolder = null;
        
        Boolean _calcMeasure = false;
        Int32 _tradeLifeLocal = 0;
        Decimal _trailingStopTrigger;
        Boolean isTwoClassUpAndDown;
        Decimal _totalFee;
        string[] IndicatorHead;

        Int32 _indDisplayLength = 0;

        Decimal _stopNewTradeTriggerLocal = 0;
        public Int32 _time = 0;
        public Int32 _date = 0;
        public String _symbolLast = String.Empty;
        Tick _lastTick = new TickImpl();
        
        Decimal _PNLForAll = 0;
        Int32 _numberOfFill = 0;
        Int32 _numberOfLongFill = 0;
        Decimal _lastLongPNL = 0;
        Int32 _numberOfShortFill = 0;
        Decimal _lastShortPNL = 0;
        Int32 _currentTradeType = 0;
        Decimal _PNLForAllAtTradeOpen = 0;
        Boolean _isRollOverDate = false;
        Boolean _isTradingStop = false;

        Random _random = new Random(1);


        bool _black = false;
        // this function is called the constructor, because it sets up the response
        // it is run before all the other functions, and has same name as my response.
        public SVMCompositeMulti() : this(true) { }
        
        public SVMCompositeMulti(bool prompt)
        {
            _black = !prompt;
            // handle when new symbols are added to the active tracker
            _active.NewTxt += new TextIdxDelegate(_active_NewTxt);

            // set our indicator names, in case we import indicators into R
            // or excel, or we want to view them in gauntlet or kadina
            Indicators = new string[] { "Symbol"};
        }
        
        public override void Reset()
        {
            // enable prompting of system parameters to user,
            // so they do not have to recompile to change things
            ParamPrompt.Popup(this, true, _black);
            ResetDetail(true);
            _symbolLast = String.Empty;
            return;            
        }

        private void ResetDetail(Boolean resetBarHis)
        {
            resetSoft();
            if (!resetBarHis)
            {
                return;
            }
            if (_myTestCase == testCase.super8)
            {
                // using 000300-SH20110503.TIK
                _gindPeriod = "supereight:1";
                _stopNewTradeTrigger = -100000m;
            }
            if (_myTestCase == testCase.turningpoint)
            {
                // using 999999-SH19990127.TIK
                //_gindPeriod = "macd:1;kdj:1;rsi:1";
            }
          

            _stopNewTradeTriggerLocal = _stopNewTradeTrigger;

            _gindNameList = new List<String>();
            _gindPeriodList = new List<Int32>();
            List<Int32> uniquePeriodList = new List<Int32>();
            String[] gindPeriodVec = GindPeriod.Split(';');
            foreach (String ss in gindPeriodVec)
            {
                String[] gindVecLocal = ss.Split(':');
                String[] gindPeriodVecLocal = gindVecLocal[1].Split(',');
                foreach (String ss1 in gindPeriodVecLocal)
                {
                    _gindNameList.Add(gindVecLocal[0]);
                    Int32 pLocal = Convert.ToInt32(ss1) * _numTickPerBar;
                    _gindPeriodList.Add(pLocal);
                    if (uniquePeriodList.IndexOf(pLocal) == -1)
                    {
                        uniquePeriodList.Add(pLocal);
                    }
                }
            }
            BarInterval[] intervaltypes = new BarInterval[uniquePeriodList.Count];
            Int32[] intervalValues = new Int32[uniquePeriodList.Count];
            for (Int32 i = 0; i < uniquePeriodList.Count; i++)
            {
                intervaltypes[i] = BarType;
                intervalValues[i] = uniquePeriodList[i];
            }

            a = new Int32[_gindPeriodList.Count];
            b = new Int32[_gindPeriodList.Count];
            c = new Int32[_gindPeriodList.Count];
            Recall = new Decimal[_gindPeriodList.Count];
            precision = new Decimal[_gindPeriodList.Count];
            FMeasure = new Decimal[_gindPeriodList.Count];
            _confusionMatrixVec = new List<DataTable>();
            _performanceMeasure = new DataTable();
            _predCaseValueToColIndex = new Dictionary<Int32, Int32>();
            _indicatorOutput = new DataTable();

            _periodsValueOnLast = new List<Int32>();
            for (Int32 i = 0; i < _gindPeriodList.Count; i++)
            {
                _periodsValueOnLast.Add(1);

                a[i] = 0;
                b[i] = 0;
                c[i] = 0;
                Recall[i] = 0;
                precision[i] = 0;
                FMeasure[i] = 0;
            }
            _calcMeasure = false;
            if (resetBarHis)
            {
                // only build bars for user's interval
                blt = new BarListTracker(intervalValues, intervaltypes);
                // only calculate on new bars
                blt.GotNewBar += new SymBarIntervalDelegate(blt_GotNewBar);
            }

            isTwoClassUpAndDown = SvmForcastPeriod > 0 && (SvmForcastPeriodUp == SvmForcastPeriodDown);
            for (Int32 i = 0; i < _gindPeriodList.Count + 1; i++)
            {
                DataTable tmpTable = new DataTable();
                List<Decimal> tmpList = new List<Decimal>();
                if (Useabsturningvalue || isTwoClassUpAndDown)
                {
                    if (isTwoClassUpAndDown)
                    {
                        tmpTable.Columns.Add("predCase1");
                        tmpTable.Columns.Add("predCase-1");
                        _predCaseValueToColIndex[1] = 0;
                        _predCaseValueToColIndex[-1] = 1;
                    }
                    else
                    {
                        tmpTable.Columns.Add("predCase1");
                        tmpTable.Columns.Add("predCase0");
                        _predCaseValueToColIndex[1] = 0;
                        _predCaseValueToColIndex[0] = 1;
                    }

                    MiscUtility.addRowToTable(tmpTable, out tmpTable, 1);
                    MiscUtility.addRowToTable(tmpTable, out tmpTable, 1);
                    _numberClass = 2;
                    for (Int32 ii = 0; ii < _numberClass; ii++)
                    {
                        for (Int32 jj = 0; jj < _numberClass; jj++)
                        {
                            tmpTable.Rows[ii][jj] = "0";
                        }
                    }
                }
                else
                {
                    tmpTable.Columns.Add("predCase1");
                    tmpTable.Columns.Add("predCase-1");
                    tmpTable.Columns.Add("predCase0");
                    _predCaseValueToColIndex[1] = 0;
                    _predCaseValueToColIndex[-1] = 1;
                    _predCaseValueToColIndex[0] = 2;
                    MiscUtility.addRowToTable(tmpTable, out tmpTable, 1);
                    MiscUtility.addRowToTable(tmpTable, out tmpTable, 1);
                    MiscUtility.addRowToTable(tmpTable, out tmpTable, 1);
                    _numberClass = 3;
                    for (Int32 ii = 0; ii < _numberClass; ii++)
                    {
                        for (Int32 jj = 0; jj < _numberClass; jj++)
                        {
                            tmpTable.Rows[ii][jj] = "0";
                        }
                    }
                }
                _confusionMatrixVec.Add(tmpTable);
            }
            for (Int32 ii = 0; ii < _numberClass; ii++)
            {
                _performanceMeasure.Columns.Add("Recall" + ii.ToString());
                _performanceMeasure.Columns.Add("Precision" + ii.ToString());
                _performanceMeasure.Columns.Add("FMeasure" + ii.ToString());
            }
            for (Int32 i = 0; i < _gindPeriodList.Count + 1; i++)
            {
                MiscUtility.addRowToTable(_performanceMeasure, out _performanceMeasure, 1);
            }
            String[] tmpVec0 = new string[] { "Symbol", "Date", "Time", "O", "H", "L", "C", "Vol", "CBardate", "CBCount", "SVMDataCount", "SVM-C", "SVM-gamma", "PNL", "Cost", "ComSVM", "ComSVMTurnRealized", "ComSVMSignalSum", "aSVM", "bSVM", "cSVM", "RecallSVM", "PrecisionSVM", "FMeasureSVM" };
            String[] tmpVec1 = new string[_numberClass * 6];
            for (Int32 j = 0; j < _numberClass; j++)
            {
                tmpVec1[j * 6 + 0] = "aSVM" + j.ToString();
                tmpVec1[j * 6 + 1] = "bSVM" + j.ToString();
                tmpVec1[j * 6 + 2] = "cSVM" + j.ToString();
                tmpVec1[j * 6 + 3] = "RecallSVM" + j.ToString();
                tmpVec1[j * 6 + 4] = "PrecisionSVM" + j.ToString();
                tmpVec1[j * 6 + 5] = "FMeasureSVM" + j.ToString();
            }
            IndicatorHead = new string[tmpVec0.Length + tmpVec1.Length];
            for (Int32 j = 0; j < tmpVec0.Length; j++)
            {
                IndicatorHead[j] = tmpVec0[j];
            }
            for (Int32 j = 0; j < tmpVec1.Length; j++)
            {
                IndicatorHead[j + tmpVec0.Length] = tmpVec1[j];
            }

            Int32 IndicatorsTotalLen = 0;
            _indDisplayLength = 11 + (_numberClass - 1) * 6;
            for (Int32 i = 0; i < _gindPeriodList.Count; i++)
            {
                if (_gindNameList[i] == "macd")
                {
                    IndicatorsTotalLen += _indDisplayLength;
                }
                if (_gindNameList[i] == "rsi")
                {
                    IndicatorsTotalLen += _indDisplayLength;
                }
                if (_gindNameList[i] == "kdj")
                {
                    IndicatorsTotalLen += _indDisplayLength;
                }
                if (_gindNameList[i] == "cci")
                {
                    IndicatorsTotalLen += _indDisplayLength;
                }
                if (_gindNameList[i] == "bias")
                {
                    IndicatorsTotalLen += _indDisplayLength;
                }
                if (_gindNameList[i] == "bollingerband")
                {
                    IndicatorsTotalLen += _indDisplayLength;
                }
                if (_gindNameList[i] == "highlow")
                {
                    IndicatorsTotalLen += _indDisplayLength;
                }
                if (_gindNameList[i] == "supereight")
                {
                    IndicatorsTotalLen += _indDisplayLength;
                }
            }
            Indicators = new string[IndicatorHead.Length + IndicatorsTotalLen];
            _indicatorValueHolder = new string[Indicators.Length];
            for (Int32 i = 0; i < _indicatorValueHolder.Length; i++)
            {
                _indicatorValueHolder[i] = String.Empty;
            }
            for (Int32 i = 0; i < IndicatorHead.Length; i++)
            {
                Indicators[i] = IndicatorHead[i];
            }
            String indName = String.Empty;
            Int32 IndicatorsLast = IndicatorHead.Length;
            for (Int32 i = 0; i < _gindPeriodList.Count; i++)
            {
                indName = _gindNameList[i].ToUpper() + "-";
                Indicators[IndicatorsLast + 0] = indName + i.ToString();
                Indicators[IndicatorsLast + 1] = indName + "BuySell" + i.ToString();
                Indicators[IndicatorsLast + 2] = indName + "LMin" + i.ToString();
                Indicators[IndicatorsLast + 3] = indName + "LMax" + i.ToString();
                Indicators[IndicatorsLast + 4] = indName + "Turn" + i.ToString();
                for (Int32 j = 0; j < _numberClass; j++)
                {
                    Indicators[IndicatorsLast + 5 + (j) * 6] = indName + i.ToString() + "-class-" + j.ToString() + "a" + j.ToString();
                    Indicators[IndicatorsLast + 6 + (j) * 6] = indName + i.ToString() + "-class-" + j.ToString() + "b" + j.ToString();
                    Indicators[IndicatorsLast + 7 + (j) * 6] = indName + i.ToString() + "-class-" + j.ToString() + "c" + j.ToString();
                    Indicators[IndicatorsLast + 8 + (j) * 6] = indName + i.ToString() + "-class-" + j.ToString() + "Recall" + j.ToString();
                    Indicators[IndicatorsLast + 9 + (j) * 6] = indName + i.ToString() + "-class-" + j.ToString() + "Precision" + j.ToString();
                    Indicators[IndicatorsLast + 10 + (j) * 6] = indName + i.ToString() + "-class-" + j.ToString() + "FMeasure" + j.ToString();
                }
                IndicatorsLast += _indDisplayLength;
            }
            if (IsAutoRunIndicators)
            {
                Indicators = new string[] { "Time", "Port NAV", "PNL", "ImpliedV", "PS", "HoldingInfo", "OptTarget" };
            }
            // wait for fill
            _wait.Clear();
            // track whether shutdown 
            _active.Clear();
            _kt.Clear();

            Hashtable ComSVMInputParam = new Hashtable();
            // SVM param
            ComSVMInputParam["svmtype"] = SVMType;
            ComSVMInputParam["probability"] = SVMProbability;
            ComSVMInputParam["c"] = SvmCValue;
            ComSVMInputParam["cstart"] = -5;
            ComSVMInputParam["cend"] = 15;
            ComSVMInputParam["cstep"] = 2;
            ComSVMInputParam["gamma"] = SvmGammaValue;
            ComSVMInputParam["gammastart"] = 3;
            ComSVMInputParam["gammaend"] = -15;
            ComSVMInputParam["gammastep"] = -2;
            ComSVMInputParam["casesfortraining"] = Casesfortraining;
            ComSVMInputParam["casesfortrainingfirst"] = CasesfortrainingFirst;
            ComSVMInputParam["featureseachcase"] = Featureseachcase;
            ComSVMInputParam["retrainfreq"] = Retrainfreq;
            ComSVMInputParam["svmtrainfreq"] = Svmtrainfreq;
            ComSVMInputParam["svmgridsearchfreq"] = Svmgridsearchfreq;
            ComSVMInputParam["issvmpassthrough"] = IsSVMPassThrough.ToString();
            ComSVMInputParam["svmpassthroughtrigger"] = SVMPassThroughTrigger;
            ComSVMInputParam["svmprobabilitytrigger"] = SVMProbabilityTrigger;
            // Wavelet param
            ComSVMInputParam["wtrunctionmethod"] = "heursure";
            ComSVMInputParam["wmotherfunction"] = "db4";
            ComSVMInputParam["wextensionmode"] = "ZeroPadding";
            ComSVMInputParam["wlookbckperiod"] = 16;
            ComSVMInputParam["wtransoformlevelshift"] = Wtransoformlevelshift;// if the value is big, then CompositeSVM will not use Wavelet;
            // other param
            ComSVMInputParam["minmumsignallength"] = CasesfortrainingFirst;
            ComSVMInputParam["calcturningpoint"] = "true";
            ComSVMInputParam["isextendedturnpoint"] = IsExtendedTurnPoint.ToString().ToLower();
            ComSVMInputParam["turningpointvaluetol"] = RealzedTurnPointTol;
            ComSVMInputParam["useabsturningvalue"] = Useabsturningvalue.ToString().ToLower();
            ComSVMInputParam["issingletrain"] = isSingleTrain.ToString().ToLower();
            ComSVMInputParam["isfullfeatures"] = IsFullFeatures.ToString();
            if (SvmForcastPeriod > 0)
            {
                ComSVMInputParam["forcastperiod"] = SvmForcastPeriod;
                ComSVMInputParam["forcasetriggerup"] = SvmForcastPeriodUp;
                ComSVMInputParam["forcasetriggerdown"] = SvmForcastPeriodDown;
            }

            _myComSVM = new CompositeSVM();
            _myComSVM.Param = ComSVMInputParam;
            _myComSVM.Initializatin();
            if (_isWrongSVMCompositeInitialization)
            {
                _myComSVM._featureValueSum = Decimal.MinValue;
            }

            _gindList = new List<GenericIndicatorTemplate>();
            for (Int32 i = 0; i < _gindPeriodList.Count; i++)
            {
                if (_gindNameList[i] == "macd")
                {
                    Hashtable macdInputParamTmp = new Hashtable();
                    macdInputParamTmp["lookbackperiodlong"] = MacdLookBackPeriodLong;
                    macdInputParamTmp["lookbackperiodlongalpha"] = -10000;
                    macdInputParamTmp["lookbackperiodshort"] = MacdLookBackPeriodShort;
                    macdInputParamTmp["lookbackperiodshortalpha"] = -10000;
                    macdInputParamTmp["lookbackperiodave"] = MacdLookBackPeriodAve;
                    macdInputParamTmp["lookbackperiodavealpha"] = -10000;
                    macdInputParamTmp["calcturningpoint"] = Calcturningpoint;
                    macdInputParamTmp["turningpointvaluetol"] = TurningPointValueTol;
                    macdInputParamTmp["period"] = _gindPeriodList[i];
                    //if (MatchTALib)
                    {
                        macdInputParamTmp["minmumsignallength"] = MacdLookBackPeriodAve + MacdLookBackPeriodLong - 2;
                        macdInputParamTmp["setemaminmumsignallength"] = "true";
                    }
                    MACD myMacdLocal = new MACD();
                    myMacdLocal.Param = macdInputParamTmp;
                    myMacdLocal.Initializatin();
                    _gindList.Add(myMacdLocal);
                    _myComSVM.UpdateIndicator(_gindList[i], _numTickPerBar);
                }
                if (_gindNameList[i] == "kdj")
                {
                    Hashtable KDJInputParamTmp = new Hashtable();
                    KDJInputParamTmp["lookbackperiod"] = 9;
                    KDJInputParamTmp["lowerbanddownlimit"] = -10000;
                    KDJInputParamTmp["lowerbanduplimit"] = 25;
                    KDJInputParamTmp["upperbanddownlimit"] = 75;
                    KDJInputParamTmp["upperbanduplimit"] = 10000;
                    KDJInputParamTmp["calcturningpoint"] = "true";
                    KDJInputParamTmp["turningpointvaluetol"] = TurningPointValueTol;
                    KDJInputParamTmp["period"] = _gindPeriodList[i];
                    KDJInputParamTmp["minmumsignallength"] = 9;
                    KDJ myKdjLocal = new KDJ();
                    myKdjLocal.Param = KDJInputParamTmp;
                    myKdjLocal.Initializatin();

                    _gindList.Add(myKdjLocal);
                    _myComSVM.UpdateIndicator(_gindList[i], _numTickPerBar);
                }
                if (_gindNameList[i] == "rsi")
                {
                    Hashtable RSIInputParamTmp = new Hashtable();
                    RSIInputParamTmp["lookbackperiod"] = 12;
                    RSIInputParamTmp["lowerbanddownlimit"] = 0;
                    RSIInputParamTmp["lowerbanduplimit"] = 20;
                    RSIInputParamTmp["upperbanddownlimit"] = 80;
                    RSIInputParamTmp["upperbanduplimit"] = 100;
                    RSIInputParamTmp["calcturningpoint"] = "true";
                    RSIInputParamTmp["turningpointvaluetol"] = TurningPointValueTol;
                    RSIInputParamTmp["period"] = _gindPeriodList[i];
                    RSIInputParamTmp["minmumsignallength"] = 12;
                    RSI myRsiLocal = new RSI();
                    myRsiLocal.Param = RSIInputParamTmp;
                    myRsiLocal.Initializatin();

                    _gindList.Add(myRsiLocal);
                    _myComSVM.UpdateIndicator(_gindList[i], _numTickPerBar);
                }
                if (_gindNameList[i] == "cci")
                {
                    Hashtable CCIInputParamTmp = new Hashtable();
                    CCIInputParamTmp["lookbackperiodave"] = CciLookBackPeriod;
                    CCIInputParamTmp["lookbackperiodsd"] = CciLookBackPeriod;
                    CCIInputParamTmp["constant"] = 0.015;
                    CCIInputParamTmp["lowerbanddownlimit"] = Decimal.MinValue;
                    CCIInputParamTmp["lowerbanduplimit"] = -CciLimitFactor;
                    CCIInputParamTmp["upperbanddownlimit"] = CciLimitFactor;
                    CCIInputParamTmp["upperbanduplimit"] = Decimal.MaxValue;
                    CCIInputParamTmp["calcturningpoint"] = Calcturningpoint;
                    CCIInputParamTmp["turningpointvaluetol"] = TurningPointValueTol;
                    CCIInputParamTmp["period"] = _gindPeriodList[i];
                    CCIInputParamTmp["minmumsignallength"] = CciLookBackPeriod;
                    CCI myCciLocal = new CCI();
                    myCciLocal.Param = CCIInputParamTmp;
                    myCciLocal.Initializatin();

                    _gindList.Add(myCciLocal);
                    _myComSVM.UpdateIndicator(_gindList[i], _numTickPerBar);
                }
                if (_gindNameList[i] == "bias")
                {
                    Hashtable BIASInputParamTmp = new Hashtable();
                    BIASInputParamTmp["lookbackperiod"] = BiasLookBackPeriod;
                    BIASInputParamTmp["lowerbanddownlimit"] = Decimal.MinValue;
                    BIASInputParamTmp["lowerbanduplimit"] = -BiasLimitFactor;
                    BIASInputParamTmp["upperbanddownlimit"] = BiasLimitFactor;
                    BIASInputParamTmp["upperbanduplimit"] = Decimal.MaxValue;
                    BIASInputParamTmp["calcturningpoint"] = Calcturningpoint; ;
                    BIASInputParamTmp["turningpointvaluetol"] = TurningPointValueTol;
                    BIASInputParamTmp["period"] = _gindPeriodList[i];
                    BIASInputParamTmp["minmumsignallength"] = BiasLookBackPeriod;
                    BIAS myBiasLocal = new BIAS();
                    myBiasLocal.Param = BIASInputParamTmp;
                    myBiasLocal.Initializatin();

                    _gindList.Add(myBiasLocal);
                    _myComSVM.UpdateIndicator(_gindList[i], _numTickPerBar);
                }
                if (_gindNameList[i] == "bollingerband")
                {
                    Hashtable BollingerBandInputParamTmp = new Hashtable();
                    BollingerBandInputParamTmp["lookbackperiod"] = BollingerBandLookBackPeriod;
                    BollingerBandInputParamTmp["bandwidth"] = BollingerBandWidth;
                    BollingerBandInputParamTmp["period"] = _gindPeriodList[i];
                    BollingerBandInputParamTmp["minmumsignallength"] = BollingerBandLookBackPeriod;
                    BollingerBandInputParamTmp["bollingerbandwidthabstrigger"] = BollingerBandWidthAbsTrigger;
                    BollingerBand myBollingerBandLocal = new BollingerBand();
                    myBollingerBandLocal.Param = BollingerBandInputParamTmp;
                    myBollingerBandLocal.Initializatin();

                    _gindList.Add(myBollingerBandLocal);
                    _myComSVM.UpdateIndicator(_gindList[i], _numTickPerBar);
                }
                if (_gindNameList[i] == "highlow")
                {
                    Hashtable HighLowInputParamTmp = new Hashtable();
                    HighLowInputParamTmp["lookbackperiod"] = HighLowLookBackPeriod;
                    HighLowInputParamTmp["lookbackperiodlow"] = HighLowLookBackPeriodLow;
                    HighLowInputParamTmp["period"] = _gindPeriodList[i];
                    HighLowInputParamTmp["isrelaxedhighlow"] = IsRelaxedHighLow;
                    if (IsHighLowLongShortTie)
                    {
                        HighLowInputParamTmp["minmumsignallength"] =
                            HighLowLookBackPeriod > HighLowLookBackPeriodLow ? HighLowLookBackPeriod : HighLowLookBackPeriodLow;
                    }
                    else
                    {
                        HighLowInputParamTmp["minmumsignallength"] =
                            HighLowLookBackPeriod > HighLowLookBackPeriodLow ? HighLowLookBackPeriodLow : HighLowLookBackPeriod;
                    }
                    HighLow myHighLowLocal = new HighLow();
                    myHighLowLocal.Param = HighLowInputParamTmp;
                    myHighLowLocal.Initializatin();

                    _gindList.Add(myHighLowLocal);
                    _myComSVM.UpdateIndicator(_gindList[i], _numTickPerBar);
                }
                if (_gindNameList[i] == "supereight")
                {
                    Hashtable SuperEightInputParamTmp = new Hashtable();
                    SuperEightInputParamTmp["lookbackperiod"] = Super8LookBackPeriod;
                    SuperEightInputParamTmp["lengthperitem"] = Super8LengthPerItem;
                    SuperEightInputParamTmp["period"] = _gindPeriodList[i];
                    SuperEightInputParamTmp["minmumsignallength"] = Super8LookBackPeriod;
                    if (UseSuerp8Vector)
                    {
                        SuperEightVector mySuperEightLocal = new SuperEightVector();
                        mySuperEightLocal.Param = SuperEightInputParamTmp;
                        mySuperEightLocal.Initializatin();

                        _gindList.Add(mySuperEightLocal);
                        _myComSVM.UpdateIndicator(_gindList[i], _numTickPerBar);
                    }
                    else
                    {
                        SuperEight mySuperEightLocal = new SuperEight();
                        mySuperEightLocal.Param = SuperEightInputParamTmp;
                        mySuperEightLocal.Initializatin();

                        _gindList.Add(mySuperEightLocal);
                        _myComSVM.UpdateIndicator(_gindList[i], _numTickPerBar);
                    }
                }
            }
            foreach (String ss in Indicators)
            {
                _indicatorOutput.Columns.Add(ss);
            }

            quotaBasket = BasketImpl.Deserialize(QuotaBasketValue);
            //if (quotaBasket.Count > 0)
            //sendbasket(quotaBasket);

            //resetSoft();
        }
        
        private void resetSoft()
        {
            aSVM = 0;
            bSVM = 0;
            cSVM = 0;
            RecallSVM = 0m;
            precisionSVM = 0m;
            FMeasureSVM = 0m;
            _totalFee = 0m;
            _numberOfFill = 0;


            _PNLForAll = 0m;
            _PNLForAllAtTradeOpen = 0m;
            _numberOfFill = 0;
            _tradeLifeLocal = 0;
            _totalFee = 0;
            _currentTradeType = 0;
            _numberOfLongFill = 0;
            _lastLongPNL = 0m;
            _numberOfShortFill = 0;
            _lastShortPNL = 0m;
            pt = new PositionTracker();

            _isRollOverDate = false;
            _isTradingStop = false;
        }
        // wait for fill
        GenericTracker<bool> _wait = new GenericTracker<bool>();
        // track whether shutdown 
        GenericTracker<bool> _active = new GenericTracker<bool>();    
        TickTracker _kt = new TickTracker();
        public IdTracker _idtLocal = new IdTracker(0);
        void _active_NewTxt(string txt, int idx)
        {
            // go ahead and notify any other trackers about this symbol
            _wait.addindex(txt, false);
            _kt.addindex(txt);
        }

        void abcToFMeasure(decimal a, decimal b, decimal c, out decimal Recall, out decimal precision, out decimal fmeasure)
        {
            Recall = 0m;
            if (a + c > 0)
                Recall = a / (a + c + 0m);
            precision = 0m;
            if (a + b > 0)
                precision = a / (a + b + 0m);
            fmeasure = 0m;
            if (Recall + precision > 0)
                fmeasure = (2 * precision * Recall) / (Recall + precision);
        }

        void updateConfusionMatrix(Int32 predCaseVale, Int32 realizedValue, Int32 indIndex)
        {
            Int32 colIndex = _predCaseValueToColIndex[predCaseVale];
            Int32 rowIndex = _predCaseValueToColIndex[realizedValue];
            Int32 lastValue = Convert.ToInt32(_confusionMatrixVec[indIndex].Rows[rowIndex][colIndex]);
            lastValue += 1;
            _confusionMatrixVec[indIndex].Rows[rowIndex][colIndex] = lastValue;

            for (Int32 ii = 0; ii < _numberClass; ii++)
            {
                Decimal localRecall = 0;
                Decimal localDenominator = 0;
                for (Int32 i = 0; i < _confusionMatrixVec[indIndex].Columns.Count; i++)
                {
                    lastValue = Convert.ToInt32(_confusionMatrixVec[indIndex].Rows[ii][i]);
                    if (ii == i)
                    {
                        localRecall = lastValue;
                    }
                    localDenominator += lastValue;
                }                
                if (localDenominator > 0)
                {
                    localRecall /= localDenominator;
                }
                _performanceMeasure.Rows[indIndex][("Recall" + ii.ToString())] = localRecall.ToString("F4", System.Globalization.CultureInfo.InvariantCulture);

                Decimal localPrecision = 0;
                localDenominator = 0;
                for (Int32 i = 0; i < _confusionMatrixVec[indIndex].Rows.Count; i++)
                {
                    lastValue = Convert.ToInt32(_confusionMatrixVec[indIndex].Rows[i][ii]);
                    if (ii == i)
                    {
                        localPrecision = lastValue;
                    }
                    localDenominator += lastValue;
                }
                if (localDenominator > 0)
                {
                    localPrecision /= localDenominator;
                }
                _performanceMeasure.Rows[indIndex][("Precision" + ii.ToString())] = localPrecision.ToString("F4", System.Globalization.CultureInfo.InvariantCulture);

                Decimal localFMeasure = 0;
                if (localPrecision + localRecall > 0)
                {
                    localFMeasure = 2 * localPrecision * localRecall / (localPrecision + localRecall);
                }
                _performanceMeasure.Rows[indIndex][("FMeasure" + ii.ToString())] = localFMeasure.ToString("F4", System.Globalization.CultureInfo.InvariantCulture);
            }
            
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
            Decimal tmpLocal1 = signalVecValue[1];
            if (_numberClass == 2 && !isTwoClassUpAndDown)
            {
                tmpLocal1 = Math.Abs(tmpLocal1);
                tmpLocal= Math.Abs(tmpLocal);
            }
            if ((tmpLocal) == 1)
            {
                if (tmpLocal1 == 1)
                {
                    a++;
                }
                else
                {
                    b++;
                }
            }
            if (tmpLocal1 == 1)
            {
                if ((tmpLocal) != 1)
                {
                    c++;
                }
            }
        }

        void blt_GotNewBar(string symbol, int interval)
        {
            if (_isRollOverDate || _isTradingStop)
            {
                return;
            }
            //Tick tOther = _kt[symbol]; 
            Tick tOther = _lastTick;

            Decimal tOtherTrade = tOther.trade;
           
            Decimal valueForGInd = tOther.trade;
            BarList _myBars = blt[symbol, interval];
            Int32 _myBarsCount = _myBars.Count-1;
            Int32 _myTickCount = _myBarsCount * interval;
            //Bar _lastBar = blt[symbol, interval][-1];
            Bar _lastBar = _myBars[-1];
            if (_lastBar.Close <= 0)
            {
                return;
            }
            // check for shutdown time
            Int32 cTime = 0;
            if (WithTickFeed)
            {
                cTime = tOther.time;
            }
            else
            {
                //cTime = _lastBar.Bartime; 
                cTime = _lastBar.time;
            }

            Boolean isRealShutDonw = (cTime >= Shutdown) && (_lastBar.Bardate==tOther.date);
            if (isRealShutDonw)
            {
                // if so shutdown
                shutdown();
                // and quit
                return;
            }
            
            if (UseBarCloseForGInd)
            {
                valueForGInd = _lastBar.Close;
            }
            // calculate the buy/sell signal from  compositeSVM            
            Decimal[] valueVecSVM = new Decimal[5];
            valueVecSVM[0] = valueForGInd;
            valueVecSVM[1] = _lastBar.High;
            valueVecSVM[2] = _lastBar.Low;
            valueVecSVM[3] = tOtherTrade;
            valueVecSVM[4] = _lastBar.Volume;

            _myComSVM.UpdateValue(ref valueVecSVM, interval, _myTickCount);  
            if (!_myComSVM.isLastDataOfSameTick())
            {
                return;
            }
          
            //BarList cBarList = blt[symbol];
            BarList cBarList = _myBars;
            Boolean isLong = false;
            Boolean isShort = false;
            if (cBarList.Count > 1)
            {
                if (!IsFastCalc)
                D("Got new bar at: " + tOther.time + " bar count: " + cBarList.Count + " for: " + tOther.symbol + " @" + tOther.date);
                Decimal[] signalVecValueComSVM = new Decimal[_myComSVM.GetSignalVecLength()];
                Decimal turningPointValueSum = 0m;
                _myComSVM.GetSignalVec(ref signalVecValueComSVM, _myTickCount);
                if(!IsFastCalc)
                updateIndicatorAndMeasure(cBarList, tOther, _myTickCount, symbol, ref signalVecValueComSVM, ref turningPointValueSum);                
                if (UseSVMSum)
                {
                    isLong = (turningPointValueSum > 0);
                    isShort = (turningPointValueSum < 0); 
                }
                else
                {
                    if (isTwoClassUpAndDown || IsSVMPassThrough || _myTestCase == testCase.super8)
                    {
                        isLong = ((signalVecValueComSVM[0]) == 1);
                        isShort = ((signalVecValueComSVM[0]) == -1);
                    }
                    else
                    {
                        isLong = (Math.Abs(signalVecValueComSVM[0]) == 1) && (turningPointValueSum > 0);
                        isShort = (Math.Abs(signalVecValueComSVM[0]) == 1) && (turningPointValueSum < 0);
                    }
                }
                if (IsAdjSignal)
                {
                    if (isLong)
                    {
                        isShort = true;
                        isLong = false;

                    }else
                    if (isShort)
                    {
                        isShort = false;
                        isLong = true;
                    }
                }
                if (IsRamdomLongShort)
                {
                    isLong = _random.NextDouble() < 0.5;
                    isShort = !isLong;
                }
            }
            if (!IsFastCalc)
            for (Int32 ii = 0; ii < _periodsValueOnCurrent.Count; ii++)
            {
                _periodsValueOnLast[ii] = _periodsValueOnCurrent[ii];
            }

            if (!_wait[symbol])
            {
                Boolean readyForNewTrade = true;
                if (IsFixedLife)
                {
                    Int32 iRem;
                    Math.DivRem(_myBarsCount, TradeLife, out iRem);
                    if(iRem!=0)
                        readyForNewTrade = false;
                }
                Boolean allFlat = true;
                //Decimal tPNL = totalClosedPNL(ref allFlat);                
                //Decimal tmpDiff = tPNL - 0 * _totalFee - _stopNewTradeTriggerLocal;
                _PNLForAll = totalClosedPNL(ref allFlat);
                Decimal tmpDiff = _PNLForAll - 0 * _totalFee - _stopNewTradeTriggerLocal;
                
                if (tmpDiff < -0.000001m)
                {
                    if (_numberOfFill > 0)
                    {
                        // only for trade later than the first one.
                        readyForNewTrade = false;
                    }
                }
                if (tOther.time > Shutdown)
                {
                    readyForNewTrade = false;
                }
                // if we're flat and not waiting
                if (pt[symbol].isFlat)
                {
                    Boolean isTradeNumberLimitReadched = (_numberOfLongFill+_numberOfShortFill)>=BothSideTradeLimit;
                    Boolean isNewTradeOpenLossLimitReached = false;
                    if (isLong)
                    {
                        isTradeNumberLimitReadched |= _numberOfLongFill >= LongSideTradeLimit;
                        if (_numberOfLongFill > 0)
                        {
                            isNewTradeOpenLossLimitReached = _lastLongPNL < _stopNewLongTradeTrigger;
                        }
                    }
                    if (isShort)
                    {
                        isTradeNumberLimitReadched |= _numberOfShortFill >= ShortSideTradeLimit;
                        if (_numberOfShortFill > 0)
                        {
                            isNewTradeOpenLossLimitReached = _lastShortPNL < _stopNewShortTradeTrigger;
                        }
                    }
                    isTradeNumberLimitReadched |= isNewTradeOpenLossLimitReached;


                    if (readyForNewTrade && !isTradeNumberLimitReadched)
                    {
                        Boolean side = true;
                        Decimal adj = 1;
                        // if we get long signal, buy      
                        if (!IsShortOnly)
                        if (isLong)
                        {
                            side = true;
                            adj = (side ? -1 : +1) * _quasiMarketOrderAdjSize;
                            if (!IsFastCalc)
                            D("Long Signal, buy");
                            Int64 _orderidLocal = _idtLocal.AssignId;
                            LimitOrder lOrder = new LimitOrder(symbol, true, EntrySize, tOtherTrade - adj, _orderidLocal);
                            if (!IsFastCalc)
                            D("Order buy:" + lOrder.ToString() + "wait:" + _wait[symbol].ToString());
                            O(lOrder);
                            // wait for fill
                            _wait[symbol] = true;
                            _numberOfLongFill++;
                            _currentTradeType = 1;
                            _PNLForAllAtTradeOpen = _PNLForAll;
                            IsMinimumProfitOn = false;
                        }
                        // otherwise if we get short signal, sell
                        if (!IsLongOnly)
                        if (isShort)
                        {
                            side = false;
                            adj = (side ? -1 : +1) * _quasiMarketOrderAdjSize;
                            if (!IsFastCalc)
                            D("Short Signal, sell");
                            Int64 _orderidLocal = _idtLocal.AssignId;
                            LimitOrder lOrder = new LimitOrder(symbol, false, EntrySize, tOtherTrade - adj, _orderidLocal);
                            if (!IsFastCalc)
                            D("Order sell:" + lOrder.ToString() + "wait:" + _wait[symbol].ToString());
                            O(lOrder);
                            // wait for fill
                            _wait[symbol] = true;
                            _numberOfShortFill++;
                            _currentTradeType = -1;
                            _PNLForAllAtTradeOpen = _PNLForAll;
                            IsMinimumProfitOn = false;
                        }
                    }
                }
                else if ( ((pt[symbol].isLong && isShort)||(pt[symbol].isShort && isLong))&& !IsOpenSignalOnly)
                {
                    if (!IsFastCalc)
                    D("counter signal, exit.");
                    Boolean side = !pt[symbol].isLong;
                    Decimal adj = (side ? -1 : +1) * _quasiMarketOrderAdjSize;
                    Int64 _orderidLocal = _idtLocal.AssignId;
                    LimitOrder lOrder = new LimitOrder(symbol, side, EntrySize, tOtherTrade - adj, _orderidLocal);
                    if (!IsFastCalc)
                    D("Order close:" + lOrder.ToString() + "wait:" + _wait[symbol].ToString());
                    O(lOrder);
                    // wait for fill
                    _wait[symbol] = true;
                }
                else
                {
                    if (IsTrailingStop)
                    {
                        Decimal tmpSpotValue = tOther.trade;
                        if (pt[symbol].isLong)
                        {
                            _trailingStopTrigger = Math.Max(_trailingStopTrigger, tmpSpotValue);
                        }
                        else
                        {
                            _trailingStopTrigger = Math.Min(_trailingStopTrigger, tmpSpotValue);
                        }
                    }
                    _tradeLifeLocal++;
                    // stop loss or take profit, or timeout
                    Decimal TakeProfitTriggerLocal = TakeProfitTrigger;
                    Decimal StopLossTriggerLocal = StopLossTrigger;
                    Decimal TrailingStopOnTriggerLocal = TrailingStopOnTrigger;
                    Decimal TrailingStopExitTriggerLocal = TrailingStopExitTrigger;

                    Position pstn = pt[tOther.symbol];
                    Decimal pnlLocal = Calc.OpenPL(tOtherTrade, pt[tOther.symbol]) / (pstn.AvgPrice)/(pstn.UnsignedSize);
                    Boolean takeProfitAct = pnlLocal > TakeProfitTriggerLocal;
                    Boolean stopLossAct = pnlLocal < StopLossTriggerLocal;
                    
                    String caseCommentExtra = String.Empty;

                    if (stopLossAct)
                    {
                        if (!IsFastCalc)
                            D("stopLossAct@" + tOtherTrade);
                    }

                    Boolean closeThisTrade = takeProfitAct || stopLossAct || _tradeLifeLocal >= TradeLife;
                    String caseComment = String.Empty;
                    if (!IsFastCalc)
                    {
                        caseComment =
                        takeProfitAct ? "takeProfit" : (stopLossAct ? "stopLoss" : ((_tradeLifeLocal >= TradeLife) ? "reachLife" : "none"));
                        caseComment += caseCommentExtra;
                    }
                    if (IsTrailingStop)
                    { 
                        {
                            if (pt[symbol].isLong)
                            {
                                closeThisTrade = tOtherTrade < (_trailingStopTrigger * (1 - TrailingStopExitTriggerLocal));
                            }
                            else
                            {
                                closeThisTrade = tOtherTrade > (_trailingStopTrigger * (1 + TrailingStopExitTriggerLocal));
                            }
                        }
                    }
                    if (closeThisTrade)
                    {
                        if (!IsFastCalc)
                        D(caseComment+" signal, exit.");
                        Boolean side = !pt[symbol].isLong;
                        Decimal adj = (side ? -1 : +1) * _quasiMarketOrderAdjSize;
                        Int64 _orderidLocal = _idtLocal.AssignId;
                        LimitOrder lOrder = new LimitOrder(symbol, side, EntrySize, tOtherTrade - adj, _orderidLocal);
                        if (!IsFastCalc)
                        D("Order close:" + lOrder.ToString() + "wait:" + _wait[symbol].ToString());
                        O(lOrder);
                        // wait for fill
                        _wait[symbol] = true;
                    }
                }
            }

            if (!IsFastCalc)
            {
                if (IsAutoRunIndicators)
                {
                    String dateTime = tOther.date.ToString() + " " + tOther.time.ToString();
                    string[] IndicatorsTmp = new string[] { dateTime, "1.0", ((Calc.OpenPL(tOther.trade, pt[tOther.symbol]) + pt[tOther.symbol].ClosedPL) * ContractSize).ToString(), "ImpliedV", "PS", "HoldingInfo", "OptTarget" };
                    //sendindicators(IndicatorsTmp);
                }
                else
                {
                    sendindicators(_indicatorValueHolder);
                }
            }
            //sendchartlabel((Calc.OpenPL(tOther.trade, pt[tOther.symbol]) + pt[tOther.symbol].ClosedPL) * ContractSize, tOther.time);
        }

        void updateIndicatorAndMeasure(BarList cBarList, Tick tOther, Int32 _myTickCount, String symbol, ref Decimal[] signalVecValueComSVM, ref Decimal turningPointValueSum)
        {
            Bar lastGoodBar = cBarList[cBarList.Count - 2];
            //_myComSVM.GetSignalVec(ref signalVecValueComSVM, _myTickCount);
            abcToFMeasure(aSVM, bSVM, cSVM, out RecallSVM, out precisionSVM, out FMeasureSVM);
            for (Int32 j = 0; j < _gindList.Count; j++)
            {
                abcToFMeasure(a[j], b[j], c[j], out Recall[j], out precision[j], out FMeasure[j]);
            }
            string[] IndicatorValueHolderHead0 = (new string[] { symbol
                    ,lastGoodBar.Bardate.ToString()
                    , lastGoodBar.time.ToString() 
                    ,lastGoodBar.Open.ToString("F4", System.Globalization.CultureInfo.InvariantCulture) 
                    ,lastGoodBar.High.ToString("F4", System.Globalization.CultureInfo.InvariantCulture) 
                    ,lastGoodBar.Low.ToString("F4", System.Globalization.CultureInfo.InvariantCulture) 
                    ,lastGoodBar.Close.ToString("F4", System.Globalization.CultureInfo.InvariantCulture) 
                    ,lastGoodBar.Volume.ToString("F4", System.Globalization.CultureInfo.InvariantCulture) 
                    ,cBarList.RecentBar.Bardate.ToString()
                    ,cBarList.Count.ToString()
                    ,_myComSVM._mySVMDataLength.ToString()
                    ,_myComSVM.currentC().ToString()
                    ,_myComSVM.currentGamma().ToString()
                    ,((Calc.OpenPL(tOther.trade, pt[tOther.symbol]) + pt[tOther.symbol].ClosedPL) * ContractSize-_totalFee).ToString("F4", System.Globalization.CultureInfo.InvariantCulture)
                    ,_totalFee.ToString("F4", System.Globalization.CultureInfo.InvariantCulture)
                    ,signalVecValueComSVM[0].ToString("F4", System.Globalization.CultureInfo.InvariantCulture)
                    ,signalVecValueComSVM[1].ToString("F4", System.Globalization.CultureInfo.InvariantCulture)
                    ,signalVecValueComSVM[2].ToString("F4", System.Globalization.CultureInfo.InvariantCulture)
                    ,aSVM.ToString("F4", System.Globalization.CultureInfo.InvariantCulture)
                    ,bSVM.ToString("F4", System.Globalization.CultureInfo.InvariantCulture)
                    ,cSVM.ToString("F4", System.Globalization.CultureInfo.InvariantCulture)
                    ,RecallSVM.ToString("F4", System.Globalization.CultureInfo.InvariantCulture)
                    ,precisionSVM.ToString("F4", System.Globalization.CultureInfo.InvariantCulture)
                    ,FMeasureSVM.ToString("F4", System.Globalization.CultureInfo.InvariantCulture)
                });
            string[] IndicatorValueHolderHead1 = new string[(_numberClass) * 6];
            for (Int32 ll = 0; ll < _numberClass; ll++)
            {
                Int32 llOther = _numberClass - 1 - ll;
                String tmp = _confusionMatrixVec[0].Rows[ll][ll].ToString();
                IndicatorValueHolderHead1[ll * 6] = tmp;
                Decimal kkSum = 0m;
                for (Int32 kk = 0; kk < _numberClass; kk++)
                {
                    if (kk != ll)
                    {
                        kkSum += Convert.ToInt32(_confusionMatrixVec[0].Rows[kk][ll]);
                    }
                }
                tmp = kkSum.ToString();
                IndicatorValueHolderHead1[ll * 6 + 1] = tmp;
                kkSum = 0m;
                for (Int32 kk = 0; kk < _numberClass; kk++)
                {
                    if (kk != ll)
                    {
                        kkSum += Convert.ToInt32(_confusionMatrixVec[0].Rows[ll][kk]);
                    }
                }
                tmp = kkSum.ToString();
                IndicatorValueHolderHead1[ll * 6 + 2] = tmp;
                tmp = _performanceMeasure.Rows[0]["Recall" + ll.ToString()].ToString();
                IndicatorValueHolderHead1[ll * 6 + 3] = tmp;
                tmp = _performanceMeasure.Rows[0]["Precision" + ll.ToString()].ToString();
                IndicatorValueHolderHead1[ll * 6 + 4] = tmp;
                tmp = _performanceMeasure.Rows[0]["FMeasure" + ll.ToString()].ToString();
                IndicatorValueHolderHead1[ll * 6 + 5] = tmp;
            }

            string[] IndicatorValueHolderHead = new string[IndicatorValueHolderHead0.Length + IndicatorValueHolderHead1.Length];
            for (Int32 i = 0; i < IndicatorValueHolderHead0.Length; i++)
            {
                IndicatorValueHolderHead[i] = IndicatorValueHolderHead0[i];
            }
            for (Int32 i = 0; i < IndicatorValueHolderHead1.Length; i++)
            {
                IndicatorValueHolderHead[i + IndicatorValueHolderHead0.Length] = IndicatorValueHolderHead1[i];
            }
            for (Int32 i = 0; i < IndicatorValueHolderHead.Length; i++)
            {
                _indicatorValueHolder[i] = IndicatorValueHolderHead[i];
            }

            turningPointValueSum = 0;
            _periodsValueOnCurrent = _myComSVM.periodsValueOn();
            Int32 nLast = _indicatorOutput.Rows.Count;
            if (nLast > 0)
            {
                updateabc(ref aSVM, ref bSVM, ref cSVM, "ComSVM", signalVecValueComSVM);
                if (signalVecValueComSVM[1] != Decimal.MinValue)
                {
                    Decimal tmpLocal = -200;
                    Decimal.TryParse(_indicatorOutput.Rows[nLast - 1]["ComSVM"].ToString(), out tmpLocal);
                    Int32 tmpLocal1 = (Int32)signalVecValueComSVM[1];
                    if (_numberClass == 2 && !isTwoClassUpAndDown)
                    {
                        tmpLocal1 = Math.Abs(tmpLocal1);
                        tmpLocal = Math.Abs(tmpLocal);
                    }
                    if (Math.Abs(tmpLocal) != Math.Abs(Decimal.MinValue))
                        updateConfusionMatrix((Int32)tmpLocal, tmpLocal1, 0);

                }
                Int32 tmpLocalIndex = 15;
                tmpLocalIndex = Array.IndexOf(IndicatorHead, "ComSVMSignalSum") + 1;
                _indicatorValueHolder[tmpLocalIndex + 0] = aSVM.ToString("F0", System.Globalization.CultureInfo.InvariantCulture) +
                    "-" + _confusionMatrixVec[0].Rows[0][0].ToString();
                _indicatorValueHolder[tmpLocalIndex + 1] = bSVM.ToString("F0", System.Globalization.CultureInfo.InvariantCulture) +
                    "-" + _confusionMatrixVec[0].Rows[1][0].ToString();
                _indicatorValueHolder[tmpLocalIndex + 2] = cSVM.ToString("F0", System.Globalization.CultureInfo.InvariantCulture) +
                    "-" + _confusionMatrixVec[0].Rows[0][1].ToString();
                _indicatorValueHolder[tmpLocalIndex + 3] = RecallSVM.ToString("F4", System.Globalization.CultureInfo.InvariantCulture) +
                    "-" + _performanceMeasure.Rows[0]["Recall0"];
                _indicatorValueHolder[tmpLocalIndex + 4] = precisionSVM.ToString("F4", System.Globalization.CultureInfo.InvariantCulture) +
                   "-" + _performanceMeasure.Rows[0]["Precision0"];
                _indicatorValueHolder[tmpLocalIndex + 5] = FMeasureSVM.ToString("F4", System.Globalization.CultureInfo.InvariantCulture) +
                   "-" + _performanceMeasure.Rows[0]["FMeasure0"];

                for (Int32 j = 0; j < _gindList.Count; j++)
                {
                    Decimal[] signalVecValueMACD = new Decimal[_gindList[j].GetSignalVecLengthLocal()];
                    _gindList[j].GetSignalVec(ref signalVecValueMACD);
                    if (_periodsValueOnCurrent[j] != 1)
                    {
                        for (Int32 ll = 0; ll < signalVecValueMACD.Length; ll++)
                        {
                            signalVecValueMACD[ll] = Decimal.MinValue;
                        }
                    }
                    else
                    {
                        if(_gindList[j].isLengthValid)
                            turningPointValueSum += signalVecValueMACD[4];
                    }

                    _indicatorValueHolder[IndicatorValueHolderHead.Length + j * _indDisplayLength + 0] = signalVecValueMACD[0].ToString("F4", System.Globalization.CultureInfo.InvariantCulture);
                    _indicatorValueHolder[IndicatorValueHolderHead.Length + j * _indDisplayLength + 1] = signalVecValueMACD[1].ToString("F4", System.Globalization.CultureInfo.InvariantCulture);
                    _indicatorValueHolder[IndicatorValueHolderHead.Length + j * _indDisplayLength + 2] = signalVecValueMACD[2].ToString("F4", System.Globalization.CultureInfo.InvariantCulture);
                    _indicatorValueHolder[IndicatorValueHolderHead.Length + j * _indDisplayLength + 3] = signalVecValueMACD[3].ToString("F4", System.Globalization.CultureInfo.InvariantCulture);
                    if (_gindList[j].Name == "supereight")
                    {
                        _indicatorValueHolder[IndicatorValueHolderHead.Length + j * _indDisplayLength + 4] = 1.ToString("F4", System.Globalization.CultureInfo.InvariantCulture);
                    }
                    else
                    {
                        _indicatorValueHolder[IndicatorValueHolderHead.Length + j * _indDisplayLength + 4] = signalVecValueMACD[4].ToString("F4", System.Globalization.CultureInfo.InvariantCulture);
                    }
                    String tmp = a[j].ToString("F0", System.Globalization.CultureInfo.InvariantCulture) +
                        "-" + _confusionMatrixVec[j + 1].Rows[0][0].ToString();
                    _indicatorValueHolder[IndicatorValueHolderHead.Length + j * _indDisplayLength + 5] = tmp;
                    tmp = b[j].ToString("F0", System.Globalization.CultureInfo.InvariantCulture) +
                        "-" + _confusionMatrixVec[j + 1].Rows[1][0].ToString();
                    _indicatorValueHolder[IndicatorValueHolderHead.Length + j * _indDisplayLength + 6] = tmp;
                    tmp = c[j].ToString("F0", System.Globalization.CultureInfo.InvariantCulture) +
                        "-" + _confusionMatrixVec[j + 1].Rows[0][1].ToString();
                    _indicatorValueHolder[IndicatorValueHolderHead.Length + j * _indDisplayLength + 7] = tmp;
                    tmp = Recall[j].ToString("F4", System.Globalization.CultureInfo.InvariantCulture) +
                        "-" + _performanceMeasure.Rows[j + 1]["Recall0"];
                    _indicatorValueHolder[IndicatorValueHolderHead.Length + j * _indDisplayLength + 8] = tmp;
                    tmp = precision[j].ToString("F4", System.Globalization.CultureInfo.InvariantCulture) +
                        "-" + _performanceMeasure.Rows[j + 1]["Precision0"];
                    _indicatorValueHolder[IndicatorValueHolderHead.Length + j * _indDisplayLength + 9] = tmp;
                    tmp = FMeasure[j].ToString("F4", System.Globalization.CultureInfo.InvariantCulture) +
                        "-" + _performanceMeasure.Rows[j + 1]["FMeasure0"];
                    _indicatorValueHolder[IndicatorValueHolderHead.Length + j * _indDisplayLength + 10] = tmp;

                    for (Int32 ll = 1; ll < _numberClass; ll++)
                    {
                        tmp = _confusionMatrixVec[j + 1].Rows[ll][ll].ToString();
                        _indicatorValueHolder[IndicatorValueHolderHead.Length + j * _indDisplayLength + 11 + (ll - 1) * 6] = tmp;
                        Decimal kkSum = 0m;
                        for (Int32 kk = 0; kk < _numberClass; kk++)
                        {
                            if (kk != ll)
                            {
                                kkSum += Convert.ToInt32(_confusionMatrixVec[j + 1].Rows[kk][ll]);
                            }
                        }
                        tmp = kkSum.ToString();
                        _indicatorValueHolder[IndicatorValueHolderHead.Length + j * _indDisplayLength + 12 + (ll - 1) * 6] = tmp;
                        kkSum = 0m;
                        for (Int32 kk = 0; kk < _numberClass; kk++)
                        {
                            if (kk != ll)
                            {
                                kkSum += Convert.ToInt32(_confusionMatrixVec[j + 1].Rows[ll][kk]);
                            }
                        }
                        tmp = kkSum.ToString();
                        _indicatorValueHolder[IndicatorValueHolderHead.Length + j * _indDisplayLength + 13 + (ll - 1) * 6] = tmp;
                        tmp = _performanceMeasure.Rows[j + 1]["Recall" + ll.ToString()].ToString();
                        _indicatorValueHolder[IndicatorValueHolderHead.Length + j * _indDisplayLength + 14 + (ll - 1) * 6] = tmp;
                        tmp = _performanceMeasure.Rows[j + 1]["Precision" + ll.ToString()].ToString();
                        _indicatorValueHolder[IndicatorValueHolderHead.Length + j * _indDisplayLength + 15 + (ll - 1) * 6] = tmp;
                        tmp = _performanceMeasure.Rows[j + 1]["FMeasure" + ll.ToString()].ToString();
                        _indicatorValueHolder[IndicatorValueHolderHead.Length + j * _indDisplayLength + 16 + (ll - 1) * 6] = tmp;
                    }
                    if (SynWithSVM && !_calcMeasure)
                    {
                        if (signalVecValueComSVM[0] != Decimal.MinValue)
                        {
                            _calcMeasure = true;
                        }
                    }
                    if (_calcMeasure)
                    {
                        String tmpTurnSym = _gindNameList[j].ToUpper() + "-Turn" + j.ToString();
                        if (j == -1) // modify : if (j == 0); reason : j==0 mean MACD, j==-1 mean ComSVM.
                        {
                            tmpTurnSym = "ComSVM";
                        }
                        updateabc(ref a[j], ref b[j], ref c[j], tmpTurnSym, signalVecValueComSVM);
                        if (signalVecValueComSVM[1] != Decimal.MinValue)
                        {
                            if (_periodsValueOnLast[j] == 1)
                            {
                                Decimal tmpLocal = -200;
                                Decimal.TryParse(_indicatorOutput.Rows[nLast - 1][tmpTurnSym].ToString(), out tmpLocal);
                                Int32 tmpLocal1 = (Int32)signalVecValueComSVM[1];
                                if (_numberClass == 2 && !isTwoClassUpAndDown)
                                {
                                    tmpLocal1 = Math.Abs(tmpLocal1);
                                    tmpLocal = Math.Abs(tmpLocal);
                                }

                                if (Math.Abs(tmpLocal) != Math.Abs(Decimal.MinValue))
                                    updateConfusionMatrix((Int32)tmpLocal, tmpLocal1, j + 1);
                            }
                        }
                    }
                }
            }
            if (!IsAutoRunIndicators)
            {
                MiscUtility.addRowToTable(_indicatorOutput, out _indicatorOutput, 1);
                nLast = _indicatorOutput.Rows.Count;
                for (Int32 j = 0; j < _indicatorValueHolder.Length; j++)
                {
                    _indicatorOutput.Rows[nLast - 1][j] = _indicatorValueHolder[j];
                }
                for (Int32 ii = 0; ii < _indicatorValueHolder.Length; ii++)
                {
                    _indicatorValueHolder[ii] = _indicatorValueHolder[ii].Replace(Decimal.MaxValue.ToString("F4", System.Globalization.CultureInfo.InvariantCulture), "NaN");
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
            _lastTick = tick;
            Int32 tickDate = tick.date;
            String tickSymbol = tick.symbol;
            // for rerun at a different date
            if (tickDate != _date)
            {
                if (_kt.getindex(tickSymbol) != -1)
                {
                    isValid = true;
                }
            }
            // ensure response is active
            if (!isValid) return;
            // Only trade between StartDate and Enddate
            if (tickDate < _startDateTL || tick.date > _endDateTL)
            {
                return;
            }
            // ensure we are tracking active status for this symbol
            int idx = _active.addindex(tickSymbol, true);
            // if we're not active, quit
            if (!_active[idx]) return;
           

            if (tickDate != _date)
            {
                Boolean resetHere = IsResetOnNewDay||(tickDate < _date);
                if (resetHere)
                {
                    Boolean resetBarData = IsBarReset || (tickDate < _date);
                    ResetDetail(resetBarData);
                    _stopNewTradeTriggerLocal = StopNewTradeTrigger + _PNLForAll;
                }
                if (_symbolLast != String.Empty)
                {
                    if (IsSkipRolloverDay)
                    {
                        if (tickSymbol != _symbolLast)
                        {
                            _isRollOverDate = true;
                            if (!IsFastCalc)
                            D("Skip trading for: " + tickSymbol + " @" + tick.date);
                        }
                        else
                        {
                            _isRollOverDate = false;
                        }
                    }
                }
                _symbolLast = tickSymbol;
            }
            _time = tick.time;
            _date = tick.date;
            // apply bar tracking to all ticks that enterz
            _kt.newTick(tick);
            blt.newTick(tick);
            
        }

        Decimal totalClosedPNL(ref Boolean isAllFlat)
        {
            Decimal totalClosePNLValue = 0;
            isAllFlat = true;
            foreach (Position p in pt)
            {
                if (p.UnsignedSize == 0)
                {
                    totalClosePNLValue += pt[p.symbol].ClosedPL * ContractSize;
                }
                if (!p.isFlat)
                {
                    isAllFlat = false;
                }

            }
            return totalClosePNLValue;
        }

        void shutdown()
        {
            if (_isTradingStop)
            {
                return;
            }
            if (!IsFastCalc)
            D("shutting down everything");
            Boolean allFlat = true;
           
            _PNLForAll = 0;
            foreach (Position p in pt)
            {
                Tick tOther = _kt[p.symbol];
                if (p.UnsignedSize > 0)
                {

                    Boolean side = !p.isLong;
                    Decimal adj = (side ? -1 : +1) * _quasiMarketOrderAdjSize;
                    Int64 _orderidLocal = _idtLocal.AssignId;
                    LimitOrder lOrder = new LimitOrder(p.symbol, side, p.UnsignedSize, tOther.trade - adj, _orderidLocal);
                    O(lOrder);
                }
                else
                {
                    _PNLForAll += pt[p.symbol].ClosedPL * ContractSize;
                }
                if (!p.isFlat)
                {
                    allFlat = false;
                }

            }
            //_PNLForAll = totalClosedPNL(ref allFlat);

            if (allFlat)
            {
                //if (!IsOptRun && IsBarReset)
                //isValid = false;
                _isTradingStop = true;
                _stopNewTradeTriggerLocal = StopNewTradeTrigger + _PNLForAll;
                if (!IsFastCalc)
                {
                    D("StopNewTradeTrigger: " + (_stopNewTradeTriggerLocal));
                    D("PNL: " + _PNLForAll);
                }
            }
        }

        void shutdown(string sym)
        {
            // notify
            if (!IsFastCalc)
            D("shutting down " + sym);
            // send flat order
            Tick tOther = _kt[sym];
            Boolean side = !pt[sym].isLong;
            Decimal adj = (side ? -1 : +1) * _quasiMarketOrderAdjSize;
            Int64 _orderidLocal = _idtLocal.AssignId;
            LimitOrder lOrder = new LimitOrder(sym, side, pt[sym].UnsignedSize, tOther.trade - adj, _orderidLocal);
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
            if (!IsFastCalc)
            D("Fill:" + fill.ToString() + " idx:" + idx.ToString() + " life:" + _tradeLifeLocal.ToString());
            // ignore unknown symbols
            if (idx < 0) return;
            // stop waiting
            _wait[fill.symbol] = false;
            _tradeLifeLocal = 0;
            _trailingStopTrigger = fill.xprice;
            _totalFee += fill.xprice * (FeeRate + Slippage) * ContractSize;
            _numberOfFill += 1;

            Boolean allFlat = false;
            _PNLForAll = totalClosedPNL(ref allFlat);
            if (allFlat)
            {
                if (_currentTradeType == 1)
                {
                    _lastLongPNL = _PNLForAll - _PNLForAllAtTradeOpen;
                    _currentTradeType = 0;
                }
                if (_currentTradeType == -1)
                {
                    _lastShortPNL = _PNLForAll - _PNLForAllAtTradeOpen;
                    _currentTradeType = 0;
                }
            }
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
        Int32 _numberClass = 2;
    }

    public class SVMCompositeMultiSuperEightShort : SVMCompositeMultiSuperEight
    {
        public SVMCompositeMultiSuperEightShort()
        {
            Super8LookBackPeriod = 15;
            UseSuerp8Vector = false;
            Featureseachcase = 8;
            SvmGammaValue = 1.0m / Featureseachcase; 
        }
    }
    public class SVMCompositeMultiSuperEightWeiNan : SVMCompositeMultiSuperEight
    {
        public SVMCompositeMultiSuperEightWeiNan()
        {
            SvmForcastPeriodUp = 0.0001m;
            SvmForcastPeriodDown = -0.0001m;
            FeeRate = 0m;
            Slippage = 0m;
            Casesfortraining = 100;
            CasesfortrainingFirst = 100;
            Retrainfreq = 10;
            Svmtrainfreq = 10;
            Svmgridsearchfreq = 10;
            IsFullFeatures = true;
            TradeLife = 5;
            IsFixedLife = false;
            TakeProfitTrigger = 0.02m;
            // To Match his original code: StopLossTrigger = 0.02m; which effective make the trade life one day.
            StopLossTrigger = -0.02m;
            IsOpenSignalOnly = true;
            Super8LookBackPeriod = 15;
            UseSuerp8Vector = false;
            Featureseachcase = 8;
            SvmGammaValue = 1.0m / Featureseachcase;
            SvmCValue = 1.0m;
        }
    }
    public class SVMCompositeMultiSuperEight : SVMCompositeMulti
    {
        public SVMCompositeMultiSuperEight()
            : base(true)
        {
            WithTickFeed = false;
            MyTestCase = testCase.super8;
            IsFixedLife = true;
            IsOpenSignalOnly = true;
            isSingleTrain = false;
            CasesfortrainingFirst = 186;
            //CasesfortrainingFirst = 200;
            Svmgridsearchfreq = 100000;
            QuasiMarketOrderAdjSize = 300m;
            Super8LengthPerItem = 5;
            Super8LookBackPeriod = 15;
            UseSuerp8Vector = true;
            Featureseachcase = 8;
            if (UseSuerp8Vector)
            {
                Featureseachcase = 8*(Super8LookBackPeriod/Super8LengthPerItem);
            }
            LongSideTradeLimit = 100000;
            StopNewLongTradeTrigger = -100000;
            ShortSideTradeLimit = 100000;
            StopNewShortTradeTrigger = -100000;
        }
    }
    public class SVMCompositeMultiAuto : SVMCompositeMulti
    {
        public SVMCompositeMultiAuto() : base(false) 
        { 
            IsAutoRunIndicators = true; 
            WithTickFeed = false;
            TrailingStopOnTrigger = -1000000m;
        }
        
    }
    public class SVMCompositeMultiTurningpoint : SVMCompositeMulti
    {
        public SVMCompositeMultiTurningpoint()
            : base(true)
        {
            WithTickFeed = false;
            MyTestCase = testCase.turningpoint;
            SvmForcastPeriod = 0;
            Casesfortraining = 215;
            CasesfortrainingFirst = 215;
            Featureseachcase = 3;
            Retrainfreq = 5;
            Svmtrainfreq = 5;
            Svmgridsearchfreq = 21500;
            //Svmgridsearchfreq = 21500;
            // make it big if no grid search is needed
            //Svmgridsearchfreq = 2150;
            IsFullFeatures = false;
            TradeLife = 500000;
            Useabsturningvalue = true;
            StopNewTradeTrigger = -100000m;
            TakeProfitTrigger = 100000m;
            StopLossTrigger = -0.05m;
            GindPeriod = "macd:1;bias:1;kdj:1";
            RealzedTurnPointTol = 0.01m;
            TurningPointValueTol = 0.0085m;
            Wtransoformlevelshift = -3000;
        }
    }
}
