﻿/*  Wavelet Studio Signal Processing Library - www.waveletstudio.net
    Copyright (C) 2011, 2012 Walter V. S. de Amorim - The Wavelet Studio Initiative

    Wavelet Studio is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Wavelet Studio is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>. 
*/

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.ComponentModel.Design;
using System.Drawing.Design;
using WaveletStudio.Blocks.CustomAttributes;
using WaveletStudio.Properties;

namespace WaveletStudio.Blocks
{
    /// <summary>
    /// Generates a signal based on a text
    /// </summary>
    [SingleInputOutputBlock]
    [Serializable]
    public class ImportFromTextBlock : BlockBase
    {
        /// <summary>
        /// Constructor
        /// </summary>
        public ImportFromTextBlock()
        {
            BlockBase root = this;
            CreateNodes(ref root);
            ColumnSeparator = ",";
            SignalStart = 0;
            SamplingInterval = 1;
        }

        /// <summary>
        /// Name
        /// </summary>
        public override string Name { get { return Resources.Text; } }

        /// <summary>
        /// Description
        /// </summary>
        public override string Description { get { return Resources.TextBlockDescription; } }

        /// <summary>
        /// Processing type
        /// </summary>
        public override ProcessingTypeEnum ProcessingType { get { return ProcessingTypeEnum.LoadSignal; } }

        /// <summary>
        /// Text
        /// </summary>
        [Parameter]
        [Editor(typeof(MultilineStringEditor), typeof(UITypeEditor))]
        public string Text { get; set; }

        /// <summary>
        /// Column separator
        /// </summary>
        [Parameter]
        public string ColumnSeparator { get; set; }

        /// <summary>
        /// Signal start
        /// </summary>
        [Parameter]
        public int SignalStart { get; set; }

        private int _samplingRate;

        private double _samplingInterval;

        /// <summary>
        /// Sampling interval
        /// </summary>
        [Parameter]
        public double SamplingInterval 
        {
            get { return _samplingInterval; }
            set
            {
                _samplingInterval = value;
                if (Math.Abs(value - 0d) > double.Epsilon)
                {
                    _samplingRate = Convert.ToInt32(Math.Round(1 / value));   
                }
            }
        }

        /// <summary>
        /// If true, the first column contains the name of the signal
        /// </summary>
        [Parameter]
        public bool SignalNameInFirstColumn { get; set; }

        /// <summary>
        /// Executes the block
        /// </summary>
        public override void Execute()
        {
            OutputNodes[0].Object.Clear();
            if(string.IsNullOrEmpty(Text))
                return;

            var lineNumber = 0;
            var lines = Text.Split('\n');
            foreach (var line in lines)
            {
                lineNumber++;
                var signal = ParseLine(line);
                if (signal == null) 
                    continue;
                if (signal.Name == "")
                    signal.Name = Resources.Line + " " + lineNumber;
                OutputNodes[0].Object.Add(signal);
            }
            if (Cascade && OutputNodes[0].ConnectingNode != null)
                OutputNodes[0].ConnectingNode.Root.Execute();            
        }

        private Signal ParseLine(string line)
        {
            if(string.IsNullOrWhiteSpace(line))
                return null;

            var values = new List<double>();
            var samples = line.Trim().Split(new[] {ColumnSeparator}, StringSplitOptions.RemoveEmptyEntries);
            var columnNumber = 0;
            var signalName = "";
            foreach (var sampleString in samples)
            {
                columnNumber++;
                if (columnNumber == 1 && SignalNameInFirstColumn)
                {
                    signalName = sampleString;
                    continue;
                }
                double value;
                if (double.TryParse(sampleString, System.Globalization.NumberStyles.Number, System.Globalization.CultureInfo.InvariantCulture, out value))
                    values.Add(value);
            }
            if(values.Count == 0)
                return null;

            return new Signal(values.ToArray())
                             {
                                 Name = signalName,
                                 Start = SignalStart,
                                 SamplingRate = _samplingRate,
                                 SamplingInterval = SamplingInterval,
                                 Finish = SignalStart + SamplingInterval*values.Count - SamplingInterval
                             };            
        }

        /// <summary>
        /// Creates the input and output nodes
        /// </summary>
        /// <param name="root"></param>
        protected override sealed void CreateNodes(ref BlockBase root)
        {
            root.OutputNodes = BlockOutputNode.CreateSingleOutputSignal(ref root);
        }


        /// <summary>
        /// Clone the block, including the template
        /// </summary>
        /// <returns></returns>
        public override BlockBase Clone()
        {
            var block = (ImportFromTextBlock)MemberwiseClone();
            block.Execute();
            return block;
        }

        /// <summary>
        /// Clones this block but mantains the links
        /// </summary>
        /// <returns></returns>
        public override BlockBase CloneWithLinks()
        {
            var block = (ImportFromTextBlock)MemberwiseCloneWithLinks();
            block.Execute();
            return block;
        }
    }
}
