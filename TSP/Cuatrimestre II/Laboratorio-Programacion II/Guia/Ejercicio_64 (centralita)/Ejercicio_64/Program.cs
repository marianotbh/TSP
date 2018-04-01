using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

namespace Ejercicio_64
{
    class Program
    {
        static void Main(string[] args)
        {
            // Mi central Centralita
            Centralita c = new Centralita("Fede Center");
            c.RutaDeArchivo = "../../../Log.txt";
            c.LlamadaAgregada += c.OnLlamadaAgregada;

            Thread llamadas = new Thread(new ParameterizedThreadStart(Centralita.GenerarLlamada));
            Thread menu = new Thread(new ParameterizedThreadStart(Program.Menu));

            menu.Start(c);
            llamadas.Start(c);
            menu.Join();
            llamadas.Abort();
            menu.Abort();

            
        }

        public void OnLlamadaAgregada(object source, EventArgs args)
        {
            Console.WriteLine("Ganancias por llamadas locales: " + c.GananciasPorLocal);
            Console.WriteLine("Ganancias por llamadas provinciales: " + c.GananciasPorProvincial);
            Console.WriteLine("Ganancias por el total de las llamadas: " + c.GananciasPorTotal);
        }

        public static void Menu(object c)
        {
            char input;
            bool seguir = true;
            if(c is Centralita)
                c = (Centralita)c;
            else
                throw new FallaLogException("No paso una central valida");

            do
            {
                Console.WriteLine("MENU");
                Console.WriteLine("1 = Ver detalle de llamadas locales");
                Console.WriteLine("2 = Ver detalle de llamadas provinciales");
                Console.WriteLine("3 = Ver detalle de todas las llamadas");
                Console.WriteLine("4 = Exit");
                input = Console.ReadKey().KeyChar;

                Console.Clear();

                switch (input)
                {
                    case '1':
                        Console.WriteLine("Ganancias por llamadas locales: " + ((Centralita)c).GananciasPorLocal);
                        break;
                    case '2':
                        Console.WriteLine("Ganancias por llamadas provinciales: " + ((Centralita)c).GananciasPorProvincial);
                        break;
                    case '3':
                        Console.WriteLine("Ganancias por el total de las llamadas: " + ((Centralita)c).GananciasPorTotal);
                        break;
                    case '4':
                        seguir = false;
                        Console.WriteLine("Saliendo...");
                        break;
                    default:
                        Console.WriteLine("Ingrese una opcion valida");
                        break;
                }
            } while (seguir == true);
        }
    }
}
