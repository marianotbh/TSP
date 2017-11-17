using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

namespace Ejercicio_63
{
    class Program
    {
        static void Main(string[] args)
        {
            Caja c1 = new Caja();
            Caja c2 = new Caja();
            Negocio neg = new Negocio(c1, c2);

            for (int i = 0; i < 10; i++)
                neg.Clientes.Add("Cliente" + i.ToString());

            Thread tAsignaCajas = new Thread(neg.AsignarCaja);
            Thread tAtenderCaja1 = new Thread(c1.AtenderClientes);
            tAtenderCaja1.Name = "Caja 1";
            Thread tAtenderCaja2 = new Thread(c2.AtenderClientes);
            tAtenderCaja2.Name = "Caja 2";

            tAsignaCajas.Start();
            tAsignaCajas.Join();
            tAtenderCaja1.Start();
            tAtenderCaja2.Start();            

            Console.ReadKey();
        }
    }
}
