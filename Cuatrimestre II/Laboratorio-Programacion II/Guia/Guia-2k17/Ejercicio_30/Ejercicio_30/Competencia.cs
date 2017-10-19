using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejercicio_30
{
    class Competencia
    {
        short CantidadCompetidores;
        short CantidadVueltas;
        List<AutoF1> competidores;

        Competencia()
        {
            this.competidores = new List<AutoF1> { };
        }

        public Competencia(short CantidadVueltas, short CantidadCompetidores)
            : this()
        {
            this.CantidadVueltas = CantidadVueltas;
            this.CantidadCompetidores = CantidadCompetidores;
        }

        public string MostrarDatos()
        {
            StringBuilder sb = new StringBuilder();
            sb.AppendLine("Competencia: ");
            sb.AppendFormat("Cantidad de vueltas: {0} - Cantidad de competidores: {1} \n", this.CantidadVueltas, this.CantidadCompetidores);
            sb.AppendLine("Competidores: ");
            foreach (AutoF1 a in this.competidores)
            {
                sb.AppendLine(a.MostrarDatos());
            }
            return sb.ToString();
        }

        public static bool operator +(Competencia c, AutoF1 a)
        {
            if (c != a && c.competidores.Count < c.CantidadCompetidores)
            {
                Random cantComb = new Random();
                a.setCantidadCombustible((short)cantComb.Next(15,100));
                a.setEnCompetencia(true);
                a.setVueltasRestantes(c.CantidadVueltas);
                c.competidores.Add(a);
                return true;
            }
            else 
                return false;
        }
        public static bool operator -(Competencia c, AutoF1 a)
        {
            if (c == a)
            {
                c.competidores.Remove(a);
                return true;
            }
            return false;                
        }
        public static bool operator ==(Competencia c, AutoF1 a)
        {
            foreach (AutoF1 f1 in c.competidores)
            {
                if (f1 == a)
                { 
                    return true;
                }
            }
            return false;
        }
        public static bool operator !=(Competencia c, AutoF1 a)
        {
            return !(c == a);
        }

        
    }
}
