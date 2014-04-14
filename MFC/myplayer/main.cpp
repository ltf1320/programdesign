
#include "stdafx.h"
#include "resource.h"
#include "MainDlg.h"
#include <COMMCTRL.H>

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	// TODO: Place code here.
	InitCommonControls();
	DialogBox(hInstance,MAKEINTRESOURCE(IDD_MAIN),NULL,Main_Proc);
	
	return 0;
}



