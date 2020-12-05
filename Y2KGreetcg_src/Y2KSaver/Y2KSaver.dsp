# Microsoft Developer Studio Project File - Name="Y2KSaver" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=Y2KSaver - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Y2KSaver.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Y2KSaver.mak" CFG="Y2KSaver - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Y2KSaver - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Y2KSaver - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Y2KSaver - Win32 Release"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "..\common" /I "..\Y2KSaver" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /i "..\common" /i "..\Y2KSaver" /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 winmm.lib vfw32.lib opengl32.lib glaux.lib glu32.lib /nologo /subsystem:windows /machine:I386 /out:"Release/Y2KSaver.scr"

!ELSEIF  "$(CFG)" == "Y2KSaver - Win32 Debug"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "..\common" /I "..\Y2KSaver" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /i "..\common" /i "..\Y2KSaver" /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 winmm.lib vfw32.lib opengl32.lib glaux.lib glu32.lib /nologo /subsystem:windows /debug /machine:I386 /out:"Debug/Y2KSaver.scr" /pdbtype:sept

!ENDIF 

# Begin Target

# Name "Y2KSaver - Win32 Release"
# Name "Y2KSaver - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\common\CMCIPlayer.cpp
# End Source File
# Begin Source File

SOURCE=..\common\glCtrl.cpp
# End Source File
# Begin Source File

SOURCE=..\common\GLFont.cpp
# End Source File
# Begin Source File

SOURCE=..\common\glFunc.cpp
# End Source File
# Begin Source File

SOURCE=..\common\glObj.cpp
# End Source File
# Begin Source File

SOURCE=..\common\glObject.cpp
# End Source File
# Begin Source File

SOURCE=.\RegKey.cpp
# End Source File
# Begin Source File

SOURCE=.\SaverWnd.cpp
# End Source File
# Begin Source File

SOURCE=.\SettingDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=..\common\xvector.cpp
# End Source File
# Begin Source File

SOURCE=.\Y2KSaver.cpp
# End Source File
# Begin Source File

SOURCE=.\Y2KSaver.rc
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\common\CMCIPlayer.h
# End Source File
# Begin Source File

SOURCE=..\common\glConstant.h
# End Source File
# Begin Source File

SOURCE=..\common\glCtrl.h
# End Source File
# Begin Source File

SOURCE=..\common\gldef.h
# End Source File
# Begin Source File

SOURCE=..\common\GLFont.h
# End Source File
# Begin Source File

SOURCE=..\common\glFunc.h
# End Source File
# Begin Source File

SOURCE=..\common\glObj.h
# End Source File
# Begin Source File

SOURCE=..\common\glObjdef.h
# End Source File
# Begin Source File

SOURCE=.\RegKey.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\SaverWnd.h
# End Source File
# Begin Source File

SOURCE=.\SettingDlg.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=..\common\xvector.h
# End Source File
# Begin Source File

SOURCE=.\Y2KSaver.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\cursor1.cur
# End Source File
# Begin Source File

SOURCE=.\res\Y2KSaver.ico
# End Source File
# Begin Source File

SOURCE=.\res\Y2KSaver.rc2
# End Source File
# End Group
# Begin Source File

SOURCE=.\res\dot.dat
# End Source File
# Begin Source File

SOURCE=.\res\face4.dat
# End Source File
# Begin Source File

SOURCE=.\res\face6.dat
# End Source File
# Begin Source File

SOURCE=.\res\Mightbe.mid
# End Source File
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
