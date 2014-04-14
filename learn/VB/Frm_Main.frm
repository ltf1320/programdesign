VERSION 5.00
Begin VB.Form Frm_Main 
   Caption         =   "Form1"
   ClientHeight    =   4830
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   8415
   LinkTopic       =   "Form1"
   ScaleHeight     =   4830
   ScaleWidth      =   8415
   StartUpPosition =   3  'Windows Default
   Begin VB.TextBox Txt_X1 
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   15
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H000000FF&
      Height          =   375
      Left            =   2520
      TabIndex        =   11
      Top             =   3360
      Width           =   975
   End
   Begin VB.TextBox Txt_X2 
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   15
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H000000FF&
      Height          =   375
      Left            =   4560
      TabIndex        =   10
      Top             =   3360
      Width           =   975
   End
   Begin VB.CommandButton Cmd_Solve 
      Caption         =   "求解"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   15
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   3120
      TabIndex        =   6
      Top             =   2520
      Width           =   1455
   End
   Begin VB.TextBox Txt_b 
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   15
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H000000FF&
      Height          =   375
      Left            =   3360
      TabIndex        =   5
      Top             =   1680
      Width           =   975
   End
   Begin VB.TextBox Txt_c 
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   15
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H000000FF&
      Height          =   375
      Left            =   4920
      TabIndex        =   4
      Top             =   1680
      Width           =   975
   End
   Begin VB.TextBox Txt_a 
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   15
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H000000FF&
      Height          =   375
      Left            =   1200
      TabIndex        =   1
      Top             =   1680
      Width           =   975
   End
   Begin VB.Label Label6 
      Caption         =   "X2="
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   15
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Left            =   3840
      TabIndex        =   9
      Top             =   3360
      Width           =   735
   End
   Begin VB.Label Label5 
      Caption         =   "X1="
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   15
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Left            =   1920
      TabIndex        =   8
      Top             =   3360
      Width           =   615
   End
   Begin VB.Label Label3 
      Caption         =   "(aX**2+bX=c)"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   15
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Left            =   6000
      TabIndex        =   7
      Top             =   1680
      Width           =   1815
   End
   Begin VB.Label Label4 
      Caption         =   "X ="
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   15
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Left            =   4440
      TabIndex        =   3
      Top             =   1680
      Width           =   615
   End
   Begin VB.Label Label2 
      Caption         =   "X**2 +"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   15
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Left            =   2280
      TabIndex        =   2
      Top             =   1680
      Width           =   1095
   End
   Begin VB.Label Label1 
      Caption         =   "解二元一次方程组"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   21.75
         Charset         =   134
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   2040
      TabIndex        =   0
      Top             =   240
      Width           =   4095
   End
End
Attribute VB_Name = "frm_main"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
'本程序
'1、练习数据类型的定义
'2、熟悉函数的使用和表达式的用法
'3、了解窗体和控件的命名方法。（以前用的是默认的）
Private Sub Cmd_Solve_Click()
    Dim a As Double
    Dim b As Double
    Dim c As Double
    Dim X1 As Double
    Dim X2 As Double
    Dim Derte As Double  '定义为双精度数据类型
        a = frm_main.Txt_a.Text
        b = frm_main.Txt_b.Text
        c = frm_main.Txt_c.Text
        Derte = Sqr(b ^ 2 - 4 * a * c)   'Sqr是开平方函数
        X1 = (-b + Derte) / 2 * a   '表达式
        X2 = (-b - Derte) / 2 * a
        frm_main.Txt_X1.Text = X1
        frm_main.Txt_X2.Text = X2
        
    
End Sub
