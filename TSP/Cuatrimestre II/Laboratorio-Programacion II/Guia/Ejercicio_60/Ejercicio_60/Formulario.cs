using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Ejercicio_60
{
    public partial class Formulario : Form
    {
        public Formulario()
        {
            InitializeComponent();
        }

        private void btnLeer_Click(object sender, EventArgs e)
        {
            List<Persona> pList = PersonaDAO.Leer();
            lstPersonas.BeginUpdate();
            foreach (Persona p in pList)
            {
                lstPersonas.Items.Add(String.Format("{0} {1}", p.Nombre, p.Apellido));
            }
            lstPersonas.EndUpdate();
        }

        private void btnGuardar_Click(object sender, EventArgs e)
        {
            Persona p = new Persona(txtNombre.Text, txtApellido.Text);
            try
            {
                if (PersonaDAO.Guardar(p))
                    MessageBox.Show("Guardado con éxito!");
                else
                    MessageBox.Show("Error al guardar");
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void lstPersonas_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        
    }
}
