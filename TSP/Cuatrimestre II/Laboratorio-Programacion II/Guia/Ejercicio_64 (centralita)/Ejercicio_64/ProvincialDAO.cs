using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.Sql;
using System.Data.SqlClient;

namespace Ejercicio_64
{
    class ProvincialDAO
    {
        static SqlConnection conn;
        static SqlCommand comm;

        static ProvincialDAO()
        {
            ProvincialDAO.conn = new SqlConnection(@"Data Source=LAB3PC01\SQLEXPRESS;Initial Catalog=Ej61;Integrated Security=True");
            ProvincialDAO.comm = new SqlCommand();
            //ProvincialDAO.comm.CommandType = System.Data.CommandType.Text;
            ProvincialDAO.comm.Connection = ProvincialDAO.conn;
        }

        public bool Guardar(Provincial p)
        {
            string sql = String.Format("INSERT INTO Centralita (Duracion, Origen, Destino, Tipo, Costo) VALUES('{0}','{1}','{2}',{3},'{4}')", p.Duracion, p.NroOrigen, p.NroDestino, 1, p.CostoLlamada);
            return EjecutarNonQuery(sql);
        }

        public Provincial Leer()
        {
            bool TodoOk = false;
            Provincial p = null;

            try
            {
                ProvincialDAO.comm.CommandText = String.Format("SELECT 1, 2, 3, 5 FROM Centralita WHERE 1 = {0}, 2 = {1}, 3 = {2}, 4 = 1", p.Duracion, p.NroOrigen, p.NroDestino);
                ProvincialDAO.conn.Open();
                SqlDataReader dr = ProvincialDAO.comm.ExecuteReader();
                while (dr.Read())
                {
                    p = new Provincial(float.Parse(dr[1].ToString()), (Provincial.Franja)(float.Parse(dr[5].ToString()) * 100), (dr[2].ToString()), dr[3].ToString());
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
                    ProvincialDAO.conn.Close();
            }
            return p;
        }

        private static bool EjecutarNonQuery(string sql)
        {
            bool todoOk = false;
            try
            {
                ProvincialDAO.comm.CommandText = sql;
                ProvincialDAO.conn.Open();
                ProvincialDAO.comm.ExecuteNonQuery();
                todoOk = true;
            }
            catch (Exception)
            {
                todoOk = false;
            }
            finally
            {
                if (todoOk)
                    ProvincialDAO.conn.Close();
            }
            return todoOk;
        }
    }
}
