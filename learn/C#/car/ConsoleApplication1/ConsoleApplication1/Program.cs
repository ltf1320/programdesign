using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("请输入汽车加满油后可行驶路程： ");
            int n = Convert.ToInt32(Console.ReadLine());
            Console.Write("请输入途经加油站总数： ");
            int k = Convert.ToInt32(Console.ReadLine());
            int[] distance = new int[k + 1];//加油站间距
            int[] note = new int[k];//记录加油站点
            Console.WriteLine("请输入加油站间距！");
            for (int i = 0; i <= k; i++)
            {//从始点起，加油站间距
                Console.Write("站点间距{0}:  ", i + 1);
                distance[i] = Convert.ToInt32(Console.ReadLine());
            }
            int count;//记录加油次数
            Problem p = new Problem();
            count = p.Greedy(distance, note, n);
            if (count >= 0)
            {
                if (count == 0)
                    Console.WriteLine("汽车不用加油就可到达终点！");
                else
                {
                    Console.WriteLine("汽车在旅途中需加{0}次油！", count);
                    Console.WriteLine("分别在以下加油站加了油：");
                    for (int i = 0; i < note.Length; i++)
                    {
                        if (note[i] != 0)
                        {//输出需加油站点
                            Console.WriteLine("第" + note[i] + "个加油站！");
                        }
                    }
                }
            }
            else
                Console.WriteLine("汽车无法到达终点！");
            Console.ReadKey();
        }
    }
    class Problem
    {
        public int Greedy(int[] d, int[] note, int n)
        {
            int i, j, s, add = 0, p = 0, k = d.Length;
            for (i = 0; i < k; i++)
            {
                if (d[i] > n)
                {//不能到达目的地
                    return -1;
                }
            }
            for (j = 0, s = 0; j < k; j++)
            {
                s += d[j];
                if (s > n)
                {//需要加油
                    add++;
                    note[p++] = j;
                    s = d[j];
                }
            }
            return add;
        }
    }
}

