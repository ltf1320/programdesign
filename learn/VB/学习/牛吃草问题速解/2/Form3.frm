VERSION 5.00
Begin VB.Form Form3 
   Caption         =   "普通题型（求牛数）"
   ClientHeight    =   2520
   ClientLeft      =   5370
   ClientTop       =   4155
   ClientWidth     =   4680
   LinkTopic       =   "Form3"
   ScaleHeight     =   2520
   ScaleWidth      =   4680
   Visible         =   0   'False
   Begin VB.CommandButton Command2 
      Caption         =   "返回"
      Height          =   615
      Left            =   2520
      TabIndex        =   7
      Top             =   1680
      Width           =   1695
   End
   Begin VB.CommandButton Command1 
      Caption         =   "      开始         根据题目输入数据"
      Height          =   615
      Left            =   360
      TabIndex        =   6
      Top             =   1680
      Width           =   1695
   End
   Begin VB.TextBox e 
      Alignment       =   2  'Center
      Height          =   270
      Left            =   1560
      TabIndex        =   2
      Top             =   1200
      Visible         =   0   'False
      Width           =   735
   End
   Begin VB.TextBox z 
      Alignment       =   2  'Center
      Height          =   270
      Left            =   2880
      TabIndex        =   1
      Top             =   1200
      Visible         =   0   'False
      Width           =   615
   End
   Begin VB.Label Label2 
      Alignment       =   2  'Center
      Caption         =   "答：这个牧场可供"
      Height          =   255
      Left            =   120
      TabIndex        =   5
      Top             =   1200
      Visible         =   0   'False
      Width           =   1455
   End
   Begin VB.Label Label3 
      Alignment       =   2  'Center
      Caption         =   "头牛吃"
      Height          =   255
      Left            =   2280
      TabIndex        =   4
      Top             =   1200
      Visible         =   0   'False
      Width           =   615
   End
   Begin VB.Label Label4 
      Alignment       =   2  'Center
      Caption         =   "天（周）。"
      Height          =   255
      Left            =   3480
      TabIndex        =   3
      Top             =   1200
      Visible         =   0   'False
      Width           =   975
   End
   Begin VB.Label Label1 
      Caption         =   "    一个牧场长满青草，每天（周）青草都匀速生长，这片牧场的草可供x头牛吃y天（周），可供a头牛吃b天（周），可供多少头牛吃z天（周）？"
      Height          =   735
      Left            =   120
      TabIndex        =   0
      Top             =   120
      Width           =   4335
   End
End
Attribute VB_Name = "Form3"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
Do
  Do
    x = Val(InputBox("x=", "请输入x的值"))
    If x <= 0 Then MsgBox "不得小于或等于0！"
  Loop While x <= o
  Do
    y = Val(InputBox("y=", "请输入y的值"))
    If y <= 0 Then MsgBox "不得小于或等于0！"
  Loop While y <= o
  Do
    a = Val(InputBox("a=", "请输入a的值"))
    If a <= 0 Then MsgBox "不得小于或等于0！"
  Loop While a <= o
  Do
    b = Val(InputBox("b=", "请输入b的值"))
    If b <= 0 Then MsgBox "不得小于或等于0！"
  Loop While b <= o
  Do
    z = Val(InputBox("z=", "请输入z的值"))
    If z <= 0 Then MsgBox "不得小于或等于0！"
  Loop While z <= o
    If a = x Or y = b Then MsgBox "两次天(周)数或牛的头数不能一样!"
Loop While a = x Or y = b
If a * b > x * y Then
    c = (a * b - x * y) / (b - y)
Else
    c = (x * y - a * b) / (y - b)
  End If
d = x * y - c * y
e = (d + z * c) / z
Label2.Visible = True
e.Visible = True
Label3.Visible = True
z.Visible = True
Label4.Visible = True
e.Text = e
z.Text = z
End Sub

Private Sub Command2_Click()
Form3.Hide
FORM1.Show
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


