namespace WindowsFormsApplication1
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
            this.label1 = new System.Windows.Forms.Label();
            this.btnFahrenheit = new System.Windows.Forms.Button();
            this.fahrenheitBox1 = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.celsiusBox1 = new System.Windows.Forms.TextBox();
            this.kelvinBox1 = new System.Windows.Forms.TextBox();
            this.btnCelsius = new System.Windows.Forms.Button();
            this.btnKelvin = new System.Windows.Forms.Button();
            this.fahrenheitBox2 = new System.Windows.Forms.TextBox();
            this.celsiusBox2 = new System.Windows.Forms.TextBox();
            this.kelvinBox2 = new System.Windows.Forms.TextBox();
            this.fahrenheitBox3 = new System.Windows.Forms.TextBox();
            this.celsiusBox3 = new System.Windows.Forms.TextBox();
            this.kelvinBox3 = new System.Windows.Forms.TextBox();
            this.fahrenheitBox4 = new System.Windows.Forms.TextBox();
            this.celsiusBox4 = new System.Windows.Forms.TextBox();
            this.kelvinBox4 = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 37);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(57, 13);
            this.label1.TabIndex = 0;
            this.label1.Text = "Fahrenheit";
            this.label1.Click += new System.EventHandler(this.label1_Click);
            // 
            // btnFahrenheit
            // 
            this.btnFahrenheit.Location = new System.Drawing.Point(187, 33);
            this.btnFahrenheit.Name = "btnFahrenheit";
            this.btnFahrenheit.Size = new System.Drawing.Size(75, 23);
            this.btnFahrenheit.TabIndex = 1;
            this.btnFahrenheit.Text = "--->";
            this.btnFahrenheit.UseVisualStyleBackColor = true;
            this.btnFahrenheit.Click += new System.EventHandler(this.btnFahrenheit_Click);
            // 
            // fahrenheitBox1
            // 
            this.fahrenheitBox1.Location = new System.Drawing.Point(81, 35);
            this.fahrenheitBox1.Name = "fahrenheitBox1";
            this.fahrenheitBox1.Size = new System.Drawing.Size(100, 20);
            this.fahrenheitBox1.TabIndex = 2;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(12, 66);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(40, 13);
            this.label2.TabIndex = 3;
            this.label2.Text = "Celsius";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(12, 93);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(36, 13);
            this.label3.TabIndex = 4;
            this.label3.Text = "Kelvin";
            // 
            // celsiusBox1
            // 
            this.celsiusBox1.Location = new System.Drawing.Point(81, 64);
            this.celsiusBox1.Name = "celsiusBox1";
            this.celsiusBox1.Size = new System.Drawing.Size(100, 20);
            this.celsiusBox1.TabIndex = 5;
            // 
            // kelvinBox1
            // 
            this.kelvinBox1.Location = new System.Drawing.Point(81, 92);
            this.kelvinBox1.Name = "kelvinBox1";
            this.kelvinBox1.Size = new System.Drawing.Size(100, 20);
            this.kelvinBox1.TabIndex = 6;
            // 
            // btnCelsius
            // 
            this.btnCelsius.Location = new System.Drawing.Point(187, 62);
            this.btnCelsius.Name = "btnCelsius";
            this.btnCelsius.Size = new System.Drawing.Size(75, 23);
            this.btnCelsius.TabIndex = 7;
            this.btnCelsius.Text = "--->";
            this.btnCelsius.UseVisualStyleBackColor = true;
            this.btnCelsius.Click += new System.EventHandler(this.btnCelsius_Click);
            // 
            // btnKelvin
            // 
            this.btnKelvin.Location = new System.Drawing.Point(187, 91);
            this.btnKelvin.Name = "btnKelvin";
            this.btnKelvin.Size = new System.Drawing.Size(75, 23);
            this.btnKelvin.TabIndex = 8;
            this.btnKelvin.Text = "--->";
            this.btnKelvin.UseVisualStyleBackColor = true;
            this.btnKelvin.Click += new System.EventHandler(this.btnKelvin_Click);
            // 
            // fahrenheitBox2
            // 
            this.fahrenheitBox2.Enabled = false;
            this.fahrenheitBox2.Location = new System.Drawing.Point(268, 35);
            this.fahrenheitBox2.Name = "fahrenheitBox2";
            this.fahrenheitBox2.Size = new System.Drawing.Size(100, 20);
            this.fahrenheitBox2.TabIndex = 9;
            // 
            // celsiusBox2
            // 
            this.celsiusBox2.Enabled = false;
            this.celsiusBox2.Location = new System.Drawing.Point(374, 35);
            this.celsiusBox2.Name = "celsiusBox2";
            this.celsiusBox2.Size = new System.Drawing.Size(100, 20);
            this.celsiusBox2.TabIndex = 10;
            // 
            // kelvinBox2
            // 
            this.kelvinBox2.Enabled = false;
            this.kelvinBox2.Location = new System.Drawing.Point(480, 35);
            this.kelvinBox2.Name = "kelvinBox2";
            this.kelvinBox2.Size = new System.Drawing.Size(100, 20);
            this.kelvinBox2.TabIndex = 11;
            // 
            // fahrenheitBox3
            // 
            this.fahrenheitBox3.Enabled = false;
            this.fahrenheitBox3.Location = new System.Drawing.Point(268, 64);
            this.fahrenheitBox3.Name = "fahrenheitBox3";
            this.fahrenheitBox3.Size = new System.Drawing.Size(100, 20);
            this.fahrenheitBox3.TabIndex = 12;
            this.fahrenheitBox3.TextChanged += new System.EventHandler(this.textBox7_TextChanged);
            // 
            // celsiusBox3
            // 
            this.celsiusBox3.Enabled = false;
            this.celsiusBox3.Location = new System.Drawing.Point(374, 64);
            this.celsiusBox3.Name = "celsiusBox3";
            this.celsiusBox3.Size = new System.Drawing.Size(100, 20);
            this.celsiusBox3.TabIndex = 13;
            this.celsiusBox3.TextChanged += new System.EventHandler(this.textBox8_TextChanged);
            // 
            // kelvinBox3
            // 
            this.kelvinBox3.Enabled = false;
            this.kelvinBox3.Location = new System.Drawing.Point(480, 64);
            this.kelvinBox3.Name = "kelvinBox3";
            this.kelvinBox3.Size = new System.Drawing.Size(100, 20);
            this.kelvinBox3.TabIndex = 14;
            this.kelvinBox3.TextChanged += new System.EventHandler(this.textBox9_TextChanged);
            // 
            // fahrenheitBox4
            // 
            this.fahrenheitBox4.Enabled = false;
            this.fahrenheitBox4.Location = new System.Drawing.Point(268, 92);
            this.fahrenheitBox4.Name = "fahrenheitBox4";
            this.fahrenheitBox4.Size = new System.Drawing.Size(100, 20);
            this.fahrenheitBox4.TabIndex = 15;
            // 
            // celsiusBox4
            // 
            this.celsiusBox4.Enabled = false;
            this.celsiusBox4.Location = new System.Drawing.Point(374, 92);
            this.celsiusBox4.Name = "celsiusBox4";
            this.celsiusBox4.Size = new System.Drawing.Size(100, 20);
            this.celsiusBox4.TabIndex = 16;
            this.celsiusBox4.TextChanged += new System.EventHandler(this.textBox11_TextChanged);
            // 
            // kelvinBox4
            // 
            this.kelvinBox4.Enabled = false;
            this.kelvinBox4.Location = new System.Drawing.Point(480, 92);
            this.kelvinBox4.Name = "kelvinBox4";
            this.kelvinBox4.Size = new System.Drawing.Size(100, 20);
            this.kelvinBox4.TabIndex = 17;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(303, 19);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(57, 13);
            this.label4.TabIndex = 18;
            this.label4.Text = "Fahrenheit";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(409, 19);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(40, 13);
            this.label5.TabIndex = 19;
            this.label5.Text = "Celsius";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(511, 19);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(36, 13);
            this.label6.TabIndex = 20;
            this.label6.Text = "Kelvin";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(608, 127);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.kelvinBox4);
            this.Controls.Add(this.celsiusBox4);
            this.Controls.Add(this.fahrenheitBox4);
            this.Controls.Add(this.kelvinBox3);
            this.Controls.Add(this.celsiusBox3);
            this.Controls.Add(this.fahrenheitBox3);
            this.Controls.Add(this.kelvinBox2);
            this.Controls.Add(this.celsiusBox2);
            this.Controls.Add(this.fahrenheitBox2);
            this.Controls.Add(this.btnKelvin);
            this.Controls.Add(this.btnCelsius);
            this.Controls.Add(this.kelvinBox1);
            this.Controls.Add(this.celsiusBox1);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.fahrenheitBox1);
            this.Controls.Add(this.btnFahrenheit);
            this.Controls.Add(this.label1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button btnFahrenheit;
        private System.Windows.Forms.TextBox fahrenheitBox1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox celsiusBox1;
        private System.Windows.Forms.TextBox kelvinBox1;
        private System.Windows.Forms.Button btnCelsius;
        private System.Windows.Forms.Button btnKelvin;
        private System.Windows.Forms.TextBox fahrenheitBox2;
        private System.Windows.Forms.TextBox celsiusBox2;
        private System.Windows.Forms.TextBox kelvinBox2;
        private System.Windows.Forms.TextBox fahrenheitBox3;
        private System.Windows.Forms.TextBox celsiusBox3;
        private System.Windows.Forms.TextBox kelvinBox3;
        private System.Windows.Forms.TextBox fahrenheitBox4;
        private System.Windows.Forms.TextBox celsiusBox4;
        private System.Windows.Forms.TextBox kelvinBox4;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
    }
}

