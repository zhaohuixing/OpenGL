/**********************************************************/
/*   The gldef.h                                    
/*                                                         
/*   Created by Xing Zhaohui (xingzhh@yahoo.com),          
/*   Sept 20, 1999                                       
/*                                                        
/*   Define some data types and constants 
/* 
/**********************************************************/

#ifndef _GLDEF_H_
#define _GLDEF_H_
#include<map>
#include<vector>
#include<list>
#include <gl\gl.h>
#include <gl\glu.h>
#include "xvector.h"
using namespace std;

#define PI 3.14159265358979323846

#define XGLFUNC(type,function,argvs)  type(*function)argvs

typedef struct GLVERTEX
{
	double  m_Texture[2];
	dVector m_Normal;
	dVector m_Vertex;
}glVertex;


typedef struct GLDRAWFALG
{
    bool    m_bLine;
    bool    m_bHide;
}glDrawFlag;


typedef vector<double> xEfficiency;

#endif