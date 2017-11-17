using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejercicio_59
{
    public class Producto
    {
        int id;
        string nombre;

        public string Nombre
        {
            get { return this.nombre; }
            set { this.nombre = value; }
        }
        public int ID
        {
            get { return this.id; }
        }

        public Producto(string nombre)
        {
            this.nombre = nombre;
        }

        #region Base de datos
        public bool Guardar()
        {
            return ProductoDAO.InsertaProducto(this);
        }

        public bool CargarPorID(int id)
        {
            Producto datos = ProductoDAO.ObtieneProductoPorID(id);
            if (datos == null)
                return false;
            else
            {
                this.id = datos.id;
                this.nombre = datos.nombre;
                return true;
            }
        }

        public bool Modificar()
        {
            return ProductoDAO.ModificaProducto(this);
        }

        public bool Eliminar()
        {
            return ProductoDAO.EliminaProducto(this);
        }
        #endregion

        public override string ToString()
        {
            return String.Format("{0}", this.nombre);
        }
    }
}
