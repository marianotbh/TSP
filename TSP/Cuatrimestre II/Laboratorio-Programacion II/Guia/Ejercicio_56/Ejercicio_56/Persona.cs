using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.Serialization.Formatters.Binary;
using System.IO;


namespace Ejercicio_56
{
    [Serializable]
    class Persona
    {
        string nombre;
        string apellido;

        public Persona()
        { }

        public Persona(string nombre, string apellido)
        {
            this.nombre = nombre;
            this.apellido = apellido;
        }

        public static void Guardar(Persona p)
        {
            BinaryFormatter serializer = new BinaryFormatter();
            try
            {
                using (FileStream fs = new FileStream("Archivo.bin", FileMode.Append))
                {
                    serializer.Serialize(fs, p);
                }       
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }
        }

        public static Persona Leer()
        {
            Persona auxPersona = null;
            BinaryFormatter serializer = new BinaryFormatter();

            try
            {
                using(FileStream fStream = new FileStream("Archivo.bin", FileMode.Open))
                {
                    auxPersona = (Persona)serializer.Deserialize(fStream);
                }                
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }               
            return auxPersona;
        }

        public override string ToString()
        {
            return String.Format("{0} {1}", this.nombre, this.apellido);
        }
    }
}
