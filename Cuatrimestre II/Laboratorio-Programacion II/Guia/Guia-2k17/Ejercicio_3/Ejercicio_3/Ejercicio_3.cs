using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejercicio_3
{
    class Ejercicio_3
    {
        static void Main(string[] args)
        {
            Console.Title = "Ejercicio #3";
            int num;
            int flag;

            Console.WriteLine("Ingrese un numero:");
            int.TryParse(Console.ReadLine(), out num);

            for(int i = 1; i < num; i++)
            {
                flag = 1;
                for(int j = 1; j < i; j++)
                {
                    if (i % j == 0 && i != j && j != 1)
                    {
                        flag = 0;
                        break;
                    }
                }
                if(flag == 1)
                {
                    Console.WriteLine("{0}", i);
                }
            }

            Console.ReadKey();
        }
    }
}
