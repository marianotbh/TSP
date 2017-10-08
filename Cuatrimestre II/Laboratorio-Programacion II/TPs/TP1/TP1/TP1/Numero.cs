using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TP1
{
    class Numero
    {
        double num;

        public double getNumero()
        {
            return num;
        }
        public Numero()
        {
            num = 0;
        }
        public Numero(string str)
        {
            setNumero(str);
        }
        public Numero(double dbl)
        {
            num = dbl;
        }
        void setNumero(string str)
        {
            num = validarNumero(str);
        }
        double validarNumero(string str)
        {
            double aux;
            double ret;
            if (double.TryParse(str, out aux))
                ret = aux;
            else
                ret = 0;
            return ret;
        }
    }
}
