// HelloWord.cpp : ����Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "HelloWord.h"


#define MAX_LOADSTRING 100
#define SafeRelease(P) {if(P){P->Release();P=NULL;}}

// ȫ�ֱ���: 
HINSTANCE hInst;								// ��ǰʵ��
TCHAR szTitle[MAX_LOADSTRING];					// �������ı�
TCHAR szWindowClass[MAX_LOADSTRING];			// ����������

ID2D1Factory* pD2DFactory = NULL;
RECT rc;


// �˴���ģ���а����ĺ�����ǰ������: 
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO:  �ڴ˷��ô��롣
	HRESULT hr = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &pD2DFactory);
	MSG msg;
	HACCEL hAccelTable;

	// ��ʼ��ȫ���ַ���
	lstrcpy(szWindowClass, _T("����"));
	lstrcpy(szTitle, _T("ltf's HelloWord"));
	MyRegisterClass(hInstance);

	// ִ��Ӧ�ó����ʼ��: 
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_HELLOWORD));

	// ����Ϣѭ��: 
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}



//
//  ����:  MyRegisterClass()
//
//  Ŀ��:  ע�ᴰ���ࡣ
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_HELLOWORD));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = NULL;
	wcex.lpszMenuName	= NULL;
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   ����:  InitInstance(HINSTANCE, int)
//
//   Ŀ��:  ����ʵ�����������������
//
//   ע��: 
//
//        �ڴ˺����У�������ȫ�ֱ����б���ʵ�������
//        ��������ʾ�����򴰿ڡ�
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // ��ʵ������洢��ȫ�ֱ�����

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  ����:  WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  Ŀ��:    ���������ڵ���Ϣ��
//
//  WM_COMMAND	- ����Ӧ�ó���˵�
//  WM_PAINT	- ����������
//  WM_DESTROY	- �����˳���Ϣ������
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	ID2D1SolidColorBrush* pBlackBrush = NULL;
	ID2D1HwndRenderTarget* pRT = NULL;
	HRESULT hr;
	switch (message)
	{
	case WM_PAINT:
		// TODO:  �ڴ���������ͼ����...
		GetClientRect(hWnd, &rc);
		hr = pD2DFactory->CreateHwndRenderTarget(
			D2D1::RenderTargetProperties(),
			D2D1::HwndRenderTargetProperties(
			hWnd,
			D2D1::SizeU(
			rc.right - rc.left,
			rc.bottom - rc.top)
			),
			&pRT
			);
		
		if (SUCCEEDED(hr))
		{

			pRT->CreateSolidColorBrush(
				D2D1::ColorF(D2D1::ColorF::Black),
				&pBlackBrush
				);
		}
		pRT->BeginDraw();
		pRT->Clear(D2D1::ColorF(D2D1::ColorF::Blue));	
		pRT->DrawRectangle(
			D2D1::RectF(
			rc.left + 100.0f,
			rc.top + 100.0f,
			rc.right - 100.0f,
			rc.bottom - 100.0f),
			pBlackBrush,
			10);
//		pRT->DrawLine(D2D1::Point2F(rc.right, rc.bottom), D2D1::Point2F(rc.left, rc.top), pBlackBrush);
		
		pRT->DrawRoundedRectangle(D2D1::RoundedRect(D2D1::RectF(150, 300, 300, 350), 300, 300), pBlackBrush,20);
//		pRT->DrawRoundedRectangle(D2D1::RoundedRect(D2D1::RectF(0.f, 100.f, 0.f, 100.f), 30, 50), pBlackBrush);
		hr = pRT->EndDraw();
		SafeRelease(pRT);
		SafeRelease(pBlackBrush);
		break;
	case WM_LBUTTONDOWN:
		MessageBox(NULL, _T("S"), _T("SS"), MB_OK);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// �����ڡ������Ϣ�������
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
