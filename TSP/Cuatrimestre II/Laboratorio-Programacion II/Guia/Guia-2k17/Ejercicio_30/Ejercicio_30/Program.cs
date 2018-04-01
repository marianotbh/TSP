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
            AutoF1 a1 = new AutoF1(01, "Escuderia1");
            AutoF1 a2 = new AutoF1(04, "Escuderia3");
            AutoF1 a3 = new AutoF1(01, "Escuderia1");
            AutoF1 a4 = new AutoF1(03, "Escuderia666");
            Competencia competencia = new Competencia(5, 2);
            bool addCheck;
            addCheck = competencia + a1;
            addCheck = competencia + a2;
            addCheck = competencia + a3;
            addCheck = competencia + a4;
            Console.WriteLine(competencia.MostrarDatos());
            Console.ReadKey();
        }
    }
}
