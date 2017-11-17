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
            this.setCantidadCombustible(0);
            this.setEnCompetencia(false);
            this.setVueltasRestantes(0);
        }

        public string MostrarDatos()
        {
            return String.Format("AUTO #{0}\n Escuderia: {1}\n Cantidad de Combustible: {2}\n En competencia: {3}\n Vueltas restantes: {4}", this.numero, this.escuderia, this.getCantidadCombustible(), this.getEnCompetencia(), this.getVueltasRestantes());
        }

        public short getCantidadCombustible()
        { return this.cantidadCombustible; }
        public void setCantidadCombustible(short cc)
        { this.cantidadCombustible = cc; }

        public bool getEnCompetencia()
        { return this.enCompetencia; }
        public void setEnCompetencia(bool ec)
        { this.enCompetencia = ec; }

        public short getVueltasRestantes()
        { return this.vueltasRestantes; }
        public void setVueltasRestantes(short vr)
        { this.vueltasRestantes = vr; }

        public static bool operator ==(AutoF1 a1, AutoF1 a2)
        {
            if (a1.escuderia == a2.escuderia && a1.numero == a2.numero)
                return true;
            else
                return false;
        }

        public static bool operator !=(AutoF1 a1, AutoF1 a2)
        { return !(a1 == a2); }
    }
}
