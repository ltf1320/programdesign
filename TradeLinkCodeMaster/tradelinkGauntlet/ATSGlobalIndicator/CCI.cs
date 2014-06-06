using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
//using TradeLink.CommonATS;
using System.Collections;

namespace ATSGlobalIndicator
{
    [Serializable]
    public class CCI : GenericIndicatorTemplate
    {
        public CCI()
        {
        }
        /// <summary>
        /// Initializatin
        /// </summary>
        public override void Initializatin()
        {
            Name = GetType().Name.ToLower();
            _turningPointValueTol = 0.0085m;
            _lookBackPeriodAve = 20;
            _lookBackPeriodSd = 20;
            _constant = 0.015m;
            _lowerBandDownLimit = Decimal.MinValue;
            _lowerBandUpLimit = -100;
            _upperBandDownLimit = Decimal.MaxValue;
            _upperBandUpLimit = 100;
            if (_inputParam != null)
                GetParam();
            _dataLength = 0;
            inUpperBand = false;
            inLowerBand = false;
            _signalVecLength = 8;
            _valueVec = new Queue<decimal>();// modify : null
            _avePrice = new Queue<decimal>();// modify : null
            _lastcci = 0m;
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
            if (_inputParam.ContainsKey("lookbackperiodave"))
            {
                _lookBackPeriodAve = Convert.ToInt32(_inputParam["lookbackperiodave"].ToString());
            }
            if (_inputParam.ContainsKey("lookbackperiodsd"))
            {
                _lookBackPeriodSd = Convert.ToInt32(_inputParam["lookbackperiodsd"].ToString());
            }
            if (_inputParam.ContainsKey("constant"))
            {
                _constant = Convert.ToDecimal(_inputParam["constant"].ToString());
            }
            if (_inputParam.ContainsKey("minmumsignallength"))
            {
                _minmumSignalLength = Convert.ToInt32(_inputParam["minmumsignallength"].ToString());
            }
            if (_inputParam.ContainsKey("lowerbanddownlimit"))
            {
                _lowerBandDownLimit = Convert.ToDecimal(_inputParam["lowerbanddownlimit"].ToString());
            }
            if (_inputParam.ContainsKey("lowerbandpplimit"))
            {
                _lowerBandUpLimit = Convert.ToDecimal(_inputParam["lowerbandpplimit"].ToString());
            }
            if (_inputParam.ContainsKey("upperbanddownlimit"))
            {
                _upperBandDownLimit = Convert.ToDecimal(_inputParam["upperbanddownlimit"].ToString());
            }
            if (_inputParam.ContainsKey("upperbanduplimit"))
            {
                _upperBandUpLimit = Convert.ToDecimal(_inputParam["upperbanduplimit"].ToString());
            }
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
        /// Indicator value update, single value input, period input
        /// </summary>
        public override void UpdateValue(ref Decimal[] valueVec, int period)
        {
            if (period == Period)
            {
                UpdateValue(ref valueVec);
            }
        }
        /// <summary>
        /// Indicator value update, single value input
        /// </summary>
        public override void UpdateValue(ref Decimal[] valueVec)
        {
            // modify : null
            _valueVec.Enqueue(valueVec[0]);
            if (_valueVec.Count > 2)
            {
                _valueVec.Dequeue();
            }
            // end modify
            _close = valueVec[0];
            _high = valueVec[1];
            _low = valueVec[2];

            Decimal tp = (_close + _high + _low) / 3;
            _avePrice.Enqueue(tp);
            if (_avePrice.Count > _lookBackPeriodAve)
            {
                _avePrice.Dequeue();
            }

            Decimal smatp = _avePrice.Average();

            if (_dataLength < _lookBackPeriodSd)
            {
                _cci = 0m;
            }
            else
            {
                Decimal smad = 0m;
                for (int i = 0; i < _lookBackPeriodSd; i++)
                {
                    smad += Math.Abs(smatp - _avePrice.ElementAt(_avePrice.Count() - i - 1));
                }
                _cci = (tp - smatp) / (_constant * smad / _lookBackPeriodSd);
            }
            if (_dataLength < (Int64)(_minmumSignalLength))
            {
                _cci = 0;
            }
            if (_dataLength <= (Int64)(_minmumSignalLength))
            {
                _lastcci = _cci;
            }
            _dataLength++;
            _signalValue = _cci;           
            updateLocalMaxMin();
            _lastcci = _signalValue;
        }
        /// <summary>
        /// Signal local min and max calculation, turning point calculation
        /// </summary>
        public override void updateLocalMaxMin()
        {
            if (_calcTurningPoint)
            {
                if (_signalValue > _upperBandDownLimit && _lastcci < _upperBandDownLimit && Math.Abs((_valueVec.ElementAt(1) - _valueVec.ElementAt(0)) / _valueVec.ElementAt(0)) > _turningPointValueTol)
                    _turningPointValue = 1;
                else if (_signalValue < _upperBandDownLimit && _lastcci > _upperBandDownLimit && Math.Abs((_valueVec.ElementAt(1) - _valueVec.ElementAt(0)) / _valueVec.ElementAt(0)) > _turningPointValueTol)
                    _turningPointValue = -1;
                else if (_signalValue < _lowerBandUpLimit && _lastcci > _lowerBandUpLimit && Math.Abs((_valueVec.ElementAt(1) - _valueVec.ElementAt(0)) / _valueVec.ElementAt(0)) > _turningPointValueTol)
                    _turningPointValue = -1;
                else if (_signalValue > _lowerBandUpLimit && _lastcci < _lowerBandUpLimit && Math.Abs((_valueVec.ElementAt(1) - _valueVec.ElementAt(0)) / _valueVec.ElementAt(0)) > _turningPointValueTol)
                    _turningPointValue = 1;
                else
                    _turningPointValue = 0;
            }

            inUpperBand = false;
            inLowerBand = false;
            if (_signalValue >= _upperBandDownLimit && _signalValue < _upperBandUpLimit)
            {
                if (_isLocalMin)
                {
                    // jump to upperBand
                    _signalValueLocalMax = _signalValue;
                    _isLocalMax = true;
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
                }
                _isLocalMin = false;
                _signalValueLocalMin = Decimal.MaxValue;
                inUpperBand = true;
            }
            else if (_signalValue > _lowerBandDownLimit && _signalValue <= _lowerBandUpLimit)
            {
                if (_isLocalMax)
                {
                    // jump to lowerband
                    _signalValueLocalMin = _signalValue;
                    _isLocalMin = true;
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

                }
                _isLocalMax = false;
                _signalValueLocalMax = Decimal.MinValue;
                inLowerBand = true;
            }
            else
            {
                _isLocalMax = false;
                _isLocalMin = false;
            }
        }
        /// <summary>
        /// Indicator value update, single value input, period input
        /// </summary>

        public Decimal _close;
        public Decimal _high;
        public Decimal _low;
        public Decimal _cci;
        public Int32 _lookBackPeriodAve;
        public Int32 _lookBackPeriodSd;
        public Decimal _constant;
        public Decimal _oneOver_lookBackPeriod;
        public Queue<Decimal> _avePrice;
        public Decimal _lastcci;
    }
}

