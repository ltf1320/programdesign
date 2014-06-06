namespace nsga2gui
{
    partial class gsna2gui
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
            this._runtest = new System.Windows.Forms.Button();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.testoutput = new System.Windows.Forms.ListBox();
            this.SuspendLayout();
            // 
            // _runtest
            // 
            this._runtest.Location = new System.Drawing.Point(12, 33);
            this._runtest.Name = "_runtest";
            this._runtest.Size = new System.Drawing.Size(86, 23);
            this._runtest.TabIndex = 0;
            this._runtest.Text = "runsga2test";
            this._runtest.UseVisualStyleBackColor = true;
            this._runtest.Click += new System.EventHandler(this._runtest_Click_1);
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(12, 93);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(209, 20);
            this.textBox1.TabIndex = 1;
            this.textBox1.Text = "0.1 input_data\\sch1.in";
            // 
            // testoutput
            // 
            this.testoutput.FormattingEnabled = true;
            this.testoutput.HorizontalScrollbar = true;
            this.testoutput.Location = new System.Drawing.Point(12, 138);
            this.testoutput.Name = "testoutput";
            this.testoutput.Size = new System.Drawing.Size(187, 95);
            this.testoutput.TabIndex = 2;
            // 
            // gsna2gui
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(284, 262);
            this.Controls.Add(this.testoutput);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this._runtest);
            this.Name = "gsna2gui";
            this.Text = "gsna2form";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button _runtest;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.ListBox testoutput;
    }
}

