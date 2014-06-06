/*  Wavelet Studio Signal Processing Library - www.waveletstudio.net
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
using WaveletStudio.Functions;

namespace WaveletStudio
{
    /// <summary>
    /// Signal extension methods
    /// </summary>
    public static class SignalExtension
    {
        /// <summary>
        /// Extension modes
        /// </summary>
        public enum ExtensionMode
        {
            /// <summary>
            /// Symmetric-padding (half-point): boundary value symmetric replication
            /// </summary>
            SymmetricHalfPoint,
            /// <summary>
            /// Symmetric-padding (whole-point): boundary value symmetric replication
            /// </summary>
            SymmetricWholePoint,
            /// <summary>
            /// Antisymmetric-padding (half-point): boundary value antisymmetric replication
            /// </summary>
            AntisymmetricHalfPoint,
            /// <summary>
            /// Antisymmetric-padding (whole-point): boundary value antisymmetric replication
            /// </summary>
            AntisymmetricWholePoint,
            /// <summary>
            /// Periodized extension
            /// </summary>
            PeriodicPadding,
            /// <summary>
            /// Zero extension
            /// </summary>
            ZeroPadding,
            /// <summary>
            /// Smooth extension of order 0 (Continuous)
            /// </summary>
            SmoothPadding0, 
            /// <summary>
            /// Smooth extension of order 1
            /// </summary>
            SmoothPadding1
        }

        /// <summary>
        /// Extends a signal using the specified extension mode
        /// </summary>
        /// <param name="input">Signal to extend</param>
        /// <param name="extensionMode">The extension mode</param>
        /// <param name="beforeSize">The extension size of the left side</param>
        /// <param name="afterSize">The extension size of right left side</param>
        /// <returns></returns>
        public static void Extend(ref Signal input, ExtensionMode extensionMode, int beforeSize, int afterSize)
        {
            var samples = Extend(input.Samples, extensionMode, beforeSize, afterSize);
            var previousSamplingInterval = input.SamplingInterval;
            input.CustomPlot = new[]{input.Start, input.Finish};
            input.Start -= input.SamplingInterval * beforeSize;
            input.Finish += input.SamplingInterval * afterSize;
            input.Samples = samples;
            input.SamplingInterval = previousSamplingInterval;
        }
        
        /// <summary>
        /// Extends an array using the specified extension mode
        /// </summary>
        /// <param name="input">Array to extend</param>
        /// <param name="extensionMode">The extension mode</param>
        /// <param name="extensionSize">The extension size of the left and right sides (each one)</param>
        /// <returns></returns>
        public static double[] Extend(double[] input, ExtensionMode extensionMode, int extensionSize)
        {
            return Extend(input, extensionMode, extensionSize, extensionSize);
        }

        /// <summary>
        /// Extends an array using the specified extension mode
        /// </summary>
        /// <param name="input">Array to extend</param>
        /// <param name="extensionMode">The extension mode</param>
        /// <param name="beforeSize">The extension size of the left side</param>
        /// <param name="afterSize">The extension size of right left side</param>
        /// <returns></returns>
        public static double[] Extend(double[] input, ExtensionMode extensionMode, int beforeSize, int afterSize)
        {//基本整个函数都要改，C#和Matlab扩展的方法不一致
            if (input.Length == 0)
            {
                return MemoryPool.Pool.New<double>(beforeSize + afterSize, true);
            }
            var pointsHalfLength = input.Length;
            while ((beforeSize > input.Length || afterSize > input.Length) && extensionMode != ExtensionMode.SymmetricWholePoint && extensionMode != ExtensionMode.AntisymmetricWholePoint)
            {
                while (beforeSize > input.Length)
                {
                    int size = beforeSize - input.Length;
                    input = Extend(input, extensionMode, pointsHalfLength);
                    input = Extend(input, extensionMode, size);
                }
                return input;
            }
            var beforeExtension = MemoryPool.Pool.New<double>(beforeSize, true);
            var afterExtension = MemoryPool.Pool.New<double>(afterSize, true);

            if (extensionMode != ExtensionMode.ZeroPadding)
            {
                if (extensionMode == ExtensionMode.SymmetricHalfPoint || extensionMode == ExtensionMode.AntisymmetricHalfPoint)
                {
                    if (beforeSize > 0)
                    {
                        Array.Copy(input, beforeExtension, beforeSize);
                        Array.Reverse(beforeExtension);
                    }
                    Array.Copy(input, input.Length - afterSize, afterExtension, 0, afterSize);
                    Array.Reverse(afterExtension);
                    if (extensionMode == ExtensionMode.AntisymmetricHalfPoint)
                    {
                        if (beforeSize > 0)
                            beforeExtension = WaveMath.Multiply(beforeExtension, -1);
                        afterExtension = WaveMath.Multiply(afterExtension, -1);
                    }
                }
                else if (extensionMode == ExtensionMode.SymmetricWholePoint)
                {
                    int inputlength = 0;
                    if (input.Length<2)
                    {
                        inputlength = 2;
                        beforeExtension = MemoryPool.Pool.New<double>(inputlength - 1, true);
                        afterExtension = MemoryPool.Pool.New<double>(inputlength - 1, true);
                        Array.Copy(input, 0, beforeExtension, 0, inputlength - 1);
                        Array.Copy(input, 0, afterExtension, 0, inputlength - 1);
                    }
                    else
                    {
                        inputlength=input.Length;
                        beforeExtension = MemoryPool.Pool.New<double>(inputlength - 1, true);
                        afterExtension = MemoryPool.Pool.New<double>(inputlength - 1, true);
                        Array.Copy(input, 0, beforeExtension, 0, inputlength - 1);
                        Array.Copy(input, 1, afterExtension, 0, inputlength - 1);
                    }
                    var temp=input;
                    int count = 0;
                    while (temp.Length + inputlength * 2 - 2 < beforeSize + afterSize + inputlength)
                    {
                        Array.Reverse(beforeExtension);
                        Array.Reverse(afterExtension);
                        var temp2 = MemoryPool.Pool.New<double>(inputlength - 1 + temp.Length + inputlength - 1);
                        afterExtension.CopyTo(temp2, 0);
                        temp.CopyTo(temp2, inputlength - 1);
                        beforeExtension.CopyTo(temp2, inputlength - 1 + temp.Length);
                        temp = temp2;
                        var tem = beforeExtension;
                        beforeExtension = afterExtension;
                        afterExtension = tem;
                        count++;
                    }
                    int k=(afterSize + inputlength + beforeSize - temp.Length) / 2;
                    beforeExtension = MemoryPool.Pool.New<double>(k, true);
                    afterExtension = MemoryPool.Pool.New<double>(k, true);
                    if (count % 2 == 1)
                    {
                        Array.Copy(input, inputlength - k - 1, beforeExtension, 0, k);
                        Array.Copy(input, 1, afterExtension, 0, k);
                    }
                    else
                    {
                        Array.Copy(input, inputlength - k - 1, afterExtension, 0, k);
                        Array.Copy(input, 1, beforeExtension, 0, k);
                        Array.Reverse(beforeExtension);
                        Array.Reverse(afterExtension);
                    }
                    var newPts = MemoryPool.Pool.New<double>(beforeSize + inputlength + afterSize);

                    beforeExtension.CopyTo(newPts, 0);
                    temp.CopyTo(newPts, beforeExtension.Length);
                    afterExtension.CopyTo(newPts, beforeExtension.Length + temp.Length);
                    return newPts;
                }
                else if (extensionMode == ExtensionMode.AntisymmetricWholePoint)
                {
                    int inputlength = 0;
                    if (input.Length < 2)
                    {
                        inputlength = 2;
                        beforeExtension = MemoryPool.Pool.New<double>(inputlength - 1, true);
                        afterExtension = MemoryPool.Pool.New<double>(inputlength - 1, true);
                        Array.Copy(input, 0, beforeExtension, 0, inputlength - 1);
                        Array.Copy(input, 0, afterExtension, 0, inputlength - 1);
                    }
                    else
                    {
                        inputlength = input.Length;
                        beforeExtension = MemoryPool.Pool.New<double>(inputlength - 1, true);
                        afterExtension = MemoryPool.Pool.New<double>(inputlength - 1, true);
                        Array.Copy(input, 0, beforeExtension, 0, inputlength - 1);
                        Array.Copy(input, 1, afterExtension, 0, inputlength - 1);
                    }
                    beforeExtension = MemoryPool.Pool.New<double>(inputlength - 1, true);
                    afterExtension = MemoryPool.Pool.New<double>(inputlength - 1, true);
                    var before = MemoryPool.Pool.New<double>(inputlength - 1);
                    var after = MemoryPool.Pool.New<double>(inputlength - 1);
                    for (int i = 0; i < input.Length - 1; i++)
                    {
                        before[i] = input[i] - input[i + 1];
                        after[i] = input[i + 1] - input[i];
                    }
                    Array.Reverse(after);
                    var temp=input;
                    while (temp.Length + inputlength * 2 - 2 < beforeSize + afterSize + inputlength)
                    {
                        var tempbefore = temp[0]; var tempafter = temp[temp.Length - 1];
                        for (int i = 0; i < inputlength - 1; i++)
                        {
                            beforeExtension[i] = tempbefore + before[i];
                            tempbefore = beforeExtension[i];
                            afterExtension[i] = tempafter + after[i];
                            tempafter = afterExtension[i];
                        }
                        Array.Reverse(before);
                        Array.Reverse(after);
                        Array.Reverse(beforeExtension);
                        var temp2 = MemoryPool.Pool.New<double>(inputlength - 1 + temp.Length + inputlength - 1);
                        beforeExtension.CopyTo(temp2, 0);
                        temp.CopyTo(temp2, beforeExtension.Length);
                        afterExtension.CopyTo(temp2, beforeExtension.Length + temp.Length);
                        temp = temp2;
                    }
                    int k = (afterSize + inputlength + beforeSize - temp.Length) / 2;
                    beforeExtension = MemoryPool.Pool.New<double>(k, true);
                    afterExtension = MemoryPool.Pool.New<double>(k, true);
                    var tempbefore2 = temp[0]; var tempafter2 = temp[temp.Length - 1];
                    for (int i = 0; i < k; i++)
                    {
                        beforeExtension[i] = tempbefore2 + before[i];
                        tempbefore2 = beforeExtension[i];
                        afterExtension[i] = tempafter2 + after[i];
                        tempafter2 = afterExtension[i];
                    }
                    Array.Reverse(beforeExtension);
                    var newPts = MemoryPool.Pool.New<double>(beforeSize + input.Length + afterSize);

                    beforeExtension.CopyTo(newPts, 0);
                    temp.CopyTo(newPts, beforeExtension.Length);
                    afterExtension.CopyTo(newPts, beforeExtension.Length + temp.Length);
                    return newPts;
                }
                else if(extensionMode == ExtensionMode.PeriodicPadding)
                {
                    if (beforeSize > 0)
                        Array.Copy(input, input.Length - beforeSize, beforeExtension, 0, beforeSize);
                    Array.Copy(input, 0, afterExtension, 0, afterSize);                    
                }
                else if (extensionMode == ExtensionMode.SmoothPadding0)
                {
                    if (beforeSize > 0)
                    {
                        for (var i = 0; i < beforeExtension.Length; i++)
                        {
                            beforeExtension[i] = input[0];
                        }
                    }
                    for (var i = 0; i < afterExtension.Length; i++)
                    {
                        afterExtension[i] = input[input.Length-1];
                    }
                }
                else if (extensionMode == ExtensionMode.SmoothPadding1)
                {
                    double previous;
                    if (beforeSize > 0)
                    {
                        var beforeDif = 0.0;
                        if (input.Length > 1)
                            beforeDif = input[0] - input[1];
                        previous = input[0];
                        for (var i = beforeSize - 1; i >= 0; i--)
                        {
                            beforeExtension[i] = previous + beforeDif;
                            previous = beforeExtension[i];
                        }
                    }   
                    var afterDif=0.0;
                    if (input.Length > 1)
                        afterDif= input[input.Length - 1] - input[input.Length - 2];
                    previous = input[input.Length - 1];
                    for (var i = 0; i < afterSize; i++)
                    {
                        afterExtension[i] = previous + afterDif;
                        previous = afterExtension[i];
                    }                                     
                }
            }

            var newPoints = MemoryPool.Pool.New<double>(beforeSize + input.Length + afterSize);            
            if (beforeSize > 0)
                beforeExtension.CopyTo(newPoints, 0);
            input.CopyTo(newPoints, beforeSize);    
            afterExtension.CopyTo(newPoints, beforeSize + input.Length);
            return newPoints;
        }

        /// <summary>
        /// Deextends an array, returning only its middle part
        /// </summary>
        /// <param name="input">Array to extend</param>
        /// <param name="size">The extension size of the left and right sides (each one)</param>
        /// <returns></returns>
		//被我改了，input.Length <= 2改为input.Length <= 1
        public static double[] Deextend(double[] input, int size)
        {
            if (input.Length <= 1)
            {
                return input;
            }
            var padding = (input.Length - size)/2;
            var result = MemoryPool.Pool.New<double>(size);
            Array.Copy(input, padding, result, 0, size);
            return result;
        }

        private static double[] GetAntisymmetricWholePointBefore(IList<double> points, int beforeSize)
        {
            var beforeExtension = MemoryPool.Pool.New<double>(beforeSize);
            if (points.Count == 1)
            {
                for (var i = 0; i < beforeSize; i++)
                {
                    beforeExtension[i] = points[0] * -1;    
                }
                return beforeExtension;
            }
            var k = beforeSize - 1;
            for (var i = 0; i < beforeSize; i++)
            {
                var dif = (i + 1 < points.Count) ? points[i] - points[i + 1] : 0;
                var previous = i == 0 ? points[0] : beforeExtension[k + 1];
                beforeExtension[k] = previous + dif;
                k--;
            }
            return beforeExtension;
        }

        private static double[] GetAntisymmetricWholePointAfter(IList<double> points, int afterSize)
        {
            var afterExtension = MemoryPool.Pool.New<double>(afterSize);
            if (points.Count == 1)
            {
                for (var i = 0; i < afterSize; i++)
                {
                    afterExtension[i] = points[0] * -1;
                }
                return afterExtension;
            }
            var k = 0;
            for (var i = points.Count - 1; i >= points.Count - afterSize; i--)
            {
                var dif = i >= 1 ? points[i] - points[i - 1] : 0;
                var previous = k == 0 ? points[i] : afterExtension[k - 1];
                afterExtension[k] = previous + dif;
                k++;
            }
            return afterExtension;
        }

        /// <summary>
        /// Gets the next power of 2 of an number
        /// </summary>
        /// <param name="number"></param>
        /// <returns></returns>
        public static int NextPowerOf2(int number)
        {            
            number = (number >> 1) | number;
            number = (number >> 2) | number;
            number = (number >> 4) | number;
            number = (number >> 8) | number;
            number = (number >> 16) | number;
            number++;
            return number;
        }        
    }
}
