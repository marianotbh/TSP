using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejercicio_58
{
    class FallaLogException : Exception
    {
        public FallaLogException()
            : this("Falla Log Exception")
        { }

        public FallaLogException(string message)
            : base(message)
        { }

        public FallaLogException(string message, Exception innerException)
            : base(message, innerException)
        { }
    }
}
