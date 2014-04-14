VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   4785
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   6690
   LinkTopic       =   "Form1"
   ScaleHeight     =   4785
   ScaleWidth      =   6690
   StartUpPosition =   3  '´°¿ÚÈ±Ê¡
   Begin VB.PictureBox Picture1 
      Height          =   495
      Left            =   2760
      ScaleHeight     =   435
      ScaleWidth      =   1155
      TabIndex        =   2
      Top             =   720
      Width           =   1215
   End
   Begin VB.CommandButton Command2 
      Caption         =   "Command2"
      Height          =   495
      Left            =   4440
      TabIndex        =   1
      Top             =   2280
      Width           =   1215
   End
   Begin VB.CommandButton Command1 
      Caption         =   "Command1"
      Height          =   495
      Left            =   1560
      TabIndex        =   0
      Top             =   2280
      Width           =   1215
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Type RECT
Left As Long
Top As Long
Right As Long
Bottom As Long
End Type

Private Declare Function GetDC Lib "user32" (ByVal hwnd As Long) As Long
Private Declare Function ReleaseDC Lib "user32" (ByVal hwnd As Long, ByVal hdc As Long) As Long
Private Declare Function CreatePatternBrush Lib "gdi32" (ByVal hBitmap As Long) As Long
Private Declare Function PatBlt Lib "gdi32" (ByVal hdc As Long, ByVal x As Long, ByVal y As Long, ByVal nWidth As Long, ByVal nHeight As Long, ByVal dwRop As Long) As Long
Private Declare Function DeleteObject Lib "gdi32" (ByVal hObject As Long) As Long
Private Declare Function CreateBitmap Lib "gdi32" (ByVal nWidth As Long, ByVal nHeight As Long, ByVal nPlanes As Long, ByVal nBitCount As Long, lpBits As Any) As Long
Private Declare Function SelectObject Lib "gdi32" (ByVal hdc As Long, ByVal hObject As Long)
Private Declare Function InvalidateRect Lib "user32" (ByVal hwnd As Long, ByVal lpRect As Long, ByVal bErase As Long) As Long
Private bybits(1 To 16) As Byte
Private hBitmap As Long, hBrush As Long
Private hDesktopWnd As Long
Private Sub Command1_Click()
Dim rop As Long, res As Long
Dim hdc5 As Long, width5 As Long, height5 As Long
hdc5 = GetDC(0)
width5 = Screen.Width \ Screen.TwipsPerPixelX
height5 = Screen.Height \ Screen.TwipsPerPixelY
rop = &HA000C9
Call SelectObject(hdc5, hBrush)
res = PatBlt(hdc5, 0, 0, width5, height5, rop)
Call DeleteObject(hBrush)
res = ReleaseDC(0, hdc5)
End Sub
Private Sub Command2_Click()
Dim aa As Long
aa = InvalidateRect(0, 0, 1)
End Sub
Private Sub Form_Load()
Dim ary
Dim i As Long
ary = Array(&H55, &H0, &HAA, &H0, _
&H55, &H0, &HAA, &H0, _
&H55, &H0, &HAA, &H0, _
&H55, &H0, &HAA, &H0)
For i = 1 To 16
bybits(i) = ary(i - 1)
Next i
hBitmap = CreateBitmap(8, 8, 1, 1, bybits(1))
hBrush = CreatePatternBrush(hBitmap)
Picture1.ForeColor = RGB(0, 0, 0)
Picture1.BackColor = RGB(255, 255, 255)
Picture1.ScaleMode = 3
End Sub
