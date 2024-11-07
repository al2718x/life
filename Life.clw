; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CFieldDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Life.h"
LastPage=0

ClassCount=6
Class1=CLifeApp
Class2=CLifeDoc
Class3=CLifeView
Class4=CMainFrame

ResourceCount=5
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class5=CAboutDlg
Resource3=IDD_FIELDDIALOG
Resource4=IDD_ABOUTBOX (English (U.S.))
Class6=CFieldDlg
Resource5=IDR_MAINFRAME (English (U.S.))

[CLS:CLifeApp]
Type=0
HeaderFile=Life.h
ImplementationFile=Life.cpp
Filter=N

[CLS:CLifeDoc]
Type=0
HeaderFile=LifeDoc.h
ImplementationFile=LifeDoc.cpp
Filter=N
LastObject=CLifeDoc
BaseClass=CDocument
VirtualFilter=DC

[CLS:CLifeView]
Type=0
HeaderFile=LifeView.h
ImplementationFile=LifeView.cpp
Filter=C
BaseClass=CScrollView
VirtualFilter=VWC
LastObject=ID_FILE_RELOAD


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=ID_TOOLS_SETUP




[CLS:CAboutDlg]
Type=0
HeaderFile=Life.cpp
ImplementationFile=Life.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Class=CAboutDlg

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_MRU_FILE1
Command6=ID_APP_EXIT
Command10=ID_EDIT_PASTE
Command11=ID_VIEW_TOOLBAR
Command12=ID_VIEW_STATUS_BAR
Command13=ID_APP_ABOUT
CommandCount=13
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command7=ID_EDIT_UNDO
Command8=ID_EDIT_CUT
Command9=ID_EDIT_COPY

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command5=ID_EDIT_CUT
Command6=ID_EDIT_COPY
Command7=ID_EDIT_PASTE
Command8=ID_EDIT_UNDO
Command9=ID_EDIT_CUT
Command10=ID_EDIT_COPY
Command11=ID_EDIT_PASTE
Command12=ID_NEXT_PANE
CommandCount=13
Command4=ID_EDIT_UNDO
Command13=ID_PREV_PANE


[TB:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_RELOAD
Command4=ID_FILE_SAVE
Command5=ID_FILE_SAVE_AS
Command6=ID_TOOLS_SETUP
Command7=ID_TOOLS_DEFAULT
Command8=ID_TOOLS_CLEAR
Command9=ID_TOOLS_RANDOMFILL
Command10=ID_TOOLS_FLIPHORIZONTAL
Command11=ID_TOOLS_FLIPVERTICAL
Command12=ID_TOOLS_SELECT
Command13=ID_TOOLS_GO
Command14=ID_TOOLS_RUN
Command15=ID_TOOLS_STOP
Command16=ID_APP_ABOUT
Command17=ID_HELP_HELP
CommandCount=17

[MNU:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_RELOAD
Command4=ID_FILE_SAVE
Command5=ID_FILE_SAVE_AS
Command6=ID_FILE_MRU_FILE1
Command7=ID_APP_EXIT
Command8=ID_VIEW_TOOLBAR
Command9=ID_VIEW_STATUS_BAR
Command10=ID_VIEW_REFRESH
Command11=ID_TOOLS_SETUP
Command12=ID_TOOLS_DEFAULT
Command13=ID_TOOLS_CLEAR
Command14=ID_TOOLS_RANDOMFILL
Command15=ID_TOOLS_FLIPHORIZONTAL
Command16=ID_TOOLS_FLIPVERTICAL
Command17=ID_TOOLS_SELECT
Command18=ID_TOOLS_GO
Command19=ID_TOOLS_RUN
Command20=ID_TOOLS_STOP
Command21=ID_APP_ABOUT
Command22=ID_HELP_HELP
CommandCount=22

[ACL:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_RELOAD
Command4=ID_FILE_SAVE
Command5=ID_TOOLS_CLEAR
Command6=ID_TOOLS_STOP
Command7=ID_HELP_HELP
Command8=ID_APP_ABOUT
Command9=ID_FILE_SAVE
Command10=ID_FILE_OPEN
Command11=ID_VIEW_REFRESH
Command12=ID_TOOLS_SETUP
Command13=ID_TOOLS_GO
Command14=ID_TOOLS_RUN
Command15=ID_FILE_CLOSE
CommandCount=15

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_FIELDDIALOG]
Type=1
Class=CFieldDlg
ControlCount=22
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_X,edit,1350631552
Control7=IDC_Y,edit,1350631552
Control8=IDC_SIZEXY,edit,1350631552
Control9=IDC_INTERVAL,edit,1350631552
Control10=IDC_STEP,edit,1350631552
Control11=IDC_COLORGRID,button,1342242816
Control12=IDC_COLORVOID,button,1342242816
Control13=IDC_COLORDEAD,button,1342242816
Control14=IDC_COLORBORN,button,1342242816
Control15=IDC_COLORLIVE,button,1342242816
Control16=IDC_PAINTBG,button,1342242819
Control17=IDC_GRID,button,1342242819
Control18=IDC_RECT,button,1342242819
Control19=IDC_TRACE,button,1342242819
Control20=IDC_TORUS,button,1342242819
Control21=IDCANCEL,button,1342242816
Control22=IDOK,button,1342242817

[CLS:CFieldDlg]
Type=0
HeaderFile=FieldDlg.h
ImplementationFile=FieldDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CFieldDlg
VirtualFilter=dWC

