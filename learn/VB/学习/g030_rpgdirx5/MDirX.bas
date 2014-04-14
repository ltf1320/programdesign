Attribute VB_Name = "MDirX"
Option Explicit

' API Stuff...
Public Const BITSPIXEL = 12 ' GetDeviceCaps's nIndex value
Public Const WS_POPUP = &H80000000 ' SetWindowLong
Public Const WS_VISIBLE = &H10000000 ' SetWindowLong
Public Const GWL_STYLE = (-16) ' SetWindowLong
Public Const HWND_TOPMOST = -1 ' SetWindowPos
Public Const SWP_NOSIZE = &H1 ' Can't be resized
Public Const SWP_NOMOVE = &H2 ' Can't be moved


'Pen Style constants
Public Const PS_SOLID = 0
Public Const PS_DASH = 1                    '  -------
Public Const PS_DOT = 2                     '  .......
Public Const PS_DASHDOT = 3                 '  _._._._
Public Const PS_DASHDOTDOT = 4              '  _.._.._
                  
Type RECT
    Left As Long
    Top As Long
    Right As Long
    Bottom As Long
End Type


' USER32
Declare Function GetDC Lib "user32" (ByVal hwnd As Long) As Long
Declare Function DeleteDC Lib "gdi32" (ByVal hdc As Long) As Long
Declare Function GetDeviceCaps Lib "gdi32" (ByVal hdc As Long, ByVal nIndex As Long) As Long
Declare Function ReleaseDC Lib "user32" (ByVal hwnd As Long, ByVal hdc As Long) As Long
Declare Function SetWindowLong Lib "user32" Alias "SetWindowLongA" (ByVal hwnd As Long, ByVal nIndex As Long, ByVal dwNewLong As Long) As Long
Declare Function SetWindowPos Lib "user32" (ByVal hwnd As Long, ByVal hWndInsertAfter As Long, ByVal x As Long, ByVal y As Long, ByVal cx As Long, ByVal cy As Long, ByVal wFlags As Long) As Long
Declare Function ShowCursor Lib "user32" (ByVal bShow As Long) As Long
Declare Function FillRect Lib "user32" (ByVal hdc As Long, lpRect As RECT, ByVal hBrush As Long) As Long
Declare Function LoadBitmap Lib "user32" Alias "LoadBitmapA" (ByVal hInstance As Long, ByVal lpBitmapName As String) As Long


' GDI32
Declare Function TextOut Lib "gdi32" Alias "TextOutA" (ByVal hdc As Long, ByVal x As Long, ByVal y As Long, ByVal lpString As String, ByVal nCount As Long) As Long
Declare Function SetBkColor Lib "gdi32" (ByVal hdc As Long, ByVal crColor As Long) As Long
Declare Function SetTextColor Lib "gdi32" (ByVal hdc As Long, ByVal crColor As Long) As Long

Declare Function SetPixel Lib "gdi32" (ByVal hdc As Long, ByVal x As Long, ByVal y As Long, ByVal crColor As Long) As Long
Declare Function CreatePen Lib "gdi32" (ByVal nPenStyle As Long, ByVal nWidth As Long, ByVal crColor As Long) As Long
Declare Function CreateSolidBrush Lib "gdi32" (ByVal crColor As Long) As Long
Declare Function DeleteObject Lib "gdi32" (ByVal hObject As Long) As Long
Declare Function SelectObject Lib "gdi32" (ByVal hdc As Long, ByVal hObject As Long) As Long
Declare Function StretchBlt Lib "gdi32" (ByVal hdc As Long, ByVal x As Long, ByVal y As Long, ByVal nWidth As Long, ByVal nHeight As Long, ByVal hSrcDC As Long, ByVal xSrc As Long, ByVal ySrc As Long, ByVal nSrcWidth As Long, ByVal nSrcHeight As Long, ByVal dwRop As Long) As Long
Declare Function GetObject Lib "gdi32" Alias "GetObjectA" (ByVal hObject As Long, ByVal nCount As Long, lpObject As Any) As Long
Declare Function CreateCompatibleDC Lib "gdi32" (ByVal hdc As Long) As Long


Declare Function Rectangle Lib "gdi32" (ByVal hdc As Long, ByVal X1 As Long, ByVal Y1 As Long, ByVal X2 As Long, ByVal Y2 As Long) As Long



Sub LoadBitmapInSurface(DDSurface As IDirectDrawSurface2, BitmapFile As String)
    
    '// from VBMaster's DirectX tutorial //
    
    Dim BmpHandle As Long
    Dim OldBmp As Long
    Dim MemDC As Long
    Dim DDSurfaceDC As Long
    Dim BM As BITMAP
    Dim a As Long

    BmpHandle = LoadImage(0&, BitmapFile, 0, 0, 0, LR_LOADFROMFILE Or LR_CREATEDIBSECTION)
    a = GetObject(BmpHandle, Len(BM), BM)

    DDSurface_.GetDC DDSurfaceDC
    MemDC = CreateCompatibleDC(0&)
    
    OldBmp = SelectObject(MemDC, BmpHandle)
    StretchBlt DDSurfaceDC, 0, 0, BM.bmWidth, BM.bmHeight, MemDC, 0, 0, BM.bmWidth, BM.bmHeight, SRCCOPY
    DDSurface_.ReleaseDC DDSurfaceDC
    
    a = SelectObject(MemDC, OldBmp)
    a = DeleteObject(BmpHandle)
    a = DeleteDC(MemDC)

End Sub


