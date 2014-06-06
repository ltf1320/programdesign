using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NSGA2Sharp
{
    public partial class NSGA2
    {
      
        /* Randomized quick sort routine to sort a population based on a particular objective chosen */
        void quicksort_front_obj(ref population pop, int objcount, List<int> obj_array, int obj_array_size)
        {
            q_sort_front_obj (ref pop, objcount, obj_array, 0, obj_array_size-1);
            return;
        }

        /* Actual implementation of the randomized quick sort used to sort a population based on a particular objective chosen */
        void q_sort_front_obj(ref population pop, int objcount, List<int> obj_array, int left, int right)
        {
            int index;
            int temp;
            int i, j;
            double pivot;
            if (left<right)
            {
                index = rnd (left, right);
                temp = obj_array[right];
                obj_array[right] = obj_array[index];
                obj_array[index] = temp;
                individual individualLocal = pop.ind[obj_array[right]];
                pivot = individualLocal.obj[objcount];
                i = left-1;
                for (j=left; j<right; j++)
                {
                    individual individualLocal1 = pop.ind[obj_array[j]];
                    if (individualLocal1.obj[objcount] <= pivot)
                    {
                        i+=1;
                        temp = obj_array[j];
                        obj_array[j] = obj_array[i];
                        obj_array[i] = temp;
                    }
                }
                index=i+1;
                temp = obj_array[index];
                obj_array[index] = obj_array[right];
                obj_array[right] = temp;
                q_sort_front_obj (ref pop, objcount, obj_array, left, index-1);
                q_sort_front_obj (ref pop, objcount, obj_array, index+1, right);
            }
            return;
        }

        /* Randomized quick sort routine to sort a population based on crowding distance */
        void quicksort_dist(ref population pop, ref List<int> dist, int front_size)
        {
            q_sort_dist(ref pop, ref dist, 0, front_size - 1);
            return;
        }

        /* Actual implementation of the randomized quick sort used to sort a population based on crowding distance */
        void q_sort_dist(ref population pop, ref List<int> dist, int left, int right)
        {
            int index;
            int temp;
            int i, j;
            double pivot;
            if (left < right)
            {
                index = rnd(left, right);
                temp = dist[right];
                dist[right] = dist[index];
                dist[index] = temp;
                individual individualLocal = pop.ind[dist[right]];
                pivot = individualLocal.crowd_dist;
                i = left - 1;
                for (j = left; j < right; j++)
                {
                    individual individualLocal1 = pop.ind[dist[j]];
                    if (individualLocal1.crowd_dist <= pivot)
                    {
                        i += 1;
                        temp = dist[j];
                        dist[j] = dist[i];
                        dist[i] = temp;
                    }
                }
                index = i + 1;
                temp = dist[index];
                dist[index] = dist[right];
                dist[right] = temp;
                q_sort_dist(ref pop, ref dist, left, index - 1);
                q_sort_dist(ref pop, ref dist, index + 1, right);
            }
            return;
        }

    }
}
