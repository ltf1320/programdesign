VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "选择题型"
   ClientHeight    =   3225
   ClientLeft      =   60
   ClientTop       =   750
   ClientWidth     =   6240
   LinkTopic       =   "Form1"
   ScaleHeight     =   3225
   ScaleWidth      =   6240
   StartUpPosition =   2  '屏幕中心
   Begin VB.CommandButton Command5 
      Caption         =   "+面积(求面积)"
      Height          =   495
      Left            =   2280
      TabIndex        =   6
      Top             =   1800
      Width           =   1455
   End
   Begin VB.CommandButton Command4 
      Caption         =   "+面积(求牛数)"
      Height          =   495
      Left            =   3960
      TabIndex        =   5
      Top             =   1800
      Width           =   1935
   End
   Begin VB.CommandButton Command2 
      Caption         =   "+面积(求天/周数)"
      Height          =   495
      Left            =   240
      TabIndex        =   4
      Top             =   1800
      Width           =   1815
   End
   Begin VB.Frame Frame1 
      Caption         =   "     刘拓锋制作"
      Height          =   375
      Left            =   4080
      TabIndex        =   3
      Top             =   2640
      Width           =   2055
   End
   Begin VB.CommandButton Command3 
      Caption         =   "普通题型（求牛数）"
      Height          =   495
      Left            =   3240
      TabIndex        =   2
      Top             =   960
      Width           =   2655
   End
   Begin VB.CommandButton Command1 
      Caption         =   "普通题型（求天/周数）"
      Height          =   495
      Left            =   240
      TabIndex        =   1
      Top             =   960
      Width           =   2655
   End
   Begin VB.Label Label1 
      Caption         =   "请选择题型"
      BeginProperty Font 
         Name            =   "华文行楷"
         Size            =   15.75
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Left            =   240
      TabIndex        =   0
      Top             =   240
      Width           =   1815
   End
   Begin VB.Menu File 
      Caption         =   "文件(&F)"
      Index           =   1
      WindowList      =   -1  'True
      Begin VB.Menu about 
         Caption         =   "代码"
      End
      Begin VB.Menu End 
         Caption         =   "退出"
      End
   End
End
Attribute VB_Name = "FORM1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub about_Click()
p = MsgBox("不告诉你", vbOKOnly, "哈哈")
End Sub

Private Sub Command1_Click()
FORM1.Hide
Form2.Show
End Sub

Private Sub Command2_Click()
FORM1.Hide
Form4.Show
End Sub

Private Sub Command3_Click()
FORM1.Hide
Form3.Show
End Sub

Private Sub Command4_Click()
FORM1.Hide
Form5.Show
End Sub

Private Sub Command5_Click()
FORM1.Hide
Form6.Show
End Sub

Private Sub End_Click()
Cancel = True
Select Case MsgBox("您真的想关闭吗?", vbOKCancel)
Case vbOK
End
Case Else
Cancel = True
End Select
End Sub
Private Sub MakeFlat()
Dim style As Long
Dim hToolbar As Long
Dim r As Long
hToolbar = FindWindowEx(Toolbar1.hWnd, 0&, "ToolbarWindow32", vbNullString)
style = SendMessageLong(hToolbar, TB_GETSTYLE, 0&, 0&)
If style And TBSTYLE_FLAT Then
style = style Xor TBSTYLE_FLAT
Else: style = style Or TBSTYLE_FLAT
End If
r = SendMessageLong(hToolbar, TB_SETSTYLE, 0, style)
Toolbar1.Refresh
End Sub
Private Sub Form_Unload(Cancel As Integer)
Cancel = True
Select Case MsgBox("您真的想关闭吗?", vbOKCancel)
Case vbOK
End
Case Else
Cancel = True
End Select
End Sub

