using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Celsius
{
    public class Celsius
    {
        public double temp;

        public static double operator +(Celsius c, Kelvin.Kelvin k)
        {
            double resultado;
            Celsius toC = k;
            resultado = c.temp + toC.temp;
            return resultado;
        }
        public static double operator +(Celsius c, Fahrenheit.Fahrenheit f)
        {
            double resultado;
            Celsius toC = f;
            resultado = c.temp + toC.temp;
            return resultado;
        }
        public static double operator -(Celsius c, Kelvin.Kelvin k)
        {
            double resultado;
            Celsius toC = k;
            resultado = c.temp - toC.temp;
            return resultado;
        }
        public static double operator -(Celsius c, Fahrenheit.Fahrenheit f)
        {
            double resultado;
            Celsius toC = f;
            resultado = c.temp - toC.temp;
            return resultado;
        }
        public static double operator *(Celsius c, Kelvin.Kelvin k)
        {
            double resultado;
            Celsius toC = k;
            resultado = c.temp * toC.temp;
            return resultado;
        }
        public static double operator *(Celsius c, Fahrenheit.Fahrenheit f)
        {
            double resultado;
            Celsius toC = f;
            resultado = c.temp * toC.temp;
            return resultado;
        }
        public static double operator /(Celsius c, Kelvin.Kelvin k)
        {
            double resultado;
            Celsius toC = k;
            resultado = c.temp / toC.temp;
            return resultado;
        }
        public static double operator /(Celsius c, Fahrenheit.Fahrenheit f)
        {
            double resultado;
            Celsius toC = f;
            resultado = c.temp / toC.temp;
            return resultado;
        }

        public static bool operator ==(Celsius c, Kelvin.Kelvin k)
        {
            bool resultado = false;
            Celsius toC = k;
            if (c.temp == toC.temp)
                resultado = true;
            return resultado;
        }
        public static bool operator ==(Celsius c, Fahrenheit.Fahrenheit f)
        {
            bool resultado = false;
            Celsius toC = f;
            if (c.temp == toC.temp)
                resultado = true;
            return resultado;
        }
        public static bool operator !=(Celsius c, Kelvin.Kelvin k)
        {
            bool resultado = false;
            Celsius toC = k;
            if (c.temp != toC.temp)
                resultado = true;
            return resultado;
        }
        public static bool operator !=(Celsius c, Fahrenheit.Fahrenheit f)
        {
            bool resultado = false;
            Celsius toC = f;
            if (c.temp != toC.temp)
                resultado = true;
            return resultado;
        }



        public static implicit operator Celsius(double d)
        {
            Celsius c = new Celsius();
            c.temp = d;
            return c;
        }
        public static implicit operator Celsius(Kelvin.Kelvin k)
        {
            Celsius c = new Celsius();
            c.temp = k.temp - 273.15;
            return c;
        }
        public static implicit operator Celsius(Fahrenheit.Fahrenheit f)
        {
            Celsius c = new Celsius();
            c.temp = (f.temp - 32) * 5/9;
            return c;
        }
    }
}
