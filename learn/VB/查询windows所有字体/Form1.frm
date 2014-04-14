VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "×ÖÌå"
   ClientHeight    =   3090
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   4680
   LinkTopic       =   "Form1"
   ScaleHeight     =   3090
   ScaleWidth      =   4680
   StartUpPosition =   3  '´°¿ÚÈ±Ê¡
   Begin VB.ListBox list1 
      Height          =   2220
      Left            =   360
      TabIndex        =   0
      Top             =   240
      Width           =   3855
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Form_Load()
Dim counter As Integer

For counter = 0 To Screen.FontCount - 1
list1.AddItem Screen.Fonts(counter)
Next
End Sub
Private Sub List1_Click()
Static tempheight As Single

If tempheight = 0 Then tempheight = list1.Height
list1.Font.Name = list1.List(list1.ListIndex)
list1.Height = tempheight
End Sub

