using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace NSGA2Sharp
{
    public partial class NSGA2
    {

        /* Function to print the information of a population in a file */
        void report_pop(ref population pop, ref StreamWriter fpt)
        {
            int i, j, k;
            for (i = 0; i < popsize; i++)
            {
                string line = "";
                for (j = 0; j < nobj; j++)
                {
                    line += pop.ind[i].obj[j].ToString();
                    line += "\t";
                    //fprintf(fpt, "%e\t", pop.ind[i].obj[j]);
                }
                if (ncon != 0)
                {
                    for (j = 0; j < ncon; j++)
                    {
                        line += pop.ind[i].constr[j].ToString();
                        line += "\t";
                        //fprintf(fpt, "%e\t", pop.ind[i].constr[j]);
                    }
                }
                if (nreal != 0)
                {
                    for (j = 0; j < nreal; j++)
                    {
                        line += pop.ind[i].xreal[j].ToString();
                        line += "\t";
                        //fprintf(fpt, "%e\t", pop.ind[i].xreal[j]);
                    }
                }
                if (nbin != 0)
                {
                    for (j = 0; j < nbin; j++)
                    {
                        for (k = 0; k < nbits[j]; k++)
                        {
                            line += pop.ind[i].gene[j][k].ToString();
                            line += "\t";
                            //fprintf(fpt, "%d\t", pop.ind[i].gene[j][k]);
                        }
                    }
                }
                line += pop.ind[i].constr_violation.ToString();
                line += "\t";
                line += pop.ind[i].rank.ToString();
                line += "\t"; ;
                line += pop.ind[i].crowd_dist.ToString();
                fpt.WriteLine(line);
                //fprintf(fpt, "%e\t", pop.ind[i].constr_violation);
                //fprintf(fpt, "%d\t", pop.ind[i].rank);
                //fprintf(fpt, "%e\n", pop.ind[i].crowd_dist);
            }
            return;
        }

        /* Function to print the information of feasible and non-dominated population in a file */
        void report_feasible(ref population pop, ref StreamWriter fpt)
        {
            int i, j, k;
            for (i = 0; i < popsize; i++)
            {
                string line = "";
                if (pop.ind[i].constr_violation == 0.0 && pop.ind[i].rank == 1)
                {
                    for (j = 0; j < nobj; j++)
                    {
                        line += pop.ind[i].obj[j].ToString();
                        line += "\t";
                        //fprintf(fpt, "%e\t", pop.ind[i].obj[j]);
                    }
                    if (ncon != 0)
                    {
                        for (j = 0; j < ncon; j++)
                        {
                            line += pop.ind[i].constr[j].ToString();
                            line += "\t";
                            //fprintf(fpt, "%e\t", pop.ind[i].constr[j]);
                        }
                    }
                    if (nreal != 0)
                    {
                        for (j = 0; j < nreal; j++)
                        {
                            line += pop.ind[i].xreal[j].ToString();
                            line += "\t";
                            //fprintf(fpt, "%e\t", pop.ind[i].xreal[j]);
                        }
                    }
                    if (nbin != 0)
                    {
                        for (j = 0; j < nbin; j++)
                        {
                            for (k = 0; k < nbits[j]; k++)
                            {
                                line += pop.ind[i].gene[j][k].ToString();
                                line += "\t";
                                //fprintf(fpt, "%d\t", pop.ind[i].gene[j][k]);
                            }
                        }
                    }
                    line += pop.ind[i].constr_violation.ToString();
                    line += "\t";
                    line += pop.ind[i].rank.ToString();
                    line += "\t"; ;
                    line += pop.ind[i].crowd_dist.ToString();
                    fpt.WriteLine(line);
                    //fprintf(fpt, "%e\t", pop.ind[i].constr_violation);
                    //fprintf(fpt, "%d\t", pop.ind[i].rank);
                    //fprintf(fpt, "%e\n", pop.ind[i].crowd_dist);
                }
            }
            return;
        }
        void display(ref population pop, ref StreamWriter fpt)
        {
            int i;
            string line;
            for (i = 0; i < popsize; i++)
            {
                if (pop.ind[i].constr_violation == 0)
                {
                    line = pop.ind[i].obj[obj1 - 1].ToString();
                    line += "\t";
                    line += pop.ind[i].obj[obj2 - 1].ToString();
                    if (choice == 3)
                    {
                        line += "t";
                        line += pop.ind[i].obj[obj3 - 1].ToString();
                    }
                    fpt.WriteLine(line);
                }
            }
        }
    }
}
