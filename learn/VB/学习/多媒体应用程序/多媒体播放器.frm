VERSION 5.00
Object = "{22D6F304-B0F6-11D0-94AB-0080C74C7E95}#1.0#0"; "MSDXM.OCX"
Begin VB.Form 多媒体播放器 
   Caption         =   "Form1"
   ClientHeight    =   3195
   ClientLeft      =   6075
   ClientTop       =   6660
   ClientWidth     =   4350
   LinkTopic       =   "Form1"
   ScaleHeight     =   3195
   ScaleWidth      =   4350
   Begin MediaPlayerCtl.MediaPlayer MediaPlayer1 
      Height          =   3375
      Left            =   0
      TabIndex        =   0
      Top             =   -120
      Width           =   4335
      AudioStream     =   -1
      AutoSize        =   0   'False
      AutoStart       =   -1  'True
      AnimationAtStart=   -1  'True
      AllowScan       =   -1  'True
      AllowChangeDisplaySize=   -1  'True
      AutoRewind      =   0   'False
      Balance         =   0
      BaseURL         =   ""
      BufferingTime   =   5
      CaptioningID    =   ""
      ClickToPlay     =   -1  'True
      CursorType      =   0
      CurrentPosition =   -1
      CurrentMarker   =   0
      DefaultFrame    =   ""
      DisplayBackColor=   0
      DisplayForeColor=   16777215
      DisplayMode     =   0
      DisplaySize     =   4
      Enabled         =   -1  'True
      EnableContextMenu=   -1  'True
      EnablePositionControls=   -1  'True
      EnableFullScreenControls=   0   'False
      EnableTracker   =   -1  'True
      Filename        =   ""
      InvokeURLs      =   -1  'True
      Language        =   -1
      Mute            =   0   'False
      PlayCount       =   1
      PreviewMode     =   0   'False
      Rate            =   1
      SAMILang        =   ""
      SAMIStyle       =   ""
      SAMIFileName    =   ""
      SelectionStart  =   -1
      SelectionEnd    =   -1
      SendOpenStateChangeEvents=   -1  'True
      SendWarningEvents=   -1  'True
      SendErrorEvents =   -1  'True
      SendKeyboardEvents=   0   'False
      SendMouseClickEvents=   0   'False
      SendMouseMoveEvents=   0   'False
      SendPlayStateChangeEvents=   -1  'True
      ShowCaptioning  =   0   'False
      ShowControls    =   -1  'True
      ShowAudioControls=   -1  'True
      ShowDisplay     =   0   'False
      ShowGotoBar     =   0   'False
      ShowPositionControls=   -1  'True
      ShowStatusBar   =   0   'False
      ShowTracker     =   -1  'True
      TransparentAtStart=   0   'False
      VideoBorderWidth=   0
      VideoBorderColor=   0
      VideoBorder3D   =   0   'False
      Volume          =   -600
      WindowlessVideo =   0   'False
   End
   Begin VB.Menu mnufile 
      Caption         =   "文件(&F)"
      Begin VB.Menu FileOpen 
         Caption         =   "打开(&O)"
      End
      Begin VB.Menu FileExit 
         Caption         =   "退出(&E)"
      End
   End
   Begin VB.Menu mnuView 
      Caption         =   "查看(&V)"
      Begin VB.Menu Normal 
         Caption         =   "正常(&N)"
      End
      Begin VB.Menu Double 
         Caption         =   "加倍(&D)"
      End
   End
End
Attribute VB_Name = "多媒体播放器"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub FileOpen_Click()
Dim mediafile As String
CommonDialog1.ShowOpen
mediafile = CommonDialog1.FileName
MediaPlayer1.FileName = mediafile
MediaPlayer1.DisplaySize = mpDefaultSize
Form1.Height = MediaPlayer1.Height + 800
Form1.Width = MediaPlayer1.Width + 120
End Sub
