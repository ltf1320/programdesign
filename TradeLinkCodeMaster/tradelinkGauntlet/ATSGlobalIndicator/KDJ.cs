using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Collections;
using System.Xml;
using System.Xml.Serialization;

namespace ATSGlobalIndicator
{
    [Serializable]
    public class KDJ : GenericIndicatorTemplate
    {
        public KDJ()
        {
        }
        /// <summary>
        /// Initializatin
        /// </summary>
        public override void Initializatin()
        {
            Name = GetType().Name.ToLower();
            _lookBackPeriod = 9;
            _lowerBandDownLimit = 0;
            _lowerBandUpLimit = 25;
            _upperBandDownLimit = 75;
            _upperBandUpLimit = 100;
            _turningPointValueTol = 0.0085m;
            if (_inputParam != null)
                GetParam();
            _dataLength = 0;
            inUpperBand =false;
            inLowerBand = false;

            _hisHigh = new Queue<Decimal>();
            _hisLow = new Queue<Decimal>();
            _k = 50;
            _d = 50;
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
            if (_inputParam.ContainsKey("lookbackperiod"))
            {
                _lookBackPeriod = Convert.ToInt32(_inputParam["lookbackperiod"].ToString());
            }
            _minmumSignalLength = _lookBackPeriod;
            if (_inputParam.ContainsKey("minmumsignallength"))
            {
                _minmumSignalLength = Convert.ToInt32(_inputParam["minmumsignallength"].ToString());
            }
            if (_inputParam.ContainsKey("lowerbanddownlimit"))
            {
                _lowerBandDownLimit = Convert.ToInt32(_inputParam["lowerbanddownlimit"].ToString());
            }
            if (_inputParam.ContainsKey("lowerbanduplimit"))
            {
                _lowerBandUpLimit = Convert.ToInt32(_inputParam["lowerbanduplimit"].ToString());
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
            _valueVec.Enqueue(valueVec[0]);
            if (_valueVec.Count > 2)
            {
                _valueVec.Dequeue();
            }

            _close = valueVec[0];
            _hisHigh.Enqueue(valueVec[1]);
            _hisLow.Enqueue(valueVec[2]);

            Decimal _rh = maxValue(ref _hisHigh);
            Decimal _rl = minValue(ref _hisLow);
            Decimal _rsv = 0;
            if (_rh > _rl)
            {
                _rsv = (_close - _rl) / (_rh - _rl) * 100;
            }
            _k = (_rsv + 2 * _k) / 3;
            _d = (_k + 2 * _d) / 3;
            _j = 3 * _k - 2 * _d;


            _dataLength++;
            if (_dataLength < (Int64)(_minmumSignalLength))
            {
                _j = 0;
            }

            _signalValue = _j;
            updateLocalMaxMin();

            if (_hisHigh.Count == _lookBackPeriod)
            {
                _hisHigh.Dequeue();
                _hisLow.Dequeue();
            }
        }
        /// <summary>
        /// Calculate input vector max value
        /// </summary>
        Decimal maxValue(ref Queue<Decimal> input)
        {
            Int32 cnt = input.Count;
            Decimal _maxV = input.ElementAt(0);
            for (Int32 i = 0; i < cnt; i++)
            {
                if (_maxV < input.ElementAt(i))
                {
                    _maxV = input.ElementAt(i);
                }
            }
            return _maxV;
        }
        /// <summary>
        /// Calculate input vector min value
        /// </summary>
        Decimal minValue(ref Queue<Decimal> input)
        {
            Int32 cnt = input.Count;
            Decimal _minV = input.ElementAt(0);
            for (Int32 i = 0; i < cnt; i++)
            {
                if (_minV > input.ElementAt(i))
                {
                    _minV = input.ElementAt(i);
                }
            }
            return _minV;
        }

        public Decimal _k;
        public Decimal _d;
        public Decimal _j;
        public Decimal _close;
        [XmlIgnore]
        public Queue<Decimal> _hisHigh;
        [XmlIgnore]
        public Queue<Decimal> _hisLow;
        public Int32 _lookBackPeriod;
    }
}
