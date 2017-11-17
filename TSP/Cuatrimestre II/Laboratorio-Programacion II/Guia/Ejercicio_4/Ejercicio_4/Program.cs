using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejercicio_4
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Title = "Ejercicio #4";
            Console.WriteLine("Escribir una aplicación que encuentre los 4 primeros números perfectos. \nNota: Utilizar estructuras repetitivas, selectivas y la función módulo(%).");
            Console.ReadKey();
            Console.Clear();

            int num = 2;
            int iNums = 0;
            int acum = 0;

            Console.Write("Los cuatro primeros numeros perfectos son: ");

            do
            {
                for (int i = 1; i < num; i++)
                {
                    if (num % i == 0)
                    {
                        acum += i;
                    }
                }
                if (acum == num)
                {
                    iNums++;
                    Console.Write("{0}, ", num);
                }
                num++;
                acum = 0;
            } while (iNums < 4);

            Console.ReadKey();
        }
    }
}
