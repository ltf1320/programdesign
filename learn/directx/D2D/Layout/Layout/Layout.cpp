// Layout.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include "Layout.h"

#define MAX_LOADSTRING 100
#define Safe_Release(P) if(P) {P->Release();P=NULL;}
#define IFS if(SUCCEEDED(hr))

// 全局变量: 
HINSTANCE hInst;								// 当前实例
TCHAR szTitle[MAX_LOADSTRING];					// 标题栏文本
TCHAR szWindowClass[MAX_LOADSTRING];			// 主窗口类名

ID2D1Factory* pDF;
ID2D1HwndRenderTarget *pRT;
RECT winrc;

VOID initD2D1()
{
	if (pDF == NULL)
	{
		HRESULT hr = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &pDF);
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

HRESULT LoadBitmapFromFile(
	PCWSTR uri,
	UINT dweight,
	UINT dheight,
	ID2D1Bitmap **bitmap
	)
{
	HRESULT hr = S_OK;
	IWICImagingFactory* pWICFactory = NULL;
	IWICBitmapDecoder* pDecoder = NULL;
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
		hr = pWICFactory->CreateDecoderFromFilename(
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
	if (SUCCEEDED(hr))
	{
		UINT oWeight, oHeight;
		hr = pSource->GetSize(&oWeight, &oHeight);
		if (SUCCEEDED(hr))
		{
			if (dweight == 0 && dheight == 0)
			{
				dweight = oWeight;
				dheight = oHeight;
			}
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

void draw1(HWND hWnd)
{
	initRT(hWnd);
	ID2D1Layer* DLayer = NULL;
	ID2D1Bitmap* pBitmap = NULL;
	HRESULT hr;
	hr = LoadBitmapFromFile(_T("F:\\824.jpg"), 500, 500, &pBitmap);
	if (SUCCEEDED(hr))
		hr= pRT->CreateLayer(&DLayer);
	if (SUCCEEDED(hr))
	{
		pRT->BeginDraw();
		pRT->Clear(D2D1::ColorF(D2D1::ColorF::White));
		pRT->PushLayer(
			D2D1::LayerParameters(D2D1::RectF(100.f, 100.f, 300.f, 300.f)),
			DLayer);
/*		D2D1_SIZE_F sz= pBitmap->GetSize();
		pRT->DrawBitmap(
			pBitmap,
			D2D1::RectF(0, 0, sz.width, sz.height));
			*/
		pRT->Clear(D2D1::ColorF(D2D1::ColorF::Blue));
		pRT->PopLayer();
		hr=pRT->EndDraw();
	}
	Safe_Release(DLayer);
	Safe_Release(pBitmap);
}

void draw2(HWND hWnd)
{
	initRT(hWnd);
	ID2D1Layer* DLayer = NULL;
	ID2D1Bitmap* pBitmap = NULL;
	ID2D1SolidColorBrush* pBrush = NULL;
	HRESULT hr;
	hr = LoadBitmapFromFile(_T("F:\\824.jpg"), winrc.right-winrc.left, winrc.bottom-winrc.top, &pBitmap);
	IFS
		hr = pRT->CreateLayer(&DLayer);
	IFS
		hr = pRT->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Green), &pBrush);
	IFS
	{
		pRT->BeginDraw();
		D2D1_SIZE_F sz = pBitmap->GetSize();
		pRT->DrawBitmap(
			pBitmap,
			D2D1::RectF(0, 0, sz.width, sz.height),0.5);
		pRT->PushLayer(
			D2D1::LayerParameters(
			D2D1::InfiniteRect(),
			0,
			D2D1_ANTIALIAS_MODE_PER_PRIMITIVE,
			D2D1::IdentityMatrix(),
			1),
			DLayer
			);
		pRT->FillRectangle(D2D1::RectF(100, 100, 200, 200), pBrush);
		pRT->FillRectangle(D2D1::RectF(200, 200, 300, 300), pBrush);
		pRT->FillRectangle(D2D1::RectF(300, 300, 400, 400), pBrush);
		pRT->PopLayer();
		hr = pRT->EndDraw();
	}
	Safe_Release(DLayer);
	Safe_Release(pBitmap);
	Safe_Release(pBrush);
}

VOID draw3(HWND hWnd)
{
	initRT(hWnd);
	ID2D1Layer* DLayer = NULL;
	ID2D1Bitmap* pBitmap = NULL;
	ID2D1SolidColorBrush* pBrush = NULL;
	ID2D1RadialGradientBrush* pGBrush = NULL;
	ID2D1GradientStopCollection* STCollection = NULL;
	HRESULT hr;
	hr = LoadBitmapFromFile(_T("F:\\824.jpg"), winrc.right - winrc.left, winrc.bottom - winrc.top, &pBitmap);
	IFS
		hr = pRT->CreateLayer(&DLayer);
	IFS
		hr = pRT->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Green), &pBrush);
	IFS
	{
		D2D1_GRADIENT_STOP gradientStops[2];
		gradientStops[0].color = D2D1::ColorF(D2D1::ColorF::Blue, 1);
		gradientStops[0].position = 0.f;
		gradientStops[1].color = D2D1::ColorF(D2D1::ColorF::Red, 0);
		gradientStops[1].position = 1.f;
		hr = pRT->CreateGradientStopCollection(
			gradientStops,
			2,
			D2D1_GAMMA_2_2,
			D2D1_EXTEND_MODE_CLAMP,
			&STCollection);
	}
		IFS
	{
		D2D1_POINT_2F center = D2D1::Point2F((FLOAT)winrc.right / 2, (FLOAT)winrc.bottom / 2);
		hr = pRT->CreateRadialGradientBrush(
			D2D1::RadialGradientBrushProperties(
			center,
			D2D1::Point2F(0, 0),
			(FLOAT)winrc.right / 2,
			(FLOAT)winrc.bottom / 2),
			STCollection,
			&pGBrush);
	}
	IFS
	{
		pRT->BeginDraw();
		pRT->Clear(D2D1::ColorF(D2D1::ColorF::Black));
		D2D1_SIZE_F sz = pBitmap->GetSize();
		pRT->PushLayer(
			D2D1::LayerParameters(
			D2D1::InfiniteRect(),
			0,
			D2D1_ANTIALIAS_MODE_PER_PRIMITIVE,
			D2D1::IdentityMatrix(),
			1,
			pGBrush),
			DLayer
			);
		pRT->DrawBitmap(
			pBitmap,
			D2D1::RectF(0, 0, sz.width, sz.height));
		pRT->PopLayer();
		hr = pRT->EndDraw();
	}
	Safe_Release(DLayer);
	Safe_Release(pBitmap);
	Safe_Release(pBrush);
}

void draw4(HWND hWnd)
{
	initRT(hWnd);
	ID2D1Layer* DLayer = NULL;
	ID2D1Bitmap* pBitmap = NULL;
	ID2D1SolidColorBrush* pBrush = NULL;
	ID2D1RadialGradientBrush* pGBrush = NULL;
	ID2D1GradientStopCollection* STCollection = NULL;
	HRESULT hr;
	hr = LoadBitmapFromFile(_T("F:\\824.jpg"), winrc.right - winrc.left, winrc.bottom - winrc.top, &pBitmap);
	IFS
		hr = pRT->CreateLayer(&DLayer);
	IFS
		hr = pRT->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Green), &pBrush);
	IFS
	{
		D2D1_GRADIENT_STOP gradientStops[2];
		gradientStops[0].color = D2D1::ColorF(D2D1::ColorF::Blue,0);
		gradientStops[0].position = 0.f;
		gradientStops[1].color = D2D1::ColorF(D2D1::ColorF::Red,1);
		gradientStops[1].position = 1.f;
		hr = pRT->CreateGradientStopCollection(
			gradientStops,
			2,
			D2D1_GAMMA_2_2,
			D2D1_EXTEND_MODE_CLAMP,
			&STCollection);
	}
	IFS
	{
		D2D1_POINT_2F center = D2D1::Point2F((FLOAT)winrc.right/2,(FLOAT)winrc.bottom/2);
		hr = pRT->CreateRadialGradientBrush(
			D2D1::RadialGradientBrushProperties(
				center,
				D2D1::Point2F(0, 0),
				(FLOAT)winrc.right / 2,
				(FLOAT)winrc.bottom / 2),
			STCollection,
			&pGBrush);
	}
	IFS
	{
		pRT->BeginDraw();
		pRT->Clear(D2D1::ColorF(D2D1::ColorF::White));
		D2D1_SIZE_F sz = pBitmap->GetSize();
/*		pRT->PushLayer(
			D2D1::LayerParameters(
			D2D1::InfiniteRect(),
			0,
			D2D1_ANTIALIAS_MODE_PER_PRIMITIVE,
			D2D1::IdentityMatrix(),
			1),
			DLayer
			);
		
		pRT->DrawBitmap(
			pBitmap,
			D2D1::RectF(0, 0, sz.width, sz.height));
			*/
		pRT->FillRectangle(D2D1::RectF(0.f, 0.f, (FLOAT)winrc.right, (FLOAT)winrc.bottom), pGBrush);
	//	pRT->PopLayer();
		hr = pRT->EndDraw();
	}
	Safe_Release(DLayer);
	Safe_Release(pBitmap);
	Safe_Release(pBrush);
}

VOID draw5(HWND hWnd)
{
	initRT(hWnd);
	ID2D1Layer* DLayer = NULL;
	ID2D1Bitmap* pBitmap = NULL;
	ID2D1SolidColorBrush* pBrush = NULL;
	ID2D1RadialGradientBrush* pGBrush = NULL;
	ID2D1GradientStopCollection* STCollection = NULL;
	D2D1_ELLIPSE ell = D2D1::Ellipse(D2D1::Point2F(300, 300), 200, 150);
	HRESULT hr=S_OK;
	IFS
		hr = pRT->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Green), &pBrush);
	IFS
	{
		D2D1_GRADIENT_STOP gradientStops[2];
		gradientStops[0].color = D2D1::ColorF(D2D1::ColorF::Blue);
		gradientStops[0].position = 0.f;
		gradientStops[1].color = D2D1::ColorF(D2D1::ColorF::Red);
		gradientStops[1].position = 1.f;
		hr = pRT->CreateGradientStopCollection(
			gradientStops,
			2,
			D2D1_GAMMA_2_2,
			D2D1_EXTEND_MODE_CLAMP,
			&STCollection);
	}
		IFS
	{
		D2D1_POINT_2F center = D2D1::Point2F(0.5, 0.5);
		hr = pRT->CreateRadialGradientBrush(
			D2D1::RadialGradientBrushProperties(
			ell.point,
			D2D1::Point2F(0, 0),
			ell.radiusX,
			ell.radiusY),
			STCollection,
			&pGBrush);
	}
	IFS
	{
		pRT->BeginDraw();
		pRT->Clear(D2D1::ColorF(D2D1::ColorF::White));
		pRT->FillEllipse(ell, pGBrush);
		hr = pRT->EndDraw();
	}
	Safe_Release(DLayer);
	Safe_Release(pBitmap);
	Safe_Release(pBrush);
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
	MSG msg;
	HACCEL hAccelTable;
	initD2D1();
	// 初始化全局字符串
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_LAYOUT, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// 执行应用程序初始化: 
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LAYOUT));

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

	wcex.style			= CS_HREDRAW | CS_VREDRAW ;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LAYOUT));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_LAYOUT);
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
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// 分析菜单选择: 
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		draw3(hWnd);
		break;
	case WM_DESTROY:
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
