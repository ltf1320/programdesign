VERSION 5.00
Begin VB.Form Form3 
   Caption         =   "��ͨ���ͣ���ţ����"
   ClientHeight    =   2520
   ClientLeft      =   5370
   ClientTop       =   4155
   ClientWidth     =   4680
   LinkTopic       =   "Form3"
   ScaleHeight     =   2520
   ScaleWidth      =   4680
   Visible         =   0   'False
   Begin VB.CommandButton Command2 
      Caption         =   "����"
      Height          =   615
      Left            =   2520
      TabIndex        =   7
      Top             =   1680
      Width           =   1695
   End
   Begin VB.CommandButton Command1 
      Caption         =   "      ��ʼ         ������Ŀ��������"
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
      Caption         =   "����������ɹ�"
      Height          =   255
      Left            =   120
      TabIndex        =   5
      Top             =   1200
      Visible         =   0   'False
      Width           =   1455
   End
   Begin VB.Label Label3 
      Alignment       =   2  'Center
      Caption         =   "ͷţ��"
      Height          =   255
      Left            =   2280
      TabIndex        =   4
      Top             =   1200
      Visible         =   0   'False
      Width           =   615
   End
   Begin VB.Label Label4 
      Alignment       =   2  'Center
      Caption         =   "�죨�ܣ���"
      Height          =   255
      Left            =   3480
      TabIndex        =   3
      Top             =   1200
      Visible         =   0   'False
      Width           =   975
   End
   Begin VB.Label Label1 
      Caption         =   "    һ������������ݣ�ÿ�죨�ܣ���ݶ�������������Ƭ�����Ĳݿɹ�xͷţ��y�죨�ܣ����ɹ�aͷţ��b�죨�ܣ����ɹ�����ͷţ��z�죨�ܣ���"
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
    x = Val(InputBox("x=", "������x��ֵ"))
    If x <= 0 Then MsgBox "����С�ڻ����0��"
  Loop While x <= o
  Do
    y = Val(InputBox("y=", "������y��ֵ"))
    If y <= 0 Then MsgBox "����С�ڻ����0��"
  Loop While y <= o
  Do
    a = Val(InputBox("a=", "������a��ֵ"))
    If a <= 0 Then MsgBox "����С�ڻ����0��"
  Loop While a <= o
  Do
    b = Val(InputBox("b=", "������b��ֵ"))
    If b <= 0 Then MsgBox "����С�ڻ����0��"
  Loop While b <= o
  Do
    z = Val(InputBox("z=", "������z��ֵ"))
    If z <= 0 Then MsgBox "����С�ڻ����0��"
  Loop While z <= o
    If a = x Or y = b Then MsgBox "������(��)����ţ��ͷ������һ��!"
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
Select Case MsgBox("�������ر���?", vbOKCancel)
Case vbOK
End
Case Else
Cancel = True
End Select
End Sub


