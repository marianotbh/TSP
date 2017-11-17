using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejercicio_56
{
    class Program
    {
        static void Main(string[] args)
        {
            Persona p = new Persona("Pepito", "Jones");
            try
            {
                Persona.Guardar(p);
                Console.WriteLine("Guardado con exito");                
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }

            p = null;

            Console.ReadKey();
            Console.Clear();

            try
            {
                p = Persona.Leer();
                Console.WriteLine("Leido: "+p.ToString());
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }

            Console.ReadKey();
        }
    }
}
