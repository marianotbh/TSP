using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    public class Humano:Animal
    {
        string _apellido;
        string _nombre;
        static int _piernas;

        static Humano()
        {
            _piernas = 2;
        }

        public Humano(int velocidadMaxima)
            :base(_piernas , velocidadMaxima)
        { }

        public Humano(string nombre, string apellido, int velocidadMaxima)
            :this(velocidadMaxima)
        {
            this._nombre = nombre;
            this._apellido = apellido;
        }

        public string MostrarHumano()
        {
            return String.Format("{0} {1} - {2}", this._nombre, this._apellido, this.MostrarDatos());
        }

        public static bool operator ==(Humano h1, Humano h2)
        {
            if (h1._nombre == h2._nombre && h1._apellido == h2._apellido)
                return true;
            else
                return false;
        }
        public static bool operator !=(Humano h1, Humano h2)
        { return !(h1 == h2); }
    }
}
