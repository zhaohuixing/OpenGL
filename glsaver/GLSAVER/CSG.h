// CSG.h: interface for the CSGObject class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CSG_H__664049C1_C786_11D2_955D_8422F5C00000__INCLUDED_)
#define AFX_CSG_H__664049C1_C786_11D2_955D_8422F5C00000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "Object.h"

enum enmTYPE 
{
	 TYPE_BALL,
	 TYPE_WAVE,
};


class CSGObject : public CObject  
{
//Attribute
private:
    enmTYPE     m_enmType;  //Object type, sphere or wave 

	fVertex*    m_vertex;   //vertex array
	uiIndice*   m_indice;   //indices array
    fEfficiency m_factor;   //efficiencies of the equation
    fDiscrete   m_dvalue;   //discrete of grid
    fDiscrete   m_dMemvalue;//backup discrete of grid
    iSize       m_size;     //size of the grid
    iSize       m_Memsize;  //backup size of the grid
    iSize       m_Oldsize;   //backup size of the grid to compare
	BYTE        m_alpha;    //alpha byte for texture color

	float       m_x;        //x-coordinate of the center of object  
	float       m_y;        //y-coordinate of the center of object
	float       m_z;        //z-coordinate of the center of object
 
	float       m_sx;       //scale in x-axis  
	float       m_sy;       //scale in y-axis
	float       m_sz;       //scale in z-axis
	
	float       m_rx;       //rotating angle around x-axis
	float       m_ry;       //rotating angle around y-axis
	float       m_rz;       //rotating angle around z-axis

	BOOL        m_bWire;    //flag for showing wireframe or not
public:
    void SetType(enmTYPE  enmType)
	{
        m_enmType = enmType;
	};

    enmTYPE GetType(void)
	{
        return m_enmType;
	};

    void SetEfficiency(float A, float B, float C)
    {
		m_factor.SetABC(A, B, C);
	};

    void GetEfficiency(float* A, float* B, float* C)
    {
		m_factor.GetABC(A, B, C);
	};

    void SetDiscrete(float dX, float dY, float dZ) 
	{
		m_dMemvalue.SetValue(dX, dY, dZ);
	};

    void GetDiscrete(float* dX, float* dY, float* dZ) 
	{
		m_dMemvalue.GetValue(dX, dY, dZ);
	};

	void SetSize(int row, int col)
	{
		m_Memsize.SetValue(row, col);
	};

	void GetSize(int* row, int* col)
	{
		m_Memsize.GetValue(row, col);
	};

    void SetAlpha(BYTE alpha)
	{
		m_alpha = alpha;
	};

    void GetAlpha(BYTE* alpha)
	{
		*alpha = m_alpha;
	};


	void SetTranslate(float x, float y, float z)
	{
		m_x = x;
		m_y = y;
		m_z = z;
	};

	void GetTranslate(float* x, float* y, float* z)
	{
		*x = m_x;
		*y = m_y;
		*z = m_z;
	};

	void SetScale(float x, float y, float z)
	{
		m_sx = x;
		m_sy = y;
		m_sz = z;
	};

	void GetScale(float* x, float* y, float* z)
	{
		*x = m_sx;
		*y = m_sy;
		*z = m_sz;
	};

	void SetRotation(float rx, float ry, float rz)
	{
		m_rx = rx;
		m_ry = ry;
		m_rz = rz;
	};

    void GetRotation(float* rx, float* ry, float* rz)
	{
		*rx = m_rx;
		*ry = m_ry;
		*rz = m_rz;
	};

    void SetDrawState(BOOL bWire)
	{
        m_bWire = bWire;
	};

    void GetDrawState(BOOL* bWire)
	{
        *bWire = m_bWire;
	};

private:
//varibles for texture
    fEfficiency m_tfactor;  //efficiencies array for creating texture
    fDiscrete   m_tdvalue;  //discrete of texture grid
    iSize       m_tsize;    //size of the texture grid
    
public:
    void SetTexFactor(float A, float B, float C)
    {
		m_tfactor.SetABC(A, B, C);
	};

    void GetTexFactor(float* A, float* B, float* C)
    {
		m_tfactor.GetABC(A, B, C);
	};

    void SetTexDiscrete(float dX, float dY, float dZ) 
	{
		m_tdvalue.SetValue(dX, dY, dZ);
	};

    void GetTexDiscrete(float* dX, float* dY, float* dZ) 
	{
		m_tdvalue.GetValue(dX, dY, dZ);
	};

	void SetTexSize(int row, int col)
	{
		m_tsize.SetValue(row, col);
	};

	void GetTexSize(int* row, int* col)
	{
		m_tsize.GetValue(row, col);
	};


//texture and vertex, indices operation
//attributions of texture, vertex and indices 
//functions
private:
	//texture process method
    void(*FuncTexture)(iSize* isize,
			           fEfficiency* factor,
			           fDiscrete* dvalue,
					   BYTE alpha);

	//object vertex process
    BOOL(*FuncVertex)(fVertex* vertexArray,
                      iSize isize,
			          fEfficiency factor,
			          fDiscrete dvalue);

	//object indices process
	BOOL(*FuncIndice)(uiIndice* indiceArray, 
					   iSize isize); 
//operation
public:
	//set texture function
    void SetTextureFunc(void(*Func)(iSize* isize,
			           fEfficiency* factor,
			           fDiscrete* dvalue,
					   BYTE alpha))
	{
        FuncTexture = Func; 
	};

	//set vertex function
    void SetVertexFunc(BOOL(*Func)(
		              fVertex* vertexArray,
                      iSize isize,
			          fEfficiency factor,
			          fDiscrete dvalue))
	{
		FuncVertex = Func;
	};

    //set indices function
    void SetIndiceFunc(BOOL(*Func)(
		               uiIndice* indiceArray, 
					   iSize isize))
	{
		FuncIndice = Func;
	};

    
public:
	CSGObject();
	virtual ~CSGObject();

    void SetTexture(void);
	void DrawObject(void);
};

#endif // !defined(AFX_CSG_H__664049C1_C786_11D2_955D_8422F5C00000__INCLUDED_)
