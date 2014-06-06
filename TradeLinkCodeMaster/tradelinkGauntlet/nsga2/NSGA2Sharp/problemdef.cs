using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NSGA2Sharp
{
    public partial class NSGA2
    {
        /* # define sch1 */
        static bool sch1 = true;
        /* # define sch2 */
        /* # define fon */
        /* # define kur */
        /* # define pol */
        /* # define vnt */
        /* # define zdt1 */
        /* # define zdt2 */
        /* # define zdt3 */
        /* # define zdt4 */
        /* # define zdt5 */
        /* # define zdt6 */
        /* # define bnh */
        /* # define osy */
        /* # define srn */
        /* # define tnk */
        //# define ctp1 
        /* # define ctp2 */
        /* # define ctp3 */
        /* # define ctp4 */
        /* # define ctp5 */
        /* # define ctp6 */
        /* # define ctp7 */
        /*# define ctp8*/
        /*  Test problem SCH1
        # of real variables = 1
        # of bin variables = 0
        # of objectives = 2
        # of constraints = 0
        */

        public static void test_problem(List<double> xreal, List<double> xbin, List<List<double>> gene, ref List<double> obj, ref List<double> constr)
        {
            if (sch1)
            {
                obj[0] = Math.Pow(xreal[0],2.0);
                obj[1] = Math.Pow((xreal[0]-2.0),2.0);
                return;
            }
        }

        #if sch1
        /*
        void test_problem (double *xreal, double *xbin, int **gene, double *obj, double *constr)
        {
            obj[0] = pow(xreal[0],2.0);
            obj[1] = pow((xreal[0]-2.0),2.0);
            return;
        }
        */
        #endif
      
    }
}
