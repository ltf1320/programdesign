using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
//using TradeLink.CommonATS;
using System.Collections;
using BaseUtility;

namespace ATSGlobalIndicator
{
    [Serializable]
    public class MACD : GenericIndicatorTemplate
    {
        public MACD()
        {
        }
        /// <summary>
        /// Initializatin
        /// </summary>
        public override void Initializatin()
        {
            Name = GetType().Name.ToLower();
            _setEMAMinmumSignalLength = false;
            _minmumSignalLength = 0;
            _lookBackPeriodAve = 0;
            _lookBackPeriodLong = 0;
            _lookBackPeriodShort = 0;
            _turningPointValueTol = 0.0085m;
            if (_inputParam != null)
                GetParam();
            _signalValueLocalMax = Decimal.MinValue;
            _signalValueLocalMin = Decimal.MaxValue;
            _dataLength = 0;
            _dif = 0m;
            _dea = 0m;
            _macd = 0m;
            _signalVecLength = 8;
            _valueVec = new Queue<decimal>();// modify : null
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
            if (_inputParam.ContainsKey("setemaminmumsignallength".ToLower()))
            {
                _setEMAMinmumSignalLength = Convert.ToBoolean(_inputParam["setemaminmumsignallength".ToLower()].ToString());
            }
            if (_inputParam.ContainsKey("minmumsignallength"))
            {
                _minmumSignalLength = Convert.ToInt32(_inputParam["minmumsignallength"].ToString());
            }
            if (_inputParam.ContainsKey("lookbackperiodave"))
            {
                _lookBackPeriodAve = Convert.ToInt32(_inputParam["lookbackperiodave"].ToString());
                if (_lookBackPeriodAve > 0)
                {
                    Hashtable _inputParamAve = new Hashtable();
                    _lookBackPeriodAveAlpha = -10000;
                    if (_inputParam.ContainsKey("lookbackperiodavealpha"))
                    {
                        _lookBackPeriodAveAlpha = Convert.ToDecimal(_inputParam["lookbackperiodavealpha"].ToString());
                    }
                    _inputParamAve["lookbackperiod"] = _lookBackPeriodAve.ToString();
                    _inputParamAve["alpha"] = _lookBackPeriodAveAlpha.ToString();
                    if (_setEMAMinmumSignalLength)
                    {
                        _inputParamAve["minmumsignallength"] = (_minmumSignalLength + 1).ToString();
                    }
                    _emaAve = new EMA();
                    _emaAve.Param = _inputParamAve;
                    _emaAve.Initializatin();
                }
            }
            _minmumSignalLength = Math.Max(_minmumSignalLength, _lookBackPeriodAve);
            if (_inputParam.ContainsKey("lookbackperiodlong"))
            {
                _lookBackPeriodLong = Convert.ToInt32(_inputParam["lookbackperiodlong"].ToString());
                if (_lookBackPeriodLong > 0)
                {
                    Hashtable _inputParamLong = new Hashtable();
                    _lookBackPeriodLongAlpha = -10000;
                    if (_inputParam.ContainsKey("lookbackperiodlongalpha"))
                    {
                        _lookBackPeriodLongAlpha = Convert.ToDecimal(_inputParam["lookbackperiodlongalpha"].ToString());
                    }
                    _inputParamLong["lookbackperiod"] = _lookBackPeriodLong.ToString();
                    _inputParamLong["alpha"] = _lookBackPeriodLongAlpha.ToString();
                    if (_setEMAMinmumSignalLength)
                    {
                        _inputParamLong["minmumsignallength"] = (_minmumSignalLength - _lookBackPeriodAve + 2).ToString();
                    }
                    _emaLong = new EMA();
                    _emaLong.Param = _inputParamLong;
                    _emaLong.Initializatin();
                }
            }
            _minmumSignalLength = Math.Max(_minmumSignalLength, _lookBackPeriodLong);
            if (_inputParam.ContainsKey("lookbackperiodshort"))
            {
                _lookBackPeriodShort = Convert.ToInt32(_inputParam["lookbackperiodshort"].ToString());
                if (_lookBackPeriodShort > 0)
                {
                    Hashtable _inputParamShort = new Hashtable();
                    _lookBackPeriodShortAlpha = -10000;
                    if (_inputParam.ContainsKey("lookbackperiodshortalpha"))
                    {
                        _lookBackPeriodShortAlpha = Convert.ToDecimal(_inputParam["lookbackperiodshortalpha"].ToString());
                    }
                    _inputParamShort["lookbackperiod"] = _lookBackPeriodShort.ToString();
                    _inputParamShort["alpha"] = _lookBackPeriodShortAlpha.ToString();
                    if (_setEMAMinmumSignalLength)
                    {
                        _inputParamShort["minmumsignallength"] = (_minmumSignalLength - _lookBackPeriodAve + 2).ToString();
                    }
                    _emaShort = new EMA();
                    _emaShort.Param = _inputParamShort;
                    _emaShort.Initializatin();
                }
            }
            _minmumSignalLength = Math.Max(_minmumSignalLength, _lookBackPeriodShort);
            if (_inputParam.ContainsKey("calcturningpoint"))
            {
                _calcTurningPoint = Convert.ToBoolean(_inputParam["calcturningpoint"].ToString());
            }
            if (_inputParam.ContainsKey("turningpointvaluetol"))
            {
                _turningPointValueTol = Convert.ToDecimal(_inputParam["turningpointvaluetol"].ToString());
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
            if (_calcTurningPoint)
            {
                _valueVec.Enqueue(value);
                if (_valueVec.Count > 2)
                {
                    _valueVec.Dequeue();
                }
            }

            _emaShort.UpdateValue(value);
            _emaLong.UpdateValue(value);
            _dif = _emaShort.GetSignal() - _emaLong.GetSignal();
            _emaAve.UpdateValue(_dif);
            _dataLength++;
            if (_dataLength <= (Int64)(_minmumSignalLength))
            {
                _macd = 0;
            }
            else
            {
                _dea = _emaAve.GetSignal();
                _macd = 2 * (_dif - _dea);
            }
            _signalValue = _macd;
            updateLocalMaxMin();
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
        /// Signal local min and max calculation, turning point calculation
        /// </summary>
        public override void updateLocalMaxMin()
        {
            if (_calcTurningPoint)
            {
                if (_isLocalMax)
                {
                    if (_signalValue < _signalValueLocalMax && Math.Abs((_valueVec.ElementAt(1) - _valueVec.ElementAt(0)) / _valueVec.ElementAt(0)) > _turningPointValueTol)
                    {
                        _turningPointValue = -1;
                    }
                    else
                    {
                        _turningPointValue = 0;
                    }
                }
                else if (_isLocalMin)
                {
                    if (_signalValue > _signalValueLocalMin && Math.Abs((_valueVec.ElementAt(1) - _valueVec.ElementAt(0)) / _valueVec.ElementAt(0)) > _turningPointValueTol)
                    {
                        _turningPointValue = 1;
                    }
                    else
                    {
                        _turningPointValue = 0;
                    }
                }
                else
                {
                    _turningPointValue = 0;
                }
            }

            if (_signalValue > 0)
            {
                if (_isLocalMin)
                {
                    // switch size for jump to positive
                    _signalValueLocalMax = _signalValue;
                    _isLocalMax = true;
                    _isLocalMin = false;
                }
                else
                {
                    if (_signalValue > _signalValueLocalMax)
                    {
                        _signalValueLocalMax = _signalValue;
                        _isLocalMax = true;
                    }
                    else
                    {
                        _isLocalMax = false;
                    }
                    _isLocalMin = false;
                }
                _signalValueLocalMin = Decimal.MaxValue; ;
            }
            else if (_signalValue < 0)
            {
                
                if (_isLocalMax)
                {
                    // switch size for jump to negative
                    _signalValueLocalMin = _signalValue;
                    _isLocalMin = true;
                    _isLocalMax = false;
                }
                else
                {
                    if (_signalValue < _signalValueLocalMin)
                    {
                        _signalValueLocalMin = _signalValue;
                        _isLocalMin = true;
                    }
                    else
                    {
                        _isLocalMin = false;
                    }
                    _isLocalMax = false;
                }
                _signalValueLocalMax = Decimal.MinValue;
            }
        }
        /// <summary>
        /// Signal value output
        /// </summary>
        public override Decimal GetSignal()
        {
            if (_calcTurningPoint)
            {
                return _turningPointValue;
            }else {
                return _signalValue;
            }
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
                    signalVecValue[i] = Decimal.MinValue;
                }
                return;
            }
            signalVecValue[0] = _signalValue;
            Boolean isLong = (_signalValue > _signalValueLocalMin && _signalValue <= 0)
                || ((_signalValue >= 0) && _signalValue >= _signalValueLocalMax);
            Boolean isShort = (_signalValue <= _signalValueLocalMin && _signalValue <= 0)
                || ((_signalValue >= 0) && _signalValue < _signalValueLocalMax);
            if (isLong)
            {
                signalVecValue[1] = 1;
            }
            else if (isShort)
            {
                signalVecValue[1] = -1;
            }
            else
            {
                signalVecValue[1] = 0;
            }
            signalVecValue[2] = _signalValueLocalMin;
            signalVecValue[3] = _signalValueLocalMax;
            signalVecValue[4] = _turningPointValue;
        }


        public Decimal _dif;
        public Decimal _dea;
        public Decimal _macd;
        public Int32 _lookBackPeriodLong;
        public Decimal _lookBackPeriodLongAlpha;
        public Int32 _lookBackPeriodShort;
        public Decimal _lookBackPeriodShortAlpha;
        public Int32 _lookBackPeriodAve;
        public Decimal _lookBackPeriodAveAlpha;
        public EMA _emaLong;
        public EMA _emaShort;
        public EMA _emaAve;
        public Boolean _setEMAMinmumSignalLength;
    }
}
