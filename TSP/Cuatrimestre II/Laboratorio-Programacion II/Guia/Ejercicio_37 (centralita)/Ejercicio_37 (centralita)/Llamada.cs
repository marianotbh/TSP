using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejercicio_37
{
    class Llamada
    {
        protected float _duracion;
        protected string _nroOrigen;
        protected string _nroDestino;

        public enum TipoLlamada
        {
            Local,
            Provincial,
            Todas
        }

        public float Duracion
        {
            get
            {
                return this._duracion;
            }
        }

        public string NroOrigen
        {
            get
            {
                return this._nroOrigen;
            }
        }

        public string NroDestino
        {
            get
            {
                return this._nroDestino;
            }
        }

        public Llamada(float duracion, string nroDestino, string nroOrigen)
        {
            this._duracion = duracion;
            this._nroDestino = nroDestino;
            this._nroOrigen = nroOrigen;
        }

        public string Mostrar()
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
    }
}
