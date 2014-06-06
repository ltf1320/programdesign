using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Xml;
using System.Xml.Serialization;
//using TradeLink.CommonATS;
using System.Collections;

namespace ATSGlobalIndicator
{
    [Serializable]
    public class Composite : GenericIndicatorTemplate
    {
        /// <summary>
        /// Initializatin
        /// </summary>
        public override void Initializatin()
        {
            _dataLength = 0;
            Name = GetType().Name.ToLower();
            if (_inputParam != null)
                GetParam();
                
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
        /// Indicator vector update
        /// </summary>
        public override void UpdateIndicator(GenericIndicatorTemplate gInd)
        {
            _genericIndicatorVector.Add(gInd);
            _genericIndicatorVectorLength = _genericIndicatorVector.Count;
        }
        /// <summary>
        /// Indicator value update, vector value input
        /// </summary>
        public override void UpdateValue(ref Decimal[] valueVec)
        {
            foreach (GenericIndicatorTemplate gi in _genericIndicatorVector)
            {
                gi.UpdateValue(ref valueVec);
            }
            Decimal[] valueVecCopy =(Decimal[]) valueVec.Clone();
            _valueMatrix.Enqueue(valueVecCopy);
            _dataLength++;
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
            Decimal sigValSum = 0;
            for (Int32 i = 0; i < _genericIndicatorVectorLength; i++)
            {
                sigValSum += _genericIndicatorVectorWeight[i] * _genericIndicatorVector[i].GetSignal();
            }
            signalVecValue[0] = sigValSum;
        }

        [XmlIgnore]
        public Queue<Decimal[]> _valueMatrix;        
        [XmlIgnore]
        public List<GenericIndicatorTemplate> _genericIndicatorVector;
        public Int32 _lookBackPeriod;
        public List<Decimal> _genericIndicatorVectorWeight;
        public Int32 _genericIndicatorVectorLength;
    }
}
