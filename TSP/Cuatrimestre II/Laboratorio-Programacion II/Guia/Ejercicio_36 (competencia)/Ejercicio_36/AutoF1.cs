using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejercicio_36
{
    class AutoF1 : VehiculoDeCarrera
    {
        short caballosDeFuerza;

        public short CaballosDeFuerza
        {
            get
            {
                return this.caballosDeFuerza;
            }
            set
            {
                this.caballosDeFuerza = value;
            }
        }

        public AutoF1(short numero, string escuderia)
            : base(numero, escuderia)
        { }

        public AutoF1(short numero, string escuderia, short caballosDeFuerza)
            : this(numero, escuderia)
        {
            this.caballosDeFuerza = caballosDeFuerza;
        }

        public string MostrarDatos()
        {
            StringBuilder sb = new StringBuilder();
            sb.Append("Auto " + base.MostrarDatos());
            sb.Append(" - Caballos de Fuerza: " + this.CaballosDeFuerza);
            return sb.ToString();
        }

        public static bool operator ==(AutoF1 a1, AutoF1 a2)
        {
            if ((VehiculoDeCarrera)a1 == (VehiculoDeCarrera)a2 && a1.CaballosDeFuerza == a2.CaballosDeFuerza)
                return true;
            else
                return false;
        }

        public static bool operator !=(AutoF1 a1, AutoF1 a2)
        { return !(a1 == a2); }
    }
}
