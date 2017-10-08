using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CentralTelefonica
{
    public class Local:Llamada
    {
        protected float _costo;

        public override float CostoLlamada
        {
            get
            {
                return CalcularCosto();
            }
        }

        public Local(Llamada llamada, float costo) : base(llamada.Duracion, llamada.NroDestino, llamada.NroOrigen)
        {
            this._costo = costo;
        }
        public Local(string origen, float duracion, string destino, float costo) : base(duracion, destino, origen)
        {
            this._costo = costo;
        }

        float CalcularCosto()
        {
            return this._costo * base._duracion;
        }

        protected override string Mostrar()
        {
            StringBuilder display = new StringBuilder();
            display.AppendLine(base.Mostrar());
            display.AppendLine("Costo llamada: " + this.CostoLlamada);
            return display.ToString();
        }

        public override bool Equals(object obj)
        {
            return (obj is Local);
        }

        public override string ToString()
        {
            return this.Mostrar();
        }
    }
}
