VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "研究性学习成果数据库管理文件"
   ClientHeight    =   5550
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   8040
   LinkTopic       =   "Form1"
   ScaleHeight     =   5550
   ScaleWidth      =   8040
   StartUpPosition =   3  '窗口缺省
   Begin VB.CommandButton Command5 
      Caption         =   "Command5"
      Height          =   495
      Left            =   6720
      TabIndex        =   20
      Top             =   4320
      Width           =   1215
   End
   Begin VB.CommandButton Command4 
      Caption         =   "查询数据"
      Height          =   495
      Left            =   6720
      TabIndex        =   19
      Top             =   3480
      Width           =   1215
   End
   Begin VB.CommandButton Command3 
      Caption         =   "删除数据"
      Height          =   495
      Left            =   6720
      TabIndex        =   18
      Top             =   2640
      Width           =   1215
   End
   Begin VB.CommandButton Command2 
      Caption         =   "修改数据"
      Height          =   495
      Left            =   6720
      TabIndex        =   17
      Top             =   1800
      Width           =   1215
   End
   Begin VB.CommandButton Command1 
      Caption         =   "添加数据"
      Height          =   495
      Left            =   6720
      TabIndex        =   16
      Top             =   960
      Width           =   1215
   End
   Begin VB.TextBox Text8 
      Height          =   375
      Left            =   1680
      TabIndex        =   15
      Text            =   "Text8"
      Top             =   4320
      Width           =   4815
   End
   Begin VB.TextBox Text7 
      Height          =   375
      Left            =   1680
      TabIndex        =   14
      Text            =   "Text7"
      Top             =   3840
      Width           =   4815
   End
   Begin VB.TextBox Text6 
      Height          =   375
      Left            =   1680
      TabIndex        =   13
      Text            =   "Text6"
      Top             =   3360
      Width           =   4815
   End
   Begin VB.TextBox Text5 
      Height          =   375
      Left            =   1680
      TabIndex        =   12
      Text            =   "Text5"
      Top             =   2880
      Width           =   4815
   End
   Begin VB.TextBox Text4 
      Height          =   375
      Left            =   1680
      TabIndex        =   11
      Text            =   "Text4"
      Top             =   2400
      Width           =   4815
   End
   Begin VB.TextBox Text3 
      Height          =   375
      Left            =   1680
      TabIndex        =   10
      Text            =   "Text3"
      Top             =   1920
      Width           =   4815
   End
   Begin VB.TextBox Text2 
      Height          =   375
      Left            =   1680
      TabIndex        =   9
      Text            =   "Text2"
      Top             =   1440
      Width           =   4815
   End
   Begin VB.TextBox Text1 
      Height          =   375
      Left            =   1680
      TabIndex        =   8
      Text            =   "Text1"
      Top             =   960
      Width           =   4815
   End
   Begin VB.Label Label8 
      Caption         =   "完成时间"
      Height          =   255
      Left            =   240
      TabIndex        =   7
      Top             =   3840
      Width           =   1215
   End
   Begin VB.Label Label7 
      Caption         =   "评分"
      Height          =   255
      Left            =   240
      TabIndex        =   6
      Top             =   4320
      Width           =   1215
   End
   Begin VB.Label Label6 
      Caption         =   "成果简介"
      Height          =   255
      Left            =   240
      TabIndex        =   5
      Top             =   3360
      Width           =   1215
   End
   Begin VB.Label Label5 
      Caption         =   "成果名称"
      Height          =   255
      Left            =   240
      TabIndex        =   4
      Top             =   2880
      Width           =   1215
   End
   Begin VB.Label Label4 
      Caption         =   "指导教师"
      Height          =   255
      Left            =   240
      TabIndex        =   3
      Top             =   2400
      Width           =   1215
   End
   Begin VB.Label Label3 
      Caption         =   "年级"
      Height          =   255
      Left            =   240
      TabIndex        =   2
      Top             =   1920
      Width           =   1215
   End
   Begin VB.Label Label2 
      Caption         =   "作者"
      Height          =   255
      Left            =   240
      TabIndex        =   1
      Top             =   1440
      Width           =   1215
   End
   Begin VB.Label Label1 
      Caption         =   "编号"
      Height          =   255
      Left            =   240
      TabIndex        =   0
      Top             =   960
      Width           =   1215
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
