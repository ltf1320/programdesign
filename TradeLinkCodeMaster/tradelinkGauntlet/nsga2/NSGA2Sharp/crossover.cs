using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NSGA2Sharp
{
    public partial class NSGA2
    {


        /* Function to cross two individuals */
        void crossover(ref individual parent1, ref individual parent2, ref individual child1, ref individual child2)
        {
            if (nreal != 0)
            {
                realcross(ref parent1, ref parent2, ref child1, ref child2);
            }
            if (nbin != 0)
            {
                bincross(ref parent1, ref parent2, ref child1, ref child2);
            }
            return;
        }

        /* Routine for real variable SBX crossover */
        void realcross(ref individual parent1, ref individual parent2, ref individual child1, ref individual child2)
        {
            int i;
            double rand;
            double y1, y2, yl, yu;
            double c1, c2;
            double alpha, beta, betaq;
            if (randomperc() <= pcross_real)
            {
                nrealcross++;
                for (i = 0; i < nreal; i++)
                {
                    if (randomperc() <= 0.5)
                    {
                        if (Math.Abs(parent1.xreal[i] - parent2.xreal[i]) > double.MinValue)
                        {
                            if (parent1.xreal[i] < parent2.xreal[i])
                            {
                                y1 = parent1.xreal[i];
                                y2 = parent2.xreal[i];
                            }
                            else
                            {
                                y1 = parent2.xreal[i];
                                y2 = parent1.xreal[i];
                            }
                            yl = min_realvar[i];
                            yu = max_realvar[i];
                            rand = randomperc();
                            beta = 1.0 + (2.0 * (y1 - yl) / (y2 - y1));
                            alpha = 2.0 - Math.Pow(beta, -(eta_c + 1.0));
                            if (rand <= (1.0 / alpha))
                            {
                                betaq = Math.Pow((rand * alpha), (1.0 / (eta_c + 1.0)));
                            }
                            else
                            {
                                betaq = Math.Pow((1.0 / (2.0 - rand * alpha)), (1.0 / (eta_c + 1.0)));
                            }
                            c1 = 0.5 * ((y1 + y2) - betaq * (y2 - y1));
                            beta = 1.0 + (2.0 * (yu - y2) / (y2 - y1));
                            alpha = 2.0 - Math.Pow(beta, -(eta_c + 1.0));
                            if (rand <= (1.0 / alpha))
                            {
                                betaq = Math.Pow((rand * alpha), (1.0 / (eta_c + 1.0)));
                            }
                            else
                            {
                                betaq = Math.Pow((1.0 / (2.0 - rand * alpha)), (1.0 / (eta_c + 1.0)));
                            }
                            c2 = 0.5 * ((y1 + y2) + betaq * (y2 - y1));
                            if (c1 < yl)
                                c1 = yl;
                            if (c2 < yl)
                                c2 = yl;
                            if (c1 > yu)
                                c1 = yu;
                            if (c2 > yu)
                                c2 = yu;
                            if (randomperc() <= 0.5)
                            {
                                child1.xreal[i] = c2;
                                child2.xreal[i] = c1;
                            }
                            else
                            {
                                child1.xreal[i] = c1;
                                child2.xreal[i] = c2;
                            }
                        }
                        else
                        {
                            child1.xreal[i] = parent1.xreal[i];
                            child2.xreal[i] = parent2.xreal[i];
                        }
                    }
                    else
                    {
                        child1.xreal[i] = parent1.xreal[i];
                        child2.xreal[i] = parent2.xreal[i];
                    }
                }
            }
            else
            {
                for (i = 0; i < nreal; i++)
                {
                    child1.xreal[i] = parent1.xreal[i];
                    child2.xreal[i] = parent2.xreal[i];
                }
            }
            return;
        }

        /* Routine for two point binary crossover */
        void bincross(ref individual parent1, ref  individual parent2, ref individual child1, ref individual child2)
        {
            int i, j;
            double rand;
            int temp, site1, site2;
            for (i = 0; i < nbin; i++)
            {
                rand = randomperc();
                if (rand <= pcross_bin)
                {
                    nbincross++;
                    site1 = rnd(0, nbits[i] - 1);
                    site2 = rnd(0, nbits[i] - 1);
                    if (site1 > site2)
                    {
                        temp = site1;
                        site1 = site2;
                        site2 = temp;
                    }
                    for (j = 0; j < site1; j++)
                    {
                        child1.gene[i][j] = parent1.gene[i][j];
                        child2.gene[i][j] = parent2.gene[i][j];
                    }
                    for (j = site1; j < site2; j++)
                    {
                        child1.gene[i][j] = parent2.gene[i][j];
                        child2.gene[i][j] = parent1.gene[i][j];
                    }
                    for (j = site2; j < nbits[i]; j++)
                    {
                        child1.gene[i][j] = parent1.gene[i][j];
                        child2.gene[i][j] = parent2.gene[i][j];
                    }
                }
                else
                {
                    for (j = 0; j < nbits[i]; j++)
                    {
                        child1.gene[i][j] = parent1.gene[i][j];
                        child2.gene[i][j] = parent2.gene[i][j];
                    }
                }
            }
            return;
        }

    }
}
