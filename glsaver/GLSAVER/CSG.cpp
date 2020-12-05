// CSG.cpp: implementation of the CSGObject class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CSG.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSGObject::CSGObject()
{
	m_vertex = NULL;
	m_indice = NULL;

	m_x = 0.0;          
	m_y = 0.0;        
	m_z = 0.0;        
 
	m_rx = 0.0;       
	m_ry = 0.0;       
	m_rz = 0.0;       

	m_bWire = FALSE;
    m_Oldsize.SetValue(0, 0);
}


CSGObject::~CSGObject()
{
	if(m_vertex)
		delete []m_vertex;   
	
	if(m_indice)
		delete []m_indice;
}


void CSGObject::SetTexture(void)
{
	(*FuncTexture)(&m_tsize,
	  &m_tfactor, &m_tdvalue, m_alpha);
}


void CSGObject::DrawObject(void)
{
	int k;
    int i;

	if(m_bWire)
	{
		m_dvalue.SetValue(m_dMemvalue.m_dX*4,
                        m_dMemvalue.m_dY*4,
						m_dMemvalue.m_dZ*4);
		m_size.SetValue((int)(m_Memsize.m_row*2.5), (int)(m_Memsize.m_col*2.5));
	    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}
    else
	{
		m_dvalue.SetValue(m_dMemvalue.m_dX,
                        m_dMemvalue.m_dY,
						m_dMemvalue.m_dZ);
		m_size.SetValue(m_Memsize.m_row*10, m_Memsize.m_col*10);
	    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}

    if(m_Oldsize.m_row != m_size.m_row ||
		m_Oldsize.m_col != m_size.m_col)
	{
	    if(m_vertex)
		    delete []m_vertex;
	    if(m_indice)
		    delete []m_indice;

	    m_vertex = new fVertex[(m_size.m_row+1) * (m_size.m_col+1)];
	    m_indice = new uiIndice[m_size.m_row * (m_size.m_col+1)];
        (*FuncIndice)(m_indice, m_size);
		m_Oldsize.m_row = m_size.m_row;
		m_Oldsize.m_col = m_size.m_col;
	}

    (*FuncVertex)(m_vertex, m_size,
			      m_factor, m_dvalue);

	SetTexture();
	
	glInterleavedArrays(GL_T2F_N3F_V3F, 0, m_vertex);

    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);
    glMatrixMode(GL_MODELVIEW);
    glTranslatef(m_x, m_y, m_z);
	glScalef(m_sx, m_sy, m_sz);
	glRotatef(m_rx, 1.0, 0.0, 0.0);
	glRotatef(m_ry, 0.0, 1.0, 0.0);
	glRotatef(m_rz, 0.0, 0.0, 1.0);
	
	for(i=0; i< m_size.m_row; i++) 
	{
        k = i*(m_size.m_col+1);
	    glDrawElements(GL_TRIANGLE_STRIP, 
			      2*(m_size.m_col+1), 
			       GL_UNSIGNED_INT, 
				   &m_indice[k]);
	}
	
	glRotatef((float)(-1.0 * m_rz), 0.0, 0.0, 1.0);
	glRotatef((float)(-1.0 * m_ry), 0.0, 1.0, 0.0);
	glRotatef((float)(-1.0 * m_rx), 1.0, 0.0, 0.0);
	glScalef((float)(1.0f/m_sx), (float)(1.0f/m_sy), (float)(1.0f/m_sz));
    glTranslatef((float)(-1.0 * m_x), 
		         (float)(-1.0 * m_y), 
				 (float)(-1.0 * m_z));
	
}