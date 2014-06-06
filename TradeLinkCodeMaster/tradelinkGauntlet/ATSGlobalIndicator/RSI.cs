using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
//using TradeLink.CommonATS;
using System.Collections;

namespace ATSGlobalIndicator
{
    [Serializable]
    public class RSI : GenericIndicatorTemplate
    {
        public RSI()
        {
        }
        /// <summary>
        /// Initializatin
        /// </summary>
        public override void Initializatin()
        {
            Name = GetType().Name.ToLower();
            _lookBackPeriod = 12;
            _lowerBandDownLimit = 0;
            _lowerBandUpLimit = 20;
            _upperBandDownLimit = 80;
            _upperBandUpLimit = 100;
            _turningPointValueTol = 0.0085m;
            if (_inputParam != null)
                GetParam();
            _dataLength = 0;
            inUpperBand = false;
            inLowerBand = false;
            _close = 0;
            _meanUp = 0m;
            _meanDown = 0m;
            _signalVecLength = 5;
            _valueVec = new Queue<decimal>();// modify : null
            _cUpvector = new Queue<decimal>();// modify : null
            _cDownvector = new Queue<decimal>();// modify : null
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
            _oneOver_lookBackPeriod = 1.0m / _lookBackPeriod;
            _minmumSignalLength = _lookBackPeriod;
            if (_inputParam.ContainsKey("minmumsignallength"))
            {
                _minmumSignalLength = Convert.ToInt32(_inputParam["minmumsignallength"].ToString());
            }
            if (_inputParam.ContainsKey("lowerbanddownlimit"))
            {
                _lowerBandDownLimit = Convert.ToInt32(_inputParam["lowerbanddownlimit"].ToString());
            }
            if (_inputParam.ContainsKey("lowerbandpplimit"))
            {
                _lowerBandUpLimit = Convert.ToInt32(_inputParam["lowerbandpplimit"].ToString());
            }
            if (_inputParam.ContainsKey("upperbanddownlimit"))
            {
                _upperBandDownLimit = Convert.ToInt32(_inputParam["upperbanddownlimit"].ToString());
            }
            if (_inputParam.ContainsKey("upperbanduplimit"))
            {
                _upperBandUpLimit = Convert.ToInt32(_inputParam["upperbanduplimit"].ToString());
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
            _valueVec.Enqueue(value);
            if (_valueVec.Count > 2)
            {
                _valueVec.Dequeue();
            }

            if (_dataLength == 0)
            {
                _close = value;
                _dataLength++;
                return;
            }
            Decimal _diff = value - _close;            
            _close = value;
            Decimal _cUp = 0m;
            Decimal _cDown = 0m;
            if (_diff > 0)
            {
                _cUp = _diff;
            }
            else
            {
                _cDown = -_diff;
            }

            _cUpvector.Enqueue(_cUp);
            _cDownvector.Enqueue(_cDown);
            if (_cUpvector.Count > _lookBackPeriod)
            {
                _cUpvector.Dequeue();
            }
            if (_cDownvector.Count > _lookBackPeriod)
            {
                _cDownvector.Dequeue();
            }

            if (_dataLength <= _lookBackPeriod)
            {
                _meanUp = _meanUp * (_dataLength - 1) + _cUp;
                _meanUp /= (_dataLength);

                _meanDown = _meanDown * (_dataLength - 1) + _cDown;
                _meanDown /= (_dataLength);

            }
            else
            {
                _meanUp = _cUpvector.Sum() / _cUpvector.Count();
                _meanDown = _cDownvector.Sum() / _cDownvector.Count();
            }

            Decimal _tmpSum = _meanUp + _meanDown;
            if (_tmpSum == 0)
            {
                _rsi = 0m;
            }
            else
            {
                _rsi = 100 * (_meanUp / _tmpSum);
            }

            if (_dataLength < (Int64)(_minmumSignalLength))
            {
                _rsi = 0;
            }
            _dataLength++;
            _signalValue = _rsi;
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

        public Decimal _close;
        public Decimal _rsi;
        public Int32 _lookBackPeriod;
        public Decimal _oneOver_lookBackPeriod;
        public Decimal _meanUp;
        public Decimal _meanDown;

        public Queue<Decimal> _cUpvector;
        public Queue<Decimal> _cDownvector;
    }
}
