using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Xml;
using System.Xml.Serialization;

namespace ATSGlobalIndicator
{
    [Serializable]
    public class SuperEightVector : GenericIndicatorTemplate
    {
        public SuperEightVector()
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
            _myIndVector = new List<SuperEight>();
            _valueMatrix = new Queue<decimal[]>();
            if (_lengthPerItem > 0)
            {
                _vecLength = _lookBackPeriod / _lengthPerItem;
                for (Int32 i = 0; i < _vecLength; i++)
                {
                    Hashtable SuperEightInputParamTmp = new Hashtable();
                    SuperEightInputParamTmp["lookbackperiod"] = _lengthPerItem;
                    SuperEightInputParamTmp["period"] = _period;
                    SuperEightInputParamTmp["minmumsignallength"] = _lengthPerItem;
                    SuperEight mySuperEightLocal = new SuperEight();
                    mySuperEightLocal.Param = SuperEightInputParamTmp;
                    mySuperEightLocal.Initializatin();
                    _myIndVector.Add(mySuperEightLocal);
                    if (i == 0)
                    {
                        _signalVecValueLocalLength = mySuperEightLocal.GetSignalVecLengthLocal();
                        _signalVecValueLocal = new Decimal[_signalVecValueLocalLength]; 
                    }
                }
                _signalVecLength = _signalVecValueLocalLength * _vecLength;
            }
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
            if (_inputParam.ContainsKey("lengthperitem"))
            {
                _lengthPerItem = Convert.ToInt32(_inputParam["lengthperitem"].ToString());
            }

            _minmumSignalLength = _lookBackPeriod;
            if (_inputParam.ContainsKey("minmumsignallength"))
            {
                _minmumSignalLength = Convert.ToInt32(_inputParam["minmumsignallength"].ToString());
            }
        }

        public override void UpdateValue(ref Decimal[] valueVec, int period)
        {
            if (period == Period)
            {
                UpdateValue(ref valueVec);
            }
        }

        public override void UpdateValue(ref Decimal[] valueVec)
        {
            Decimal[] valueVecCopy = (Decimal[])valueVec.Clone();
            _valueMatrix.Enqueue(valueVecCopy);
            _dataLength++;
            if (_valueMatrix.Count > _lookBackPeriod)
            {
                _valueMatrix.Dequeue();
            }
            if (_valueMatrix.Count == _lookBackPeriod)
            {
                if (_dataLength > _lookBackPeriod)
                {
                    for (Int32 i = 0; i < _myIndVector.Count; i++)
                    {
                        Int32 iValue = (i+1) * _lengthPerItem - 1;
                        Decimal[] tmpValue = _valueMatrix.ElementAt(iValue);
                        _myIndVector[i].UpdateValue(ref tmpValue);
                    }
                }
                else
                {
                    for (Int32 i = 0; i < _myIndVector.Count; i++)
                    {
                        for (Int32 j = 0; j < _lengthPerItem; j++)
                        {
                            Int32 iValue = (i) * _lengthPerItem +j;
                            Decimal[] tmpValue = _valueMatrix.ElementAt(iValue);
                            _myIndVector[i].UpdateValue(ref tmpValue);
                        }
                    }
                }
            }
        }

        public override void GetSignalVec(ref Decimal[] signalVecValue)
        {
            if (_dataLength <= _minmumSignalLength)
            {
                for (Int32 i = 0; i < GetSignalVecLength(); i++)
                {
                    signalVecValue[i] = Decimal.MinValue;
                }
                return;
            }
            for (Int32 i = 0; i < _myIndVector.Count; i++)
            {
                _myIndVector[i].GetSignalVec(ref _signalVecValueLocal);
                for (Int32 j = 0; j < _signalVecValueLocalLength; j++)
                {
                    Int32 ll = i * _signalVecValueLocalLength + j;
                    signalVecValue[ll] = _signalVecValueLocal[j];
                }
            }
        }

        public Int32 _lookBackPeriod;
        public Int32 _lengthPerItem;
        public Int32 _vecLength;
        public Queue<Decimal[]> _valueMatrix;
        public List<SuperEight> _myIndVector;
        Decimal[] _signalVecValueLocal;
        public Int32 _signalVecValueLocalLength;
    }
}
