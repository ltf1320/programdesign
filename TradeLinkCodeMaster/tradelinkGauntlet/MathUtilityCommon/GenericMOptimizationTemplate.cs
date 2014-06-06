using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using MathUtilityCommon.API;
using System.Data;
using System.ComponentModel;

namespace MathUtilityCommon
{
    public class GenericMOptimizationTemplate : genericMOptimization
    {
        public virtual Ndimensional_fvec EvluationFunction
            { get { return _funtionToOpt; } set {_funtionToOpt = value; } }
        public virtual Ndimensional_fvec ConstrainFunction
            { get { return _funtionToCalConstrains; } set { _funtionToCalConstrains = value; } }
        public virtual BackgroundWorker BatchWorker
            { get { return _worker; } set { _worker = value; } }
        public virtual Hashtable Param
            { get { return _paramTable; } set { _paramTable = value; } }
        public virtual void LoadParamFromFile(String inputFilePath)
        {
        }
        
        public virtual void Initialization()
        {
        }

        public virtual Int32 DoOptimization()
        {
            return Int32.MinValue;
        }

        public virtual void OutputSolutions(ref DataTable solMap)
        {
        }

        public virtual void TestRun(Hashtable testRunInput)
        {
        }

        protected BackgroundWorker _worker = null;
        protected Ndimensional_fvec _funtionToOpt = null;
        protected Ndimensional_fvec _funtionToCalConstrains = null;
        protected Hashtable _paramTable = null;
    }
}
