namespace svmgui
{
    partial class svmgui
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
            this.tableLayoutPanel1 = new System.Windows.Forms.TableLayoutPanel();
            this._runScale = new System.Windows.Forms.Button();
            this._runPredict = new System.Windows.Forms.Button();
            this._trainParam = new System.Windows.Forms.TextBox();
            this._predictParam = new System.Windows.Forms.TextBox();
            this._trainOutput = new System.Windows.Forms.ListBox();
            this._scaleOutput = new System.Windows.Forms.ListBox();
            this._predictOutput = new System.Windows.Forms.ListBox();
            this._runTrain = new System.Windows.Forms.Button();
            this._scaleParam = new System.Windows.Forms.TextBox();
            this.tableLayoutPanel1.SuspendLayout();
            this.SuspendLayout();
            // 
            // tableLayoutPanel1
            // 
            this.tableLayoutPanel1.AutoSize = true;
            this.tableLayoutPanel1.ColumnCount = 3;
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 13.21839F));
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 46.26437F));
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 40.37356F));
            this.tableLayoutPanel1.Controls.Add(this._runScale, 0, 1);
            this.tableLayoutPanel1.Controls.Add(this._runPredict, 0, 2);
            this.tableLayoutPanel1.Controls.Add(this._trainParam, 1, 0);
            this.tableLayoutPanel1.Controls.Add(this._predictParam, 1, 2);
            this.tableLayoutPanel1.Controls.Add(this._trainOutput, 2, 0);
            this.tableLayoutPanel1.Controls.Add(this._scaleOutput, 2, 1);
            this.tableLayoutPanel1.Controls.Add(this._predictOutput, 2, 2);
            this.tableLayoutPanel1.Controls.Add(this._runTrain, 0, 0);
            this.tableLayoutPanel1.Controls.Add(this._scaleParam, 1, 1);
            this.tableLayoutPanel1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tableLayoutPanel1.Location = new System.Drawing.Point(0, 0);
            this.tableLayoutPanel1.Name = "tableLayoutPanel1";
            this.tableLayoutPanel1.RowCount = 3;
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 33.33333F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 33.33333F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 33.33333F));
            this.tableLayoutPanel1.Size = new System.Drawing.Size(696, 305);
            this.tableLayoutPanel1.TabIndex = 0;
            this.tableLayoutPanel1.Paint += new System.Windows.Forms.PaintEventHandler(this.tableLayoutPanel1_Paint);
            // 
            // _runScale
            // 
            this._runScale.Anchor = System.Windows.Forms.AnchorStyles.None;
            this._runScale.Location = new System.Drawing.Point(8, 140);
            this._runScale.Name = "_runScale";
            this._runScale.Size = new System.Drawing.Size(75, 23);
            this._runScale.TabIndex = 1;
            this._runScale.Text = "Scale";
            this._runScale.UseVisualStyleBackColor = true;
            this._runScale.Click += new System.EventHandler(this._runScale_Click);
            // 
            // _runPredict
            // 
            this._runPredict.Anchor = System.Windows.Forms.AnchorStyles.None;
            this._runPredict.Location = new System.Drawing.Point(8, 242);
            this._runPredict.Name = "_runPredict";
            this._runPredict.Size = new System.Drawing.Size(75, 23);
            this._runPredict.TabIndex = 2;
            this._runPredict.Text = "Predict";
            this._runPredict.UseVisualStyleBackColor = true;
            this._runPredict.Click += new System.EventHandler(this._runPredict_Click);
            // 
            // _trainParam
            // 
            this._trainParam.Anchor = System.Windows.Forms.AnchorStyles.None;
            this._trainParam.Location = new System.Drawing.Point(95, 27);
            this._trainParam.Multiline = true;
            this._trainParam.Name = "_trainParam";
            this._trainParam.Size = new System.Drawing.Size(316, 47);
            this._trainParam.TabIndex = 3;
            this._trainParam.Text = "-s 1 -g 0.04167 -n 0.339 -e 0.00001 TestParam/IF0005_100.scd TestParam/IF0005_100" +
    ".mdl";
            this._trainParam.TextChanged += new System.EventHandler(this._trainParam_TextChanged);
            // 
            // _predictParam
            // 
            this._predictParam.Anchor = System.Windows.Forms.AnchorStyles.None;
            this._predictParam.Location = new System.Drawing.Point(95, 228);
            this._predictParam.Multiline = true;
            this._predictParam.Name = "_predictParam";
            this._predictParam.Size = new System.Drawing.Size(316, 50);
            this._predictParam.TabIndex = 5;
            this._predictParam.Text = "TestParam/IF0005_10.scd TestParam/IF0005_100.mdl TestParam/IF0005_10.prd";
            // 
            // _trainOutput
            // 
            this._trainOutput.Dock = System.Windows.Forms.DockStyle.Fill;
            this._trainOutput.FormattingEnabled = true;
            this._trainOutput.Location = new System.Drawing.Point(417, 3);
            this._trainOutput.Name = "_trainOutput";
            this._trainOutput.Size = new System.Drawing.Size(276, 95);
            this._trainOutput.TabIndex = 6;
            // 
            // _scaleOutput
            // 
            this._scaleOutput.Dock = System.Windows.Forms.DockStyle.Fill;
            this._scaleOutput.FormattingEnabled = true;
            this._scaleOutput.Location = new System.Drawing.Point(417, 104);
            this._scaleOutput.Name = "_scaleOutput";
            this._scaleOutput.Size = new System.Drawing.Size(276, 95);
            this._scaleOutput.TabIndex = 7;
            // 
            // _predictOutput
            // 
            this._predictOutput.Dock = System.Windows.Forms.DockStyle.Fill;
            this._predictOutput.FormattingEnabled = true;
            this._predictOutput.Location = new System.Drawing.Point(417, 205);
            this._predictOutput.Name = "_predictOutput";
            this._predictOutput.Size = new System.Drawing.Size(276, 97);
            this._predictOutput.TabIndex = 8;
            // 
            // _runTrain
            // 
            this._runTrain.Anchor = System.Windows.Forms.AnchorStyles.None;
            this._runTrain.Location = new System.Drawing.Point(8, 39);
            this._runTrain.Name = "_runTrain";
            this._runTrain.Size = new System.Drawing.Size(75, 23);
            this._runTrain.TabIndex = 0;
            this._runTrain.Text = "Train";
            this._runTrain.UseVisualStyleBackColor = true;
            this._runTrain.Click += new System.EventHandler(this._runTrain_Click);
            // 
            // _scaleParam
            // 
            this._scaleParam.Anchor = System.Windows.Forms.AnchorStyles.None;
            this._scaleParam.Location = new System.Drawing.Point(95, 128);
            this._scaleParam.Multiline = true;
            this._scaleParam.Name = "_scaleParam";
            this._scaleParam.Size = new System.Drawing.Size(316, 46);
            this._scaleParam.TabIndex = 4;
            this._scaleParam.Text = "-r TestParam/IF0005_100.scl TestParam/IF0005_10.txt > TestParam/IF0005_10.scd";
            this._scaleParam.TextChanged += new System.EventHandler(this._scaleParam_TextChanged);
            // 
            // svmgui
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(696, 305);
            this.Controls.Add(this.tableLayoutPanel1);
            this.Name = "svmgui";
            this.Text = "SVMGUI";
            this.tableLayoutPanel1.ResumeLayout(false);
            this.tableLayoutPanel1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel1;
        private System.Windows.Forms.Button _runTrain;
        private System.Windows.Forms.Button _runScale;
        private System.Windows.Forms.Button _runPredict;
        private System.Windows.Forms.TextBox _trainParam;
        private System.Windows.Forms.TextBox _scaleParam;
        private System.Windows.Forms.TextBox _predictParam;
        private System.Windows.Forms.ListBox _trainOutput;
        private System.Windows.Forms.ListBox _scaleOutput;
        private System.Windows.Forms.ListBox _predictOutput;
    }
}

