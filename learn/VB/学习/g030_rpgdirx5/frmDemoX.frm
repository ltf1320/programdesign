VERSION 5.00
Object = "{6B7E6392-850A-101B-AFC0-4210102A8DA7}#1.3#0"; "COMCTL32.OCX"
Begin VB.Form frmTestX 
   Caption         =   "DirectX Test"
   ClientHeight    =   3495
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   6795
   LinkTopic       =   "Form1"
   ScaleHeight     =   3495
   ScaleWidth      =   6795
   StartUpPosition =   3  'Windows Default
   Begin VB.PictureBox picHidden 
      Appearance      =   0  'Flat
      AutoRedraw      =   -1  'True
      BackColor       =   &H80000005&
      BorderStyle     =   0  'None
      ForeColor       =   &H80000008&
      Height          =   480
      Left            =   120
      ScaleHeight     =   32
      ScaleMode       =   3  'Pixel
      ScaleWidth      =   32
      TabIndex        =   0
      Top             =   1200
      Visible         =   0   'False
      Width           =   480
   End
   Begin VB.Timer tmrMain 
      Enabled         =   0   'False
      Interval        =   20
      Left            =   120
      Top             =   120
   End
   Begin ComctlLib.ImageList imlFloorTiles 
      Left            =   720
      Top             =   600
      _ExtentX        =   1005
      _ExtentY        =   1005
      BackColor       =   -2147483643
      ImageWidth      =   32
      ImageHeight     =   32
      MaskColor       =   12632256
      UseMaskColor    =   0   'False
      _Version        =   327682
      BeginProperty Images {0713E8C2-850A-101B-AFC0-4210102A8DA7} 
         NumListImages   =   3
         BeginProperty ListImage1 {0713E8C3-850A-101B-AFC0-4210102A8DA7} 
            Picture         =   "frmDemoX.frx":0000
            Key             =   ""
         EndProperty
         BeginProperty ListImage2 {0713E8C3-850A-101B-AFC0-4210102A8DA7} 
            Picture         =   "frmDemoX.frx":0C52
            Key             =   ""
         EndProperty
         BeginProperty ListImage3 {0713E8C3-850A-101B-AFC0-4210102A8DA7} 
            Picture         =   "frmDemoX.frx":18A4
            Key             =   ""
         EndProperty
      EndProperty
   End
   Begin ComctlLib.ImageList imlGuy 
      Left            =   120
      Top             =   600
      _ExtentX        =   1005
      _ExtentY        =   1005
      BackColor       =   -2147483643
      ImageWidth      =   48
      ImageHeight     =   48
      MaskColor       =   16777215
      _Version        =   327682
      BeginProperty Images {0713E8C2-850A-101B-AFC0-4210102A8DA7} 
         NumListImages   =   16
         BeginProperty ListImage1 {0713E8C3-850A-101B-AFC0-4210102A8DA7} 
            Picture         =   "frmDemoX.frx":24F6
            Key             =   ""
         EndProperty
         BeginProperty ListImage2 {0713E8C3-850A-101B-AFC0-4210102A8DA7} 
            Picture         =   "frmDemoX.frx":4048
            Key             =   ""
         EndProperty
         BeginProperty ListImage3 {0713E8C3-850A-101B-AFC0-4210102A8DA7} 
            Picture         =   "frmDemoX.frx":5B9A
            Key             =   ""
         EndProperty
         BeginProperty ListImage4 {0713E8C3-850A-101B-AFC0-4210102A8DA7} 
            Picture         =   "frmDemoX.frx":76EC
            Key             =   ""
         EndProperty
         BeginProperty ListImage5 {0713E8C3-850A-101B-AFC0-4210102A8DA7} 
            Picture         =   "frmDemoX.frx":923E
            Key             =   ""
         EndProperty
         BeginProperty ListImage6 {0713E8C3-850A-101B-AFC0-4210102A8DA7} 
            Picture         =   "frmDemoX.frx":AD90
            Key             =   ""
         EndProperty
         BeginProperty ListImage7 {0713E8C3-850A-101B-AFC0-4210102A8DA7} 
            Picture         =   "frmDemoX.frx":C8E2
            Key             =   ""
         EndProperty
         BeginProperty ListImage8 {0713E8C3-850A-101B-AFC0-4210102A8DA7} 
            Picture         =   "frmDemoX.frx":E434
            Key             =   ""
         EndProperty
         BeginProperty ListImage9 {0713E8C3-850A-101B-AFC0-4210102A8DA7} 
            Picture         =   "frmDemoX.frx":FF86
            Key             =   ""
         EndProperty
         BeginProperty ListImage10 {0713E8C3-850A-101B-AFC0-4210102A8DA7} 
            Picture         =   "frmDemoX.frx":11AD8
            Key             =   ""
         EndProperty
         BeginProperty ListImage11 {0713E8C3-850A-101B-AFC0-4210102A8DA7} 
            Picture         =   "frmDemoX.frx":1362A
            Key             =   ""
         EndProperty
         BeginProperty ListImage12 {0713E8C3-850A-101B-AFC0-4210102A8DA7} 
            Picture         =   "frmDemoX.frx":1517C
            Key             =   ""
         EndProperty
         BeginProperty ListImage13 {0713E8C3-850A-101B-AFC0-4210102A8DA7} 
            Picture         =   "frmDemoX.frx":16CCE
            Key             =   ""
         EndProperty
         BeginProperty ListImage14 {0713E8C3-850A-101B-AFC0-4210102A8DA7} 
            Picture         =   "frmDemoX.frx":18820
            Key             =   ""
         EndProperty
         BeginProperty ListImage15 {0713E8C3-850A-101B-AFC0-4210102A8DA7} 
            Picture         =   "frmDemoX.frx":1A372
            Key             =   ""
         EndProperty
         BeginProperty ListImage16 {0713E8C3-850A-101B-AFC0-4210102A8DA7} 
            Picture         =   "frmDemoX.frx":1BEC4
            Key             =   ""
         EndProperty
      EndProperty
   End
End
Attribute VB_Name = "frmTestX"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
'RPG DirectX Scrolling and Animation Demo
'by Paul Pagel - pagel@clarityconnect.com
'1998 ver 1.0

Option Explicit

' DirectDraw Objects
Dim dDraw As IDirectDraw2 ' DirectDraw main object
Dim ddsPrimary As IDirectDrawSurface2 ' Primary surface (AKA Front Buffer)
Dim ddsBack1 As IDirectDrawSurface2 ' Back buffer (AKA Offscreen surface)
Dim ddsFloor As IDirectDrawSurface2
Dim ddsChars As IDirectDrawSurface2 'buffer to hold guy character animations
Dim ddsTiles As IDirectDrawSurface2 'floor tiles


Dim ddsd As DDSURFACEDESC ' Suface information
Dim ddc As DDSCAPS ' Device capabilities

Dim ClrKey As DDCOLORKEY

Dim miBaseX As Integer 'upper left corner map position
Dim miBaseY As Integer

Dim miDirX As Integer '-1, 0, 1 = left, none, right
Dim miDirY As Integer '-1, 0, 1 = up, none, down
Dim miStep As Integer '0 = stopped/completed, 1-8=walking
Dim meFaceDir As EDirection 'direction main char is facing

'key state vars
Dim mePendingDir As EDirection

Dim mbPendingUp    As Boolean
Dim mbPendingDown  As Boolean
Dim mbPendingLeft  As Boolean
Dim mbPendingRight As Boolean
Dim mbShowStats    As Boolean

Dim mbRunning As Boolean

Dim BPP As Long ' bits per pixel of the system

Private Sub Form_Activate()
    
    On Error GoTo ErrorActivate
    
    'main char initial position and facing direction
    miBaseX = 2
    miBaseY = 2
    meFaceDir = dirDown
    
    ChDir App.Path
    
    'get the map and tileset data
    If MMap.OpenMap(App.Path & "\DemoMap.map") Then
        Call FillTileBuffer
        Call FillFloorBuffer(miBaseX, miBaseY)
    End If
    
    mbRunning = True
    tmrMain.Enabled = True
    Exit Sub
    
ErrorActivate:
    MsgBox Err.Description, , "Form_Activate ERROR"
    Unload Me
End Sub

Private Sub Form_KeyDown(KeyCode As Integer, Shift As Integer)
    
    Select Case KeyCode
        Case vbKeyDown
            mbPendingDown = True
            
        Case vbKeyUp
            mbPendingUp = True
            
        Case vbKeyLeft
            mbPendingLeft = True
            
        Case vbKeyRight
            mbPendingRight = True
                    
        Case vbKeySpace
            mbRunning = False 'end the demo
                    
        Case vbKeyS
            mbShowStats = True
            
    End Select
        
End Sub

Private Sub Form_KeyUp(KeyCode As Integer, Shift As Integer)
    
    Select Case KeyCode
            Case vbKeyDown
                mbPendingDown = False
                
            Case vbKeyUp
                mbPendingUp = False
            
            Case vbKeyLeft
               mbPendingLeft = False
               
            Case vbKeyRight
                mbPendingRight = False
                
            Case vbKeyS
                mbShowStats = False
                
        End Select
    
End Sub

Private Sub Form_Load()
    
    Dim dc As Long ' Desktop's device-context
    Dim i As Integer
    Dim hdcChar As Long
    
    dc = GetDC(0)
    ' get the bits per pixel of the user's system
    BPP = GetDeviceCaps(dc, BITSPIXEL)
    ' Release the dc by freeing any system resources
    Call ReleaseDC(0, dc)
    
    ' Full-Screen window without border & title bar
    SetWindowLong Me.hwnd, GWL_STYLE, WS_POPUP Or WS_VISIBLE
    
    ' Topmost Window
    SetWindowPos Me.hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE Or SWP_NOSIZE
    
    ' Black color background
    Me.BackColor = Hex(RGB(0, 0, 0))
    
    ' Create a new DirectDraw object with the current
    ' display driver's GUID
    Call DirectDrawCreate(ByVal 0&, dDraw, Nothing)
    
    ' Set the FullScreen, Rebootable, Exclusive mode...
    Call dDraw.SetCooperativeLevel(Me.hwnd, DDSCL_EXCLUSIVE Or DDSCL_FULLSCREEN Or DDSCL_ALLOWREBOOT)
    
    ' Set display mode to 640x480 mode...
    Call dDraw.SetDisplayMode(640, 480, BPP, 0, 0)

    ' Now create a Front buffer
    With ddsd
        .dwSize = Len(ddsd)
        .dwFlags = DDSD_CAPS Or DDSD_BACKBUFFERCOUNT
        .DDSCAPS.dwCaps = DDSCAPS_PRIMARYSURFACE Or DDSCAPS_FLIP Or DDSCAPS_COMPLEX Or DDSCAPS_SYSTEMMEMORY
        ' Back buffer
        .dwBackBufferCount = 1
    End With
    
    ' Create the front buffer
    Call dDraw.CreateSurface(ddsd, ddsPrimary, Nothing)
    
    ' Fill out DDSCAPS struct
    ddc.dwCaps = DDSCAPS_BACKBUFFER
    
    ' Get the back buffer
    Call ddsPrimary.GetAttachedSurface(ddc, ddsBack1)
    'Call ddsPrimary.GetAttachedSurface(ddc, ddsBack2)
    
    'set up character buffer surface
    With ddsd
        .dwSize = Len(ddsd)
        .dwFlags = DDSD_CAPS Or DDSD_WIDTH Or DDSD_HEIGHT
        .DDSCAPS.dwCaps = DDSCAPS_OFFSCREENPLAIN Or DDSCAPS_SYSTEMMEMORY
        .dwWidth = 192
        .dwHeight = 192
    End With
    Call dDraw.CreateSurface(ddsd, ddsChars, Nothing)
    
    TwipsX = Screen.TwipsPerPixelX
    TwipsY = Screen.TwipsPerPixelY
    
    'set up the offscreen char buffer with images
    Dim iDir As Integer
    Dim iAnim As Integer
    Call ddsChars.GetDC(hdcChar)
    For i = 1 To imlGuy.ListImages.Count
        imlGuy.ListImages(i).Draw hdcChar, iAnim * 48 * TwipsX, iDir * 48 * TwipsY
        iAnim = iAnim + 1 'next animation cell
        If iAnim = 4 Then 'currently 4 animations per direction
            iDir = iDir + 1 'next direction (up,down,left,right)
            iAnim = 0       'first animation cell for the direction
        End If
    Next i
    Call ddsChars.ReleaseDC(hdcChar) 'don't forget to do this!
    
    
    'set up indexed tile buffer
    With ddsd
        .dwSize = Len(ddsd)
        .dwFlags = DDSD_CAPS Or DDSD_WIDTH Or DDSD_HEIGHT
        .DDSCAPS.dwCaps = DDSCAPS_OFFSCREENPLAIN Or DDSCAPS_SYSTEMMEMORY
        .dwWidth = 640  'holds up to 20 tiles - for now
        .dwHeight = 32
    End With
    Call dDraw.CreateSurface(ddsd, ddsTiles, Nothing)
    
    '// set up double-buffered floor surface //
    'Buffer has a two tile (64 pixel) border around
    'the 640x480 screen area.  New tiles are drawn to
    'the outer border in the direction the main character
    'is moving
    With ddsd
        .dwSize = Len(ddsd)
        .dwFlags = DDSD_CAPS Or DDSD_WIDTH Or DDSD_HEIGHT
        .DDSCAPS.dwCaps = DDSCAPS_OFFSCREENPLAIN Or DDSCAPS_SYSTEMMEMORY
        .dwWidth = 768  '64+640+64
        .dwHeight = 608 '64+480+64
    End With
    Call dDraw.CreateSurface(ddsd, ddsFloor, Nothing)
    
    'make white the transparent color for the chars buffer
    ClrKey.dwColorSpaceHighValue = RGB(255, 255, 255)
    ClrKey.dwColorSpaceLowValue = RGB(255, 255, 255)
    ddsChars.SetColorKey DDCKEY_SRCBLT, ClrKey
    
    'tmrMain.Enabled = True
    
End Sub

Private Sub Form_QueryUnload(Cancel As Integer, UnloadMode As Integer)
    
    If UnloadMode <> 1 Then ' Form_Unload event didn't occur
        ' Restore the display mode back...
        Call dDraw.RestoreDisplayMode
        Call dDraw.SetCooperativeLevel(0, DDSCL_NORMAL) ' Restore to normal screen
        
        ' Set the DirectDraw Objects to Nothing... VERY VERY IMPORTANT!
        Set ddsChars = Nothing
        Set ddsTiles = Nothing
        Set ddsFloor = Nothing
        Set ddsBack1 = Nothing   ' First release the back buffer
        Set ddsPrimary = Nothing ' And then release the front buffer
        Set dDraw = Nothing
        
        ' End the program
        End
    End If
End Sub

Private Sub Form_Unload(Cancel As Integer)
    
    ' Restore the display mode back...
    Call dDraw.RestoreDisplayMode
    Call dDraw.SetCooperativeLevel(0, DDSCL_NORMAL) ' Restore to normal screen
    
    ' Set the DirectDraw Objects to Nothing... VERY VERY IMPORTANT!
    Set ddsChars = Nothing   'character animation buffer
    Set ddsTiles = Nothing   'tile set buffer
    Set ddsFloor = Nothing   'scroll area buffer
    Set ddsBack1 = Nothing   'First release the back buffer
    Set ddsPrimary = Nothing 'And then release the front buffer
    Set dDraw = Nothing
    
    ' End the program
    End
End Sub


Private Sub tmrMain_Timer()
    
    On Error GoTo ErrorTimer
    Static bDrawing As Boolean
    
    If bDrawing Then Exit Sub
    bDrawing = True
    
    Dim rcBig As RECT
    Dim rcChar As RECT
    Dim lOffsetX As Integer
    Dim lOffsetY As Integer
    Dim iDestTile As Integer
    Dim iAnim As Integer 'character movement animation frame
    
    '// start of main drawing routine //
    Do
        'allow change of direction only after full movement cycle
        If miStep = 0 Then
            If mbPendingLeft Then
                miDirX = -1
                meFaceDir = dirLeft
            ElseIf mbPendingRight Then
                miDirX = 1
                meFaceDir = dirRight
            ElseIf mbPendingUp Then
                miDirY = -1
                meFaceDir = dirUp
            ElseIf mbPendingDown Then
                miDirY = 1
                meFaceDir = dirDown
            End If
            
            'check destination tile behavior
            iDestTile = Map1(miBaseX + 8 + miDirX, miBaseY + 6 + miDirY)
            If TileBehavior(iDestTile) = "" Or TileBehavior(iDestTile) = "NoGo" Then
                miDirX = 0
                miDirY = 0
            End If
            'other tile behaviors could be checked here
            '(doors, chests, ladders, etc.)
        End If
        
        
        If miDirX Or miDirY Then
            miStep = miStep + 1
            If miStep = 1 Then
                
                'these BaseX,Y checks aren't necessary if map
                'is bordered by NoGo tiles
                miBaseX = miBaseX + miDirX
                If miBaseX < -8 Then
                    miDirX = 0
                    miBaseX = -8
                End If
                If miBaseX > MapSizeX - 9 Then
                    miDirX = 0
                    miBaseX = MapSizeX - 9
                End If
            
                miBaseY = miBaseY + miDirY
                If miBaseY < -6 Then
                    miDirY = 0
                    miBaseY = -6
                End If
                If miBaseY > MapSizeY - 7 Then
                    miDirY = 0
                    miBaseY = MapSizeY - 7
                End If
            End If
        Else
            miStep = 0
        End If
        
        'calculate visible screen offset from floor buffer
        '8 steps of 4 pixels = move char one 32 pixel tile
        lOffsetX = miStep * 4 * miDirX
        lOffsetY = miStep * 4 * miDirY
        
        'tile source surface area to blt
        rcBig.Left = lOffsetX + 32
        rcBig.Top = lOffsetY + 32
        rcBig.Right = lOffsetX + 639 + 32
        rcBig.Bottom = lOffsetY + 479 + 32
        'Debug.Print lOffsetX, lOffsetY
        
        'chars source surface area to blt
        'pick the next animation frame for the
        'direction the character is moving
        iAnim = miStep Mod 4 'four char animation frames
        With rcChar
            .Left = iAnim * 48
            .Right = .Left + 48
            'each direction's animation is on a different
            'row in the Char buffer
            .Top = (meFaceDir - 1) * 48
            .Bottom = .Top + 48
        End With
        
        'draw floor to hidden back buffer
        ddsBack1.BltFast 0, 0, ddsFloor, rcBig, DDBLTFAST_WAIT Or DDBLTFAST_NOCOLORKEY
        'draw main char to back buffer at center of screen
        ddsBack1.BltFast 280, 210, ddsChars, rcChar, DDBLTFAST_WAIT Or DDBLTFAST_SRCCOLORKEY
        
        If mbShowStats Then ShowStatBox
        
        'copy fully-drawn back buffer to primary surface
        'done in one fell swoop to insure
        'flicker-free animation
        rcBig.Top = 0
        rcBig.Left = 0
        rcBig.Bottom = 479
        rcBig.Right = 639
        ddsPrimary.BltFast 0, 0, ddsBack1, rcBig, DDBLTFAST_WAIT Or DDBLTFAST_NOCOLORKEY
        
        If miStep >= 8 Then
            'character has just finished taking one full
            'step (moved 32 pixels)
        
            'take visible portion of map and
            'center it on the floor buffer
            'and update the outer edge of the
            'floor buffer with new tile images
            'in the direction of movement
            
            If miDirX = 1 Then  'finished moving right
                rcBig.Top = 0
                rcBig.Bottom = 64 + 479 + 64
                rcBig.Left = 32
                rcBig.Right = 64 + 639 + 64
                ddsFloor.BltFast 0, 0, ddsFloor, rcBig, DDBLTFAST_WAIT Or DDBLTFAST_NOCOLORKEY
                DrawZBuffer dirRight
                
            ElseIf miDirX = -1 Then 'finished moving left
                rcBig.Top = 0
                rcBig.Bottom = 64 + 479 + 64
                rcBig.Left = 0
                rcBig.Right = 64 + 639 + 32
                ddsFloor.BltFast 32, 0, ddsFloor, rcBig, DDBLTFAST_WAIT Or DDBLTFAST_NOCOLORKEY
                DrawZBuffer dirLeft
                
            ElseIf miDirY = 1 Then 'finished moving down
                rcBig.Top = 32
                rcBig.Bottom = 64 + 479 + 64
                rcBig.Left = 0
                rcBig.Right = 64 + 639 + 64
                ddsFloor.BltFast 0, 0, ddsFloor, rcBig, DDBLTFAST_WAIT Or DDBLTFAST_NOCOLORKEY
                DrawZBuffer dirDown
                
            ElseIf miDirY = -1 Then 'finished moving up
                rcBig.Top = 0
                rcBig.Bottom = 64 + 479 + 32
                rcBig.Left = 0
                rcBig.Right = 64 + 639 + 64
                ddsFloor.BltFast 0, 32, ddsFloor, rcBig, DDBLTFAST_WAIT Or DDBLTFAST_NOCOLORKEY
                DrawZBuffer dirUp
                            
            End If
                    
            miDirX = 0
            miDirY = 0
            miStep = 0  'reset character step counter
            bDrawing = False
            DoEvents
        End If
        
        bDrawing = False
        DoEvents
    Loop While mbRunning = True
    Unload Me
    Exit Sub
    
ErrorTimer:
    MsgBox Err.Description, , "tmrMain_Timer ERROR"
    Unload Me
End Sub

Private Sub DrawZBuffer(DrawSide As EDirection)
    
    '// updates the floor scrolling buffer //
    'new floor tiles are drawn on the outer
    'edge of the buffer in the direction of
    'character movement
    
    On Error GoTo ErrorDrawZ
    Dim iMapX As Integer
    Dim iMapY As Integer
    Dim x As Long
    Dim y As Long
    Dim iTile As Integer
    Dim hdcFloor As Long
    Dim rcTile As RECT
    
    'Call ddsFloor.GetDC(hdcFloor)
    
    'default to blank tile square
    rcTile.Top = 0
    rcTile.Bottom = 32
    
    Select Case DrawSide
        Case dirRight
            'right side buffer
            For y = -2 To 16
                iMapX = miBaseX + 21
                iMapY = miBaseY + y
                rcTile.Left = 0  'default to blank tile
                rcTile.Right = 32
                'make sure map location is within map boundaries
                If iMapX >= 0 And iMapX < MapSizeX And iMapY >= 0 And iMapY < MapSizeY Then
                    iTile = Map1(iMapX, iMapY)
                    If iTile >= 0 Then
                        'use faster BltFast routine later!!!!
                        'imlFloorTiles.ListImages(iTile).Draw hdcFloor, (64 + 639 + 32) * TwipsX, (y + 2) * 32 * TwipsY
                        rcTile.Left = iTile * 32
                        rcTile.Right = (iTile * 32) + 32
                    End If
                End If
                ddsFloor.BltFast 735, (y + 2) * 32, ddsTiles, rcTile, DDBLTFAST_WAIT Or DDBLTFAST_NOCOLORKEY
            Next y
        
        Case dirLeft
            'left side buffer
            For y = -2 To 16
                iMapX = miBaseX - 2
                iMapY = miBaseY + y
                rcTile.Left = 0  'default to blank tile
                rcTile.Right = 32
                'make sure map location is within map boundaries
                If iMapX >= 0 And iMapX < MapSizeX And iMapY >= 0 And iMapY < MapSizeY Then
                    iTile = Map1(iMapX, iMapY)
                    If iTile >= 0 Then
                        'use faster BltFast routine later!!!!
                        'imlFloorTiles.ListImages(iTile).Draw hdcFloor, 0, (y + 2) * 32 * TwipsY
                        rcTile.Left = iTile * 32
                        rcTile.Right = (iTile * 32) + 32
                    End If
                End If
                ddsFloor.BltFast 0, (y + 2) * 32, ddsTiles, rcTile, DDBLTFAST_WAIT Or DDBLTFAST_NOCOLORKEY
            Next y
            
        Case dirDown
            For x = -2 To 21
                iMapX = miBaseX + x
                iMapY = miBaseY + 16
                rcTile.Left = 0  'default to blank tile
                rcTile.Right = 32
                'make sure map location is within map boundaries
                If iMapX >= 0 And iMapX < MapSizeX And iMapY >= 0 And iMapY < MapSizeY Then
                    iTile = Map1(iMapX, iMapY)
                    If iTile >= 0 Then
                        'use faster BltFast routine later!!!!
                        'imlFloorTiles.ListImages(iTile).Draw hdcFloor, (x + 2) * 32 * TwipsX, (64 + 479 + 32) * TwipsY
                        rcTile.Left = iTile * 32
                        rcTile.Right = (iTile * 32) + 32
                    End If
                End If
                ddsFloor.BltFast (x + 2) * 32, 64 + 479 + 32, ddsTiles, rcTile, DDBLTFAST_WAIT Or DDBLTFAST_NOCOLORKEY
            Next x
            
        Case dirUp
            For x = -2 To 21
                iMapX = miBaseX + x
                iMapY = miBaseY - 2
                rcTile.Left = 0  'default to blank tile
                rcTile.Right = 32
                'make sure map location is within map boundaries
                If iMapX >= 0 And iMapX < MapSizeX And iMapY >= 0 And iMapY < MapSizeY Then
                    iTile = Map1(iMapX, iMapY)
                    If iTile >= 0 Then
                        'use faster BltFast routine later!!!!
                        'imlFloorTiles.ListImages(iTile).Draw hdcFloor, (x + 2) * 32 * TwipsX, 0
                        rcTile.Left = iTile * 32
                        rcTile.Right = (iTile * 32) + 32
                    End If
                End If
                ddsFloor.BltFast (x + 2) * 32, 0, ddsTiles, rcTile, DDBLTFAST_WAIT Or DDBLTFAST_NOCOLORKEY
            Next x
            
    End Select
    'Call ddsFloor.ReleaseDC(hdcFloor)
    Exit Sub
    
ErrorDrawZ:
    MsgBox Err.Description, , "DrawZBuffer ERROR"
    'Call ddsFloor.ReleaseDC(hdcFloor)
    Unload Me
End Sub

Private Sub FillTileBuffer()
    
    '// loads the tileset pictures into the DD Tiles buffer //
    
    On Error GoTo ErrorFillTile
    Dim i As Integer
    Dim iMaxTiles As Integer
    Dim hdcTiles As Long
    
    'first tile (#0) is always a blank square
    
    Call ddsTiles.GetDC(hdcTiles)
    iMaxTiles = imlFloorTiles.ListImages.Count
    For i = 1 To iMaxTiles
        imlFloorTiles.ListImages(i).Draw hdcTiles, i * 32 * TwipsX, 0
    Next i
    Call ddsTiles.ReleaseDC(hdcTiles)
    Exit Sub
    
ErrorFillTile:
    MsgBox Err.Description, , "FillTileBuffer ERROR"
    Call ddsFloor.ReleaseDC(hdcTiles)
    Unload Me
End Sub


Private Sub FillFloorBuffer(ByVal VisibleBaseX As Long, ByVal VisibleBaseY As Long)
    
    'sets up the floor buffer with tile images for the
    'current map area
    
    On Error GoTo ErrorFillFloor
    Dim x As Long
    Dim y As Long
    Dim iMapX As Integer
    Dim iMapY As Integer
    Dim iTile As Integer
    Dim iMaxTile As Integer
    Dim rcTile As RECT
    
    iMaxTile = imlFloorTiles.ListImages.Count
    TwipsX = Screen.TwipsPerPixelX
    TwipsY = Screen.TwipsPerPixelY
    
    rcTile.Top = 0
    rcTile.Bottom = 32
    
    For x = -2 To 21
        For y = -2 To 16
            iMapX = VisibleBaseX + x
            iMapY = VisibleBaseY + y
            rcTile.Left = 0  'default to blank tile
            rcTile.Right = 32
            If iMapX >= 0 And iMapX < MapSizeX And iMapY >= 0 And iMapY < MapSizeY Then
                iTile = Map1(iMapX, iMapY)
                If iTile > 0 And iTile <= iMaxTile Then
                    rcTile.Left = iTile * 32
                    rcTile.Right = iTile * 32 + 32
                     'imlFloorTiles.ListImages(iTile).Draw hdcFloor, (x + 2) * 32 * TwipsX, (y + 2) * 32 * TwipsY
                End If
            End If
            ddsFloor.BltFast (x + 2) * 32, (y + 2) * 32, ddsTiles, rcTile, DDBLTFAST_WAIT Or DDBLTFAST_NOCOLORKEY
        Next y
    Next x
    Exit Sub
    
ErrorFillFloor:
    MsgBox Err.Description, , "FillFloorBuffer ERROR"
    Unload Me
End Sub

Private Sub ShowStatBox()
    
    'displays a blue box with various character/game stats
    'in the lower left-hand corner of the screen
    
    On Error GoTo ErrorShowStat
    Dim hdcBack As Long ' Back buffer's DC
    Dim lpString As String
    Dim hndPen As Long
    Dim hndBrush As Long
    Dim oldpen As Long
    Dim oldbrush As Long
    Dim di As Long
    Dim rcBox As RECT

    
    ' DON'T BREAK THE CODE ON THE FOLLOWING LINES!!
    ' Get the DC of the back buffer
    Call ddsBack1.GetDC(hdcBack)
    
    ' You can break the code from here on!
    
    ' Set the back color and text color
    Call SetBkColor(hdcBack, vbBlue)
    Call SetTextColor(hdcBack, vbWhite)
    
    'create a white pen for drawing the box border
    hndPen = CreatePen(PS_SOLID, 2, vbWhite)
    If hndPen <> 0 Then oldpen = SelectObject(hdcBack, hndPen)
    
    With rcBox
        .Top = 360
        .Left = 20
        .Bottom = 470
        .Right = 200
        
        'draw stats box outline
        Rectangle hdcBack, .Left - 1, .Top - 1, .Right + 1, .Bottom + 1
        'restore original pen
        If oldpen <> 0 Then di = SelectObject(hdcBack, oldpen)
        
        'create blue brush to fill box with
        hndBrush = CreateSolidBrush(vbBlue)
        If hndBrush <> 0 Then oldbrush = SelectObject(hdcBack, hndBrush)
        'draw blue box
        FillRect hdcBack, rcBox, hndPen
        'restore old brush
        If oldbrush <> 0 Then di = SelectObject(hdcBack, oldbrush)
        
        'print stats information
        lpString = "Studly's Stats"
        Call TextOut(hdcBack, .Left + 8, .Top + 8, lpString, Len(lpString))
        lpString = "HP:  0128 / 0256"
        Call TextOut(hdcBack, .Left + 8, .Top + 32, lpString, Len(lpString))
        lpString = "X: " & Str$(miBaseX + 8) & "   Y: " & Str$(miBaseY + 6)
        Call TextOut(hdcBack, .Left + 8, .Top + 56, lpString, Len(lpString))
    End With
    
    ' delete drawing objects and release the DC's, very important!!
    If hndPen Then di = DeleteObject(hndPen)
    If hndBrush Then di = DeleteObject(hndBrush)
    Call ddsBack1.ReleaseDC(hdcBack)
    Exit Sub
    
ErrorShowStat:
    MsgBox Err.Description, , "ShowStatBox ERROR"
    If hndPen Then di = DeleteObject(hndPen)
    If hndBrush Then di = DeleteObject(hndBrush)
    Call ddsBack1.ReleaseDC(hdcBack)
    Unload Me
End Sub
