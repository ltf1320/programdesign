// GetLocalIp.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

using namespace std;

//获得本机主机名和IP地址
int GetHostAndIp( char* name,int len, char ** ipAddress)
{
	char szPath[128] = "";
	WSADATA wsaData;
	PHOSTENT hostinfo;
	//调用MAKEWORD（）获得Winsock版本的正确值，用于加载Winsock库 
	if (WSAStartup(MAKEWORD(2,0), &wsaData) == 0) {
		//现在是加载Winsock库，如果WSAStartup（）函数返回值为0，说明加载成功，程序可以继续 
		if ((gethostname(szPath, sizeof(szPath))) == 0) {
			
			//如果成功地将本地主机名存放入由name参数指定的缓冲区中 
			if ((hostinfo = gethostbyname(name)) != NULL) {
				//这是获取主机名，如果获得主机名成功的话，将返回一个指针，指向hostinfo，hostinfo 
				//为PHOSTENT型的变量，下面即将用到这个结构体 
				*ipAddress = inet_ntoa(*(struct in_addr *)*hostinfo->h_addr_list);
				//调用inet_ntoa（）函数，将hostinfo结构变量中的h_addr_list转化为标准的点分表示的IP 
				//地址（如192.168.0.1） 
				// printf("%s\n",ip);//输出IP地址
			}
		}
		else
		{
			cout << WSAGetLastError() << endl;
			system("pause");
			delete name;
			name = NULL;
		}
		WSACleanup();                     //卸载Winsock库，并释放所有资源 
	}

	strcpy_s(name, len, szPath);
	return 0;
}


int _tmain(int argc, _TCHAR* argv[])
{
	char host[200]="", *ip;
	GetHostAndIp(host,200, &ip);
	cout << host << endl;
	cout << ip << endl;
	system("pause");
	return 0;
}

