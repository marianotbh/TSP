using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EjercicioCampus
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Title = "Ejercicio #13";
            /*
             13. Desarrollar una clase llamada 'Conversor', que posea dos métodos de clase (estáticos):
                   string DecimalBinario(double). 
                    * Convierte un número de decimal a binario.
                   double BinarioDecimal(string). 
                    * Convierte un número binario a decimal.
             */
            string input;
            int opt;
            double pass;

            NumeroBinario objBin = "1001";
            NumeroDecimal objDec = 9;
            Console.WriteLine("objBin = {0} \nobjDec = {1}",objBin.numBin,objDec.numDec);
            Double resDouble = objDec + objBin;
            String resString = objBin + objDec;
            Console.WriteLine("Resultado double: {0}",resDouble);
            Console.WriteLine("Resultado string: {0}",resString);




            Console.WriteLine("\n\nQue desea hacer?");
            Console.WriteLine("1 = Double to Bin");
            Console.WriteLine("2 = Bin to Double");
            input = Console.ReadLine();
            int.TryParse(input, out opt);
            switch (opt)
            {
                case 1:
                    input = Console.ReadLine();
                    double.TryParse(input, out pass);
                    Console.WriteLine("Convertido {0}d a {1}b", pass, Conversor.DecimalBinario(pass));
                    break;
                case 2:
                    input = Console.ReadLine();
                    Console.WriteLine("Convertido {0}d a {1}b", input, Conversor.BinarioDecimal(input));
                    break;
                default:
                    Console.WriteLine("Ingrese una opcion valida");
                    break;
            }
            Console.ReadKey();
        }
    }
}
