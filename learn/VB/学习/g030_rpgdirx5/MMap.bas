Attribute VB_Name = "MMap"
Option Explicit

Function OpenMap(ByVal OpenFilename As String) As Boolean
    
    'loads a saved map from disk
    
    On Error GoTo ErrorOpenMap
    Dim iFree As Integer
    Dim x As Integer
    Dim y As Integer
    Dim sTSname As String
    Dim sTSfile As String
    Dim sOLname As String
    Dim sOLfile As String
    
    
    iFree = FreeFile
    Open OpenFilename For Input As #iFree
    Input #iFree, MapNumber, MapSizeX, MapSizeY, MapLayers
    'these may be commented out if you don't play to use
    'the 'Load associated tile set option'
    Input #iFree, sTSname, sTSfile
    Input #iFree, sOLname, sOLfile
    
    'resize and clear out the map arrays
    ReDim Map1(MapSizeX, MapSizeY)
    ReDim Map2(MapSizeX, MapSizeY)
    
    For y = 0 To MapSizeY - 1
        For x = 0 To MapSizeX - 1
            Input #iFree, Map1(x, y)
        Next x
    Next y
    
    If MapLayers > 1 Then
        'overlay layer has been saved with map data
        'EnableOverlay = True
        For y = 0 To MapSizeY - 1
            For x = 0 To MapSizeX - 1
                Input #iFree, Map2(x, y)
            Next x
        Next y
    Else
        'EnableOverlay = False
    End If
    Close #iFree
    OpenMap = True 'success
    
    'check for tile set in current directory
    If OpenTileSet(App.Path & "\" & sTSname) = False Then
        'check for tile set in full path name
        OpenTileSet (sTSfile)
    End If
    Exit Function
    
ErrorOpenMap:
    Debug.Print Err.Description, vbExclamation
    OpenMap = False
End Function

Function OpenTileSet(ByVal SetFileName As String) As Boolean
    
    On Error GoTo ErrorOpenTile
    Dim iFree As Integer
    Dim iTotTiles As Integer
    Dim i As Integer
    Dim x As Integer
    Dim y As Integer
    Dim sKey As String
    Dim sTag As String
    
    iFree = FreeFile
    Open SetFileName For Input As #iFree
    
    With frmTestX.imlFloorTiles
        .ListImages.Clear
        Input #iFree, iTotTiles
        ReDim TileBehavior(iTotTiles)
        For i = 1 To iTotTiles
            Input #iFree, sKey, sTag
            If Not ReadBitmap(iFree, frmTestX.picHidden, x, y) Then
                Err.Raise 75 'file/path access error
            End If
            If i = 1 Then
                .ImageWidth = x
                .ImageHeight = y
            End If
            Set frmTestX.picHidden.Picture = frmTestX.picHidden.Image
            .ListImages.Add i, sKey, frmTestX.picHidden.Picture
            .ListImages(i).Tag = sTag
            TileBehavior(i) = sTag
        Next i
    End With
    Close #iFree
    OpenTileSet = True
    Exit Function

ErrorOpenTile:
    Debug.Print Err.Description, vbExclamation, "OpenTileSet Error"
    OpenTileSet = False
    On Error Resume Next
    Close #iFree
End Function

Function ReadBitmap(ByVal BitFileNumber As Integer, picDest As PictureBox, Xsize As Integer, Ysize As Integer) As Boolean
    
    '// reads bitmap pixel data from previously opened file //
    
    On Error GoTo ErrorReadBitmap
    Dim x As Integer
    Dim y As Integer
    Dim ColorVal As Long
        
    Input #BitFileNumber, Xsize, Ysize
    picDest.Width = Xsize * Screen.TwipsPerPixelX
    picDest.Height = Ysize * Screen.TwipsPerPixelY
    For y = 0 To Ysize - 1
        For x = 0 To Xsize - 1
            'read pixel val from file
            Input #BitFileNumber, ColorVal
            'write pixel to picture destination
            SetPixel picDest.hdc, x, y, ColorVal
        Next x
    Next y
    
    picDest.Refresh
    ReadBitmap = True
    Exit Function

ErrorReadBitmap:
    Debug.Print Err.Description, vbExclamation
    ReadBitmap = False
End Function
