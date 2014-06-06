using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;

namespace svmcallcsharp
{
    [StructLayout(LayoutKind.Sequential)]
    public struct svm_node
    {

        /// int
        public int index;

        /// double
        public double value;
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct svm_problem
    {

        /// int
        public int l;

        /// double*
        public IntPtr y;

        /// svm_node**
        public IntPtr x;
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct svm_parameter
    {

        /// int
        public int svm_type;

        /// int
        public int kernel_type;

        /// int
        public int degree;

        /// double
        public double gamma;

        /// double
        public double coef0;

        /// double
        public double cache_size;

        /// double
        public double eps;

        /// double
        public double C;

        /// int
        public int nr_weight;

        /// int*
        public IntPtr weight_label;

        /// double*
        public IntPtr weight;

        /// double
        public double nu;

        /// double
        public double p;

        /// int
        public int shrinking;

        /// int
        public int probability;
    }
   
    public struct svm_scale
    {
        public double upper;
        public double lower;
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct svm_model
    {

        /// svm_parameter
        public svm_parameter param;

        /// int
        public int nr_class;

        /// int
        public int l;

        /// svm_node**
        public IntPtr SV;

        /// double**
        public IntPtr sv_coef;

        /// double*
        public IntPtr rho;

        /// double*
        public IntPtr probA;

        /// double*
        public IntPtr probB;

        /// int*
        public IntPtr sv_indices;

        /// int*
        public IntPtr label;

        /// int*
        public IntPtr nSV;

        /// int
        public int free_sv;
    }

    public partial class svmcallcs
    {

        /// Return Type: void
        ///prob: svm_problem*
        ///param: svm_parameter*
        ///nr_fold: int
        ///target: double*
        [DllImport(_dllLocation2, EntryPoint = "svm_cross_validation", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.Cdecl)]
        public static extern void svm_cross_validation(ref svm_problem prob, ref svm_parameter param, int nr_fold, ref double target,bool setSeed);


        /// Return Type: int
        ///model_file_name: char*
        ///model: svm_model*
        [DllImport(_dllLocation2, EntryPoint = "svm_save_model", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.Cdecl)]
        public static extern int svm_save_model([In] [MarshalAs(UnmanagedType.LPStr)] string model_file_name, ref svm_model model);


        /// Return Type: svm_model*
        ///model_file_name: char*
        [DllImport(_dllLocation2, EntryPoint = "svm_load_model", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr svm_load_model([In] [MarshalAs(UnmanagedType.LPStr)] string model_file_name);


        /// Return Type: int
        ///model: svm_model*
        [DllImport(_dllLocation2, EntryPoint = "svm_get_svm_type", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.Cdecl)]
        public static extern int svm_get_svm_type(ref svm_model model);


        /// Return Type: int
        ///model: svm_model*
        [DllImport(_dllLocation2, EntryPoint = "svm_get_nr_class", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.Cdecl)]
        public static extern int svm_get_nr_class(ref svm_model model);


        /// Return Type: void
        ///model: svm_model*
        ///label: int*
        [DllImport(_dllLocation2, EntryPoint = "svm_get_labels", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.Cdecl)]
        public static extern void svm_get_labels(ref svm_model model, ref int label);


        /// Return Type: void
        ///model: svm_model*
        ///sv_indices: int*
        [DllImport(_dllLocation2, EntryPoint = "svm_get_sv_indices", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.Cdecl)]
        public static extern void svm_get_sv_indices(ref svm_model model, ref int sv_indices);


        /// Return Type: int
        ///model: svm_model*
        [DllImport(_dllLocation2, EntryPoint = "svm_get_nr_sv", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.Cdecl)]
        public static extern int svm_get_nr_sv(ref svm_model model);


        /// Return Type: double
        ///model: svm_model*
        [DllImport(_dllLocation2, EntryPoint = "svm_get_svr_probability", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.Cdecl)]
        public static extern double svm_get_svr_probability(ref svm_model model);


        /// Return Type: double
        ///model: svm_model*
        ///x: svm_node*
        ///dec_values: double*
        [DllImport(_dllLocation2, EntryPoint = "svm_predict_values", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.Cdecl)]
        public static extern double svm_predict_values(ref svm_model model, ref svm_node x, ref double dec_values);


        /// Return Type: double
        ///model: svm_model*
        ///x: svm_node*
        [DllImport(_dllLocation2, EntryPoint = "svm_predict", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.Cdecl)]
        public static extern double svm_predict(ref svm_model model, [In] svm_node[] x);


        /// Return Type: double
        ///model: svm_model*
        ///x: svm_node*
        ///prob_estimates: double*
        [DllImport(_dllLocation2, EntryPoint = "svm_predict_probability", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.Cdecl)]
        public static extern double svm_predict_probability(ref svm_model model, ref svm_node x, ref double prob_estimates);


        /// Return Type: void
        ///model_ptr: svm_model*
        [DllImport(_dllLocation2, EntryPoint = "svm_free_model_content", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.Cdecl)]
        public static extern void svm_free_model_content(ref svm_model model_ptr);


        /// Return Type: void
        ///model_ptr_ptr: svm_model**
        [DllImport(_dllLocation2, EntryPoint = "svm_free_and_destroy_model", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.Cdecl)]
        public static extern void svm_free_and_destroy_model(ref IntPtr model_ptr_ptr);


        /// Return Type: void
        ///param: svm_parameter*
        [DllImport(_dllLocation2, EntryPoint = "svm_destroy_param", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.Cdecl)]
        public static extern void svm_destroy_param(ref svm_parameter param);


        /// Return Type: char*
        ///prob: svm_problem*
        ///param: svm_parameter*
        [DllImport(_dllLocation2, EntryPoint = "svm_check_parameter", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.Cdecl)]
        public static extern string svm_check_parameter(ref svm_problem prob, ref svm_parameter param);


        /// Return Type: int
        ///model: svm_model*
        [DllImport(_dllLocation2, EntryPoint = "svm_check_probability_model", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.Cdecl)]
        public static extern int svm_check_probability_model(ref svm_model model);

        // svm training with scaling
        // scaleRestore = true -> scale and same parameters in scaleParam; scaleRestore = false -> restore from scaleParam
        public static void svm_scale(ref svm_problem data, ref List<svm_scale> scaleParams, bool scaleRestore)
        {
            int nCases = data.l;
            if (!scaleRestore && scaleParams.Count != 1) throw new Exception("invalid scale parameters: two many");

            svm_node Nd;
            svm_scale Scl = new svm_scale();
            Nd.index = 0;
            Nd.value = 0;
            double lwrScld = scaleParams[0].lower;
            double upprScld = scaleParams[0].upper;
            int maxindex = 0;
            int idx = 0;
            double lwrScld_i, upprScld_i;
            for (int i = 0; i < nCases; i++)
            {
                IntPtr NdPtr = Marshal.ReadIntPtr(data.x, i * Marshal.SizeOf(data.x));
                Nd = (svm_node)Marshal.PtrToStructure(NdPtr, typeof(svm_node));

                while (Nd.index != -1)
                {
                    idx = Nd.index;
                    if (scaleRestore)
                    { // restore the original value based on the scale parameters
                        if (scaleParams.Count < idx + 1) throw new Exception("invalid scale parameters: too few");
                        lwrScld_i = scaleParams[idx].lower;
                        upprScld_i = scaleParams[idx].upper;
                        Nd.value = lwrScld_i + (upprScld_i - lwrScld_i) / (upprScld - lwrScld) * (Nd.value - lwrScld);
                        // write back
                        Marshal.StructureToPtr(Nd, NdPtr, true);
                    }
                    else
                    { // 1st pass finding the max index and max/min values 
                        if (idx > maxindex)
                        {
                            Scl.upper = Scl.lower = 0;
                            for (int j = maxindex+1; j <idx; j++) scaleParams.Add(Scl);
                            Scl.upper = Scl.lower = Nd.value;
                            scaleParams.Add(Scl);
                            maxindex = idx;
                        }
                        // already had a max/min for this index: update 
                        Scl.upper = Math.Max(Nd.value, scaleParams[idx].upper);
                        Scl.lower = Math.Min(Nd.value, scaleParams[idx].lower);                       
                        scaleParams[idx] = Scl;
                    }
                    // move to next element
                    NdPtr += Marshal.SizeOf(Nd);
                    Nd = (svm_node)Marshal.PtrToStructure(NdPtr, typeof(svm_node));                   
                }
            }
            // 2nd pass for scaling
            if (scaleRestore) return;
            for (int i = 0; i < nCases; i++)
            {
                IntPtr NdPtr = Marshal.ReadIntPtr(data.x, i * Marshal.SizeOf(data.x));
                Nd = (svm_node)Marshal.PtrToStructure(NdPtr, typeof(svm_node)); 
                while (Nd.index != -1)
                {
                    idx = Nd.index;
                    lwrScld_i = scaleParams[idx].lower;
                    upprScld_i = scaleParams[idx].upper;
                    Nd.value = lwrScld + (upprScld - lwrScld) / (upprScld_i - lwrScld_i) * (Nd.value - lwrScld_i);
                    // write back
                    Marshal.StructureToPtr(Nd, NdPtr, true);
                    // move to next element
                    NdPtr += Marshal.SizeOf(Nd);
                    Nd = (svm_node)Marshal.PtrToStructure(NdPtr, typeof(svm_node)); 
                }
            }
            return;
        }
    }
}
