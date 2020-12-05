// GLFont.h: interface for the CGLFont class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GLFONT_H__1F38C981_2654_11D3_955D_8422F5C00000__INCLUDED_)
#define AFX_GLFONT_H__1F38C981_2654_11D3_955D_8422F5C00000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
#include "gl\gl.h"
#include "gl\glu.h"

#define FONTLIST    256

//the type of 3D Font, solid or wireframe
enum GLFontType
{
	GL_FONT_SOLID,
    GL_FONT_LINE,
};


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

	//Set the translate in X-direction of the 3D font
	void   SetXOffset(double dXOffset){m_dXOffset = dXOffset;};
	
	//Get the translate in X-direction of the 3D font
	double GetXOffset(void){ return m_dXOffset;};

	//Set the translate in Y-direction of the 3D font
	void   SetYOffset(double dYOffset){m_dYOffset = dYOffset;};
	
	//Get the translate in Y-direction of the 3D font
	double GetYOffset(void){ return m_dYOffset;};

	//Set the translate in Z-direction of the 3D font
	void   SetZOffset(double dZOffset){m_dZOffset = dZOffset;};
	
	//Get the translate in Z-direction of the 3D font
	double GetZOffset(void){ return m_dZOffset;};

	//Set the scale in X-direction of the 3D font
	void   SetXScale(double dXScale){m_dXScale = dXScale;};
	
	//Get the scale in X-direction of the 3D font
	double GetXScale(void){ return m_dXScale;};

	//Set the scale in Y-direction of the 3D font
	void   SetYScale(double dYScale){m_dYScale = dYScale;};

	//Get the scale in Y-direction of the 3D font
	double GetYScale(void){ return m_dYScale;};

	//Set the scale in Z-direction of the 3D font
	void   SetZScale(double dZScale){m_dZScale = dZScale;};
	
	//Get the scale in Z-direction of the 3D font
	double GetZScale(void){ return m_dZScale;};

	//Set the rotate around X-axis of the 3D font
	void   SetXRotate(double dXRotate){m_dXRotate = dXRotate;};

	//Get the rotate around Y-axis of the 3D font
	double GetXRotate(void){ return m_dXRotate;};

	//Set the rotate around Y-axis of the 3D font
	void   SetYRotate(double dYRotate){m_dYRotate = dYRotate;};
	
	//Get the rotate around Y-axis of the 3D font
	double GetYRotate(void){ return m_dYRotate;};

	//Set the rotate around Z-axis of the 3D font
	void   SetZRotate(double dZRotate){m_dZRotate = dZRotate;};
	
	//Get the rotate around Z-axis of the 3D font
	double GetZRotate(void){ return m_dZRotate;};

	//Set the material emission of the 3D font
	void   SetEmission(float dMEmission[4]);

	//Get the material emission of the 3D font
	void   GetEmission(float dMEmission[4]);
	
	//Set the material specular of the 3D font
	void   SetSpecular(float dMSpecular[4]);
	
	//Get the material specular of the 3D font
	void   GetSpecular(float dMSpecular[4]);
	
	//Set the material ambient of the 3D font
	void   SetAmbient(float dMAmbient[4]); 

	//Get the material ambient of the 3D font
	void   GetAmbient(float dMAmbient[4]); 
	
	//Set the material diffuse of the 3D font
	void   SetDiffuse(float dMDiffuse[4]);
	
	//Get the material diffuse of the 3D font
	void   GetDiffuse(float dMDiffuse[4]);
	
	//Set the material shininess of the 3D font
	void   SetShininess(float dMShininess);  

	//Get the material shininess of the 3D font
	void   GetShininess(float* dMShininess);  

	//Set the content string which will be displayed
	void   SetText(const char* strText){m_strText = strText;};

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
	double       m_dXOffset;     //the offset in X direction
	double       m_dYOffset;     //the offset in Y direction
	double       m_dZOffset;     //the offset in Z direction
	double       m_dXScale;      //the scale in X direction
	double       m_dYScale;      //the scale in Y direction
	double       m_dZScale;      //the scale in Z direction
    double       m_dXRotate;     //the rotation around X-axis 
    double       m_dYRotate;     //the rotation around Y-axis 
    double       m_dZRotate;     //the rotation around Z-axis 
	float        m_dMEmission[4];//the material emission of the font 
	float        m_dMSpecular[4];//the material specular of the font
	float        m_dMAmbient[4]; //the material ambient of the font
	float        m_dMDiffuse[4]; //the material diffuse of the font 
	float        m_dMShininess;  //the material diffuse of the font 
	CString      m_strText;      //the text for display
    
};

#endif // !defined(AFX_GLFONT_H__1F38C981_2654_11D3_955D_8422F5C00000__INCLUDED_)
