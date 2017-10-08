using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CentralTelefonica
{
    public class Centralita
    {
        List<Llamada> listaDeLlamadas;
        string razonSocial;

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

        Centralita()
        {
            listaDeLlamadas = new List<Llamada> { };
        }

        public Centralita(string razonSocial)
            :this()
        {
            this.razonSocial = razonSocial;
        }

        float CalcularGanancia(Llamada.TipoLlamada tipo)
        {
            float ganancia = 0;
            foreach (Llamada llamada in listaDeLlamadas)
            {
                switch (tipo)
                {
                    case Llamada.TipoLlamada.Local:
                        if (llamada is Local)
                            ganancia += llamada.CostoLlamada;   
                        break;
                    case Llamada.TipoLlamada.Provincial:
                        if (llamada is Provincial)
                            ganancia += llamada.CostoLlamada;
                        break;
                    case Llamada.TipoLlamada.Todas:
                            ganancia += llamada.CostoLlamada;
                        break;
                }
            }
            return ganancia;
        }

        string Mostrar()
        {
            StringBuilder display = new StringBuilder();
            display.AppendLine("Razon social: " + this.razonSocial);
            display.AppendLine("Ganancia total por llamadas locales: " + this.GananciasPorLocal);
            display.AppendLine("Ganancia total por llamadas provinciales: " + this.GananciasPorProvincial);
            display.AppendLine("Ganancia total: " + this.GananciasPorTotal);
            foreach (Llamada llamada in listaDeLlamadas)
            {
                display.AppendLine("---------------------------------------------------");
                display.AppendLine(llamada.ToString());
                display.AppendLine("---------------------------------------------------");
            }
            return display.ToString();
        }

        public override string ToString()
        {
            return this.Mostrar();
        }

        void AgregarLlamada(Llamada nuevaLlamada)
        {
            this.listaDeLlamadas.Add(nuevaLlamada);
        }

        public void OrdenarLlamadas()
        {
           this.listaDeLlamadas.Sort(Llamada.OrdenarPorDuracion);
        }

        public static bool operator ==(Centralita c, Llamada llamada)
        {
            foreach (Llamada ll in c.listaDeLlamadas)
                if (llamada == ll)
                    return true;
            return false;
        }
        public static bool operator !=(Centralita c, Llamada llamada)
        {
            return !(c == llamada);
        }
        public static Centralita operator +(Centralita c, Llamada nuevaLlamada)
        {
            if (c != nuevaLlamada)
            {
                c.AgregarLlamada(nuevaLlamada);
            }
            else
            {
                throw new CentralitaException("AAAAAAAAAAAAAAAAAAAAA", c.GetType().Name, "Operador +");
            }
            return c;
        }
    }
}
