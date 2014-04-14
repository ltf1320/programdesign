VERSION 5.00
Begin VB.Form Form4 
   Caption         =   "Form4"
   ClientHeight    =   3090
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   4680
   LinkTopic       =   "Form4"
   ScaleHeight     =   3090
   ScaleWidth      =   4680
   StartUpPosition =   3  '窗口缺省
   Begin VB.TextBox z 
      Alignment       =   2  'Center
      Height          =   270
      Left            =   2880
      TabIndex        =   6
      Top             =   1320
      Visible         =   0   'False
      Width           =   615
   End
   Begin VB.TextBox e 
      Alignment       =   2  'Center
      Height          =   270
      Left            =   1560
      TabIndex        =   4
      Top             =   1320
      Visible         =   0   'False
      Width           =   735
   End
   Begin VB.CommandButton Command2 
      Caption         =   "返回"
      Height          =   615
      Left            =   2400
      TabIndex        =   1
      Top             =   2160
      Width           =   1695
   End
   Begin VB.CommandButton Command1 
      Caption         =   "      开始         根据题目输入数据"
      Height          =   615
      Left            =   360
      TabIndex        =   0
      Top             =   2160
      Width           =   1695
   End
   Begin VB.Label Label4 
      Alignment       =   2  'Center
      Caption         =   "天（周）。"
      Height          =   255
      Left            =   3480
      TabIndex        =   7
      Top             =   1320
      Visible         =   0   'False
      Width           =   975
   End
   Begin VB.Label Label3 
      Alignment       =   2  'Center
      Caption         =   "头牛吃"
      Height          =   255
      Left            =   2280
      TabIndex        =   5
      Top             =   1320
      Visible         =   0   'False
      Width           =   615
   End
   Begin VB.Label Label2 
      Alignment       =   2  'Center
      Caption         =   "答：这个牧场可供"
      Height          =   255
      Left            =   120
      TabIndex        =   3
      Top             =   1320
      Visible         =   0   'False
      Width           =   1455
   End
   Begin VB.Label Label1 
      Caption         =   $"Form4.frx":0000
      Height          =   735
      Left            =   120
      TabIndex        =   2
      Top             =   240
      Width           =   4455
   End
End
Attribute VB_Name = "Form4"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
Do
  Do
    Sa = Val(InputBox("Sa=", "请输入Sa的数值"))
    If Sa <= 0 Then MsgBox "不得小于或等于0！"
  Loop While Sa <= 0
  Do
    Sb = Val(InputBox("Sb=", "请输入Sb的数值"))
    If Sb <= 0 Then MsgBox "不得小于或等于0！"
  Loop While Sb <= 0
  Do
    Sc = Val(InputBox("Sc=", "请输入Sc的数值"))
    If Sc <= 0 Then MsgBox "不得小于或等于0！"
  Loop While Sc <= 0
  Do
    x = Val(InputBox("x=", "请输入x的值"))
    If x <= 0 Then MsgBox "不得小于或等于0！"
  Loop While x <= 0
  Do
    y = Val(InputBox("y=", "请输入y的值"))
    If y <= 0 Then MsgBox "不得小于或等于0！"
  Loop While y <= 0
  Do
    a = Val(InputBox("a=", "请输入a的值"))
    If a <= 0 Then MsgBox "不得小于或等于0！"
  Loop While a <= 0
  Do
    b = Val(InputBox("b=", "请输入b的值"))
    If b <= 0 Then MsgBox "不得小于或等于0！"
  Loop While b <= 0
  Do
    e = Val(InputBox("e=", "请输入z的值"))
    If e <= 0 Then MsgBox "不得小于或等于0！"
  Loop While e <= 0
    If a = x Or y = b Then MsgBox "两次天(周)数或牛的头数不能一样!"
Loop While a = x Or y = b
If (a * b) / Sb > (x * y) / Sa Then
    c = ((a * b) / Sb - (x * y) / Sa) / (b - y)
ElseIf a * b < x * y Then
    c = ((x * y) / Sa - (a * b) / Sb) / (y - b)
Else
    MsgBox "你输入的数值有误!"
End If
d = (x * y) / Sa - c * y
z = (d * Sc) / (e - c * Sc)
Label2.Visible = True
e.Visible = True
Label3.Visible = True
z.Visible = True
Label4.Visible = True
e.Text = e
z.Text = z
End Sub

Private Sub Command2_Click()
Form4.Hide
FORM1.Show
End Sub
