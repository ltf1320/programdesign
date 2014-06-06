using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace MathUtilityCommon.API
{
    public delegate void Ndimensional_fvec(double[] arg, double[] fi, object obj);
    public delegate void Ndimensional_jac(double[] arg, double[] fi, double[,] jac, object obj);
}
