using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CentralTelefonica
{
    public class Provincial:Llamada
    {
        protected Franja _franjaHoraria;

        public enum Franja
        {
            Franja_1,
            Franja_2,
            Franja_3
        }

        public override float CostoLlamada
        {
            get
            {
                return this.CalcularCosto();
            }
        }

        public Provincial(Franja miFranja, Llamada llamada)
            :this(llamada.NroOrigen, miFranja, llamada.Duracion, llamada.NroDestino)
        {  }
        public Provincial(string origen, Franja miFranja, float duracion, string destino)
            :base(duracion, destino, origen)
        {
            this._franjaHoraria = miFranja;
        }


        float CalcularCosto()
        {
            float ret;
            if (this._franjaHoraria == Franja.Franja_1)
                ret = base.Duracion * 0.99f;
            else if (this._franjaHoraria == Franja.Franja_2)
                ret = base.Duracion * 1.25f;
            else
                ret = base.Duracion * 0.66f;
            return ret;
        }

        protected override string Mostrar()
        {
            StringBuilder display = new StringBuilder();
            display.AppendLine(base.Mostrar());
            display.AppendLine("Costo: " + this.CostoLlamada);
            display.AppendLine("Franja horaria: " + this._franjaHoraria);
            return display.ToString();
        }

        public override bool Equals(object obj)
        {
            return (obj is Provincial);
        }

        public override string ToString()
        {
            return this.Mostrar();
        }
    }
}
