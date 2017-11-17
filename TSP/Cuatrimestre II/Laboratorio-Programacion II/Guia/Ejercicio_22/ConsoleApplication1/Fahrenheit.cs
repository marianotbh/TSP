using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Fahrenheit
{
    public class Fahrenheit
    {
        public double temp;
        
        public static double operator +(Fahrenheit f, Kelvin.Kelvin k)
        {
            double resultado;
            Fahrenheit toF = k;
            resultado = f.temp + toF.temp;
            return resultado;
        }
        public static double operator +(Fahrenheit f, Celsius.Celsius c)
        {
            double resultado;
            Fahrenheit toF = c;
            resultado = f.temp + toF.temp;
            return resultado;
        }
        public static double operator -(Fahrenheit f, Kelvin.Kelvin k)
        {
            double resultado;
            Fahrenheit toF = k;
            resultado = f.temp - toF.temp;
            return resultado;
        }
        public static double operator -(Fahrenheit f, Celsius.Celsius c)
        {
            double resultado;
            Fahrenheit toF = c;
            resultado = f.temp - toF.temp;
            return resultado;
        }
        public static double operator *(Fahrenheit f, Kelvin.Kelvin k)
        {
            double resultado;
            Fahrenheit toF = k;
            resultado = f.temp * toF.temp;
            return resultado;
        }
        public static double operator *(Fahrenheit f, Celsius.Celsius c)
        {
            double resultado;
            Fahrenheit toF = c;
            resultado = f.temp * toF.temp;
            return resultado;
        }
        public static double operator /(Fahrenheit f, Kelvin.Kelvin k)
        {
            double resultado;
            Fahrenheit toF = k;
            resultado = f.temp / toF.temp;
            return resultado;
        }
        public static double operator /(Fahrenheit f, Celsius.Celsius c)
        {
            double resultado;
            Fahrenheit toF = c;
            resultado = f.temp / toF.temp;
            return resultado;
        }

        public static bool operator ==(Fahrenheit f, Kelvin.Kelvin k)
        {
            bool resultado = false;
            Fahrenheit toF = k;
            if (f.temp == toF.temp)
                resultado = true;
            return resultado;
        }
        public static bool operator ==(Fahrenheit f, Celsius.Celsius c)
        {
            bool resultado = false;
            Fahrenheit toF = c;
            if (f.temp == toF.temp)
                resultado = true;
            return resultado;
        }
        public static bool operator !=(Fahrenheit f, Kelvin.Kelvin k)
        {
            bool resultado = false;
            Fahrenheit toF = k;
            if (f.temp != toF.temp)
                resultado = true;
            return resultado;
        }
        public static bool operator !=(Fahrenheit f, Celsius.Celsius c)
        {
            bool resultado = false;
            Fahrenheit toF = c;
            if (f.temp != toF.temp)
                resultado = true;
            return resultado;
        }

        public static implicit operator Fahrenheit(double d)
        {
            Fahrenheit f = new Fahrenheit();
            f.temp = d;
            return f;
        }
        public static implicit operator Fahrenheit(Kelvin.Kelvin k)
        {
            Fahrenheit f = new Fahrenheit();
            f.temp = k.temp *  9 / 5 - 459.67;
            return f;
        }
        public static implicit operator Fahrenheit(Celsius.Celsius c)
        {
            Fahrenheit f = new Fahrenheit();
            f.temp = (c.temp * (9.0/5)) + 32;
            return f;
        }
    }
}
