using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Diccionario
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void btnCalcular_Click(object sender, EventArgs e)
        {
            Dictionary<string, int> diccionario = new Dictionary<string, int>();
            string[] text = textBox.Text.Split(' ');
            string pop = "";

            foreach (string palabra in text)
            {
                if (diccionario.ContainsKey(palabra))
                    diccionario[palabra] = diccionario[palabra] + 1;
                else
                    diccionario.Add(palabra,1);
            }

            foreach (KeyValuePair<string, int> palabra in diccionario.OrderByDescending(palabra => palabra.Value).Take(3))
            {
                pop += palabra.Key + " --> " + palabra.Value + "\n";
            }

            MessageBox.Show(pop);
        }
    }
}
