using System;
using System.ComponentModel;
using System.Windows.Forms;
using System.IO;

namespace Ejercicio_55
{
    public partial class Form1 : Form
    {
        string path = null;

        public Form1()
        {
            InitializeComponent();
            statusBar.Text = String.Format("{0} caracteres", richTextBox.Text.Length);
        }

        private void menuStrip1_ItemClicked(object sender, ToolStripItemClickedEventArgs e)
        {

        }

        private void richTextBox_TextChanged(object sender, EventArgs e)
        {
            statusBar.Text = String.Format("{0} caracteres", richTextBox.Text.Length);
        }

        private void menuAbrir_Click(object sender, EventArgs e)
        {
            OpenFileDialog openDialog = new OpenFileDialog();
            openDialog.InitialDirectory = "c:\\";

            if (openDialog.ShowDialog() == DialogResult.OK)
            {
                path = openDialog.FileName;
                StreamReader reader = new StreamReader(path);
                richTextBox.Text = reader.ReadLine();
                reader.Close();
            }
        }

        private void menuGuardar_Click(object sender, EventArgs e)
        {
            if (path == null)
            {
                menuGuardarComo_Click(sender, e);                
            }
            else
            {
                StreamWriter writer = new StreamWriter(path);
                writer.WriteLine(richTextBox.Text);
                writer.Close();
            }                
        }

        private void menuGuardarComo_Click(object sender, EventArgs e)
        {
            SaveFileDialog saveDialog = new SaveFileDialog();
            saveDialog.InitialDirectory = "c:\\";
            if (saveDialog.ShowDialog() == DialogResult.OK)
            {
                path = saveDialog.FileName;
                StreamWriter writer = new StreamWriter(path);
                writer.WriteLine(richTextBox.Text);
                writer.Close();
            }
        }
    }
}
