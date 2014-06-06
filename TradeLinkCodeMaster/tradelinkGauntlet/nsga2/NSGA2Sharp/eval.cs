using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NSGA2Sharp
{
    public partial class NSGA2
    {

        /* Routine to evaluate objective function values and constraints for a population */
        void evaluate_pop(ref population pop)
        {
            int i;
            for (i = 0; i < popsize; i++)
            {
                individual individualLocal = pop.ind[i];
                evaluate_ind(ref individualLocal);
            }
            return;
        }

        /* Routine to evaluate objective function values and constraints for an individual */
        void evaluate_ind(ref individual ind)
        {
            int j;
            _evalFunc(ind.xreal, ind.xbin, ind.gene, ref ind.obj, ref ind.constr);
            if (ncon == 0)
            {
                ind.constr_violation = 0.0;
            }
            else
            {
                ind.constr_violation = 0.0;
                for (j = 0; j < ncon; j++)
                {
                    if (ind.constr[j] < 0.0)
                    {
                        ind.constr_violation += ind.constr[j];
                    }
                }
            }
            return;
        }

    }
}
