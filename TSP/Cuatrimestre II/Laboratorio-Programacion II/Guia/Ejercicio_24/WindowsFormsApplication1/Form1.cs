using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void textBox7_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox9_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox8_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox11_TextChanged(object sender, EventArgs e)
        {

        }

        private void btnCelsius_Click(object sender, EventArgs e)
        {
            string input = celsiusBox1.Text;
            double num;
            Fahrenheit.Fahrenheit f = new Fahrenheit.Fahrenheit();
            Celsius.Celsius c = new Celsius.Celsius();
            Kelvin.Kelvin k = new Kelvin.Kelvin();

            double.TryParse(input, out num);
            c = num;
            f = c;
            k = c;

            fahrenheitBox3.Text = f.temp.ToString();
            celsiusBox3.Text = c.temp.ToString();
            kelvinBox3.Text = k.temp.ToString();
        }

        private void btnKelvin_Click(object sender, EventArgs e)
        {
            string input = kelvinBox1.Text;
            double num;
            Fahrenheit.Fahrenheit f = new Fahrenheit.Fahrenheit();
            Celsius.Celsius c = new Celsius.Celsius();
            Kelvin.Kelvin k = new Kelvin.Kelvin();

            double.TryParse(input, out num);
            k = num;
            c = k;
            f = k;

            fahrenheitBox4.Text = f.temp.ToString();
            celsiusBox4.Text = c.temp.ToString();
            kelvinBox4.Text = k.temp.ToString();
        }

        private void btnFahrenheit_Click(object sender, EventArgs e)
        {
            string input = fahrenheitBox1.Text;
            double num;
            Fahrenheit.Fahrenheit f = new Fahrenheit.Fahrenheit();
            Celsius.Celsius c = new Celsius.Celsius();
            Kelvin.Kelvin k = new Kelvin.Kelvin();
            
            double.TryParse(input, out num);
            f = num;
            c = f;
            k = f;

            fahrenheitBox2.Text = f.temp.ToString();
            celsiusBox2.Text = c.temp.ToString();
            kelvinBox2.Text = k.temp.ToString();
        }
    }
}
