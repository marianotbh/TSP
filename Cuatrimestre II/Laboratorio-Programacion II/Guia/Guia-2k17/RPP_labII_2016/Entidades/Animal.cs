using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    public abstract class Animal
    {
        protected int _cantidadPatas;
        protected static Random _distanciaRecorrida;
        protected int _velocidadMaxima;

        public int CantidadPatas
        {
            get { return this._cantidadPatas; }
            set 
            {
                if (value <= 4)
                    this._cantidadPatas = value;
                else
                    this._cantidadPatas = 4;            
            }
        }

        int DistanciaRecorrida
        {
            get { return _distanciaRecorrida.Next(10, this._velocidadMaxima); }
        }

        public int VelocidadMaxima
        {
            get { return this._velocidadMaxima; }
            set
            {
                if (value <= 60)
                    this._velocidadMaxima = value;
                else
                    this._velocidadMaxima = 60;
            }
        }

        static Animal()
        { _distanciaRecorrida = new Random(); }

        public Animal(int cantidadPatas, int velocidadMaxima)
        { 
            this._cantidadPatas = cantidadPatas;
            this.VelocidadMaxima = velocidadMaxima;
        }

        public string MostrarDatos()
        {
            return String.Format("Distancia recorrida: {0} - Velocidad Maxima: {1} - Cant. Patas: {2}", this.DistanciaRecorrida, this._velocidadMaxima, this.CantidadPatas);
        }
    }
}
