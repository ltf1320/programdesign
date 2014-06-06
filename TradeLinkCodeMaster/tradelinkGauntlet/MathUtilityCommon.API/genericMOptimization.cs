using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Data;
using System.Threading;
using System.ComponentModel;

namespace MathUtilityCommon.API
{
    public interface genericMOptimization
    {
        Ndimensional_fvec EvluationFunction{ get; set; }
        Ndimensional_fvec ConstrainFunction{ get; set; }
        BackgroundWorker BatchWorker{ get; set; }
        Hashtable Param { get; set; }
        void LoadParamFromFile(String inputFilePath);

        void Initialization();

        Int32 DoOptimization();

        void OutputSolutions(ref DataTable solMap);

        void TestRun(Hashtable testRunInput);
    }
}
