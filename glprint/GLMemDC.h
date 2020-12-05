// GLMemDC.h: interface for the CGLMemDC class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GLMEMDC_H__C73818C2_5732_11D3_955D_8422F5C00000__INCLUDED_)
#define AFX_GLMEMDC_H__C73818C2_5732_11D3_955D_8422F5C00000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CGLMemoryDC  
{
public:
	CGLMemoryDC();
	virtual ~CGLMemoryDC();

//data of DIB
private:
    HBITMAP      m_hBitmap;       //handle of bitmap
	BITMAPINFO   m_DIBInfo;       //infomation about the DIB
    BYTE*        m_hImage;        //DIB color data
	DWORD        m_dwDataSize;    //DIB data size 

    int          GetColorNumber(int nBitCount);

public:
	void         ClearMemory(void);
	BOOL         SetMemorySize(int width, int height);
	void         GetMemorySize(int* width, int* height);
	void         CopyDataFromDC(CDC* pDC, CRect& rect);
	void         CopyDataToDC(CDC* pDC, CRect& rect);
	void         WriteDataToDC(CDC* pDC, int startx, int starty);
	void         WriteDataToDIBfile(CFile* DIBFile);
};

#endif // !defined(AFX_GLMEMDC_H__C73818C2_5732_11D3_955D_8422F5C00000__INCLUDED_)
