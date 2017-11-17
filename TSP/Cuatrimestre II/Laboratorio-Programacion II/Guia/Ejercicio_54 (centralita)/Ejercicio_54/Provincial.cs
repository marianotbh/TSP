using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejercicio_54
{
    public class Provincial : Llamada, IGuardar<Provincial>
    {
        protected Franja _franja;

        public enum Franja
        {
            Franja_1 = 99,
            Franja_2 = 125,
            Franja_3 = 66
        }

        public override float CostoLlamada
        {
            get
            {
                return this.CalcularCosto();
            }
        }

        public string RutaDeArchivo
        {
            get
            {
                throw new NotImplementedException();
            }

            set
            {
                throw new NotImplementedException();
            }
        }

        public Provincial(Franja miFranja, Llamada llamada)
            : this(llamada.Duracion, miFranja, llamada.NroOrigen, llamada.NroDestino)
        { }

        public Provincial(float duracion, Franja miFranja, string origen, string destino)
            : base(duracion, destino, origen)
        {
            this._franja = miFranja;
        }

        float CalcularCosto()
        {
            return this.Duracion * ((float)this._franja / 100);
        }

        protected override string Mostrar()
        {
            StringBuilder sb = new StringBuilder();
            sb.AppendLine(base.Mostrar());
            sb.AppendLine("Costo de llamada dentro de la " + this._franja + ": " + this.CostoLlamada);
            return sb.ToString();
        }

        public override bool Equals(object obj)
        {
            if (obj is Provincial)
                return true;
            else
                return false;
        }

        public override string ToString()
        {
            return this.Mostrar();
        }

        public bool Guardar()
        {
            Console.WriteLine(this.ToString());
            return true;
        }

        public Provincial Leer()
        {
            throw new NotImplementedException();
        }
    }
}
