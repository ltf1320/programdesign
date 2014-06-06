using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Data;
using System.Collections;
using ATSGlobal.API;
using System.Xml;
using System.Xml.Serialization;
using CommonUtilityAlbert;

namespace ATSGlobalIndicator
{
    [XmlInclude(typeof(MACD))]
    [XmlInclude(typeof(RSI))]
    [XmlInclude(typeof(KDJ))]
    [XmlInclude(typeof(CCI))]
    [XmlInclude(typeof(BIAS))]
    [XmlInclude(typeof(EMA))]
    [XmlInclude(typeof(SMA))]
    [XmlInclude(typeof(HighLow))]
    [XmlInclude(typeof(SuperEight))]
    [XmlInclude(typeof(Composite))]
    [XmlInclude(typeof(CompositeSVM))]
    [Serializable]
    public class GenericIndicatorTemplate : GenericIndicator
    {
        
        public GenericIndicatorTemplate()
        {
            _turningPointValueTol = Decimal.MinValue;
        }
        /// <summary>
        /// Input param
        /// </summary>
        [XmlIgnore]
        public virtual Hashtable Param { get { return _inputParam; } set { paramCopy(value); } }
        public String _inputParamXML;

        public void preSerialization()
        {

            // in public already
            _inputParamXML = SerializationUtil.SerializeHashtable(_inputParam);
            
        }
        public string SerializeXML()
        {
            preSerialization();
            String mySerialziedGenericIndicatorTemplate = SerializationUtil.SerializeObject<GenericIndicatorTemplate>(this);
            return mySerialziedGenericIndicatorTemplate;
        }
        public void postDeSerialization()
        {
            // in public already
            _inputParam = SerializationUtil.DeserializeHashtable(_inputParamXML);
            
        }
        public void DeserializeXML(string msg)
        {
            GenericIndicatorTemplate myCopy = SerializationUtil.DeserializeObject<GenericIndicatorTemplate>(msg);
            CopyRelated.CopyTo(myCopy, this);
            postDeSerialization();
        }  
        /// <summary>
        /// Initializatin
        /// </summary>
        public virtual void Initializatin()
        {
            Name = GetType().Name.ToLower();
            if (_inputParam != null)
                GetParam();
            _signalVecLength = 8;
        }
        /// <summary>
        /// Getting parameter from input
        /// </summary>
        public virtual void GetParam()
        {
            if (_inputParam.ContainsKey("name"))
            {
                Name = _inputParam["name"].ToString();
            }
        }
        /// <summary>
        /// Indicator vector update
        /// </summary>
        public virtual void UpdateIndicator(GenericIndicatorTemplate gInd)
        {
        }
        /// <summary>
        /// Indicator vector update
        /// </summary>
        public virtual void UpdateIndicator(GenericIndicatorTemplate gInd, Int32 numTickPerBar)
        {
        } 
        /// <summary>
        /// Indicator value update, single value input
        /// </summary>
        public virtual void UpdateValue(Decimal value)
        {
        }
        /// <summary>
        /// Indicator value update, single value input
        /// </summary>
        public virtual void UpdateValue(Decimal value, int period)
        {
        }    
        /// <summary>
        /// Indicator value update, vector value input
        /// </summary>
        public virtual void UpdateValue(ref Decimal[] valueVec)
        {
            UpdateValue(valueVec[0]);
            _spotValue = valueVec[3];
        }
        /// <summary>
        /// Indicator value update, vector value input, period input
        /// </summary>
        public virtual void UpdateValue(ref Decimal[] valueVec, int period)
        {
                UpdateValue(valueVec[0], period);
                _spotValue = valueVec[3];
        }
        /// <summary>
        /// Signal value output
        /// </summary>
        public virtual Decimal GetSignal()
        {
            Decimal value = Decimal.MaxValue;
            return value;
        }
        /// <summary>
        /// Open signal value output
        /// </summary>
        public virtual Decimal GetOpenSignal()
        {
            Decimal value = Decimal.MaxValue;
            return value;
        }
        /// <summary>
        /// close signal value output
        /// </summary>
        public virtual Decimal GetCloseSignal()
        {
            Decimal value = Decimal.MaxValue;
            return value;
        }
        /// <summary>
        /// Signal vector value output
        /// </summary>
        public virtual void GetSignalVec(ref Decimal[] signalVecValue)
        {
            if (_dataLength <= (Int64)(_minmumSignalLength))
            {
                for (Int32 i = 0; i < GetSignalVecLength(); i++)
                {
                    signalVecValue[i] = Decimal.MinValue;
                }
                return;
            }
            signalVecValue[0] = _signalValue;
            Boolean isLong = (_signalValue > _signalValueLocalMin && inLowerBand)
               || (inUpperBand && _signalValue >= _signalValueLocalMax);
            Boolean isShort = (_signalValue <= _signalValueLocalMin && inLowerBand)
                || (inUpperBand && _signalValue < _signalValueLocalMax);
            if (isLong)
            {
                signalVecValue[1] = 1;
            }
            else if (isShort)
            {
                signalVecValue[1] = -1;
            }
            else if(_signalValueLocalMax!=0)
            {
                signalVecValue[1] = 1;
            }
            else if (_signalValueLocalMin!=0)
            {
                signalVecValue[1] = -1;
            }else 
            {
                signalVecValue[1] = 0;
            }
            signalVecValue[2] = _signalValueLocalMin;
            signalVecValue[3] = _signalValueLocalMax;
            signalVecValue[4] = _turningPointValue;
        }
        /// <summary>
        /// signal output data length
        /// </summary>
        public virtual Int32 GetSignalVecLength()
        {
            return 8;
        }
        public virtual Int32 GetSignalVecLengthLocal()
        {
            return _signalVecLength;
        }
        /// <summary>
        /// Signal local min and max calculation, turning point calculation
        /// </summary>
        public virtual void updateLocalMaxMin()
        {
            if (_calcTurningPoint)
            {
                if (_isLocalMax)
                {
                    if ((_signalValue < _signalValueLocalMax) && (Math.Abs((_valueVec.ElementAt(1) - _valueVec.ElementAt(0)) / _valueVec.ElementAt(0)) > _turningPointValueTol))
                    {
                        _turningPointValue = -1;
                    }
                    else
                    {
                        _turningPointValue = 0;
                    }
                }
                else if (_isLocalMin)
                {
                    if ((_signalValue > _signalValueLocalMin) && (Math.Abs((_valueVec.ElementAt(1) - _valueVec.ElementAt(0)) / _valueVec.ElementAt(0)) > _turningPointValueTol))
                    {
                        _turningPointValue = 1;
                    }
                    else
                    {
                        _turningPointValue = 0;
                    }
                }
                else
                {
                    _turningPointValue = 0;
                }
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
        /// Dserialization
        /// </summary>
        public virtual void FromString(String sInput)
        {
            // to reconstruct the indicatior from serialization value
        }    
        /// <summary>
        /// Reset indicator
        /// </summary>
        public virtual void Reset()
        {
        }        
        /// <summary>
        /// Numeric tag for this genericIndicator used by programs that load genericIndicator
        /// </summary>
        public Int32 ID { get { return _id; } set { _id = value; } }
        /// <summary>
        /// Whether genericIndicator can be used or not
        /// </summary>
        public Boolean isValid { get { return _valid; } set { _valid = value; } }      
        /// <summary>
        /// Custom name of genericIndicator set by you
        /// </summary>
        public String Name { get { return _name; } set { _name = value; } }
        /// <summary>
        /// Period length in term of number of ticks
        /// </summary>
        public Int32 Period { get { return _period; } set { _period = value; } }
        /// <summary>
        /// Minmum Signal Length
        /// </summary>
        public Int32 MinmumSignalLength { get { return _minmumSignalLength; } set { _minmumSignalLength = value; } }
        /// <summary>
        /// Whether data is after the  MinmumSignalLength
        /// </summary>
        public Boolean isLengthValid { get {return _dataLength > (Int64)(_minmumSignalLength);} } 
        /// <summary>
        /// Internal private parameter and functions  
        /// </summary>
        private void paramCopy(Hashtable htInput)
        {
            _inputParam =(Hashtable) htInput.Clone();
        }
        [XmlIgnore]
        public Hashtable _inputParam = null;
        public String _name = "";
        public Boolean _valid = true;
        public Int32 _id = UNKNOWNINDICATOR;
        public const Int32 UNKNOWNINDICATOR = Int32.MaxValue;
        public Boolean inUpperBand;
        public Boolean inLowerBand;
        public Decimal _signalValueLocalMax;
        public Decimal _signalValueLocalMin;
        public Decimal _signalValue;
        public Decimal _spotValue;
        public Decimal _lowerBandDownLimit;
        public Decimal _lowerBandUpLimit;
        public Decimal _upperBandDownLimit;
        public Decimal _upperBandUpLimit;
        public Boolean _calcTurningPoint;
        public Boolean _isLocalMax;
        public Boolean _isLocalMin;
        public Decimal _turningPointValue;
        public Int32 _period = 1;
        public Int32 _minmumSignalLength;
        public Int64 _dataLength;
        public Int32 _signalVecLength;        
        public Decimal _turningPointValueTol;

        // To be serialized
        [XmlIgnore]
        public Queue<Decimal> _valueVec = null; 
    }
}
