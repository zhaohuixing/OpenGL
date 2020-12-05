/**********************************************************/
/*   The glObjdef.h                                          
/*                                                         
/*   Created by Xing Zhaohui (xingzhh@yahoo.com),          
/*   Nov 10, 1999                                           
/*                                                        
/*   Declare the ellipsoid, word, cube objects
/* 
/**********************************************************/

#ifndef __GLOBJECTDEF__
#define __GLOBJECTDEF__
#include "glObj.h"
#include "glFont.h"
#include "glFunc.h"

#define  GT_BALL   0
#define  GT_WORD   1
#define  GT_CUBE   2
/*********************************************************/
/*                                                       */
/*                                                       */
/*                                                       */
/*                 The ellipsoid object                  */
/*                                                       */
/*                                                       */
/*                                                       */
/*********************************************************/
class glEllipsoid : public CGLBaseObject
{
public:
    glEllipsoid();
    ~glEllipsoid();

public:
	void SetSize(int row, int col);
	void SetTextureSize(int tWidth, int tHeight);
	void SetTexCoord(double rowstart, double colstart, 
		             double row, double col);
	void SetTexCoord(int rowstart, int colstart);
	void SetWireFrame(int rStart, int rEnd, 
		              int cStart, int cEnd, 
					  BOOL bLine);
	void SetHideState(int rStart, int rEnd, 
		              int cStart, int cEnd, 
					  BOOL bHide);
	void SetEfficiency(double* Efficiency, int num);
	void SetTexEfficiency(double* tEfficiency, int num);
	void ResetWireFrame(void);
	void ResetHideState(void);
	void GetSize(int* row, int* col);
	BOOL GetWireFrame(int row, int col, BOOL* bLine);
	BOOL GetHideState(int row, int col, BOOL* bHide);
	void GetTextureSize(int* tWidth, int* tHeight);

public:
	glVertex*    m_glVertex;
	xEfficiency  m_glEfficiency;
	xEfficiency  m_tEfficiency;
	//bTexture*	 m_glTexture;
	void*	     m_glTexture;
    BOOL*        m_bLineArray;
    BOOL*        m_bHideArray;

	int          m_row;
	int          m_col;
	int          m_TexWidth;
	int          m_TexHeight;

	BOOL         m_bSetVertex;
	BOOL         m_bSetTexture;

public:
	void SetVertexFunc(BOOL (*vFunc)(int row, int col, 
		                      xEfficiency  glEfficiency,
							  glVertex* glVerArray));

	void SetTextureFunc(BOOL (*tFunc)(int TexWidth, int TexHeight, 
		                xEfficiency  tEfficiency,
		                bTexture* glTexture));

	void BuildVertex(void);
	void BuildTexture(void);
	void BuildBMPTexture(UINT ResID);
	void DrawObject(void);

private:
	XGLFUNC(BOOL, SetVertex, (int row, int col, 
		                      xEfficiency  glEfficiency,
							  glVertex* glVerArray));
	XGLFUNC(BOOL, SetTexture, (int TexWidth, int TexHeight,
		                       xEfficiency  tEfficiency,
		                       bTexture* glTexture));

};
	

/*********************************************************/
/*                                                       */
/*                                                       */
/*                                                       */
/*               The 3D font object                      */ 
/*                                                       */
/*                                                       */
/*                                                       */
/*********************************************************/
class glWord : public CGLBaseObject
{
public:
    glWord();
	~glWord();

private:
	CGLFont   m_glFont;

public:
	void SetTextureSize(int tWidth, int tHeight);
	void GetTextureSize(int* tWidth, int* tHeight);
	void SetTexEfficiency(double* tEfficiency, int num);

    void SetFontType(GLFontType FontType);
	void SetFontSize(double dThick);
	void SetFontText(char* strText);
public:
	int          m_TexWidth;
	int          m_TexHeight;
    CDC*         m_pDC;
	xEfficiency  m_tEfficiency;
	bTexture*	 m_glTexture;

	BOOL         m_bSetFont;
	BOOL         m_bSetTexture;

public:
	void SetTextureFunc(BOOL (*tFunc)(int TexWidth, int TexHeight, 
		                xEfficiency  tEfficiency,
		                bTexture* glTexture));
	
	void BuildFont(CDC* pDC, char* fontname);
	void BuildTexture(void);
	void DrawObject(void);

private:
	XGLFUNC(BOOL, SetTexture, (int TexWidth, int TexHeight,
		                       xEfficiency  tEfficiency,
		                       bTexture* glTexture));

};	


/*********************************************************/
/*                                                       */
/*                                                       */
/*                                                       */
/*                   3D Cube object                      */
/*                                                       */
/*                                                       */
/*                                                       */
/*********************************************************/
class glCube : public CGLBaseObject
{
public:
    glCube();
	~glCube();

public:
	int          m_TexWidth;
	int          m_TexHeight;
	xEfficiency  m_tEfficiency;
	void*	     m_glTexture;
	double       m_dLength;

	BOOL         m_bSetTexture;
public:
	void SetTextureSize(int tWidth, int tHeight);
	void SetTexEfficiency(double* tEfficiency, int num);
	
	void SetTextureFunc(BOOL (*tFunc)(int TexWidth, int TexHeight, 
		                xEfficiency  tEfficiency,
		                bTexture* glTexture));

	void SetLength(double dLength); 
	void GetLength(double* dLength); 

	void BuildVertex(void);
	void BuildTexture(void);
	void BuildBMPTexture(UINT ResID);
	void DrawObject(void);

private:
	UINT         m_uiListID;     //the ID of the displaylist

private:
	XGLFUNC(BOOL, SetTexture, (int TexWidth, int TexHeight,
		                       xEfficiency  tEfficiency,
		                       bTexture* glTexture));
};

#endif