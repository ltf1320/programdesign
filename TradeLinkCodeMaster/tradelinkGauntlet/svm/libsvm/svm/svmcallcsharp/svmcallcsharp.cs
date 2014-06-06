using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.InteropServices;
using System.IO;

namespace svmcallcsharp
{
    public partial class svmcallcs
    {
        const string _dllLocation1 = @".\svm\libsvm\svm\Debug\svmcall.dll";
        #if DEBUG
                const string _dllLocation2 = @"..\..\..\..\ThirdPartLib\libsvm\Debug\libsvm.dll";
        #else
                const string _dllLocation2 = @"..\..\..\..\ThirdPartLib\libsvm\Release\libsvm.dll";
        #endif


        [DllImport(_dllLocation1, EntryPoint = "maintrainwithmsg", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.Cdecl)]

        public static extern void maintrainwithmsg(int argc, [In] IntPtr[] argv, StringBuilder argv1);


        [DllImport(_dllLocation1, EntryPoint = "mainscalewithmsg", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.Cdecl)]

        public static extern void mainscalewithmsg(int argc, [In] IntPtr[] argv, StringBuilder argv1);


        [DllImport(_dllLocation1, EntryPoint = "mainpredictwithmsg", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.Cdecl)]

        public static extern void mainpredictwithmsg(int argc, [In] IntPtr[] argv, StringBuilder argv1);

        /// Return Type: svm_model*
        ///prob: svm_problem*
        ///param: svm_parameter*
        [DllImport(_dllLocation2, EntryPoint = "svm_train", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr svm_train(ref svm_problem prob, ref svm_parameter param);

        public static IntPtr StringToByteArray(string s)
        {
            IntPtr p = new IntPtr();
            byte[] b = new byte[s.Length + 1];
            int i;
            for (i = 0; i < s.Length; i++)
                b[i] = (byte)s.ToCharArray()[i];
            b[s.Length] = 0;
            p = Marshal.AllocCoTaskMem(s.Length + 1);
            Marshal.Copy(b, 0, p, s.Length + 1);
            return p;
        }
    }
}
