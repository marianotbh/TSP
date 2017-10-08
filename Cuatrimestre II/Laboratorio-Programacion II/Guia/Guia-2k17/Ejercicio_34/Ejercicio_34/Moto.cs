using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejercicio_34
{
     class Moto:VehiculoTerrestre
    {
        short cilindrada;

        public Moto(short cilindrada, short cantidadRuedas, short cantidadPuertas, Colores color)
            : base(cantidadRuedas, cantidadPuertas, color)
        {
            this.cilindrada = cilindrada;
        }
    }
}
