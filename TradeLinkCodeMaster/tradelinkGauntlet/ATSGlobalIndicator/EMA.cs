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
    public class EMA : GenericIndicatorTemplate
    {
        public EMA()
        {
        }
        /// <summary>
        /// Initializatin
        /// </summary>
        public override void Initializatin()
        {
            Name = GetType().Name.ToLower();
            _lookBackPerid = 0;
            _alpha = 0;            
            _lastEMAValue = 0;
            if (_inputParam != null)
                GetParam();
            _valueVec = new Queue<decimal>();
            _dataLength = 0;
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
            if (_inputParam.ContainsKey("alpha"))
            {
                _alpha = Convert.ToDecimal(_inputParam["alpha"].ToString());
                if (_alpha == -10000)
                {
                    _alpha = 2.0m / (_lookBackPerid + 1m);
                }
                _oneMinusAlpha = 1 - _alpha;
            }
            if (_inputParam.ContainsKey("name"))
            {
                Name = _inputParam["name"].ToString();
            }
            if (_inputParam.ContainsKey("lastema"))
            {
                _lastEMAValue = Convert.ToDecimal(_inputParam["lastema"].ToString());
            }
            _minmumSignalLength = _lookBackPerid;
            if (_inputParam.ContainsKey("minmumsignallength"))
            {
                _minmumSignalLength = Convert.ToInt32(_inputParam["minmumsignallength"].ToString());
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
            if (_minmumSignalLength == 0)
            {
                if (_lastEMAValue == 0)
                {
                    _lastEMAValue = value;
                }
                _currentEMAValue = _alpha * value + _oneMinusAlpha * _lastEMAValue;
                _lastEMAValue = _currentEMAValue;
            }
            else
            {
                if (_dataLength < _minmumSignalLength)
                {
                    _valueVec.Enqueue(value);
                    if (_valueVec.Count > _lookBackPerid)
                    {
                        _valueVec.Dequeue();
                    }
                    _dataLength++;
                    _currentEMAValue = 0m;
                    foreach (Decimal vTmp in _valueVec)
                    {
                        _currentEMAValue += vTmp;
                    }
                    _currentEMAValue /= _valueVec.Count;
                    _lastEMAValue = _currentEMAValue;
                }
                else
                {
                    _currentEMAValue = _alpha * value + _oneMinusAlpha * _lastEMAValue;
                    _lastEMAValue = _currentEMAValue;
                }
                
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
            return _currentEMAValue;
        }
        //[XmlIgnore]
        //public Queue<Decimal> _valueVec;
        public Int32 _lookBackPerid;
        public Decimal _alpha;
        public Decimal _oneMinusAlpha;
        public Decimal _lastEMAValue;
        public Decimal _currentEMAValue;

    }
}
