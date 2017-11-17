using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data;
using System.Data.SqlClient;

namespace Ejercicio_60
{
    public class PersonaDAO
    {
        static SqlConnection connection;
        static SqlCommand command;

        static PersonaDAO()
        {
            PersonaDAO.connection = new SqlConnection(Properties.Settings.Default.ConnectionString);
            PersonaDAO.command = new SqlCommand();
            PersonaDAO.command.CommandType = System.Data.CommandType.Text;
            PersonaDAO.command.Connection = PersonaDAO.connection;
        }

        public static bool Guardar(Persona p)
        {
            string sql = String.Format("INSERT INTO Persona (Nombre, Apellido) VALUES('{0}', '{1}')", p.Nombre, p.Apellido);
            return EjecutarNonQuery(sql);
        }

        public static List<Persona> Leer()
        {
            bool TodoOk = false;
            Persona p = null;
            List<Persona> pList = new List<Persona>();

            try
            {
                PersonaDAO.command.CommandText = "SELECT Nombre, Apellido FROM Persona";
                PersonaDAO.connection.Open();
                SqlDataReader oDr = PersonaDAO.command.ExecuteReader();
                while (oDr.Read())
                {
                    p = new Persona(oDr["Nombre"].ToString(), oDr["Apellido"].ToString());
                    pList.Add(p);
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
                    PersonaDAO.connection.Close();
            }
            return pList;
        }

        public static Persona LeerPorID(int id)
        {
            bool TodoOk = false;
            Persona p = null;

            try
            {
                PersonaDAO.command.CommandText = "SELECT Nombre, Apellido FROM Persona WHERE ID = " + id.ToString();
                PersonaDAO.connection.Open();
                SqlDataReader oDr = PersonaDAO.command.ExecuteReader();
                while (oDr.Read())
                {
                    p = new Persona(oDr["Nombre"].ToString(), oDr["Apellido"].ToString());
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
                    PersonaDAO.connection.Close();
            }
            return p;
        }

        public static bool Modificar(Persona p, string newNombre, string newApellido)
        {
            string sql = String.Format("UPDATE Persona SET Nombre = '{0}', Apellido = '{1}' WHERE Name = '{2}', Apellido = '{3}'", newNombre, newApellido, p.Nombre, p.Apellido);
            return EjecutarNonQuery(sql);
        }

        public static bool Borrar(Persona p)
        {
            string sql = String.Format("DELETE FROM Persona WHERE Name = '{0}', Apellido = '{1}'", p.Nombre, p.Apellido);
            return EjecutarNonQuery(sql);
        }

        static bool EjecutarNonQuery(string sql)
        {
            bool todoOk = false;
            try
            {
                PersonaDAO.command.CommandText = sql;
                Console.WriteLine(PersonaDAO.command.CommandText);
                PersonaDAO.connection.Open();
                PersonaDAO.command.ExecuteNonQuery();
                todoOk = true;
            }
            catch (Exception)
            {
                todoOk = false;
            }
            finally
            {
                if (todoOk)
                    PersonaDAO.connection.Close();
            }
            return todoOk;
        }
    }
}
