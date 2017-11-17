using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejercicio_30
{
    class Competencia
    {
        short cantidadCompetidores;
        short cantidadVueltas;
        List<AutoF1> competidores;

        Competencia()
        {
            this.competidores = new List<AutoF1>();
        }

        public Competencia(short cantidadVueltas, short cantidadCompetidores)
            : this()
        {
            this.cantidadVueltas = cantidadVueltas;
            this.cantidadCompetidores = cantidadCompetidores;
        }

        public string MostrarDatos()
        {
            StringBuilder sb = new StringBuilder();
            sb.AppendFormat("Competencia de {0} vueltas \n{1} Participantes: \n", this.cantidadVueltas, this.cantidadCompetidores);
            foreach(AutoF1 a in this.competidores)
            {
                sb.AppendLine(a.MostrarDatos());
            }
            return sb.ToString();
        }

        public static bool operator +(Competencia c, AutoF1 f1)
        {
            if (c != f1 && c.competidores.Count < c.cantidadCompetidores)
            {
                Random r = new Random();
                f1.setVueltasRestantes(c.cantidadVueltas);
                f1.setEnCompetencia(true);
                f1.setCantidadCombustible((short)r.Next(15, 100));
                c.competidores.Add(f1);
                return true;
            }
            else
                return false;
        }

        public static bool operator -(Competencia c, AutoF1 f1)
        {
            if (c == f1)
            {
                c.competidores.Remove(f1);
                return true;
            }
            else
                return false;                
        }

        public static bool operator ==(Competencia c, AutoF1 f1)
        {
            foreach(AutoF1 a in c.competidores)
            {
                if (a == f1)
                    return true;
            }
            return false;
        }

        public static bool operator !=(Competencia c, AutoF1 f1)
        { return !(c == f1); }
    }
}
