using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejercicio_37
{
    class Centralita
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
                        gain += ((Local)ll).CostoLlamada;
            }                
            else if (tipo == Llamada.TipoLlamada.Provincial)
            {
                foreach (Llamada ll in this.Llamadas)
                    if (ll is Provincial)
                        gain += ((Provincial)ll).CostoLlamada;
            }                
            else
            {
                foreach(Llamada ll in this.Llamadas)
                {
                    if (ll is Local)
                        gain += ((Local)ll).CostoLlamada;
                    else if( ll is Provincial)
                        gain += ((Provincial)ll).CostoLlamada;
                }
            }
            return gain;
        }

        public void OrdenarLlamadas()
        {
            this.Llamadas.Sort(Llamada.OrdenarPorDuracion);
        }

        public string Mostrar()
        {
            StringBuilder sb = new StringBuilder();
            sb.AppendLine("Central: " + this.razonSocial);
            sb.AppendLine("");
            sb.AppendLine("Ganancias por el total de las llamadas: " + this.GananciasPorTotal);
            sb.AppendLine("Ganancias por llamadas locales: " + this.GananciasPorLocal);
            sb.AppendLine("Ganancias por llamadas provinciales" + this.GananciasPorProvincial);
            sb.AppendLine("");
            sb.AppendLine("Detalle de llamadas:");
            foreach(Llamada ll in this.Llamadas)
            {
                if(ll is Local)
                    sb.AppendLine(((Local)ll).Mostrar());
                else if(ll is Provincial)
                    sb.AppendLine(((Provincial)ll).Mostrar());
            }
            return sb.ToString();
        }
    }
}
