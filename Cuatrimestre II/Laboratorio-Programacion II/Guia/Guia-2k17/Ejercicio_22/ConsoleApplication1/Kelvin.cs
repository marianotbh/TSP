using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Kelvin
{
    public class Kelvin
    {
        public double temp;

        public static double operator +(Kelvin k, Celsius.Celsius c)
        {
            double resultado;
            Kelvin toK = c;
            resultado = k.temp + toK.temp;
            return resultado;
        }
        public static double operator +(Kelvin k, Fahrenheit.Fahrenheit f)
        {
            double resultado;
            Kelvin toK = f;
            resultado = k.temp + toK.temp;
            return resultado;
        }
        public static double operator -(Kelvin k, Celsius.Celsius c)
        {
            double resultado;
            Kelvin toK = c;
            resultado = k.temp - toK.temp;
            return resultado;
        }
        public static double operator -(Kelvin k, Fahrenheit.Fahrenheit f)
        {
            double resultado;
            Kelvin toK = f;
            resultado = k.temp - toK.temp;
            return resultado;
        }
        public static double operator *(Kelvin k, Celsius.Celsius c)
        {
            double resultado;
            Kelvin toK = c;
            resultado = k.temp * toK.temp;
            return resultado;
        }
        public static double operator *(Kelvin k, Fahrenheit.Fahrenheit f)
        {
            double resultado;
            Kelvin toK = f;
            resultado = k.temp * toK.temp;
            return resultado;
        }
        public static double operator /(Kelvin k, Celsius.Celsius c)
        {
            double resultado;
            Kelvin toK = c;
            resultado = k.temp / toK.temp;
            return resultado;
        }
        public static double operator /(Kelvin k, Fahrenheit.Fahrenheit f)
        {
            double resultado;
            Kelvin toK = f;
            resultado = k.temp / toK.temp;
            return resultado;
        }

        public static bool operator ==(Kelvin k, Celsius.Celsius c)
        {
            bool resultado = false;
            Kelvin toK = c;
            if(k.temp == toK.temp)
                resultado = true;
            return resultado;
        }
        public static bool operator ==(Kelvin k, Fahrenheit.Fahrenheit f)
        {
            bool resultado = false;
            Kelvin toK = f;
            if(k.temp == toK.temp)
                resultado = true;
            return resultado;
        }
        public static bool operator !=(Kelvin k, Celsius.Celsius c)
        {
            bool resultado = false;
            Kelvin toK = c;
            if (k.temp != toK.temp)
                resultado = true;
            return resultado;
        }
        public static bool operator !=(Kelvin k, Fahrenheit.Fahrenheit f)
        {
            bool resultado = false;
            Kelvin toK = f;
            if (k.temp != toK.temp)
                resultado = true;
            return resultado;
        }

        public static implicit operator Kelvin(double d)
        {
            Kelvin k = new Kelvin();
            k.temp = d;
            return k;
        }
        public static implicit operator Kelvin(Fahrenheit.Fahrenheit f)
        {
            Kelvin k = new Kelvin();
            k.temp = (f.temp + 459.67) * 5/9;
            return k;
        }
        public static implicit operator Kelvin(Celsius.Celsius c)
        {
            Kelvin k = new Kelvin();
            k.temp = c.temp + 273.15;
            return k;
        }
    }
}
