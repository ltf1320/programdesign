using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;
using svmcallcsharp;

namespace svmgui
{
    public partial class svmgui : Form
    {
        public svmgui()
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
            argv[0] = svmcallcsharp.svmcallcs.StringToByteArray("maintrain");
            for (Int32 i = 1; i < argc; i++)
            {
                if (isFileName(tmpV[i - 1]))
                {
                    FileInfo fi = new FileInfo(tmpV[i - 1]);
                    if (fi.Exists)
                    {
                        argv[i] = svmcallcsharp.svmcallcs.StringToByteArray(fi.FullName);
                        actualArg += fi.FullName;
                    }
                    else
                    {
                        argv[i] = svmcallcsharp.svmcallcs.StringToByteArray(tmpV[i - 1]);
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
                        argv[i] = svmcallcsharp.svmcallcs.StringToByteArray(tmpSS);
                        actualArg += tmpSS;
                    }else {
                        argv[i] = svmcallcsharp.svmcallcs.StringToByteArray(tmpV[i - 1]);
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
        private void updateLog(StringBuilder msgOut, ListBox lbox)
        {
            lbox.Items.Add("WorkingDir: "+_currentWorkingDir);
            String[] aa = (msgOut.ToString()).Split(new string[] { "\n" }, StringSplitOptions.RemoveEmptyEntries);
            foreach (String ss in aa)
            {
                lbox.Items.Add(ss);
            }
        }
        private Boolean isFileName(string s)
        {
            if (s == "")
            {
                return false;
            }
            Boolean isGoodFileName = true;
            foreach (char character in Path.GetInvalidFileNameChars())
            {
                if(s.Contains(character.ToString()) )
                {
                    return false;
                }
            }
            foreach (char character in Path.GetInvalidPathChars())
            {
                if (s.Contains(character.ToString()))
                {
                    return false;
                }
            }
            return isGoodFileName;
        }
        private void _runTrain_Click(object sender, EventArgs e)
        {
            Int32 argc = 0;
            IntPtr[] argv = null;
            prepareArg(out argc, out argv, _trainParam, _trainOutput);
            StringBuilder tmp = new StringBuilder(_StringBuilderCapacity);
            svmcallcsharp.svmcallcs.maintrainwithmsg(argc, argv, tmp);
            updateLog(tmp, _trainOutput);
        }
        private void _runScale_Click(object sender, EventArgs e)
        {
            Int32 argc = 0;
            IntPtr[] argv = null;
            prepareArg(out argc, out argv, _scaleParam, _scaleOutput);
            StringBuilder tmp = new StringBuilder(_StringBuilderCapacity);
            svmcallcsharp.svmcallcs.mainscalewithmsg(argc, argv, tmp);
            updateLog(tmp, _scaleOutput);
        }
        private void _runPredict_Click(object sender, EventArgs e)
        {
            Int32 argc = 0;
            IntPtr[] argv = null;
            prepareArg(out argc, out argv, _predictParam, _predictOutput);
            StringBuilder tmp = new StringBuilder(_StringBuilderCapacity);
            svmcallcsharp.svmcallcs.mainpredictwithmsg(argc, argv, tmp);
            updateLog(tmp, _predictOutput);
        }

        Int32 _StringBuilderCapacity;
        String _currentWorkingDir;

        private void _scaleParam_TextChanged(object sender, EventArgs e)
        {

        }

        private void _trainParam_TextChanged(object sender, EventArgs e)
        {

        }

        private void tableLayoutPanel1_Paint(object sender, PaintEventArgs e)
        {

        }
    }
}
