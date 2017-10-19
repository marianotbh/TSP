using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejercicio_47
{
    class Contabilidad<T, U>
        where T : Documento
        where U : Documento, new()
    {
        List<T> egresos;
        List<U> ingresos;

        public static Contabilidad<T, U> operator +(Contabilidad<T,U> cont, T egreso)
        {
            cont.egresos.Add(egreso);
            return cont;
        }

        public static Contabilidad<T, U> operator +(Contabilidad<T,U> cont, U ingreso)
        {
            cont.ingresos.Add(ingreso);
            return cont;
        }

        public Contabilidad()
        {
            egresos = new List<T>();
            ingresos = new List<U>();
        }
    }
}
