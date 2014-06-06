﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NSGA2Sharp
{
    public partial class NSGA2
    {

        /* Routine for usual non-domination checking
           It will return the following values
           1 if a dominates b
           -1 if b dominates a
           0 if both a and b are non-dominated */

        int check_dominance(ref individual a, ref individual b)
        {
            int i;
            int flag1;
            int flag2;
            flag1 = 0;
            flag2 = 0;
            if (a.constr_violation < 0 && b.constr_violation < 0)
            {
                if (a.constr_violation > b.constr_violation)
                {
                    return (1);
                }
                else
                {
                    if (a.constr_violation < b.constr_violation)
                    {
                        return (-1);
                    }
                    else
                    {
                        return (0);
                    }
                }
            }
            else
            {
                if (a.constr_violation < 0 && b.constr_violation == 0)
                {
                    return (-1);
                }
                else
                {
                    if (a.constr_violation == 0 && b.constr_violation < 0)
                    {
                        return (1);
                    }
                    else
                    {
                        for (i = 0; i < nobj; i++)
                        {
                            if (a.obj[i] < b.obj[i])
                            {
                                flag1 = 1;

                            }
                            else
                            {
                                if (a.obj[i] > b.obj[i])
                                {
                                    flag2 = 1;
                                }
                            }
                        }
                        if (flag1 == 1 && flag2 == 0)
                        {
                            return (1);
                        }
                        else
                        {
                            if (flag1 == 0 && flag2 == 1)
                            {
                                return (-1);
                            }
                            else
                            {
                                return (0);
                            }
                        }
                    }
                }
            }
        }
      
    }
}
