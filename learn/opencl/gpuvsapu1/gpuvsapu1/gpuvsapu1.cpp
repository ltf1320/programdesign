// gpuvsapu1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

const int nSupp = 1;//选定小波系数的类型和数值

const double hCoef[10][20] =
{
	{0.707106781187,  0.707106781187},

	{ .482962913145,  .836516303738,  .224143868042, -.129409522551 },

	//coif1小波系数
	{ -0.0157   ,-0.0727    ,0.3849    ,0.8526    ,0.3379   ,-0.0727 },

	//sym4 小波系数
	{ -0.0758  ,-0.0296  ,0.4976  ,0.8037  ,0.2979  ,-0.0992  ,-0.0126  ,0.0322 },

	{ .332670552950,  .806891509311,  .459877502118, -.135011020010, -.085441273882,  .035226291882 },

	{ .230377813309,  .714846570553,  .630880767930, -.027983769417,
	-.187034811719,  .030841381836,  .032883011667, -.010597401785 },	

	{ .077852054085,  .396539319482,  .729132090846,  .469782287405, -.143906003929,
	-.224036184994,  .071309219267,  .080612609151, -.038029936935, -.016574541631,
	.012550998556,  .000429577973, -.001801640704,  .000353713800 },

	{ .054415842243,  .312871590914,  .675630736297,  .585354683654, -.015829105256,
	-.284015542962,  .000472484574,  .128747426620, -.017369301002, -.044088253931,
	.013981027917,  .008746094047, -.004870352993, -.000391740373,  .000675449406,
	-.000117476784 },

	{ .038077947364,  .243834674613,  .604823123690,  .657288078051,  .133197385825,
	-.293273783279, -.096840783223,  .148540749338,  .030725681479, -.067632829061,
	.000250947115,  .022361662124, -.004723204758, -.004281503682,  .001847646883,
	.000230385764, -.000251963189,  .000039347320 },

	{ .026670057901,  .188176800078,  .527201188932,  .688459039454,  .281172343661,
	-.249846424327, -.195946274377,  .127369340336,  .093057364604, -.071394147166,
	-.029457536822,  .033212674059,  .003606553567, -.010733175483,  .001395351747,
	.001992405295, -.000685856695, -.000116466855,  .000093588670, -.000013264203 }
};

double LC(double x)
{
	if (x>=255)
	{
		return 255; 
	}
	else
	{
		if (x<0)
		{
			return 0;
		}
		else
			return (x+0.5);
	}
}

const int testgroup = 50;
const int row=testgroup*100;
const int col=testgroup*100;

int _tmain(int argc, _TCHAR* argv[])
{
	
	double cImage[row*col];
	double vImage[col*row];
	for(int i=0;i<row*col;i++)
	{
		cImage[i]=(rand()%255)/255.0;
		vImage[i]=cImage[1];
	}
	double* h = (double *)hCoef[nSupp-1];//选定小波系数
	const double s = (double)(sqrt((double)2));
	double* temp = 0;
	////////////////////////////////以下进行DWT//////////////////////////////////////////
	int vCPU=clock();
	///////////////////////////////行DWT/////////////////////////////////////////////
	for (int hei = 0; hei<row; hei++)
	{
		int index1 = 0;
		int index2 = 2*nSupp -1;
		temp = &cImage[hei*row];
		int step = col/2;
		double* temp2 = new double[step];//用于暂存高频分量

		for (int i = 0;i<step;i++)
		{
			double s1 = 0;//低频系数
			double s2 = 0;//高频系数
			double t = -1;
			for (int j = 0; j<2*nSupp; j++, t=-t)
			{
                index1 = index1 < 0 ? (2*step + index1) : index1;
				index1 = index1 > (2*step - 1) ? (index1-2*step) : index1;
				index2 = index2 > (2*step - 1) ? (index2 - 2*step) : index2;
				index2 = index2 < 0 ? (2*step + index2) : index2;

				s1 += h[j] * temp[index1];
				s2 += t * h[j] * temp[index2];

				index1++;
				index2--;
			}
			temp[i] = s1/s;//低频分量回归原图

			temp2[i] = s2/s;//高频分量暂存

			index1 -= 2*nSupp;
			index2 += 2*nSupp;
			index1 += 2;//完成步长为2的下采样
			index2 += 2;
		}
		for (int k = 0;k<step;k++)//高频分量回归原图
		{
			temp[k+step] = temp2[k];
		}
		delete []temp2;
	}

	//矩阵转置
	double x=0;
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			x=cImage[i*row+j];
			cImage[i*row+j]=cImage[j*col+i];
			cImage[j*col+i]=x;
		}
	}

	/////////////////////////////列DWT/////////////////////////////////////////////
	for (int hei = 0; hei<col; hei++)
	{
		int index1 = 0;
		int index2 = 2*nSupp -1;
		temp = &cImage[hei*col];
		int step = row/2;
		double* temp2 = new double[step];//用于暂存高频分量

		for (int i = 0;i<step;i++)
		{
			double s1 = 0;//低频系数
			double s2 = 0;//高频系数
			double t = -1;
			for (int j = 0; j<2*nSupp; j++, t=-t)
			{
                index1 = index1 < 0 ? (2*step + index1) : index1;
				index1 = index1 > (2*step - 1) ? (index1-2*step) : index1;
				index2 = index2 > (2*step - 1) ? (index2 - 2*step) : index2;
				index2 = index2 < 0 ? (2*step + index2) : index2;

				s1 += h[j] * temp[index1];
				s2 += t * h[j] * temp[index2];

				index1++;
				index2--;
			}
			temp[i] = s1/s;//低频分量回归原图

			temp2[i] = s2/s;//高频分量暂存

			index1 -= 2*nSupp;
			index2 += 2*nSupp;
			index1 += 2;//完成步长为2的下采样
			index2 += 2;
		}
		for (int k = 0;k<step;k++)//高频分量回归原图
		{
			temp[k+step] = temp2[k];
		}
		delete []temp2;
	}

	for(int i=0;i<col;i++)
	{
		for(int j=0;j<row;j++)
		{
			x=cImage[i*col+j];
			cImage[i*col+j]=cImage[j*row+i];
			cImage[j*row+i]=x;
		}
	}

	int CurN = col/2;
	for (int hei = 0; hei <row; hei++)
	{
		int index1 = CurN / 2;
		int index2 = CurN / 2 - nSupp +1;

		int step = CurN / 2;

		temp = &cImage[hei*row];
		double* temp2 = new double[CurN];//暂存一维数据

		for (int l = 0;l<CurN;l++)//提取某一行的数据
		{
			temp2[l] = temp[l];
		}

		for (int i = 0; i<step; i++)
		{
			int index3 = 0;

			double s1=0, s2=0;

			for (int j=0; j<nSupp; j++)
			{
				index1 = index1 < 0 ? (CurN/2 + index1) : index1;
				index1 = index1 > (CurN/2 - 1) ? (index1-CurN/2) : index1;
				index2 = index2 > (CurN/2 - 1) ? (index2 - CurN/2) : index2;
				index2 = index2 < 0 ? (CurN/2 + index2) : index2;

				s1 += h[index3] * temp2[index1] + h[index3+1] * temp2[index2+ CurN/2];
				s2 += h[index3+1] * temp2[index1] - h[index3] * temp2[index2+ CurN/2];

				index3 += 2;
				index1--;
				index2++;
			}
			temp[2*i] = s1*s;
			temp[2*i+1] = s2*s;

			index1 += nSupp;
			index2 -= nSupp;
			index1++;
			index2++;
		}
		delete []temp2;
	}

	//矩阵转置
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			x=cImage[i*row+j];
			cImage[i*row+j]=cImage[j*col+i];
			cImage[j*col+i]=x;
		}
	}

	//////////////////////////列IDWT//////////////////////////////////////////////////
	CurN = row;//反变换后图像的长度
	for (int hei = 0; hei <col; hei++)
	{
		int index1 = CurN / 2;
		int index2 = CurN / 2 - nSupp +1;

		int step = CurN / 2;

		temp = &cImage[hei*col];
		double* temp2 = new double[CurN];//暂存一维数据

		for (int l = 0;l<CurN;l++)//提取某一行的数据
		{
			temp2[l] = temp[l];
		}

		for (int i = 0; i<step; i++)
		{
			int index3 = 0;

			double s1=0, s2=0;

			for (int j=0; j<nSupp; j++)
			{
				index1 = index1 < 0 ? (CurN/2 + index1) : index1;
				index1 = index1 > (CurN/2 - 1) ? (index1-CurN/2) : index1;
				index2 = index2 > (CurN/2 - 1) ? (index2 - CurN/2) : index2;
				index2 = index2 < 0 ? (CurN/2 + index2) : index2;

				s1 += h[index3] * temp2[index1] + h[index3+1] * temp2[index2+ CurN/2];
				s2 += h[index3+1] * temp2[index1] - h[index3] * temp2[index2+ CurN/2];

				index3 += 2;
				index1--;
				index2++;
			}
			temp[2*i] = s1*s;
			temp[2*i+1] = s2*s;

			index1 += nSupp;
			index2 -= nSupp;
			index1++;
			index2++;
		}
		delete []temp2;
	}

	for(int i=0;i<col;i++)
	{
		for(int j=0;j<row;j++)
		{
			x=cImage[i*col+j];
			cImage[i*col+j]=cImage[j*row+i];
			cImage[j*row+i]=x;
		}
	}
	printf("CPU:%dms",clock()-vCPU);
	system("pause");
	return 0;
}


