using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.InteropServices;
using System.IO;

namespace nsga2cscall
{
    public class nsga2cscall
    {
        const string _dllLocation = @".\nsga2\Debug\nsga2call.dll";
        [DllImport(_dllLocation, EntryPoint = "maintestwithmsg", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.Cdecl)]
        public static extern void maintrainwithmsg(int argc, [In] IntPtr[] argv, StringBuilder argv1);

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
