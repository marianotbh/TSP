using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejercicio_54
{
    abstract public class Llamada
    {
        protected float duracion;
        protected string nroOrigen;
        protected string nroDestino;

        public enum TipoLlamada
        {
            Local,
            Provincial,
            Todas
        }

        abstract public float CostoLlamada
        { get; }

        public float Duracion
        {
            get
            {
                return this.duracion;
            }
        }

        public string NroOrigen
        {
            get
            {
                return this.nroOrigen;
            }
        }

        public string NroDestino
        {
            get
            {
                return this.nroDestino;
            }
        }

        public Llamada(float duracion, string nroDestino, string nroOrigen)
        {
            this.duracion = duracion;
            this.nroDestino = nroDestino;
            this.nroOrigen = nroOrigen;
        }

        protected virtual string Mostrar()
        {
            StringBuilder sb = new StringBuilder();
            sb.AppendFormat("Llamada desde {0} hacia {1} con duración de {2} minutos", this.NroOrigen, this.NroDestino, this.Duracion);
            return sb.ToString();
        }

        public static int OrdenarPorDuracion(Llamada llamada1, Llamada llamada2)
        {
            if (llamada1.Duracion > llamada2.Duracion)
                return 1;
            else if (llamada1.Duracion < llamada2.Duracion)
                return -1;
            else
                return 0;
        }

        public static bool operator ==(Llamada l1, Llamada l2)
        {
            if (l1.Equals(l2) && l1.NroDestino == l2.NroDestino && l1.NroOrigen == l2.NroOrigen)
                return true;
            else
                return false;
        }

        public static bool operator !=(Llamada l1, Llamada l2)
        { return !(l1 == l2); }
    }
}
