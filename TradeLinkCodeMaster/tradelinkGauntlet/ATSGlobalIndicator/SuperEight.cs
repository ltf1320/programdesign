using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Xml;
using System.Xml.Serialization;
//using TradeLink.CommonATS;

namespace ATSGlobalIndicator
{
    [Serializable]
    public class SuperEight : GenericIndicatorTemplate
    {
        public SuperEight()
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

            Hashtable myValueParam = new Hashtable();
            myValueParam["period"] = _period;
            myValueParam["lookbackperiod"] = _lookBackPeriod;
            myValueParam["minmumsignallength"] = _minmumSignalLength+1;
            _myValue = new SMA();
            _myValue.Param = myValueParam;
            _myValue.Initializatin();

            Hashtable myVolParam = new Hashtable();
            myVolParam["period"] = _period;
            myVolParam["lookbackperiod"] = _lookBackPeriod;
            myVolParam["minmumsignallength"] = _minmumSignalLength+1;
            _myVol = new SMA();
            _myVol.Param = myVolParam;
            _myVol.Initializatin();

            Hashtable myReturnParam = new Hashtable();
            myReturnParam["period"] = _period;
            myReturnParam["lookbackperiod"] = _lookBackPeriod;
            myReturnParam["minmumsignallength"] = _minmumSignalLength;
            myReturnParam["iscalcstd"] = "true";
            _myReturn = new SMA();
            _myReturn.Param = myReturnParam;
            _myReturn.Initializatin();

            Hashtable myHighLowParam = new Hashtable();
            myHighLowParam["period"] = _period;
            myHighLowParam["lookbackperiod"] = _lookBackPeriod;
            myHighLowParam["minmumsignallength"] = _minmumSignalLength+1;
            myHighLowParam["compitwithweinan"] = "true";            
            _myHighLow = new HighLow();
            _myHighLow.Param = myHighLowParam;
            _myHighLow.Initializatin();
            _signalVecLength = 8;
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
            _alpha = 1.0m / (_lookBackPeriod);
            if (_inputParam.ContainsKey("alpha"))
            {
                _alpha = Convert.ToDecimal(_inputParam["alpha"].ToString());
                if (_alpha == -10000)
                {
                    _alpha = 1.0m / (_lookBackPeriod);
                }
            }
            _minmumSignalLength = _lookBackPeriod;
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
        /// Indicator value update, vector value input, period input
        /// </summary>
        public override void UpdateValue(ref Decimal[] valueVec, int period)
        {
            if (period == Period)
            {
                UpdateValue(ref valueVec);
            }
        }
        /// <summary>
        /// Indicator value update, vector value input
        /// </summary>
        public override void UpdateValue(ref Decimal[] valueVec)
        {
            _myHighLow.UpdateValue(ref valueVec);
            _myValue.UpdateValue(valueVec[0]);
            _myVol.UpdateValue(valueVec[4]);
            Decimal currentReturn = 0m;
            if (_lastValue > 0)
            {
                //currentReturn = (valueVec[0] - _lastValue) / _lastValue;
                currentReturn = valueVec[0] - _lastValue;
                _myReturn.UpdateValue(currentReturn);
            }            
            _lastValue = valueVec[0];
            _dataLength++;
            
        }
        /// <summary>
        /// Indicator value update, vector value input, period input
        /// </summary>
        public override void UpdateValue(Decimal value, int period)
        {
            if (period == Period)
            {
                UpdateValue(value);
            }
        }
        /// <summary>
        /// Signal vector value output
        /// </summary>
        public override void GetSignalVec(ref Decimal[] signalVecValue)
        {
            if (_myValue._dataLength <= (long)(_minmumSignalLength+4))
            {
                for (Int32 i = 0; i < GetSignalVecLength(); i++)
                {
                    signalVecValue[i] = Decimal.MinValue;
                }
                return;
            }
            Decimal[] signalVecValueLocal = new Decimal[_myValue.GetSignalVecLength()];            
            _myValue.GetSignalVec(ref signalVecValueLocal);
            Decimal close = signalVecValueLocal[1];
            Decimal closeAve = signalVecValueLocal[0];
            _myVol.GetSignalVec(ref signalVecValueLocal);
            Decimal volClose = signalVecValueLocal[1];
            Decimal volCloseAve = signalVecValueLocal[0];
            _myReturn.GetSignalVec(ref signalVecValueLocal);
            Decimal returnCloseAve = signalVecValueLocal[0];
            Decimal returnCloseStd = signalVecValueLocal[2];
            _myHighLow.GetSignalVec(ref signalVecValueLocal);
            Decimal maxClose = signalVecValueLocal[3];
            Decimal minClose = signalVecValueLocal[2];

            signalVecValue[0] = close / closeAve;
            signalVecValue[1] = volClose / volCloseAve;
            //signalVecValue[2] = returnCloseAve;
            signalVecValue[2] = returnCloseAve * (decimal)_lookBackPeriod;
            signalVecValue[3] = returnCloseStd;
            signalVecValue[4] = maxClose / closeAve;
            signalVecValue[5] = minClose / closeAve;
            signalVecValue[6] = close;
            signalVecValue[7] = volClose;
        }
        
        public Int32 _lookBackPeriod;
        public Decimal _alpha;
        public HighLow _myHighLow;
        public SMA _myValue;
        public SMA _myVol;
        public SMA _myReturn;
        public Decimal _spotVol;
        public Decimal _lastValue;
    }
}
