#include "stdafx.h"

HINSTANCE _HInstance;                              // Ӧ�ó�����
TCHAR _Title[] = _T("���ı���");                 // ���崰�ڵı���

TCHAR _WindowClass[] = _T("MySimpleTextBoxApp");// ����������
ATOM _RegisterClass();                             // ע����������
HWND _CreateWindow(int nCmdShow);                  // ����������
LRESULT CALLBACK _WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);   // ��������Ϣ������

TCHAR _TextBoxClass[] = _T("MySimpleTextBox"); // �ı��������
ATOM _RegisterTextBoxClass();                      // ע���ı������
HWND _CreateTextBoxWindow(HWND hParentWnd);        // �����ı���
LRESULT CALLBACK _TextBoxWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam); // �ı��򴰿���Ϣ������
void _DrawText(HDC hDC);                           // �����ı�
void _SetCaretPos(HWND hWnd);                      // ���ù��λ��
void _UpdateWindow(HWND hWnd);                     // ���´���


// һЩ��������
#define MAINWINDOW_WIDTH    400      // �����ڿ��
#define MAINWINDOW_HEIGHT   200      // �����ڸ߶�
#define TEXTBOX_WIDTH       300      // �ı�����
#define TEXTBOX_HEIGHT      20       // �ı���߶�
#define TEXTBOX_MAXLENGTH   1024 // �ı������ı�����󳤶�

TCHAR _String[TEXTBOX_MAXLENGTH + 1] = _T("");     // �ı�
int    _StringPosition = ::_tcslen(_String);        // ����������ڵ�λ��

int APIENTRY _tWinMain(HINSTANCE hInstance,        // ��ǰ��Ӧ�ó�����
	HINSTANCE hPrevInstance, // ǰһ��Ӧ�ó���ʵ���ľ������Win32�ϣ�ʼ��ΪNULL��
	LPTSTR lpCmdLine,        // �����в���
	int        nCmdShow     // ���ڵ���ʾ��ʽ
	)
{
	_HInstance = hInstance;

	_RegisterClass();                         // ע�ᴰ����
	if (_CreateWindow(nCmdShow) == NULL)       // ��������
		return FALSE;

	MSG msg;
	while (::GetMessage(&msg, NULL, 0, 0))    // ����Ϣ�����л�ȡ��Ϣ
	{
		::TranslateMessage(&msg);            // ת��һЩ�������Ϣ
		::DispatchMessage(&msg);             // ִ����Ϣ����
	}

	return (int)msg.wParam;
}


// ע��Ӧ�ó��򴰿���
ATOM _RegisterClass()
{
	WNDCLASSEX wc;
	::ZeroMemory(&wc, sizeof(wc));                 // ��Ϊһ����գ���Ϊ����δ��ֵ���ֶε�Ĭ��ֵΪ����NULL��

	wc.cbSize = sizeof(wc);
	wc.style = CS_HREDRAW | CS_VREDRAW;  // ָ�������ں��������ĳߴ緢���仯ʱ�����ػ洰��
	wc.hInstance = _HInstance;
	wc.hbrBackground = (HBRUSH)(COLOR_APPWORKSPACE + 1);  // ָ�������ڱ���Ϊ����������ϵͳ��ɫ
	wc.lpszClassName = _WindowClass;          // ��ΪҪע�����������������ʱҪ�Դ�����Ϊ��ʶ��
	wc.lpfnWndProc = _WndProc;                      // ��Ϊ��������Ϣ�ĺ���

	return ::RegisterClassEx(&wc);                 // ����API����ע�ᴰ����
}

// ��������
HWND _CreateWindow(int nCmdShow)
{
	HWND hWnd = ::CreateWindow(_WindowClass, _Title, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, MAINWINDOW_WIDTH, MAINWINDOW_HEIGHT, NULL, NULL, _HInstance, NULL);

	if (hWnd == NULL)
		return NULL;

	::ShowWindow(hWnd, nCmdShow);
	::UpdateWindow(hWnd);

	return hWnd;
}

// ���ڴ������
LRESULT CALLBACK _WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static HWND hTextBoxWnd;

	switch (message)
	{
	case WM_CREATE: {
		_RegisterTextBoxClass();    // ע���ı������
		hTextBoxWnd = _CreateTextBoxWindow(hWnd); // �����ı���
	} break;

	case WM_ACTIVATE:                // �����ڱ�����ʱ���������������ı�����
		::SetFocus(hTextBoxWnd);
		break;

	case WM_SETCURSOR: {  // ���ù����״
		static HCURSOR hCursor = ::LoadCursor(NULL, IDC_ARROW);
		::SetCursor(hCursor);
	} break;

	case WM_DESTROY:   // Ӧ�ó��򱻹ر�
		::PostQuitMessage(0);
		break;

	default:
		return ::DefWindowProc(hWnd, message, wParam, lParam);
	}

	return (LRESULT)0;
}

// ע���ı������
ATOM _RegisterTextBoxClass()
{
	WNDCLASSEX wc;
	::ZeroMemory(&wc, sizeof(wc));

	wc.cbSize = sizeof(wc);
	wc.style = CS_VREDRAW | CS_HREDRAW | CS_DBLCLKS;   // ָ�������ڳߴ緢���仯ʱ�ػ洰�ڣ�������Ӧ���˫���¼�
	wc.hInstance = _HInstance;
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1); // ָ�����ڱ�����ɫΪϵͳ��ɫ�����ڱ�����
	wc.lpszClassName = _TextBoxClass;                  // ָ��Ҫע��Ĵ�����������������ʱҪ�Դ�����Ϊ��ʶ��
	wc.lpfnWndProc = _TextBoxWndProc;               // ��������Ϣ�ĺ���

	return ::RegisterClassEx(&wc);                     // ����API����ע���ı��򴰿�
}


// �����ı���
HWND _CreateTextBoxWindow(HWND hParentWnd)
{
	// ֮�´�����Ϊ�����ı�����ʾ�ڸ��������룬������λ��
	RECT parentWndRect;
	::GetClientRect(hParentWnd, &parentWndRect);  // ��ȡ�����ڿͻ�����λ��
	int left = (parentWndRect.right - TEXTBOX_WIDTH) / 2, top = (parentWndRect.bottom - TEXTBOX_HEIGHT) / 2;

	// �����ı���
	HWND hWnd = ::CreateWindow(_TextBoxClass, NULL, WS_CHILDWINDOW | WS_VISIBLE,
		left, top, TEXTBOX_WIDTH, TEXTBOX_HEIGHT,
		hParentWnd, NULL, _HInstance, NULL);

	return hWnd;
}

// �ı�����Ϣ�Ĵ������
LRESULT CALLBACK _TextBoxWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_PAINT: {  // ��������֮���Լ�һ�Դ����ţ���Ϊ����֮�¶���ı����ֲ���

		static PAINTSTRUCT ps;
		static RECT rect;
		HDC hDC = ::BeginPaint(hWnd, &ps);  // ��ʼ���Ʋ���

		::GetClientRect(hWnd, &rect);        // ��ȡ�ͻ����ĳߴ�
		::DrawEdge(hDC, &rect, EDGE_SUNKEN, BF_RECT);  // ���Ʊ߿�EDGE_SUNKEN��ʾ������ʽΪ��Ƕ��ʽ��BF_RECT��ʾ���ƾ��α߿�
		_DrawText(hDC);                      // �����ı�
		::EndPaint(hWnd, &ps);               // �������Ʋ���

	} break;

	case WM_SETFOCUS: {    // ��ý���
		::CreateCaret(hWnd, (HBITMAP)NULL, 1, TEXTBOX_HEIGHT - 5);     // �������
		_SetCaretPos(hWnd);                            // ���ù��λ��
		::ShowCaret(hWnd);                   // ��ʾ���
	} break;

	case WM_KILLFOCUS: // ʧȥ����
		::HideCaret(hWnd);                   // ���ع��
		::DestroyCaret();                    // ���ٹ��
		break;

	case WM_SETCURSOR: {  // ���ù����״
		static HCURSOR hCursor = ::LoadCursor(NULL, IDC_IBEAM);
		::SetCursor(hCursor);
	} break;

	case WM_CHAR: {    // �ַ���Ϣ
		TCHAR code = (TCHAR)wParam;
		int len = ::_tcslen(_String);
		if (code < (TCHAR)' ' || len >= TEXTBOX_MAXLENGTH)
			return 0;

		::MoveMemory(_String + _StringPosition + 1, _String + _StringPosition, (len - _StringPosition + 1) * sizeof(TCHAR));
		_String[_StringPosition++] = code;

		_UpdateWindow(hWnd);
		_SetCaretPos(hWnd);

	} break;

	case WM_KEYDOWN: {  // ��������Ϣ
		TCHAR code = (TCHAR)wParam;

		switch (code)
		{
		case VK_LEFT: // �����
			if (_StringPosition > 0)
				_StringPosition--;
			break;

		case VK_RIGHT:     // �ҹ���
			if (_StringPosition < (int)::_tcslen(_String))
				_StringPosition++;
			break;

		case VK_HOME: // HOME ��
			_StringPosition = 0;
			break;

		case VK_END:  // END ��
			_StringPosition = ::_tcslen(_String);
			break;

		case VK_BACK: // �˸��
			if (_StringPosition > 0)
			{
				::MoveMemory(_String + _StringPosition - 1, _String + _StringPosition, (::_tcslen(_String) - _StringPosition + 1) * sizeof(TCHAR));
				_StringPosition--;
				_UpdateWindow(hWnd);
			}
			break;

		case VK_DELETE: {  // ɾ����
			int len = ::_tcslen(_String);
			if (_StringPosition < len)
			{
				::MoveMemory(_String + _StringPosition, _String + _StringPosition + 1, (::_tcslen(_String) - _StringPosition + 1) * sizeof(TCHAR));
				_UpdateWindow(hWnd);
			}

		} break;

		}

		_SetCaretPos(hWnd);

	} break;

	case WM_LBUTTONDOWN: {  // ��굥�������ù��λ��
		int x = LOWORD(lParam);
		HDC hDc = ::GetDC(hWnd);

		int strLen = ::_tcslen(_String), strPos = 0;
		SIZE size;

		for (strPos = 0; strPos<strLen; strPos++)
		{
			::GetTextExtentPoint(hDc, _String, strPos, &size);

			if (size.cx + 4 >= x)
				break;
		}

		_StringPosition = strPos;
		::GetTextExtentPoint(hDc, _String, strPos, &size);
		::SetCaretPos(size.cx + 4, 3);

		::ReleaseDC(hWnd, hDc);

	} break;

	default:
		return ::DefWindowProc(hWnd, message, wParam, lParam);
	}

	return (LRESULT)0;
}

// ���´���
void _UpdateWindow(HWND hWnd)
{
	RECT rect;
	::GetClientRect(hWnd, &rect);
	::InvalidateRect(hWnd, &rect, TRUE);
	::UpdateWindow(hWnd);
}

// �����ı�
void _DrawText(HDC hDC)
{
	int len = ::_tcslen(_String);
	::TextOut(hDC, 4, 2, _String, len);
}

// ���ù��λ��
void _SetCaretPos(HWND hWnd)
{
	HDC hDC = ::GetDC(hWnd);

	SIZE size;
	::GetTextExtentPoint(hDC, _String, _StringPosition, &size);
	::SetCaretPos(4 + size.cx, 3);

	::ReleaseDC(hWnd, hDC);

}
