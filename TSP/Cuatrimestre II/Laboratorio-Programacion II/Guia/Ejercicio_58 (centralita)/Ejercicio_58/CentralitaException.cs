using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejercicio_58
{
    public class CentralitaException : Exception
    {
        string nombreClase;
        string nombreMetodo;

        public Exception ExcepcionInterna
        {
            get
            {
                return this.InnerException;
            }
        }
        public string NombreClase
        {
            get
            {
                return this.nombreClase;
            }
        }
        public string NombreMetodo
        {
            get
            {
                return this.nombreMetodo;
            }
        }

        public CentralitaException(string mensaje, string clase, string metodo)
            : base(mensaje)
        {
            this.nombreClase = clase;
            this.nombreMetodo = metodo;
        }

        public CentralitaException(string mensaje, string clase, string metodo, Exception innerException)
            : base(mensaje, innerException)
        {
            this.nombreClase = clase;
            this.nombreMetodo = metodo;
        }

        public override string ToString()
        {
            StringBuilder sb = new StringBuilder();
            sb.AppendLine(this.Message);
            sb.AppendFormat("Excepción en el método {0} de la clase {1}\n", this.NombreMetodo, this.NombreClase);
            return sb.ToString();
        }
    }
}
