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
using WaveletStudio.Properties;

namespace WaveletStudio.Blocks
{
    /// <summary>
    /// Output node of an block
    /// </summary>
    [Serializable]
    public class BlockOutputNode : BlockNodeBase
    {
        /// <summary>
        /// Object generated by the block
        /// </summary>
        public List<Signal> Object { get; set; }

        /// <summary>
        /// Constructor
        /// </summary>
        public BlockOutputNode()
        {

        }

        /// <summary>
        /// Constructor
        /// </summary>
        /// <param name="root">The block object thar contains this node</param>
        /// <param name="name">Name of the output</param>
        /// <param name="shortName">Short name</param>
        public BlockOutputNode(ref BlockBase root, string name, string shortName) : base(ref root, name, shortName)
        {
            Object = new List<Signal>();
        }

        /// <summary>
        /// Connect this output node to an input node in other block
        /// </summary>
        /// <param name="node"></param>
        public void ConnectTo(BlockInputNode node)
        {
            ConnectingNode = node;
            node.ConnectingNode = this;
        }
        
        /// <summary>
        /// Connect this output node to an input node in other block
        /// </summary>
        /// <param name="node"></param>
        public void ConnectTo(ref BlockInputNode node)
        {
            ConnectingNode = node;
            node.ConnectingNode = this;
        }

        /// <summary>
        /// Clones this object
        /// </summary>
        /// <returns></returns>
        public BlockOutputNode Clone()
        {
            return (BlockOutputNode)MemberwiseClone();
        }

        /// <summary>
        /// Create a single output node in a block
        /// </summary>
        internal static List<BlockOutputNode> CreateSingleOutput(ref BlockBase root)
        {
            return new List<BlockOutputNode> { new BlockOutputNode(ref root, Resources.Output, Resources.Out) };
        }
        
        /// <summary>
        /// Create a single output node in a block
        /// </summary>
        internal static List<BlockOutputNode> CreateSingleOutputSignal(ref BlockBase root)
        {
            return new List<BlockOutputNode> { new BlockOutputNode(ref root, Resources.Signal, Resources.Out) };
        }
    }
}
