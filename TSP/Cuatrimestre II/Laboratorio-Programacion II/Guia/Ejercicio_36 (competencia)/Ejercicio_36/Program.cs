using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejercicio_36
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Title = "Ejericio #36";

            Competencia cF1 = new Competencia(5, 2, Competencia.TipoCompetencia.F1);
            Competencia cMC = new Competencia(5, 1, Competencia.TipoCompetencia.MotoCross);
            AutoF1 a1 = new AutoF1(1, "Escuderia1");
            AutoF1 a1repe = new AutoF1(1, "Escuderia1");
            AutoF1 a2 = new AutoF1(2, "Escuderia2");
            AutoF1 aExtra = new AutoF1(4, "EscuderiaExtra");
            VehiculoDeCarrera vc = new MotoCross(2, "MotoEscuderia");

            bool x;

            x = cF1 + a1;
            x = cF1 + a1repe;
            x = cF1 + a2;
            x = cF1 + vc;
            x = cF1 + aExtra;
            x = cMC + vc;

            Console.WriteLine(cF1.MostrarDatos());
            Console.WriteLine(cMC.MostrarDatos());
            Console.ReadKey();
        }
    }
}
