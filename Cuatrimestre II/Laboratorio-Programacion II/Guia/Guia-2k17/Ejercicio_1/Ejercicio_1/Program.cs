using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejercicio1
{
    class Program
    {
        static void Main(string[] args)
        {
            string input;
            int num;
            int maxVal = 0;
            int minVal = 0;
            int prom = 0;
            int i = 0;

            do
            {
                Console.WriteLine("Ingrese el numero {0}:", i + 1);
                input = Console.ReadLine();
                if (int.TryParse(input, out num))
                {
                    if (num > maxVal || i == 0)
                        maxVal = num;
                    if (num < minVal || i == 0)
                        minVal = num;
                    prom += num;
                    i++;
                }
                else
                    Console.WriteLine("No es un numero valido");
            } while (i < 5);

            prom = prom / i;

            Console.WriteLine("El menor valor ingresado es: {0}", minVal);
            Console.WriteLine("El mayor valor ingresado es: {0}", maxVal);
            Console.WriteLine("El promedio de los valores ingresados es: {0}", prom);
            Console.ReadKey();
        }
    }
}
