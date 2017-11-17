using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejercicio_34
{
    public class VehiculoTerrestre
    {
        short cantidadRuedas;
        short cantidadPuertas;
        Colores color;

        public enum Colores
        {
            Rojo,
            Blanco,
            Azul,
            Gris,
            Negro
        }

        VehiculoTerrestre()
        {
        }

        public VehiculoTerrestre(short cantidadRuedas, short cantidadPuertas, Colores color)
        {
            this.cantidadPuertas = cantidadPuertas;
            this.cantidadRuedas = cantidadRuedas;
            this.color = color;
        }
    }
}
