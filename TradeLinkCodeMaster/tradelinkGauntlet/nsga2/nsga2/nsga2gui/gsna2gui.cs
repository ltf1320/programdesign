using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;
using nsga2cscall;

namespace nsga2gui
{
    public partial class gsna2gui : Form
    {
        public gsna2gui()
        {
            InitializeComponent();
            _StringBuilderCapacity = 10000;
            _currentWorkingDir = Directory.GetCurrentDirectory();
        }

        private void prepareArg(out Int32 argc, out IntPtr[] argv, TextBox tBoxInput, ListBox lbox)
        {
            String actualArg = String.Empty;
            String[] tmpV = tBoxInput.Text.Split(' ');
            argc = tmpV.Length + 1;
            argv = new IntPtr[argc];
            argv[0] = nsga2cscall.nsga2cscall.StringToByteArray("maintest");
            for (Int32 i = 1; i < argc; i++)
            {
                if (isFileName(tmpV[i - 1]))
                {
                    FileInfo fi = new FileInfo(tmpV[i - 1]);
                    if (fi.Exists)
                    {
                        argv[i] = nsga2cscall.nsga2cscall.StringToByteArray(fi.FullName);
                        actualArg += fi.FullName;
                    }
                    else
                    {
                        argv[i] = nsga2cscall.nsga2cscall.StringToByteArray(tmpV[i - 1]);
                        actualArg += tmpV[i - 1];
                    }
                }
                else
                {
                    if(tmpV[i - 1].Contains('>'))
                    {
                        String[] tmpV1 = tmpV[i - 1].Split('>');
                        String tmpSS = String.Empty;
                        if (tmpV[i - 1].Length > 1)
                        {
                            for (Int32 ii = 0; ii < tmpV1.Length; ii++)
                            {
                                if (isFileName(tmpV1[ii]))
                                {
                                    FileInfo fi = new FileInfo(tmpV1[ii]);
                                    if (fi.Exists)
                                    {
                                        tmpSS += (fi.FullName);
                                    }
                                    else
                                    {
                                        tmpSS += (tmpV1[ii]);
                                    }
                                }
                                else
                                {
                                    tmpSS += tmpV1[ii];
                                }
                                if (ii < tmpV1.Length - 1)
                                {
                                    tmpSS += ">";
                                }
                            }
                        }
                        else
                        {
                            tmpSS = tmpV[i - 1];
                        }
                        argv[i] = nsga2cscall.nsga2cscall.StringToByteArray(tmpV[i - 1]);
                        actualArg += tmpV[i - 1];
                    }
                }
                if (i < argc - 1)
                {
                    actualArg += " ";
                }
            }

            lbox.Items.Add("ActualArg: " + actualArg);
        }
        private void _runtest_Click_1(object sender, EventArgs e)
        {
            Int32 argc = 0;
            IntPtr[] argv = null;
            prepareArg(out argc, out argv, textBox1, testoutput);
            StringBuilder tmp = new StringBuilder(_StringBuilderCapacity);
            nsga2cscall.nsga2cscall.maintrainwithmsg(argc, argv, tmp);
            updateLog(tmp, testoutput);
        }
        private Boolean isFileName(string s)
        {
            if (s == "")
            {
                return false;
            }
            string[] tmpV = s.Split('\\');

            Boolean isGoodFileName = true;

            for (Int32 ii = 0; ii < tmpV.Length; ii++)
            {
                foreach (char character in Path.GetInvalidFileNameChars())
                {
                    if (tmpV[ii].Contains(character.ToString()))
                    {
                        return false;
                    }
                }
                foreach (char character in Path.GetInvalidPathChars())
                {
                    if (tmpV[ii].Contains(character.ToString()))
                    {
                        return false;
                    }
                }
            }
            return isGoodFileName;
        }
        private void updateLog(StringBuilder msgOut, ListBox lbox)
        {
            lbox.Items.Add("WorkingDir: " + _currentWorkingDir);
            String[] aa = (msgOut.ToString()).Split(new string[] { "\n" }, StringSplitOptions.RemoveEmptyEntries);
            foreach (String ss in aa)
            {
                lbox.Items.Add(ss);
            }
        }

        int _StringBuilderCapacity;
        string _currentWorkingDir;
    }
}
