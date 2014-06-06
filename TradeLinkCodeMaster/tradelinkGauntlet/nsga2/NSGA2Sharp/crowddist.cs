using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NSGA2Sharp
{
    public partial class NSGA2
    {
        /* Routine to compute crowding distance based on ojbective function values when the population in in the form of a list */
        void assign_crowding_distance_list(ref population pop, ref lists lst, int front_size)
        {
            List<List<int>> obj_array;
            List<int> dist,obj;
            int i, j;
            lists temp;
            temp = lst;
            if (front_size == 1)
            {
                individual individualLocal = pop.ind[lst.index];
                individualLocal.crowd_dist = double.MaxValue;
                return;
            }
            if (front_size == 2)
            {
                individual individualLocal = pop.ind[lst.index];
                individualLocal.crowd_dist = double.MaxValue;
                individual individualLocalChild = pop.ind[lst.child.index];
                individualLocalChild.crowd_dist = double.MaxValue;
                return;
            }
            obj_array = new List<List<int>>();
            dist = new List<int>();
            for (i = 0; i < nobj; i++)
            {
                obj = new List<int>();
                for (j = 0; j < front_size; j++) obj.Add(0);
                obj_array.Add(obj);
            }
            for (j = 0; j < front_size; j++)
            {
                dist.Add(temp.index);
                temp = temp.child;
            }
            assign_crowding_distance(ref pop, ref dist, ref obj_array, front_size);
            
            return;
        }

        /* Routine to compute crowding distance based on objective function values when the population in in the form of an array */
        void assign_crowding_distance_indices(ref population pop, int c1, int c2)
        {
            List<List<int>> obj_array;
            List<int> dist,obj;
            int i, j;
            int front_size;
            front_size = c2 - c1 + 1;
            if (front_size == 1)
            {
                individual individualLocal = pop.ind[c1];
                individualLocal.crowd_dist = double.MaxValue;
                return;
            }
            if (front_size == 2)
            {
                individual individualLocal = pop.ind[c1];
                individualLocal.crowd_dist = double.MaxValue;
                individual individualLocalChild = pop.ind[c2];
                individualLocalChild.crowd_dist = double.MaxValue;
                return;
            }
            obj_array = new List<List<int>>();
            dist = new List<int>();
            for (i = 0; i < nobj; i++)
            {
                obj = new List<int>();
                for (j = 0; j < front_size; j++) obj.Add(0);
                obj_array.Add(obj);
            }
            for (j = 0; j < front_size; j++)
            {
                dist.Add(c1++);
            }
            assign_crowding_distance(ref pop, ref dist, ref obj_array, front_size);
            
            return;
        }

        /* Routine to compute crowding distances */
        void assign_crowding_distance(ref population pop, ref List<int> dist, ref List<List<int>> obj_array, int front_size)
        {
            int i, j;
            for (i = 0; i < nobj; i++)
            {
                for (j = 0; j < front_size; j++)
                {
                    obj_array[i][j] = dist[j];
                }
                quicksort_front_obj(ref pop, i, obj_array[i], front_size);
            }
            for (j = 0; j < front_size; j++)
            {
                individual individualLocal = pop.ind[dist[j]];
                individualLocal.crowd_dist = 0.0;
            }
            for (i = 0; i < nobj; i++)
            {
                individual individualLocal = pop.ind[obj_array[i][0]];
                individualLocal.crowd_dist = double.MaxValue;
            }
            for (i = 0; i < nobj; i++)
            {
                for (j = 1; j < front_size - 1; j++)
                {
                    individual individualLocal = pop.ind[obj_array[i][j]];
                    if (individualLocal.crowd_dist != double.MaxValue)
                    {
                        individual individualLocal1 = pop.ind[obj_array[i][front_size - 1]];
                        individual individualLocal2 = pop.ind[obj_array[i][0]];
                        individual individualLocal3 = pop.ind[obj_array[i][j]];
                        individual individualLocal4 = pop.ind[obj_array[i][j + 1]];
                        individual individualLocal5 = pop.ind[obj_array[i][j - 1]];
                        if (individualLocal1.obj[i] == individualLocal2.obj[i])
                        {
                            
                            individualLocal3.crowd_dist += 0.0; // ???
                        }
                        else
                        {
                            individualLocal3.crowd_dist += (individualLocal4.obj[i] - individualLocal5.obj[i]) /( individualLocal1.obj[i] - individualLocal2.obj[i]);
                        }
                    }
                }
            }
            for (j = 0; j < front_size; j++)
            {
                individual individualLocal = pop.ind[dist[j]];
                if (individualLocal.crowd_dist != double.MaxValue)
                {
                    individualLocal.crowd_dist = (individualLocal.crowd_dist) / nobj;
                }
            }
            return;
        }

    }
}
