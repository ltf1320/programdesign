VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "ͬѧ¼"
   ClientHeight    =   5535
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   7410
   LinkTopic       =   "Form1"
   ScaleHeight     =   5535
   ScaleWidth      =   7410
   StartUpPosition =   3  '����ȱʡ
   Begin VB.Data Data1 
      Caption         =   "�ɹ����"
      Connect         =   "Access 2000;"
      DatabaseName    =   ""
      DefaultCursorType=   0  'ȱʡ�α�
      DefaultType     =   2  'ʹ�� ODBC
      Exclusive       =   0   'False
      Height          =   375
      Left            =   480
      Options         =   0
      ReadOnly        =   0   'False
      RecordsetType   =   1  'Dynaset
      RecordSource    =   ""
      Top             =   5040
      Width           =   5535
   End
   Begin VB.TextBox Text7 
      Height          =   375
      Left            =   1680
      TabIndex        =   18
      Top             =   4320
      Width           =   3495
   End
   Begin VB.TextBox Text6 
      Height          =   375
      Left            =   1680
      TabIndex        =   17
      Top             =   3600
      Width           =   3495
   End
   Begin VB.TextBox Text5 
      Height          =   375
      Left            =   1680
      TabIndex        =   16
      Top             =   2880
      Width           =   3495
   End
   Begin VB.TextBox Text4 
      Height          =   375
      Left            =   1680
      TabIndex        =   15
      Top             =   2160
      Width           =   3495
   End
   Begin VB.TextBox Text3 
      Height          =   375
      Left            =   1680
      TabIndex        =   14
      Top             =   1440
      Width           =   3495
   End
   Begin VB.TextBox Text2 
      Height          =   375
      Left            =   1680
      TabIndex        =   13
      Top             =   840
      Width           =   3495
   End
   Begin VB.TextBox Text1 
      Height          =   375
      Left            =   1680
      TabIndex        =   12
      Top             =   240
      Width           =   3495
   End
   Begin VB.CommandButton CmdQuit 
      Caption         =   "�˳�"
      Height          =   735
      Left            =   5400
      TabIndex        =   11
      Top             =   4080
      Width           =   1575
   End
   Begin VB.CommandButton CmdQuery 
      Caption         =   "��ѯ����"
      Height          =   735
      Left            =   5400
      TabIndex        =   10
      Top             =   3120
      Width           =   1575
   End
   Begin VB.CommandButton CmdDelete 
      Caption         =   "ɾ������"
      Height          =   735
      Left            =   5400
      TabIndex        =   9
      Top             =   2160
      Width           =   1575
   End
   Begin VB.CommandButton CmdModify 
      Caption         =   "�޸�����"
      Height          =   735
      Left            =   5400
      TabIndex        =   8
      Top             =   1200
      Width           =   1575
   End
   Begin VB.CommandButton CmdAdd 
      Caption         =   "�������"
      Height          =   735
      Left            =   5400
      TabIndex        =   0
      Top             =   240
      Width           =   1575
   End
   Begin VB.Label Label7 
      Caption         =   "E-mail"
      Height          =   255
      Left            =   120
      TabIndex        =   7
      Top             =   4440
      Width           =   1455
   End
   Begin VB.Label Label6 
      Caption         =   "IOCQ"
      Height          =   255
      Left            =   120
      TabIndex        =   6
      Top             =   3600
      Width           =   1455
   End
   Begin VB.Label Label5 
      Caption         =   "סַ"
      Height          =   255
      Left            =   120
      TabIndex        =   5
      Top             =   2880
      Width           =   1455
   End
   Begin VB.Label Label4 
      Caption         =   "�绰"
      Height          =   255
      Left            =   120
      TabIndex        =   4
      Top             =   2160
      Width           =   1455
   End
   Begin VB.Label Label3 
      Caption         =   "�Ա�"
      Height          =   255
      Left            =   120
      TabIndex        =   3
      Top             =   1440
      Width           =   1455
   End
   Begin VB.Label Label2 
      Caption         =   "����"
      Height          =   255
      Left            =   120
      TabIndex        =   2
      Top             =   840
      Width           =   1455
   End
   Begin VB.Label Label1 
      Caption         =   "ѧ��"
      Height          =   255
      Left            =   120
      TabIndex        =   1
      Top             =   240
      Width           =   1455
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
