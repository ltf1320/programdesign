﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NSGA2Sharp
{
    public partial class NSGA2
    {

        /* Function to perform mutation in a population */
        void mutation_pop(ref population pop)
        {
            int i;
            for (i = 0; i < popsize; i++)
            {
                individual individualA = pop.ind[i];
                mutation_ind(ref individualA);
            }
            return;
        }

        /* Function to perform mutation of an individual */
        void mutation_ind(ref individual ind)
        {
            if (nreal != 0)
            {
                real_mutate_ind(ref ind);
            }
            if (nbin != 0)
            {
                bin_mutate_ind(ref ind);
            }
            return;
        }

        /* Routine for binary mutation of an individual */
        void bin_mutate_ind(ref individual ind)
        {
            int j, k;
            double prob;
            for (j = 0; j < nbin; j++)
            {
                for (k = 0; k < nbits[j]; k++)
                {
                    prob = randomperc();
                    if (prob <= pmut_bin)
                    {
                        if (ind.gene[j][k] == 0)
                        {
                            ind.gene[j][k] = 1;
                        }
                        else
                        {
                            ind.gene[j][k] = 0;
                        }
                        nbinmut += 1;
                    }
                }
            }
            return;
        }

        /* Routine for real polynomial mutation of an individual */
        void real_mutate_ind(ref individual ind)
        {
            int j;
            double rnd, delta1, delta2, mut_pow, deltaq;
            double y, yl, yu, val, xy;
            for (j = 0; j < nreal; j++)
            {
                if (randomperc() <= pmut_real)
                {
                    y = ind.xreal[j];
                    yl = min_realvar[j];
                    yu = max_realvar[j];
                    delta1 = (y - yl) / (yu - yl);
                    delta2 = (yu - y) / (yu - yl);
                    rnd = randomperc();
                    mut_pow = 1.0 / (eta_m + 1.0);
                    if (rnd <= 0.5)
                    {
                        xy = 1.0 - delta1;
                        val = 2.0 * rnd + (1.0 - 2.0 * rnd) * (Math.Pow(xy, (eta_m + 1.0)));
                        deltaq = Math.Pow(val, mut_pow) - 1.0;
                    }
                    else
                    {
                        xy = 1.0 - delta2;
                        val = 2.0 * (1.0 - rnd) + 2.0 * (rnd - 0.5) * (Math.Pow(xy, (eta_m + 1.0)));
                        deltaq = 1.0 - (Math.Pow(val, mut_pow));
                    }
                    y = y + deltaq * (yu - yl);
                    if (y < yl)
                        y = yl;
                    if (y > yu)
                        y = yu;
                    ind.xreal[j] = y;
                    nrealmut += 1;
                }
            }
            return;
        }
    }
}
