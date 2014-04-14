using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace MySpace
{
    class Out
    {
        static void Main(string[] args)
        {
            char button;
            if(args.Length==0)
            {
                Console.WriteLine("ConvertToPhoneNumber.exe <phrase>");
                Console.WriteLine("'-' indicates no standard phone button");
                return;
            }
            foreach(string word in args)
            {
                foreach(char ch in word)
                {
                    if(GetPhoneButton(ch,out button))
                    {
                        Console.Write(button);
                    }
                    else Console.Write('-');
                }
                Console.WriteLine();
            }

        }

        static bool GetPhoneButton(char ch,out char button)
        {
            bool success=true;
            switch(ch)
            {
                case 'a':case 'b':case 'c':button='1';break;
                case 'd':case 'e':case 'f':button='2';break;
                case 'g':case 'h':case 'i':button='3';break;
                default:button='-';success=false;break;
            }
            return success;
    }
}
