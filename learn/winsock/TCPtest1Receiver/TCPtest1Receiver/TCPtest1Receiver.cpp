// TCPtest1Receiver.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	SOCKET sock;
	WORD Sver = MAKEWORD(2, 0);
	WSADATA wsaData;
	int err = WSAStartup(Sver, &wsaData);
	if (err)
	{
		cout << "Socket init failed" << endl;
		return -1;
	}
	if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 0)
	{
		WSACleanup();
		return -1;
	}
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == INVALID_SOCKET)
	{
		cout << "socket create failed" << endl;
	}
	sockaddr_in myaddr;
	memset(&myaddr, 0, sizeof(myaddr));
	myaddr.sin_family = AF_INET;
	myaddr.sin_addr.s_addr = inet_addr("192.168.1.5");
	myaddr.sin_port = htons(7777);
	cout << "connecting" << endl;
	if (connect(sock, (sockaddr*)&myaddr, sizeof(myaddr)) == SOCKET_ERROR)
	{
		cout << "error:" << WSAGetLastError() << endl;
		cout << "just here" << endl;
		closesocket(sock);
		WSACleanup();
		return 1;
	}
	else
		cout << "connect succeeded!" << endl;
	char buf[256];
	long number = 0;
	int iResult = 0;
	while (true)
	{
		memset(buf, 0, sizeof(buf));
		number++;
		iResult = recv(sock, buf, sizeof(buf), 0);
		if (iResult < 0)
		{
			cout << "sender sock closed" << endl;
			break;
		}
		cout << number << ":" << buf << endl;
		Sleep(1000);
	}
	if (!closesocket(sock))
	{
		WSAGetLastError();
		return -1;
	}
	if (!WSACleanup())
	{
		WSAGetLastError();
		return -1;
	}
	return 0;
}

