using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejercicio_36
{
    class VehiculoDeCarrera
    {
        short cantidadCombustible;
        bool enCompetencia;
        string escuderia;
        short numero;
        short vueltasRestantes;

        #region Propiedades
        public short CantidadCombustible
        {
            get
            {
                return this.cantidadCombustible;
            }
            set
            {
                this.cantidadCombustible = value;
            }
        }

        public bool EnCompetencia
        {
            get 
            {
                return this.enCompetencia;
            }
            set
            {
                this.enCompetencia = value;
            }
        }

        public string Escuderia
        {
            get
            {
                return this.escuderia;
            }
            set 
            {
                this.escuderia = value;
            }
        }

        public short Numero
        {
            get
            {
                return this.numero;
            }
            set
            {
                this.numero = value;
            }
        }

        public short VueltasRestantes
        {
            get
            {
                return this.vueltasRestantes;
            }
            set 
            {
                this.vueltasRestantes = value;
            }
        }
        #endregion

        public VehiculoDeCarrera(short numero, string escuderia)
        {
            this.Numero = numero;
            this.Escuderia = escuderia;
            this.enCompetencia = false;
            this.cantidadCombustible = 0;
            this.vueltasRestantes = 0;
        }

        public virtual string MostrarDatos()
        {
            StringBuilder st = new StringBuilder();
            st.AppendFormat("Numero: {0} \nEscuderia: {1} \nEn Competencia: {2} \nCantidad de Combustible: {3} \nVueltas Restantes: {4}", this.Numero, this.Escuderia, this.EnCompetencia, this.CantidadCombustible, this.VueltasRestantes);
            return st.ToString();
        }

        
    }
}
