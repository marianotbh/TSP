using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

namespace Ejercicio_63
{
    class Negocio
    {
        Caja caja1;
        Caja caja2;
        List<string> clientes;

        public Caja Caja1
        {
            get { return this.caja1; }
        }

        public Caja Caja2
        {
            get { return this.caja2; }
        }

        public List<string> Clientes
        {
            get { return this.clientes; }
        }

        public Negocio(Caja c1, Caja c2)
        {
            this.caja1 = c1;
            this.caja2 = c2;
            this.clientes = new List<string>();
        }

        public void AsignarCaja()
        {
            Console.WriteLine("Asignando Cajas...");
            foreach (string cliente in this.Clientes)
            {
                if (Caja1.FilaClientes.Count < Caja2.FilaClientes.Count)
                    Caja1.FilaClientes.Add(cliente);
                else if (Caja1.FilaClientes.Count > Caja2.FilaClientes.Count)
                    Caja2.FilaClientes.Add(cliente);
                else
                    Caja1.FilaClientes.Add(cliente);
                Thread.Sleep(1000);
            }
        }
    }
}
