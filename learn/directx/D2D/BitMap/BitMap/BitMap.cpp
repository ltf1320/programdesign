// BitMap.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include "BitMap.h"

#define MAX_LOADSTRING 100
#define Safe_Release(P) if(P){P->Release();P=NULL;}

// 全局变量: 
HINSTANCE hInst;								// 当前实例
TCHAR szTitle[MAX_LOADSTRING];					// 标题栏文本
TCHAR szWindowClass[MAX_LOADSTRING];			// 主窗口类名

ID2D1Factory* pDF=NULL;
ID2D1HwndRenderTarget* pRT = NULL;
RECT winrc;

HRESULT LoadBitmapFromFile(
	PCWSTR uri,
	UINT dweight,
	UINT dheight,
	ID2D1Bitmap **bitmap
	)
{
	HRESULT hr = S_OK;
	IWICImagingFactory* pWICFactory=NULL;
	IWICBitmapDecoder* pDecoder=NULL;
	IWICBitmapScaler* pScaler = NULL;
	IWICBitmapFrameDecode* pSource = NULL;
	IWICFormatConverter* pConverter = NULL;
	hr = CoCreateInstance(
		CLSID_WICImagingFactory,
		NULL,
		CLSCTX_INPROC_SERVER,
		IID_IWICImagingFactory,
		(LPVOID*)&pWICFactory);
	if (SUCCEEDED(hr))
	{
		hr=pWICFactory->CreateDecoderFromFilename(
			uri,
			NULL,
			GENERIC_READ,
			WICDecodeMetadataCacheOnLoad,
			&pDecoder);
	}
	if (SUCCEEDED(hr))
	{
		hr = pDecoder->GetFrame(0, &pSource);
	}
	if (SUCCEEDED(hr))
	{
		hr = pWICFactory->CreateFormatConverter(&pConverter);
	}
	if(SUCCEEDED(hr))
	{
		UINT oWeight, oHeight;
		hr = pSource->GetSize(&oWeight, &oHeight);
		if (SUCCEEDED(hr))
		{
			hr = pWICFactory->CreateBitmapScaler(&pScaler);
			if (SUCCEEDED(hr))
			{
				hr = pScaler->Initialize(
					pSource,
					dweight,
					dheight,
					WICBitmapInterpolationModeCubic);
			}
			
			if (SUCCEEDED(hr))
			{
				hr = pConverter->Initialize(
					pScaler,
					GUID_WICPixelFormat32bppPBGRA,
					WICBitmapDitherTypeNone,
					NULL,
					0.f,
					WICBitmapPaletteTypeMedianCut
					);
			}
			
		}
	}
	if (SUCCEEDED(hr))
	{
		hr = pRT->CreateBitmapFromWicBitmap(pConverter, bitmap);
	}
	Safe_Release(pWICFactory);
	Safe_Release(pDecoder);
	Safe_Release(pScaler);
	Safe_Release(pSource);
	Safe_Release(pConverter);
	return hr;
}

VOID initD2D1()
{
	if (pDF == NULL)
	{
		HRESULT hr=D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &pDF);
	}
}

VOID initRT(HWND hWnd)
{
	if (pRT == NULL)
	{
		GetClientRect(hWnd, &winrc);
		HRESULT hr = pDF->CreateHwndRenderTarget(
			D2D1::RenderTargetProperties(), 
			D2D1::HwndRenderTargetProperties(
				hWnd, D2D1::SizeU(winrc.right - winrc.left, winrc.bottom - winrc.top)
				), 
				&pRT);
	}
}

VOID draw(HWND hWnd)
{
	initRT(hWnd);
	ID2D1Bitmap* pBitmap=NULL;
	ID2D1TransformedGeometry* transGeometry=NULL;
	ID2D1RectangleGeometry* rec=NULL;
	ID2D1SolidColorBrush* pBrush = NULL;
	HRESULT hr=LoadBitmapFromFile(_T("F:\\图片\\佐助.jpg"), winrc.right - winrc.left, winrc.bottom - winrc.top, &pBitmap);
	D2D1_SIZE_F bitsz= pBitmap->GetSize();
	D2D1_RECT_F drect = D2D1::RectF(
		(FLOAT)winrc.left,
		(FLOAT)winrc.top,
		(FLOAT)winrc.right,
		(FLOAT)winrc.bottom);
	if (SUCCEEDED(hr))
	{
		hr = pDF->CreateRectangleGeometry(
			drect,
			&rec);
	}

	if (SUCCEEDED(hr))
	{
		hr = pDF->CreateTransformedGeometry(
			rec,
			D2D1::Matrix3x2F::Scale(D2D1::SizeF(0.5, 0.5), D2D1::Point2F((FLOAT)winrc.right / 2, (FLOAT)winrc.bottom / 2)), &transGeometry);
	}
	if (SUCCEEDED(hr))
	{
		hr = pRT->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Blue), &pBrush);
	}
	if (SUCCEEDED(hr))
	{
		pRT->BeginDraw();
		pRT->Clear(D2D1::ColorF(D2D1::ColorF::White));
/*		pRT->DrawBitmap(pBitmap, D2D1::RectF(
			(FLOAT)winrc.left,
			(FLOAT)winrc.top,
			(FLOAT)winrc.right,
			(FLOAT)winrc.bottom));
			*/
		
	//	pRT->DrawGeometry(transGeometry,pBrush);
		pRT->SetTransform(D2D1::Matrix3x2F::Rotation(45, D2D1::Point2F((FLOAT)winrc.right / 2, (FLOAT)winrc.bottom / 2)));
		pRT->DrawGeometry(transGeometry,pBrush);
	}
	hr = pRT->EndDraw();
}

VOID cleanup()
{
	Safe_Release(pRT);
	Safe_Release(pDF);
}
// 此代码模块中包含的函数的前向声明: 
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

 	// TODO:  在此放置代码。
	initD2D1();
	MSG msg;
	HACCEL hAccelTable;

	// 初始化全局字符串
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_BITMAP, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// 执行应用程序初始化: 
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_BITMAP));

	// 主消息循环: 
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
//  函数:  MyRegisterClass()
//
//  目的:  注册窗口类。
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
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_BITMAP));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= NULL;
	wcex.lpszMenuName	= NULL;
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));
	

	return RegisterClassEx(&wcex);
}

//
//   函数:  InitInstance(HINSTANCE, int)
//
//   目的:  保存实例句柄并创建主窗口
//
//   注释: 
//
//        在此函数中，我们在全局变量中保存实例句柄并
//        创建和显示主程序窗口。
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // 将实例句柄存储在全局变量中

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      300, 100, 600, 600, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  函数:  WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目的:    处理主窗口的消息。
//
//  WM_COMMAND	- 处理应用程序菜单
//  WM_PAINT	- 绘制主窗口
//  WM_DESTROY	- 发送退出消息并返回
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;

	switch (message)
	{
	case WM_PAINT:
		draw(hWnd);
		break;
	case WM_DESTROY:
		cleanup();
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// “关于”框的消息处理程序。
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
