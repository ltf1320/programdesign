using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.ComponentModel;

namespace NSGA2Sharp
{
    public partial class NSGA2
    {
        public delegate void OBJECTIVEFunction(List<double> xreal, List<double> xbin, List<List<double>> gene, ref List<double> obj, ref List<double> constr);

        public OBJECTIVEFunction evalFunction { get { return _evalFunc; } set { _evalFunc = value; } }
        
        public class individual
        {
            public int rank;
            public double constr_violation;
            public List<double> xreal;
            public List<List<double>> gene;
            public List<double> xbin;
            public List<double> obj;
            public List<double> constr;
            public double crowd_dist;
        }

        public struct population
        {
            public List<individual> ind;
        }

        public class lists
        {
            public int index = -1;
            public lists parent;
            public lists child;
        }

        int nreal;
        int nbin;
        int nobj;
        int ncon;
        int popsize;
        double pcross_real;
        double pcross_bin;
        double pmut_real;
        double pmut_bin;
        double eta_c;
        double eta_m;
        int ngen;
        int nbinmut;
        int nrealmut;
        int nbincross;
        int nrealcross;
        List<int> nbits;
        List<double> min_realvar;
        List<double> max_realvar;
        List<double> min_binvar;
        List<double> max_binvar;
        int bitlength;
        int choice;
        int obj1;
        int obj2;
        int obj3;
        int angle1;
        int angle2;
        StreamWriter initPop;
        StreamWriter bestPop;
        StreamWriter allPop;
        StreamWriter finPop;
        StreamWriter param;
        StreamWriter plot;

        population parent_pop;
        population child_pop;
        population mixed_pop;

        bool _log = false;

        [Description("Random seed")]
        public double Seed { get { return seed; } set { seed = value; } }
        [Description("Logging")]
        public bool log { get { return _log; } set { _log = value; } }


        public NSGA2(string input_file,bool lg=false)
        {
            log = lg;
            init();
            loadParamFromFile(input_file);
        }
        void init()
        {
            seed = 0.5;
            if (log)
            {
                initPop = new StreamWriter("./nsga2/Initial_pop1.out");
                bestPop = new StreamWriter("./nsga2/Best_pop1.out");
                allPop = new StreamWriter("./nsga2/All_pop1.out");
                finPop = new StreamWriter("./nsga2/Final_pop1.out");
                param = new StreamWriter("./nsga2/Params1.out");
                plot = new StreamWriter("./nsga2/Plot1.out");
                initPop.WriteLine("# This file contains the data of initial population\n");
                bestPop.WriteLine("# This file contains the data of final feasible population (if found)\n");
                allPop.WriteLine("# This file contains the data of all generations\n");
                finPop.WriteLine("# This file contains the data of final population\n");
                param.WriteLine("# This file contains information about inputs as read by the program\n");
            }
        }

        /* read the original input files that comes with the package. see README in nsga2. they also can be make properties and set individually instead. 
         * we then need a constructor of null ragument.
        */
        void loadParamFromFile(string input_file_name) 
        {
            StreamReader sr = new StreamReader(input_file_name);
            string line;
            line = sr.ReadLine();
            popsize = Convert.ToInt32(line);
            if(popsize < 4.0 || popsize%4 != 0) 
                throw new Exception("Wrong population size entered, hence exiting  ");
            line = sr.ReadLine();
            ngen = Convert.ToInt32(line); ;
            if(ngen <1 )
                throw new Exception("Wrong number of generations entered, hence exiting ");
            line = sr.ReadLine();
            nobj = Convert.ToInt32(line); ;
            if (nobj < 1)
                throw new Exception("Wrong number of objectives entered, hence exiting ");
            line = sr.ReadLine();
            ncon = Convert.ToInt32(line); ;
            if (ncon < 0)
                throw new Exception("Wrong number of constraints entered, hence exiting ");
            line = sr.ReadLine();
            nreal = Convert.ToInt32(line); ;
            if (nreal < 0)
                throw new Exception("Wrong number of real variables entered, hence exiting ");
            if (nreal != 0)
            {
                List<string> sp_line = new List<string>();
                min_realvar = new List<double>();
                max_realvar = new List<double>();
                for (int i = 0; i < nreal; i++)
                {
                    line = sr.ReadLine();
                    sp_line.AddRange(line.Split(' '));
                    min_realvar.Add(Convert.ToDouble(sp_line[0]));
                    max_realvar.Add(Convert.ToDouble(sp_line[1]));
                    if (max_realvar[i] <= min_realvar[i])
                        throw new Exception(" Wrong limits entered for the min and max bounds of real variable, hence exiting");
                }

                line = sr.ReadLine();
                pcross_real = Convert.ToDouble(line);
                if (pcross_real < 0.0 || pcross_real > 1.0)
                    throw new Exception("Entered value of probability of crossover of real variables is out of bounds, hence exiting");
                line = sr.ReadLine();
                pmut_real = Convert.ToDouble(line);
                if (pmut_real < 0.0 || pmut_real > 1.0)
                    throw new Exception("Entered value of probability of mutation of real variables is out of bounds, hence exiting");
                line = sr.ReadLine();
                eta_c = Convert.ToDouble(line);
                if (eta_c <= 0.0)
                    throw new Exception("Wrong value of distribution index for crossover entered, hence exiting");
                line = sr.ReadLine();
                eta_m = Convert.ToDouble(line);
                if (eta_m <= 0.0)
                    throw new Exception("Wrong value of distribution index for mutation entered, hence exiting");
            }
            line = sr.ReadLine();
            nbin = Convert.ToInt32(line);
            if (nbin < 0)
                throw new Exception("Wrong number of binary variables entered, hence exiting");
            if (nbin != 0)
            {
                List<string> sp_line = new List<string>();
                min_binvar = new List<double>();
                max_binvar = new List<double>();
                nbits = new List<int>();
                for (int i = 0; i < nbin; i++)
                {
                    line = sr.ReadLine();
                    sp_line.AddRange(line.Split(' '));
                    nbits.Add(Convert.ToInt32(sp_line[0]));
                    if (nbits[i] < 1)
                        throw new Exception("Wrong number of bits for binary variable entered, hence exiting");
                    min_binvar.Add(Convert.ToDouble(sp_line[1]));
                    max_binvar.Add(Convert.ToDouble(sp_line[2]));
                    if (max_binvar[i] <= min_binvar[i])
                        throw new Exception(" Wrong limits entered for the min and max bounds of binary variable, hence exiting");
                }
                line = sr.ReadLine();
                pcross_bin = Convert.ToDouble(line);
                if (pcross_bin < 0.0 || pcross_bin > 1.0)
                    throw new Exception("Entered value of probability of crossover of binary variables is out of bounds, hence exiting");
                line = sr.ReadLine();
                pmut_bin = Convert.ToDouble(line);
                if (pmut_bin < 0.0 || pmut_bin > 1.0)
                    throw new Exception("Entered value of probability of mutation of binary variables is out of bounds, hence exiting");
            }
            if (nreal==0 && nbin==0)
                throw new Exception("Number of real as well as binary variables, both are zero, hence exiting");
            // skip the real time  gnuplot part for now. 
            line = sr.ReadLine();
            choice = Convert.ToInt32(line);
            if (choice <= 0 && choice > 3 )
                throw new Exception("Wrong choice ID entered, hence exiting");
                // assuming at least two onjective
            line = sr.ReadLine();
            obj1 = Convert.ToInt32(line);
            if (obj1 < 1 || obj1 > nobj)
                throw new Exception("Wrong value of X objective entered");
            line = sr.ReadLine();
            obj2 = Convert.ToInt32(line);
            if (obj2 < 1 || obj2 > nobj)
                throw new Exception("Wrong value of Y objective entered");
            if (choice == 3)
            {
                line = sr.ReadLine();
                obj3 = Convert.ToInt32(line);
                if (obj3 < 1 || obj3 > nobj)
                    throw new Exception("Wrong value of X objective entered");
            }
        }
        public void doOptimization()
        {
            string line;
            if (nbin != 0)
            {
                for (int i = 0; i < nbin; i++)
                {
                    bitlength += nbits[i];
                }
            }

            if (log)
            {
                line = "Population size = ";
                line += popsize.ToString();
                line += "/n";
                param.WriteLine(line);
                line = "Number of generations = ";
                line += ngen.ToString();
                line += "/n";
                param.WriteLine(line);
                line = " Number of objective functions = ";
                line += nobj.ToString();
                line += "/n";
                param.WriteLine(line);
                line = " Number of constraints = ";
                line += ncon.ToString();
                line += "/n";
                param.WriteLine(line);
                line = "Number of real variables = %  ";
                line += nreal.ToString();
                line += "/n";
                param.WriteLine(line);
                if (nreal != 0)
                {
                    line = "Lower limit of real variable ";
                    string line1 = " Upper limit of real variable ";
                    for (int i = 0; i < nreal; i++)
                    {
                        line += (i + 1).ToString();
                        line += "=";
                        line += min_realvar[i].ToString();
                        param.WriteLine(line);
                        line1 += (i + 1).ToString();
                        line1 += "=";
                        line1 += max_realvar[i].ToString();
                        param.WriteLine(line1);
                    }
                    line = " Probability of crossover of real variable =  ";
                    line += pcross_real.ToString();
                    line += "/n";
                    param.WriteLine(line);
                    line = " Probability of mutation of real variable =  ";
                    line += pmut_real.ToString();
                    line += "/n";
                    param.WriteLine(line);
                }
                line = " Number of binary variables =  ";
                line += nbin.ToString();
                line += "/n";
                param.WriteLine(line);
                if (nbin != 0)
                {
                    line = "Lower limit of binary variable ";
                    string line1 = " Upper limit of binary variable ";
                    string line2 = "  Number of bits for binary variable ";
                    for (int i = 0; i < nbin; i++)
                    {
                        line += (i + 1).ToString();
                        line += "=";
                        line += min_binvar[i].ToString();
                        param.WriteLine(line);
                        line1 += (i + 1).ToString();
                        line1 += "=";
                        line1 += max_binvar[i].ToString();
                        param.WriteLine(line1);
                        line2 += (i + 1).ToString();
                        line2 += "=";
                        line2 += nbits[i].ToString();
                        param.WriteLine(line2);
                    }
                    line = " Probability of crossover of real variable =  ";
                    line += pcross_bin.ToString();
                    line += "/n";
                    param.WriteLine(line);
                    line = " Probability of mutation of real variable =  ";
                    line += pmut_bin.ToString();
                    line += "/n";
                    param.WriteLine(line);
                }
                line = "Seed for random number generator = ";
                line += Seed.ToString();
                line += "/n";
                param.WriteLine(line);

                line = "# of objectives = ";
                line += nobj.ToString();
                line += ",  # of constraints = ";
                line += ncon.ToString();
                line += ", # of real_var = ";
                line += nreal.ToString();
                line += ",  # of bits of bin_var = ";
                line += nbin.ToString();
                line += "constr_violation, rank, crowding_distance";

                initPop.WriteLine(line);
                bestPop.WriteLine(line);
                allPop.WriteLine(line);
                finPop.WriteLine(line);
            }
            nbinmut = 0;
            nrealmut = 0;
            nbincross = 0;
            nrealcross = 0;
            parent_pop = new population();
            child_pop = new population();
            mixed_pop = new population();
            Console.WriteLine("performing first generation");
            allocate_memory_pop(ref parent_pop, popsize);
            allocate_memory_pop(ref child_pop, popsize);
            allocate_memory_pop(ref mixed_pop, 2 * popsize);
            randomize();
            initialize_pop(ref parent_pop);
            decode_pop(ref parent_pop);
            evaluate_pop(ref parent_pop);
            assign_rank_and_crowding_distance(ref parent_pop);
            if (log)
            {
                report_pop(ref parent_pop, ref initPop);
                line = "# gen = 1\n";
                allPop.WriteLine(line);
                report_pop(ref parent_pop, ref allPop);
            }
            Console.WriteLine("gen = 1");
            for (int i = 2; i <= ngen; i++)
            {
                selection(ref parent_pop, ref child_pop);
                mutation_pop(ref child_pop);
                decode_pop(ref child_pop);
                evaluate_pop(ref child_pop);
                merge(ref parent_pop, ref child_pop, ref mixed_pop);
                fill_nondominated_sort(ref mixed_pop, ref parent_pop);
                /* Comment following four lines if information for all
                generations is not desired, it will speed up the execution */
                if (log)
                {
                    line = "# gen = ";
                    line += i.ToString();
                    allPop.WriteLine(line);
                }
            }
            if (log && choice != 0) display(ref parent_pop, ref plot);

            line = " Generations finished";
            Console.WriteLine(line);
            if (log)
            {
                report_pop(ref parent_pop, ref finPop);
                report_feasible(ref parent_pop, ref bestPop);
                if (nreal != 0)
                {
                    line = "Number of crossover of real variable = ";
                    line += nrealcross.ToString();
                    param.WriteLine(line);
                    line = " Number of mutation of real variable = ";
                    line += nrealmut.ToString();
                    param.WriteLine(line);
                }
                if (nbin != 0)
                {
                    line = "Number of crossover of binary variable = ";
                    line += nbincross.ToString();
                    param.WriteLine(line);
                    line = " Number of mutation of binary variable = ";
                    line += nbinmut.ToString();
                    param.WriteLine(line);
                }
                param.Flush();
                finPop.Flush();
                allPop.Flush();
                bestPop.Flush();
                initPop.Flush();
                plot.Flush();
            }
            Console.WriteLine("Routine successfully exited ");
        }  

        protected OBJECTIVEFunction _evalFunc;
    }
}
