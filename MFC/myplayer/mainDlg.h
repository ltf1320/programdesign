#ifndef _MAIN_H
#define _MAIN_H

#include <windows.h>

BOOL WINAPI Main_Proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
BOOL Main_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam);
void Main_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify);
BOOL Main_HScroll(HWND hwnd,HWND hwndctl,UINT code,int pos);
BOOL Main_VScroll(HWND hwnd,HWND hwndctl,UINT code,int pos);
void Main_OnClose(HWND hwnd);

#endif


