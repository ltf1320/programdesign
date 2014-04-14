using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace OutProject
{
    class Program
    {
        static void Main(string[] args)
        {
            int a=Console.Read();
            int result=0;
           if(plus (a,out result))
            Console.WriteLine(Environment.SystemDirectory);
           Console.ReadKey();
        }
        
        static bool plus(int a, out int result)
        {
            bool success = true;
            if (a > 0) result = a + 1;
            else if (a < 0) result = a - 1;
            else
            {
                success = false;
                result = 0;
            }
            return success;
        }
        
    }
}