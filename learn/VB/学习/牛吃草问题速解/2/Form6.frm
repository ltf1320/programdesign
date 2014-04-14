VERSION 5.00
Begin VB.Form Form6 
   Caption         =   "Form6"
   ClientHeight    =   3090
   ClientLeft      =   2820
   ClientTop       =   2400
   ClientWidth     =   4680
   LinkTopic       =   "Form6"
   ScaleHeight     =   3090
   ScaleWidth      =   4680
   Begin VB.TextBox Sc 
      Height          =   270
      Left            =   1920
      Locked          =   -1  'True
      TabIndex        =   4
      Top             =   1200
      Visible         =   0   'False
      Width           =   735
   End
   Begin VB.CommandButton Command2 
      Caption         =   "返回"
      Height          =   615
      Left            =   2400
      TabIndex        =   3
      Top             =   2040
      Width           =   1695
   End
   Begin VB.CommandButton Command1 
      Caption         =   "      开始         根据题目输入数据"
      Height          =   615
      Left            =   240
      TabIndex        =   2
      Top             =   2040
      Width           =   1695
   End
   Begin VB.Label Label2 
      Alignment       =   2  'Center
      Caption         =   "答：这个牧场的面积为"
      Height          =   255
      Left            =   120
      TabIndex        =   1
      Top             =   1200
      Visible         =   0   'False
      Width           =   1815
   End
   Begin VB.Label Label1 
      Caption         =   $"Form6.frx":0000
      Height          =   735
      Left            =   120
      TabIndex        =   0
      Top             =   120
      Width           =   4455
   End
End
Attribute VB_Name = "Form6"
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
    e = Val(InputBox("e=", "请输入e的值"))
    If e <= 0 Then MsgBox "不得小于或等于0！"
  Loop While e <= 0
  Do
    z = Val(InputBox("z=", "请输入z的值"))
    If z <= 0 Then MsgBox "不得小于或等于0！"
  Loop While z <= 0   '输入数据
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
Sc = (e * z - c * z) / d
Label2.Visible = True
Sc.Visible = True
Sc.Text = Sc
End Sub
