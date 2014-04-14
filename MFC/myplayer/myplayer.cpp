// myplayer.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include <windows.h>
#include <windowsx.h>
#include "commdlg.h"
#include "resource.h"
#include "mainDlg.h"
#include "mmsystem.h"
#include "myfun.h"

BOOL WINAPI Main_Proc(HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam)
{
	switch(uMsg)
	{
		HANDLE_MSG(hWnd,WM_INITDIALOG,Main_OnInitDialog);
		HANDLE_MSG(hWnd,WM_COMMAND,Main_OnCommand);
		HANDLE_MSG(hWnd,WM_CLOSE,Main_OnClose);
		HANDLE_MSG(hWnd,WM_HSCROLL,Main_HScroll);
		HANDLE_MSG(hWnd,WM_VSCROLL,Main_VScroll);
	}

    return FALSE;
}




BOOL Main_OnInitDialog(HWND hwnd,HWND hwndFocus,LPARAM lParam)
{
	HICON hIcon = LoadIcon((HINSTANCE) GetWindowLong(hwnd, GWL_HINSTANCE) ,MAKEINTRESOURCE(IDI_ICON1));
    SendMessage(hwnd, WM_SETICON, TRUE,  (LPARAM)hIcon);
    SendMessage(hwnd, WM_SETICON, FALSE, (LPARAM)hIcon);
    ZeroMemory(chShortName,sizeof(chShortName));
	SetVolumeTrack(hwnd);
	OnIntialComBox(hwnd);
	ReadFileToList(hwnd);
	return TRUE;
}


BOOL Main_HScroll(HWND hwnd,HWND hwndctl,UINT code,int pos)
{   HWND hwndTrack = GetDlgItem(hwnd,IDC_SLIDER1);
	if (hwndctl==hwndTrack)
	{
		if (TB_ENDTRACK==code)
		{
			int p=SendMessage(hwndTrack,TBM_GETPOS,0,0);
			TCHAR cmd[MAX_PATH];
			BOOL bPause1=bPause;
			BOOL bStop1=bStop;
			wsprintf(cmd,"play %s from %ld",chShortName,p*1000);
			stop();
			mciSendString(cmd,"",0,NULL);
			SetVolume(hwnd,iVolume);
			bStop=FALSE;
			bPause=bPause1;
			if (bPause)
			{
				pause();
			}
			else
			{
				bPause =FALSE;
				bStop =FALSE;
			}
		}
	}
	return FALSE;

}

BOOL Main_VScroll(HWND hwnd,HWND hwndctl,UINT code,int pos)
{   HWND hwndV=GetDlgItem(hwnd,IDC_SLIDER2);
	if (hwndctl==hwndV)
	{
		if (TB_ENDTRACK==code)
		{
			int v=SendMessage(hwndV,TBM_GETPOS,0,0);
			showVolume(hwnd,v); 
			SetVolume(hwnd,iVolume);
		}
	}
	return FALSE;
}


void Main_OnCommand(HWND hwnd,int id,HWND hwndCtrl,UINT codeNotify)
{   
	switch(id)
	{
	case IDC_OPEN:
		{ 
			addSong(hwnd);

		}
		break;
	case IDC_PLAY:
		{
			if (bStop)
			{
				getCurrentPoint(hwnd);
				play(hwnd);
			}
			else if(bPause)
			{				
				play(hwnd);
			}
			else
			{
				pause();
			}
		}
		break;
	case IDC_STOP:
		{
			stop();
		}
		break;
	case IDC_PRE:
		{
			//stop();
			jump(hwnd,0,0);			
		}
		break;
	case IDC_NEXT:
		{
			//stop();
			jump(hwnd,1,0);			
		}
		break;
	case IDC_EMPTY:
		{
			stop();
            deleteListBox(hwnd,1);
			
		}
		break;
	case IDC_DEL:
		{
			if (SendDlgItemMessage(hwnd,IDC_LIST1,LB_GETCURSEL,0,0)==iPath)
			{
				stop();
			}
            deleteListBox(hwnd,0);			
		}
		break;
	case IDC_LIST1:
		{
			if (LBN_DBLCLK==codeNotify)
			{
				stop();
				getCurrentPoint(hwnd);
				play(hwnd);
			}
		}
		break;

	default:break;

	}
}


void Main_OnClose(HWND hwnd)
{ 
	saveListToFile(hwnd);
	EndDialog(hwnd,0);
}