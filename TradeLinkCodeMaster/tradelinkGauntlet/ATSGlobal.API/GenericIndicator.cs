using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Collections;

namespace ATSGlobal.API
{
    public interface GenericIndicator
    {
        /// <summary>
        /// Input param
        /// </summary>
        Hashtable Param { get; set; }

        /// <summary>
        /// Initializatin
        /// </summary>
        void Initializatin();

        /// <summary>
        /// Indicator value update, single value input
        /// </summary>
        void UpdateValue(Decimal value);

        /// <summary>
        /// Indicator value update, vector value input
        /// </summary>
        void UpdateValue(ref Decimal[] valueVec);

        /// <summary>
        /// Signal value output
        /// </summary>
        Decimal GetSignal();

        /// <summary>
        /// Open signal value output
        /// </summary>
        Decimal GetOpenSignal();

        /// <summary>
        /// close signal value output
        /// </summary>
        Decimal GetCloseSignal();

        /// <summary>
        /// Signal vector value output
        /// </summary>
        void GetSignalVec(ref Decimal[] signalVecValue);

        /// <summary>
        /// Serialization
        /// </summary>
        String ToString();

        /// <summary>
        /// Dserialization
        /// </summary>
        void FromString(String sInput);

        /// <summary>
        /// Reset indicator
        /// </summary>
        void Reset();
        // GenericIndicator Information
        Boolean isValid { get; set; }
        String Name { get; set; }
        Int32 ID { get; set; }
    }
}
