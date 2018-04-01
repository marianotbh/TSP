using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejercicio_30
{
    class AutoF1
    {
        short cantidadCombustible;
        bool enCompetencia;
        string escuderia;
        short numero;
        short vueltasRestantes;

        public AutoF1(short numero, string escuderia)
        {
            this.numero = numero;
            this.escuderia = escuderia;
            this.enCompetencia = false;
            this.cantidadCombustible = 0;
            this.vueltasRestantes = 0;
        }

        public string MostrarDatos()
        { 
            StringBuilder sb = new StringBuilder();
            sb.AppendFormat("Numero: {0}\nEscuderia: {1}\nCantidad combustible: {2}\nCantidad vueltas: {3}\nEn competencia: {4}\n", this.numero, this.escuderia, this.getCantidadCombustible(), this.getVueltasRestantes(), this.getEnCompetencia());
            return sb.ToString();
        }

        public static bool operator ==(AutoF1 a1, AutoF1 a2)
        {
            if (a1.numero == a2.numero && a1.escuderia == a2.escuderia)
                return true;
            else
                return false;
        }

        public static bool operator !=(AutoF1 a1, AutoF1 a2)
        {
            return !(a1 == a2);
        }

        public short getCantidadCombustible()
        { return this.cantidadCombustible; }
        public void setCantidadCombustible(short cantidadCombustible)
        { this.cantidadCombustible = cantidadCombustible; }

        public bool getEnCompetencia()
        { return this.enCompetencia; }
        public void setEnCompetencia(bool enCompetencia)
        { this.enCompetencia = enCompetencia; }

        public short getVueltasRestantes()
        { return this.vueltasRestantes; }
        public void setVueltasRestantes(short vueltasRestantes)
        { this.vueltasRestantes = vueltasRestantes; }
    }
}
