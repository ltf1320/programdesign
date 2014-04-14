#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <Windowsx.h>
#include <STRING.H>
#include "resource.h"
#include <TIME.H>
#include <mmsystem.h>
#include <commctrl.h>
#include <COMMDLG.H>

BOOL bPause =FALSE;       //��ͣ��־
BOOL bStop = TRUE;        //ֹͣ��־
BOOL flags;   //������˸��ʾ

TCHAR songName[MAX_PATH];
TCHAR showName[MAX_PATH];
TCHAR chMusic[MAX_PATH];  //�ļ�·����ַ
TCHAR chShortName[MAX_PATH]; //��ǰ�����ļ���·����

TCHAR songLength[20];  //�������ȣ�״̬����ֵ
TCHAR curPosition[20]; //��ǰλ��
TCHAR status[MAX_PATH];//��ǰ״̬


int length;  //��������
int iCurPositon; //��ǰλ��
int iVolume;     //������С
//int pMethod;  //�Զ����ŷ�ʽ
int iPath;  //��ǰList Box ѡ��ֵ
int count;//ͳ��ֵ

void playControl(HWND hwnd,int pMethod);
int  getPlayMethod(HWND hwnd);
void saveListToFile(HWND hwnd);
void ReadFileToList(HWND hwnd);


//����ļ�
void addSong(HWND hwnd)
{
    TCHAR szFile[MAX_PATH]; //�����õ���ԭʼ�Ĵ�� 
	TCHAR szPath[MAX_PATH];	 //·�� 
	TCHAR szFileName[50*MAX_PATH]; //���������ÿ���ļ�·�������� 
	TCHAR *p;
	OPENFILENAME ofn;
	ZeroMemory(&ofn,sizeof(ofn));
	ofn.lStructSize=sizeof(ofn);
	ofn.lpstrFile=szFile;
	ofn.lpstrFile[0]=TEXT('\0');
	ofn.nMaxFile=sizeof(szFile);
	ofn.lpstrFilter=TEXT("ALL\0*.*\0mp3\0*.mp3\0");
	ofn.nFilterIndex=2;
	ofn.lpstrFileTitle=NULL;
	ofn.nMaxFileTitle=0;
	ofn.hwndOwner=hwnd;
	ofn.lpstrInitialDir=NULL;
	ofn.Flags=OFN_EXPLORER|OFN_PATHMUSTEXIST|OFN_FILEMUSTEXIST|OFN_ALLOWMULTISELECT;
	if (GetOpenFileName(&ofn))
	{
		lstrcpyn(szPath,szFile,ofn.nFileOffset);
		
		szPath[ofn.nFileOffset]='\0';
		if(szPath[ofn.nFileOffset-1]!='\\')
		{
			szPath[ofn.nFileOffset-1]='\\';
		}
		ZeroMemory(szFileName,sizeof(szFileName));
		p=szFile+ofn.nFileOffset;
		int i=0;
		while (*p)
		{
			lstrcat(szFileName,szPath);
			lstrcat(szFileName,p);
			SendDlgItemMessage(hwnd,IDC_LIST1,LB_INSERTSTRING,count,(LPARAM)szFileName);
			p+=strlen(p)+1;
			i++;
			ZeroMemory(szFileName,sizeof(szFileName));

		}
		count =SendDlgItemMessage(hwnd,IDC_LIST1,LB_GETCOUNT,0,0);


	}
}
//��ȡ��ǰѡ�����ļ�·��
int getCurrentPoint(HWND hwnd)
{
	//HWND hwndCtrl=GetDlgItem(hwnd,IDC_LIST1);
	int i = SendMessage(GetDlgItem(hwnd,IDC_LIST1),LB_GETCURSEL,0,0);
// 	ZeroMemory(chMusic,sizeof(chMusic));
// 	ZeroMemory(chShortName,sizeof(chShortName));
	SendMessage(GetDlgItem(hwnd,IDC_LIST1),LB_GETTEXT,i,(LPARAM)chMusic);
	GetShortPathName(chMusic,chShortName,sizeof(chShortName)/sizeof(char));
	iPath=i;
	return i;
}

//��ȡ�������ȣ�����
void getSongLength()
{
	TCHAR cmd[MAX_PATH];
	TCHAR buff[30];
	wsprintf(cmd,TEXT("status %s length"),chShortName);
	mciSendString(cmd,buff,sizeof(buff),NULL);
	long t= atol(buff);
	int min=t/(1000*60);
	int sec=t%(1000*60)/1000;
	wsprintf(songLength,TEXT("%02d:%02d"),min,sec);
	length= t/1000;

}

//��ȡ��ǰλ�ã�����
void getCurPositon()
{
	TCHAR cmd[MAX_PATH];
	TCHAR buff[30];
	wsprintf(cmd,TEXT("status %s position"),chShortName);
	mciSendString(cmd,buff,sizeof(buff),NULL);
	long t= atol(buff);
	int min=t/(1000*60);
	int sec=t%(1000*60)/1000;
	wsprintf(curPosition,TEXT("%02d:%02d"),min,sec);
	iCurPositon =t/1000;
	
}
//��ȡ����ֵ
void getVolume(HWND hwnd)
{
	TCHAR cmd[MAX_PATH];
	TCHAR buff[MAX_PATH];
	wsprintf(cmd,"status %s volume",chShortName);
	mciSendString(cmd,buff,sizeof(buff),0);
	iVolume=atol(buff);

}

//��ȡ�������ƣ�ȥ��·��
void getSongName(HWND hwnd)
{
	TCHAR *p,*pdest;
	int i;
	p=chMusic;
	pdest=strrchr(chMusic,'\\');
	i=(int)(pdest-chMusic+1);
	p=p+i;
	ZeroMemory(songName,sizeof(songName));
	strcat(songName,p);
	
}

//���ò��Ž�����
void SetTrackPos(HWND hwnd)
{
	SendDlgItemMessage(hwnd,IDC_SLIDER1,TBM_SETRANGEMAX,false,length);
	SendDlgItemMessage(hwnd,IDC_SLIDER1,TBM_SETRANGEMIN,false,0);
	SendDlgItemMessage(hwnd,IDC_SLIDER1,TBM_SETPOS,true,iCurPositon);

}


//��������������
void SetVolumeTrack(HWND hwnd)
{
	
	SendDlgItemMessage(hwnd,IDC_SLIDER2,TBM_SETRANGEMAX,false,1000);
	SendDlgItemMessage(hwnd,IDC_SLIDER2,TBM_SETRANGEMIN,false,0);
	SendDlgItemMessage(hwnd,IDC_SLIDER2,TBM_SETPOS,true,0);
	iVolume=1000; //������ʼֵΪ���
	
}

//���ò�����������
void SetVolume(HWND hwnd,int volume)
{
	TCHAR cmd[MAX_PATH];
	int v=volume;
	wsprintf(cmd,"setaudio %s volume to %ld",chShortName,volume);
	mciSendString(cmd,"",0,0);
	//SendDlgItemMessage(hwnd,IDC_SLIDER2,TBM_SETPOS,true,volume);
	//iVolume=volume;

}

//��ʾ������������ֵ
void showVolume(HWND hwnd,int volume)
{
	SendDlgItemMessage(hwnd,IDC_SLIDER2,TBM_SETPOS,true,volume);
 	iVolume=1000-volume;
	
}

//��ʾ�����ƶ�Ч��
void horizontalSongName()
{   
	if (flags)
	{   
		wsprintf(showName,"%s",songName);
		flags=FALSE;
	}
	else
	{
		ZeroMemory(showName,sizeof(showName));
		flags=TRUE;
	}
}

void showSongName(HWND hwnd)
{
	// 	TCHAR *p,*pdest;
	// 	int i;
	// 	p=chMusic;
	// 	pdest=strrchr(chMusic,'\\');
	// 	i=(int)(pdest-chMusic+1);
	// 	p=p+i;
	// 	TCHAR buff[MAX_PATH];
	//     strcat(buff,horizontalSongName());
	horizontalSongName();
	SetDlgItemText(hwnd,IDC_EDIT1,showName);
	
}



void CALLBACK timeproc(HWND hwnd,UINT message,UINT iTimerID,DWORD dwTime)
{
	TCHAR chTime[MAX_PATH];
	getSongLength();
	getCurPositon();
	wsprintf(chTime,TEXT("%s/%s"),curPosition,songLength);
	
	SetDlgItemText(hwnd,IDC_EDIT2,chTime);
    showSongName(hwnd);
	SetTrackPos(hwnd);
	int pMethod=getPlayMethod(hwnd);
	playControl(hwnd,pMethod);
	
	
}

void showTime(HWND hwnd)
{
	ZeroMemory(songLength,sizeof(songLength));
    ZeroMemory(curPosition,sizeof(curPosition));
	SetTimer(hwnd,1,800,timeproc);


}




void play(HWND hwnd)
{
//	char ch =chShortName[0];
	if (chShortName[0]!='\0')
	{
		TCHAR cmd[MAX_PATH];
		wsprintf(cmd,"play %s",chShortName);
		//SetDlgItemText(hwnd,IDC_EDIT1,chMusic);
		mciSendString(cmd,"",0,NULL);
		SetVolume(hwnd,iVolume);
		getSongName(hwnd);
		flags=TRUE;
		showTime(hwnd);
		getVolume(hwnd);
		//showVolume(hwnd);

		bPause=FALSE;
		bStop=FALSE;
	}
	
}

void pause()
{
	TCHAR cmd[MAX_PATH];
	wsprintf(cmd,"pause %s",chShortName);
	mciSendString(cmd,"",0,NULL);
	bPause=TRUE;
	
	
}


void stop()
{
	TCHAR cmd[MAX_PATH];
	wsprintf(cmd,"stop %s",chShortName);
	mciSendString(cmd,"",0,NULL);
	bStop=TRUE;
	bPause=FALSE;
	
}

//�����ļ���ת,��һ�ף���һ��
// void jump(HWND hwnd,int jumpto)
// {
// 	stop();
//     int i=getCurrentPoint(hwnd);
// 	int icount=SendDlgItemMessage(hwnd,IDC_LIST1,LB_GETCOUNT,0,0);
// 	switch(jumpto)
// 	{
// 	case 1:
// 		{   
// 			if(i<icount-1)
// 			{
// 				i = i+1;
// 				SendDlgItemMessage(hwnd,IDC_LIST1,LB_SETSEL,FALSE,(LPARAM)i-1);//��һ��ȡ��ѡ�� 
// 				//stop();
// 			}
// 		}
// 		break;
// 	case 0:
// 		{
// 			if(i>0)
// 			{
// 				i = i-1;
// 				SendDlgItemMessage(hwnd,IDC_LIST1,LB_SETSEL,FALSE,(LPARAM)i+1);//��һ��ȡ��ѡ�� 
// 				//stop();
// 			}
// 		}
// 		break;
// 	default:break;
// 	}
// 
// 	SendDlgItemMessage(hwnd,IDC_LIST1,LB_SETSEL,TRUE,(LPARAM)i);//ѡ����һ�� 
// 	int a=getCurrentPoint(hwnd);
// 	play(hwnd);
// 
// }

//�����ļ���ת�����ݷ�ʽ��ת��1����һ�ף�0����һ�ף�2������·��ѡ���
void jump(HWND hwnd,int method,int jumpto)
{
	stop();
    int i=getCurrentPoint(hwnd);
	int icount=SendDlgItemMessage(hwnd,IDC_LIST1,LB_GETCOUNT,0,0);
	switch(method)
	{
	case 0:  //��һ��
		{
			if(i>0)
			{
				i = i-1;
				SendDlgItemMessage(hwnd,IDC_LIST1,LB_SETSEL,FALSE,(LPARAM)i+1);//��һ��ȡ��ѡ�� 
				//stop();
			}
		}
		break;
	case 1: //��һ��
		{   
			if(i<icount-1)
			{
				i = i+1;
				SendDlgItemMessage(hwnd,IDC_LIST1,LB_SETSEL,FALSE,(LPARAM)i-1);//��һ��ȡ��ѡ�� 
				//stop();
			}
		}
		break;
	case 2:  //��ת��jumpto����
		{
			SendDlgItemMessage(hwnd,IDC_LIST1,LB_SETSEL,FALSE,(LPARAM)i);//ԭ����ѡ��ȡ��
			i=jumpto;

		}
		break;
	default:break;
	}
	
	SendDlgItemMessage(hwnd,IDC_LIST1,LB_SETSEL,TRUE,(LPARAM)i);//ѡ����һ�� 
	int a=getCurrentPoint(hwnd);
	play(hwnd);
	
}


//Comboxѡ���ʼ��
void OnIntialComBox(HWND hwnd)
{
	HWND hwndcomb=GetDlgItem(hwnd,IDC_COMBO1);
	ComboBox_InsertString(hwndcomb,-1,TEXT("����ѭ��"));
	ComboBox_InsertString(hwndcomb,-1,TEXT("˳�򲥷�"));
	ComboBox_InsertString(hwndcomb,-1,TEXT("ѭ������"));
    ComboBox_InsertString(hwndcomb,-1,TEXT("�������"));
	ComboBox_SetCurSel(hwndcomb,0);
	
}


//��ȡ���ſ��Ʒ�ʽ
int getPlayMethod(HWND hwnd)
{
	HWND hwndcomb=GetDlgItem(hwnd,IDC_COMBO1);
	int i=ComboBox_GetCurSel(hwndcomb);
	return i;
	
}

//��ȡList box�е���������
int getRandIndex(HWND hwnd)
{
	int iCount =SendDlgItemMessage(hwnd,IDC_LIST1,LB_GETCOUNT,0,0);
	srand((unsigned)time(NULL));
	int i= rand()%iCount;
	return i;

}



//���ſ���
void playControl(HWND hwnd,int pMethod)
{
	TCHAR cmd[MAX_PATH];
	wsprintf(cmd,"status %s mode",chShortName);
	mciSendString(cmd,status,sizeof(status),0);
	if ((lstrcmp(status,"stopped")==0)&&!bStop)
	{
		switch(pMethod)
		{
		case 0:    //����ѭ��
			{
				//int jumpto =iPath;
				jump(hwnd,2,iPath);
			}
			break;
		case 1:   //˳�򲥷�
			{
				jump(hwnd,1,0);
			}
			break;
		case 2:    //ѭ������
			{
				int iCout=SendDlgItemMessage(hwnd,IDC_LIST1,LB_GETCOUNT,0,0);
				if (iPath==iCout-1)
				{
					jump(hwnd,2,0);
				} 
				else
				{
					jump(hwnd,1,0);
				}				
			}
			break;
		case 3:    //�������
			{
				int iPosition=getRandIndex(hwnd);
				jump(hwnd,2,iPosition);				
			}
			break;
		default:break;
		}
	}
}


//���沥���б��ļ�
void saveListToFile(HWND hwnd)
{
	FILE *fp;
	//TCHAR buff[50][MAX_PATH];
	remove("c:/list.list");
    if (NULL==(fp=fopen("c:/list.list","w")))
    {
		MessageBox(hwnd,"�����б��ļ�������","����",MB_OK|MB_ICONWARNING);
    }
	else
	{
		HWND hwndlist=GetDlgItem(hwnd,IDC_LIST1);
		int iCount=SendDlgItemMessage(hwnd,IDC_LIST1,LB_GETCOUNT,0,0);
		int i=0;
		fprintf(fp,"%i",iCount);
		fprintf(fp,"%c",'\n');
		//fwrite(&iCount,sizeof(int),1,fp);
		for (;i<iCount;i++)
		{

			//fwrite(&szFile[i],sizeof(szFile[i]),1,fp);
			TCHAR szFile[MAX_PATH];
			SendMessage(hwndlist,LB_GETTEXT,i,(LPARAM)szFile);
			fprintf(fp,"%s",szFile);
		    fprintf(fp,"%c",'\n');
		}
		fclose(fp);
	}

}

//��ȡ�����б�
void ReadFileToList(HWND hwnd)
{
	FILE *fp;
	//TCHAR buff[50][MAX_PATH];
    if (NULL==(fp=fopen("c:/list.list","r")))
    {
		MessageBox(hwnd,"�����б��ļ�������","����",MB_OK|MB_ICONWARNING);
    }
	else
	{
		int iCount,i=0;
		//fread(&iCount,sizeof(int),1,fp);
		TCHAR ic[10];
		fgets(ic,sizeof(ic),fp);
		//fscanf(fp,"%i",&iCount);
		iCount=atoi(ic);
		count=iCount;
		if (iCount>0)
		{
			for (;i<iCount;i++)
			{
	// 			fwrite(&buff[i],sizeof(buff[i]),1,fp);
	// 			lstrcpy(szFile,buff[i]);
				TCHAR str[MAX_PATH];
				fgets(str,sizeof(str),fp);
				//char ch =str[strlen(str)-1];
				str[strlen(str)-1] ='\0';
				SendDlgItemMessage(hwnd,IDC_LIST1,LB_INSERTSTRING,i,(LPARAM)str);
			}
		}
		fclose(fp);
	}

}
//ɾ����ǰ�����ղ����б�
void deleteListBox(HWND hwnd,int dMethod)
{
	HWND hwndlist =GetDlgItem(hwnd,IDC_LIST1);
	switch(dMethod)
	{
	case 0:
		{
			int iCurSel=SendMessage(hwndlist,LB_GETCURSEL,0,0);
            SendMessage(hwndlist,LB_DELETESTRING,iCurSel,0);


		}
		break;
	case 1:
		{
			int iCount =SendMessage(hwndlist,LB_GETCOUNT,0,0);
			int i;
			for (i=0;i<iCount;i++)
			{
				SendMessage(hwndlist,LB_DELETESTRING,0,0);

			}
		}
		break;
	default:break;
	}


}


