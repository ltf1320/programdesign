using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Runtime.InteropServices;
using System.Threading;
namespace game1
{
    public partial class Form1 : Form
    {
        qiu qiu1;
        ban ban1; 
        public Form1()
        {
            InitializeComponent();
            Form.CheckForIllegalCrossThreadCalls = false;
            //this.BackColor = Color.White;
            ban1 = new ban(this);
            qiu1 = new qiu(this,ban1);
            
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }
    }
}
