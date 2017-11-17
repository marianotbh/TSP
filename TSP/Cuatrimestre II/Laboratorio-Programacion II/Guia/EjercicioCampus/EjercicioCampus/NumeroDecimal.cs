using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EjercicioCampus
{
    public class NumeroDecimal
    {
        public double numDec;

        private NumeroDecimal(double num)
        {
            this.numDec = num;
        }
        public static double operator +(NumeroDecimal numDecimal, NumeroBinario numBinario)
        {
            double resultado;
            resultado = Conversor.BinarioDecimal(numBinario.numBin) + numDecimal.numDec;
            return resultado;
        }
        public static double operator -(NumeroDecimal numDecimal, NumeroBinario numBinario)
        {
            double resultado;
            resultado = Conversor.BinarioDecimal(numBinario.numBin) - numDecimal.numDec;
            return resultado;
        }
        public static bool operator ==(NumeroDecimal numDecimal, NumeroBinario numBinario)
        {
            bool retorno;
            if (Conversor.BinarioDecimal(numBinario.numBin) == numDecimal.numDec)
                retorno = true;
            else
                retorno = false;
            return retorno;
        }
        public static bool operator !=(NumeroDecimal numDecimal, NumeroBinario numBinario)
        {
            bool retorno;
            if (Conversor.BinarioDecimal(numBinario.numBin) != numDecimal.numDec)
                retorno = true;
            else
                retorno = false;
            return retorno;
        }

        public static implicit operator NumeroDecimal(double num)
        {
            NumeroDecimal obj = new NumeroDecimal(num);
            return obj;
        }
        public static explicit operator double(NumeroDecimal num)
        {
            double numero = num.numDec;
            return numero;
        }
    }
}
