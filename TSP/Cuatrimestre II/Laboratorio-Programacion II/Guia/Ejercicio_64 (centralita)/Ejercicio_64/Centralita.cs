using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Threading;

namespace Ejercicio_64
{
    public delegate void LlamadaAgregadaEventHandler(object source, EventArgs args);

    public class Centralita : IGuardar<string>
    {
        List<Llamada> listaDeLlamadas;
        string razonSocial;
        string path;
        public event LlamadaAgregadaEventHandler LlamadaAgregada;

        public float GananciasPorLocal
        {
            get
            {
                return this.CalcularGanancia(Llamada.TipoLlamada.Local);
            }
        }
        public float GananciasPorProvincial
        {
            get
            {
                return this.CalcularGanancia(Llamada.TipoLlamada.Provincial);
            }
        }
        public float GananciasPorTotal
        {
            get
            {
                return this.CalcularGanancia(Llamada.TipoLlamada.Todas);
            }
        }
        public List<Llamada> Llamadas
        {
            get
            {
                return this.listaDeLlamadas;
            }
        }

        public string RutaDeArchivo
        {
            get
            {
                return this.path;
            }

            set
            {
                this.path = value;
            }
        }

        public Centralita()
        {
            this.listaDeLlamadas = new List<Llamada>();
        }
        public Centralita(string nombreEmpresa)
            : this()
        {
            this.razonSocial = nombreEmpresa;
        }

        float CalcularGanancia(Llamada.TipoLlamada tipo)
        {
            float gain = 0;
            if (tipo == Llamada.TipoLlamada.Local)
            {
                foreach (Llamada ll in this.Llamadas)
                    if (ll is Local)
                        gain += ll.CostoLlamada;
            }                
            else if (tipo == Llamada.TipoLlamada.Provincial)
            {
                foreach (Llamada ll in this.Llamadas)
                    if (ll is Provincial)
                        gain += ll.CostoLlamada;
            }                
            else
                foreach(Llamada ll in this.Llamadas)
                    gain += ll.CostoLlamada;
            return gain;
        }

        public void OrdenarLlamadas()
        {
            this.Llamadas.Sort(Llamada.OrdenarPorDuracion);
        }

        string Mostrar()
        {
            StringBuilder sb = new StringBuilder();
            sb.AppendLine("Central: " + this.razonSocial);
            sb.AppendLine("");
            sb.AppendLine("Ganancias por el total de las llamadas: " + this.GananciasPorTotal);
            sb.AppendLine("Ganancias por llamadas locales: " + this.GananciasPorLocal);
            sb.AppendLine("Ganancias por llamadas provinciales: " + this.GananciasPorProvincial);
            sb.AppendLine("");
            sb.AppendLine("Detalle de llamadas:");
            foreach (Llamada ll in this.Llamadas)
                sb.AppendLine(ll.ToString());
            return sb.ToString();
        }

        void AgregarLlamada(Llamada ll)
        {
            this.Llamadas.Add(ll);
            OnLlamadaAgregada(ll);
        }

        protected virtual void OnLlamadaAgregada(Llamada ll)
        {
            LlamadaAgregada(this, null);
        }







        public override string ToString()
        {
            return this.Mostrar();
        }

        public bool Guardar()
        {
            using (StreamWriter sw = new StreamWriter(this.RutaDeArchivo))
            {
                sw.WriteLine(DateTime.Now.ToLongDateString() + " " + DateTime.Now.ToShortTimeString() + " -- Se realizó una llamada.");
                sw.WriteLine(this.ToString());
            }
            return true;
        }

        public string Leer()
        {
            using (StreamReader sr = new StreamReader(this.RutaDeArchivo))
            {
                return sr.ReadToEnd();
            }
        }

        public static bool operator ==(Centralita c, Llamada ll)
        {
            foreach (Llamada llamada in c.Llamadas)
                if (ll == llamada)
                    return true;
            return false;
        }

        public static bool operator !=(Centralita c, Llamada ll)
        { return !(c == ll); }

        public static Centralita operator +(Centralita c, Llamada ll)
        {
            if (c != ll)
            {
                c.AgregarLlamada(ll);
                LocalDAO lDAO = new LocalDAO();
                ProvincialDAO pDAO = new ProvincialDAO();
                if (ll is Provincial)
                    pDAO.Guardar((Provincial)ll);
                else if (ll is Local)
                    lDAO.Guardar((Local)ll);
                if(!c.Guardar())
                    throw new FallaLogException("Falla al guardar");
            }                
            else
                throw new CentralitaException("La llamada ya se encuentra en la base de datos", "Centralita", "Operador +");
            return c;
        }

        public static void GenerarLlamada(object c)
        {
            if (c is Centralita)
            {
                c = (Centralita)c;
                Random r = new Random();

                List<string> lugares = new List<string>() { "Origen1", "Lugarrrr", "Allá", "Acá", "Lugarlugar" };
                List<int> franjas = new List<int>() { 99, 125, 66 };

                while (true)
                {
                    int res = r.Next(0, 1000);
                    try
                    {
                        if (res % 2 == 0)
                        {
                            Local l = new Local(lugares[r.Next(0, 4)], (float)r.Next(0, 100), lugares[r.Next(0, 4)], (float)r.Next(0, 100));
                            c = (Centralita)c + l;
                        }
                        else
                        {
                            Provincial p = new Provincial((float)r.Next(0, 100), (Provincial.Franja)franjas[r.Next(0, 2)], lugares[r.Next(0, 4)], lugares[r.Next(0, 4)]);
                            c = (Centralita)c + p;
                        }
                        Console.WriteLine("Llamada agregada");
                    }
                    catch (Exception e)
                    {
                        Console.WriteLine(e.Message);
                    }                    
                    Thread.Sleep(r.Next(500, 5000));
                }
            }
            else
                throw new FallaLogException("No se paso una central valida");
        }
    }
}
