using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejercicio_48
{
    public class MotoCross : VehiculoDeCarrera
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
            sb.Append("Moto " + base.MostrarDatos());
            sb.Append(" - Cilindrada: " + this.Cilindrada);
            return sb.ToString();
        }

        public static bool operator ==(MotoCross m1, MotoCross m2)
        {
            if ((VehiculoDeCarrera)m1 == (VehiculoDeCarrera)m2 && m1.Cilindrada == m2.Cilindrada)
                return true;
            else
                return false;
        }

        public static bool operator !=(MotoCross m1, MotoCross m2)
        { return !(m1 == m2); }
    }
}
