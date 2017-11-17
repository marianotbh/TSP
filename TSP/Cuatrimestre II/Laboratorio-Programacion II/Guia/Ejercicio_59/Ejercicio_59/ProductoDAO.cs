using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data;
using System.Data.SqlClient;

namespace Ejercicio_59
{
    class ProductoDAO
    {
        private static SqlConnection _conexion;
        private static SqlCommand _comando;

        #region Constructores
        static ProductoDAO()
        {
            ProductoDAO._conexion = new SqlConnection(Properties.Settings.Default.CadenaConexion);
            ProductoDAO._comando = new SqlCommand();
            ProductoDAO._comando.CommandType = System.Data.CommandType.Text;
            ProductoDAO._comando.Connection = ProductoDAO._conexion;
        }
        #endregion

        #region Métodos
        public static Producto ObtieneProductoPorID(int id)
        {
            bool TodoOk = false;
            Producto Producto = null;

            try
            {
                ProductoDAO._comando.CommandText = "SELECT Name FROM Production.Product P WHERE P.ProductID = " + id.ToString();
                ProductoDAO._conexion.Open();        
                SqlDataReader oDr = ProductoDAO._comando.ExecuteReader();
                while (oDr.Read())
                {
                    Producto = new Producto(oDr["Name"].ToString());
                }
                oDr.Close();
                TodoOk = true;
            }

            catch (Exception ex)
            {
                Console.WriteLine(ex.ToString());
            }
            finally
            {
                if (TodoOk)
                    ProductoDAO._conexion.Close();
            }
            return Producto;
        }

        public static bool InsertaProducto(Producto p)
        {
            string sql = "INSERT INTO Production.Product (Name) VALUES(";
            sql = sql + "'" + p.Nombre;
            return EjecutarNonQuery(sql);

        }

        public static bool ModificaProducto(Producto p)
        {
            string sql = "UPDATE Production.Product SET Name = '" + p.Nombre + "' WHERE ProductID = " + p.ID.ToString();
            return EjecutarNonQuery(sql);
        }

        public static bool EliminaProducto(Producto p)
        {
            string sql = "DELETE FROM Production.Product WHERE ProductID = " + p.ID.ToString();
            return EjecutarNonQuery(sql);
        }

        private static bool EjecutarNonQuery(string sql)
        {
            bool todoOk = false;
            try
            {
                ProductoDAO._comando.CommandText = sql;
                ProductoDAO._conexion.Open();
                ProductoDAO._comando.ExecuteNonQuery();
                todoOk = true;
            }
            catch (Exception)
            {
                todoOk = false;
            }
            finally
            {
                if (todoOk)
                    ProductoDAO._conexion.Close();
            }
            return todoOk;
        }
        #endregion
    }
}
