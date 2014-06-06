using System;
using BaseUtility;
using System.IO;
using System.Runtime.InteropServices;
using System.Text;
using System.Data;

using System.Collections;
using System.Collections.Generic;
using System.Threading;
using System.ComponentModel;

namespace MathUtilityCommon
{
    public class Mopsocd : GenericMOptimizationTemplate
    {
        public override void LoadParamFromFile(String inputFilePath)
        {
            DataTable paramTableInput = null;
            StreamReader sr = new StreamReader(inputFilePath, Encoding.GetEncoding("GB18030"));
            paramTableInput = CsvParser.Parse(sr, false);
            for (Int32 i = 0; i < paramTableInput.Columns.Count; i++)
            {
                paramTableInput.Columns[i].ColumnName = paramTableInput.Rows[0][i].ToString();
            }
            sr.Close();
            loadOptParamTable(ref paramTableInput);
        }
        
        public override void Initialization()
        {
            loadParameters();

            archiveVar = new double[archive_size][];
            archiveFit = new double[archive_size][];
            for (Int32 i = 0; i < archive_size; i++)
            {
                archiveVar[i] = new double[maxvar];
                archiveFit[i] = new double[maxfun];
            }

            popVar = new double[popsize][];
            popFit = new double[popsize][];
            pbestsVar = new double[popsize][];
            pbestsFit = new double[popsize][];
            velocity = new double[popsize][];
            for (Int32 i = 0; i < popsize; i++)
            {
                popVar[i] = new double[maxvar];
                popFit[i] = new double[maxfun];
                pbestsVar[i] = new double[maxvar];
                pbestsFit[i] = new double[maxfun];
                velocity[i] = new double[maxvar];
            }
            crowdDist = new double[archive_size + 1];
        }
        public override Int32 DoOptimization()
        {
            Initialization();

            uint i, j, t;
            PI = 4.0 * Math.Atan(1.0);

            bool writeTmpOut = true;
            StreamWriter swoutfile = null;
            StreamWriter swplotfile = null;
            StreamWriter swstdout = null;
            String outputFileName = "SolMap.csv";
            String outputFileExtra = "";
            lock (_locker)
            {

                String outputdir = "";
                String tmpRoot = "";
                if (_paramTable.ContainsKey("outputdir"))
                {
                    outputdir = _paramTable["outputdir"].ToString();
                }

                if (_paramTable.ContainsKey("outputFileExtra".ToLower()))
                {
                    outputFileExtra = _paramTable["outputFileExtra".ToLower()].ToString();
                    tmpRoot = outputdir + "/" + outputFileExtra;
                }

                if (outputdir == "current")
                {
                    swoutfile = new StreamWriter("output.out", false, Encoding.GetEncoding("GB18030"));
                    swplotfile = new StreamWriter("plot.out", false, Encoding.GetEncoding("GB18030"));
                    swstdout = new StreamWriter("stdout.out", false, Encoding.GetEncoding("GB18030"));
                }
                else
                {
                    tmpRoot = outputdir + "/" + outputFileExtra;
                    outputFileName = tmpRoot + outputFileName;
                    swoutfile = new StreamWriter(tmpRoot + "output.out", false, Encoding.GetEncoding("GB18030"));
                    swplotfile = new StreamWriter(tmpRoot + "plot.out", false, Encoding.GetEncoding("GB18030"));
                    swstdout = new StreamWriter(tmpRoot + "stdout.out", false, Encoding.GetEncoding("GB18030"));
                }
            }


            /* Initialize random number generator */
            initialize_rand();

            /* Initialize generation counter */
            t = 0;

            /* Initialize population with random values */
            initialize_popG();

            /* Initialize velocity */
            initialize_vel();

            /* Evaluate particles in population */
            evaluateG();

            /* Store initial personal bests (both variable and fitness values) of particles */
            store_pbests();

            /* Insert nondominated particles in population into the archive */
            insert_nondomG();

            /******* MAIN LOOP *********/
            while (t <= maxgen)
            {

                if (_worker != null)
                {
                    if (_worker.CancellationPending == true)
                    {
                        //e.Cancel = true;
                        lock (_locker)
                        {
                            //outMessage.Add("Cancel the job at: " + DateTime.Now.ToString());
                        }
                        return 0;
                    }
                }

                /* Compute crowding distance of each particle in the archive */
                /* Only when there are at least 3 particles in the archive */
                if (nondomCtr > 2)
                    crowding();

                /* Compute new velocity of each particle in the population */
                compute_velocity();

                /* Maintain particles in the population within the search space */
                maintain_particlesG();

                /* Mutate particles in the population */
                if (t < maxgen * pMut)
                    mutateG(t);

                /* Evaluate particles in the population */
                evaluateG();

                /* Insert new nondominated particles in pop into archive */
                update_archiveG();

                /* Update personal bests of particles in the population */
                update_pbests();

                /* Print Best So Far */
                if (writeTmpOut)
                    lock (_locker)
                    {
                        if (t % printevery == 0 || t == maxgen)
                        {
                            swoutfile.Write("Size of Pareto Set At" + DateTime.Now.ToString() + ": " + nondomCtr.ToString());
                            swoutfile.Write(swoutfile.NewLine);
                            for (i = 0; i < nondomCtr; i++)
                            {
                                swoutfile.Write("Function Values: ");
                                for (j = 0; j < maxfun; j++)
                                {
                                    swoutfile.Write(archiveFit[i][j]);
                                    swoutfile.Write(" ");

                                }
                                swoutfile.Write(swoutfile.NewLine);
                                for (j = 0; j < maxvar; j++)
                                {

                                    swoutfile.Write(archiveVar[i][j]);
                                    swoutfile.Write(" ");
                                }
                                swoutfile.Write(swoutfile.NewLine);

                            }

                            swoutfile.Write(swoutfile.NewLine);
                            swoutfile.Flush();
                        }

                        if (t == maxgen)
                        {
                            swplotfile.Write("# GNU Plot");
                            swplotfile.Write(swplotfile.NewLine);
                            for (i = 0; i < nondomCtr; i++)
                            {
                                for (j = 0; j < maxfun; j++)
                                {
                                    swplotfile.Write(archiveFit[i][j]);
                                    swplotfile.Write(" ");
                                }
                                swplotfile.Write(swplotfile.NewLine);
                            }
                            swplotfile.Flush();
                        }
                    }

                /* Increment generation counter */
                t++;

            }

            /* Write results to file */
            if (writeTmpOut)
                lock (_locker)
                {
                    //save_results(archiveName);
                    swstdout.Write("job all done for: " + outputFileExtra);
                    swoutfile.Write(swoutfile.NewLine);

                    DataTable solMap = null;
                    OutputSolutions(ref solMap);

                    StreamWriter sw = new StreamWriter(outputFileName, false, Encoding.GetEncoding("GB18030"));
                    CsvWriter.WriteToStream(sw, solMap, true, true);
                    sw.Close();

                    swoutfile.Close();
                    swplotfile.Close();
                    swstdout.Close();
                }

            return 1;
        }
        public override void OutputSolutions(ref DataTable solMap)
        {
            if (solMap != null)
            {
                solMap.Clear();
            }
            solMap = new DataTable();
            solMap.Columns.Add("solnum");
            for (Int32 i = 0; i < maxvar; i++)
            {
                solMap.Columns.Add("var" + i.ToString());
            }
            for (Int32 i = 0; i < maxfun; i++)
            {
                solMap.Columns.Add("fvalue" + i.ToString());
            }
            for (Int32 i = 0; i < maxcontrains; i++)
            {
                solMap.Columns.Add("constrainvalue" + i.ToString());
            }
            MiscUtility.addRowToTable(solMap, out solMap, nondomCtr);
            for (Int32 i = 0; i < nondomCtr; i++)
            {
                solMap.Rows[i]["solnum"] = i.ToString();
                for (Int32 j = 0; j < maxvar; j++)
                {
                    String colName = "var" + j.ToString();
                    solMap.Rows[i][colName] = archiveVar[i][j];
                    argLocal[j] = archiveVar[i][j];
                }

                for (Int32 j = 0; j < maxfun; j++)
                {
                    String colName = "fvalue" + j.ToString();
                    solMap.Rows[i][colName] = archiveFit[i][j];
                }

                if (maxcontrains > 0)
                {
                    _funtionToCalConstrains(argLocal, constrainsValueLocal, objLocal);

                    for (Int32 j = 0; j < maxcontrains; j++)
                    {
                        String colName = "constrainvalue" + j.ToString();
                        solMap.Rows[i][colName] = constrainsValueLocal[j];
                    }
                }
            }
        }
        public override void TestRun(Hashtable testRunInput)
        {
            switch (testRunInput["testcase"].ToString())
            {
                case "kita":
                    EvluationFunction = myKita;
                    ConstrainFunction = myKitaConstrains;
                    function = 100;
                    break;
                case "deb":
                    EvluationFunction = myDeb;
                    function = 200;
                    break;
                case "kursawe":
                    function = 300;
                    EvluationFunction = myKursawe;
                    break;

                case "DTLZ6":
                    function = 500;
                    EvluationFunction = myDTLZ6;
                    break;

                default:
                    EvluationFunction = myKita;
                    ConstrainFunction = myKitaConstrains;
                    break;
            }

            DoOptimization();
        }
        
        private void loadOptParamTable(ref DataTable optParamTable)
        {
            Hashtable optParamHashtable = new Hashtable();
            Int32 argIndex = 0;
            Int32 funIndex = 0;
            Int32 constrainFunIndex = 0;
            for (Int32 i = 0; i < optParamTable.Rows.Count; i++)
            {
                String state = optParamTable.Rows[i]["state"].ToString().ToLower();
                if (state == "none")
                {
                    String varName = optParamTable.Rows[i]["code"].ToString().ToLower();
                    String keyType = varName;
                    String keyValue = optParamTable.Rows[i]["initvalue"].ToString().ToLower();
                    optParamHashtable.Add(keyType.ToLower(), keyValue.ToLower());
                }

                if (state == "on")
                {
                    String keyType = "var" + argIndex.ToString() + "lowerbound";
                    String keyValue = optParamTable.Rows[i]["lowerbound"].ToString().ToLower();
                    optParamHashtable.Add(keyType.ToLower(), keyValue.ToLower());

                    keyType = "var" + argIndex.ToString() + "upperbound";
                    keyValue = optParamTable.Rows[i]["upperbound"].ToString().ToLower();
                    optParamHashtable.Add(keyType.ToLower(), keyValue.ToLower());
                    argIndex++;
                }
                if (state == "valueon")
                {
                    String keyType = "fvalueweight" + funIndex.ToString();
                    String keyValue = optParamTable.Rows[i]["initvalue"].ToString().ToLower();
                    optParamHashtable.Add(keyType.ToLower(), keyValue.ToLower());

                    keyType = "fvaluename" + funIndex.ToString();
                    keyValue = optParamTable.Rows[i]["code"].ToString().ToLower();
                    optParamHashtable.Add(keyType.ToLower(), keyValue.ToLower());
                    funIndex++;
                }
                if (state == "constrainvalueon")
                {
                    String keyType = "fconstrainvalueweight" + constrainFunIndex.ToString();
                    String keyValue = optParamTable.Rows[i]["initvalue"].ToString().ToLower();
                    optParamHashtable.Add(keyType.ToLower(), keyValue.ToLower());

                    keyType = "fconstrainvaluename" + constrainFunIndex.ToString();
                    keyValue = optParamTable.Rows[i]["code"].ToString().ToLower();
                    optParamHashtable.Add(keyType.ToLower(), keyValue.ToLower());

                    keyType = "constrain" + constrainFunIndex.ToString() + "upperbound";
                    keyValue = optParamTable.Rows[i]["upperbound"].ToString().ToLower();
                    optParamHashtable.Add(keyType.ToLower(), keyValue.ToLower());

                    constrainFunIndex++;
                }
            }

            Int32 maxFunNum = Convert.ToInt32(optParamHashtable["maxfun"].ToString());
            if (funIndex < maxFunNum)
            {
                optParamHashtable["maxfun"] = funIndex;
            }

            Param = optParamHashtable;
        }
        private void loadParameters()
        {
            if (_paramTable == null)
            {
                // Just to make the code run.
                _paramTable = new Hashtable();
            }
            if (_paramTable.ContainsKey("function"))
            {
                function = Convert.ToInt32(_paramTable["function"].ToString());
            }
            if (_paramTable.ContainsKey("popsize"))
            {
                popsize = Convert.ToInt32(_paramTable["popsize"].ToString());
            }

            if (_paramTable.ContainsKey("maxgen"))
            {
                maxgen = Convert.ToInt32(_paramTable["maxgen"].ToString());
            }

            if (_paramTable.ContainsKey("optimization"))
            {
                optimization = Convert.ToInt32(_paramTable["optimization"].ToString());
            }

            if (_paramTable.ContainsKey("archive_size"))
            {
                archive_size = Convert.ToInt32(_paramTable["archive_size"].ToString());
            }

            if (_paramTable.ContainsKey("maxfun"))
            {
                maxfun = Convert.ToUInt32(_paramTable["maxfun"].ToString());
            }

            if (_paramTable.ContainsKey("verbose"))
            {
                verbose = Convert.ToInt32(_paramTable["verbose"].ToString());
            }

            if (_paramTable.ContainsKey("pmut"))
            {
                pMut = Convert.ToDouble(_paramTable["pmut"].ToString());
            }

            if (_paramTable.ContainsKey("maxvar"))
            {
                maxvar = Convert.ToUInt32(_paramTable["maxvar"].ToString());
            }

            // Now we load the variable bound if any
            if (maxvar > 0)
            {
                varLowerBound = new double[maxvar];
                varUpperBound = new double[maxvar];
            }
            for (Int32 i = 0; i < maxvar; i++)
            {
                String varLBKey = "var" + i.ToString() + "lowerbound";
                String varUBKey = "var" + i.ToString() + "upperbound";

                if (_paramTable.ContainsKey(varLBKey))
                {
                    double lbLocal = Convert.ToDouble(_paramTable[varLBKey.ToLower()].ToString());
                    varLowerBound[i] = lbLocal;
                }
                if (_paramTable.ContainsKey(varUBKey.ToLower()))
                {
                    double ubLocal = Convert.ToDouble(_paramTable[varUBKey.ToLower()].ToString());
                    varUpperBound[i] = ubLocal;
                }
            }

            argLocal = new double[maxvar];
            fiLocal = new double[maxfun];
            objLocal = new object();

            // Now we load the contrain bound if any
            if (_paramTable.ContainsKey("maxcontrains"))
            {
                maxcontrains = Convert.ToUInt32(_paramTable["maxcontrains"].ToString());
            }

            if (maxcontrains > 0)
            {
                constrainsUpperBond = new double[maxcontrains];
            }

            for (Int32 i = 0; i < maxcontrains; i++)
            {
                String constrainUBKey = "constrain" + i.ToString() + "upperbound";

                if (_paramTable.ContainsKey(constrainUBKey.ToLower()))
                {
                    double ubLocal = Convert.ToDouble(_paramTable[constrainUBKey.ToLower()].ToString());
                    constrainsUpperBond[i] = ubLocal;
                }
            }
            constrainsValueLocal = new double[maxcontrains];
        }
        private void myKursawe(double[] arg, double[] fi, object obj)
        {
            double r = 0.0;
            uint j;

            for (j = 0; j < 2; j++)
                r += -10.0 * Math.Exp(-0.2 * Math.Sqrt(Math.Pow(arg[j], 2) + Math.Pow(arg[j + 1], 2)));
            /*
            Double tmp = 0.0;
            Double tmp1 = 0.0;
            for (Int32 i = 0; i < 3; i++)
            {
                if (i < 2)
                {
                    tmp += Math.Exp(-0.2 * Math.Sqrt(arg[i] * arg[i] + arg[i + 1] * arg[i + 1]));
                }
                tmp1 += Math.Pow(Math.Abs(arg[i]), 0.8) + 5.0 * Math.Sin(arg[i]) * Math.Sin(arg[i]) * Math.Sin(arg[i]);
            }
            */

            fi[0] = r;

            r = 0.0;
            for (j = 0; j < 3; j++)
                r += Math.Pow(Math.Abs(arg[j]), 0.8) + 5.0 * Math.Sin(Math.Pow(arg[j], 3));
            fi[1] = r;

        }
        private void myKita(double[] arg, double[] fi, object obj)
        {
            fi[0] = -arg[0] * arg[0] + arg[1];
            fi[1] = arg[0] / 2.0 + arg[1] + 1;

        }
        private void myDeb(double[] arg, double[] fi, object obj)
        {
            fi[0] = arg[0];
            double g = 2.0 - Math.Exp(-Math.Pow(((arg[1] - 0.2) / 0.004), 2)) - 0.8 * Math.Exp(-Math.Pow(((arg[1] - 0.6) / 0.4), 2));

            fi[1] = g / arg[0];

        }
        private void myKitaConstrains(double[] arg, double[] fi, object obj)
        {
            fi[0] = arg[0] / 6.0 + arg[1] - 13.0 / 2.0;
            fi[1] = arg[0] / 2.0 + arg[1] - 15.0 / 2.0;
            fi[2] = arg[0] * 5.0 + arg[1] - 30.0;
        }
        private void myDTLZ6(double[] arg, double[] fi, object obj)
        {
            fi[0] = arg[0];
            fi[1] = arg[1];

            uint j = 0;
            uint n = maxvar;
            uint k = n - maxfun + 1;
            double g, h, s, t;

            s = 0;
            for (j = 2; j < maxvar; j++)
            {
                s += arg[j];
            }

            g = 1 + (9 / 20) * s;

            t = 0;
            for (j = 0; j < maxfun - 1; j++)
            {
                t += (arg[j] * (1 + Math.Sin(3 * PI * arg[j]))) / (1 + g);
            }

            h = 3 - t;

            fi[2] = ((1 + g) * h);

        }
        private void initialize_popG()
        {
            uint i, j;
            for (i = 0; i < popsize; i++)
                for (j = 0; j < maxvar; j++)
                    popVar[i][j] = RandomDouble(varLowerBound[j], varUpperBound[j]);
        }
        private void evaluateG()
        {
            uint i, j;
            for (i = 0; i < popsize; i++)
            {
                for (j = 0; j < maxvar; j++)
                {
                    argLocal[j] = popVar[i][j];
                }

                _funtionToOpt(argLocal, fiLocal, objLocal);

                for (j = 0; j < maxfun; j++)
                {
                    popFit[i][j] = fiLocal[j];
                }
            }
        }
        private uint check_constraintsG(double[] consVar) /* Check for constraint to determine feasibility */
        {
            uint violations = 0;
            if (maxcontrains > 0)
            {
                _funtionToCalConstrains(consVar, constrainsValueLocal, objLocal);

                for (Int32 i = 0; i < maxcontrains; i++)
                {
                    if (constrainsValueLocal[i] > constrainsUpperBond[i])
                    {
                        violations++;
                    }
                }
            }

            return violations;
        }
        private void mutateG(uint t) /* Mutation of particles adapted from MOPSO */
        {
            uint i;
            int dimension = 0;
            //double minvalue[maxvar], maxvalue[maxvar], minvaluetemp, maxvaluetemp, range;
            double valtemp = 0;
            double[] minvalue = varLowerBound;
            double[] maxvalue = varUpperBound;
            double minvaluetemp, maxvaluetemp, range;

            //get_ranges(minvalue, maxvalue);

            for (i = 0; i < popsize; i++)
            {
                if (flip(Math.Pow(1.0 - (double)t / (maxgen * pMut), 1.5)) > 0)
                {
                    dimension = RandomInt(0, maxvar - 1);

                    range = (maxvalue[dimension] - minvalue[dimension]) * Math.Pow(1.0 - (double)t / (maxgen * pMut), 1.5) / 2;

                    valtemp = RandomDouble(range, -range);

                    if (popVar[i][dimension] - range < minvalue[dimension])
                        minvaluetemp = minvalue[dimension];
                    else
                        minvaluetemp = popVar[i][dimension] - range;

                    if (popVar[i][dimension] + range > maxvalue[dimension])
                        maxvaluetemp = maxvalue[dimension];
                    else
                        maxvaluetemp = popVar[i][dimension] + range;

                    popVar[i][dimension] = RandomDouble(minvaluetemp, maxvaluetemp);
                }
            }
        }
        private void update_archiveG()  /* Insert new nondominated particles in pop into archive */
        {
            uint i, j, k, bottom;

            /* for each particle in the population */
            for (k = 0; k < popsize; k++)
            {

                /* if particle in pop is nondominated */
                if (check_nondomG(k) == 1)
                {

                    /* if memory is not yet full, insert particle */
                    if (nondomCtr < archive_size)
                    {
                        i = (uint)nondomCtr;

                        for (j = 0; j < maxvar; j++)
                            archiveVar[i][j] = popVar[k][j];

                        for (j = 0; j < maxfun; j++)
                            archiveFit[i][j] = popFit[k][j];

                        nondomCtr += 1;

                    }
                    else
                    {      /* if memory is full, select particle to replace */
                        /* Crowding distance computation and sorting */
                        crowding();
                        bottom = (uint)((nondomCtr - 1) * .90);
                        i = (uint)RandomInt(bottom, nondomCtr - 1);

                        /* insert new particle to noDom */
                        for (j = 0; j < maxvar; j++)
                            archiveVar[i][j] = popVar[k][j];

                        for (j = 0; j < maxfun; j++)
                            archiveFit[i][j] = popFit[k][j];
                    }
                }
            }
        }
        private uint check_nondomG(uint i) /* Check for feasibility and nondomination of particles in pop and archive */
        {
            uint sum, h = 0, j;
            //double archiveCons[maxvar], popCons[maxvar];

            double[] archiveCons = new double[maxvar];
            double[] popCons = new double[maxvar];

            do
            {
                sum = 0;
                for (j = 0; j < maxvar; j++)
                {
                    archiveCons[j] = archiveVar[h][j];
                    popCons[j] = popVar[i][j];
                }

                /* if particle in archive has lesser contraint violations */
                if (check_constraintsG(archiveCons) < check_constraintsG(popCons))
                    return 0;

                /* if particle in archive has more contraint violations, delete it */
                if (check_constraintsG(archiveCons) > check_constraintsG(popCons))
                {
                    if (nondomCtr > 0)
                    {
                        for (j = 0; j < maxvar; j++)
                            archiveVar[h][j] = archiveVar[nondomCtr - 1][j];

                        for (j = 0; j < maxfun; j++)
                            archiveFit[h][j] = archiveFit[nondomCtr - 1][j];

                        nondomCtr -= 1;
                    }
                }
                else
                {
                    for (j = 0; j < maxfun; j++)
                    {
                        if (((archiveFit[h][j] < popFit[i][j]) && (optimization == 0))
                            || ((archiveFit[h][j] > popFit[i][j]) && (optimization == 1)))
                            sum += 1;
                    }

                    if (sum == maxfun)	/* If particle in archive dominates */
                        return 0;
                    else if (sum == 0)
                    {	/* If particle in archive is dominated, delete it */
                        if (nondomCtr > 0)
                        {
                            for (j = 0; j < maxvar; j++)
                                archiveVar[h][j] = archiveVar[nondomCtr - 1][j];

                            for (j = 0; j < maxfun; j++)
                                archiveFit[h][j] = archiveFit[nondomCtr - 1][j];
                            nondomCtr -= 1;
                        }
                    }
                    else
                    {
                        h += 1;
                    }
                }
            } while (h < nondomCtr);

            return 1;
        }
        private void insert_nondomG() /* Insert nondominated particles in population into the archive */
        {
            uint i, j, k, total, insertFlag, bottom;
            //double archiveCons[maxvar], popCons[maxvar];
            double[] archiveCons = new double[maxvar];
            double[] popCons = new double[maxvar];
            insertFlag = 1000;

            for (i = 0; i < popsize; i++)
            {


                if (nondomCtr == 0)
                { /* if archive is empty */

                    /* Insert particle in pop into archive */
                    for (j = 0; j < maxvar; j++)
                        archiveVar[nondomCtr][j] = popVar[i][j];

                    for (j = 0; j < maxfun; j++)
                        archiveFit[nondomCtr][j] = popFit[i][j];

                    nondomCtr += 1;

                }
                else
                { /* if archive is not empty */

                    insertFlag = 1;

                    /*for each particle in archive	*/
                    for (k = 0; k < nondomCtr; k++)
                    {

                        /* First, check for feasibility */

                        for (j = 0; j < maxvar; j++)
                        {
                            popCons[j] = popVar[i][j];
                            archiveCons[j] = archiveVar[k][j];
                        }

                        /* If both particles are infeasible */
                        if ((check_constraintsG(archiveCons) > 0) && (check_constraintsG(popCons) > 0))
                        {
                            delete_particle(k);           /* Delete particle in archive           */
                            insertFlag = 0;		/* Do not insert particle in pop        */
                            break;
                        }
                        else if (check_constraintsG(popCons) > 0)
                        { /* If particle in pop is infeasible */
                            insertFlag = 0;			   /* Do not insert particle in pop    */
                            break;
                        }
                        else if (check_constraintsG(archiveCons) > 0)
                        { /* If particle in archive is infeasible */
                            delete_particle(k);                          /* Delete particle in archive           */

                            if ((nondomCtr != 0) || (k != nondomCtr - 1))
                                k--;

                            continue;

                        }

                        /* Second, check for domination */
                        total = 0;

                        /* If both are feasible, check for nondomination */

                        for (j = 0; j < maxfun; j++)
                        {
                            if (((popFit[i][j] < archiveFit[k][j]) && (optimization == 0))
                               || (popFit[i][j] > archiveFit[k][j]) && (optimization == 1))
                                total += 1;
                        }

                        if (total == maxfun)   /* If particle in pop dominates     */
                            delete_particle(k); /* Delete particle in archive       */
                        else if (total == 0)
                        {  /* If particle in archive dominates */
                            insertFlag = 0;     /* Do not insert particle in pop    */
                            break;
                        }

                    } /* Finished comparing one particle in pop with particles in archive */
                }

                /* Insert particle in pop if it is feasible and nondominated */
                if (insertFlag == 1)
                {

                    /* If memory is not yet full, insert particle */
                    if (nondomCtr < archive_size)
                    {
                        for (j = 0; j < maxvar; j++)
                            archiveVar[nondomCtr][j] = popVar[i][j];
                        for (j = 0; j < maxfun; j++)
                            archiveFit[nondomCtr][j] = popFit[i][j];
                        nondomCtr += 1;
                    }
                    else
                    {      /* If memory is full, select particle to replace */

                        /* Compute crowding distance values of particles in archive*/
                        crowding();

                        bottom = (uint)((nondomCtr - 1) * 0.90);

                        /* Randomly select which particle from the most areas to replace */
                        int aa = (int)bottom;
                        int bb = (int)(nondomCtr - 1);
                        k = (uint)RandomInt(aa, bb);

                        /* Insert new particle into archive */
                        for (j = 0; j < maxvar; j++)
                            archiveVar[k][j] = popVar[i][j];

                        for (j = 0; j < maxfun; j++)
                            archiveFit[k][j] = popFit[i][j];
                    }
                }
            } /* Finished comparing particles in pop with particles in archive */
        }
        private void maintain_particlesG()  /* Maintain particles in the population within the search space */
        {
            uint i, j;
            //double minvalue[maxvar], maxvalue[maxvar];

            double[] minvalue = varLowerBound;
            double[] maxvalue = varUpperBound;


            //return; 
            /* This statement checks the stability of the swarm by allowing particles to fly past their boundaries */
            /* Stable swarms do not explode even without boundary constraints.  */
            /* Comment this out if you are not happy with this type of checking */

            for (i = 0; i < popsize; i++)
            {
                for (j = 0; j < maxvar; j++)
                {

                    /* If particle goes beyond minimum range value */
                    if (popVar[i][j] < minvalue[j])
                    {

                        /* Set it to minimum range value */
                        popVar[i][j] = minvalue[j];

                        /* Change to opposite direction */
                        velocity[i][j] = -velocity[i][j];

                    }

                    /* If particle goes beyond maximum range value */
                    if (popVar[i][j] > maxvalue[j])
                    {
                        /* Set it to maximum range value */
                        popVar[i][j] = maxvalue[j];

                        /* Change to opposite direction */
                        velocity[i][j] = -velocity[i][j];

                    }
                }
            }
        }

        //[DllImport("msvcrt.dll")]
        //private static extern int srand(int seed);
        int srand(int seed)
        {
            random = new Random(seed);
            return seed;
        }

        //[DllImport("msvcrt.dll")]
        //private static extern int rand();
        int rand()
        {
            return random.Next();
        }

        // Original methods
        double kita_f1(uint i)
        {
            return (-(popVar[i][0] * popVar[i][0]) + popVar[i][1]);
        }
        double kita_f2(uint i)
        {
            return ((popVar[i][0] / 2.0) + popVar[i][1] + 1);
        }
        double kursawe_f1(uint i)
        {
            double r = 0.0;
            uint j;

            for (j = 0; j < 2; j++)
                r += -10.0 * Math.Exp(-0.2 * Math.Sqrt(Math.Pow(popVar[i][j], 2) + Math.Pow(popVar[i][j + 1], 2)));

            return r;
        }
        double kursawe_f2(uint i)
        {
            double r = 0.0;
            uint j;

            for (j = 0; j < 3; j++)
                r += Math.Pow(Math.Abs(popVar[i][j]), 0.8) + 5.0 * Math.Sin(Math.Pow(popVar[i][j], 3));
            return r;
        }
        double deb_f1(uint i)
        {
            return (popVar[i][0]);
        }
        double deb_f2(uint i)
        {
            double g = 2.0 - Math.Exp(-Math.Pow(((popVar[i][1] - 0.2) / 0.004), 2)) - 0.8 * Math.Exp(-Math.Pow(((popVar[i][1] - 0.6) / 0.4), 2));

            return ((double)g / popVar[i][0]);
        }
        double DTLZ6_f1(uint i)
        {
            return (popVar[i][0]);
        }
        double DTLZ6_f2(uint i)
        {
            return (popVar[i][1]);
        }
        double DTLZ6_f3(uint i)
        {
            uint j = 0;
            uint n = maxvar;
            uint k = n - maxfun + 1;
            double g, h, s, t;

            s = 0;
            for (j = 2; j < maxvar; j++)
            {
                s += popVar[i][j];
            }

            g = 1 + (9 / 20) * s;

            t = 0;
            for (j = 0; j < maxfun - 1; j++)
            {
                t += (popVar[i][j] * (1 + Math.Sin(3 * PI * popVar[i][j]))) / (1 + g);
            }

            h = 3 - t;

            return ((1 + g) * h);
        }

        // Original methods
        private void initialize_rand()
        {
            uint i, j;
            DateTime timeOrigin = new DateTime(1970, 1, 1, 0, 0, 0);
            int totalSec = MiscUtility.getTimeSpanInSeconds(timeOrigin, DateTime.Now);
            totalSec = 1;
            //srand((uint)time((time_t *)NULL));
            srand(totalSec);
            i = (uint)(31329.0 * rand() / (32767 + 1.0));
            j = (uint)(30082.0 * rand() / (32767 + 1.0));

            RandomInitialise((int)i, (int)j);
        }
        void initialize_pop() /* Initialize population variables */
        {
            uint i, j;

            switch (function)
            {
                case 100: /* Kita test function*/
                    for (i = 0; i < popsize; i++)
                        for (j = 0; j < maxvar; j++)
                            popVar[i][j] = RandomDouble(0.0, 7.0);
                    break;

                case 200: /* Kursawe test function */
                    for (i = 0; i < popsize; i++)
                        for (j = 0; j < maxvar; j++)
                            popVar[i][j] = RandomDouble(-5.0, 5.0);
                    break;

                case 300: /* Deb test function */
                    for (i = 0; i < popsize; i++)
                        for (j = 0; j < maxvar; j++)
                            popVar[i][j] = RandomDouble(0.1, 1.0);//0.8191);
                    break;

                case 500: /* DTLZ6 test function */
                    for (i = 0; i < popsize; i++)
                        for (j = 0; j < maxvar; j++)
                            popVar[i][j] = RandomDouble(0.0, 1.0);
                    break;

                /** Add and initialize your test functions here  ***/

            }
        }
        void initialize_vel() /* Initialize population velocity to zero */
        {
            uint i, j;

            for (i = 0; i < popsize; i++)
                for (j = 0; j < maxvar; j++)
                    velocity[i][j] = 0.0;

        }
        void evaluate() /* Evaluate particles in population */
        {
            uint i, j;

            for (i = 0; i < popsize; i++)
            {
                for (j = 0; j < maxfun; j++)
                {

                    switch (function + j)
                    {
                        case 100:	/* Kita's first objective function */
                            popFit[i][j] = kita_f1(i);
                            break;

                        case 101:	/* Kita's second objective function */
                            popFit[i][j] = kita_f2(i);
                            break;

                        case 200:	/* Kursawe's first objective function */
                            popFit[i][j] = kursawe_f1(i);
                            break;

                        case 201:	/* Kursawe's second objective function */
                            popFit[i][j] = kursawe_f2(i);
                            break;

                        case 300:	/* Deb's first objective function */
                            popFit[i][j] = deb_f1(i);
                            break;

                        case 301:	/* Deb's second objective function */
                            popFit[i][j] = deb_f2(i);
                            break;

                        case 500:	/* DTLZ6's first objective function */
                            popFit[i][j] = DTLZ6_f1(i);
                            break;

                        case 501:	/* DTLZ6's second objective function */
                            popFit[i][j] = DTLZ6_f2(i);
                            break;

                        case 502:	/* DTLZ1's third objective function */
                            popFit[i][j] = DTLZ6_f3(i);
                            break;

                        /** Add your test function here **/

                    } /* end of switch */
                }
            }
        }
        void store_pbests() /* Store personal bests (both variable and fitness values) of particles */
        {
            uint i, j;

            /* Store variable values of personal bests */
            for (i = 0; i < popsize; i++)
                for (j = 0; j < maxvar; j++)
                    pbestsVar[i][j] = popVar[i][j];

            /* Store fitness values of personal bests */
            for (i = 0; i < popsize; i++)
                for (j = 0; j < maxfun; j++)
                    pbestsFit[i][j] = popFit[i][j];

        }
        void insert_nondom() /* Insert nondominated particles in population into the archive */
        {
            uint i, j, k, total, insertFlag, bottom;
            //double archiveCons[maxvar], popCons[maxvar];
            double[] archiveCons = new double[maxvar];
            double[] popCons = new double[maxvar];
            insertFlag = 1000;

            for (i = 0; i < popsize; i++)
            {


                if (nondomCtr == 0)
                { /* if archive is empty */

                    /* Insert particle in pop into archive */
                    for (j = 0; j < maxvar; j++)
                        archiveVar[nondomCtr][j] = popVar[i][j];

                    for (j = 0; j < maxfun; j++)
                        archiveFit[nondomCtr][j] = popFit[i][j];

                    nondomCtr += 1;

                }
                else
                { /* if archive is not empty */

                    insertFlag = 1;

                    /*for each particle in archive	*/
                    for (k = 0; k < nondomCtr; k++)
                    {

                        /* First, check for feasibility */

                        for (j = 0; j < maxvar; j++)
                        {
                            popCons[j] = popVar[i][j];
                            archiveCons[j] = archiveVar[k][j];
                        }

                        /* If both particles are infeasible */
                        if ((check_constraints(archiveCons) > 0) && (check_constraints(popCons) > 0))
                        {
                            delete_particle(k);           /* Delete particle in archive           */
                            insertFlag = 0;		/* Do not insert particle in pop        */
                            break;
                        }
                        else if (check_constraints(popCons) > 0)
                        { /* If particle in pop is infeasible */
                            insertFlag = 0;			   /* Do not insert particle in pop    */
                            break;
                        }
                        else if (check_constraints(archiveCons) > 0)
                        { /* If particle in archive is infeasible */
                            delete_particle(k);                          /* Delete particle in archive           */

                            if ((nondomCtr != 0) || (k != nondomCtr - 1))
                                k--;

                            continue;

                        }

                        /* Second, check for domination */
                        total = 0;

                        /* If both are feasible, check for nondomination */

                        for (j = 0; j < maxfun; j++)
                        {
                            if (((popFit[i][j] < archiveFit[k][j]) && (optimization == 0))
                               || (popFit[i][j] > archiveFit[k][j]) && (optimization == 1))
                                total += 1;
                        }

                        if (total == maxfun)   /* If particle in pop dominates     */
                            delete_particle(k); /* Delete particle in archive       */
                        else if (total == 0)
                        {  /* If particle in archive dominates */
                            insertFlag = 0;     /* Do not insert particle in pop    */
                            break;
                        }

                    } /* Finished comparing one particle in pop with particles in archive */
                }

                /* Insert particle in pop if it is feasible and nondominated */
                if (insertFlag == 1)
                {

                    /* If memory is not yet full, insert particle */
                    if (nondomCtr < archive_size)
                    {
                        for (j = 0; j < maxvar; j++)
                            archiveVar[nondomCtr][j] = popVar[i][j];
                        for (j = 0; j < maxfun; j++)
                            archiveFit[nondomCtr][j] = popFit[i][j];
                        nondomCtr += 1;
                    }
                    else
                    {      /* If memory is full, select particle to replace */

                        /* Compute crowding distance values of particles in archive*/
                        crowding();

                        bottom = (uint)((nondomCtr - 1) * 0.90);

                        /* Randomly select which particle from the most areas to replace */
                        int aa = (int)bottom;
                        int bb = (int)(nondomCtr - 1);
                        k = (uint)RandomInt(aa, bb);

                        /* Insert new particle into archive */
                        for (j = 0; j < maxvar; j++)
                            archiveVar[k][j] = popVar[i][j];

                        for (j = 0; j < maxfun; j++)
                            archiveFit[k][j] = popFit[i][j];
                    }
                }
            } /* Finished comparing particles in pop with particles in archive */
        }
        void delete_particle(uint k) /* Delete particle in archive */
        {
            uint j;

            /* if infeasible particle is the last in archive or only one particle in archive */
            if ((nondomCtr == 1) || (k == (nondomCtr - 1)))
            {

                nondomCtr -= 1;

            }
            else
            {       /* move last particle in archive in place of infeasible particle	*/

                for (j = 0; j < maxvar; j++)
                    archiveVar[k][j] = archiveVar[nondomCtr - 1][j];

                for (j = 0; j < maxfun; j++)
                    archiveFit[k][j] = archiveFit[nondomCtr - 1][j];

                nondomCtr -= 1;
            }
        }
        uint check_constraints(double[] consVar) /* Check for constraint to determine feasibility */
        {
            uint violations = 0;

            switch (function)
            {

                case 100: /* Kita test function */
                    if (0 < (double)(consVar[0] / 6.0 + consVar[1] - 13.0 / 2.0))
                        violations++;
                    if (0 < (double)(consVar[0] / 2.0 + consVar[1] - 15.0 / 2.0))
                        violations++;
                    if (0 < (double)(5.0 * consVar[0] + consVar[1] - 30.0))
                        violations++;

                    return violations;

                /** Add test function constraints, if any, here! **/

                default:
                    return 0;
            }
        }
        void crowding() /* Computes crowding distance values of particles in archive */
        {
            uint i, f, begin;

            /* initialize crowding distance values */
            //for(i=0; i <= nondomCtr; i++)
            for (i = 0; i <= nondomCtr; i++)
            {
                //if (i < archive_size)
                {
                    crowdDist[i] = 0;
                }
            }

            for (f = 0; f < maxfun; f++)
            {
                begin = 0;
                /* Sort fitness values */
                qsortFitness(f, begin, (uint)nondomCtr);

                /* Compute crowding distance */
                compute_distance(f);
            }

            /* Sort crowding distance values */
            begin = 0;
            qsortCrowd(begin, (uint)nondomCtr);

        }
        void qsortFitness(uint f, uint begin, uint lastPart) /* Sort fitness values of particles in archive */
        {
            uint l = begin + 1;
            uint r = lastPart;
            double pivot = archiveFit[begin][f];

            uint k;
            //double tempF[maxfun], tempP[maxvar], temp;
            double[] tempF = new double[maxfun];
            double[] tempP = new double[maxvar];
            double temp;

            while (l < r)
            {
                if (archiveFit[l][f] <= pivot)
                {
                    l++;
                }
                else
                {

                    r--;

                    /* swap */
                    /* Exchange fitness positions of two particles in the archiveFit */
                    for (k = 0; k < maxfun; k++)
                    {
                        tempF[k] = archiveFit[l][k];
                        archiveFit[l][k] = archiveFit[r][k];
                    }

                    for (k = 0; k < maxfun; k++)
                        archiveFit[r][k] = tempF[k];

                    /* Also exchange particle positions in archiveVar */
                    for (k = 0; k < maxvar; k++)
                    {
                        tempP[k] = archiveVar[l][k];
                        archiveVar[l][k] = archiveVar[r][k];
                    }

                    for (k = 0; k < maxvar; k++)
                        archiveVar[r][k] = tempP[k];

                    /* Also exchange their crowding distance */
                    temp = crowdDist[l];
                    crowdDist[l] = crowdDist[r];
                    crowdDist[r] = temp;
                }
            }

            l--;

            /* Exchange fitness positions of two particles in the array archiveFit */
            for (k = 0; k < maxfun; k++)
            {
                tempF[k] = archiveFit[begin][k];
                archiveFit[begin][k] = archiveFit[l][k];
            }

            for (k = 0; k < maxfun; k++)
                archiveFit[l][k] = tempF[k];

            /* Also exchange particle positions in archiveVar */
            for (k = 0; k < maxvar; k++)
            {
                tempP[k] = archiveVar[begin][k];
                archiveVar[begin][k] = archiveVar[l][k];
            }

            for (k = 0; k < maxvar; k++)
                archiveVar[l][k] = tempP[k];

            /* Also exchange their crowding distance */
            temp = crowdDist[begin];
            crowdDist[begin] = crowdDist[l];
            crowdDist[l] = temp;

            if (l - begin > 1)
                qsortFitness(f, begin, l);

            if (lastPart - r > 1)
                qsortFitness(f, r, lastPart);
        }
        void compute_distance(uint f) /* Compute the crowding distance of each particle in noDomF */
        {
            uint i, max;

            max = 1;
            for (i = 1; i < nondomCtr - 1; i++)
            {
                crowdDist[i] = crowdDist[i] + (archiveFit[i + 1][f] - archiveFit[i - 1][f]);

                if (crowdDist[max] < crowdDist[i])
                    max = i;
            }

            /* give maximum crowding distance value to the boundary points so that they are always selected */
            crowdDist[0] = crowdDist[0] + crowdDist[max];
            crowdDist[nondomCtr - 1] = crowdDist[nondomCtr - 1] + crowdDist[max];

        }
        void qsortCrowd(uint begin, uint lastPart) /* Sort crowding distance values */
        {
            uint l = begin + 1;
            uint r = lastPart;
            double pivot = crowdDist[begin];

            uint k;
            //double temp, tempP[maxvar], tempF[maxfun];
            double temp;
            double[] tempP = new double[maxvar];
            double[] tempF = new double[maxfun];

            while (l < r)
            {

                if (crowdDist[l] >= pivot)
                {
                    l++;
                }
                else
                {

                    r--;

                    /* exchange their crowding distance values */
                    temp = crowdDist[l];
                    crowdDist[l] = crowdDist[r];
                    crowdDist[r] = temp;

                    /* Exchange fitness positions of two particles in the array archiveFit */
                    for (k = 0; k < maxfun; k++)
                    {
                        tempF[k] = archiveFit[l][k];
                        archiveFit[l][k] = archiveFit[r][k];
                    }

                    for (k = 0; k < maxfun; k++)
                        archiveFit[r][k] = tempF[k];

                    /* Also exchange particle positions in archiveVar */
                    for (k = 0; k < maxvar; k++)
                    {
                        tempP[k] = archiveVar[l][k];
                        archiveVar[l][k] = archiveVar[r][k];
                    }

                    for (k = 0; k < maxvar; k++)
                        archiveVar[r][k] = tempP[k];
                }
            }

            l--;

            /* Exchange fitness positions of two particles in the array archiveVar */
            for (k = 0; k < maxfun; k++)
            {
                tempF[k] = archiveFit[begin][k];
                archiveFit[begin][k] = archiveFit[l][k];
            }

            for (k = 0; k < maxfun; k++)
                archiveFit[l][k] = tempF[k];

            /* Also exchange particle positions in archiveVar */
            for (k = 0; k < maxvar; k++)
            {
                tempP[k] = archiveVar[begin][k];
                archiveVar[begin][k] = archiveVar[l][k];
            }

            for (k = 0; k < maxvar; k++)
                archiveVar[l][k] = tempP[k];

            /* Also exchange their crowding distance */
            temp = crowdDist[begin];
            crowdDist[begin] = crowdDist[l];
            crowdDist[l] = temp;

            if (l - begin > 1)
                qsortCrowd(begin, l);

            if (lastPart - r > 1)
                qsortCrowd(r, lastPart);
        }
        void compute_velocity() /* Compute new velocity of each particle in the population */
        {
            uint top, i, j, gBest;

            top = (uint)((nondomCtr - 1) * 0.10);

            for (i = 0; i < popsize; i++)
            {
                gBest = (uint)RandomInt(0, top);

                for (j = 0; j < maxvar; j++)
                    velocity[i][j] = 0.4 * velocity[i][j] + 1.0 * RandomDouble(0.0, 1.0) * (pbestsVar[i][j] - popVar[i][j]) + 1.0 * RandomDouble(0.0, 1.0) * (archiveVar[gBest][j] - popVar[i][j]);
                /* W  * Vi             + C1  * RandomDouble(0.0, 1.0) * (pBest           -           Xi) + C2  * RandomDouble(0.0, 1.0) * (gBest                -    Xi) */
            }

            /* Calculate new positions of particles */
            for (i = 0; i < popsize; i++)
                for (j = 0; j < maxvar; j++)
                    popVar[i][j] = popVar[i][j] + velocity[i][j];
        }
        void mutate(uint t) /* Mutation of particles adapted from MOPSO */
        {
            uint i;
            int dimension = 0;
            //double minvalue[maxvar], maxvalue[maxvar], minvaluetemp, maxvaluetemp, range;
            double valtemp = 0;
            double[] minvalue = new double[maxvar];
            double[] maxvalue = new double[maxvar];
            double minvaluetemp, maxvaluetemp, range;

            get_ranges(minvalue, maxvalue);

            for (i = 0; i < popsize; i++)
            {
                if (flip(Math.Pow(1.0 - (double)t / (maxgen * pMut), 1.5)) > 0)
                {
                    dimension = RandomInt(0, maxvar - 1);

                    range = (maxvalue[dimension] - minvalue[dimension]) * Math.Pow(1.0 - (double)t / (maxgen * pMut), 1.5) / 2;

                    valtemp = RandomDouble(range, -range);

                    if (popVar[i][dimension] - range < minvalue[dimension])
                        minvaluetemp = minvalue[dimension];
                    else
                        minvaluetemp = popVar[i][dimension] - range;

                    if (popVar[i][dimension] + range > maxvalue[dimension])
                        maxvaluetemp = maxvalue[dimension];
                    else
                        maxvaluetemp = popVar[i][dimension] + range;

                    popVar[i][dimension] = RandomDouble(minvaluetemp, maxvaluetemp);
                }
            }
        }
        void update_archive()  /* Insert new nondominated particles in pop into archive */
        {
            uint i, j, k, bottom;

            /* for each particle in the population */
            for (k = 0; k < popsize; k++)
            {

                /* if particle in pop is nondominated */
                if (check_nondom(k) == 1)
                {

                    /* if memory is not yet full, insert particle */
                    if (nondomCtr < archive_size)
                    {
                        i = (uint)nondomCtr;

                        for (j = 0; j < maxvar; j++)
                            archiveVar[i][j] = popVar[k][j];

                        for (j = 0; j < maxfun; j++)
                            archiveFit[i][j] = popFit[k][j];

                        nondomCtr += 1;

                    }
                    else
                    {      /* if memory is full, select particle to replace */
                        /* Crowding distance computation and sorting */
                        crowding();
                        bottom = (uint)((nondomCtr - 1) * .90);
                        i = (uint)RandomInt(bottom, nondomCtr - 1);

                        /* insert new particle to noDom */
                        for (j = 0; j < maxvar; j++)
                            archiveVar[i][j] = popVar[k][j];

                        for (j = 0; j < maxfun; j++)
                            archiveFit[i][j] = popFit[k][j];
                    }
                }
            }
        }
        uint check_nondom(uint i) /* Check for feasibility and nondomination of particles in pop and archive */
        {
            uint sum, h = 0, j;
            //double archiveCons[maxvar], popCons[maxvar];

            double[] archiveCons = new double[maxvar];
            double[] popCons = new double[maxvar];

            do
            {
                sum = 0;
                for (j = 0; j < maxvar; j++)
                {
                    archiveCons[j] = archiveVar[h][j];
                    popCons[j] = popVar[i][j];
                }

                /* if particle in archive has lesser contraint violations */
                if (check_constraints(archiveCons) < check_constraints(popCons))
                    return 0;

                /* if particle in archive has more contraint violations, delete it */
                if (check_constraints(archiveCons) > check_constraints(popCons))
                {
                    for (j = 0; j < maxvar; j++)
                        archiveVar[h][j] = archiveVar[nondomCtr - 1][j];

                    for (j = 0; j < maxfun; j++)
                        archiveFit[h][j] = archiveFit[nondomCtr - 1][j];

                    nondomCtr -= 1;
                }
                else
                {
                    for (j = 0; j < maxfun; j++)
                    {
                        if (((archiveFit[h][j] < popFit[i][j]) && (optimization == 0))
                            || ((archiveFit[h][j] > popFit[i][j]) && (optimization == 1)))
                            sum += 1;
                    }

                    if (sum == maxfun)	/* If particle in archive dominates */
                        return 0;
                    else if (sum == 0)
                    {	/* If particle in archive is dominated, delete it */
                        for (j = 0; j < maxvar; j++)
                            archiveVar[h][j] = archiveVar[nondomCtr - 1][j];

                        for (j = 0; j < maxfun; j++)
                            archiveFit[h][j] = archiveFit[nondomCtr - 1][j];
                        nondomCtr -= 1;
                    }
                    else
                    {
                        h += 1;
                    }
                }
            } while (h < nondomCtr);

            return 1;
        }
        void get_ranges(double[] minvalue, double[] maxvalue) /* Get range values of variables */
        {
            uint i;

            switch (function)
            {
                case 100:	/* Kita test function */
                    for (i = 0; i < maxvar; i++)
                    {
                        minvalue[i] = 0.0;
                        maxvalue[i] = 7.0;
                    }
                    break;

                case 200:   /* Kursawe test function */
                    for (i = 0; i < maxvar; i++)
                    {
                        minvalue[i] = -5.0;
                        maxvalue[i] = 5.0;
                    }
                    break;

                case 300:	/* Deb test function */
                    for (i = 0; i < maxvar; i++)
                    {
                        minvalue[i] = 0.1;
                        maxvalue[i] = 1.0;//0.8191; 
                    }
                    break;

                case 500:	/* DTLZ6 test function */
                    for (i = 0; i < maxvar; i++)
                    {
                        minvalue[i] = 0.0;
                        maxvalue[i] = 1.0;
                    }
                    break;

            }
        }
        void maintain_particles()  /* Maintain particles in the population within the search space */
        {
            uint i, j;
            //double minvalue[maxvar], maxvalue[maxvar];
            double[] minvalue = new double[maxvar];
            double[] maxvalue = new double[maxvar];


            //return; 
            /* This statement checks the stability of the swarm by allowing particles to fly past their boundaries */
            /* Stable swarms do not explode even without boundary constraints.  */
            /* Comment this out if you are not happy with this type of checking */

            switch (function)
            {
                case 100: /* Kita test function */
                    for (i = 0; i < maxvar; i++)
                    {
                        minvalue[i] = 0.0;
                        maxvalue[i] = 7.0;
                    }
                    break;

                case 200: /* Kursawe test function */
                    for (i = 0; i < maxvar; i++)
                    {
                        minvalue[i] = -5.0;
                        maxvalue[i] = 5.0;
                    }
                    break;

                case 300: /* Deb test function */
                    for (i = 0; i < maxvar; i++)
                    {
                        minvalue[i] = 0.1;
                        maxvalue[i] = 1.0;//0.8191;
                    }
                    break;

                case 500: /* DTLZ6 test function */
                    for (i = 0; i < maxvar; i++)
                    {
                        minvalue[i] = 0.0;
                        maxvalue[i] = 1.0;
                    }
                    break;

                /** Add boundary constraints here! **/

            }

            for (i = 0; i < popsize; i++)
            {
                for (j = 0; j < maxvar; j++)
                {

                    /* If particle goes beyond minimum range value */
                    if (popVar[i][j] < minvalue[j])
                    {

                        /* Set it to minimum range value */
                        popVar[i][j] = minvalue[j];

                        /* Change to opposite direction */
                        velocity[i][j] = -velocity[i][j];

                    }

                    /* If particle goes beyond maximum range value */
                    if (popVar[i][j] > maxvalue[j])
                    {
                        /* Set it to maximum range value */
                        popVar[i][j] = maxvalue[j];

                        /* Change to opposite direction */
                        velocity[i][j] = -velocity[i][j];

                    }
                }
            }


        }
        void update_pbests() /* Update personal bests of particles in the population */
        {
            uint i, j, sum, better;

            for (i = 0; i < popsize; i++)
            {
                sum = 0;
                for (j = 0; j < maxfun; j++)
                {
                    if (((popFit[i][j] < pbestsFit[i][j]) && (optimization == 0))
                    || ((popFit[i][j] > pbestsFit[i][j]) && (optimization == 1)))
                        sum += 1;
                }

                if (sum == maxfun)
                {
                    better = 0;
                }
                else
                {
                    if (sum == 0)
                        better = 1;
                    else
                        better = (uint)RandomInt(0, 1);
                }

                if (better == 0)
                {
                    for (j = 0; j < maxfun; j++)
                        pbestsFit[i][j] = popFit[i][j];
                    for (j = 0; j < maxvar; j++)
                        pbestsVar[i][j] = popVar[i][j];
                }
            }
        }
        void save_results(string archiveName)  /* Write results to file */
        {

            /*
            uint i, j;
            FILE *fp;

            fp = fopen(archiveName, "w");
        	
            for(i = 0; i < nondomCtr; i++) {
                for(j = 0; j < maxfun; j++)
                fprintf(fp, "%.6f ", archiveFit[i][j]);		      
                fprintf(fp, "\n");
            }
        	
            fclose(fp);
            */

            StreamWriter sw = new StreamWriter(archiveName, false, Encoding.GetEncoding("GB18030"));
            for (uint i = 0; i < nondomCtr; i++)
            {
                for (uint j = 0; j < maxfun; j++)
                {
                    sw.Write(archiveFit[i][j]);
                    sw.Write(" ");
                }
                sw.Write(sw.NewLine);
            }
            sw.Close();
        }
        public int mainfunc()
        {

            Initialization();
            //char archiveName[20];
            String archiveName;
            uint i, j, t;
            //clock_t  startTime, endTime;
            DateTime startTime, endTime;
            double duration, clocktime;
            //FILE *outfile,*plotfile;

            PI = 4.0 * Math.Atan(1.0);

            //sprintf(archiveName,"archive.out");
            archiveName = "archive.out";
            //outfile = fopen("output.out","w");
            //plotfile = fopen("plot.out","w");
            StreamWriter swoutfile = new StreamWriter("output.out", false, Encoding.GetEncoding("GB18030"));
            StreamWriter swplotfile = new StreamWriter("plot.out", false, Encoding.GetEncoding("GB18030"));
            StreamWriter swstdout = new StreamWriter("stdout.out", false, Encoding.GetEncoding("GB18030"));

            /* Initialize random number generator */
            initialize_rand();

            startTime = DateTime.Now;

            /* Initialize generation counter */
            t = 0;

            /* Initialize population with random values */
            initialize_pop();

            /* Initialize velocity */
            initialize_vel();

            /* Evaluate particles in population */
            evaluate();

            /* Store initial personal bests (both variable and fitness values) of particles */
            store_pbests();

            /* Insert nondominated particles in population into the archive */
            insert_nondom();

            /******* MAIN LOOP *********/
            while (t <= maxgen)
            {

                //clocktime = (clock() - startTime)/(double)CLOCKS_PER_SEC;
                if (verbose > 0 && t % printevery == 0 || t == maxgen)
                {
                    //fprintf(stdout,"Generation %d Time: %.2f sec\n",t,clocktime);
                    //fflush(stdout);
                }

                if (t % printevery == 0 || t == maxgen)
                {
                    //fprintf(outfile,"Generation %d Time: %.2f sec\n",t,clocktime);
                }

                /* Compute crowding distance of each particle in the archive */
                /* Only when there are at least 3 particles in the archive */
                if (nondomCtr > 2)
                    crowding();

                /* Compute new velocity of each particle in the population */
                compute_velocity();

                /* Maintain particles in the population within the search space */
                maintain_particles();

                /* Mutate particles in the population */
                if (t < maxgen * pMut)
                    mutate(t);

                /* Evaluate particles in the population */
                evaluate();

                /* Insert new nondominated particles in pop into archive */
                update_archive();

                /* Update personal bests of particles in the population */
                update_pbests();

                /* Print Best So Far */
                if (t % printevery == 0 || t == maxgen)
                {
                    //fprintf(outfile, "Size of Pareto Set: %d\n", nondomCtr);
                    swoutfile.Write("Size of Pareto Set: " + nondomCtr.ToString());
                    swoutfile.Write(swoutfile.NewLine);
                    for (i = 0; i < nondomCtr; i++)
                    {
                        //fprintf(outfile, "Function Values: ");
                        swoutfile.Write("Function Values: ");
                        for (j = 0; j < maxfun; j++)
                        {
                            //fprintf(outfile, "%.6f ", archiveFit[i][j]);
                            swoutfile.Write(archiveFit[i][j]);
                            swoutfile.Write(" ");

                        }
                        swoutfile.Write(swoutfile.NewLine);

                        //fprintf(outfile, "\n");

                        for (j = 0; j < maxvar; j++)
                        {
                            //fprintf(outfile, "%.6f ", archiveVar[i][j]);
                            swoutfile.Write(archiveVar[i][j]);
                            swoutfile.Write(" ");
                        }
                        swoutfile.Write(swoutfile.NewLine);


                        //fprintf(outfile, "\n");
                    }
                    //fprintf(outfile, "\n\n");
                    swoutfile.Write(swoutfile.NewLine);
                    //fflush(outfile);
                    swoutfile.Flush();
                }

                if (t == maxgen)
                {
                    //fprintf(plotfile, "# GNU Plot\n");
                    swplotfile.Write("# GNU Plot");
                    swplotfile.Write(swplotfile.NewLine);
                    for (i = 0; i < nondomCtr; i++)
                    {
                        for (j = 0; j < maxfun; j++)
                        {
                            //fprintf(plotfile, "%.4f ", archiveFit[i][j]);
                            swplotfile.Write(archiveFit[i][j]);
                            swplotfile.Write(" ");
                        }
                        swplotfile.Write(swplotfile.NewLine);
                        //fprintf(plotfile, "\n");
                    }
                    //fflush(plotfile);
                    swplotfile.Flush();
                }


                /* Increment generation counter */
                t++;

            }

            /* Write results to file */

            save_results(archiveName);

            /* Compute time duration */
            endTime = DateTime.Now;
            //duration = ( endTime - startTime ) / (double)CLOCKS_PER_SEC;
            //fprintf(stdout, "%lf sec\n", duration);

            //fclose(outfile);
            //fclose(plotfile);
            swoutfile.Close();
            swplotfile.Close();

            //return EXIT_SUCCESS;
            return 1;
        }

        int FALSE = 0;
        int TRUE = 1;


        /* Globals */
        double[] u = new double[97];
        double c, cd, cm;
        int i97, j97;
        static int test = 0;

        void RandomInitialise(int ij, int kl)
        {
            double s, t;
            int ii, i, j, k, l, jj, m;

            /*
               Handle the seed range errors
                  First random number seed must be between 0 and 31328
                  Second seed must have a value between 0 and 30081
            */
            if (ij < 0 || ij > 31328 || kl < 0 || kl > 30081)
            {
                ij = 1802;
                kl = 9373;
            }

            i = (ij / 177) % 177 + 2;
            j = (ij % 177) + 2;
            k = (kl / 169) % 178 + 1;
            l = (kl % 169);

            for (ii = 0; ii < 97; ii++)
            {
                s = 0.0;
                t = 0.5;
                for (jj = 0; jj < 24; jj++)
                {
                    m = (((i * j) % 179) * k) % 179;
                    i = j;
                    j = k;
                    k = m;
                    l = (53 * l + 1) % 169;
                    if (((l * m % 64)) >= 32)
                        s += t;
                    t *= 0.5;
                }
                u[ii] = s;
            }

            c = 362436.0 / 16777216.0;
            cd = 7654321.0 / 16777216.0;
            cm = 16777213.0 / 16777216.0;
            i97 = 97;
            j97 = 33;
            test = TRUE;
        }
        double RandomUniform()
        {
            double uni;

            /* Make sure the initialisation routine has been called */
            //if (!test)
            if (test == 0)
                RandomInitialise(1802, 9373);

            uni = u[i97 - 1] - u[j97 - 1];
            if (uni <= 0.0)
                uni++;
            u[i97 - 1] = uni;
            i97--;
            if (i97 == 0)
                i97 = 97;
            j97--;
            if (j97 == 0)
                j97 = 97;
            c -= cd;
            if (c < 0.0)
                c += cm;
            uni -= c;
            if (uni < 0.0)
                uni++;

            return (uni);
        }
        double RandomGaussian(double mean, double stddev)
        {
            double q, u, v, x, y;

            /*
               Generate P = (u,v) uniform in rect. enclosing acceptance region
               Make sure that any random numbers <= 0 are rejected, since
               gaussian() requires uniforms > 0, but RandomUniform() delivers >= 0.
            */
            do
            {
                u = RandomUniform();
                v = RandomUniform();
                if (u <= 0.0 || v <= 0.0)
                {
                    u = 1.0;
                    v = 1.0;
                }
                v = 1.7156 * (v - 0.5);

                /*  Evaluate the quadratic form */
                x = u - 0.449871;
                y = Math.Abs(v) + 0.386595;
                q = x * x + y * (0.19600 * y - 0.25472 * x);

                /* Accept P if inside inner ellipse */
                if (q < 0.27597)
                    break;

                /*  Reject P if outside outer ellipse, or outside acceptance region */
            } while ((q > 0.27846) || (v * v > -4.0 * Math.Log(u) * u * u));

            /*  Return ratio of P's coordinates as the normal deviate */
            return (mean + stddev * v / u);
        }
        int RandomInt(int lower, int upper)
        {
            return ((int)(RandomUniform() * (upper - lower + 1)) + lower);
        }
        int RandomInt(uint lower, uint upper)
        {
            return RandomInt((int)lower, (int)upper);
        }
        int RandomInt(int lower, uint upper)
        {
            return RandomInt((int)lower, (int)upper);
        }
        int RandomInt(uint lower, int upper)
        {
            return RandomInt((int)lower, (int)upper);
        }
        double RandomDouble(double lower, double upper)
        {
            return ((upper - lower) * RandomUniform() + lower);
        }
        int flip(double pf)
        {
            if (RandomDouble(0.0, 1.0) <= pf) return 1; else return 0;
        }

        static readonly object _locker = new object();
        // Original variable
        private Int32 function = 500;      /* set functions code                          */
        private Int32 popsize = 100;       /* set number of particles in the population   */
        private Int32 maxgen = 100;        /* set maximum number of generations           */
        private Int32 optimization = 0;	    /* set optimization type, 0 for min, 1 for max */
        private Int32 archive_size = 500;  /* set capacity of archive                     */
        private uint maxfun = 3;          /* set maximum number of objective functions   */
        private uint maxvar = 22;          /* set maximum number of variables             */
        private uint maxcontrains = 3;          /* set maximum number of constrains             */
        private Int32 verbose = 1;         /* verbosity level 0,1                         */
        private Int32 printevery = 10;     /* how frequently should output be generated   */
        private double PI;
        private double pMut = 0.5;			 /* probability of mutation                          */
        private Int32 nondomCtr = 0;		 /* number of nondominated solutions in archive      */

        //double [,] archiveVar = new double[archive_size,maxvar]; /* variable values of particles in the archive  */
        //double [,] archiveFit=new double[archive_size,maxfun]; /* fitness values of particles in the archive   */
        //double [,] popVar = new double[popsize,maxvar];	         /* variable values of particles in the population   */   
        //double [,] popFit= new double[popsize,maxfun];		 /* fitness values of particles in the population    */
        //double [,] pbestsVar = new double[popsize,maxvar];	 /* personal bests of particles in the population    */
        //double [,] pbestsFit = new double[popsize,maxfun];	 /* personal bests of particles in the population    */
        //double [,] velocity = new double[popsize,maxvar];	 /* velocity of particles in the population          */
        //double[] crowdDist = new double[archive_size];		 /* crowding distance values of particles in archive */
        double[][] archiveVar = null;
        double[][] archiveFit = null;
        double[][] popVar = null;
        double[][] popFit = null;

        double[][] pbestsVar = null;
        double[][] pbestsFit = null;
        double[][] velocity = null;
        double[] crowdDist = null;

        double[] varLowerBound = null;
        double[] varUpperBound = null;
        double[] constrainsUpperBond = null;

        double[] argLocal = null;
        double[] fiLocal = null;
        object objLocal = null;
        double[] constrainsValueLocal = null;
        Random random = new Random();
    }
}
