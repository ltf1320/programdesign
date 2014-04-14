VERSION 5.00
Begin VB.Form Form1 
   BorderStyle     =   1  'Fixed Single
   Caption         =   "Ping"
   ClientHeight    =   3105
   ClientLeft      =   45
   ClientTop       =   330
   ClientWidth     =   4605
   Icon            =   "Form1.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   3105
   ScaleWidth      =   4605
   StartUpPosition =   3  '´°¿ÚÈ±Ê¡
   Begin VB.TextBox Text1 
      Height          =   315
      Index           =   5
      Left            =   120
      TabIndex        =   6
      Text            =   "DataPointer"
      Top             =   2640
      Width           =   4335
   End
   Begin VB.TextBox Text1 
      Height          =   315
      Index           =   4
      Left            =   120
      TabIndex        =   5
      Text            =   "Data"
      Top             =   1380
      Width           =   4335
   End
   Begin VB.TextBox Text1 
      Height          =   315
      Index           =   3
      Left            =   120
      TabIndex        =   4
      Text            =   "DataSize"
      Top             =   2220
      Width           =   4335
   End
   Begin VB.TextBox Text1 
      Height          =   315
      Index           =   2
      Left            =   120
      TabIndex        =   3
      Text            =   "RoundTripTime"
      Top             =   960
      Width           =   4335
   End
   Begin VB.TextBox Text1 
      Height          =   315
      Index           =   1
      Left            =   120
      TabIndex        =   2
      Text            =   "Address"
      Top             =   1800
      Width           =   4335
   End
   Begin VB.TextBox Text1 
      Height          =   315
      Index           =   0
      Left            =   120
      TabIndex        =   1
      Text            =   "status"
      Top             =   540
      Width           =   4335
   End
   Begin VB.CommandButton Command1 
      Caption         =   "Ping"
      Height          =   375
      Left            =   120
      TabIndex        =   0
      Top             =   120
      Width           =   1215
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub Command1_Click()
   
   Dim ECHO As ICMP_ECHO_REPLY
   Dim pos As Integer
   Dim ipaddr As String
      
  'ping an ip address, passing the
  'address and the ECHO structure
   ipaddr = InputBox("Input the IP address to ping:", , "127.0.0.1")
   Call Ping(ipaddr, ECHO)
   Me.Caption = "Ping - " & ipaddr
  'display the results from the ECHO structure
   Text1(0) = GetStatusCode(ECHO.status)
   Text1(1) = ECHO.Address
   Text1(2) = ECHO.RoundTripTime & " ms"
   Text1(3) = ECHO.DataSize & " bytes"
   
   If Left$(ECHO.Data, 1) <> Chr$(0) Then
      pos = InStr(ECHO.Data, Chr$(0))
      Text1(4) = Left$(ECHO.Data, pos - 1)
   End If

   Text1(5) = ECHO.DataPointer
   
End Sub

