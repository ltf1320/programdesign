VERSION 5.00
Begin VB.Form Form2 
   Caption         =   "��ͨ���ͣ����죨�ܣ�����"
   ClientHeight    =   2505
   ClientLeft      =   5580
   ClientTop       =   4155
   ClientWidth     =   4680
   LinkTopic       =   "Form2"
   ScaleHeight     =   2505
   ScaleWidth      =   4680
   Begin VB.TextBox Text5 
      Height          =   270
      Left            =   3720
      TabIndex        =   12
      Top             =   480
      Width           =   615
   End
   Begin VB.TextBox Text4 
      Height          =   270
      Left            =   1800
      TabIndex        =   11
      Top             =   480
      Width           =   615
   End
   Begin VB.TextBox Text3 
      Height          =   270
      Left            =   480
      TabIndex        =   10
      Top             =   480
      Width           =   735
   End
   Begin VB.TextBox Text2 
      Height          =   270
      Index           =   0
      Left            =   2880
      TabIndex        =   9
      Top             =   240
      Width           =   615
   End
   Begin VB.TextBox Text1 
      Height          =   270
      Left            =   1560
      TabIndex        =   8
      Top             =   240
      Width           =   735
   End
   Begin VB.TextBox e 
      Alignment       =   2  'Center
      Height          =   270
      Left            =   2880
      TabIndex        =   6
      Top             =   1200
      Visible         =   0   'False
      Width           =   615
   End
   Begin VB.TextBox z 
      Alignment       =   2  'Center
      Height          =   270
      Left            =   1560
      TabIndex        =   4
      Top             =   1200
      Visible         =   0   'False
      Width           =   735
   End
   Begin VB.CommandButton Command2 
      Caption         =   "����"
      Height          =   615
      Left            =   2520
      TabIndex        =   2
      Top             =   1680
      Width           =   1695
   End
   Begin VB.CommandButton Command1 
      Caption         =   "      ��ʼ         ������Ŀ��������"
      Height          =   615
      Left            =   360
      TabIndex        =   1
      Top             =   1680
      Width           =   1695
   End
   Begin VB.Label Label4 
      Alignment       =   2  'Center
      Caption         =   "�죨�ܣ���"
      Height          =   255
      Left            =   3480
      TabIndex        =   7
      Top             =   1200
      Visible         =   0   'False
      Width           =   1095
   End
   Begin VB.Label Label3 
      Alignment       =   2  'Center
      Caption         =   "ͷţ��"
      Height          =   255
      Left            =   2280
      TabIndex        =   5
      Top             =   1200
      Visible         =   0   'False
      Width           =   615
   End
   Begin VB.Label Label2 
      Alignment       =   2  'Center
      Caption         =   "����������ɹ�"
      Height          =   255
      Left            =   120
      TabIndex        =   3
      Top             =   1200
      Visible         =   0   'False
      Width           =   1455
   End
   Begin VB.Label Label1 
      Caption         =   $"Form2.frx":0000
      Height          =   825
      Left            =   120
      TabIndex        =   0
      Top             =   120
      Width           =   4380
      WordWrap        =   -1  'True
   End
End
Attribute VB_Name = "Form2"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
Do
Do
  x = Val(InputBox("x=", "������x��ֵ"))
  If x <= 0 Then MsgBox "����С�ڻ����0��"
Loop While x <= 0

Do
  y = Val(InputBox("y=", "������y��ֵ"))
  If y <= 0 Then MsgBox "����С�ڻ����0��"
Loop While y <= 0

Do
  a = Val(InputBox("a=", "������a��ֵ"))
  If a <= 0 Then MsgBox "����С�ڻ����0��"
Loop While a <= 0

Do
  b = Val(InputBox("b=", "������b��ֵ"))
  If b <= 0 Then MsgBox "����С�ڻ����0��"
Loop While b <= 0

Do
  z = Val(InputBox("z=", "������z��ֵ"))
  If z <= 0 Then MsgBox "����С�ڻ����0��"
Loop While z <= 0
If a = x Or y = b Then MsgBox "������(��)����ţ��ͷ������һ��"
Loop While a = x Or y = b
If x * y > a * b Then
  c = (x * y - a * b) / (y - b)
  Else
  c = (a * b - x * y) / (b - y)
End If
d = x * y - c * y
e = d / (z - c)
Label2.Visible = True
e.Visible = True
Label3.Visible = True
z.Visible = True
Label4.Visible = True
z.Text = z
e.Text = e
End Sub

Private Sub Command2_Click()
Form2.Hide
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

