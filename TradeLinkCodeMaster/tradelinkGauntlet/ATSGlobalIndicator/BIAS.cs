using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
//using TradeLink.CommonATS;
using System.Collections;

namespace ATSGlobalIndicator
{
    [Serializable]
    public class BIAS : GenericIndicatorTemplate
    {
        public BIAS()
        {
        }
        /// <summary>
        /// Initializatin
        /// </summary>
        public override void Initializatin()
        {
            Name = GetType().Name.ToLower();
            _lookBackPeriod = 6;
            _turningPointValueTol = 0.0085m;
            _lowerBandDownLimit = Decimal.MinValue;
            _lowerBandUpLimit = -2;
            _upperBandDownLimit = Decimal.MaxValue;
            _upperBandUpLimit = 2;
            if (_inputParam != null)
                GetParam();
            _dataLength = 0;
            inUpperBand = false;
            inLowerBand = false;
            _signalVecLength = 8;
            _valueVec = new Queue<decimal>();// modify : null
            _closeVector = new Queue<decimal>();// modify : null
            _lastbias = 0m;
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
            if (_inputParam.ContainsKey("lookbackperiod"))
            {
                _lookBackPeriod = Convert.ToInt32(_inputParam["lookbackperiod"].ToString());
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
        /// Indicator value update, single value input
        /// </summary>
        public override void UpdateValue(Decimal value)
        {
            // modify : null
            _valueVec.Enqueue(value);
            if (_valueVec.Count > 2)
            {
                _valueVec.Dequeue();
            }
            // end modify
            _close = value;

            _closeVector.Enqueue(_close);
            if (_closeVector.Count > _lookBackPeriod)
            {
                _closeVector.Dequeue();
            }

            Decimal aveclose = _closeVector.Average();

            if (_dataLength < _lookBackPeriod)
            {
                _bias = 0m;
            }
            else
            {
                _bias = (_close - aveclose) / aveclose * 100;
            }
            if (_dataLength < (Int64)(_minmumSignalLength))
            {
                _bias = 0;
            }
            if (_dataLength <= (Int64)(_minmumSignalLength))
            {
                _lastbias = _bias;
            }
            _dataLength++;
            _signalValue = _bias;
            updateLocalMaxMin();
            _lastbias = _signalValue;
        }
        /// <summary>
        /// Signal local min and max calculation, turning point calculation
        /// </summary>
        public override void updateLocalMaxMin()
        {
            if (_calcTurningPoint)
            {
                if (_signalValue < _upperBandDownLimit && _lastbias > _upperBandDownLimit && Math.Abs((_valueVec.ElementAt(1) - _valueVec.ElementAt(0)) / _valueVec.ElementAt(0)) > _turningPointValueTol)
                    _turningPointValue = -1;
                else if (_signalValue > _lowerBandUpLimit && _lastbias < _lowerBandUpLimit && Math.Abs((_valueVec.ElementAt(1) - _valueVec.ElementAt(0)) / _valueVec.ElementAt(0)) > _turningPointValueTol)
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
        public override void UpdateValue(Decimal value, int period)
        {
            if (period == Period)
            {
                UpdateValue(value);
            }
        }

        public Decimal _close;
        public Decimal _bias;
        public Int32 _lookBackPeriod;
        public Decimal _oneOver_lookBackPeriod;
        public Queue<Decimal> _closeVector;
        public Decimal _lastbias;
    }
}

