#include "stdafx.h"

#include "Object.h"


void NoiseTexture(iSize* isize,
					   fEfficiency* factor,
					   fDiscrete* dvalue,
					   BYTE alpha)
{
//avoid the warning information in compiling, no special sense
	dvalue = dvalue;
	factor = factor;

    bTexture* bColor;
    int iLoop1, iLoop2; 
	int k;
    int p; 

	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	
	bColor = new bTexture[(isize->m_row) * (isize->m_col)];
    
	if(bColor == NULL)
		return;
	
    for(iLoop1 = 0; iLoop1 < isize->m_row; iLoop1++)
	{
       for(iLoop2 = 0; iLoop2 < isize->m_col; iLoop2++)
	   {
           k = iLoop1 * isize->m_col + iLoop2;
           p = k % 16; 
		   switch(p)
           {
		      case 0:
			     bColor[k].SetColors(255, 0, 0, 255&alpha);
                 break;
		      case 1:
			     bColor[k].SetColors(0, 255, 0, 0);
                 break;
			  case 2:  
				 bColor[k].SetColors(0, 0, 255, 255&alpha);
                 break;
			  case 3:  
				 bColor[k].SetColors(255, 255, 255, 255&alpha);
				 break;
		      case 4:
			     bColor[k].SetColors(255, 0, 255, 255&alpha);
                 break;
		      case 5:
			     bColor[k].SetColors(255, 255, 0, 0);
                 break;
			  case 6:  
				 bColor[k].SetColors(0, 255, 255, 255&alpha);
                 break;
			  case 7:  
				 bColor[k].SetColors(238, 12, 113, 25&alpha);
				 break;
		      case 8:
			     bColor[k].SetColors(0, 128, 255, 255&alpha);
                 break;
		      case 9:
			     bColor[k].SetColors(0, 255, 128, 0);
                 break;
			  case 10:  
				 bColor[k].SetColors(255, 128, 0, 255&alpha);
                 break;
			  case 11:  
				 bColor[k].SetColors(255, 0, 128, 0);
				 break;
		      case 12:
			     bColor[k].SetColors(128, 0, 255, 255&alpha);
                 break;
		      case 13:
			     bColor[k].SetColors(128, 255, 0, 0);
                 break;
			  case 14:  
				 bColor[k].SetColors(55, 55, 55, 55&alpha);
                 break;
			  case 15:  
				 bColor[k].SetColors(255, 125, 125, 255&alpha);
		   }
	   }
	}

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, isize->m_col, isize->m_row, 
		 0, GL_RGBA, GL_UNSIGNED_BYTE, bColor);

	if(bColor)
	   delete []bColor;
}    
 

void CheckerTexture(iSize* isize,
					   fEfficiency* factor,
					   fDiscrete* dvalue,
					   BYTE alpha)
{
	bTexture *bColor;
    int iLoop1, iLoop2; 
	int k;
	BYTE br1, bg1, bb1, br2, bg2, bb2;


	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	br1 = ((int)factor->m_A)&0xFF;   
	bg1 = ((int)factor->m_B)&0xFF;
	bb1 = ((int)factor->m_C)&0xFF;

	br2 = ((int)dvalue->m_dX)&0xFF; 
	bg2 = ((int)dvalue->m_dY)&0xFF;
	bb2 = ((int)dvalue->m_dZ)&0xFF;

	bColor = new bTexture[(isize->m_row) * (isize->m_col)];
    
	if(bColor == NULL)
		return;

    for(iLoop1 = 0; iLoop1 < isize->m_row; iLoop1++)
	{
       for(iLoop2 = 0; iLoop2 < isize->m_col; iLoop2++)
	   {
           k = iLoop1 * isize->m_col + iLoop2;
		   
		   if((iLoop1%2) ^ (iLoop2%2))
           {
              bColor[k].SetColors(br1, bg1, bb1, alpha);
		   }
		   else
           {
              bColor[k].SetColors(br2, bg2, bb2, alpha);
		   }
	   }
	}

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, isize->m_col, isize->m_row, 
		 0, GL_RGBA, GL_UNSIGNED_BYTE, bColor);
	
	if(bColor)
	  delete []bColor;
}

void SingleColor(iSize* isize,
					   fEfficiency* factor,
					   fDiscrete* dvalue,
					   BYTE alpha)
{
	bTexture *bColor;
    int iLoop1, iLoop2; 
	int k;
	BYTE br, bg, bb;


	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	br = ((int)factor->m_A)&0xFF;   
	bg = ((int)factor->m_B)&0xFF;
	bb = ((int)factor->m_C)&0xFF;

	bColor = new bTexture[(isize->m_row) * (isize->m_col)];

    for(iLoop1 = 0; iLoop1 < isize->m_row; iLoop1++)
	{
       for(iLoop2 = 0; iLoop2 < isize->m_col; iLoop2++)
	   {
           k = iLoop1 * isize->m_col + iLoop2;
		   
           bColor[k].SetColors(br, bg, bb, alpha);
	   }
	}

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, isize->m_col, isize->m_row, 
		 0, GL_RGBA, GL_UNSIGNED_BYTE, bColor);
	
	if(bColor)
	   delete []bColor;
}


BOOL SetIndices(uiIndice* indiceArray, iSize isize)
{
	if(indiceArray == NULL)
		return FALSE;

	int m, k;

	for(int i = 0; i < isize.m_row; i++)
    {
		m = i*(isize.m_col + 1);
		for(int j = 0; j <= isize.m_col; j++)
		{
			k = i*(isize.m_col+1)+j;
			indiceArray[k].SetIndices(m + j,m + isize.m_col + j + 1);
		}
	}

	return TRUE;
}


BOOL CreateWaveSquare(fVertex* vertexArray, iSize isize,
					   fEfficiency factor, fDiscrete dvalue)
{
	float dTemp, dL, dVL, dNL;             
	float dSin, dCos;
    float dX, dY, dZ;
	float dNX, dNY, dNZ;  
    float dA, dC;  
    float dST, dCT, dDT; 
	int  i, j, k;               

    if(vertexArray == NULL)
		return FALSE;

    dA = (float)(dvalue.m_dX * isize.m_col/ 2.0);
    dC = (float)(dvalue.m_dZ * isize.m_row/ 2.0);

	for(i = 0; i <= isize.m_row; i++)
	{
	   dZ = dvalue.m_dZ * i - dC;
	   for(j = 0; j <= isize.m_col; j++)
	   {
	      dX = dvalue.m_dX * j - dA;
		  k = i * (isize.m_col + 1) + j;
	   
          dL = (float)(sqrt(dX*dX + dZ*dZ)); 
          
		  if(dL > IPI)
			  dVL = dL;
		  else
			  dVL = IPI;
		  
		  if(dL != 0.0 && factor.m_A != 0.0)
		  {
		     //calculate vertex
			 
			 dTemp = factor.m_B*dL + factor.m_C; 
		     dSin = (float)sin(dTemp);
			 dCos = (float)cos(dTemp);
		     
			 dST = dSin/(factor.m_B*dL*10);
			 dCT = factor.m_B*dCos;
			 
			 dY = (float)(factor.m_A*dSin /(factor.m_B*dVL*10));
			 
             vertexArray[k].SetVertex(dX, dY, dZ);

             //calculate normal
		     dDT = factor.m_A*(dST - dCT)/(dL*dL);
			 dNX = dDT*dX;
		     dNY = 1.0;
		     dNZ = dDT*dZ;
		     dNL = (float)(sqrt(dNX*dNX + dNY*dNY + dNZ*dNZ));
			 dNX /= dNL;
		     dNY /= dNL;
		     dNZ /= dNL;
			 
			 vertexArray[k].SetNormal(dNX, dNY, dNZ);
		  }
		  else
		  {
			 vertexArray[k].SetVertex(dX, 0.0, dZ);
			 vertexArray[k].SetNormal(0.0, 1.0, 0.0);
		  }
          vertexArray[k].SetTexture(i/(float)isize.m_row, 
			                        j/(float)isize.m_col);
	   
	      
	   }
   }
	
   return TRUE;
}


BOOL CreateWaveRound(fVertex* vertexArray,
                       iSize isize,
					   fEfficiency factor,
					   fDiscrete dvalue)
{
	float dTemp, dL, dNL;             
	float dSin, dCos;
    float dX, dY, dZ;
	float dNX, dNY, dNZ;  
    float dST, dCT, dDT;  
    float dAngle, dRadius, dRotate;
	int  i, j, k;               

    if(vertexArray == NULL)
		return FALSE;

    dRotate = (float)(2.0 * PI /(float)isize.m_col);

	for(i = 0; i <= isize.m_row; i++)
	{
	   dRadius = dvalue.m_dX * (isize.m_row - i);
	   
	   for(j = 0; j <= isize.m_col; j++)
	   {
		  k = i * (isize.m_col + 1) + j;
		  
		  dAngle = dRotate * j;
		  
	      dX = (float)(dRadius * cos(dAngle));
		  dZ = (float)(dRadius * sin(dAngle));
             
          dL = (float)(sqrt(dX*dX + dZ*dZ)); 


		  if(dL != 0.0 && factor.m_A != 0.0)
		  {
			 dTemp = factor.m_B*dL + factor.m_C; 
		     dSin = (float)(sin(dTemp));
			 dCos = (float)(cos(dTemp));
		     
			 dST = (float)(dSin/(factor.m_B*dL*10.0));
			 dCT = (float)(factor.m_B*dCos);
			 
		     dY = (float)(factor.m_A*(dSin)/(factor.m_B*dL*10.0));

			 vertexArray[k].SetVertex(dX, dY, dZ);

             //calculate normal
		     dDT = factor.m_A*(dST - dCT)/(dL*dL);
			 dNX = dDT*dX;
		     dNY = 1.0f;
		     dNZ = dDT*dZ;
		     dNL = (float)(sqrt(dNX*dNX + dNY*dNY + dNZ*dNZ));
		     dNX /= dNL;
		     dNY /= dNL;
		     dNZ /= dNL;
			 
			 vertexArray[k].SetNormal(dNX, dNY, dNZ);

		  }
		  else
		  {
			 vertexArray[k].SetVertex(dX, 0.0, dZ);
			 vertexArray[k].SetNormal(0.0, 1.0, 0.0);

		  }
		  vertexArray[k].SetTexture(i/(float)isize.m_row, 
			                        j/(float)isize.m_col);
	   }
   }
	
   return TRUE;
}


BOOL CreateSpere(fVertex* vertexArray, iSize isize,
					   fEfficiency factor, fDiscrete dvalue)
{
    float dTemp;             
    float dDTheta, dRotate;
	float dSin, dCos;
    float dX, dY, dZ;
	float dE, dT, dL, dNX, dNY, dNZ, dNL;  
    float dA, dB, dC;  
  
	int  i, j, k;               

    if(vertexArray == NULL)
		return FALSE;

    dT = (float)(2.0*factor.m_B/(float)(isize.m_row));
	dRotate = (float)((2.0 * PI /(float)isize.m_col));
    dA = factor.m_A*factor.m_A;
	dB = factor.m_B*factor.m_B;
	dC = factor.m_C*factor.m_C;


	for(i = 0; i <= isize.m_row; i++)
	{
	   dY = dT * (float)i - factor.m_B;
       dTemp = (float)(dY*dY / dB); 
	   for(j = 0; j <= isize.m_col; j++)
	   {
		   k = i * (isize.m_col + 1) + j;
		   
		   //calculate vertex
		   dDTheta = j * dRotate;
		   dSin = (float)(sin(dDTheta));
		   dCos = (float)(cos(dDTheta));
		   dL = (float)((dCos*dCos)/dA + (dSin*dSin)/dC); 
		   dE = (float)sqrt((1 - dTemp)/dL);
		   dX = (float)(dE*dCos);
		   dZ = (float)(dE*dSin);


           vertexArray[k].SetVertex(dX, dY, dZ);
           
		   //calculate normal
		   dNX = (float)(2.0 * dX / dA);
		   dNY = (float)(2.0 * dY / dB);
		   dNZ = (float)(2.0 * dZ / dC);

		   
		   dNL = (float)sqrt(dNX*dNX + dNY*dNY + dNZ*dNZ);
		   
		   if(dNL != 0.0)
		   {
		      dNX /= dNL;
		      dNY /= dNL;
		      dNZ /= dNL;
		   }
		   else
		   {
		      dNX = 0.0;
		      dNY = 1.0;
	          dNZ = 0.0;
			  
		   }

		   vertexArray[k].SetNormal(dNX, dNY, dNZ);
		   
		   vertexArray[k].SetTexture(i/(float)isize.m_row, 
		   	                        j/(float)isize.m_col);
	   }
	}   

	return TRUE;    
}


//palette setup when compiled with MFC library
#ifdef __AFXWIN_H__
void SetupPalette(HDC hDC, HPALETTE hPalette)
{
	PIXELFORMATDESCRIPTOR pfd;  // Pixel Format Descriptor         
	LOGPALETTE *pPal;			// Pointer to memory for logical palette
	int PixelFormat;			// Pixel format index
    int paletteSize;            // Number of entries in palette 
	BYTE RedMask;               // Range for each color entry (7,7,and 3)
	BYTE GreenMask;
	BYTE BlueMask;
								

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
    hPalette = CreatePalette(pPal);

	//If success, select and realize the palette for this device context
    if(hPalette) 
	{
	    SelectPalette(hDC, hPalette, FALSE);
	    RealizePalette(hDC);
    }

	//Free the memory allocated for the logical palette 
    free(pPal);
}

#endif


