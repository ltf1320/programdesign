using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Collections;//hashtable用的

namespace ATSGlobalIndicator
{
    [Serializable]
    public class TRIX : GenericIndicatorTemplate
    {
        public TRIX()
        {
        }
        /// <summary>
        /// Initializatin
        /// </summary>
        public override void Initializatin()
        {
            Name = GetType().Name.ToLower(); //tolower：转化为小写
            _lookBackPeriod = 0;
            if (_inputParam != null)
                GetParam();
            _valueVec = new Queue<decimal>();
            _dataLength = 0;
            _trix = 0m;
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
            if (_inputParam.ContainsKey("period"))
            {
                _period = Convert.ToInt32(_inputParam["period"].ToString());
            }
            _minmumSignalLength = 0;//其实这样设mSL的default为0是不太好的，得改
            if (_inputParam.ContainsKey("minmumsignallength"))
            {
                _minmumSignalLength = Convert.ToInt32(_inputParam["minmumsignallength"].ToString());
            }
            if (_inputParam.ContainsKey("lookbackperiod"))
            {
                _lookBackPeriod = Convert.ToInt32(_inputParam["lookbackperiod"].ToString());
                if (_lookBackPeriod > 0)
                {
                    _lookBackPeriodAlpha = -10000;
                    if (_inputParam.ContainsKey("lookbackperiodalpha"))
                    {
                        _lookBackPeriodAlpha = Convert.ToDecimal(_inputParam["lookbackperiodalpha"].ToString());
                    }

                    Hashtable _inputParamema1 = new Hashtable();
                    _inputParamema1["lookbackperiod"] = _lookBackPeriod.ToString();
                    _inputParamema1["alpha"] = _lookBackPeriodAlpha.ToString();

                    _ema1 = new EMA();
                    _ema1.Param = _inputParamema1;
                    _ema1.Initializatin();

                    Hashtable _inputParamema2 = new Hashtable();
                    _inputParamema2["lookbackperiod"] = _lookBackPeriod.ToString();
                    _inputParamema2["alpha"] = _lookBackPeriodAlpha.ToString();

                    _ema2 = new EMA();
                    _ema2.Param = _inputParamema2;
                    _ema2.Initializatin();

                    Hashtable _inputParamtr = new Hashtable();
                    _inputParamtr["lookbackperiod"] = _lookBackPeriod.ToString();
                    _inputParamtr["alpha"] = _lookBackPeriodAlpha.ToString();

                    _tr = new EMA();
                    _tr.Param = _inputParamtr;
                    _tr.Initializatin();
                }
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
        /// Indicator value update, single value input
        /// </summary>
        public override void UpdateValue(Decimal value)
        {
            _ema1.UpdateValue(value);
            _ema2.UpdateValue(_ema1.GetSignal());
            _tr.UpdateValue(_ema2.GetSignal());
            _currentTrValue = _tr.GetSignal();
            _dataLength++;
            if (_lastTrValue == 0)
            {
                _lastTrValue = _currentTrValue;
            }
            if (_dataLength <= (Int64)(_minmumSignalLength))
            {
                _trix = 0m;
            }
            else
            {
                _trix = (_currentTrValue - _lastTrValue) / _lastTrValue;
            }
            _lastTrValue = _currentTrValue;
        }
        /// <summary>
        /// Indicator value update, single value input, period input
        /// </summary>
        public override void UpdateValue(Decimal value, int period)
        {
            if (period == Period)
            {
                UpdateValue(value);
            }
        }
        /// <summary>
        /// Signal value output
        /// </summary>
        public override Decimal GetSignal()
        {
            return _trix;
        }
        /// <summary>
        /// Signal vector value output
        /// </summary>
        public override void GetSignalVec(ref Decimal[] signalVecValue)
        {
            if (_dataLength <= (Int64)(_minmumSignalLength))
            {
                for (Int32 i = 0; i < GetSignalVecLength(); i++)
                {
                    signalVecValue[i] = 3333333;//Decimal.MinValue;
                }
                return;
            }
            signalVecValue[0] = _trix;
            signalVecValue[1] = 0;
            signalVecValue[2] = 0;
            signalVecValue[3] = 0;

        }
        public Int32 _lookBackPeriod;
        public Decimal _lookBackPeriodAlpha;
        public Decimal _trix;
        public Decimal _currentTrValue;
        public Decimal _lastTrValue;
        public EMA _ema1;
        public EMA _ema2;
        public EMA _tr;

    }
}

