using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejercicio_48
{
    public class Competencia<T>
        where T : VehiculoDeCarrera
    {
        short cantidadCompetidores;
        short cantidadVueltas;
        List<T> competidores;
        TipoCompetencia tipo;

        public enum TipoCompetencia
        {
            F1,
            MotoCross            
        }

        #region Properties
        public short CantidadDeCompetidores
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

        public short CantidadDeVueltas
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

        public List<T> Competidores
        {
            get
            {
                return this.competidores;
            }
        }
        #endregion

        Competencia()
        {
            this.competidores = new List<T>();
        }
        public Competencia(short cantidadVueltas, short cantidadCompetidores, TipoCompetencia tipo)
            : this()
        {
            this.CantidadDeVueltas = cantidadVueltas;
            this.CantidadDeCompetidores = cantidadCompetidores;
            this.Tipo = tipo;
        }

        public string MostrarDatos()
        {
            StringBuilder sb = new StringBuilder();
            sb.AppendFormat("Competencia de {0} de {1} vueltas \n{2} Participantes: \n", this.Tipo, this.CantidadDeVueltas, this.CantidadDeCompetidores);
            foreach (T v in this.competidores)
                sb.AppendLine(v.MostrarDatos());                          
            return sb.ToString();
        }

        public static bool operator +(Competencia<T> c, T vc)
        {
            try
            {
                if (c != vc && c.competidores.Count < c.cantidadCompetidores)
                {
                    Random r = new Random();
                    vc.VueltasRestantes = c.CantidadDeVueltas;
                    vc.EnCompetencia = true;
                    vc.CantidadCombustible = (short)r.Next(15, 100);
                    c.competidores.Add(vc);
                    return true;
                }
                else
                    return false;
            }
            catch(CompetenciaNoDisponibleException e)
            {
                throw new CompetenciaNoDisponibleException("Competencia Incorrecta", "Competencia", "Operador +", e);
            }
        }

        public static bool operator -(Competencia<T> c, T vc)
        {
            if (c == vc)
            {
                c.competidores.Remove(vc);
                return true;
            }
            else
                return false;                
        }

        public static bool operator ==(Competencia<T> c, T vc)
        {
 
            if ((c.Tipo == TipoCompetencia.F1 && vc is AutoF1) || (c.Tipo == TipoCompetencia.MotoCross && vc is MotoCross))
            {
                foreach (VehiculoDeCarrera v in c.competidores)
                {
                    if (v == vc)
                        return true;
                }
                return false;
            }
            else
                throw new CompetenciaNoDisponibleException("El vehículo no corresponde a la competencia", "Competencia", "Operador ==");
        }

        public static bool operator !=(Competencia<T> c, T vc)
        { return !(c == vc); }
    }
}
