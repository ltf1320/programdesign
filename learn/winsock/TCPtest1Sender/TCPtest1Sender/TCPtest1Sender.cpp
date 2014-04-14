// TCPtest1Sender.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	SOCKET sock,clientSock;
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
	bind(sock, (sockaddr*)&myaddr, sizeof(myaddr));

	sockaddr_in desaddr;
	memset(&desaddr, 0, sizeof(desaddr));
	desaddr.sin_family = AF_INET;
	desaddr.sin_addr.s_addr = inet_addr("192.168.1.7");
	desaddr.sin_port = htons(7777);

	if (listen(sock,5) == SOCKET_ERROR)
	{
		closesocket(sock);
		WSACleanup();
		abort();
	}
	else
		cout << "listen succeeded!" << endl;

	int nlen = sizeof(desaddr);
	clientSock = accept(sock, (sockaddr*)&desaddr, &nlen);
	if (clientSock < 0)
	{
		cout << "client sock error!" << endl;
		abort();
	}
	else
		cout << "accept succeeded!" << endl;
	UINT uIndex = 1;
	char szMsg[] = "Hello";
	while (true)
	{
		Sleep(1000);
		if (send(clientSock, szMsg, sizeof(szMsg), 0) == SOCKET_ERROR)
		{
			cout << "error:" << WSAGetLastError() << endl;
			break;
		}
		else
			cout << "sended" << endl;
	}
	if (!closesocket(sock))
	{
		cout << WSAGetLastError() << endl;
		return -1;
	}
	if (!closesocket(clientSock))
	{
		cout << WSAGetLastError() << endl;
		return -1;
	}
	if (!WSACleanup())
	{
		WSAGetLastError();
		return -1;
	}
	return 0;
}

