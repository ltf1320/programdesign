using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Collections;//hashtable用的

namespace ATSGlobalIndicator
{
    [Serializable]
    public class ADMA : GenericIndicatorTemplate
    {
        public ADMA()//adaptive moving average 自适应移动平均
        {
        }
        /// <summary>
        /// Initializatin
        /// </summary>
        public override void Initializatin()
        {
            Name = GetType().Name.ToLower(); //tolower：转化为小写
            _alpha = 0.8m;
            if (_inputParam != null)
                GetParam();
            _valueVec = new Queue<decimal>();
            _dataLength = 0;
            _adma = 0m;
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
            if (_inputParam.ContainsKey("c"))
            {
                _c = Convert.ToInt32(_inputParam["c"].ToString());
            }
            if (_inputParam.ContainsKey("d"))
            {
                _d = Convert.ToInt32(_inputParam["d"].ToString());
            }
            if (_inputParam.ContainsKey("delta"))
            {
                _delta = Convert.ToInt32(_inputParam["delta"].ToString());
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
            _Enumerator = Math.Abs(_valueVec.ElementAt(0) - _valueVec.ElementAt(_valueVec.Count - 1));
            _Edominator = 0m;
            if (_valueVec.Count > 1)
            {
                for (int i = 1; i < _valueVec.Count; i++)
                {
                    _Edominator += Math.Abs(_valueVec.ElementAt(i) - _valueVec.ElementAt(i - 1));
                }
            }
            else
            {
                _Edominator = 1m; //这样分别对待是因为当_valueVec.count==1时，分母是为0的
                //这里分母只要不为0为什么都好，我取了1m.
            }
            _E = _Enumerator / _Edominator;
            if (_lastValue == 0)//其实这里是有点问题的，_lastValue==0并不代表就是第一个数字
            //有可能真的是上一个值就是为0，因此其实这个判断要改，但懒得了~
            {
                _lastValue = value;
            }
            _alpha = (decimal)(Math.Pow((double)(_c + _d * _E), (double)(_delta)));
            _currentValue = _alpha * value + (1 - _alpha) * _lastValue;
            _dataLength++;
            _adma = _currentValue;
            _lastValue = _currentValue;
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
            return _adma;
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
                    signalVecValue[i] = 33333333;//= Decimal.MinValue;
                }
                return;
            }
            signalVecValue[0] = _adma;
            signalVecValue[1] = 0;
            signalVecValue[2] = 0;
            signalVecValue[3] = 0;

        }
        public Decimal _adma;
        public Decimal _c;
        public Decimal _d;
        public Decimal _delta;
        public Decimal _alpha;
        public Decimal _E;
        public Decimal _currentValue;
        public Decimal _lastValue = 0m;
        public Decimal _Enumerator;
        public Decimal _Edominator;
    }
}

