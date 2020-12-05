; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CAboutDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "greet.h"

ClassCount=3
Class1=CGreetApp
Class2=CGreetDlg
Class3=CAboutDlg

ResourceCount=5
Resource1=IDD_GREET_DIALOG (English (U.S.))
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX
Resource4=IDD_ABOUTBOX (English (U.S.))
Resource5=IDD_GREET_DIALOG

[CLS:CGreetApp]
Type=0
HeaderFile=greet.h
ImplementationFile=greet.cpp
Filter=N

[CLS:CGreetDlg]
Type=0
HeaderFile=greetDlg.h
ImplementationFile=greetDlg.cpp
Filter=D
LastObject=CGreetDlg
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=greetDlg.h
ImplementationFile=greetDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=8
Control1=IDC_STATIC,static,1342308480
Control2=IDC_STATIC,static,1342308352
Control3=IDOK,button,1342373889
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1350572558
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,button,1342177287
Control8=IDC_STATIC,static,1342308352

[DLG:IDD_GREET_DIALOG]
Type=1
Class=CGreetDlg
ControlCount=1
Control1=IDC_IMAGE,static,1342308352

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=?
ControlCount=5
Control1=IDC_STATIC,static,1342181390
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Control5=IDC_STATIC,static,1342308352

[DLG:IDD_GREET_DIALOG (English (U.S.))]
Type=1
Class=?
ControlCount=1
Control1=IDC_IMAGE,static,1342308352

