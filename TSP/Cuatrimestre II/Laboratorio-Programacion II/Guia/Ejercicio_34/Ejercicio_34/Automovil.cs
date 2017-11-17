using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejercicio_34
{
    class Automovil:VehiculoTerrestre
    {
        short cantidadMarchas;
        int cantidadPasajeros;

        public Automovil(short cantidadMarchas, int cantidadPasajeros, short cantidadRuedas, short cantidadPuertas, Colores color) 
            : base(cantidadRuedas,cantidadPuertas,color)
        {
            this.cantidadMarchas = cantidadMarchas;
            this.cantidadPasajeros = cantidadPasajeros;
        }
    }
}
