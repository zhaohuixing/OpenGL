#if !defined(__OBJECT_H__)
#define __OBJECT_H__

#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <gl\gl.h>
#include <gl\glu.h>


#define PI       3.1415926f
#define IPI      (float)(0.15915495/10.0)   

//Vertex value of the object 
template <class Type>class vertex
{
public:    
	Type m_texture[2];
	Type m_normal[3];
	Type m_vertex[3];

public:
    vertex(){};
	~vertex(){};

    void SetTexture(Type texture1, Type texture2)
	{
	    m_texture[0] = texture1;
	    m_texture[1] = texture2;
	};

    void GetTexture(Type* texture1, Type* texture2)
	{
	    *texture1 = m_texture[0];
	    *texture2 = m_texture[1];
	};
    
	void SetNormal(Type normal1, Type normal2, Type normal3)
	{
	    m_normal[0] = normal1;
	    m_normal[1] = normal2;
	    m_normal[2] = normal3;
	};
    
	void GetNormal(Type* normal1, Type* normal2, Type* normal3)
	{
	    *normal1 = m_normal[0];
	    *normal2 = m_normal[1];
	    *normal3 = m_normal[2];
	};

    void SetVertex(Type vertex1, Type vertex2, Type vertex3)
	{
	    m_vertex[0] = vertex1;
	    m_vertex[1] = vertex2;
	    m_vertex[2] = vertex3;
	};
    
	void GetVertex(Type* vertex1, Type* vertex2, Type* vertex3)
	{
	    *vertex1 = m_vertex[0];
	    *vertex2 = m_vertex[1];
	    *vertex3 = m_vertex[2];
	};
};

typedef vertex<float> fVertex;


//Indices value of the object 
template <class Type>class indices
{
public:
	Type m_indice[2];

public:
    indices(){};
    ~indices(){};

	void SetIndices(Type indice1, Type indice2)
	{
		m_indice[0] = indice1;
		m_indice[1] = indice2;

	};

	void GetIndices(Type* indice1, Type* indice2)
	{
		*indice1 = m_indice[0];
		*indice2 = m_indice[1];

	};
};

typedef indices<unsigned int> uiIndice;


//Color value of texture
template <class Type>class texture
{
public:
    Type m_red; 
    Type m_green; 
    Type m_blue; 
    Type m_alpha; 

public:
    texture(){};
    ~texture(){};

	void SetColors(Type red, Type green, 
		           Type blue, Type alpha)
	{
        m_red = red; 
        m_green = green; 
        m_blue = blue; 
        m_alpha = alpha; 
	};
	
	void GetColors(Type *red, Type *green, 
		           Type *blue, Type *alpha)
	{
        *red = m_red; 
        *green = m_green; 
        *blue = m_blue; 
        *alpha = m_alpha; 
	};
	
};


typedef texture<BYTE> bTexture;


//Efficiencies of the equation of the object model
template <class Type>class efficiency
{
public:
	Type m_A;
	Type m_B;
	Type m_C;

public:
    efficiency(){};
    ~efficiency(){};

	void SetABC(Type A, Type B, Type C)
	{
		m_A = A; 
		m_B = B;
		m_C = C;
	};

	void GetABC(Type* A, Type* B, Type* C)
	{
		*A = m_A; 
		*B = m_B;
		*C = m_C;
	};
};

typedef efficiency<float> fEfficiency;


//Disrete value for the grid of base
//element of the object for rendering
template <class Type>class discrete
{
public:
	Type m_dX;
	Type m_dY;
	Type m_dZ;

public:
    discrete(){};
    ~discrete(){};

    void SetValue(Type dX, Type dY, Type dZ)
	{
	   m_dX = dX;
	   m_dY = dY;
	   m_dZ = dZ;
	};

    void GetValue(Type* dX, Type* dY, Type* dZ)
	{
	   *dX = m_dX;
	   *dY = m_dY;
	   *dZ = m_dZ;
	};
};

typedef discrete<float> fDiscrete;


//size structure similar to CSize and Size
template <class Type>class size
{
public:
	Type m_row;
	Type m_col;

public:
    size(){};
    ~size(){};
 
    void SetValue(Type row, Type col)
	{
	   m_row = row;
	   m_col = col;
	};

    void GetValue(Type* row, Type* col)
	{
	   *row = m_row;
	   *col = m_col;
	};
};


typedef size<int> iSize;


void NoiseTexture(iSize* isize,
				  fEfficiency* factor,
				  fDiscrete* dvalue,
				  BYTE alpha);

void CheckerTexture(iSize* isize,
					fEfficiency* factor,
					fDiscrete* dvalue,
					BYTE alpha);


void SingleColor(iSize* isize,
				 fEfficiency* factor,
				 fDiscrete* dvalue,
				 BYTE alpha);


BOOL SetIndices(uiIndice* indiceArray, 
					   iSize isize);


BOOL CreateWaveSquare(fVertex* vertexArray,
                       iSize isize,
					   fEfficiency factor,
					   fDiscrete dvalue);

BOOL CreateWaveRound(fVertex* vertexArray,
                       iSize isize,
					   fEfficiency factor,
					   fDiscrete dvalue);


BOOL CreateSpere(fVertex* vertexArray,
                       iSize isize,
					   fEfficiency factor,
					   fDiscrete dvalue);


//palette setup when compiled with MFC library
#ifdef __AFXWIN_H__
	void SetupPalette(HDC hDC, HPALETTE hPalette);  
#endif

#endif