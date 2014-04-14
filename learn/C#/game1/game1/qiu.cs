using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Drawing;
using System.Timers;
namespace game1
{
    class qiu
    {
        PictureBox picturebox1;
        int size = 100;
        System.Timers.Timer mytimer;
        bool Dx = true, Dy = true;
        Point pt;
        Form form;
        ban ban1;
        public qiu(Form form,ban ban1)
        {
            this.form = form;
            this.ban1 = ban1;
            picturebox1 = new PictureBox();
            picturebox1.SizeMode = PictureBoxSizeMode.Zoom;
            picturebox1.Size = new Size(size, size);
            picturebox1.Image = Image.FromFile(Application.StartupPath + "\\qiu1.gif");
            form.Controls.Add(picturebox1);
            mytimer = new System.Timers.Timer(10);
            mytimer.Elapsed += new ElapsedEventHandler(mytimer_Elapsed);
            mytimer.Enabled = true;
        } 

        void mytimer_Elapsed(object sender, ElapsedEventArgs e)
        {
            if (Dx) pt.X = pt.X + 3; else pt.X = pt.X - 3;
            if (Dy) pt.Y = pt.Y + 3; else pt.Y = pt.Y - 3;
            this.picturebox1.Location = pt;
            pt.X = picturebox1.Location.X;
            pt.Y = picturebox1.Location.Y;
            if (pt.X > form.Width - picturebox1.Width || pt.X < 0) Dx = !Dx;
            if (pt.Y > form.Height - picturebox1.Height - 30 || pt.Y < 0) Dy = !Dy;

            if (pt.X + size / 2 > ban1.point.X && pt.X + size / 2 < ban1.point.X + ban1.size.Width && pt.Y + size < ban1.point.Y+4)
            { if (pt.Y + size > ban1.point.Y) { Dy = false; } }
        }
    }
}
