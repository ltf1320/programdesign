// GetLocalIp.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

using namespace std;

//��ñ�����������IP��ַ
int GetHostAndIp( char* name,int len, char ** ipAddress)
{
	char szPath[128] = "";
	WSADATA wsaData;
	PHOSTENT hostinfo;
	//����MAKEWORD�������Winsock�汾����ȷֵ�����ڼ���Winsock�� 
	if (WSAStartup(MAKEWORD(2,0), &wsaData) == 0) {
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
	char host[200]="", *ip;
	GetHostAndIp(host,200, &ip);
	cout << host << endl;
	cout << ip << endl;
	system("pause");
	return 0;
}

