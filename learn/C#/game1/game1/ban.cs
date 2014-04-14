using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Drawing;
using System.Windows.Forms;
using System.Threading;
using System.Runtime.InteropServices;
namespace game1
{
    class ban
    {
        Form1 form; 
        PictureBox picturebox1;
        Point pt;
        public Size size;
   
        public ban(Form1 form)
        {
            size = new Size(200,20);
            pt.X = form.Height;
            pt.Y = form.Width / 2;
            this.form = form;
            picturebox1 = new PictureBox();
            picturebox1.SizeMode = PictureBoxSizeMode.Zoom;
            picturebox1.Size = size;
            picturebox1.BackColor = Color.Transparent;
            picturebox1.Image = Image.FromFile(Application.StartupPath + "\\ban.png");
            form.Controls.Add(picturebox1);
            picturebox1.Location = pt;

            form.KeyDown += new KeyEventHandler(form_KeyDown);
        }

        void form_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Left && pt.X > 0)
            {
                pt.X = pt.X - 20;
                picturebox1.Location = pt;
            }
            if (e.KeyCode == Keys.Right && pt.X+size.Width <form.Width )
            {
                pt.X = pt.X + 20;
                picturebox1.Location = pt;
            }
        }

        public Point point
        {
            get { return pt; }
        }

    }
}
