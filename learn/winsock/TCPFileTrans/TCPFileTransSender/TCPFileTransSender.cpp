// TCPFileTransSender.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
using namespace std;
#define BUF_SIZE 256

int GetHostAndIp(char* name, int len, char ** ipAddress)
{
	char szPath[128] = "";
	WSADATA wsaData;
	PHOSTENT hostinfo;
	//����MAKEWORD�������Winsock�汾����ȷֵ�����ڼ���Winsock�� 
	if (WSAStartup(MAKEWORD(2, 0), &wsaData) == 0) {
		//�����Ǽ���Winsock�⣬���WSAStartup������������ֵΪ0��˵�����سɹ���������Լ��� 
		if ((gethostname(szPath, sizeof(szPath))) == 0) {

			//����ɹ��ؽ������������������name����ָ���Ļ������� 
			if ((hostinfo = gethostbyname(name)) != NULL) {
				//���ǻ�ȡ���������������������ɹ��Ļ���������һ��ָ�룬ָ��hostinfo��hostinfo 
				//ΪPHOSTENT�͵ı��������漴���õ�����ṹ�� 
				*ipAddress = inet_ntoa(*(struct in_addr *)*hostinfo->h_addr_list);
				//����inet_ntoa������������hostinfo�ṹ�����е�h_addr_listת��Ϊ��׼�ĵ�ֱ�ʾ��IP 
				//��ַ����192.168.0.1�� 
				// printf("%s\n",ip);//���IP��ַ
			}
		}
		else
		{
			cout << WSAGetLastError() << endl;
			system("pause");
			delete name;
			name = NULL;
		}
		WSACleanup();                     //ж��Winsock�⣬���ͷ�������Դ 
	}
	strcpy_s(name, len, szPath);
	return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	SOCKET lsock, dsock;
	WSAData wsaData;
	WSAStartup(MAKEWORD(2, 0), &wsaData);

	lsock = socket(AF_INET, SOCK_STREAM, 0);
	if (lsock == INVALID_SOCKET)
	{
		cerr << "create sock failed" << endl;
		system("pause");
		WSACleanup();
		return -1;
	}

	sockaddr_in laddr;
	laddr.sin_family = AF_INET;
	laddr.sin_addr.s_addr = inet_addr("192.168.1.5");
	laddr.sin_port = htons(7777);
	memset(laddr.sin_zero, 0, sizeof(laddr.sin_zero));
	bind(lsock, (sockaddr*)&laddr, sizeof(laddr));

	sockaddr_in daddr;
	daddr.sin_family = AF_INET;
	daddr.sin_addr.s_addr = inet_addr("192.168.1.7");
	daddr.sin_port = htons(7777);
	memset(daddr.sin_zero, 0, sizeof(daddr.sin_zero));
	
	cout << "listening" << endl;
	if (listen(lsock, 5) == SOCKET_ERROR)
	{
		closesocket(lsock);
		WSACleanup();
		cerr << "listen error" << endl;
		system("pause");
		return -1;
	}
	int len=sizeof(daddr);
	dsock = accept(lsock, (sockaddr*)&daddr, &len);
	cout << "listen succeeded" << endl;
	if (dsock == INVALID_SOCKET)
	{
		closesocket(lsock);
		WSACleanup();
		cerr << "accept error" << endl;
		system("pause");
		return -1;
	}

	closesocket(lsock);
	FILE* fp=NULL;
	char fileName[100] = "1.bmp";
	int err= fopen_s(&fp,"F:\\1.bmp","rb");
	if (err == HFILE_ERROR)
	{
		WSACleanup();
		cerr << "file open error" << endl;
		system("pause");
		return -1;
	}

	char buf[BUF_SIZE];
	int tmp;
	int num = 0;
	if (send(dsock, fileName, 100, 0) == SOCKET_ERROR)
	{
		cerr << "trans start error" << endl;
		system("pause");
		WSACleanup();
		return -1;
	}
	if (recv(dsock, buf, 1, 0) == SOCKET_ERROR)
	{
		cerr << "trans start error" << endl;
		system("pause");
		WSACleanup();
		return -1;
	}

	fseek(fp, 0L, SEEK_END);
	int fileSize = ftell(fp);
	cout << fileSize << endl;
	sprintf_s(buf, "%d", fileSize);
	if (send(dsock, buf, BUF_SIZE, 0) == SOCKET_ERROR)
	{
		cerr << "trans start error" << endl;
		system("pause");
		WSACleanup();
		return -1;
	}
	if (recv(dsock, buf, 1, 0) == SOCKET_ERROR)
	{
		cerr << "trans start error" << endl;
		system("pause");
		WSACleanup();
		return -1;
	}

	cout << "file trans started" << endl;
	fseek(fp, 0L, SEEK_SET);
	int gnum = fileSize / BUF_SIZE, md = fileSize%BUF_SIZE;
	for (int i = 0; i < gnum;i++)
	{
		fread(buf, 1, BUF_SIZE, fp);
		if (send(dsock, buf, BUF_SIZE, 0) == SOCKET_ERROR)
		{
			cerr << "trans error" << endl;
			system("pause");
			WSACleanup();
			return -1;
		}
		if (recv(dsock, buf, 1, 0) == SOCKET_ERROR)
		{
			cerr << "trans error" << endl;
			system("pause");
			WSACleanup();
			return -1;
		}
		num++;
	}
	fread(buf, 1, md, fp);
	if (send(dsock, buf, md, 0) == SOCKET_ERROR)
	{
		cerr << "trans error" << endl;
		system("pause");
		WSACleanup();
		return -1;
	}
	if (recv(dsock, buf, 1, 0) == SOCKET_ERROR)
	{
		cerr << "trans error" << endl;
		system("pause");
		WSACleanup();
		return -1;
	}
	cout << "file trans succeeded" << endl;
	closesocket(dsock);
	WSACleanup();
	fclose(fp);
	system("pause");
	return 0;
}

