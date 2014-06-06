using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NSGA2Sharp
{
    public partial class NSGA2
    {
        /* Routine to perform non-dominated sorting */
        void fill_nondominated_sort(ref population mixed_pop, ref population new_pop)
        {
            int flag;
            int i, j;
            int end;
            int front_size;
            int archieve_size;
            int rank=1;
            lists pool;
            lists elite;
            lists temp1, temp2;
            pool = new lists();
            elite = new lists();
            front_size = 0;
            archieve_size=0;
            pool.index = -1;
            pool.parent = null;
            pool.child = null;
            elite.index = -1;
            elite.parent = null;
            elite.child = null;
            temp1 = pool;
            for (i=0; i<2*popsize; i++)
            {
                insert (ref temp1,i);
                temp1 = temp1.child;
            }
            i=0;
            do
            {
                temp1 = pool.child;
                insert (ref elite, temp1.index);
                front_size = 1;
                temp2 = elite.child;
                temp1 = del (ref temp1);
                temp1 = temp1.child;
                do
                {
                    temp2 = elite.child;
                    if (temp1==null)
                    {
                        break;
                    }
                    do
                    {
                        end = 0;
                        individual individualA = mixed_pop.ind[temp1.index];
                        individual individualB = mixed_pop.ind[temp2.index];
                        flag = check_dominance(ref individualA, ref individualB);
                        if (flag == 1)
                        {
                            insert (ref pool, temp2.index);
                            temp2 = del (ref temp2);
                            front_size--;
                            temp2 = temp2.child;
                        }
                        if (flag == 0)
                        {
                            temp2 = temp2.child;
                        }
                        if (flag == -1)
                        {
                            end = 1;
                        }
                    }
                    while (end!=1 && temp2!=null);
                    if (flag == 0 || flag == 1)
                    {
                        insert (ref elite, temp1.index);
                        front_size++;
                        temp1 = del (ref temp1);
                    }
                    temp1 = temp1.child;
                }
                while (temp1 != null);
                temp2 = elite.child;
                j=i;
                if ( (archieve_size+front_size) <= popsize)
                {
                    do
                    {
                        individual individualA = mixed_pop.ind[temp2.index];
                        individual individualB = new_pop.ind[i];
                        copy_ind(ref individualA, ref individualB);
                        individual individualC = new_pop.ind[i];
                        individualC.rank = rank;
                        archieve_size+=1;
                        temp2 = temp2.child;
                        i+=1;
                    }
                    while (temp2 != null);
                    assign_crowding_distance_indices (ref new_pop, j, i-1);
                    rank+=1;
                }
                else
                {
                    crowding_fill (ref mixed_pop, ref new_pop, i, front_size, ref elite);
                    archieve_size = popsize;
                    for (j=i; j<popsize; j++)
                    {
                        individual individualA = new_pop.ind[j];
                        individualA.rank = rank;
                    }
                }
                temp2 = elite.child;
                do
                {
                    temp2 = del (ref temp2);
                    temp2 = temp2.child;
                }
                while (elite.child !=null);
            }
            while (archieve_size < popsize);
            while (pool!=null)
            {
                temp1 = pool;
                pool = pool.child;
            }
            while (elite!=null)
            {
                temp1 = elite;
                elite = elite.child;
            }
            return;
        }

        /* Routine to fill a population with individuals in the decreasing order of crowding distance */
        void crowding_fill(ref population mixed_pop, ref population new_pop, int count, int front_size, ref lists elite)
        {
            List<int> dist;
            lists temp;
            int i, j;
            assign_crowding_distance_list(ref mixed_pop, ref elite.child, front_size);
            dist = new List<int>();
            temp = elite.child;
            for (j = 0; j < front_size; j++)
            {
                dist.Add(temp.index);
                temp = temp.child;
            }
            quicksort_dist(ref mixed_pop, ref dist, front_size);
            for (i = count, j = front_size - 1; i < popsize; i++, j--)
            {
                individual individualA = mixed_pop.ind[dist[j]];
                individual individualB = new_pop.ind[i];
                copy_ind(ref individualA, ref individualB);
                //copy_ind(&mixed_pop->ind[dist[j]], &new_pop->ind[i]);
            }
            return;
        }

    }
}
