using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejercicio_30
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Title = "Ejericio #30";

            Competencia c = new Competencia(5, 3);
            AutoF1 a1 = new AutoF1(1, "Escuderia1");
            AutoF1 a1repe = new AutoF1(1, "Escuderia1");
            AutoF1 a2 = new AutoF1(2, "Escuderia2");
            AutoF1 a3 = new AutoF1(3, "Escuderia3");
            AutoF1 aExtra = new AutoF1(4, "EscuderiaExtra");

            bool x;

            x = c + a1;
            x = c + a1repe;
            x = c + a2;
            x = c + a3;
            x = c + aExtra;

            Console.WriteLine(c.MostrarDatos());
            Console.ReadKey();
        }
    }
}
