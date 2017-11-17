using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejercicio_45
{
    class Program
    {
        static void Main(string[] args)
        {
            try
            {
                MetodoDeInstancia mdi = new MetodoDeInstancia();
                mdi.MetodoDInstancia();
            }
            catch (Exception e)
            {
                do
                {
                    Console.WriteLine(e.Message);
                    e = e.InnerException;
                }while(!object.ReferenceEquals(e,null));
            }
            Console.ReadKey();
        }

        
    }
}
