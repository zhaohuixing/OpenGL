// GLMemDC.cpp: implementation of the CGLMemDC class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "GLMemDC.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CGLMemoryDC::CGLMemoryDC()
{
    m_hBitmap = NULL;      
	memset(&m_DIBInfo, 0, sizeof(BITMAPINFO));  
    m_hImage = NULL; 
	m_dwDataSize = 0;    
}

CGLMemoryDC::~CGLMemoryDC()
{
	ClearMemory();
}


/********************************************************************/
/* Get the color entries number of the image             		    */
/********************************************************************/
int CGLMemoryDC::GetColorNumber(int nBitCount)
{
	int ColorTableEntries;

    switch(nBitCount)
	{
	    case 1:            //Black and White 
	        ColorTableEntries = 2;
	    case 4:            //16 colors 
	        ColorTableEntries = 16;
	    case 8:            //256 colors 
	        ColorTableEntries = 256;
	    case 16:             
	    case 24:            
	    case 32:            
			ColorTableEntries = 0;
		break;
	}
	
	return ColorTableEntries;
}


/********************************************************************/
/* Clear all memory   											    */
/********************************************************************/
void CGLMemoryDC::ClearMemory(void)
{
    if(m_hBitmap)
		DeleteObject(m_hBitmap);
	m_hBitmap = NULL;      
	memset(&m_DIBInfo, 0, sizeof(BITMAPINFO));  
    m_hImage = NULL; 
	m_dwDataSize = 0;    
}


/********************************************************************/
/* Set the memory device size   								    */
/********************************************************************/
BOOL CGLMemoryDC::SetMemorySize(int width, int height)
{
	//clear every thing
	ClearMemory();

	//set DIB image header information
	//just support true color bitmap
	m_DIBInfo.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	m_DIBInfo.bmiHeader.biCompression = BI_RGB;
    m_DIBInfo.bmiHeader.biPlanes = 1;
    m_DIBInfo.bmiHeader.biBitCount = 32;
    m_DIBInfo.bmiHeader.biWidth = width;
    m_DIBInfo.bmiHeader.biHeight = height;
    m_DIBInfo.bmiHeader.biSizeImage = width*height*4;

	//craete the BITMAP color data memory
    m_hBitmap = CreateDIBSection(
		        NULL,
				&m_DIBInfo,
				DIB_RGB_COLORS,
				(void **)&m_hImage,
                NULL,
				NULL);
    
	//if sucess
	if(m_hBitmap)
		return TRUE;
	else
        return FALSE;   
}


/********************************************************************/
/* Get the memory device size   								    */
/********************************************************************/
void CGLMemoryDC::GetMemorySize(int* width, int* height)
{
    *width = m_DIBInfo.bmiHeader.biWidth;
    *height = m_DIBInfo.bmiHeader.biHeight;
}


/********************************************************************/
/* Scan the image from the device context   					    */
/********************************************************************/
void CGLMemoryDC::CopyDataFromDC(CDC* pDC, CRect& rect)
{
	CDC      dcBuffer;       //the compatible DC 
	CBitmap  bmBitmap;		 //bitmap in memory for retreive data from DC
	CBitmap* pbmBitmapOld;

	//if the orignal bitmap did not set up
	if(!m_hBitmap)
        return;

	//create compatible DC to copy image
	dcBuffer.CreateCompatibleDC(pDC);

	//create memory bitmap 
    bmBitmap.CreateCompatibleBitmap(pDC,
                  m_DIBInfo.bmiHeader.biWidth,
                  m_DIBInfo.bmiHeader.biHeight);
    
	//set memory bitmap to memory DC
	pbmBitmapOld = dcBuffer.SelectObject(&bmBitmap);
    
	//copy source DC image to memory bitmap
	dcBuffer.StretchBlt(0, 0,  
             m_DIBInfo.bmiHeader.biWidth,
	         m_DIBInfo.bmiHeader.biHeight,
			 pDC, 
             rect.left,
			 rect.top,
			 rect.Width(),
			 rect.Height(),
			 SRCCOPY);

	//restore the orginal object in memory DC
    dcBuffer.SelectObject(pbmBitmapOld);

	//copy image data from memory bitmap
	GetDIBits(pDC->m_hDC,
		(HBITMAP)bmBitmap, 
		0, 
        m_DIBInfo.bmiHeader.biHeight,
        m_hImage,
		&m_DIBInfo,
		DIB_RGB_COLORS);
}


/********************************************************************/
/* Copy image data to target DC             					    */
/*                                                                  */ 
/* This function just support the color printer setting in Text     */
/* mode																*/
/********************************************************************/
void CGLMemoryDC::CopyDataToDC(CDC* pDC, CRect& rect)
{
    ::StretchDIBits(pDC->m_hDC, 
		            rect.left, 
					rect.top, 
		            rect.Width(), 
					rect.Height(),
                    0, 0, 
					m_DIBInfo.bmiHeader.biWidth, 
					m_DIBInfo.bmiHeader.biHeight,
                    m_hImage,  
					&m_DIBInfo, 
					DIB_RGB_COLORS, 
					SRCCOPY);
}


/********************************************************************/
/* Write image data directly to target DC             				*/
/*                                                                  */ 
/* This function just support the color printer setting in Photo    */
/* quality mode														*/
/********************************************************************/
void CGLMemoryDC::WriteDataToDC(CDC* pDC, int startx, int starty)
{
    ::SetDIBitsToDevice(pDC->m_hDC, 
		                startx, 
						starty,
                        m_DIBInfo.bmiHeader.biWidth,
	                    m_DIBInfo.bmiHeader.biHeight,
                        0, 0, 0,
	                    m_DIBInfo.bmiHeader.biHeight,
                        m_hImage, 
						&m_DIBInfo, 
						DIB_RGB_COLORS);
           			 
}


/********************************************************************/
/* Write image data to a DIB file (disk file)  					    */
/********************************************************************/
void CGLMemoryDC::WriteDataToDIBfile(CFile* DIBFile)
{
    BITMAPFILEHEADER  bmFileHeader;
    BITMAPINFOHEADER  bmInfoHeader;
    int     nByte = sizeof(RGBQUAD)*GetColorNumber(m_DIBInfo.bmiHeader.biBitCount);
	void*   PaletteEntry;
	
	//prepare image header data
	bmFileHeader.bfType = 0x4d42;   
    bmFileHeader.bfSize = 0;
	bmFileHeader.bfReserved1 = 0;
	bmFileHeader.bfReserved2 = 0;
	bmFileHeader.bfOffBits = sizeof(BITMAPFILEHEADER)
                    		 + sizeof(BITMAPINFOHEADER)
		                     + nByte;
	
	//write image header data to DIB file
	DIBFile->Write((LPVOID)&bmFileHeader,sizeof(BITMAPFILEHEADER)); 
	
	//prepare image header information data
	bmInfoHeader.biSize = m_DIBInfo.bmiHeader.biSize;
	bmInfoHeader.biCompression = m_DIBInfo.bmiHeader.biCompression;
    bmInfoHeader.biPlanes = m_DIBInfo.bmiHeader.biPlanes;
    bmInfoHeader.biBitCount = m_DIBInfo.bmiHeader.biBitCount;
    bmInfoHeader.biWidth = m_DIBInfo.bmiHeader.biWidth;
    bmInfoHeader.biHeight = m_DIBInfo.bmiHeader.biHeight;
    bmInfoHeader.biSizeImage = m_DIBInfo.bmiHeader.biSizeImage;
    bmInfoHeader.biClrUsed = m_DIBInfo.bmiHeader.biClrUsed;
	
	//write image header information data to DIB file
	DIBFile->Write((LPVOID)&bmInfoHeader,sizeof(BITMAPINFOHEADER)); 
    
    nByte = sizeof(RGBQUAD)*GetColorNumber(m_DIBInfo.bmiHeader.biBitCount);
    
	//wrtie the palette and color data to DIB file
	DIBFile->Write(PaletteEntry, nByte); 
	DIBFile->Write(m_hImage, m_DIBInfo.bmiHeader.biSizeImage);
}