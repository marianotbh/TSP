using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    public class Carrera
    {
        List<Animal> _animales;
        int _corredoresMax;

        Carrera()
        {
            _animales = new List<Animal> { };
        }

        public Carrera(int corredoresMax)
            : this()
        {
            this._corredoresMax = corredoresMax;
        }

        public static bool operator ==(Carrera c, Animal a)
        {
            foreach (Animal animal in c._animales)
                if (animal == a)
                    return true;
            return false;
        }

        public static bool operator !=(Carrera c, Animal a)
        { return !(c == a); }

        public static Carrera operator +(Carrera c, Animal a)
        {
            if (c != a && c._animales.Count < c._corredoresMax)
                c._animales.Add(a);
            return c;
        }

        public string MostrarCarrera(Carrera c)
        {
            StringBuilder carrera = new StringBuilder();
            carrera.AppendLine(this._animales.Count + " corredores");
            for (int i = 0; i < this._animales.Count; i++)
            {
                if (c._animales[i] is Humano)
                    carrera.AppendLine(((Humano)c._animales[i]).MostrarHumano());
                else if (c._animales[i] is Perro)
                    carrera.AppendLine(((Perro)c._animales[i]).MostrarPerro());
                else if (c._animales[i] is Caballo)
                    carrera.AppendLine(((Caballo)c._animales[i]).MostrarCaballo());
            }
            return carrera.ToString();
        }
    }
}
