using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejercicio_48
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Title = "Ejericio #48";

            Competencia<VehiculoDeCarrera> cF1 = new Competencia<VehiculoDeCarrera>(5, 2, Competencia<VehiculoDeCarrera>.TipoCompetencia.F1);
            Competencia<VehiculoDeCarrera> cMC = new Competencia<VehiculoDeCarrera>(5, 1, Competencia<VehiculoDeCarrera>.TipoCompetencia.MotoCross);
            AutoF1 a1 = new AutoF1(1, "Escuderia1");
            AutoF1 a1repe = new AutoF1(1, "Escuderia1");
            AutoF1 a2 = new AutoF1(2, "Escuderia2");
            AutoF1 aExtra = new AutoF1(4, "EscuderiaExtra");
            VehiculoDeCarrera vc = new MotoCross(2, "MotoEscuderia");

            bool x;

            x = cF1 + a1;
            x = cF1 + a1repe;
            x = cF1 + a2;
            try
            {
                x = cF1 + vc;
            }
            catch(CompetenciaNoDisponibleException e)
            {
                Console.WriteLine(e.ToString());
            }            
            x = cF1 + aExtra;
            x = cMC + vc;

            Console.WriteLine(cF1.MostrarDatos());
            Console.WriteLine(cMC.MostrarDatos());

            Console.ReadKey();
        }
    }
}
