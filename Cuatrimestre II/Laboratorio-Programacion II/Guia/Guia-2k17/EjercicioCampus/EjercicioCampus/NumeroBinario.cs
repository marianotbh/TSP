using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EjercicioCampus
{
    public class NumeroBinario
    {
        public string numBin;

        private NumeroBinario(string num)
        {
            this.numBin = num;
        }

        public static string operator +(NumeroBinario numBinario, NumeroDecimal numDecimal)
        {
            double resultado;
            resultado = Conversor.BinarioDecimal(numBinario.numBin) + numDecimal.numDec;
            return Conversor.DecimalBinario(resultado);
        }
        public static string operator -(NumeroBinario numBinario, NumeroDecimal numDecimal)
        {
            double resultado;
            resultado = Conversor.BinarioDecimal(numBinario.numBin) - numDecimal.numDec;
            return Conversor.DecimalBinario(resultado);
        }
        public static bool operator ==(NumeroBinario numBinario, NumeroDecimal numDecimal)
        {
            bool retorno;
            if (Conversor.BinarioDecimal(numBinario.numBin) == numDecimal.numDec)
                retorno = true;
            else
                retorno = false;
            return retorno;
        }
        public static bool operator !=(NumeroBinario numBinario, NumeroDecimal numDecimal)
        {
            bool retorno;
            if (Conversor.BinarioDecimal(numBinario.numBin) != numDecimal.numDec)
                retorno = true;
            else
                retorno = false;
            return retorno;
        }

        public static implicit operator NumeroBinario(string num)
        {
            NumeroBinario obj = new NumeroBinario(num);
            return obj;
        }
        public static explicit operator string(NumeroBinario num)
        {
            string numero = num.numBin;
            return numero;
        }
    }
}
