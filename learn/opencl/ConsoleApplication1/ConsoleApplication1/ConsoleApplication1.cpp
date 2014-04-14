// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

__kernel  void image_rotate(
	__global uchar * src_data,
	__global uchar * dest_data,        //Data in global memory
	int W, int H,                   //Image Dimensions
	float sinTheta, float cosTheta)   //Rotation Parameters
{
	const int ix = get_global_id(0);
	const int iy = get_global_id(1);
	int xc = W / 2;
	int yc = H / 2;
	int xpos = (ix - xc)*cosTheta - (iy - yc)*sinTheta + xc;
	int ypos = (ix - xc)*sinTheta + (iy - yc)*cosTheta + yc;
	if ((xpos >= 0) && (xpos< W) && (ypos >= 0) && (ypos< H))
		dest_data[ypos*W + xpos] = src_data[iy*W + ix];
}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

