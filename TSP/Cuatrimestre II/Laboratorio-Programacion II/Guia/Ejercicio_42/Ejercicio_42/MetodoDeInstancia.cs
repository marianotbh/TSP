using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejercicio_42
{
    class MetodoDeInstancia
    {
        public void MetodoDInstancia()
        {
            try
            {
                new ExcepAux(0);
            }
            catch (Exception e)
            {
                throw new MiExcepcion("Mi Exception", e);
            }
        }
    }
}
