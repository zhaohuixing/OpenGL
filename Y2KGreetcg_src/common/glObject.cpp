/**********************************************************/
/*   The glObject.cpp                                          
/*                                                         
/*   Created by Xing Zhaohui (xingzhh@yahoo.com),          
/*   Nov 10, 1999                                           
/*                                                        
/*   Declare the ellipsoid, word, cube objects
/* 
/**********************************************************/
#include "stdafx.h"
#include "glObjdef.h"

#define CUBELIST 20

/*********************************************************/
/*                                                       */
/*                                                       */
/*                                                       */
/*             The ellipsoid object clasee               */
/*                                                       */
/*                                                       */
/*                                                       */
/*********************************************************/

/**********************************************************/
/*   Construction                                         
/**********************************************************/
glEllipsoid::glEllipsoid() : CGLBaseObject()
{
	m_row = 0;
	m_col = 0;
    m_glEfficiency.clear();
    m_glVertex = NULL;
	m_glTexture = NULL;
    m_bLineArray = NULL;
    m_bHideArray = NULL;

	m_bSetVertex = FALSE;
	m_bSetTexture = FALSE;

	SetVertexFunc(&Ellipsoid);
	SetObjectType(GT_BALL);
}	


/**********************************************************/
/*   Destruction                                           
/**********************************************************/
glEllipsoid::~glEllipsoid()
{
	m_row = 0;
	m_col = 0;
    m_glEfficiency.clear();
	if(m_glVertex)
	{
		delete []m_glVertex;
		m_glVertex = NULL;
	}
    if(m_glTexture)
	{
		delete []m_glTexture;
		m_glTexture = NULL;
	}
    if(m_bLineArray)
	{
		delete []m_bLineArray;
		m_bLineArray = NULL;
	}
    if(m_bHideArray)
	{
		delete []m_bHideArray;
		m_bHideArray = NULL;
	}
}


/**********************************************************/
/*   Set the grid number of the object
/**********************************************************/
void glEllipsoid::SetSize(int row, int col)
{
	m_row = row;
	m_col = col;

    
	if(m_glVertex)
	{
		delete []m_glVertex;
	}
	m_glVertex = new glVertex[(m_row+1)*(m_col+1)];
	memset(m_glVertex, 0, (m_row+1)*(m_col+1)*sizeof(glVertex));
	
    if(m_bLineArray)
	{
		delete []m_bLineArray;
	}
    if(m_bHideArray)
	{
		delete []m_bHideArray;
	}
	
	m_bLineArray = new BOOL[m_row*m_col];
	memset(m_bLineArray, 0, m_row*m_col*sizeof(BOOL));
	m_bHideArray = new BOOL[m_row*m_col];
	memset(m_bHideArray, 0, m_row*m_col*sizeof(BOOL));

}


/**********************************************************/
/*   Set texture image size                                           
/**********************************************************/
void glEllipsoid::SetTextureSize(int tWidth, int tHeight)
{
	m_TexWidth = tWidth;
	m_TexHeight	= tHeight;

	if(m_glTexture)
		delete []m_glTexture;
	m_glTexture = (void*)new bTexture[m_TexWidth*m_TexHeight];
}


/**********************************************************/
/*   Set the texture unit increment of the object grid
/**********************************************************/
void glEllipsoid::SetTexCoord(double rowstart, double colstart, 
		             double row, double col)
{
	ASSERT(m_bSetVertex == TRUE);

	int k;
	for(int i = 0; i <= m_row; i++)
    {
	   for(int j = 0; j <= m_col; j++)
	   { 
          k = i * (m_col + 1) + j;
		  m_glVertex[k].m_Texture[0] = ((double)i) / row + rowstart;
		  if(m_glVertex[k].m_Texture[0] > 1.0)
               m_glVertex[k].m_Texture[0] -= 1.0;

		  m_glVertex[k].m_Texture[1] = ((double)j) / col + colstart;
		  if(m_glVertex[k].m_Texture[1] > 1.0)
              m_glVertex[k].m_Texture[1] -= 1.0;
	   }
	}
}



/**********************************************************/
/*   Set the texture unit increment of the object grid
/**********************************************************/
void glEllipsoid::SetTexCoord(int rowstart, int colstart)
{
	ASSERT(m_bSetVertex == TRUE);

	int k, i1, j1;
	int col2 = 2*m_col;
	for(int i = 0; i <= m_row; i++)
    {
       i1 = (i + rowstart) % m_row;
	   for(int j = 0; j <= m_col; j++)
	   { 
          j1 = (j + colstart) % col2;  
          k = i * (m_col + 1) + j;
		  m_glVertex[k].m_Texture[0] = ((double)i1) / ((double)m_row);

		  m_glVertex[k].m_Texture[1] = ((double)j1) / ((double)col2);
	   }
	}
}



/**********************************************************/
/*   Set the draw state: solid or wireframe
/**********************************************************/
void glEllipsoid::SetWireFrame(int rStart, int rEnd, 
		              int cStart, int cEnd, BOOL bLine)
{
    ASSERT(rStart >= 0 && rStart < m_row);
	if(rStart < 0 || rStart >= m_row)
		return;
    ASSERT(rEnd >= 0 && rEnd < m_row);
    if(rEnd < 0 || rEnd >= m_row)
		return;

    ASSERT(rEnd >= rStart);
    if(rEnd < rStart)
		return;

    ASSERT(cStart >= 0 && cStart < m_col);
	if(cStart < 0 || cStart >= m_col)
		return;
    ASSERT(cEnd >= 0 && cEnd < m_col);
    if(cEnd < 0 || cEnd >= m_col)
		return;

    ASSERT(cEnd >= cStart);
    if(cEnd < cStart)
		return;

	ASSERT(m_bLineArray != NULL);
	if(m_bLineArray == NULL)
		return;

	int index;
	for(int i = rStart; i <= rEnd; i++)
	{
	   for(int j = cStart; j <= cEnd; j++)
	   {
		   index = i * m_col + j;
		   m_bLineArray[index] = bLine;
	   }
	}
}


/**********************************************************/
/*   Set the draw state: hide or show
/**********************************************************/
void glEllipsoid::SetHideState(int rStart, int rEnd, 
		              int cStart, int cEnd, BOOL bHide)
{
    ASSERT(rStart >= 0 && rStart < m_row);
	if(rStart < 0 || rStart >= m_row)
		return;
    ASSERT(rEnd >= 0 && rEnd < m_row);
    if(rEnd < 0 || rEnd >= m_row)
		return;

    ASSERT(rEnd >= rStart);
    if(rEnd < rStart)
		return;

    ASSERT(cStart >= 0 && cStart < m_col);
	if(cStart < 0 || cStart >= m_col)
		return;
    ASSERT(cEnd >= 0 && cEnd < m_col);
    if(cEnd < 0 || cEnd >= m_col)
		return;

    ASSERT(cEnd >= cStart);
    if(cEnd < cStart)
		return;

	ASSERT(m_bHideArray != NULL);
	if(m_bHideArray == NULL)
		return;

	int index;
	for(int i = rStart; i <= rEnd; i++)
	{
	   for(int j = cStart; j <= cEnd; j++)
	   {
		   index = i * m_col + j;
		   m_bHideArray[index] = bHide;
	   }
	}
}


/**********************************************************/
/*   Set the efficiencies of the equation of the object
/**********************************************************/
void glEllipsoid::SetEfficiency(double* Efficiency, int num)
{
    m_glEfficiency.clear();

	for(int i = 0; i < num; i++)
		m_glEfficiency.push_back(Efficiency[i]);
}


/**********************************************************/
/*   Set the efficiencies of the texture
/**********************************************************/
void glEllipsoid::SetTexEfficiency(double* tEfficiency, int num)
{
    m_tEfficiency.clear();

	for(int i = 0; i < num; i++)
		m_tEfficiency.push_back(tEfficiency[i]);
}


/**********************************************************/
/*   Reset the draw state
/**********************************************************/
void glEllipsoid::ResetWireFrame(void)
{
	ASSERT(m_bLineArray != NULL);
	if(m_bLineArray == NULL)
		return;
	
	memset(m_bLineArray, 0, m_row*m_col*sizeof(BOOL));
}


/**********************************************************/
/*   Reset the draw state
/**********************************************************/
void glEllipsoid::ResetHideState(void)
{
	ASSERT(m_bHideArray != NULL);
	if(m_bHideArray == NULL)
		return;
	
	memset(m_bHideArray, 0, m_row*m_col*sizeof(BOOL));
}


/**********************************************************/
/*   Get the grid number
/**********************************************************/
void glEllipsoid::GetSize(int* row, int* col)
{
	*row = m_row;
	*col = m_col;
}


/**********************************************************/
/*   Get the draw state
/**********************************************************/
BOOL glEllipsoid::GetWireFrame(int row, int col, BOOL* bLine)
{
    ASSERT(row >= 0 && row < m_row);
	if(row < 0 || row >= m_row)
		return FALSE;

    ASSERT(col >= 0 && col < m_col);
    if(col < 0 || col >= m_col)
		return FALSE;
    ASSERT(m_bLineArray != NULL);
	if(m_bLineArray == NULL)
		return FALSE;

	int index;
	index = row * m_col + col;
	*bLine = m_bLineArray[index];
	return TRUE;

}


/**********************************************************/
/*   Get the draw state
/**********************************************************/
BOOL glEllipsoid::GetHideState(int row, int col, BOOL* bHide)
{
    ASSERT(row >= 0 && row < m_row);
	if(row < 0 || row >= m_row)
		return FALSE;

    ASSERT(col >= 0 && col < m_col);
    if(col < 0 || col >= m_col)
		return FALSE;
    ASSERT(m_bHideArray != NULL);
	if(m_bHideArray == NULL)
		return FALSE;

	int index;
	index = row * m_col + col;
	*bHide = m_bHideArray[index];
	return TRUE;
}


/**********************************************************/
/*   Get the size of texture image
/**********************************************************/
void glEllipsoid::GetTextureSize(int* tWidth, int* tHeight)
{
	*tWidth = m_TexWidth;
	*tHeight = m_TexHeight;
}


/**********************************************************/
/*   Set the function to build the vertexs
/**********************************************************/
void glEllipsoid::SetVertexFunc(BOOL (*vFunc)(int row, int col, 
		                      xEfficiency  glEfficiency,
							  glVertex* glVerArray))
{
	SetVertex = *vFunc;
}


/**********************************************************/
/*   Set the function to build the texture image
/**********************************************************/
void glEllipsoid::SetTextureFunc(BOOL (*tFunc)(int TexWidth, int TexHeight, 
		                xEfficiency  tEfficiency,
		                bTexture* glTexture))
{
	SetTexture = *tFunc;
}


/**********************************************************/
/*   Build the coordinate and normal value of the grids
/**********************************************************/
void glEllipsoid::BuildVertex(void)
{
	ASSERT(m_glVertex != NULL);
	if(m_glVertex == NULL)
		return;

	m_bSetVertex =
		this->SetVertex(m_row, m_col, m_glEfficiency, m_glVertex);
}


/**********************************************************/
/*   Build the texture
/**********************************************************/
void glEllipsoid::BuildTexture(void)
{
	ASSERT(m_glTexture != NULL);
	if(m_glTexture == NULL)
		return;

	m_bSetTexture =
	    this->SetTexture(m_TexWidth, m_TexHeight, m_tEfficiency, 
		                 (bTexture*)m_glTexture);
}


/**********************************************************/
/*   Build the texture from resource
/**********************************************************/
void glEllipsoid::BuildBMPTexture(UINT ResID)
{
	HRSRC             hSrc;
	HGLOBAL           hMem;
	void*             pData;
	CFile             file;
	BITMAPFILEHEADER  BmpFileHeader;
	BITMAPINFOHEADER  BmpInfoHeader;      

	if(m_glTexture)
		delete []m_glTexture;

	//Get the bitmap file header 
	if (!file.Open("Ball", CFile::modeCreate | CFile::modeWrite, NULL))
	{
		AfxMessageBox("Can't create temperary file");
	    return ;
	}
	
	// find the resource
	hSrc = FindResource(AfxGetInstanceHandle(), MAKEINTRESOURCE(ResID), "DIB");
	if (hSrc == NULL)
	{
		AfxMessageBox("Can not find the reource");
		return ;
	}

	// load the resource
	hMem = LoadResource(AfxGetInstanceHandle(), hSrc);
	if (hMem == NULL)
	{
		AfxMessageBox("Can not load the resource data");
		return ;
	}

	// lock the resource
	pData = LockResource(hMem);
	if (pData == NULL)
	{
		AfxMessageBox("Can not lock the memory for resource data");
		return ;		
	}

	// write the resource to the file
	file.Write(pData, SizeofResource(AfxGetInstanceHandle(), hSrc));
	file.Close();

	//Get the bitmap file header 
	if (!file.Open("Ball", CFile::modeRead, NULL))
	{
		AfxMessageBox("Can't open temperary file");
		m_bSetTexture = FALSE;
	    return;
	}
	
	//Get the bitmap file header 
	file.Read(&BmpFileHeader,sizeof(BITMAPFILEHEADER));

	//Get the bitmap infomation header 
	file.Read(&BmpInfoHeader, sizeof(BITMAPINFOHEADER));

	//set the texture size
	m_TexWidth = BmpInfoHeader.biWidth;
	m_TexHeight	= BmpInfoHeader.biHeight;
    
	m_glTexture = new BYTE[BmpInfoHeader.biSizeImage];
    
	file.Read(m_glTexture, BmpInfoHeader.biSizeImage);

	//Close the file
	file.Close();
	file.Remove("Ball");
	
	m_bSetTexture = TRUE;
}


/**********************************************************/
/*   Draw the object
/**********************************************************/
void glEllipsoid::DrawObject(void)
{
	ASSERT(m_bSetVertex == TRUE);
	ASSERT(m_bSetTexture == TRUE);


	glEnable(GL_TEXTURE_2D);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    
	gluBuild2DMipmaps(GL_TEXTURE_2D, 4, m_TexWidth, m_TexHeight, 
              GL_BGR_EXT, GL_UNSIGNED_BYTE, m_glTexture);

    glMatrixMode(GL_MODELVIEW);
    glShadeModel(GL_SMOOTH);

	int index;
	int i, j, k;
	for(i = 0; i < m_row; i++)
    {
	   for(j = 0; j < m_col; j++)
	   { 
          index = i * m_col + j;
          if(m_bHideArray[index] == FALSE)
		  {
             if(m_bLineArray[index] == TRUE)
      	        glBegin(GL_LINE_LOOP);
    	     else
			    glBegin(GL_QUADS);
	          
	         k = i * (m_col + 1) + j;
		     glTexCoord2dv(m_glVertex[k].m_Texture);
	         glNormal3dv(m_glVertex[k].m_Normal.GetXYZ()); 
			 glVertex3dv(m_glVertex[k].m_Vertex.GetXYZ());
              
		     k = i * (m_col + 1) + j + 1;
		     glTexCoord2dv(m_glVertex[k].m_Texture);
	         glNormal3dv(m_glVertex[k].m_Normal.GetXYZ()); 
			 glVertex3dv(m_glVertex[k].m_Vertex.GetXYZ());

		     k = (i + 1) * (m_col + 1) + j + 1;
		     glTexCoord2dv(m_glVertex[k].m_Texture);
	         glNormal3dv(m_glVertex[k].m_Normal.GetXYZ()); 
			 glVertex3dv(m_glVertex[k].m_Vertex.GetXYZ());

		     k = (i + 1) * (m_col + 1) + j ;
		     glTexCoord2dv(m_glVertex[k].m_Texture);
	         glNormal3dv(m_glVertex[k].m_Normal.GetXYZ()); 
			 glVertex3dv(m_glVertex[k].m_Vertex.GetXYZ());

		     glEnd();
		  }
	   }
	}
	glDisable(GL_TEXTURE_2D);
}


/*********************************************************/
/*                                                       */
/*                                                       */
/*                                                       */
/*             The 3D font object class                  */ 
/*                                                       */
/*                                                       */
/*                                                       */
/*********************************************************/

/**********************************************************/
/*   Construction                                         
/**********************************************************/
glWord::glWord() : CGLBaseObject()
{
	m_glFont.SetFontType(GL_FONT_SOLID);
	m_glFont.SetFontSize(0.1);
	m_glFont.SetText("Happy 2000");
	m_bSetFont = FALSE;
	m_bSetTexture = FALSE;
	m_glTexture = NULL;
}


/**********************************************************/
/*   Destruction                                           
/**********************************************************/
glWord::~glWord()
{
	if(m_glTexture)
		delete []m_glTexture;
}

/**********************************************************/
/*   Set texture image size                                           
/**********************************************************/
void glWord::SetTextureSize(int tWidth, int tHeight)
{
	m_TexWidth = tWidth;
	m_TexHeight = tHeight;

	if(m_glTexture)
		delete []m_glTexture;
	m_glTexture = new bTexture[m_TexWidth*m_TexHeight];
}


/**********************************************************/
/*   Get texture image size                                           
/**********************************************************/
void glWord::GetTextureSize(int* tWidth, int* tHeight)
{
	*tWidth = m_TexWidth;
	*tHeight = m_TexHeight;
}


/**********************************************************/
/*   Set the efficiency of texture image                                           
/**********************************************************/
void glWord::SetTexEfficiency(double* tEfficiency, int num)
{
    m_tEfficiency.clear();

	for(int i = 0; i < num; i++)
		m_tEfficiency.push_back(tEfficiency[i]);
}


/**********************************************************/
/*   Set the font type: solid or wireframe                                           
/**********************************************************/
void glWord::SetFontType(GLFontType FontType)
{
	m_glFont.SetFontType(FontType);
}


/**********************************************************/
/*   Get the font type: solid or wireframe                                           
/**********************************************************/
void glWord::SetFontSize(double dThick)
{
	m_glFont.SetFontSize(dThick);
}


/**********************************************************/
/*   Set the string to show
/**********************************************************/
void glWord::SetFontText(char* strText)
{
	m_glFont.SetText(strText);
}


/**********************************************************/
/*   Set the function to build the texture image
/**********************************************************/
void glWord::SetTextureFunc(BOOL (*tFunc)(int TexWidth, int TexHeight, 
		                xEfficiency  tEfficiency,
		                bTexture* glTexture))
{
	SetTexture = *tFunc;
}


/**********************************************************/
/*   Build the 3D font
/**********************************************************/
void glWord::BuildFont(CDC* pDC, char* fontname)
{
	ASSERT(m_bSetTexture == TRUE);


	glEnable(GL_TEXTURE_2D);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	
	glTexImage2D(GL_TEXTURE_2D, 0, 4, m_TexWidth, m_TexHeight, 
		 0, GL_RGBA, GL_UNSIGNED_BYTE, m_glTexture);
    
	glMatrixMode(GL_MODELVIEW);
    glShadeModel(GL_SMOOTH);
	
	m_bSetFont = m_glFont.CreateFont(pDC, fontname);

	glDisable(GL_TEXTURE_2D);
}


/**********************************************************/
/*   Build the texture
/**********************************************************/
void glWord::BuildTexture(void)
{
	ASSERT(m_glTexture != NULL);
	if(m_glTexture == NULL)
		return;

	m_bSetTexture =
	    this->SetTexture(m_TexWidth, m_TexHeight, m_tEfficiency, m_glTexture);
}


/**********************************************************/
/*   Draw 3D font
/**********************************************************/
void glWord::DrawObject(void)
{
	ASSERT(m_bSetFont == TRUE);

	m_glFont.GLDrawText();
	
}


/*********************************************************/
/*                                                       */
/*                                                       */
/*                                                       */
/*               3D Cube object class                    */
/*                                                       */
/*                                                       */
/*                                                       */
/*********************************************************/

/**********************************************************/
/*   Construction                                         
/**********************************************************/
glCube::glCube() : CGLBaseObject()
{
	m_uiListID = 0;
	m_glTexture = NULL;
	m_bSetTexture = FALSE;
    m_dLength = 1.0;
}


/**********************************************************/
/*   Destruction                                           
/**********************************************************/
glCube::~glCube()
{
    if(m_uiListID != 0)
        glDeleteLists(m_uiListID, CUBELIST);
	
	if(m_glTexture)
		delete []m_glTexture;
}


/**********************************************************/
/*   Set texture image size                                           
/**********************************************************/
void glCube::SetTextureSize(int tWidth, int tHeight)
{
	m_TexWidth = tWidth;
	m_TexHeight = tHeight;

	if(m_glTexture)
		delete []m_glTexture;
	m_glTexture = new bTexture[m_TexWidth*m_TexHeight];
}


/**********************************************************/
/*   Set the efficiency of texture image                                           
/**********************************************************/
void glCube::SetTexEfficiency(double* tEfficiency, int num)
{
    m_tEfficiency.clear();

	for(int i = 0; i < num; i++)
		m_tEfficiency.push_back(tEfficiency[i]);
}

	
/**********************************************************/
/*   Set the function to build the texture image
/**********************************************************/
void glCube::SetTextureFunc(BOOL (*tFunc)(int TexWidth, int TexHeight, 
		                xEfficiency  tEfficiency,
		                bTexture* glTexture))
{
	SetTexture = *tFunc;
}


/**********************************************************/
/*   Set the length of the cube side
/**********************************************************/
void glCube::SetLength(double dLength)
{
    m_dLength = dLength;
}

/**********************************************************/
/*   Get the length of the cube side
/**********************************************************/
void glCube::GetLength(double* dLength) 
{
    *dLength = m_dLength;
}


/**********************************************************/
/*   Build the vertexs of the cube
/**********************************************************/
void glCube::BuildVertex(void)
{
	ASSERT(m_bSetTexture == TRUE);

	m_uiListID = glGenLists(CUBELIST);
    ASSERT(m_uiListID > 0);

	glNewList(m_uiListID, GL_COMPILE_AND_EXECUTE);

	glEnable(GL_TEXTURE_2D);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    
	gluBuild2DMipmaps(GL_TEXTURE_2D, 4, m_TexWidth, m_TexHeight, 
              GL_BGR_EXT, GL_UNSIGNED_BYTE, m_glTexture);

    glMatrixMode(GL_MODELVIEW);
    glShadeModel(GL_SMOOTH);

	double tu = 1.0 / 6.0;
	
	//#1 side of the cube
	glBegin(GL_POLYGON);
		glNormal3d(0.0, 1.0, 0.0);

		glTexCoord2f(0.0, 0.0); 
		glVertex3d(-m_dLength, m_dLength, m_dLength);
		
		glTexCoord2f(1.0, 0.0); 
		glVertex3d(m_dLength, m_dLength, m_dLength);
		
		glTexCoord2f(1.0, tu); 
		glVertex3d(m_dLength, m_dLength, -m_dLength);
		
		glTexCoord2f(0.0, tu); 
		glVertex3d(-m_dLength, m_dLength, -m_dLength);
	glEnd();
	
	//#2 side of the cube
	glBegin(GL_POLYGON);
		glNormal3d(0.0, -1.0, 0.0);

		glTexCoord2d(0.0, tu); 
		glVertex3d(-m_dLength, -m_dLength, m_dLength);
		
		glTexCoord2d(1.0, tu); 
		glVertex3d(m_dLength, -m_dLength, m_dLength);
		
		glTexCoord2d(1.0, 2.0*tu); 
		glVertex3d(m_dLength, -m_dLength, -m_dLength);
		
		glTexCoord2d(0.0, 2.0*tu); 
		glVertex3d(-m_dLength, -m_dLength, -m_dLength);
	glEnd();

	//#3 side of the cube
	glBegin(GL_POLYGON);
		glNormal3d(1.0, 0.0, 0.0);

		glTexCoord2d(0.0, 2.0*tu); 
		glVertex3d(m_dLength, m_dLength, m_dLength);
		
		glTexCoord2d(1.0, 2.0*tu); 
		glVertex3d(m_dLength, m_dLength, -m_dLength);
		
		glTexCoord2d(1.0, 3.0*tu); 
		glVertex3d(m_dLength, -m_dLength, -m_dLength);
		
		glTexCoord2d(0.0, 3.0*tu); 
		glVertex3d(m_dLength, -m_dLength, m_dLength);
	glEnd();


	//#4 side of the cube
	glBegin(GL_POLYGON);
		glNormal3d(-1.0, 0.0, 0.0);
		
		glTexCoord2d(0.0, 3.0*tu); 
		glVertex3d(-m_dLength, m_dLength, m_dLength);
		
		glTexCoord2d(1.0, 3.0*tu); 
		glVertex3d(-m_dLength, m_dLength, -m_dLength);
		
		glTexCoord2d(1.0, 4.0*tu); 
		glVertex3d(-m_dLength, -m_dLength, -m_dLength);
		
		glTexCoord2d(0.0, 4.0*tu); 
		glVertex3d(-m_dLength, -m_dLength, m_dLength);
	glEnd();

	//#5 side of the cube
	glBegin(GL_POLYGON);
		glNormal3d(0.0, 0.0, 1.0);
		
		glTexCoord2d(0.0, 4.0*tu); 
		glVertex3d(m_dLength, m_dLength, m_dLength);
		
		glTexCoord2d(1.0, 4.0*tu); 
		glVertex3d(m_dLength, -m_dLength, m_dLength);
		
		glTexCoord2d(1.0, 5.0*tu); 
		glVertex3d(-m_dLength, -m_dLength, m_dLength);
		
		glTexCoord2d(0.0, 5.0*tu); 
		glVertex3d(-m_dLength, m_dLength, m_dLength);
	glEnd();

	//#6 side of the cube
	glBegin(GL_POLYGON);
		glNormal3d(0.0, 0.0, -1.0);
		
		glTexCoord2d(0.0, 5.0*tu); 
		glVertex3d(-m_dLength, m_dLength, -m_dLength);
		
		glTexCoord2d(1.0, 5.0*tu); 
		glVertex3d(-m_dLength, -m_dLength, -m_dLength);
		
		glTexCoord2d(1.0, 6.0*tu); 
		glVertex3d(m_dLength, -m_dLength, -m_dLength);
		
		glTexCoord2f(0.0, 6.0*tu); 
		glVertex3d(m_dLength,  m_dLength, -m_dLength);
	glEnd();

	
	glDisable(GL_TEXTURE_2D);

	glEndList();
}


/**********************************************************/
/*   Build the texure
/**********************************************************/
void glCube::BuildTexture(void)
{
	ASSERT(m_glTexture != NULL);
	if(m_glTexture == NULL)
		return;

	m_bSetTexture =
	    this->SetTexture(m_TexWidth, m_TexHeight, m_tEfficiency, 
		                 (bTexture*)m_glTexture);
}


/**********************************************************/
/*   Build the texure from reource
/**********************************************************/
void glCube::BuildBMPTexture(UINT ResID)
{
	HRSRC             hSrc;
	HGLOBAL           hMem;
	void*             pData;
	CFile             file;
	BITMAPFILEHEADER  BmpFileHeader;
	BITMAPINFOHEADER  BmpInfoHeader;      

	if(m_glTexture)
		delete []m_glTexture;

	//Get the bitmap file header 
	if (!file.Open("Cube", CFile::modeCreate | CFile::modeWrite, NULL))
	{
		AfxMessageBox("Can't create temperary file");
	    return ;
	}
	
	// find the resource
	hSrc = FindResource(AfxGetInstanceHandle(), MAKEINTRESOURCE(ResID), "DIB");
	if (hSrc == NULL)
	{
		AfxMessageBox("Can not find the reource");
		return ;
	}

	// load the resource
	hMem = LoadResource(AfxGetInstanceHandle(), hSrc);
	if (hMem == NULL)
	{
		AfxMessageBox("Can not load the resource data");
		return ;
	}

	// lock the resource
	pData = LockResource(hMem);
	if (pData == NULL)
	{
		AfxMessageBox("Can not lock the memory for resource data");
		return ;		
	}

	// write the resource to the file
	file.Write(pData, SizeofResource(AfxGetInstanceHandle(), hSrc));
	file.Close();

	//Get the bitmap file header 
	if (!file.Open("Cube", CFile::modeRead, NULL))
	{
		AfxMessageBox("Can't open temperary file");
		m_bSetTexture = FALSE;
	    return;
	}
	
	//Get the bitmap file header 
	file.Read(&BmpFileHeader,sizeof(BITMAPFILEHEADER));

	//Get the bitmap infomation header 
	file.Read(&BmpInfoHeader, sizeof(BITMAPINFOHEADER));

	//set the texture size
	m_TexWidth = BmpInfoHeader.biWidth;
	m_TexHeight	= BmpInfoHeader.biHeight;
    
	m_glTexture = new BYTE[BmpInfoHeader.biSizeImage];
    
	file.Read(m_glTexture, BmpInfoHeader.biSizeImage);

	//Close the file
	file.Close();
	file.Remove("Cube");
	
	m_bSetTexture = TRUE;
}


/**********************************************************/
/*   Draw the cube
/**********************************************************/
void glCube::DrawObject(void)
{
    ASSERT(m_uiListID > 0);
	
	glCallList(m_uiListID);
}











