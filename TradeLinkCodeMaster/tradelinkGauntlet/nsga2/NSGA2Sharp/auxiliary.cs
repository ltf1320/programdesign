using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NSGA2Sharp
{
    public partial class NSGA2
    {  
        /* Function to return the maximum of two variables */
        double maximum(double a, double b)
        {
            if (a > b)
            {
                return (a);
            }
            return (b);
        }
        /* Function to return the minimum of two variables */
        double minimum(double a, double b)
        {
            if (a < b)
            {
                return (a);
            }
            return (b);
        }
    }
}
