using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejercicio_47
{
    class Program
    {
        static void Main(string[] args)
        {
            Factura factura = new Factura(999);
            Recibo reciboSinNumero = new Recibo();
            Recibo reciboConNumero = new Recibo(666);

            Contabilidad<Factura, Recibo> conta = new Contabilidad<Factura,Recibo>();
            conta += factura;
            conta += reciboSinNumero;
            conta += reciboConNumero;
        }
    }
}
