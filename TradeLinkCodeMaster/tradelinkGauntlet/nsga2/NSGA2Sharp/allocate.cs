using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NSGA2Sharp
{
    public partial class NSGA2
    {
        void allocate_memory_pop(ref population pop, int size)
        {
            int i;
            pop.ind = new List<individual>();
            for (i = 0; i < size; i++)
            {
                individual anInd = new individual();
                allocate_memory_ind(ref anInd);
                pop.ind.Add(anInd);
            }
            return;
        }
        void allocate_memory_ind(ref individual ind)
        {
            int j,k;
            if (nreal != 0)
            {
                ind.xreal = new List<double>();
                for (j = 0; j < nreal; j++) ind.xreal.Add(0.0);
            }
            if (nbin != 0)
            {
                ind.xbin = new List<double>();
                ind.gene = new List<List<double>>();
                for (j = 0; j < nbin; j++)
                {
                    ind.xbin.Add(0.0);
                    ind.gene[j] = new List<double>();
                    for (k = 0; k < nbits[j]; k++) ind.gene[j].Add(0.0);
                }
            }
            ind.obj = new List<double>();
            for (j = 0; j < nobj; j++) ind.obj.Add(0);
            if (ncon != 0)
            {
                ind.constr = new List<double>();
                for (j = 0; j < ncon; j++) ind.constr.Add(0);
            }
            return;
        }
    }
}
