// BitMap.cpp : ����Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "BitMap.h"

#define MAX_LOADSTRING 100
#define Safe_Release(P) if(P){P->Release();P=NULL;}

// ȫ�ֱ���: 
HINSTANCE hInst;								// ��ǰʵ��
TCHAR szTitle[MAX_LOADSTRING];					// �������ı�
TCHAR szWindowClass[MAX_LOADSTRING];			// ����������

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
	HRESULT hr=LoadBitmapFromFile(_T("F:\\ͼƬ\\����.jpg"), winrc.right - winrc.left, winrc.bottom - winrc.top, &pBitmap);
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
	initD2D1();
	MSG msg;
	HACCEL hAccelTable;

	// ��ʼ��ȫ���ַ���
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_BITMAP, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// ִ��Ӧ�ó����ʼ��: 
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_BITMAP));

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
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_BITMAP));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= NULL;
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
