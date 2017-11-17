using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Threading;
using System.Timers;

namespace Ejercicio_62
{
    public partial class Formulario : Form
    {
        Thread reloj;

        public Formulario()
        {
            InitializeComponent();
            reloj = new Thread(AsignarHoraIII);
        }

        void AsignarHora()
        {
            lblHora.Text = DateTime.Now.ToString();
        }
        
        void AsignarHoraI()
        {
            while (true)
            {
                for (int i = 0; i < 1000000; i++)
                    AsignarHora();
            }
        }

        void AsignarHoraII()
        {
            System.Timers.Timer timer = new System.Timers.Timer();
            timer.Interval = 1000;
            while(!timer.Enabled)
            {
                AsignarHora();
                timer.Start();
                while (timer.Enabled)
                { }
                timer.Stop();
            }            
        }

        void AsignarHoraIII()
        {
            while (true)
            {
                if (this.lblHora.InvokeRequired)
                {
                    this.lblHora.BeginInvoke((MethodInvoker)delegate()
                    {
                        AsignarHora();
                    });
                }
                else
                {
                    AsignarHora();
                }
                Thread.Sleep(1000);
            }
        }

        private void Formulario_Shown(object sender, EventArgs e)
        {
            //AsignarHoraI();
            //AsignarHoraII();
            reloj.Start();            
        }

        private void Formulario_FormClosing(object sender, FormClosingEventArgs e)
        {
            reloj.Abort();
        }
    }
}
