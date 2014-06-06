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
    public class HighLow : GenericIndicatorTemplate
    {
        public HighLow()
        {
        }
        /// <summary>
        /// Initializatin
        /// </summary>
        public override void Initializatin()
        {
            Name = GetType().Name.ToLower();
            _lookBackPeriod = 0;
            if (_inputParam != null)
                GetParam();
            _dataLength = 0;
            _hisHigh = new Queue<Decimal>();
            _hisLow = new Queue<Decimal>();
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
            _lookBackPeriodLow = _lookBackPeriod;
            if (_inputParam.ContainsKey("lookbackperiodlow"))
            {
                _lookBackPeriodLow = Convert.ToInt32(_inputParam["lookbackperiodlow"].ToString());
            }
            _minmumSignalLength = _lookBackPeriod;
            if (_inputParam.ContainsKey("minmumsignallength"))
            {
                _minmumSignalLength = Convert.ToInt32(_inputParam["minmumsignallength"].ToString());
            }
            _isRelaxedHighLow = false;
            if (_inputParam.ContainsKey("isrelaxedhighlow"))
            {
                _isRelaxedHighLow = Convert.ToBoolean(_inputParam["isrelaxedhighlow"].ToString());
            }
            _compitWithWeiNan = false;
            if (_inputParam.ContainsKey("compitwithweinan"))
            {
                _compitWithWeiNan = Convert.ToBoolean(_inputParam["compitwithweinan"].ToString());
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
            _close = valueVec[0];
            _hisHigh.Enqueue(valueVec[1]);
            _hisLow.Enqueue(valueVec[2]);
            _spotValue = valueVec[3];
            if (_hisHigh.Count < _lookBackPeriod)
            {
                if (_hisHigh.Count == 1)
                {
                    _highHigh = valueVec[1];
                }
                else
                {
                    _highHigh = Math.Max(_highHigh, valueVec[1]);
                }
            }
            else
            {
                _highHigh = maxValue(ref _hisHigh);
            }

            if (_hisLow.Count < _lookBackPeriodLow)
            {
                if (_hisLow.Count == 1)
                {
                    _lowLow = valueVec[2];
                }
                else
                {
                    _lowLow = Math.Min(_lowLow, valueVec[2]);
                }
            }
            else
            {
                _lowLow = minValue(ref _hisLow);
            }

            _isNewHigh = _highHigh == valueVec[1];
            _isNewLow = _lowLow == valueVec[2];
            _dataLength++;
            if (_dataLength < (Int64)(_minmumSignalLength))
            {
                _highHigh = 0;
                _lowLow = 0;
            }
            if (_compitWithWeiNan)
            {
                if (_hisHigh.Count >= _lookBackPeriod)
                {
                    _hisHigh.Dequeue();
                }
                if (_hisLow.Count >= _lookBackPeriodLow)
                {
                    _hisLow.Dequeue();
                }
            }
            else
            {
                if (_hisHigh.Count > _lookBackPeriod)
                {
                    _hisHigh.Dequeue();
                }
                if (_hisLow.Count > _lookBackPeriodLow)
                {
                    _hisLow.Dequeue();
                }
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
            signalVecValue[0] = _close;
            Boolean isLong = (_spotValue >= _highHigh);
            if (_dataLength <= (Int64)(_lookBackPeriod))
            {
                isLong = false;
            }
            Boolean isShort = (_spotValue <= _lowLow);
            if (_dataLength <= (Int64)(_lookBackPeriodLow))
            {
                isShort = false;
            }
            if (_isRelaxedHighLow)
            {
                isShort |= _isNewLow;
                isLong |= _isNewHigh;
            }
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
            if (_dataLength < _minmumSignalLength)
            {
                signalVecValue[1] = 0;
            }
            signalVecValue[2] = _lowLow;
            signalVecValue[3] = _highHigh;
            signalVecValue[4] = signalVecValue[1];
        }
        /// <summary>
        /// Calculate input vector max value
        /// </summary>
        Decimal maxValue(ref Queue<Decimal> input)
        {
            Decimal _maxV = Decimal.MinValue;
            foreach (Decimal ss in input)
            {
                if (_maxV < ss)
                {
                    _maxV = ss;
                }
            }
            return _maxV;
        }
        /// <summary>
        /// Calculate input vector min value
        /// </summary>
        Decimal minValue(ref Queue<Decimal> input)
        {
            Decimal _minV = Decimal.MaxValue;
            foreach (Decimal ss in input)
            {
                if (_minV > ss)
                {
                    _minV = ss;
                }
            }
            return _minV;
        }

        public Decimal _highHigh;
        public Decimal _lowLow;
        public Decimal _close;
        [XmlIgnore]
        public Queue<Decimal> _hisHigh;
        [XmlIgnore]
        public Queue<Decimal> _hisLow;
        public Int32 _lookBackPeriod;
        public Int32 _lookBackPeriodLow;
        public Boolean _isRelaxedHighLow;
        public Boolean _isNewHigh;
        public Boolean _isNewLow;

        public Boolean _compitWithWeiNan;
    }
}
