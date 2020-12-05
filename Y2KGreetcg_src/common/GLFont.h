/**********************************************************/
/*   The GLFont.h                                    
/*                                                         
/*   Created by Xing Zhaohui (xingzhh@yahoo.com),          
/*   june ??, 1999                                       
/*                                                        
/*   Declare the 3D OpenGL Font class 
/* 
/**********************************************************/

#ifndef __GLFONT_H__
#define __GLFONT_H__

#include "gl\gl.h"
#include "gl\glu.h"

#define FONTLIST    256

//the type of 3D Font, solid or wireframe
enum GLFontType
{
	GL_FONT_SOLID,
    GL_FONT_LINE,
};


/*********************************************************/
/*                                                       */
/*                                                       */
/*                                                       */
/*             3D OpenGL font class                      */
/*                                                       */
/*                                                       */
/*                                                       */
/*********************************************************/
class CGLFont  
{
public:
	CGLFont();
	virtual ~CGLFont();

	//Set the 3D font type, solid or wireframe
	void   SetFontType(GLFontType FontType){m_FontType = FontType;};
	
	//Get the current 3D font type
	void   GetFontType(GLFontType* FontType){*FontType = m_FontType;};

    //Set the thickness of 3D font
	void   SetFontSize(double dThick){m_dThick = dThick;};
    
	//Get the thickness of 3D font
    void   GetFontSize(double* dThick){*dThick = m_dThick;};

	//Set the content string which will be displayed
	void   SetText(char* strText){m_strText = strText;};

	//Create the 3D font from the truetype library, fontname is
	//the Font name of truetype
	BOOL CreateFont(CDC* pDrawDC, char* fontname);
	
	//Draw the 3D Font string in screen
	void GLDrawText(void);

//Parameters
private:
	GLFontType   m_FontType;     //font type
	UINT         m_uiListID;     //the ID of the displaylist
    double       m_dThick;       //the letters thick 
	CString      m_strText;      //the text for display
};

#endif 
