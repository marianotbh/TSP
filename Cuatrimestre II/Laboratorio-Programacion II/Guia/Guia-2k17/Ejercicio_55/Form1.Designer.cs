namespace Ejercicio_55
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.richTextBox = new System.Windows.Forms.RichTextBox();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.menuArchivo = new System.Windows.Forms.ToolStripMenuItem();
            this.menuAbrir = new System.Windows.Forms.ToolStripMenuItem();
            this.menuGuardar = new System.Windows.Forms.ToolStripMenuItem();
            this.menuGuardarComo = new System.Windows.Forms.ToolStripMenuItem();
            this.openFileDialog1 = new System.Windows.Forms.OpenFileDialog();
            this.saveFileDialog1 = new System.Windows.Forms.SaveFileDialog();
            this.statusStrip = new System.Windows.Forms.StatusStrip();
            this.statusBar = new System.Windows.Forms.ToolStripStatusLabel();
            this.menuStrip1.SuspendLayout();
            this.statusStrip.SuspendLayout();
            this.SuspendLayout();
            // 
            // richTextBox
            // 
            this.richTextBox.Dock = System.Windows.Forms.DockStyle.Fill;
            this.richTextBox.Location = new System.Drawing.Point(0, 24);
            this.richTextBox.Name = "richTextBox";
            this.richTextBox.Size = new System.Drawing.Size(284, 238);
            this.richTextBox.TabIndex = 0;
            this.richTextBox.Text = "";
            this.richTextBox.TextChanged += new System.EventHandler(this.richTextBox_TextChanged);
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.menuArchivo});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(284, 24);
            this.menuStrip1.TabIndex = 1;
            this.menuStrip1.Text = "menuStrip1";
            this.menuStrip1.ItemClicked += new System.Windows.Forms.ToolStripItemClickedEventHandler(this.menuStrip1_ItemClicked);
            // 
            // menuArchivo
            // 
            this.menuArchivo.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.menuAbrir,
            this.menuGuardar,
            this.menuGuardarComo});
            this.menuArchivo.Name = "menuArchivo";
            this.menuArchivo.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.A)));
            this.menuArchivo.Size = new System.Drawing.Size(60, 20);
            this.menuArchivo.Text = "Archivo";
            // 
            // menuAbrir
            // 
            this.menuAbrir.Name = "menuAbrir";
            this.menuAbrir.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.A)));
            this.menuAbrir.Size = new System.Drawing.Size(242, 22);
            this.menuAbrir.Text = "Abrir";
            this.menuAbrir.Click += new System.EventHandler(this.menuAbrir_Click);
            // 
            // menuGuardar
            // 
            this.menuGuardar.Name = "menuGuardar";
            this.menuGuardar.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.S)));
            this.menuGuardar.Size = new System.Drawing.Size(242, 22);
            this.menuGuardar.Text = "Guardar";
            this.menuGuardar.Click += new System.EventHandler(this.menuGuardar_Click);
            // 
            // menuGuardarComo
            // 
            this.menuGuardarComo.Name = "menuGuardarComo";
            this.menuGuardarComo.ShortcutKeyDisplayString = "Ctrl+Mayus+S";
            this.menuGuardarComo.ShortcutKeys = ((System.Windows.Forms.Keys)(((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.Shift) 
            | System.Windows.Forms.Keys.S)));
            this.menuGuardarComo.Size = new System.Drawing.Size(242, 22);
            this.menuGuardarComo.Text = "Guardar como...";
            this.menuGuardarComo.Click += new System.EventHandler(this.menuGuardarComo_Click);
            // 
            // openFileDialog1
            // 
            this.openFileDialog1.FileName = "openFileDialog1";
            // 
            // statusStrip
            // 
            this.statusStrip.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.statusBar});
            this.statusStrip.Location = new System.Drawing.Point(0, 240);
            this.statusStrip.Name = "statusStrip";
            this.statusStrip.Size = new System.Drawing.Size(284, 22);
            this.statusStrip.TabIndex = 2;
            this.statusStrip.Text = "statusStrip1";
            // 
            // statusBar
            // 
            this.statusBar.Name = "statusBar";
            this.statusBar.Size = new System.Drawing.Size(0, 17);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(284, 262);
            this.Controls.Add(this.statusStrip);
            this.Controls.Add(this.richTextBox);
            this.Controls.Add(this.menuStrip1);
            this.Name = "Form1";
            this.Text = "Ej55";
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.statusStrip.ResumeLayout(false);
            this.statusStrip.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.RichTextBox richTextBox;
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem menuArchivo;
        private System.Windows.Forms.OpenFileDialog openFileDialog1;
        private System.Windows.Forms.SaveFileDialog saveFileDialog1;
        private System.Windows.Forms.StatusStrip statusStrip;
        private System.Windows.Forms.ToolStripStatusLabel statusBar;
        private System.Windows.Forms.ToolStripMenuItem menuAbrir;
        private System.Windows.Forms.ToolStripMenuItem menuGuardar;
        private System.Windows.Forms.ToolStripMenuItem menuGuardarComo;
    }
}

