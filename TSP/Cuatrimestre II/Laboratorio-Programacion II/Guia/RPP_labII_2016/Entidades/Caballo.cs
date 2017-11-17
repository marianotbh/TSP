using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    public class Caballo:Animal
    {
        string _nombre;
        static int _patas;

        static Caballo()
        { _patas = 4; }

        public Caballo(string nombre, int velocidadMaxima)
            :base(_patas, velocidadMaxima)
        { this._nombre = nombre; }

        public string MostrarCaballo()
        { return String.Format("Caballo: {0} - {1}", this._nombre, this.MostrarDatos()); }

        public static bool operator ==(Caballo c1, Caballo c2)
        {
            if (c1._nombre == c2._nombre)
                return true;
            else
                return false;
        }
        public static bool operator !=(Caballo c1, Caballo c2)
        { return !(c1 == c2); }

    }
}
