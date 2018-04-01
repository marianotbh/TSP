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
            AutoF1 a1 = new AutoF1(01, "Escuderia1", 10);
            AutoF1 a2 = new AutoF1(04, "Escuderia3", 8);
            AutoF1 a3 = new AutoF1(04, "Escuderia3", 8);
            MotoCross m1 = new MotoCross(02, "Escuderia3", 400);
            MotoCross m2 = new MotoCross(02, "Escuderia3", 400);
            MotoCross m3 = new MotoCross(03, "Escuderia4", 250);
            bool check;

            Competencia competenciaMC = new Competencia(5, 3, Competencia.TipoCompetencia.MotoCross);
            Competencia competenciaF1 = new Competencia(5, 4, Competencia.TipoCompetencia.F1);

            check = competenciaMC + m1;
            check = competenciaMC + m2;
            check = competenciaMC + m3;
            check = competenciaF1 + a1;
            check = competenciaF1 + a2;
            check = competenciaF1 + a3;
            Console.Write(competenciaF1.MostrarDatos());
            Console.Write(competenciaMC.MostrarDatos());

            Console.ReadKey();
        }
    }
}
