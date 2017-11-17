using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejercicio_48
{
    public class CompetenciaNoDisponibleException : Exception
    {
        string nombreClase;
        string nombreMetodo;

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

        public CompetenciaNoDisponibleException(string mensaje, string clase, string metodo)
            : base(mensaje)
        {
            this.nombreClase = clase;
            this.nombreMetodo = metodo;
        }

        public CompetenciaNoDisponibleException(string mensaje, string clase, string metodo, Exception innerException)
            : base(mensaje, innerException)
        {
            this.nombreClase = clase;
            this.nombreMetodo = metodo;
        }

        public override string ToString()
        {
            StringBuilder sb = new StringBuilder();
            CompetenciaNoDisponibleException aux = this;
            sb.AppendFormat("Excepción del método {0} de la clase {1} \n", aux.NombreMetodo, aux.NombreClase);
            sb.AppendLine(aux.Message);
            sb.AppendLine("\nInner exceptions: ");
            while(aux.InnerException != null)
            {
                sb.AppendLine(aux.InnerException.Message);
                aux = (CompetenciaNoDisponibleException)aux.InnerException;
            }
            return sb.ToString(); 
        }
    }
}
