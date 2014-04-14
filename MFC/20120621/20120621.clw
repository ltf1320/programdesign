; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMainFrame
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "20120621.h"
LastPage=0

ClassCount=7
Class1=CMy20120621App
Class2=CMy20120621Doc
Class3=CMy20120621View
Class4=CMainFrame

ResourceCount=4
Resource1=IDR_MAINFRAME
Class5=CAboutDlg
Resource2=IDD_ABOUTBOX
Class6=Dialog
Resource3=IDD_DIALOG_killMomo
Class7=Dialog2
Resource4=IDD_DIALOG1

[CLS:CMy20120621App]
Type=0
HeaderFile=20120621.h
ImplementationFile=20120621.cpp
Filter=N

[CLS:CMy20120621Doc]
Type=0
HeaderFile=20120621Doc.h
ImplementationFile=20120621Doc.cpp
Filter=N

[CLS:CMy20120621View]
Type=0
HeaderFile=20120621View.h
ImplementationFile=20120621View.cpp
Filter=C


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=IDE_Jiecheng




[CLS:CAboutDlg]
Type=0
HeaderFile=20120621.cpp
ImplementationFile=20120621.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_APP_ABOUT
Command17=ID_Momo_kill
Command18=IDE_Jiecheng
CommandCount=18

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[CLS:Dialog]
Type=0
HeaderFile=Dialog.h
ImplementationFile=Dialog.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=Dialog

[DLG:IDD_DIALOG_killMomo]
Type=1
Class=Dialog
ControlCount=5
Control1=IDCANCEL,button,1342242816
Control2=IDC_N2,edit,1350631552
Control3=IDC_N1,edit,1350631552
Control4=IDC_N3,edit,1350631552
Control5=IDC_Start,button,1342242816

[DLG:IDD_DIALOG1]
Type=1
Class=Dialog2
ControlCount=4
Control1=IDCANCEL,button,1342242816
Control2=IDC_CAL,button,1342242816
Control3=IDC_N1,edit,1350631552
Control4=IDC_N2,edit,1350631552

[CLS:Dialog2]
Type=0
HeaderFile=Dialog2.h
ImplementationFile=Dialog2.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_CAL
VirtualFilter=dWC

