namespace Kadina
{
    partial class kadinamain
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
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(kadinamain));
            this.statusStrip1 = new System.Windows.Forms.StatusStrip();
            this.recent = new System.Windows.Forms.ToolStripDropDownButton();
            this.reslist = new System.Windows.Forms.ToolStripDropDownButton();
            this._skinsavail = new System.Windows.Forms.ToolStripDropDownButton();
            this._tabs = new System.Windows.Forms.TabControl();
            this.msgtab = new System.Windows.Forms.TabPage();
            this.debugControl1 = new TradeLink.AppKit.DebugControl();
            this.ticktab = new System.Windows.Forms.TabPage();
            this.itab = new System.Windows.Forms.TabPage();
            this.postab = new System.Windows.Forms.TabPage();
            this.ordertab = new System.Windows.Forms.TabPage();
            this.filltab = new System.Windows.Forms.TabPage();
            this.charttab = new System.Windows.Forms.TabPage();
            this._results = new System.Windows.Forms.TabPage();
            this.statusStrip2 = new System.Windows.Forms.StatusStrip();
            this._stat = new System.Windows.Forms.ToolStripStatusLabel();
            this.toolTip1 = new System.Windows.Forms.ToolTip(this.components);
            this.onemin = new System.Windows.Forms.Button();
            this.fivemin = new System.Windows.Forms.Button();
            this.tenmin = new System.Windows.Forms.Button();
            this.thirtymin = new System.Windows.Forms.Button();
            this.onehour = new System.Windows.Forms.Button();
            this.ptend = new System.Windows.Forms.Button();
            this.onesec = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.twohour = new System.Windows.Forms.Button();
            this.fourhour = new System.Windows.Forms.Button();
            this.button1 = new System.Windows.Forms.Button();
            this._reset = new System.Windows.Forms.Button();
            this._useBidAsk = new System.Windows.Forms.CheckBox();
            this.oneday = new System.Windows.Forms.Button();
            this.fiveday = new System.Windows.Forms.Button();
            this.tenday = new System.Windows.Forms.Button();
            this.onemonth = new System.Windows.Forms.Button();
            this.sixmonth = new System.Windows.Forms.Button();
            this.oneyear = new System.Windows.Forms.Button();
            this.fiveyear = new System.Windows.Forms.Button();
            this.tenyear = new System.Windows.Forms.Button();
            this.MSGOnOff = new System.Windows.Forms.Button();
            this.msgTypeToChose = new System.Windows.Forms.ComboBox();
            this.msgTypeLabel = new System.Windows.Forms.Label();
            this.statusStrip1.SuspendLayout();
            this._tabs.SuspendLayout();
            this.msgtab.SuspendLayout();
            this.statusStrip2.SuspendLayout();
            this.SuspendLayout();
            // 
            // statusStrip1
            // 
            this.statusStrip1.AutoSize = false;
            this.statusStrip1.Dock = System.Windows.Forms.DockStyle.Top;
            this.statusStrip1.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            this.statusStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.recent,
            this.reslist,
            this._skinsavail});
            this.statusStrip1.LayoutStyle = System.Windows.Forms.ToolStripLayoutStyle.Flow;
            this.statusStrip1.Location = new System.Drawing.Point(0, 0);
            this.statusStrip1.Name = "statusStrip1";
            this.statusStrip1.Padding = new System.Windows.Forms.Padding(1, 3, 1, 22);
            this.statusStrip1.ShowItemToolTips = true;
            this.statusStrip1.Size = new System.Drawing.Size(863, 64);
            this.statusStrip1.SizingGrip = false;
            this.statusStrip1.TabIndex = 1;
            this.statusStrip1.Text = "statusStrip1";
            this.toolTip1.SetToolTip(this.statusStrip1, "Study Options");
            // 
            // recent
            // 
            this.recent.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Text;
            this.recent.Image = ((System.Drawing.Image)(resources.GetObject("recent.Image")));
            this.recent.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.recent.Name = "recent";
            this.recent.Size = new System.Drawing.Size(68, 19);
            this.recent.Text = "Add data";
            this.recent.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.recent.ToolTipText = "Add historical tick files to study";
            this.recent.DropDownItemClicked += new System.Windows.Forms.ToolStripItemClickedEventHandler(this.recent_DropDownItemClicked);
            // 
            // reslist
            // 
            this.reslist.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Text;
            this.reslist.Image = ((System.Drawing.Image)(resources.GetObject("reslist.Image")));
            this.reslist.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.reslist.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.reslist.Name = "reslist";
            this.reslist.Overflow = System.Windows.Forms.ToolStripItemOverflow.Never;
            this.reslist.Size = new System.Drawing.Size(92, 19);
            this.reslist.Text = "Add response";
            this.reslist.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.reslist.ToolTipText = "Choose response library and a response to study";
            this.reslist.DropDownItemClicked += new System.Windows.Forms.ToolStripItemClickedEventHandler(this.libs_DropDownItemClicked);
            // 
            // _skinsavail
            // 
            this._skinsavail.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Text;
            this._skinsavail.Image = ((System.Drawing.Image)(resources.GetObject("_skinsavail.Image")));
            this._skinsavail.ImageTransparentColor = System.Drawing.Color.Magenta;
            this._skinsavail.Name = "_skinsavail";
            this._skinsavail.Size = new System.Drawing.Size(47, 19);
            this._skinsavail.Text = "Skins";
            this._skinsavail.DropDownItemClicked += new System.Windows.Forms.ToolStripItemClickedEventHandler(this._skinsavail_DropDownItemClicked);
            // 
            // _tabs
            // 
            this._tabs.AllowDrop = true;
            this._tabs.Appearance = System.Windows.Forms.TabAppearance.Buttons;
            this._tabs.Controls.Add(this.msgtab);
            this._tabs.Controls.Add(this.ticktab);
            this._tabs.Controls.Add(this.itab);
            this._tabs.Controls.Add(this.postab);
            this._tabs.Controls.Add(this.ordertab);
            this._tabs.Controls.Add(this.filltab);
            this._tabs.Controls.Add(this.charttab);
            this._tabs.Controls.Add(this._results);
            this._tabs.Location = new System.Drawing.Point(0, 67);
            this._tabs.Name = "_tabs";
            this._tabs.SelectedIndex = 0;
            this._tabs.Size = new System.Drawing.Size(504, 196);
            this._tabs.TabIndex = 2;
            this._tabs.DragDrop += new System.Windows.Forms.DragEventHandler(this.kadinamain_DragDrop);
            this._tabs.DragEnter += new System.Windows.Forms.DragEventHandler(this.kadinamain_DragEnter);
            // 
            // msgtab
            // 
            this.msgtab.Controls.Add(this.debugControl1);
            this.msgtab.Location = new System.Drawing.Point(4, 25);
            this.msgtab.Name = "msgtab";
            this.msgtab.Padding = new System.Windows.Forms.Padding(3);
            this.msgtab.Size = new System.Drawing.Size(496, 167);
            this.msgtab.TabIndex = 0;
            this.msgtab.Text = "Messages";
            this.msgtab.UseVisualStyleBackColor = true;
            // 
            // debugControl1
            // 
            this.debugControl1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.debugControl1.EnableSearching = true;
            this.debugControl1.ExternalTimeStamp = 0;
            this.debugControl1.Location = new System.Drawing.Point(3, 3);
            this.debugControl1.Margin = new System.Windows.Forms.Padding(1);
            this.debugControl1.Name = "debugControl1";
            this.debugControl1.Size = new System.Drawing.Size(490, 161);
            this.debugControl1.TabIndex = 0;
            this.debugControl1.TimeStamps = false;
            this.debugControl1.UseExternalTimeStamp = false;
            // 
            // ticktab
            // 
            this.ticktab.Location = new System.Drawing.Point(4, 25);
            this.ticktab.Name = "ticktab";
            this.ticktab.Padding = new System.Windows.Forms.Padding(3);
            this.ticktab.Size = new System.Drawing.Size(496, 167);
            this.ticktab.TabIndex = 1;
            this.ticktab.Text = "Ticks";
            this.ticktab.UseVisualStyleBackColor = true;
            // 
            // itab
            // 
            this.itab.Location = new System.Drawing.Point(4, 25);
            this.itab.Name = "itab";
            this.itab.Size = new System.Drawing.Size(496, 167);
            this.itab.TabIndex = 2;
            this.itab.Text = "Indicators";
            this.itab.UseVisualStyleBackColor = true;
            // 
            // postab
            // 
            this.postab.Location = new System.Drawing.Point(4, 25);
            this.postab.Margin = new System.Windows.Forms.Padding(2, 3, 2, 3);
            this.postab.Name = "postab";
            this.postab.Size = new System.Drawing.Size(496, 167);
            this.postab.TabIndex = 3;
            this.postab.Text = "Position";
            this.postab.UseVisualStyleBackColor = true;
            // 
            // ordertab
            // 
            this.ordertab.Location = new System.Drawing.Point(4, 25);
            this.ordertab.Margin = new System.Windows.Forms.Padding(2, 3, 2, 3);
            this.ordertab.Name = "ordertab";
            this.ordertab.Size = new System.Drawing.Size(496, 167);
            this.ordertab.TabIndex = 4;
            this.ordertab.Text = "Orders";
            this.ordertab.UseVisualStyleBackColor = true;
            // 
            // filltab
            // 
            this.filltab.Location = new System.Drawing.Point(4, 25);
            this.filltab.Margin = new System.Windows.Forms.Padding(2, 3, 2, 3);
            this.filltab.Name = "filltab";
            this.filltab.Size = new System.Drawing.Size(496, 167);
            this.filltab.TabIndex = 5;
            this.filltab.Text = "Fills";
            this.filltab.UseVisualStyleBackColor = true;
            // 
            // charttab
            // 
            this.charttab.Location = new System.Drawing.Point(4, 25);
            this.charttab.Margin = new System.Windows.Forms.Padding(2);
            this.charttab.Name = "charttab";
            this.charttab.Size = new System.Drawing.Size(496, 167);
            this.charttab.TabIndex = 6;
            this.charttab.Text = "Chart";
            this.charttab.UseVisualStyleBackColor = true;
            // 
            // _results
            // 
            this._results.Location = new System.Drawing.Point(4, 25);
            this._results.Margin = new System.Windows.Forms.Padding(2);
            this._results.Name = "_results";
            this._results.Padding = new System.Windows.Forms.Padding(2);
            this._results.Size = new System.Drawing.Size(496, 167);
            this._results.TabIndex = 7;
            this._results.Text = "Results";
            this._results.UseVisualStyleBackColor = true;
            // 
            // statusStrip2
            // 
            this.statusStrip2.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this._stat});
            this.statusStrip2.Location = new System.Drawing.Point(0, 264);
            this.statusStrip2.Name = "statusStrip2";
            this.statusStrip2.Padding = new System.Windows.Forms.Padding(1, 0, 9, 0);
            this.statusStrip2.Size = new System.Drawing.Size(863, 22);
            this.statusStrip2.SizingGrip = false;
            this.statusStrip2.TabIndex = 1;
            this.statusStrip2.Text = "statusStrip2";
            // 
            // _stat
            // 
            this._stat.Name = "_stat";
            this._stat.Size = new System.Drawing.Size(340, 17);
            this._stat.Text = "Kadina lets you see your response to a given set of market data.";
            // 
            // onemin
            // 
            this.onemin.Location = new System.Drawing.Point(333, 8);
            this.onemin.Margin = new System.Windows.Forms.Padding(2);
            this.onemin.Name = "onemin";
            this.onemin.Size = new System.Drawing.Size(40, 22);
            this.onemin.TabIndex = 3;
            this.onemin.Text = "1m";
            this.onemin.UseVisualStyleBackColor = true;
            this.onemin.Click += new System.EventHandler(this.onemin_Click);
            // 
            // fivemin
            // 
            this.fivemin.Location = new System.Drawing.Point(377, 8);
            this.fivemin.Margin = new System.Windows.Forms.Padding(2);
            this.fivemin.Name = "fivemin";
            this.fivemin.Size = new System.Drawing.Size(37, 22);
            this.fivemin.TabIndex = 4;
            this.fivemin.Text = "5m";
            this.fivemin.UseVisualStyleBackColor = true;
            this.fivemin.Click += new System.EventHandler(this.fivemin_Click);
            // 
            // tenmin
            // 
            this.tenmin.Location = new System.Drawing.Point(419, 8);
            this.tenmin.Margin = new System.Windows.Forms.Padding(2);
            this.tenmin.Name = "tenmin";
            this.tenmin.Size = new System.Drawing.Size(41, 22);
            this.tenmin.TabIndex = 5;
            this.tenmin.Text = "10m";
            this.tenmin.UseVisualStyleBackColor = true;
            this.tenmin.Click += new System.EventHandler(this.tenmin_Click);
            // 
            // thirtymin
            // 
            this.thirtymin.Location = new System.Drawing.Point(463, 8);
            this.thirtymin.Margin = new System.Windows.Forms.Padding(2);
            this.thirtymin.Name = "thirtymin";
            this.thirtymin.Size = new System.Drawing.Size(41, 22);
            this.thirtymin.TabIndex = 6;
            this.thirtymin.Text = "30m";
            this.thirtymin.UseVisualStyleBackColor = true;
            this.thirtymin.Click += new System.EventHandler(this.thirtymin_Click);
            // 
            // onehour
            // 
            this.onehour.Location = new System.Drawing.Point(291, 36);
            this.onehour.Margin = new System.Windows.Forms.Padding(2);
            this.onehour.Name = "onehour";
            this.onehour.Size = new System.Drawing.Size(39, 22);
            this.onehour.TabIndex = 7;
            this.onehour.Text = "1hr";
            this.onehour.UseVisualStyleBackColor = true;
            this.onehour.Click += new System.EventHandler(this.onehour_Click);
            // 
            // ptend
            // 
            this.ptend.Location = new System.Drawing.Point(419, 36);
            this.ptend.Margin = new System.Windows.Forms.Padding(2);
            this.ptend.Name = "ptend";
            this.ptend.Size = new System.Drawing.Size(41, 22);
            this.ptend.TabIndex = 8;
            this.ptend.Text = "end";
            this.ptend.UseVisualStyleBackColor = true;
            this.ptend.Click += new System.EventHandler(this.ptend_Click);
            // 
            // onesec
            // 
            this.onesec.Location = new System.Drawing.Point(290, 8);
            this.onesec.Margin = new System.Windows.Forms.Padding(2);
            this.onesec.Name = "onesec";
            this.onesec.Size = new System.Drawing.Size(39, 22);
            this.onesec.TabIndex = 9;
            this.onesec.Text = "1s";
            this.onesec.UseVisualStyleBackColor = true;
            this.onesec.Click += new System.EventHandler(this.onesec_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(223, 12);
            this.label1.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(50, 13);
            this.label1.TabIndex = 10;
            this.label1.Text = "Duration:";
            // 
            // twohour
            // 
            this.twohour.Location = new System.Drawing.Point(334, 36);
            this.twohour.Margin = new System.Windows.Forms.Padding(2);
            this.twohour.Name = "twohour";
            this.twohour.Size = new System.Drawing.Size(40, 22);
            this.twohour.TabIndex = 11;
            this.twohour.Text = "2hr";
            this.twohour.UseVisualStyleBackColor = true;
            this.twohour.Click += new System.EventHandler(this.twohour_Click);
            // 
            // fourhour
            // 
            this.fourhour.Location = new System.Drawing.Point(378, 36);
            this.fourhour.Margin = new System.Windows.Forms.Padding(2);
            this.fourhour.Name = "fourhour";
            this.fourhour.Size = new System.Drawing.Size(37, 22);
            this.fourhour.TabIndex = 12;
            this.fourhour.Text = "4hr";
            this.fourhour.UseVisualStyleBackColor = true;
            this.fourhour.Click += new System.EventHandler(this.fourhour_Click);
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(463, 36);
            this.button1.Margin = new System.Windows.Forms.Padding(2);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(41, 22);
            this.button1.TabIndex = 13;
            this.button1.Text = "cst";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // _reset
            // 
            this._reset.Location = new System.Drawing.Point(218, 36);
            this._reset.Margin = new System.Windows.Forms.Padding(2);
            this._reset.Name = "_reset";
            this._reset.Size = new System.Drawing.Size(63, 22);
            this._reset.TabIndex = 14;
            this._reset.Text = "Restart";
            this._reset.UseVisualStyleBackColor = true;
            this._reset.Click += new System.EventHandler(this._reset_Click);
            // 
            // _useBidAsk
            // 
            this._useBidAsk.AutoSize = true;
            this._useBidAsk.Checked = true;
            this._useBidAsk.CheckState = System.Windows.Forms.CheckState.Checked;
            this._useBidAsk.Location = new System.Drawing.Point(135, 39);
            this._useBidAsk.Name = "_useBidAsk";
            this._useBidAsk.Size = new System.Drawing.Size(78, 17);
            this._useBidAsk.TabIndex = 15;
            this._useBidAsk.Text = "UseBidAsk";
            this._useBidAsk.UseVisualStyleBackColor = true;
            this._useBidAsk.CheckedChanged += new System.EventHandler(this._useBidAsk_CheckedChanged);
            // 
            // oneday
            // 
            this.oneday.Location = new System.Drawing.Point(509, 8);
            this.oneday.Name = "oneday";
            this.oneday.Size = new System.Drawing.Size(41, 23);
            this.oneday.TabIndex = 16;
            this.oneday.Text = "1d";
            this.oneday.UseVisualStyleBackColor = true;
            this.oneday.Click += new System.EventHandler(this.oneday_Click);
            // 
            // fiveday
            // 
            this.fiveday.Location = new System.Drawing.Point(553, 8);
            this.fiveday.Name = "fiveday";
            this.fiveday.Size = new System.Drawing.Size(42, 23);
            this.fiveday.TabIndex = 17;
            this.fiveday.Text = "5d";
            this.fiveday.UseVisualStyleBackColor = true;
            this.fiveday.Click += new System.EventHandler(this.fiveday_Click);
            // 
            // tenday
            // 
            this.tenday.Location = new System.Drawing.Point(598, 8);
            this.tenday.Name = "tenday";
            this.tenday.Size = new System.Drawing.Size(40, 23);
            this.tenday.TabIndex = 18;
            this.tenday.Text = "10d";
            this.tenday.UseVisualStyleBackColor = true;
            this.tenday.Click += new System.EventHandler(this.tenday_Click);
            // 
            // onemonth
            // 
            this.onemonth.Location = new System.Drawing.Point(508, 36);
            this.onemonth.Name = "onemonth";
            this.onemonth.Size = new System.Drawing.Size(52, 23);
            this.onemonth.TabIndex = 19;
            this.onemonth.Text = "1month";
            this.onemonth.UseVisualStyleBackColor = true;
            this.onemonth.Click += new System.EventHandler(this.onemonth_Click);
            // 
            // sixmonth
            // 
            this.sixmonth.Location = new System.Drawing.Point(563, 36);
            this.sixmonth.Name = "sixmonth";
            this.sixmonth.Size = new System.Drawing.Size(50, 23);
            this.sixmonth.TabIndex = 20;
            this.sixmonth.Text = "6month";
            this.sixmonth.UseVisualStyleBackColor = true;
            this.sixmonth.Click += new System.EventHandler(this.sixmonth_Click);
            // 
            // oneyear
            // 
            this.oneyear.Location = new System.Drawing.Point(617, 36);
            this.oneyear.Name = "oneyear";
            this.oneyear.Size = new System.Drawing.Size(30, 23);
            this.oneyear.TabIndex = 21;
            this.oneyear.Text = "1y";
            this.oneyear.UseVisualStyleBackColor = true;
            this.oneyear.Click += new System.EventHandler(this.oneyear_Click);
            // 
            // fiveyear
            // 
            this.fiveyear.Location = new System.Drawing.Point(650, 36);
            this.fiveyear.Name = "fiveyear";
            this.fiveyear.Size = new System.Drawing.Size(30, 23);
            this.fiveyear.TabIndex = 22;
            this.fiveyear.Text = "5y";
            this.fiveyear.UseVisualStyleBackColor = true;
            this.fiveyear.Click += new System.EventHandler(this.fiveyear_Click);
            // 
            // tenyear
            // 
            this.tenyear.Location = new System.Drawing.Point(684, 36);
            this.tenyear.Name = "tenyear";
            this.tenyear.Size = new System.Drawing.Size(33, 23);
            this.tenyear.TabIndex = 23;
            this.tenyear.Text = "10y";
            this.tenyear.UseVisualStyleBackColor = true;
            this.tenyear.Click += new System.EventHandler(this.tenyear_Click);
            // 
            // MSGOnOff
            // 
            this.MSGOnOff.Location = new System.Drawing.Point(650, 7);
            this.MSGOnOff.Name = "MSGOnOff";
            this.MSGOnOff.Size = new System.Drawing.Size(75, 23);
            this.MSGOnOff.TabIndex = 24;
            this.MSGOnOff.Text = "MSG(Off)";
            this.MSGOnOff.UseVisualStyleBackColor = true;
            this.MSGOnOff.Click += new System.EventHandler(this.MSGOnOff_Click);
            // 
            // msgTypeToChose
            // 
            this.msgTypeToChose.FormattingEnabled = true;
            this.msgTypeToChose.Items.AddRange(new object[] {
            "none"});
            this.msgTypeToChose.Location = new System.Drawing.Point(786, 8);
            this.msgTypeToChose.Name = "msgTypeToChose";
            this.msgTypeToChose.Size = new System.Drawing.Size(54, 21);
            this.msgTypeToChose.TabIndex = 25;
            this.msgTypeToChose.SelectedIndexChanged += new System.EventHandler(this.msgTypeToChose_SelectedIndexChanged);
            // 
            // msgTypeLabel
            // 
            this.msgTypeLabel.AutoSize = true;
            this.msgTypeLabel.Location = new System.Drawing.Point(729, 12);
            this.msgTypeLabel.Name = "msgTypeLabel";
            this.msgTypeLabel.Size = new System.Drawing.Size(55, 13);
            this.msgTypeLabel.TabIndex = 26;
            this.msgTypeLabel.Text = "MSGType";
            // 
            // kadinamain
            // 
            this.AllowDrop = true;
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(863, 286);
            this.Controls.Add(this.msgTypeLabel);
            this.Controls.Add(this.msgTypeToChose);
            this.Controls.Add(this.MSGOnOff);
            this.Controls.Add(this.tenyear);
            this.Controls.Add(this.fiveyear);
            this.Controls.Add(this.oneyear);
            this.Controls.Add(this.sixmonth);
            this.Controls.Add(this.onemonth);
            this.Controls.Add(this.tenday);
            this.Controls.Add(this.fiveday);
            this.Controls.Add(this.oneday);
            this.Controls.Add(this._useBidAsk);
            this.Controls.Add(this._reset);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.fourhour);
            this.Controls.Add(this.twohour);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.onesec);
            this.Controls.Add(this.ptend);
            this.Controls.Add(this.onehour);
            this.Controls.Add(this.thirtymin);
            this.Controls.Add(this.tenmin);
            this.Controls.Add(this.fivemin);
            this.Controls.Add(this.onemin);
            this.Controls.Add(this.statusStrip2);
            this.Controls.Add(this._tabs);
            this.Controls.Add(this.statusStrip1);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "kadinamain";
            this.Text = "Kadina";
            this.DragDrop += new System.Windows.Forms.DragEventHandler(this.kadinamain_DragDrop);
            this.DragEnter += new System.Windows.Forms.DragEventHandler(this.kadinamain_DragEnter);
            this.statusStrip1.ResumeLayout(false);
            this.statusStrip1.PerformLayout();
            this._tabs.ResumeLayout(false);
            this.msgtab.ResumeLayout(false);
            this.statusStrip2.ResumeLayout(false);
            this.statusStrip2.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.StatusStrip statusStrip1;
        private System.Windows.Forms.ToolStripDropDownButton reslist;
        private System.Windows.Forms.TabControl _tabs;
        private System.Windows.Forms.TabPage msgtab;
        private System.Windows.Forms.TabPage ticktab;
        private System.Windows.Forms.ToolStripDropDownButton recent;
        private System.Windows.Forms.TabPage itab;
        private System.Windows.Forms.TabPage postab;
        private System.Windows.Forms.TabPage ordertab;
        private System.Windows.Forms.TabPage filltab;
        private System.Windows.Forms.ToolTip toolTip1;
        private System.Windows.Forms.StatusStrip statusStrip2;
        private System.Windows.Forms.ToolStripStatusLabel _stat;
        private System.Windows.Forms.TabPage charttab;
        private System.Windows.Forms.TabPage _results;
        private System.Windows.Forms.Button onemin;
        private System.Windows.Forms.Button fivemin;
        private System.Windows.Forms.Button tenmin;
        private System.Windows.Forms.Button thirtymin;
        private System.Windows.Forms.Button onehour;
        private System.Windows.Forms.Button ptend;
        private System.Windows.Forms.Button onesec;
        private System.Windows.Forms.Label label1;
        private TradeLink.AppKit.DebugControl debugControl1;
        private System.Windows.Forms.Button twohour;
        private System.Windows.Forms.Button fourhour;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button _reset;
        private System.Windows.Forms.ToolStripDropDownButton _skinsavail;
        private System.Windows.Forms.CheckBox _useBidAsk;
        private System.Windows.Forms.Button oneday;
        private System.Windows.Forms.Button fiveday;
        private System.Windows.Forms.Button tenday;
        private System.Windows.Forms.Button onemonth;
        private System.Windows.Forms.Button sixmonth;
        private System.Windows.Forms.Button oneyear;
        private System.Windows.Forms.Button fiveyear;
        private System.Windows.Forms.Button tenyear;
        private System.Windows.Forms.Button MSGOnOff;
        private System.Windows.Forms.ComboBox msgTypeToChose;
        private System.Windows.Forms.Label msgTypeLabel;
    }
}

