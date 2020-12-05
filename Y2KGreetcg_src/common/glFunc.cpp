/**********************************************************/
/*   The glFunc.cpp                                    
/*                                                         
/*   Created by Xing Zhaohui (xingzhh@yahoo.com),          
/*   Oct 29, 1999                                       
/*                                                        
/*   Declare various functions
/* 
/**********************************************************/
#include "stdafx.h"
#include <math.h>
#include "glFunc.h"


/**********************************************************/
/* Create ellipsoid object vertex data
/* (x*x)/(a*a) + (y*y)/(b*b) + (z*z)/(c*c) = 1.0
/**********************************************************/
BOOL Ellipsoid(int row, int col, xEfficiency  glEfficiency,
			   glVertex* glVerArray)
{
	ASSERT(row > 0 && col > 0);
	if(row <= 0 || col <= 0)
		return FALSE;

    ASSERT(glEfficiency.size() >= 3);
    if(glEfficiency.size() < 3)
		return FALSE;


	int i, j, k;
	double dT, dr, dA, dB, dC, dA2, dB2, dC2;
	double Astep, dArc;                //rotation along Z-axis
    double Rstep, dRot;                //rotation along center in user-reference section
	
	double dCosA, dSinA, dCosR, dSinR;
	double dDelta, dL, dX, dY, dZ, dNX, dNY, dNZ;
    dVector V;
	dVector VN;
	
	dA = glEfficiency[0];  //efficiency a
	dB = glEfficiency[1];  //efficiency b
	dC = glEfficiency[2];  //efficiency c		 


	ASSERT(dA > 0.0 && dB > 0.0 && dC > 0.0);
	if(!(dA > 0.0 && dB > 0.0 && dC > 0.0))
		return FALSE;

	dA2 = dA*dA;
	dB2 = dB*dB;
	dC2 = dC*dC;

	Astep = (2.0 * dB / (row));
	Rstep = (2.0 * PI / (col));
	for(i = 0; i <= row; i++)
	{
	   dY = Astep*i - dB;
	   dT = (dY*dY/dB2); 

       for(j = 0; j <= col; j++)
	   {
           //get vertex and normal in user reference coordinate
		   dRot = Rstep*((double)j);
			   
           dCosR = cos(dRot);
	       dSinR = sin(dRot);     	  
		   
		   dr = dCosR*dCosR/dA2 + dSinR*dSinR/dC2;
		   dL = sqrt((1.0 - dT)/dr);
		   dX = dL*dCosR;
		   dZ = dL*dSinR;

		   dNX = 2.0*dX / dA2;
		   dNY = 2.0*dY / dB2;
		   dNZ = 2.0*dZ / dC2;
		   dDelta = sqrt(dNX*dNX+dNY*dNY+dNZ*dNZ);
		   if(dDelta != 0.0)
		   {
		       dNX /= dDelta;
		       dNY /= dDelta;
		       dNZ /= dDelta;
		   }
		   else
		   {
		       dNX = 0.0;
		       dNY = 1.0;
		       dNZ = 0.0;
		   }
		   V.SetValue(dX, dY, dZ);
		   VN.SetValue(dNX, dNY, dNZ);
		   VN.Normalize();

	       k = i * (col+1) + j;
	       glVerArray[k].m_Vertex = V;
		   glVerArray[k].m_Normal = VN;
	   }
	}

	return TRUE;
}


/**********************************************************/
/* Create checker texture image data
/**********************************************************/
BOOL SetChecker(int TexWidth, int TexHeight, xEfficiency  tEfficiency,
		        bTexture* glTexture)
{
    ASSERT(tEfficiency.size() >= 7);
    if(tEfficiency.size() < 7)
		return FALSE;
    
	ASSERT(glTexture != NULL);
    if(glTexture == NULL)
		return FALSE;

	int           iLoop1, iLoop2; 
	int           k;
	unsigned char br1, bg1, bb1, br2, bg2, bb2, alpha;
	
	br1 = (((int)tEfficiency[0])&0xFF);   
	bg1 = (((int)tEfficiency[1])&0xFF);
	bb1 = (((int)tEfficiency[2])&0xFF);

	br2 = ((int)tEfficiency[3])&0xFF; 
	bg2 = ((int)tEfficiency[4])&0xFF;
	bb2 = ((int)tEfficiency[5])&0xFF;

	alpha = ((int)tEfficiency[6])&0xFF;

    for(iLoop1 = 0; iLoop1 < TexWidth; iLoop1++)
	{
       for(iLoop2 = 0; iLoop2 < TexHeight; iLoop2++)
	   {
           k = iLoop1 * TexHeight + iLoop2;
		   
		   if(((iLoop1)%2) ^ ((iLoop2)%2))
           {
              glTexture[k].SetColors(br1, bg1, bb1, alpha);
		   }
		   else
           {
              glTexture[k].SetColors(br2, bg2, bb2, alpha);
		   }
	   }
	}

	return TRUE;
}


/**********************************************************/
/* Create noise texture image data
/**********************************************************/
BOOL NoiseTexture(int TexWidth, int TexHeight, xEfficiency  tEfficiency,
		        bTexture* glTexture)
{
//avoid the warning information in compiling, no special sense
    ASSERT(tEfficiency.size() >= 1);
    if(tEfficiency.size() < 1)
		return FALSE;
    
	ASSERT(glTexture != NULL);
    if(glTexture == NULL)
		return FALSE;

	int           iLoop1, iLoop2; 
	int           p, k;
	unsigned char alpha = ((int)tEfficiency[0])&0xFF;;
	
    for(iLoop1 = 0; iLoop1 < TexWidth; iLoop1++)
	{
       for(iLoop2 = 0; iLoop2 < TexHeight; iLoop2++)
	   {
           k = iLoop1 * TexHeight + iLoop2;
           p = k % 20; 
		   switch(p)
           {
		      case 0:
			     glTexture[k].SetColors(255, 0, 0, 255&alpha);
                 break;
		      case 1:
			     glTexture[k].SetColors(0, 255, 0, 0);
                 break;
			  case 2:  
				 glTexture[k].SetColors(0, 0, 255, 255&alpha);
                 break;
			  case 3:  
				 glTexture[k].SetColors(255, 255, 255, 255&alpha);
				 break;
		      case 4:
			     glTexture[k].SetColors(255, 0, 255, 255&alpha);
                 break;
		      case 5:
			     glTexture[k].SetColors(255, 255, 0, 0);
                 break;
			  case 6:  
				 glTexture[k].SetColors(0, 255, 255, 255&alpha);
                 break;
			  case 7:  
				 glTexture[k].SetColors(238, 12, 113, 25&alpha);
				 break;
		      case 8:
			     glTexture[k].SetColors(0, 128, 255, 255&alpha);
                 break;
		      case 9:
			     glTexture[k].SetColors(0, 255, 128, 0);
                 break;
			  case 10:  
				 glTexture[k].SetColors(255, 128, 0, 255&alpha);
                 break;
			  case 11:  
				 glTexture[k].SetColors(255, 0, 128, 0);
				 break;
		      case 12:
			     glTexture[k].SetColors(128, 0, 255, 255&alpha);
                 break;
		      case 13:
			     glTexture[k].SetColors(128, 255, 128, 0);
                 break;
			  case 14:  
				 glTexture[k].SetColors(55, 55, 55, 55&alpha);
                 break;
			  case 15:  
				 glTexture[k].SetColors(255, 125, 125, 255&alpha);
				 break;
			  case 16:  
				 glTexture[k].SetColors(128, 128, 250, 255&alpha);
				 break;
			  case 17:  
				 glTexture[k].SetColors(1, 1, 1, 1&alpha);
				 break;
			  case 18:  
				 glTexture[k].SetColors(64, 128, 255, 255&alpha);
				 break;
			  case 19:  
				 glTexture[k].SetColors(128, 64, 128, 1&alpha);
				 break;
		   }
	   }
	}

	return TRUE;
}    



/**********************************************************/
/* Create palette
/**********************************************************/
void SetupPalette(CDC* pDC, CPalette& Palette)
{
	PIXELFORMATDESCRIPTOR pfd;  // Pixel Format Descriptor         
	LOGPALETTE *pPal;			// Pointer to memory for logical palette
	int PixelFormat;			// Pixel format index
    int paletteSize;            // Number of entries in palette 
	BYTE RedMask;               // Range for each color entry (7,7,and 3)
	BYTE GreenMask;
	BYTE BlueMask;
	HDC  hDC = pDC->GetSafeHdc();							


	// Get the pixel format index and retrieve the pixel format description
    PixelFormat = GetPixelFormat(hDC);
    DescribePixelFormat(hDC, PixelFormat, sizeof(PIXELFORMATDESCRIPTOR), &pfd);
    
	
	// Check whether the pixel format and the pixel type
	if (!(pfd.dwFlags & PFD_NEED_PALETTE ||
	  pfd.iPixelType == PFD_TYPE_COLORINDEX))
	    return;

	// Get the number of entries in palette. 256 colors for 8 bits 
    paletteSize = 1 << pfd.cColorBits;
    
	// Allocate for the logical palette
	pPal = (LOGPALETTE*)
	malloc(sizeof(LOGPALETTE) + paletteSize * sizeof(PALETTEENTRY));
    
	
	// Fill the logical palette header information 
	pPal->palVersion = 0x300;            //support Windows3.0
    pPal->palNumEntries = paletteSize;   //number of colors entries

    // Set the 1st entries of logical palette with the current system palette 
    (void) GetSystemPaletteEntries(hDC, 0, paletteSize, &pPal->palPalEntry[0]);

	//Set the RGB mask
	RedMask = (1 << pfd.cRedBits) - 1;
	GreenMask = (1 << pfd.cGreenBits) - 1;
	BlueMask = (1 << pfd.cBlueBits) - 1;

	//Set all entries of the logical palette 
    for (int i=0; i<paletteSize; ++i) 
	{
	    pPal->palPalEntry[i].peRed =
		    (((i >> pfd.cRedShift) & RedMask) * 255) / RedMask;
	    pPal->palPalEntry[i].peGreen =
		    (((i >> pfd.cGreenShift) & GreenMask) * 255) / GreenMask;
	    pPal->palPalEntry[i].peBlue =
		    (((i >> pfd.cBlueShift) & BlueMask) * 255) / BlueMask;
	    pPal->palPalEntry[i].peFlags = 0;
    }

	//Create the palette
    if(Palette.CreatePalette(pPal))
	{
	    pDC->SelectPalette(&Palette, FALSE);
	    pDC->RealizePalette();
    }

	//Free the memory allocated for the logical palette 
    free(pPal);
}

