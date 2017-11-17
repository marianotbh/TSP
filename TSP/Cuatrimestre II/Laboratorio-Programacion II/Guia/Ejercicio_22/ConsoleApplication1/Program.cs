using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejercicio22
{
    class Program
    {
        static void Main(string[] args)
        {
            Fahrenheit.Fahrenheit Ftemp = new Fahrenheit.Fahrenheit();
            Kelvin.Kelvin Ktemp = new Kelvin.Kelvin();
            Celsius.Celsius Ctemp = new Celsius.Celsius();
            double resultado;
            bool check;
            Ftemp = 86;
            Ktemp = 303.15;
            Ctemp = 30;

            resultado = Ftemp + Ktemp;
            Console.WriteLine("F+K = {0}", resultado);
            resultado = Ftemp + Ctemp;
            Console.WriteLine("F+C = {0}", resultado);
            resultado = Ktemp + Ftemp;
            Console.WriteLine("K+F = {0}", resultado);
            resultado = Ktemp + Ctemp;
            Console.WriteLine("K+C = {0}", resultado);
            resultado = Ctemp + Ftemp;
            Console.WriteLine("C+F = {0}", resultado);
            resultado = Ctemp + Ktemp;
            Console.WriteLine("C+K = {0}", resultado);

            if(Ctemp == Ftemp)
                check = true;
            else
                check = false;
            Console.WriteLine("C==F = {0}", check);

            Console.ReadKey();
        }
    }
}
