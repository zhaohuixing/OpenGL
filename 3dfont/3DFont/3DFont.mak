# Microsoft Developer Studio Generated NMAKE File, Based on 3DFont.dsp
!IF "$(CFG)" == ""
CFG=3DFont - Win32 Debug
!MESSAGE No configuration specified. Defaulting to 3DFont - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "3DFont - Win32 Release" && "$(CFG)" != "3DFont - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "3DFont.mak" CFG="3DFont - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "3DFont - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "3DFont - Win32 Debug" (based on "Win32 (x86) Application")
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

!IF  "$(CFG)" == "3DFont - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\3DFont.exe"

!ELSE 

ALL : "$(OUTDIR)\3DFont.exe"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\3DFont.obj"
	-@erase "$(INTDIR)\3DFont.pch"
	-@erase "$(INTDIR)\3DFont.res"
	-@erase "$(INTDIR)\3DFontDoc.obj"
	-@erase "$(INTDIR)\3DFontView.obj"
	-@erase "$(INTDIR)\GLFont.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\3DFont.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS"\
 /Fp"$(INTDIR)\3DFont.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD\
 /c 
CPP_OBJS=.\Release/
CPP_SBRS=.
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /o NUL /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\3DFont.res" /i "..\common" /i "..\3DFont" /d\
 "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\3DFont.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=opengl32.lib glaux.lib glu32.lib /nologo /subsystem:windows\
 /incremental:no /pdb:"$(OUTDIR)\3DFont.pdb" /machine:I386\
 /out:"$(OUTDIR)\3DFont.exe" 
LINK32_OBJS= \
	"$(INTDIR)\3DFont.obj" \
	"$(INTDIR)\3DFont.res" \
	"$(INTDIR)\3DFontDoc.obj" \
	"$(INTDIR)\3DFontView.obj" \
	"$(INTDIR)\GLFont.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\3DFont.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "3DFont - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\3DFont.exe"

!ELSE 

ALL : "$(OUTDIR)\3DFont.exe"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\3DFont.obj"
	-@erase "$(INTDIR)\3DFont.pch"
	-@erase "$(INTDIR)\3DFont.res"
	-@erase "$(INTDIR)\3DFontDoc.obj"
	-@erase "$(INTDIR)\3DFontView.obj"
	-@erase "$(INTDIR)\GLFont.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\3DFont.exe"
	-@erase "$(OUTDIR)\3DFont.ilk"
	-@erase "$(OUTDIR)\3DFont.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /Fp"$(INTDIR)\3DFont.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /o NUL /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\3DFont.res" /i "..\common" /i "..\3DFont" /d\
 "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\3DFont.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=opengl32.lib glaux.lib glu32.lib /nologo /subsystem:windows\
 /incremental:yes /pdb:"$(OUTDIR)\3DFont.pdb" /debug /machine:I386\
 /out:"$(OUTDIR)\3DFont.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\3DFont.obj" \
	"$(INTDIR)\3DFont.res" \
	"$(INTDIR)\3DFontDoc.obj" \
	"$(INTDIR)\3DFontView.obj" \
	"$(INTDIR)\GLFont.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\3DFont.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

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


!IF "$(CFG)" == "3DFont - Win32 Release" || "$(CFG)" == "3DFont - Win32 Debug"
SOURCE=.\3DFont.cpp

!IF  "$(CFG)" == "3DFont - Win32 Release"

DEP_CPP_3DFON=\
	"..\common\GLFont.h"\
	".\3DFont.h"\
	".\3DFontDoc.h"\
	".\3DFontView.h"\
	".\MainFrm.h"\
	

"$(INTDIR)\3DFont.obj" : $(SOURCE) $(DEP_CPP_3DFON) "$(INTDIR)"\
 "$(INTDIR)\3DFont.pch"


!ELSEIF  "$(CFG)" == "3DFont - Win32 Debug"

DEP_CPP_3DFON=\
	"..\common\GLFont.h"\
	".\3DFont.h"\
	".\3DFontDoc.h"\
	".\3DFontView.h"\
	".\MainFrm.h"\
	

"$(INTDIR)\3DFont.obj" : $(SOURCE) $(DEP_CPP_3DFON) "$(INTDIR)"\
 "$(INTDIR)\3DFont.pch"


!ENDIF 

SOURCE=.\3DFont.rc
DEP_RSC_3DFONT=\
	".\res\3DFont.ico"\
	".\res\3DFont.rc2"\
	".\res\3DFontDoc.ico"\
	".\res\Toolbar.bmp"\
	

"$(INTDIR)\3DFont.res" : $(SOURCE) $(DEP_RSC_3DFONT) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\3DFontDoc.cpp

!IF  "$(CFG)" == "3DFont - Win32 Release"

DEP_CPP_3DFONTD=\
	".\3DFont.h"\
	".\3DFontDoc.h"\
	

"$(INTDIR)\3DFontDoc.obj" : $(SOURCE) $(DEP_CPP_3DFONTD) "$(INTDIR)"\
 "$(INTDIR)\3DFont.pch"


!ELSEIF  "$(CFG)" == "3DFont - Win32 Debug"

DEP_CPP_3DFONTD=\
	".\3DFont.h"\
	".\3DFontDoc.h"\
	

"$(INTDIR)\3DFontDoc.obj" : $(SOURCE) $(DEP_CPP_3DFONTD) "$(INTDIR)"\
 "$(INTDIR)\3DFont.pch"


!ENDIF 

SOURCE=.\3DFontView.cpp

!IF  "$(CFG)" == "3DFont - Win32 Release"

DEP_CPP_3DFONTV=\
	"..\common\GLFont.h"\
	".\3DFont.h"\
	".\3DFontDoc.h"\
	".\3DFontView.h"\
	

"$(INTDIR)\3DFontView.obj" : $(SOURCE) $(DEP_CPP_3DFONTV) "$(INTDIR)"\
 "$(INTDIR)\3DFont.pch"


!ELSEIF  "$(CFG)" == "3DFont - Win32 Debug"

DEP_CPP_3DFONTV=\
	"..\common\GLFont.h"\
	".\3DFont.h"\
	".\3DFontDoc.h"\
	".\3DFontView.h"\
	

"$(INTDIR)\3DFontView.obj" : $(SOURCE) $(DEP_CPP_3DFONTV) "$(INTDIR)"\
 "$(INTDIR)\3DFont.pch"


!ENDIF 

SOURCE=..\common\GLFont.cpp
DEP_CPP_GLFON=\
	"..\common\GLFont.h"\
	

"$(INTDIR)\GLFont.obj" : $(SOURCE) $(DEP_CPP_GLFON) "$(INTDIR)"\
 "$(INTDIR)\3DFont.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\MainFrm.cpp

!IF  "$(CFG)" == "3DFont - Win32 Release"

DEP_CPP_MAINF=\
	".\3DFont.h"\
	".\MainFrm.h"\
	

"$(INTDIR)\MainFrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\3DFont.pch"


!ELSEIF  "$(CFG)" == "3DFont - Win32 Debug"

DEP_CPP_MAINF=\
	".\3DFont.h"\
	".\MainFrm.h"\
	

"$(INTDIR)\MainFrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\3DFont.pch"


!ENDIF 

SOURCE=.\StdAfx.cpp
DEP_CPP_STDAF=\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "3DFont - Win32 Release"

CPP_SWITCHES=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS"\
 /Fp"$(INTDIR)\3DFont.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD\
 /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\3DFont.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "3DFont - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D\
 "_WINDOWS" /D "_AFXDLL" /Fp"$(INTDIR)\3DFont.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\3DFont.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

