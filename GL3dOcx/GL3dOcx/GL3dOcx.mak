# Microsoft Developer Studio Generated NMAKE File, Based on GL3dOcx.dsp
!IF "$(CFG)" == ""
CFG=GL3dOcx - Win32 Debug
!MESSAGE No configuration specified. Defaulting to GL3dOcx - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "GL3dOcx - Win32 Release" && "$(CFG)" !=\
 "GL3dOcx - Win32 Debug" && "$(CFG)" != "GL3dOcx - Win32 Unicode Debug" &&\
 "$(CFG)" != "GL3dOcx - Win32 Unicode Release"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "GL3dOcx.mak" CFG="GL3dOcx - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "GL3dOcx - Win32 Release" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE "GL3dOcx - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "GL3dOcx - Win32 Unicode Debug" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE "GL3dOcx - Win32 Unicode Release" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "GL3dOcx - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\GL3dOcx.ocx" "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : "$(OUTDIR)\GL3dOcx.ocx" "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\GL3dOcx.obj"
	-@erase "$(INTDIR)\GL3dOcx.pch"
	-@erase "$(INTDIR)\GL3dOcx.res"
	-@erase "$(INTDIR)\GL3dOcx.tlb"
	-@erase "$(INTDIR)\GL3dOcxCtl.obj"
	-@erase "$(INTDIR)\GL3dOcxPpg.obj"
	-@erase "$(INTDIR)\GLFont.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\GL3dOcx.exp"
	-@erase "$(OUTDIR)\GL3dOcx.lib"
	-@erase "$(OUTDIR)\GL3dOcx.ocx"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_WINDLL" /D "_AFXDLL" /D "_USRDLL" /Fp"$(INTDIR)\GL3dOcx.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Release/
CPP_SBRS=.
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /o NUL /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\GL3dOcx.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\GL3dOcx.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=opengl32.lib glu32.lib glaux.lib /nologo /subsystem:windows /dll\
 /incremental:no /pdb:"$(OUTDIR)\GL3dOcx.pdb" /machine:I386 /def:".\GL3dOcx.def"\
 /out:"$(OUTDIR)\GL3dOcx.ocx" /implib:"$(OUTDIR)\GL3dOcx.lib" 
DEF_FILE= \
	".\GL3dOcx.def"
LINK32_OBJS= \
	"$(INTDIR)\GL3dOcx.obj" \
	"$(INTDIR)\GL3dOcx.res" \
	"$(INTDIR)\GL3dOcxCtl.obj" \
	"$(INTDIR)\GL3dOcxPpg.obj" \
	"$(INTDIR)\GLFont.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\GL3dOcx.ocx" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\Release
TargetPath=.\Release\GL3dOcx.ocx
InputPath=.\Release\GL3dOcx.ocx
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ELSEIF  "$(CFG)" == "GL3dOcx - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\GL3dOcx.ocx" "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : "$(OUTDIR)\GL3dOcx.ocx" "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\GL3dOcx.obj"
	-@erase "$(INTDIR)\GL3dOcx.pch"
	-@erase "$(INTDIR)\GL3dOcx.res"
	-@erase "$(INTDIR)\GL3dOcx.tlb"
	-@erase "$(INTDIR)\GL3dOcxCtl.obj"
	-@erase "$(INTDIR)\GL3dOcxPpg.obj"
	-@erase "$(INTDIR)\GLFont.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\GL3dOcx.exp"
	-@erase "$(OUTDIR)\GL3dOcx.ilk"
	-@erase "$(OUTDIR)\GL3dOcx.lib"
	-@erase "$(OUTDIR)\GL3dOcx.ocx"
	-@erase "$(OUTDIR)\GL3dOcx.pdb"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_WINDLL" /D "_AFXDLL" /D "_USRDLL" /Fp"$(INTDIR)\GL3dOcx.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /o NUL /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\GL3dOcx.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\GL3dOcx.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=opengl32.lib glu32.lib glaux.lib /nologo /subsystem:windows /dll\
 /incremental:yes /pdb:"$(OUTDIR)\GL3dOcx.pdb" /debug /machine:I386\
 /def:".\GL3dOcx.def" /out:"$(OUTDIR)\GL3dOcx.ocx"\
 /implib:"$(OUTDIR)\GL3dOcx.lib" /pdbtype:sept 
DEF_FILE= \
	".\GL3dOcx.def"
LINK32_OBJS= \
	"$(INTDIR)\GL3dOcx.obj" \
	"$(INTDIR)\GL3dOcx.res" \
	"$(INTDIR)\GL3dOcxCtl.obj" \
	"$(INTDIR)\GL3dOcxPpg.obj" \
	"$(INTDIR)\GLFont.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\GL3dOcx.ocx" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\Debug
TargetPath=.\Debug\GL3dOcx.ocx
InputPath=.\Debug\GL3dOcx.ocx
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ELSEIF  "$(CFG)" == "GL3dOcx - Win32 Unicode Debug"

OUTDIR=.\DebugU
INTDIR=.\DebugU
# Begin Custom Macros
OutDir=.\DebugU
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\GL3dOcx.ocx" "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : "$(OUTDIR)\GL3dOcx.ocx" "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\GL3dOcx.obj"
	-@erase "$(INTDIR)\GL3dOcx.pch"
	-@erase "$(INTDIR)\GL3dOcx.res"
	-@erase "$(INTDIR)\GL3dOcx.tlb"
	-@erase "$(INTDIR)\GL3dOcxCtl.obj"
	-@erase "$(INTDIR)\GL3dOcxPpg.obj"
	-@erase "$(INTDIR)\GLFont.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\GL3dOcx.exp"
	-@erase "$(OUTDIR)\GL3dOcx.ilk"
	-@erase "$(OUTDIR)\GL3dOcx.lib"
	-@erase "$(OUTDIR)\GL3dOcx.ocx"
	-@erase "$(OUTDIR)\GL3dOcx.pdb"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_WINDLL" /D "_AFXDLL" /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)\GL3dOcx.pch"\
 /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\DebugU/
CPP_SBRS=.
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /o NUL /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\GL3dOcx.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\GL3dOcx.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=opengl32.lib glu32.lib glaux.lib /nologo /subsystem:windows /dll\
 /incremental:yes /pdb:"$(OUTDIR)\GL3dOcx.pdb" /debug /machine:I386\
 /def:".\GL3dOcx.def" /out:"$(OUTDIR)\GL3dOcx.ocx"\
 /implib:"$(OUTDIR)\GL3dOcx.lib" /pdbtype:sept 
DEF_FILE= \
	".\GL3dOcx.def"
LINK32_OBJS= \
	"$(INTDIR)\GL3dOcx.obj" \
	"$(INTDIR)\GL3dOcx.res" \
	"$(INTDIR)\GL3dOcxCtl.obj" \
	"$(INTDIR)\GL3dOcxPpg.obj" \
	"$(INTDIR)\GLFont.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\GL3dOcx.ocx" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\DebugU
TargetPath=.\DebugU\GL3dOcx.ocx
InputPath=.\DebugU\GL3dOcx.ocx
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ELSEIF  "$(CFG)" == "GL3dOcx - Win32 Unicode Release"

OUTDIR=.\ReleaseU
INTDIR=.\ReleaseU
# Begin Custom Macros
OutDir=.\ReleaseU
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\GL3dOcx.ocx" "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : "$(OUTDIR)\GL3dOcx.ocx" "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\GL3dOcx.obj"
	-@erase "$(INTDIR)\GL3dOcx.pch"
	-@erase "$(INTDIR)\GL3dOcx.res"
	-@erase "$(INTDIR)\GL3dOcx.tlb"
	-@erase "$(INTDIR)\GL3dOcxCtl.obj"
	-@erase "$(INTDIR)\GL3dOcxPpg.obj"
	-@erase "$(INTDIR)\GLFont.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\GL3dOcx.exp"
	-@erase "$(OUTDIR)\GL3dOcx.lib"
	-@erase "$(OUTDIR)\GL3dOcx.ocx"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_WINDLL" /D "_AFXDLL" /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)\GL3dOcx.pch"\
 /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\ReleaseU/
CPP_SBRS=.
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /o NUL /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\GL3dOcx.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\GL3dOcx.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=opengl32.lib glu32.lib glaux.lib /nologo /subsystem:windows /dll\
 /incremental:no /pdb:"$(OUTDIR)\GL3dOcx.pdb" /machine:I386 /def:".\GL3dOcx.def"\
 /out:"$(OUTDIR)\GL3dOcx.ocx" /implib:"$(OUTDIR)\GL3dOcx.lib" 
DEF_FILE= \
	".\GL3dOcx.def"
LINK32_OBJS= \
	"$(INTDIR)\GL3dOcx.obj" \
	"$(INTDIR)\GL3dOcx.res" \
	"$(INTDIR)\GL3dOcxCtl.obj" \
	"$(INTDIR)\GL3dOcxPpg.obj" \
	"$(INTDIR)\GLFont.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\GL3dOcx.ocx" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\ReleaseU
TargetPath=.\ReleaseU\GL3dOcx.ocx
InputPath=.\ReleaseU\GL3dOcx.ocx
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ENDIF 

.c{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<


!IF "$(CFG)" == "GL3dOcx - Win32 Release" || "$(CFG)" ==\
 "GL3dOcx - Win32 Debug" || "$(CFG)" == "GL3dOcx - Win32 Unicode Debug" ||\
 "$(CFG)" == "GL3dOcx - Win32 Unicode Release"
SOURCE=.\GL3dOcx.cpp
DEP_CPP_GL3DO=\
	".\GL3dOcx.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\GL3dOcx.obj" : $(SOURCE) $(DEP_CPP_GL3DO) "$(INTDIR)"\
 "$(INTDIR)\GL3dOcx.pch"


SOURCE=.\GL3dOcx.odl

!IF  "$(CFG)" == "GL3dOcx - Win32 Release"

MTL_SWITCHES=/nologo /D "NDEBUG" /tlb "$(OUTDIR)\GL3dOcx.tlb" /mktyplib203 /o\
 NUL /win32 

"$(OUTDIR)\GL3dOcx.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "GL3dOcx - Win32 Debug"

MTL_SWITCHES=/nologo /D "_DEBUG" /tlb "$(OUTDIR)\GL3dOcx.tlb" /mktyplib203 /o\
 NUL /win32 

"$(OUTDIR)\GL3dOcx.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "GL3dOcx - Win32 Unicode Debug"

MTL_SWITCHES=/nologo /D "_DEBUG" /tlb "$(OUTDIR)\GL3dOcx.tlb" /mktyplib203 /o\
 NUL /win32 

"$(OUTDIR)\GL3dOcx.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "GL3dOcx - Win32 Unicode Release"

MTL_SWITCHES=/nologo /D "NDEBUG" /tlb "$(OUTDIR)\GL3dOcx.tlb" /mktyplib203 /o\
 NUL /win32 

"$(OUTDIR)\GL3dOcx.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\GL3dOcx.rc

!IF  "$(CFG)" == "GL3dOcx - Win32 Release"

DEP_RSC_GL3DOC=\
	".\GL3dOcx.ico"\
	".\GL3dOcxCtl.bmp"\
	
NODEP_RSC_GL3DOC=\
	".\Release\GL3dOcx.tlb"\
	

"$(INTDIR)\GL3dOcx.res" : $(SOURCE) $(DEP_RSC_GL3DOC) "$(INTDIR)"\
 "$(INTDIR)\GL3dOcx.tlb"
	$(RSC) /l 0x409 /fo"$(INTDIR)\GL3dOcx.res" /i "Release" /d "NDEBUG" /d\
 "_AFXDLL" $(SOURCE)


!ELSEIF  "$(CFG)" == "GL3dOcx - Win32 Debug"

DEP_RSC_GL3DOC=\
	".\GL3dOcx.ico"\
	".\GL3dOcxCtl.bmp"\
	
NODEP_RSC_GL3DOC=\
	".\Debug\GL3dOcx.tlb"\
	

"$(INTDIR)\GL3dOcx.res" : $(SOURCE) $(DEP_RSC_GL3DOC) "$(INTDIR)"\
 "$(INTDIR)\GL3dOcx.tlb"
	$(RSC) /l 0x409 /fo"$(INTDIR)\GL3dOcx.res" /i "Debug" /d "_DEBUG" /d "_AFXDLL"\
 $(SOURCE)


!ELSEIF  "$(CFG)" == "GL3dOcx - Win32 Unicode Debug"

DEP_RSC_GL3DOC=\
	".\GL3dOcx.ico"\
	".\GL3dOcxCtl.bmp"\
	
NODEP_RSC_GL3DOC=\
	".\DebugU\GL3dOcx.tlb"\
	

"$(INTDIR)\GL3dOcx.res" : $(SOURCE) $(DEP_RSC_GL3DOC) "$(INTDIR)"\
 "$(INTDIR)\GL3dOcx.tlb"
	$(RSC) /l 0x409 /fo"$(INTDIR)\GL3dOcx.res" /i "DebugU" /d "_DEBUG" /d\
 "_AFXDLL" $(SOURCE)


!ELSEIF  "$(CFG)" == "GL3dOcx - Win32 Unicode Release"

DEP_RSC_GL3DOC=\
	".\GL3dOcx.ico"\
	".\GL3dOcxCtl.bmp"\
	
NODEP_RSC_GL3DOC=\
	".\ReleaseU\GL3dOcx.tlb"\
	

"$(INTDIR)\GL3dOcx.res" : $(SOURCE) $(DEP_RSC_GL3DOC) "$(INTDIR)"\
 "$(INTDIR)\GL3dOcx.tlb"
	$(RSC) /l 0x409 /fo"$(INTDIR)\GL3dOcx.res" /i "ReleaseU" /d "NDEBUG" /d\
 "_AFXDLL" $(SOURCE)


!ENDIF 

SOURCE=.\GL3dOcxCtl.cpp
DEP_CPP_GL3DOCX=\
	".\GL3dOcx.h"\
	".\GL3dOcxCtl.h"\
	".\GL3dOcxPpg.h"\
	".\GLFont.h"\
	".\StdAfx.h"\
	{$(INCLUDE)}"gl\gl.h"\
	

"$(INTDIR)\GL3dOcxCtl.obj" : $(SOURCE) $(DEP_CPP_GL3DOCX) "$(INTDIR)"\
 "$(INTDIR)\GL3dOcx.pch"


SOURCE=.\GL3dOcxPpg.cpp
DEP_CPP_GL3DOCXP=\
	".\GL3dOcx.h"\
	".\GL3dOcxPpg.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\GL3dOcxPpg.obj" : $(SOURCE) $(DEP_CPP_GL3DOCXP) "$(INTDIR)"\
 "$(INTDIR)\GL3dOcx.pch"


SOURCE=.\GLFont.cpp
DEP_CPP_GLFON=\
	".\GLFont.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\GLFont.obj" : $(SOURCE) $(DEP_CPP_GLFON) "$(INTDIR)"\
 "$(INTDIR)\GL3dOcx.pch"


SOURCE=.\StdAfx.cpp
DEP_CPP_STDAF=\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "GL3dOcx - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_WINDLL" /D "_AFXDLL" /D "_USRDLL" /Fp"$(INTDIR)\GL3dOcx.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\GL3dOcx.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "GL3dOcx - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D\
 "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_USRDLL" /Fp"$(INTDIR)\GL3dOcx.pch"\
 /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\GL3dOcx.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "GL3dOcx - Win32 Unicode Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D\
 "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_USRDLL" /D "_UNICODE"\
 /Fp"$(INTDIR)\GL3dOcx.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD\
 /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\GL3dOcx.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "GL3dOcx - Win32 Unicode Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_WINDLL" /D "_AFXDLL" /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)\GL3dOcx.pch"\
 /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\GL3dOcx.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

