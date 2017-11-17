using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejercicio_3
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Title = "Ejercicio #3";
            Console.WriteLine("Mostrar por pantalla todos los números primos que haya hasta el número que ingrese el usuario por consola.\nNota: Utilizar estructuras repetitivas, selectivas y la función módulo (%).");
            Console.ReadKey();
            Console.Clear();

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
