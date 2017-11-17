using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejercicio_45
{
    class ExcepAux : Exception
    {
        public ExcepAux()
        {
            try
            {
                metodoStatico();
            }
            catch (DivideByZeroException e)
            {
                throw e;
            }
        }

        public ExcepAux(int a)
        {
            try
            {
                new ExcepAux();
            }
            catch(Exception e)
            {
                throw new UnaException("Una Exception", e);
            }
        }

        static void metodoStatico()
        {
            throw new DivideByZeroException();
        }
    }
}
