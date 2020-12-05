/**********************************************************/
/*   The glFunc.h                                    
/*                                                         
/*   Created by Xing Zhaohui (xingzhh@yahoo.com),          
/*   Oct 29, 1999                                       
/*                                                        
/*   Declare various functions
/* 
/**********************************************************/
#ifndef __GLFUNC_H__
#define __GLFUNC_H__
#include "gldef.h"

// Create ellipsoid object vertex data
BOOL Ellipsoid(int row, int col, xEfficiency  glEfficiency,
							  glVertex* glVerArray);


// Create checker texture image data
BOOL SetChecker(int TexWidth, int TexHeight, xEfficiency  tEfficiency,
		        bTexture* glTexture);


// Create noise texture image data
BOOL NoiseTexture(int TexWidth, int TexHeight, xEfficiency  tEfficiency,
		        bTexture* glTexture);


// Create palette
void SetupPalette(CDC* pDC, CPalette& Palette);  

#endif