using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

namespace Ejercicio_63
{
    class Caja
    {
        List<string> filaClientes;

        public List<string> FilaClientes
        {
            get { return this.filaClientes; }
        }

        public Caja()
        {
            filaClientes = new List<string>();
        }

        public void AtenderClientes()
        {
            
            foreach (string cliente in this.FilaClientes)
            {
                Random r = new Random(cliente.Length);
                Thread.Sleep(r.Next(1000,10000));
                Console.WriteLine(String.Format("{0} Cliente: {1}", Thread.CurrentThread.Name, cliente));
            }
        }

    }
}
