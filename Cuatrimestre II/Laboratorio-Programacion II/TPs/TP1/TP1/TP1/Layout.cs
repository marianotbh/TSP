using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace TP1
{
    public partial class Layout : Form
    {
        public Layout()
        {
            InitializeComponent();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {       
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
        }

        private void button1_Click(object sender, EventArgs e)
        {
            txtNumero1.Text = " ";
            txtNumero2.Text = " ";
            cmbOperacion.DisplayMember = "1";
        }

        private void button2_Click(object sender, EventArgs e)
        {
            double result;
            Numero num1 = new Numero(txtNumero1.Text);
            Numero num2 = new Numero(txtNumero2.Text);
            result = Calculadora.operar(num1, num2 , cmbOperacion.Text);
            lblResultado.Text = result.ToString();
        }

        private void Layout_Load(object sender, EventArgs e)
        {

        }
    }
}
