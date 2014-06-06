using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NSGA2Sharp
{
    public partial class NSGA2
    {

        /* Function to initialize a population randomly */
        void initialize_pop(ref population pop)
        {
            int i;
            for (i = 0; i < popsize; i++)
            {
                individual individualA = pop.ind[i];
                initialize_ind(ref individualA);
            }
            return;
        }

        /* Function to initialize an individual randomly */
        void initialize_ind(ref individual ind)
        {
            int j, k;
            if (nreal != 0)
            {
                for (j = 0; j < nreal; j++)
                {
                    ind.xreal[j]= rndreal(min_realvar[j], max_realvar[j]);
                }
            }
            if (nbin != 0)
            {
                for (j = 0; j < nbin; j++)
                {
                    for (k = 0; k < nbits[j]; k++)
                    {
                        if (randomperc() <= 0.5)
                        {
                            ind.gene[j][k] = 0;
                        }
                        else
                        {
                            ind.gene[j][k] = 1;
                        }
                    }
                }
            }
            return;
        }
    }
}
