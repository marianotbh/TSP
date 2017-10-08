using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TP1
{
    class Calculadora
    {
        static public double operar(Numero num1, Numero num2, string operador)
        {
            double result = 0;
            operador = validarOperador(operador);
            switch(operador)
            {
                case "+":
                    result = num1.getNumero() + num2.getNumero();
                    break;
                case "-":
                    result = num1.getNumero() - num2.getNumero();
                    break;
                case "*":
                    result = num1.getNumero() * num2.getNumero();
                    break;
                case "/":
                    if (num2.getNumero() != 0)
                        result = num1.getNumero() / num2.getNumero();
                    else
                        result = 0;
                    break;
            }
            return result;
        }
        static string validarOperador(string operador)
        {
            if (operador != "+" && operador != "-" && operador != "*" && operador != "/")
                operador = "+";
            return operador;
        }
    }
}
