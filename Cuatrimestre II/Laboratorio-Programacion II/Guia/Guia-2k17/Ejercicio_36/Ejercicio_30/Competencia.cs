using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejercicio_36
{
    class Competencia
    {
        short cantidadCompetidores;
        short cantidadVueltas;
        List<VehiculoDeCarrera> competidores;
        TipoCompetencia tipo;

        public enum TipoCompetencia
        {
            F1,
            MotoCross
        }

        #region Propiedades
        public short CantidadCompetidores
        {
            get
            {
                return this.cantidadCompetidores;
            }
            set
            {
                this.cantidadCompetidores = value;
            }
        }
        public short CantidadVueltas
        {
            get
            {
                return this.cantidadVueltas;
            }
            set
            {
                this.cantidadVueltas = value;
            }
        }
        public VehiculoDeCarrera this[int i]
        {
            get
            {
                return this.competidores[i];
            }
        }
        public TipoCompetencia Tipo
        {
            get
            {
                return this.tipo;
            }
            set
            {
                this.tipo = value;
            }
        }
        #endregion

        Competencia()
        {
            this.competidores = new List<VehiculoDeCarrera> { };
        }

        public Competencia(short CantidadVueltas, short CantidadCompetidores, TipoCompetencia tipo)
            : this()
        {
            this.CantidadVueltas = CantidadVueltas;
            this.CantidadCompetidores = CantidadCompetidores;
            this.tipo = tipo;
        }

        public string MostrarDatos()
        {
            StringBuilder sb = new StringBuilder();
            sb.AppendLine("Competencia: ");
            sb.AppendFormat("Cantidad de vueltas: {0} - Cantidad de competidores: {1} \n", this.CantidadVueltas, this.CantidadCompetidores);
            sb.AppendLine("Competidores: ");
            foreach (VehiculoDeCarrera v in this.competidores)
            {
                sb.AppendLine(v.MostrarDatos());
            }
            return sb.ToString();
        }

        public static bool operator +(Competencia c, VehiculoDeCarrera v)
        {
            if (c != v && c.competidores.Count < c.CantidadCompetidores)
            {
                Random cantComb = new Random();
                v.CantidadCombustible = (short)cantComb.Next(15, 100);
                v.EnCompetencia = true;
                v.VueltasRestantes = c.CantidadVueltas;
                c.competidores.Add(v);
                return true;
            }
            else 
                return false;
        }
        public static bool operator -(Competencia c, VehiculoDeCarrera v)
        {
            if (c == v)
            {
                c.competidores.Remove(v);
                return true;
            }
            return false;                
        }
        public static bool operator ==(Competencia c, VehiculoDeCarrera v)
        {
            foreach (VehiculoDeCarrera vehiculo in c.competidores)
            {
                if (vehiculo == v && ((vehiculo is AutoF1 && c.Tipo == TipoCompetencia.F1)||(vehiculo is MotoCross && c.Tipo == TipoCompetencia.MotoCross)))
                {
                    return true;
                }
            }
            return false;
        }
        public static bool operator !=(Competencia c, VehiculoDeCarrera v)
        {
            return !(c == v);
        }

        
    }
}
