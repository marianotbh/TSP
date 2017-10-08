using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CentralTelefonica
{
    public abstract class Llamada
    {
        protected float _duracion;
        protected string _nroDestino;
        protected string _nroOrigen;

        public enum TipoLlamada
        {
            Local,
            Provincial,
            Todas
        }

        public abstract float CostoLlamada { get; }

        public float Duracion
        {
            get
            {
                return this._duracion;
            }
        }
        public string NroDestino
        {
            get
            {
                return this._nroDestino;
            }
        }
        public string NroOrigen
        {
            get
            {
                return this._nroOrigen;
            }
        }

        public Llamada(float duracion, string nroDestino, string nroOrigen)
        {

            this._duracion = duracion;
            this._nroDestino = nroDestino;
            this._nroOrigen = nroOrigen;
        }
        
        public static int OrdenarPorDuracion(Llamada llamada1, Llamada llamada2)
        {
            int ret;
            if (llamada1.Duracion < llamada2.Duracion)
                ret = -1;
            else if (llamada1.Duracion > llamada2.Duracion)
                ret = 1;
            else
                ret = 0;
            return ret;
        }
        protected virtual string Mostrar()
        {
            StringBuilder display = new StringBuilder();
            display.AppendLine("Duracion: " + this.Duracion);
            display.AppendLine("Nro Destino: " + this.NroDestino);
            display.AppendLine("Nro Origen: " + this.NroOrigen);
            return display.ToString();
        }

        public static bool operator ==(Llamada ll1, Llamada ll2)
        {
            return (ll1.Equals(ll2) && ll1.NroDestino == ll2.NroDestino && ll1.NroOrigen == ll2.NroOrigen);
        }
        public static bool operator !=(Llamada ll1, Llamada ll2)
        {
            return !(ll1 == ll2);
        }

    }
}
