using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NSGA2Sharp
{
    public partial class NSGA2
    {

        /* Routine to merge two populations into one */
        void merge(ref population pop1, ref population pop2, ref population pop3)
        {
            int i, k;
            for (i = 0; i < popsize; i++)
            {
                individual individualA = pop1.ind[i];
                individual individualB = pop3.ind[i];
                copy_ind(ref individualA, ref individualB);
            }
            for (i = 0, k = popsize; i < popsize; i++, k++)
            {
                individual individualA = pop2.ind[i];
                individual individualB = pop3.ind[k];
                copy_ind(ref individualA, ref individualB);
            }
            return;
        }

        /* Routine to copy an individual 'ind1' into another individual 'ind2' */
        void copy_ind(ref individual ind1, ref individual ind2)
        {
            int i, j;
            ind2.rank = ind1.rank;
            ind2.constr_violation = ind1.constr_violation;
            ind2.crowd_dist = ind1.crowd_dist;
            if (nreal != 0)
            {
                for (i = 0; i < nreal; i++)
                {
                    ind2.xreal[i] = ind1.xreal[i];
                }
            }
            if (nbin != 0)
            {
                for (i = 0; i < nbin; i++)
                {
                    ind2.xbin[i] = ind1.xbin[i];
                    for (j = 0; j < nbits[i]; j++)
                    {
                        ind2.gene[i][j] = ind1.gene[i][j];
                    }
                }
            }
            for (i = 0; i < nobj; i++)
            {
                ind2.obj[i] = ind1.obj[i];
            }
            if (ncon != 0)
            {
                for (i = 0; i < ncon; i++)
                {
                    ind2.constr[i] = ind1.constr[i];
                }
            }
            return;
        }

    }
}
