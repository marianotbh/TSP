using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejercicio_36
{
    class MotoCross : VehiculoDeCarrera
    {
        short cilindrada;

        public short Cilindrada
        {
            get
            {
                return this.cilindrada;
            }
            set
            {
                this.cilindrada = value;
            }
        }

        public MotoCross(short numero, string escuderia)
            : base(numero, escuderia)
        { }
        public MotoCross(short numero, string escuderia, short cilindrada)
            : this(numero, escuderia)
        {
            this.Cilindrada = cilindrada;
        }

        public override string MostrarDatos()
        {
            StringBuilder sb = new StringBuilder();
            sb.AppendLine(base.MostrarDatos());
            sb.AppendFormat("Cilindrada: {0}", this.Cilindrada);
            return sb.ToString();
        }

        public static bool operator ==(MotoCross m1, MotoCross m2)
        {
            if(m1.Numero == m2.Numero && m1.Escuderia == m2.Escuderia && m1.Cilindrada == m2.Cilindrada)
                return true;
            else
                return false;
        }
        public static bool operator !=(MotoCross m1, MotoCross m2)
        {
            return !(m1 == m2);
        }
    }
}
