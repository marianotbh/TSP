using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Repaso
{
    class Producto
    {
        protected string _marca;
        protected float _precio;
        protected string _codigoDeBarra;

        public Producto(string marca, string codigo, float precio)
        {
            this._marca = marca;
            this._precio = precio;
            this._codigoDeBarra = codigo;
        }

        public string GetMarca()
        {
            return this._marca;
        }
        public float GetPrecio()
        {
            return this._precio;
        }
        public string MostrarProducto()
        {
            string producto;
            {
                producto = "Marca: " + this._marca + " - Precio: " + this._precio + " - Codigo: " + this._codigoDeBarra + "\n"; 
            }            
            return producto;
        }

        public static bool operator ==(Producto prod1, Producto prod2)
        {
            bool ret = false;
            if (prod1._marca == prod2._marca && prod1._codigoDeBarra == prod2._codigoDeBarra)
                ret = true;
            return ret;
        }
        public static bool operator !=(Producto prod1, Producto prod2)
        {
            bool ret = true;
            if (prod1._marca == prod2._marca && prod1._codigoDeBarra == prod2._codigoDeBarra)
                ret = false;
            return ret;
        }
        public static bool operator ==(Producto prod1, string prod2)
        {
            bool ret;
            if (prod1._marca == prod2)
                ret = true;
            else
                ret = false;
            return ret;
        }
        public static bool operator !=(Producto prod1, string prod2)
        {
            bool ret;
            if (prod1._marca != prod2)
                ret = true;
            else
                ret = false;
            return ret;
        }
        public static explicit operator string(Producto prod)
        {
            return prod._codigoDeBarra;
        }
    }
}
