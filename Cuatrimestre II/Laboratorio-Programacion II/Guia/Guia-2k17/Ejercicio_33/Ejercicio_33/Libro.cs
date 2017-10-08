using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejercicio_33
{
    class Libro
    {
        List<string> paginas;
        
        public string this[int i]
        {
            get
            {

            }
            set
            {
            }
        }

        public static bool operator +(Libro l, string pagina)
        {
            bool ret = false;

            return ret;
        }
        public static bool operator ==(Libro l, string pagina)
        {
            bool ret = false;
            foreach (string p in l.paginas)
            {
                if (p == pagina)
                {
                    ret = true;
                    break;
                }
            }
            return ret;
        }
        public static bool operator !=(Libro l, string pagina)
        {
            return !(l == pagina);
        }
    }
}
