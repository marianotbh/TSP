using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.Sql;
using System.Data.SqlClient;

namespace Ejercicio_64
{
    class LocalDAO
    {
        static SqlConnection conn;
        static SqlCommand comm;

        static LocalDAO()
        {
            LocalDAO.conn = new SqlConnection(@"Data Source=LAB3PC01\SQLEXPRESS;Initial Catalog=Ej61;Integrated Security=True");
            LocalDAO.comm = new SqlCommand();
            //LocalDAO.comm.CommandType = System.Data.CommandType.Text;
            LocalDAO.comm.Connection = LocalDAO.conn;
        }

        public bool Guardar(Local l)
        {
            string sql = String.Format("INSERT INTO Centralita (Duracion, Origen, Destino, Tipo, Costo) VALUES('{0}','{1}','{2}',{3},'{4}')", l.Duracion, l.NroOrigen, l.NroDestino, 1, l.CostoLlamada);
            return EjecutarNonQuery(sql);
        }

        public Local Leer()
        {
            bool TodoOk = false;
            Local l = null;

            try
            {
                LocalDAO.comm.CommandText = String.Format("SELECT 1, 2, 3, 5 FROM Centralita WHERE 1 = {0}, 2 = {1}, 3 = {2}, 4 = 0", l.Duracion, l.NroOrigen, l.NroDestino);
                LocalDAO.conn.Open();
                SqlDataReader dr = LocalDAO.comm.ExecuteReader();
                while (dr.Read())
                {
                    l = new Local(dr[2].ToString(), float.Parse(dr[1].ToString()), dr[3].ToString(), float.Parse(dr[5].ToString()));
                }
                dr.Close();
                TodoOk = true;
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.ToString());
            }
            finally
            {
                if (TodoOk)
                    LocalDAO.conn.Close();
            }
            return l;
        }

        private static bool EjecutarNonQuery(string sql)
        {
            bool todoOk = false;
            try
            {
                LocalDAO.comm.CommandText = sql;
                LocalDAO.conn.Open();
                LocalDAO.comm.ExecuteNonQuery();
                todoOk = true;
            }
            catch (Exception)
            {
                todoOk = false;
            }
            finally
            {
                if (todoOk)
                    LocalDAO.conn.Close();
            }
            return todoOk;
        }
    }
}
