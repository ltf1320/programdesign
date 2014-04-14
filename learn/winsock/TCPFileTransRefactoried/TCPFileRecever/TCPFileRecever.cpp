// TCPFileRecever.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#define FILENAME_SIZE 100
#define BUF_SIZE 1024
#define TERROR -1

using namespace std;

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
		}
		else
		{
			cout << WSAGetLastError() << endl;
			WSACleanup();
			return TERROR;
		}
	}
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

int initSock(SOCKET *sock, int AF, int sockType, int protocol)
{
	*sock = socket(AF, sockType, 0);
	if (*sock == INVALID_SOCKET)
	{
		cerr << "sock init error" << endl;
		return TERROR;
	}
	return 0;
}

sockaddr_in initAddr_in(int AF, const char* ip, int port)
{
	sockaddr_in addr;
	addr.sin_family = AF;
	addr.sin_addr.s_addr = inet_addr(ip);
	addr.sin_port = htons(port);
	return addr;
}

int recvBuf(SOCKET sock, char* buf, int len, int flag)
{
	int tmp;
	if ((tmp=recv(sock, buf, len, flag)) == SOCKET_ERROR)
	{
		cerr << "receive error" << endl;
		WSACleanup();
		return TERROR;
	}
	char bb;
	if (send(sock, &bb, 1, flag) == SOCKET_ERROR)
	{
		cerr << "receive error" << endl;
		system("pause");
		WSACleanup();
		return TERROR;
	}
	return tmp;
}

void getFileName(const char *filePath, char* fileName)
{
	int len = strlen(filePath);
	int nlen = len;
	while (filePath[len - 1] != '\\')
	{
		nlen--;
	}
	strcpy_s(fileName, len, filePath + nlen);
}

int _tmain(int argc, _TCHAR* argv[])
{
	SOCKET sock;
	WSAData wsaData;
	initWSA(wsaData);
	initSock(&sock, AF_INET, SOCK_STREAM, 0);

	sockaddr_in addr = initAddr_in(AF_INET, "192.168.1.5", 7777);
	cout << "connecting" << endl;
	if (connect(sock, (sockaddr*)&addr, sizeof(addr)) == SOCKET_ERROR)
	{
		cerr << "connect failed" << endl;
		system("pause");
		return -1;
	}
	cout << "connected" << endl;
	cout << "getting file name & Size" << endl;
	char fileName[FILENAME_SIZE];
	if (recvBuf(sock, fileName, FILENAME_SIZE, 0) <=0)
	{
		cerr << "get file name failed" << endl;
		system("pause");
		return -1;
	}
	cout << "fileName::" << fileName << endl;

	FILE* fp=NULL;
	char filePath[FILENAME_SIZE] = "E:\\ltf\\recv\\";
	strcat_s(filePath, FILENAME_SIZE, fileName);
	if (fopen_s(&fp, filePath, "wb")!=0)
	{
		cerr << "create file error" << endl;
		system("pause");
		return - 1;
	}

	char buf[BUF_SIZE];
	int fileSize;
	if (recvBuf(sock, buf, FILENAME_SIZE, 0) == TERROR)
	{
		cerr << "get fileSize error" << endl;
		system("pause");
		return -1;
	}
	sscanf_s(buf, "%d", &fileSize);
	cout << "fileSize::" << fileSize << endl;
	cout << "receive file started" << endl;
	int tn = fileSize / BUF_SIZE, last = fileSize%BUF_SIZE;
	int tmp;
	cout << filePath << endl;
	int startTime = clock();
	printf("%%00");
	for (int i = 0; i < tn; i++)
	{
		if ((tmp=recvBuf(sock, buf, BUF_SIZE, 0))!=BUF_SIZE)
		{
			cerr << "receive error:not enough" << endl;
			system("pause");
			return -1;
		}
		fwrite(buf, 1, BUF_SIZE, fp);
		printf("\b\b%02d", i*100 / (tn + 1));
	}
	if (recvBuf(sock, buf, last, 0) != last)
	{
		cerr << "receive error" << endl;
		system("pause");
		return -1;
	}
	printf("\b\b%100\n");
	double costTime = (clock() - startTime) / CLOCKS_PER_SEC;

	fwrite(buf, 1, last, fp);
	cout << "receive file succeeded" << endl;
	printf("cost time:%.2fs\n", costTime);
	printf("speed: %.0fKB/s", 1.0*fileSize / 1024 / costTime);
	system("pause");
	return 0;
}

