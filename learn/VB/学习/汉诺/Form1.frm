VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "汉诺"
   ClientHeight    =   4755
   ClientLeft      =   5295
   ClientTop       =   5325
   ClientWidth     =   6000
   LinkTopic       =   "Form1"
   ScaleHeight     =   4755
   ScaleWidth      =   6000
   Begin VB.TextBox Text3 
      Height          =   3135
      Left            =   3000
      MultiLine       =   -1  'True
      ScrollBars      =   2  'Vertical
      TabIndex        =   3
      Top             =   960
      Width           =   2415
   End
   Begin VB.TextBox Text2 
      Height          =   270
      Left            =   120
      TabIndex        =   2
      Top             =   3120
      Width           =   1815
   End
   Begin VB.TextBox Text1 
      Height          =   270
      Left            =   120
      TabIndex        =   0
      Top             =   960
      Width           =   1695
   End
   Begin VB.CommandButton Command1 
      Caption         =   "开始计算"
      Height          =   615
      Left            =   120
      TabIndex        =   7
      Top             =   1680
      Width           =   1695
   End
   Begin VB.Label Label4 
      Caption         =   "输入金盘数目，进行计算"
      Height          =   255
      Left            =   120
      TabIndex        =   6
      Top             =   240
      Width           =   5295
   End
   Begin VB.Label Label3 
      Caption         =   "经过"
      Height          =   255
      Left            =   3000
      TabIndex        =   5
      Top             =   720
      Width           =   1815
   End
   Begin VB.Label Label1 
      Caption         =   "金盘数目"
      Height          =   255
      Left            =   120
      TabIndex        =   4
      Top             =   600
      Width           =   1695
   End
   Begin VB.Label Label2 
      Caption         =   "搬动次数"
      Height          =   255
      Left            =   120
      TabIndex        =   1
      Top             =   2640
      Width           =   1695
   End
   Begin VB.Menu Flie 
      Caption         =   "文件(&F)"
      WindowList      =   -1  'True
      Begin VB.Menu abaot 
         Caption         =   "关于汉诺(Hannoi)"
      End
      Begin VB.Menu End 
         Caption         =   "退出（&E)"
         Shortcut        =   ^W
      End
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub abaot_Click()
Form2.Show
End Sub
Private Sub Hanoi(n As Integer, ByVal A As String, ByVal B As String, ByVal C As String, t As Long)
  If n = 1 Then
    Text3.Text = Cls + Text3.Text + A + "→" + B + vbCrLf
    t = t + 1
  Else
    Call Hanoi(n - 1, A, B, C, t)
    Text3.Text = Text3.Text + A + "→" + B + vbCrLf
    t = t + 1
    Call Hanoi(n - 1, C, B, A, t)
  End If
End Sub
Private Sub Command1_Click()
  Dim t As Long, n As Integer
  t = 0
  n = Val(Text1.Text)
  A = "A"
  B = "B"
  C = "C"
  Call Hanoi(n, A, B, C, t)
  Text2.Text = t
End Sub
Private Sub End_Click()
  End
End Sub
