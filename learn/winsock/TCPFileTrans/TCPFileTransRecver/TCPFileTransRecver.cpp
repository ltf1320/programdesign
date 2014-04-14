// TCPFileTransRecver.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
using namespace std;
#define BUF_SIZE 256

int _tmain(int argc, _TCHAR* argv[])
{
	SOCKET sock;
	WSAData wsaData;
	if (WSAStartup(MAKEWORD(2, 0), &wsaData) == SOCKET_ERROR)
	{
		cerr << "socket init failed" << endl;
		system("pause");
		return -1;
	}
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == INVALID_SOCKET)
	{
		cerr << "create sock failed" << endl;
		WSACleanup();
		system("pause");
		return -1;
	}

	sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr("192.168.1.5");
	addr.sin_port = htons(7777);

	cout << "connecting" << endl;
	if (connect(sock, (sockaddr*)&addr, sizeof(addr)) == SOCKET_ERROR)
	{
		cerr << "connect failed" << endl;
		WSACleanup();
		system("pause");
		return -1;
	}

	cout << "connect succeeded" << endl;
	char fileName[100];
	int tmp = recv(sock, fileName, 100, 0);
	if (tmp < 0)
	{
		cerr << "receive error" << endl;
		WSACleanup();
		system("pause");
		return -1;
	}
	FILE *fp;
	char filePath[120] = "E:\\ltf\\recv\\";
	strcpy_s(filePath + 12, 100, fileName);
	if (send(sock, filePath, 1, 0) == SOCKET_ERROR)
	{
		cerr << "trans start error" << endl;
		system("pause");
		WSACleanup();
		return -1;
	}
	char buf[BUF_SIZE];

	if (recv(sock, buf, BUF_SIZE, 0) == SOCKET_ERROR)
	{
		cerr << "trans start error" << endl;
		system("pause");
		WSACleanup();
		return -1;
	}
	if (send(sock, buf, 1, 0) == SOCKET_ERROR)
	{
		cerr << "trans start error" << endl;
		system("pause");
		WSACleanup();
		return -1;
	}
	int fileSize;
	sscanf_s(buf, "%d", &fileSize);
	cout << "fileSize::"<<fileSize << endl;
	int gnum = fileSize / BUF_SIZE, md = fileSize%BUF_SIZE;
	int err = fopen_s(&fp, filePath, "wb");
	if (err == -1)
	{
		cerr << "file open error" << endl;
		system("pasue");
		WSACleanup();
		return -1;
	}
	cout << "file trans started:" << fileName << endl;
	int num = 0;
	for (int i = 0; i < gnum;i++)
	{
		tmp = recv(sock, buf, BUF_SIZE, 0);
		if (tmp <= 0)
		{
			cerr << "receive error" << endl;
			fclose(fp);
			WSACleanup();
			system("pause");
			return -1;
		}
		fwrite(buf,1,BUF_SIZE, fp);
		tmp = send(sock, buf, 1, 0);
		if (tmp < 0)
		{
			cerr << "receive error" << endl;
			fclose(fp);
			WSACleanup();
			system("pause");
			return -1;
		}
	}
	tmp = recv(sock, buf, md, 0);
	if (tmp <= 0)
	{
		cerr << "receive error" << endl;
		fclose(fp);
		WSACleanup();
		system("pause");
		return -1;
	}
	cout << ++num << " received" << endl;
	fwrite(buf, 1, md, fp);
	fclose(fp);
	closesocket(sock);
	WSACleanup();
	system("pause");
	cout << "git" << endl;
	return 0;
}

