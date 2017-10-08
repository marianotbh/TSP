using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    public class Perro:Animal
    {
        static int _patas;
        Razas raza;

        public enum Razas 
        { 
            Galgo,
            OvejeroAleman
        }

        static Perro()
        { _patas = 4; }

        public Perro(Razas raza, int velocidadMaxima)
            :this(velocidadMaxima)
        {
            this.raza = raza;
        }

        public Perro(int velocidadMaxima)
            : base(_patas, velocidadMaxima)
        { }

        public string MostrarPerro()
        { return String.Format("Perro: {0} - {1}", this.raza, this.MostrarDatos()); }

        public static bool operator ==(Perro p1, Perro p2)
        {
            if (p1.VelocidadMaxima == p2.VelocidadMaxima && p1.raza == p2.raza)
                return true;
            else
                return false;
        }
        public static bool operator !=(Perro p1, Perro p2)
        { return !(p1 == p2); }
    }
}
