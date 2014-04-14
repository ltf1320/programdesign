VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   2745
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   4590
   LinkTopic       =   "Form1"
   ScaleHeight     =   2745
   ScaleWidth      =   4590
   StartUpPosition =   3  '窗口缺省
   Begin VB.TextBox AB 
      Height          =   270
      Left            =   2880
      TabIndex        =   11
      Top             =   2160
      Width           =   1335
   End
   Begin VB.CommandButton Command1 
      Caption         =   "开始运算"
      Height          =   495
      Left            =   360
      TabIndex        =   10
      Top             =   2040
      Width           =   1215
   End
   Begin VB.TextBox tn 
      Height          =   270
      Left            =   2760
      TabIndex        =   9
      Top             =   1200
      Width           =   1095
   End
   Begin VB.TextBox tl 
      Height          =   270
      Left            =   2760
      TabIndex        =   8
      Top             =   1560
      Width           =   1095
   End
   Begin VB.TextBox tv2 
      Height          =   270
      Left            =   720
      TabIndex        =   7
      Top             =   1560
      Width           =   1095
   End
   Begin VB.TextBox tv1 
      Height          =   270
      Left            =   720
      TabIndex        =   6
      Top             =   1200
      Width           =   1095
   End
   Begin VB.Label Label7 
      AutoSize        =   -1  'True
      Caption         =   "AB："
      Height          =   180
      Left            =   2040
      TabIndex        =   12
      Top             =   2160
      Width           =   360
   End
   Begin VB.Label Label6 
      Caption         =   "v1:"
      Height          =   255
      Left            =   240
      TabIndex        =   5
      Top             =   1200
      Width           =   495
   End
   Begin VB.Label Label5 
      Caption         =   "n:"
      Height          =   255
      Left            =   2400
      TabIndex        =   4
      Top             =   1200
      Width           =   255
   End
   Begin VB.Label Label4 
      Caption         =   "v2:"
      Height          =   255
      Left            =   240
      TabIndex        =   3
      Top             =   1560
      Width           =   375
   End
   Begin VB.Label Label3 
      Caption         =   "L:"
      Height          =   255
      Left            =   2400
      TabIndex        =   2
      Top             =   1560
      Width           =   375
   End
   Begin VB.Label Label2 
      Caption         =   "请输入对应数值"
      Height          =   255
      Left            =   240
      TabIndex        =   1
      Top             =   840
      Width           =   1695
   End
   Begin VB.Label Label1 
      Caption         =   $"Form1.frx":0000
      Height          =   495
      Left            =   240
      TabIndex        =   0
      Top             =   240
      Width           =   4095
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
Dim v1, v2, n, l, sa, s1, s2 As String
Dim i, k As Integer
If IsNumeric(tv1.Text) Then
v1 = Abs(tv1.Text)
v2 = Abs(tv2.Text)
n = tn.Text
l = tl.Text
n = Abs(Int(n))
i = 1
sa = v1 / (v1 + v2)
k = 1
Do While i <= n + 1
    If sa >= 0 And sa <= 1 Then
        If k = 1 Then
            sa = 2 * v1 / (v1 + v2) - sa
        Else
            sa = 2 * v2 / (v1 + v2) - sa
        End If
        k = -k
    Else
        If sa < 0 Then
            If k = -1 Then
                sa = 2 * v1 / (v1 + v2) - sa
            Else
                sa = 2 * v2 / (v1 + v2) - sa
            End If
        Else
            If k = -1 Then
                sa = sa - 2 * (sa - 1) * v2 / (v1 + v2)
            Else
                sa = sa - 2 * (sa - 1) * v1 / (v1 + v2)
            End If
        End If
    End If
    If i = n Then
        s1 = Abs(sa)
    End If
    If i = n + 1 Then
        s2 = Abs(sa)
    End If
    i = i + 1
Loop
If Abs(s2 - s1) = 0 Then
    MsgBox "两次相遇距离必为0！“"
Else
    AB.Text = l / Abs(s2 - s1)
End If
Else
    MsgBox "你至少得知道什么叫数字吧.."
End If
End Sub

