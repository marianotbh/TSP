using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;
using System.Xml;
using System.IO;

namespace Ejercicio_58
{
    [XmlInclude(typeof(Llamada))]
    public class Local : Llamada, IGuardar<Local>
    {
        protected float _costo;

        public override float CostoLlamada
        {
            get
            {
                return this.CalcularCosto();
            }
        }

        public string RutaDeArchivo
        {
            get
            {
                throw new NotImplementedException();
            }

            set
            {
                throw new NotImplementedException();
            }
        }

        public Local(Llamada llamada, float costo)
            : this(llamada.NroOrigen, llamada.Duracion, llamada.NroDestino, costo)
        { }

        public Local(string origen, float duracion, string destino, float costo)
            : base(duracion, destino, origen)
        {
            this._costo = costo;
        }

        float CalcularCosto()
        {
            return this.Duracion * this._costo;
        }

        protected override string Mostrar()
        {
            StringBuilder sb = new StringBuilder();
            sb.AppendLine(base.Mostrar());
            sb.AppendLine("Costo de la llamada: " + this.CostoLlamada);
            return sb.ToString();
        }

        public override bool Equals(object obj)
        {
            if (obj is Local)
                return true;
            else
                return false;
        }

        public override string ToString()
        {
            return this.Mostrar();
        }

        public bool Guardar()
        {
            using (XmlTextWriter writer = new XmlTextWriter(this.RutaDeArchivo, Encoding.Default))
            {
                XmlSerializer sr = new XmlSerializer(typeof(Local));
                sr.Serialize(writer, this);
                return true;
            }
        }

        public Local Leer()
        {
            using (XmlTextReader reader = new XmlTextReader(this.RutaDeArchivo))
            {
                XmlSerializer sr = new XmlSerializer(typeof(Local));
                object aux = (object)sr.Deserialize(reader);
                if (aux is Local)
                    return (Local)aux;
                else
                    throw new InvalidCastException();

            }
        }
    }
}
