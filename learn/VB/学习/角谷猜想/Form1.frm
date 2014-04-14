VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "角谷猜想"
   ClientHeight    =   5760
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   7260
   LinkTopic       =   "Form1"
   ScaleHeight     =   5760
   ScaleWidth      =   7260
   StartUpPosition =   3  '窗口缺省
   Begin VB.TextBox Text1 
      Height          =   270
      Left            =   240
      Locked          =   -1  'True
      OLEDropMode     =   1  'Manual
      TabIndex        =   6
      TabStop         =   0   'False
      Top             =   4200
      Width           =   2340
   End
   Begin VB.CommandButton Command1 
      Caption         =   "开始计算"
      Height          =   495
      Left            =   480
      TabIndex        =   4
      Top             =   2160
      Width           =   2055
   End
   Begin VB.TextBox Text2 
      Height          =   4335
      HideSelection   =   0   'False
      IMEMode         =   1  'ON
      Left            =   3360
      Locked          =   -1  'True
      MaxLength       =   9999
      MultiLine       =   -1  'True
      OLEDropMode     =   1  'Manual
      ScrollBars      =   2  'Vertical
      TabIndex        =   0
      TabStop         =   0   'False
      Top             =   960
      WhatsThisHelpID =   1
      Width           =   3375
   End
   Begin VB.TextBox s 
      Height          =   270
      Left            =   600
      TabIndex        =   3
      TabStop         =   0   'False
      Top             =   1440
      Width           =   1815
   End
   Begin VB.Label Label3 
      Caption         =   "所需次数"
      Height          =   255
      Left            =   240
      TabIndex        =   5
      Top             =   3720
      Width           =   2055
   End
   Begin VB.Label Label2 
      Caption         =   "请输入大于1小于9999999的任何整数"
      Height          =   255
      Left            =   120
      TabIndex        =   2
      Top             =   960
      Width           =   2895
   End
   Begin VB.Label Label1 
      Caption         =   "输入数字，就可以显示计算过程"
      BeginProperty Font 
         Name            =   "楷体_GB2312"
         Size            =   14.25
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Left            =   240
      TabIndex        =   1
      Top             =   240
      Width           =   4215
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
  Dim m As String
  m = Val(s.Text)
  If m <= 1 Then
    MsgBox "请输入一个大于1小于9999999的整数！", vbOKCancel, "错误"
  Else
     Text2.Text = ""
     Do While m <> 1
      If m Mod 2 = 0 Then
        Text2.Text = Text2.Text & m & "/" & "2" & "="
        m = m / 2
        Text2.Text = Text2.Text & m & vbCrLf
        t = t + 1
      Else
        Text2.Text = Text2.Text & m & "*" & "3" & "+" & "1" & "="
        v = m * 3 + 1
        m = v
        Text2.Text = Text2.Text & m & vbCrLf
        t = t + 1
      End If
    Loop
  End If
Text1.Text = t
End Sub
