using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using WaveletStudio.Functions;
using WaveletStudio.Wavelet;

namespace MathUtilityCommon
{
    public class Wavevelet
    {
        public static List<DecompositionLevel> Filter(List<DecompositionLevel> output, string method)
        {
            List<DecompositionLevel> New = output;
            double lamda;
            if (method == "minimax") lamda = Minimax(output);
            else if (method == "sqtwolog") lamda = Sqtwolog(output);
            else if (method == "rigrsure") lamda = Rigrsure(output);
            else if (method == "heursure") lamda = Heursure(output);
            else
            {
                lamda = 0.5;
            }
            int n = output.Count;
            for (int i = 0; i < n; i++)
            {
                New[i].Details = Filter(output[i].Details, lamda);
            }
            return New;
        }

        public static double[] Filter(double[] old, double index = 1)
        {
            double[] n = new double[old.Length];
            for (int i = 0; i < old.Length; i++)
            {
                if (Math.Abs(old[i]) < index) n[i] = 0;
                else n[i] = old[i];
            }
            return n;
        }

        public static double[] GetAbsDetailcoeffs(List<DecompositionLevel> output, int start, int end)
        {
            double temp;
            List<double> coeffs = new List<double>();
            for (int i = start - 1; i < end; i++)
            {
                for (int j = 0; j < output[i].Details.Length; j++)
                {
                    temp = Math.Abs(output[i].Details[j]);
                    coeffs.Add(temp);
                }
            }
            coeffs.Sort();
            double[] coeff = coeffs.ToArray();
            return coeff;
        }

        public static double Median(double[] data)
        {
            int n = data.Length;
            double median;
            int m1 = (n + 1) / 2;
            double m2 = (n + 1) / 2.0;
            if (m2 - m1 < 0.25) median = data[m1 - 1];
            else median = (data[m1 - 1] + data[m1]) / 2;
            return median;
        }

        public static double Minimax(List<DecompositionLevel> output)
        {
            int N = output[0].Details.Length * 2;
            int n = output.Count;
            double lamda = 0;
            if (N > 32)
            {
                double[] coeffs = GetAbsDetailcoeffs(output, 1, 1);
                double sigma = Median(coeffs) / 0.6745;
                lamda = sigma * (0.3936 + 0.1829 * Math.Log(N));
            }
            return lamda;
        }

        public static double Sqtwolog(List<DecompositionLevel> output)
        {
            int n = output.Count;
            double lamda;
            int N = output[0].Details.Length * 2;
            double sigma = Median(GetAbsDetailcoeffs(output, 1, 1)) / 0.6745;
            lamda = sigma * Math.Sqrt(2 * Math.Log(N));
            return lamda;
        }

        public static double Rigrsure(List<DecompositionLevel> output)
        {
            int N = 0;
            int n = output.Count;
            for (int i = 0; i < n; i++)
                N += output[i].Details.Length;
            double lamda = double.PositiveInfinity;
            double[] coeffs = GetAbsDetailcoeffs(output, 1, n);
            double[] temp = new double[N];
            double sum = 0;
            int j = 0;
            for (int i = 0; i < N; i++)
            {
                sum += Math.Pow(coeffs[i], 2);
                temp[i] = (N - 2 * (i + 1) + (N - i - 1) * Math.Pow(coeffs[i], 2) + sum) / N;
                if (temp[i] < lamda)
                {
                    j = i;
                    lamda = temp[i];
                }
            }
            double[] coeff = GetAbsDetailcoeffs(output, 1, 1);
            double sigma = Median(coeff) / 0.6745;
            lamda = sigma * coeffs[j];
            return lamda;
        }

        public static double Heursure(List<DecompositionLevel> output)
        {
            int N = output[0].Details.Length * 2;
            int n = output.Count;
            double s = 0;
            double[] coeffs = GetAbsDetailcoeffs(output, 1, n);
            for (int i = 0; i < coeffs.Length; i++)
                s += Math.Pow(coeffs[i], 2);
            double A = (s - N) / N;
            double B = Math.Pow(Math.Log(N) / Math.Log(2), 3 / 2) * Math.Sqrt(N);
            double lamda = Sqtwolog(output);
            double temp = Rigrsure(output);
            if (A >= B)
                lamda = Math.Min(lamda, temp);
            return lamda;
        }
    }
}
