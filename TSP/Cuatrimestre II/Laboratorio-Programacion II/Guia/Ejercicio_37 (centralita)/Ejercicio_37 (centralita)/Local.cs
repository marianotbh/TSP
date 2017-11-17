using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejercicio_37
{
    class Local : Llamada
    {
        protected float _costo;

        public float CostoLlamada
        {
            get
            {
                return this.CalcularCosto();
            }
        }

        public Local(Llamada llamada, float costo)
            : base(llamada.Duracion, llamada.NroDestino, llamada.NroOrigen)
        {
            this._costo = costo;
        }

        public Local(string origen, float duracion, string destino, float costo)
            : this(new Llamada(duracion, destino, origen), costo)
        { }

        float CalcularCosto()
        {
            return this.Duracion * this._costo;
        }

        public string Mostrar()
        {
            StringBuilder sb = new StringBuilder();
            sb.AppendLine(base.Mostrar());
            sb.AppendLine("Costo de la llamada: " + this.CostoLlamada);
            return sb.ToString();
        }
    }
}
