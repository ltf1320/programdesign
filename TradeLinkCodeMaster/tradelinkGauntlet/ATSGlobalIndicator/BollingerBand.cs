using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Xml;
using System.Xml.Serialization;
//using TradeLink.CommonATS;

namespace ATSGlobalIndicator
{
    [Serializable]
    public class BollingerBand : GenericIndicatorTemplate
    {
        public BollingerBand()
        {
        }
        /// <summary>
        /// Initializatin
        /// </summary>
        public override void Initializatin()
        {
            Name = GetType().Name.ToLower();
            // find the proper param
            _lookBackPerid = 0;
            _bandWidth = 2;
            _lastAveValue = 0;
            _lastVarAveValue = 0;
            _valueVec = new Queue<decimal>();
            _dataLength = 0;
            _signalVecLength = 6;
            _bollingerBandWidthAbsTrigger = 5 / 2500m;
            if (_inputParam != null)
                GetParam();
            _varAdj = _lookBackPerid / (_lookBackPerid - 1.0m);
            
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
                _lookBackPerid = Convert.ToInt32(_inputParam["lookbackperiod"].ToString());
            }
            if (_inputParam.ContainsKey("bandwidth"))
            {
                _bandWidth = Convert.ToDecimal(_inputParam["bandwidth"].ToString());
            }
            _alpha = 1.0m / (_lookBackPerid);
            if (_inputParam.ContainsKey("alpha"))
            {
                _alpha = Convert.ToDecimal(_inputParam["alpha"].ToString());
                if (_alpha == -10000)
                {
                    _alpha = 1.0m / (_lookBackPerid);
                }
            }
            if (_inputParam.ContainsKey("lastavevalue"))
            {
                _lastAveValue = Convert.ToDecimal(_inputParam["lastavevalue"].ToString());
            }
            if (_inputParam.ContainsKey("_lastvaravevalue"))
            {
                _lastVarAveValue = Convert.ToDecimal(_inputParam["_lastvaravevalue"].ToString());
            }
            _minmumSignalLength = _lookBackPerid;
            if (_inputParam.ContainsKey("minmumsignallength"))
            {
                _minmumSignalLength = Convert.ToInt32(_inputParam["minmumsignallength"].ToString());
            }
            if (_inputParam.ContainsKey("bollingerbandwidthabstrigger"))
            {
                _bollingerBandWidthAbsTrigger = Convert.ToDecimal(_inputParam["bollingerbandwidthabstrigger"].ToString());
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
            _currentValue = value;
            Int32 _elementCount = _valueVec.Count;
            Decimal _lastElement = value;
            if (_elementCount > 0)
            {
                _lastElement = _valueVec.ElementAt(0);
            }
            _valueVec.Enqueue(value);
            _elementCount++;
            if (_elementCount > _lookBackPerid)
            {
                _valueVec.Dequeue();
            }
            _dataLength++;
            if (_dataLength <= _minmumSignalLength)
            {
                _currentAveValue = 0m;
                foreach (Decimal vTmp in _valueVec)
                {
                    _currentAveValue += vTmp;
                }
                _currentAveValue /= _valueVec.Count;
                _lastAveValue = _currentAveValue;

                _currentVarAveValue = 0m;
                foreach (Decimal vTmp in _valueVec)
                {
                    _currentVarAveValue += vTmp * vTmp;
                }
                _currentVarAveValue /= _valueVec.Count;
                _lastVarAveValue = _currentVarAveValue;
                _currentStdAveValue = _currentVarAveValue - _currentAveValue * _currentAveValue;
                if (_valueVec.Count > 1)
                    _currentStdAveValue *= _valueVec.Count / (_valueVec.Count - 1);
                _currentStdAveValue = Math.Abs(_currentStdAveValue);
                _currentStdAveValue = (Decimal)Math.Sqrt((Double)_currentStdAveValue);
            }
            else
            {
                _currentAveValue = _alpha * (value - _lastElement) + _lastAveValue;
                _lastAveValue = _currentAveValue;

                _currentVarAveValue = _alpha * (value * value - _lastElement * _lastElement) + _lastVarAveValue;
                _lastVarAveValue = _currentVarAveValue;

                _currentStdAveValue = _currentVarAveValue - _currentAveValue * _currentAveValue;
                _currentStdAveValue *= _varAdj;
                _currentStdAveValue = Math.Abs(_currentStdAveValue);
                _currentStdAveValue = (Decimal)Math.Sqrt((Double)_currentStdAveValue);
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
        /// <summary>
        /// Signal value output
        /// </summary>
        public override Decimal GetSignal()
        {
            return _currentAveValue;
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
            signalVecValue[0] = _currentAveValue;
            signalVecValue[2] = _currentAveValue - _bandWidth * _currentStdAveValue;
            signalVecValue[3] = _currentAveValue + _bandWidth * _currentStdAveValue;
            Boolean isLong = (_spotValue < signalVecValue[2]);
            Boolean isShort = (_spotValue > signalVecValue[3]);
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
            if (_currentStdAveValue / _currentValue <= _bollingerBandWidthAbsTrigger)
            {
                signalVecValue[1] = 0;
            }
            if (_dataLength < _minmumSignalLength)
            {
                signalVecValue[1] = 0;
            }
            signalVecValue[4] = signalVecValue[1];
            signalVecValue[5] = _currentStdAveValue;
            
        }
        //[XmlIgnore]
        //public Queue<Decimal> _valueVec;
        public Int32 _lookBackPerid;
        public Decimal _alpha;
        public Decimal _currentValue;
        public Decimal _lastAveValue;
        public Decimal _currentAveValue;
        public Decimal _lastVarAveValue;
        public Decimal _currentVarAveValue;
        public Decimal _currentStdAveValue;
        public Decimal _bandWidth;
        public Decimal _varAdj;
        public Decimal _bollingerBandWidthAbsTrigger;
    }
}
