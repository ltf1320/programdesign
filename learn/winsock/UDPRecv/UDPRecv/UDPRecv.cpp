// UDPRecv.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	SOCKET sock;
	WORD wVer=MAKEWORD(2,0);
	WSADATA wsaData;
	int err = WSAStartup(wVer, &wsaData);
	if (err)
	{
		cout << "socket start error" << endl;
		return -1;
	}
	sock = socket(AF_INET, SOCK_DGRAM, 0);
	if (sock == INVALID_SOCKET)
	{
		cout << "sock create error" << endl;
		return -1;
	}
	bool opt = true;
	//setsockopt(sock, SOL_SOCKET, SO_BROADCAST, (char FAR *)&opt, sizeof(opt));

	sockaddr_in myaddr;
	memset(&myaddr, 0, sizeof(myaddr));
	myaddr.sin_family = AF_INET;
	myaddr.sin_addr.s_addr = ADDR_ANY;
	myaddr.sin_port = htons(7777);
	
	bind(sock, (sockaddr*)&myaddr, sizeof(myaddr));
	cout << "here" << endl;
	int fromlen = sizeof(SOCKADDR);
	char buf[256];
	while (true)
	{
		memset(buf, 0, sizeof(buf));
		if (recv(sock, buf, sizeof(buf), 0) == SOCKET_ERROR)
		{
			cout << "receive error:" <<WSAGetLastError()<< endl;
		}
		cout << buf << endl;
		Sleep(1000);
	}
	if (!closesocket(sock)) {
		WSAGetLastError();
		return -1;
	}
	if (!WSACleanup()) {
		WSAGetLastError();
		return -1;
	}
	return 0;
}

