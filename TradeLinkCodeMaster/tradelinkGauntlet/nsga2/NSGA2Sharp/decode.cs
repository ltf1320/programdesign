using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NSGA2Sharp
{
    public partial class NSGA2
    {
        /* Function to decode a population to find out the binary variable values based on its bit pattern */
        void decode_pop(ref population pop)
        {
            int i;
            if (nbin != 0)
            {
                for (i = 0; i < popsize; i++)
                {
                    individual individualLocal = pop.ind[i];
                    decode_ind(ref individualLocal);
                }
            }
            return;
        }

        /* Function to decode an individual to find out the binary variable values based on its bit pattern */
        void decode_ind(ref individual ind)
        {
            int j, k;
            int sum;
            if (nbin != 0)
            {
                for (j = 0; j < nbin; j++)
                {
                    sum = 0;
                    for (k = 0; k < nbits[j]; k++)
                    {
                        if (ind.gene[j][k] == 1)
                        {
                            sum += (int)Math.Pow(2, nbits[j] - 1 - k);
                        }
                    }
                    ind.xbin[j] = min_binvar[j] + (double)sum * (max_binvar[j] - min_binvar[j]) / (Math.Pow(2, nbits[j]) - 1);
                }
            }
            return;
        }

    }
}
