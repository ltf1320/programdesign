using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace prime
{
    class Program
    {
        static void Main(string[] args)
        {
            Employee E1=new Employee();
            E1.Name="abc dda";
            Console.WriteLine(E1.Name);
            
            var pp=
                new 
                {
                    p=1,
                    TT="22"
                };
            Console.WriteLine(pp.p);
            Console.ReadKey();
        }
    }
}
