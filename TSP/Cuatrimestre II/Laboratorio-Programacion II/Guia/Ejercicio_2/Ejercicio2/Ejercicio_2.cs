using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejercicio_2
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Title = "Ejercicio #2";
            Console.WriteLine("Ingresar un número y mostrar: el cuadrado y el cubo del mismo. \nSe debe validar que el número sea mayor que cero, caso contrario, mostrar el mensaje: \nERROR. ¡Reingresar número!.\nNota: Utilizar el método ‘Pow’ de la clase Math para realizar la operación.");
            Console.ReadKey();
            Console.Clear();

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
