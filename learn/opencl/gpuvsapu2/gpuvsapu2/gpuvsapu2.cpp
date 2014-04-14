// gpuvsapu1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <amp.h>
using namespace concurrency;
const int nSupp = 1;//选定小波系数的类型和数值

float LC(float x)
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

bool pick_accelerator()
{
    std::vector<accelerator> accs = accelerator::get_all();
    accelerator chosen_one;

    auto result = 
        std::find_if(accs.begin(), accs.end(), [] (const accelerator& acc)
    {
        return !acc.is_emulated && 
            acc.supports_double_precision && 
            !acc.has_display;
    });

    if (result != accs.end())
        chosen_one = *(result);

    std::wcout << chosen_one.description << std::endl;

    bool success = accelerator::set_default(chosen_one.device_path);
    return success;
}

const int testgroup = 20;
const int row=testgroup*100;
const int col=testgroup*100;

int _tmain(int argc, _TCHAR* argv[])
{
	float hCoef[200] =
	{
		0.707106781187,  0.707106781187 ,

		 .482962913145,  .836516303738,  .224143868042, -.129409522551  ,

		//coif1小波系数
		  -0.0157   ,-0.0727    ,0.3849    ,0.8526    ,0.3379   ,-0.0727  ,

		//sym4 小波系数
		  -0.0758  ,-0.0296  ,0.4976  ,0.8037  ,0.2979  ,-0.0992  ,-0.0126  ,0.0322  ,

		  .332670552950,  .806891509311,  .459877502118, -.135011020010, -.085441273882,  .035226291882  ,

		  .230377813309,  .714846570553,  .630880767930, -.027983769417,
		-.187034811719,  .030841381836,  .032883011667, -.010597401785  ,	

		  .077852054085,  .396539319482,  .729132090846,  .469782287405, -.143906003929,
		-.224036184994,  .071309219267,  .080612609151, -.038029936935, -.016574541631,
		.012550998556,  .000429577973, -.001801640704,  .000353713800  ,

		  .054415842243,  .312871590914,  .675630736297,  .585354683654, -.015829105256,
		-.284015542962,  .000472484574,  .128747426620, -.017369301002, -.044088253931,
		.013981027917,  .008746094047, -.004870352993, -.000391740373,  .000675449406,
		-.000117476784  ,

		  .038077947364,  .243834674613,  .604823123690,  .657288078051,  .133197385825,
		-.293273783279, -.096840783223,  .148540749338,  .030725681479, -.067632829061,
		.000250947115,  .022361662124, -.004723204758, -.004281503682,  .001847646883,
		.000230385764, -.000251963189,  .000039347320  ,

		  .026670057901,  .188176800078,  .527201188932,  .688459039454,  .281172343661,
		-.249846424327, -.195946274377,  .127369340336,  .093057364604, -.071394147166,
		-.029457536822,  .033212674059,  .003606553567, -.010733175483,  .001395351747,
		.001992405295, -.000685856695, -.000116466855,  .000093588670, -.000013264203  
	};
	float cImage[row*col];
	for(int i=0;i<row*col;i++)
	{
		cImage[i]=(rand()%255)/255.0;
	}
	//float* h = (float *)hCoef[nSupp-1];//选定小波系数
	const float s = (float)(sqrt((float)2));
	float t5[col];
	////////////////////////////////以下进行DWT//////////////////////////////////////////
	int vT=clock();

	try{
	pick_accelerator();
	///////////////////////////////行DWT/////////////////////////////////////////////
	array<int,1> para(1000);
	array_view<float,1> vImage(row*col,cImage);
	array_view<float,1> h(200,hCoef);
	array_view<float,1>temp(col,t5);
	parallel_for_each(para.extent, 
        [=](index<1> hei) restrict(amp)
	{
		int index1 = 0;
		int index2 = 2*nSupp -1;
		const int step = col/2;

		for (int i = 0;i<step;i++)
		{
			float s1 = 0;//低频系数
			float s2 = 0;//高频系数
			float t = -1;
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

			temp[i+step] = s2/s;//高频分量暂存

			index1 -= 2*nSupp;
			index2 += 2*nSupp;
			index1 += 2;//完成步长为2的下采样
			index2 += 2;
		}
		for (int i = 0;i<2*step;i++)//高频分量回归原图
		{
			vImage[i+hei[0]*row] = temp[i];
		}
	});
	//矩阵转置
	parallel_for_each(para.extent, 
        [=](index<1> hei) restrict(amp)
	{
		float x=0;
		int i=hei[0];
		for(int j=i+1;j<col;j++)
		{
			x=vImage[i*row+j];
			vImage[i*row+j]=vImage[j*col+i];
			vImage[j*col+i]=x;
		}
	});

	/////////////////////////////列DWT/////////////////////////////////////////////
	parallel_for_each(para.extent, 
        [=](index<1> hei) restrict(amp)
	{
		int index1 = 0;
		int index2 = 2*nSupp -1;
		const int step = row/2;
		
		for (int i = 0;i<step;i++)
		{
			float s1 = 0;//低频系数
			float s2 = 0;//高频系数
			float t = -1;
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

			temp[i+step] = s2/s;//高频分量暂存

			index1 -= 2*nSupp;
			index2 += 2*nSupp;
			index1 += 2;//完成步长为2的下采样
			index2 += 2;
		}
		for (int i = 0;i<2*step;i++)//高频分量回归原图
		{
			vImage[i+hei[0]*row] = temp[i];
		}
	});

	parallel_for_each(para.extent, 
        [=](index<1> hei) restrict(amp)
	{
		float x=0;
		int i=hei[0];
		for(int j=i;j<row;j++)
		{
			x=vImage[i*col+j];
			vImage[i*col+j]=vImage[j*row+i];
			vImage[j*row+i]=x;
		}
	});

	const int CurN = col;
	parallel_for_each(para.extent, 
        [=](index<1> hei) restrict(amp)
	{
		int index1 = CurN / 2;
		int index2 = CurN / 2 - nSupp +1;

		int step = CurN / 2;

		for (int l = 0;l<CurN;l++)//提取某一行的数据
		{
			temp[l] = vImage[l+hei[0]*row];
		}

		for (int i = 0; i<step; i++)
		{
			int index3 = 0;

			float s1=0, s2=0;

			for (int j=0; j<nSupp; j++)
			{
				index1 = index1 < 0 ? (CurN/2 + index1) : index1;
				index1 = index1 > (CurN/2 - 1) ? (index1-CurN/2) : index1;
				index2 = index2 > (CurN/2 - 1) ? (index2 - CurN/2) : index2;
				index2 = index2 < 0 ? (CurN/2 + index2) : index2;

				s1 += h[index3] * temp[index1] + h[index3+1] * temp[index2+ CurN/2];
				s2 += h[index3+1] * temp[index1] - h[index3] * temp[index2+ CurN/2];

				index3 += 2;
				index1--;
				index2++;
			}
			vImage[2*i] = s1*s;
			vImage[2*i+1] = s2*s;

			index1 += nSupp;
			index2 -= nSupp;
			index1++;
			index2++;
		}
	});

	//矩阵转置
	parallel_for_each(para.extent, 
        [=](index<1> hei) restrict(amp)
	{
		float x=0;
		int i=hei[0];
		for(int j=0;j<col;j++)
		{
			x=vImage[i*row+j];
			vImage[i*row+j]=vImage[j*col+i];
			vImage[j*col+i]=x;
		}
	});

	//////////////////////////列IDWT//////////////////////////////////////////////////
	//反变换后图像的长度
	parallel_for_each(para.extent, 
        [=](index<1> hei) restrict(amp)
	{
		int index1 = CurN / 2;
		int index2 = CurN / 2 - nSupp +1;

		int step = CurN / 2;


		for (int l = 0;l<CurN;l++)//提取某一行的数据
		{
			temp[l] = vImage[l+hei[0]*col];
		}

		for (int i = 0; i<step; i++)
		{
			int index3 = 0;

			float s1=0, s2=0;

			for (int j=0; j<nSupp; j++)
			{
				index1 = index1 < 0 ? (CurN/2 + index1) : index1;
				index1 = index1 > (CurN/2 - 1) ? (index1-CurN/2) : index1;
				index2 = index2 > (CurN/2 - 1) ? (index2 - CurN/2) : index2;
				index2 = index2 < 0 ? (CurN/2 + index2) : index2;

				s1 += h[index3] * temp[index1] + h[index3+1] * temp[index2+ CurN/2];
				s2 += h[index3+1] * temp[index1] - h[index3] * temp[index2+ CurN/2];

				index3 += 2;
				index1--;
				index2++;
			}
			vImage[2*i] = s1*s;
			vImage[2*i+1] = s2*s;

			index1 += nSupp;
			index2 -= nSupp;
			index1++;
			index2++;
		}
	});

	parallel_for_each(para.extent, 
        [=](index<1> hei) restrict(amp)
	{
		float x=0;
		int i=hei[0];
		for(int j=0;j<row;j++)
		{
			x=vImage[i*col+j];
			vImage[i*col+j]=vImage[j*row+i];
			vImage[j*row+i]=x;
		}
	});
	}
	catch(std::exception & e)
	{
		printf("%s",e.what());
	}
	printf("GPU:%dms",clock()-vT);
	system("pause");
	return 0;
}


