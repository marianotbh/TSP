using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using TP1;

namespace TrabajoPractico1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void btnLimpiar_Click(object sender, EventArgs e)
        {
            txtNumero1.ResetText();
            txtNumero2.ResetText();
            cmbOperacion.ResetText();
            lblResultado.ResetText();
        }

        private void btnOperar_Click(object sender, EventArgs e)
        {
            Numero num1 = new Numero(txtNumero1.Text);
            Numero num2 = new Numero(txtNumero2.Text);
            double resultado = Calculadora.operar(num1, num2, cmbOperacion.Text);
            lblResultado.Text = resultado.ToString();
        }
    }
}
