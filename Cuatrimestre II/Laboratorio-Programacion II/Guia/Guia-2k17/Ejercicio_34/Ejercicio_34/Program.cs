using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejercicio_34
{
    class Program
    {
        static void Main(string[] args)
        {
            Camion camion = new Camion(2, 250, 6, 2, VehiculoTerrestre.Colores.Rojo);
            Automovil auto = new Automovil(7, 4, 4, 4, VehiculoTerrestre.Colores.Gris);
            Moto moto = new Moto(250, 2, 1, VehiculoTerrestre.Colores.Azul);
            
            Console.ReadKey();
        }
    }
}
