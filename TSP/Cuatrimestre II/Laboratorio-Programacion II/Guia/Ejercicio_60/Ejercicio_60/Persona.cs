using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejercicio_60
{
    public class Persona
    {
        string nombre;
        string apellido;

        public string Nombre
        {
            get
            { return this.nombre; }
            set
            { this.nombre = value; }
        }

        public string Apellido
        {
            get
            { return this.apellido; }
            set
            { this.nombre = value; }
        }

        public Persona(string nombre, string apellido)
        {
            this.nombre = nombre;
            this.apellido = apellido;
        }

    }
}
