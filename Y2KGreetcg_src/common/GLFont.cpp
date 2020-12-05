/**********************************************************/
/*   The GLFont.cpp                                    
/*                                                         
/*   Created by Xing Zhaohui (xingzhh@yahoo.com),          
/*   june ??, 1999                                       
/*                                                        
/*   Declare the 3D OpenGL Font class 
/* 
/**********************************************************/

#include "stdafx.h"
#include "GLFont.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif


/*********************************************************/
/*                                                       */
/*                                                       */
/*                                                       */
/*             3D OpenGL font class                      */
/*                                                       */
/*                                                       */
/*                                                       */
/*********************************************************/

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CGLFont::CGLFont()
{
	m_FontType = GL_FONT_SOLID;
	m_uiListID = 0;
    m_dThick = 0.1;
}

CGLFont::~CGLFont()
{
    if(m_uiListID != 0)
        glDeleteLists(m_uiListID, FONTLIST);
}


//////////////////////////////////////////////////////////////////////
// Create the font to display the text 
//////////////////////////////////////////////////////////////////////
BOOL CGLFont::CreateFont(CDC* pDrawDC, char* fontname)
{
	m_uiListID = glGenLists(FONTLIST);

	if(pDrawDC == NULL || m_uiListID == 0)
	{
        return FALSE;
	}

	//Create the font to display
	CFont newfont;
	CFont* oldfont;
	BOOL  bresult;
	GLYPHMETRICSFLOAT gmf[FONTLIST];

	if(fontname != NULL)
	{	
        bresult = newfont.CreateFont(-12, 0, 0, 0, FW_NORMAL, 0, 0, 0, ANSI_CHARSET, 
		       OUT_TT_ONLY_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
               FF_DONTCARE|DEFAULT_PITCH, fontname);

	    //if new font failed to be created
	    if(!bresult)
		{
		    return FALSE;
		}

	    oldfont = pDrawDC->SelectObject(&newfont);
	}
	else
	{
	    oldfont = (CFont*)pDrawDC->SelectStockObject(SYSTEM_FONT);
	}

	if(m_FontType == GL_FONT_SOLID)
	{
        bresult = wglUseFontOutlines(pDrawDC->m_hDC, 0, FONTLIST, m_uiListID, 
			0.0f, (float)m_dThick, WGL_FONT_POLYGONS, gmf);	
	}
	else if(m_FontType == GL_FONT_LINE)
	{
        bresult = wglUseFontOutlines(pDrawDC->m_hDC, 0, FONTLIST, m_uiListID, 
			0.0f, (float)m_dThick, WGL_FONT_LINES, gmf);	
	}
	
	pDrawDC->SelectObject(oldfont);
	newfont.DeleteObject();
	
	if(!bresult)
	{
		return FALSE;
	}

	return TRUE;
}


//////////////////////////////////////////////////////////////////////
// display the text string
//////////////////////////////////////////////////////////////////////
void CGLFont::GLDrawText()
{
	if (m_uiListID == 0)
	{
		return;
	}

	GLsizei size = m_strText.GetLength();
	
	//display the letter
	glListBase(m_uiListID);
	glCallLists(size, GL_UNSIGNED_BYTE, (const GLvoid*)m_strText.GetBuffer(size)); 
}