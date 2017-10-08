using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Repaso
{
    class Estante
    {
        private int _capacidadMaxima;
        private int _ubicacion;
        private Producto[] _productos;

        public Estante(int cap, int ubi):this(cap)
        {
            this._capacidadMaxima = cap;
            this._ubicacion = ubi;
        }
        private Estante(int cap)
        {
            this._productos = new Producto[cap];
        }
        public Producto[] GetProductos()
        {
            return this._productos;
        }
        public string MostrarEstante()
        {
            string infoEstante;
            string productos = " ";

            foreach (Producto producto in this._productos)
            {
                if (!(object.ReferenceEquals(producto, null)))
                    productos += producto.MostrarProducto();
            }

            infoEstante = "Capacidad maxima: " + this._capacidadMaxima + "\nUbicacion: " + this._ubicacion + "\nProductos:" + productos; 

            return infoEstante;
        }
        static public bool operator ==(Estante estante, Producto prod)
        {
            bool ret = false;
            foreach(Producto producto in estante._productos)
            {
                if(prod == producto)
                {
                    ret = true;
                    break;
                }
                else
                    ret = false;
            }
            return ret;
        }
        static public bool operator !=(Estante estante, Producto prod)
        {
            bool ret = true;
            for(int i = 0; i < estante._productos.Length; i++)
            {
                if (!(object.ReferenceEquals(estante._productos[i], null)) && prod == estante._productos[i])
                {
                    ret = false;
                    break;
                }
            }
            return ret;
        }
        static public bool operator +(Estante estante, Producto prod)
        {
            bool ret = false;
            for (int i = 0; i < estante._productos.Length; i++)
            {
                if (object.ReferenceEquals(estante._productos[i], null) && estante != prod)
                {
                    ret = true;
                    estante._productos[i] = prod;
                    break;
                }
            }
            return ret;
        }
        static public Estante operator -(Estante estante, Producto prod)
        {
            int len = estante._productos.Length;
            for (int i = 0; i < len; i++)
            {
                if (estante._productos[i] == prod)
                {
                    estante._productos[i] = null;
                }
            }
            return estante;
        }
    }
}
