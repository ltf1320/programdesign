using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NSGA2Sharp
{
    public partial class NSGA2
    {
        /* Function to assign rank and crowding distance to a population of size pop_size*/
        void assign_rank_and_crowding_distance(ref population new_pop)
        {
            int flag;
            int i;
            int end;
            int front_size;
            int rank=1;
            lists orig;
            lists cur;
            lists temp1, temp2;
            orig = new lists();
            cur = new lists();
            front_size = 0;
            orig.index = -1;
            orig.parent = null;
            orig.child = null;
            cur.index = -1;
            cur.parent = null;
            cur.child = null;
            temp1 = orig;
            for (i=0; i<popsize; i++)
            {
                insert (ref temp1,i);
                temp1 = temp1.child;
            }
            do
            {
                if (orig.child.child == null)
                {
                    individual individualA = new_pop.ind[orig.child.index];
                    individualA.rank = rank;
                    individualA.crowd_dist = double.MaxValue;
                    break;
                }
                temp1 = orig.child;
                insert (ref cur, temp1.index);
                front_size = 1;
                temp2 = cur.child;
                temp1 = del (ref temp1);
                temp1 = temp1.child;
                do
                {
                    temp2 = cur.child;
                    do
                    {
                        end = 0;
                        individual individualA = new_pop.ind[temp1.index];
                        individual individualB = new_pop.ind[temp2.index];
                        flag = check_dominance(ref individualA, ref individualB);
                        if (flag == 1)
                        {
                            insert (ref orig, temp2.index);
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
                        insert (ref cur, temp1.index);
                        front_size++;
                        temp1 = del (ref temp1);
                    }
                    temp1 = temp1.child;
                }
                while (temp1 != null);
                temp2 = cur.child;
                do
                {
                    individual individualA = new_pop.ind[temp2.index];
                    individualA.rank = rank;
                    temp2 = temp2.child;
                }
                while (temp2 != null);
                assign_crowding_distance_list (ref new_pop, ref cur.child, front_size);
                temp2 = cur.child;
                do
                {
                    temp2 = del (ref temp2);
                    temp2 = temp2.child;
                }
                while (cur.child !=null);
                rank+=1;
            } while (orig.child != null);
            return;
        }

    }
}
