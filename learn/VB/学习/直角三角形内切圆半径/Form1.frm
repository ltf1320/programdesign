VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   2415
   ClientLeft      =   4785
   ClientTop       =   3960
   ClientWidth     =   4860
   LinkTopic       =   "Form1"
   ScaleHeight     =   2415
   ScaleWidth      =   4860
   Begin VB.TextBox Text3 
      Height          =   270
      Left            =   1320
      TabIndex        =   3
      Top             =   1680
      Width           =   1455
   End
   Begin VB.TextBox Text2 
      Height          =   270
      Left            =   2280
      TabIndex        =   2
      Top             =   960
      Width           =   855
   End
   Begin VB.TextBox Text1 
      Height          =   270
      Left            =   1440
      TabIndex        =   1
      Top             =   960
      Width           =   735
   End
   Begin VB.CommandButton Com1 
      Caption         =   "计算"
      Height          =   255
      Left            =   3360
      TabIndex        =   0
      Top             =   960
      Width           =   1335
   End
   Begin VB.Label Label3 
      Caption         =   "内切圆半径"
      Height          =   255
      Left            =   240
      TabIndex        =   6
      Top             =   1680
      Width           =   975
   End
   Begin VB.Label Label2 
      Caption         =   "请输入直角边"
      Height          =   255
      Left            =   120
      TabIndex        =   5
      Top             =   960
      Width           =   1095
   End
   Begin VB.Label Label1 
      Caption         =   "根据直角三角形2直角边算其内切园半径"
      Height          =   255
      Left            =   240
      TabIndex        =   4
      Top             =   240
      Width           =   3255
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Com1_Click()
Dim a As Double
Dim b As Double
Dim c As Double
Dim s As Double
a = Val(Text1.Text)
b = Val(Text2.Text)
c = Sqr(a ^ 2 + b ^ 2)
Call js(a, b, c, s)
Text3.Text = s
End Sub

Private Sub js(a As Double, b As Double, c As Double, s As Double)
s = (a + b - c) / 2
End Sub

