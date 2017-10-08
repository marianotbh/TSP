using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejercicio_5
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Title = "Ejercicio #5";
            Console.WriteLine("Se pide elaborar una aplicación que calcule los centros numéricos entre 1 y el número que el usuario ingrese por consola.\nNota: Utilizar estructuras repetitivas, selectivas y la función módulo(%).");
            Console.ReadKey();
            Console.Clear();

            int num;
            int acumAtras;
            int acumAdelante;
            int centro = 0;

            Console.Write("Ingrese un numero: ");
            int.TryParse(Console.ReadLine(), out num);

            while (centro < num)
            {
                centro++;
                acumAtras = 0;
                acumAdelante = 0;
                for(int i = 1; i < centro; i++)
                {
                    acumAtras += i;
                }
                for(int d = centro+1; d <= acumAtras; d++)
                {
                    if (acumAdelante == acumAtras || acumAdelante > acumAtras)
                        break;
                    acumAdelante += d;
                }
                if (acumAtras == acumAdelante)
                {
                    Console.WriteLine("Centro: {0}", centro);
                }
            }

            Console.ReadKey();
        }
    }
}
