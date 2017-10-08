using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejercicio_2
{
    class Ejercicio_2
    {
        static void Main(string[] args)
        {
            Console.Title = "Ejercicio #1";

            string input;
            int num;
            double cuadrado;
            double cubo;

            Console.WriteLine("Ingrese un numero:");
            input = Console.ReadLine();
            while(!(int.TryParse(input, out num)) || num == 0)
            {
                Console.WriteLine("Error! reingrese el numero");
                input = Console.ReadLine();
            }

            cuadrado = Math.Pow(num, 2);
            cubo = Math.Pow(num, 3);

            Console.WriteLine("El cuadrado del numero es: {0}", cuadrado);
            Console.WriteLine("El cubo del numero es: {0}", cubo);

            Console.ReadKey();
        }
    }
}
