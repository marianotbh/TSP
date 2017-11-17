using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Ejercicio_59
{
    public partial class Forma : Form
    {
        Producto auxProd = null;

        public Forma()
        {
            InitializeComponent();
        }

        private void btnAdd_Click(object sender, EventArgs e)
        {
            if (txtBoxName.Text.Length > 0)
            {
                Producto p = new Producto(txtBoxName.Text);
                if (p.Guardar())
                    MessageBox.Show("Guardado con éxito!");
                else
                    MessageBox.Show("No se pudo guardar");
            }
            else
                MessageBox.Show("No puede dejar campos vacios");
        }

        private void btnMod_Click(object sender, EventArgs e)
        {
            DialogResult boton = MessageBox.Show("Esta seguro que desea modificar el nombre de este producto?", "Modificar producto", MessageBoxButtons.OKCancel, MessageBoxIcon.Warning);
            if (boton == DialogResult.OK)
            {
                Producto p = auxProd;
                p.Nombre = txtBoxName.Text;
                if (p.Modificar())
                    MessageBox.Show("Modificado con éxito");
                else
                    MessageBox.Show("No se ha podido modificar");
            }          
        }

        private void btnDel_Click(object sender, EventArgs e)
        {
            DialogResult boton = MessageBox.Show("Esta seguro que desea eliminar el nombre de este producto?", "Eliminar producto", MessageBoxButtons.OKCancel, MessageBoxIcon.Warning);
            if (boton == DialogResult.OK)
            {
                Producto p = auxProd;
                p.Nombre = txtBoxName.Text;
                if (p.Eliminar())
                    MessageBox.Show("Eliminado con éxito");
                else
                    MessageBox.Show("No se pudo eliminar");
            }  
        }

        private void btnBuscar_Click(object sender, EventArgs e)
        {
            int aut;
            if (int.TryParse(txtBuscar.Text, out aut))
            {
                Producto p = new Producto(txtBoxName.Text);
                if (p.CargarPorID(aut))
                {
                    txtBoxID.Text = p.ID.ToString();
                    txtBoxName.Text = p.Nombre;
                    auxProd = p;
                }
                else
                    MessageBox.Show("No encontrado");
            }
            else
                MessageBox.Show("Ingrese un ID valido");
        }
    }
}
