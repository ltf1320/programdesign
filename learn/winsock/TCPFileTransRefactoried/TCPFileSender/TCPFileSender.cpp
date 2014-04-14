// TCPFileSender.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
using namespace std;

#define FILENAME_SIZE 100
#define BUF_SIZE 1024
#define TERROR -1

int GetHostAndIp(char* name, int len, char ** ipAddress)
{
	char szPath[128] = "";
	WSADATA wsaData;
	PHOSTENT hostinfo;
	if (WSAStartup(MAKEWORD(2, 0), &wsaData) == 0) {
		if ((gethostname(szPath, sizeof(szPath))) == 0) {
			if ((hostinfo = gethostbyname(szPath)) != NULL) {
				*ipAddress = inet_ntoa(*(struct in_addr *)*hostinfo->h_addr_list);
			}
			else return TERROR;
		}
		else
		{
			cout << WSAGetLastError() << endl;
			WSACleanup();
			return TERROR;
		}
	}
	else return TERROR;
	strcpy_s(name, len, szPath);
	return 0;
}
int initWSA(WSADATA &wsaData)
{
	if (WSAStartup(MAKEWORD(2, 0), &wsaData) == SOCKET_ERROR)
	{
		cerr << "socket init error" << endl;
		return TERROR;
	}
	return 0;
}

int initSock(SOCKET *sock,int AF,int sockType,int protocol)
{
	*sock = socket(AF,sockType, 0);
	if (*sock == INVALID_SOCKET)
	{
		cerr << "sock init error" << endl;
		return TERROR;
	}
	return 0;
}

sockaddr_in initAddr_in(int AF,const char* ip,int port)
{
	sockaddr_in addr;
	addr.sin_family = AF;
	addr.sin_addr.s_addr = inet_addr(ip);
	addr.sin_port = htons(port);
	return addr;
}

sockaddr_in initAddr_in(int AF, ULONG ip, int port)
{
	sockaddr_in addr;
	addr.sin_family = AF;
	addr.sin_addr.s_addr = ip;
	addr.sin_port = htons(port);
	return addr;
}

int sendBuf(SOCKET sock, char* buf, int len,int flag)
{
	if (send(sock, buf, len, flag) == SOCKET_ERROR)
	{
		cerr << "send error" << endl;
		WSACleanup();
		return TERROR;
	}
	char bb;
	if (recv(sock, &bb, 1, flag) == SOCKET_ERROR)
	{
		cerr << "send error" << endl;
		WSACleanup();
		return TERROR;
	}
	return 0;
}

void getFileName(const char *filePath,char* fileName)
{
	int len = strlen(filePath);
	int nlen = len;
	while (filePath[nlen - 1] != '\\')
	{
		nlen--;
	}
	strcpy_s(fileName, len, filePath + nlen);
}

int _tmain(int argc, _TCHAR* argv[])
{
	WSADATA wsaData;
	if (initWSA(wsaData) == TERROR)
		return -1;
	SOCKET lsock, dsock;
	if (initSock(&lsock,AF_INET,SOCK_STREAM,0) == TERROR)
		return -1;
	char *localIp, localName[50];
	if (GetHostAndIp(localName, 50, &localIp) == TERROR)
	{
		cerr << "get local ip failed" << endl;
		system("pause");
		return -1;
	}

	sockaddr_in laddr, daddr;
	laddr = initAddr_in(AF_INET, localIp, 7777);
	daddr = initAddr_in(AF_INET, INADDR_ANY,7777);
	bind(lsock, (sockaddr*)&laddr, sizeof(laddr));
	cout << "listening" << endl;
	if (listen(lsock, 5) == SOCKET_ERROR)
	{
		cout << "listen error" << endl;
		cout << WSAGetLastError() << endl;
		system("pause");
		return -1;
	}


	dsock = accept(lsock, (sockaddr*)&daddr,NULL);
	if (dsock == INVALID_SOCKET)
	{
		cout << "accept error" << endl;
		return -1;
	}
	cout << "connect succeeded" << endl;

	char filePath[FILENAME_SIZE] = "F:\\1.bmp";
	char fileName[FILENAME_SIZE];
	getFileName(filePath, fileName);
	FILE* fp;
	int err = fopen_s(&fp, filePath, "rb");
	if (err !=0)
	{
		cerr << "open file error" << endl;
		system("pause");
		return -1;
	}
	
	if (sendBuf(dsock, fileName, FILENAME_SIZE, 0) == TERROR)
	{
		cerr << "sending file name error" << endl;
		system("pause");
		return -1;
	}
	int fileSize = _filelength(_fileno(fp));
	char buf[BUF_SIZE];
	sprintf_s(buf, "%d", fileSize);
	if (sendBuf(dsock, buf, FILENAME_SIZE, 0) == TERROR)
	{
		cerr << "sending file size error" << endl;
		system("pause");
		return -1;
	}
	int tn = fileSize / BUF_SIZE,last=fileSize%BUF_SIZE;
	cout << "file transfer started" << endl;
	printf("%%00");
	int startTime = clock();
	for (int i = 0; i < tn; i++)
	{
		if (fread(buf, 1, BUF_SIZE, fp) != BUF_SIZE)
		{
			cerr << "file read error" << endl;
			return -1;
		}
		if (sendBuf(dsock, buf, BUF_SIZE, 0) == TERROR)
		{
			cerr << "file transfer error" << endl;
			return -1;
		}
		printf("\b\b%02d", i*100 / (tn + 1));
	}
	if (fread(buf, 1, last, fp) != last)
	{
		cerr << "file read error" << endl;
		return -1;
	}
	if (sendBuf(dsock, buf, last, 0) == TERROR)
	{
		cerr << "file transfer error" << endl;
		return -1;
	}
	printf("\b\b100\n");
	double costTime = (clock() - startTime)/CLOCKS_PER_SEC;

	cout << "file send succeeded" << endl;
	printf("cost time:%.2fs\n", costTime);
	printf("speed: %.0fKB/s", 1.0*fileSize / 1024 / costTime);
	system("pause");
	return 0;
}

