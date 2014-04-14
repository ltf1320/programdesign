Attribute VB_Name = "MGlobals"
Option Explicit

Global Map1() As Integer  'map floor surface array
Global Map2() As Integer  'map overlay surface array (not used yet)

Global TileBehavior() As String  '"Go", "NoGo", "Door", etc.


Global MapSizeX As Integer
Global MapSizeY As Integer
Global MapNumber As Integer

Global MapLayers As Integer
Global EnableOverlay As Boolean

Global TwipsX As Long
Global TwipsY As Long

Public Enum EDirection
    dirNone = 0
    dirUp = 1
    dirDown = 2
    dirLeft = 3
    dirRight = 4
End Enum

Public Type TChar  'not yet implemented
    MapX As Integer  'Map1(x,y) coords
    MapY As Integer
    DirX As Integer  '-1, 0, 1 = Left, None, Right
    DirY As Integer  '-1, 0, 1 = Up, None, Down
    PicNum  As Integer
    Behave  As Integer
End Type

Dim MyGuy As TChar
