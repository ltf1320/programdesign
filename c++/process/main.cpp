#include <windows.h>
#include "psapi.h"
#include"stdio.h"
#include <tlhelp32.h>

int main()
{
	int i=0;
	PROCESSENTRY32 pe32;
	pe32.dwSize = sizeof(pe32);
	HANDLE hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if(hProcessSnap == INVALID_HANDLE_VALUE)
	{
		i+=0;
	}

	BOOL bMore = ::Process32First(hProcessSnap, &pe32);
	while(bMore)
	{
		//printf(" �������ƣ�%s \n", pe32.szExeFile);
		if(stricmp("chrome.exe",pe32.szExeFile)==0)
		{
			//printf("����������");
			i+=1;
		}
		bMore = Process32Next(hProcessSnap, &pe32);
	}
	if(i>1){           //����1���ų�����
		printf("Yes %d\n",i);
	}else{
		printf("No\n");;
	}
	return 0;
}

