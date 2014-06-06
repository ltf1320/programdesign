using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NSGA2Sharp
{
    public partial class NSGA2
    {

        /* Routine for tournament selection, it creates a new_pop from old_pop by performing tournament selection and the crossover */
        void selection(ref population old_pop, ref population new_pop)
        {
            List<int> a1, a2;
            int temp;
            int i;
            int rand;
            individual parent1, parent2;
            a1 = new List<int>();
            a2 = new List<int>();
            for (i=0; i<popsize; i++)
            {
                a1.Add(i);
                a2.Add(i);
            }
            for (i=0; i<popsize; i++)
            {
                rand = rnd (i, popsize-1);
                temp = a1[rand];
                a1[rand] = a1[i];
                a1[i] = temp;
                rand = rnd (i, popsize-1);
                temp = a2[rand];
                a2[rand] = a2[i];
                a2[i] = temp;
            }
            for (i=0; i<popsize; i+=4)
            {
                individual individualA = old_pop.ind[a1[i]];
                individual individualB = old_pop.ind[a1[i + 1]];
                parent1 = tournament(ref individualA, ref individualB);
                individual individualC = old_pop.ind[a1[i + 2]];
                individual individualD = old_pop.ind[a1[i + 3]];
                parent2 = tournament(ref individualC, ref individualD);
                individual individualE = new_pop.ind[i];
                individual individualF = new_pop.ind[i + 1];
                crossover(ref parent1, ref parent2, ref individualE, ref individualF);
                individual individualG = old_pop.ind[a2[i]];
                individual individualH = old_pop.ind[a2[i + 1]];
                parent1 = tournament(ref individualG, ref individualH);
                individual individualI = old_pop.ind[a2[i + 2]];
                individual individualJ = old_pop.ind[a2[i + 3]];
                parent2 = tournament(ref individualI, ref individualJ);
                individual individualK = new_pop.ind[i + 2];
                individual individualL = new_pop.ind[i + 3];
                crossover(ref parent1, ref parent2, ref individualK, ref individualL);
            }
            return;
        }

        /* Routine for binary tournament */
        individual tournament(ref individual ind1, ref individual ind2)
        {
            int flag;
            flag = check_dominance(ref ind1, ref ind2);
            if (flag == 1)
            {
                return (ind1);
            }
            if (flag == -1)
            {
                return (ind2);
            }
            if (ind1.crowd_dist > ind2.crowd_dist)
            {
                return (ind1);
            }
            if (ind2.crowd_dist > ind1.crowd_dist)
            {
                return (ind2);
            }
            if ((randomperc()) <= 0.5)
            {
                return (ind1);
            }
            else
            {
                return (ind2);
            }
        }
    }
}
