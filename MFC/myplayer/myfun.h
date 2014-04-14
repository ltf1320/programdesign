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

BOOL bPause =FALSE;       //暂停标志
BOOL bStop = TRUE;        //停止标志
BOOL flags;   //歌名闪烁显示

TCHAR songName[MAX_PATH];
TCHAR showName[MAX_PATH];
TCHAR chMusic[MAX_PATH];  //文件路径地址
TCHAR chShortName[MAX_PATH]; //当前播放文件短路径名

TCHAR songLength[20];  //歌曲长度，状态返回值
TCHAR curPosition[20]; //当前位置
TCHAR status[MAX_PATH];//当前状态


int length;  //歌曲长度
int iCurPositon; //当前位置
int iVolume;     //声音大小
//int pMethod;  //自动播放方式
int iPath;  //当前List Box 选项值
int count;//统计值

void playControl(HWND hwnd,int pMethod);
int  getPlayMethod(HWND hwnd);
void saveListToFile(HWND hwnd);
void ReadFileToList(HWND hwnd);


//添加文件
void addSong(HWND hwnd)
{
    TCHAR szFile[MAX_PATH]; //函数得到的原始的存放 
	TCHAR szPath[MAX_PATH];	 //路径 
	TCHAR szFileName[50*MAX_PATH]; //分离出来的每个文件路径和名字 
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
//获取当前选定的文件路径
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

//获取歌曲长度，秒数
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

//获取当前位置，秒数
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
//获取音量值
void getVolume(HWND hwnd)
{
	TCHAR cmd[MAX_PATH];
	TCHAR buff[MAX_PATH];
	wsprintf(cmd,"status %s volume",chShortName);
	mciSendString(cmd,buff,sizeof(buff),0);
	iVolume=atol(buff);

}

//获取歌曲名称，去掉路径
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

//设置播放进度条
void SetTrackPos(HWND hwnd)
{
	SendDlgItemMessage(hwnd,IDC_SLIDER1,TBM_SETRANGEMAX,false,length);
	SendDlgItemMessage(hwnd,IDC_SLIDER1,TBM_SETRANGEMIN,false,0);
	SendDlgItemMessage(hwnd,IDC_SLIDER1,TBM_SETPOS,true,iCurPositon);

}


//设置音量设置条
void SetVolumeTrack(HWND hwnd)
{
	
	SendDlgItemMessage(hwnd,IDC_SLIDER2,TBM_SETRANGEMAX,false,1000);
	SendDlgItemMessage(hwnd,IDC_SLIDER2,TBM_SETRANGEMIN,false,0);
	SendDlgItemMessage(hwnd,IDC_SLIDER2,TBM_SETPOS,true,0);
	iVolume=1000; //音量初始值为最大
	
}

//设置播放音乐音量
void SetVolume(HWND hwnd,int volume)
{
	TCHAR cmd[MAX_PATH];
	int v=volume;
	wsprintf(cmd,"setaudio %s volume to %ld",chShortName,volume);
	mciSendString(cmd,"",0,0);
	//SendDlgItemMessage(hwnd,IDC_SLIDER2,TBM_SETPOS,true,volume);
	//iVolume=volume;

}

//显示音量滑动条数值
void showVolume(HWND hwnd,int volume)
{
	SendDlgItemMessage(hwnd,IDC_SLIDER2,TBM_SETPOS,true,volume);
 	iVolume=1000-volume;
	
}

//显示名称移动效果
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

//播放文件跳转,下一首，上一首
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
// 				SendDlgItemMessage(hwnd,IDC_LIST1,LB_SETSEL,FALSE,(LPARAM)i-1);//上一首取消选定 
// 				//stop();
// 			}
// 		}
// 		break;
// 	case 0:
// 		{
// 			if(i>0)
// 			{
// 				i = i-1;
// 				SendDlgItemMessage(hwnd,IDC_LIST1,LB_SETSEL,FALSE,(LPARAM)i+1);//下一首取消选定 
// 				//stop();
// 			}
// 		}
// 		break;
// 	default:break;
// 	}
// 
// 	SendDlgItemMessage(hwnd,IDC_LIST1,LB_SETSEL,TRUE,(LPARAM)i);//选定新一首 
// 	int a=getCurrentPoint(hwnd);
// 	play(hwnd);
// 
// }

//播放文件跳转，根据方式跳转：1：下一首；0：上一首；2：具体路径选项播放
void jump(HWND hwnd,int method,int jumpto)
{
	stop();
    int i=getCurrentPoint(hwnd);
	int icount=SendDlgItemMessage(hwnd,IDC_LIST1,LB_GETCOUNT,0,0);
	switch(method)
	{
	case 0:  //上一首
		{
			if(i>0)
			{
				i = i-1;
				SendDlgItemMessage(hwnd,IDC_LIST1,LB_SETSEL,FALSE,(LPARAM)i+1);//下一首取消选定 
				//stop();
			}
		}
		break;
	case 1: //下一首
		{   
			if(i<icount-1)
			{
				i = i+1;
				SendDlgItemMessage(hwnd,IDC_LIST1,LB_SETSEL,FALSE,(LPARAM)i-1);//上一首取消选定 
				//stop();
			}
		}
		break;
	case 2:  //跳转到jumpto播放
		{
			SendDlgItemMessage(hwnd,IDC_LIST1,LB_SETSEL,FALSE,(LPARAM)i);//原播放选项取消
			i=jumpto;

		}
		break;
	default:break;
	}
	
	SendDlgItemMessage(hwnd,IDC_LIST1,LB_SETSEL,TRUE,(LPARAM)i);//选定新一首 
	int a=getCurrentPoint(hwnd);
	play(hwnd);
	
}


//Combox选项初始化
void OnIntialComBox(HWND hwnd)
{
	HWND hwndcomb=GetDlgItem(hwnd,IDC_COMBO1);
	ComboBox_InsertString(hwndcomb,-1,TEXT("单曲循环"));
	ComboBox_InsertString(hwndcomb,-1,TEXT("顺序播放"));
	ComboBox_InsertString(hwndcomb,-1,TEXT("循环播放"));
    ComboBox_InsertString(hwndcomb,-1,TEXT("随机播放"));
	ComboBox_SetCurSel(hwndcomb,0);
	
}


//获取播放控制方式
int getPlayMethod(HWND hwnd)
{
	HWND hwndcomb=GetDlgItem(hwnd,IDC_COMBO1);
	int i=ComboBox_GetCurSel(hwndcomb);
	return i;
	
}

//获取List box中的随机项序号
int getRandIndex(HWND hwnd)
{
	int iCount =SendDlgItemMessage(hwnd,IDC_LIST1,LB_GETCOUNT,0,0);
	srand((unsigned)time(NULL));
	int i= rand()%iCount;
	return i;

}



//播放控制
void playControl(HWND hwnd,int pMethod)
{
	TCHAR cmd[MAX_PATH];
	wsprintf(cmd,"status %s mode",chShortName);
	mciSendString(cmd,status,sizeof(status),0);
	if ((lstrcmp(status,"stopped")==0)&&!bStop)
	{
		switch(pMethod)
		{
		case 0:    //单曲循环
			{
				//int jumpto =iPath;
				jump(hwnd,2,iPath);
			}
			break;
		case 1:   //顺序播放
			{
				jump(hwnd,1,0);
			}
			break;
		case 2:    //循环播放
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
		case 3:    //随机播放
			{
				int iPosition=getRandIndex(hwnd);
				jump(hwnd,2,iPosition);				
			}
			break;
		default:break;
		}
	}
}


//保存播放列表到文件
void saveListToFile(HWND hwnd)
{
	FILE *fp;
	//TCHAR buff[50][MAX_PATH];
	remove("c:/list.list");
    if (NULL==(fp=fopen("c:/list.list","w")))
    {
		MessageBox(hwnd,"播放列表文件不存在","警告",MB_OK|MB_ICONWARNING);
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

//读取播放列表
void ReadFileToList(HWND hwnd)
{
	FILE *fp;
	//TCHAR buff[50][MAX_PATH];
    if (NULL==(fp=fopen("c:/list.list","r")))
    {
		MessageBox(hwnd,"播放列表文件不存在","警告",MB_OK|MB_ICONWARNING);
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
//删除当前项或清空播放列表
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


