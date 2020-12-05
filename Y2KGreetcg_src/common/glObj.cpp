/**********************************************************/
/*   The glObj.h                                          
/*                                                         
/*   Created by Xing Zhaohui (xingzhh@yahoo.com),          
/*   Oct 4, 1999                                           
/*                                                        
/*   Implement the basic OpenGL object class from which different
/*   kinds of objects can be derived        
/*        
/**********************************************************/

#include "stdafx.h"
#include "glObj.h"

/*********************************************************/
/*                                                       */
/*                                                       */
/*                                                       */
/*           The basic 3D OpenGL object clasee           */
/*                                                       */
/*                                                       */
/*                                                       */
/*********************************************************/

/**********************************************************/
/* Construction
/**********************************************************/

CGLBaseObject::CGLBaseObject()
{
	InitProperty();
}


/**********************************************************/
/* Destruction
/**********************************************************/
CGLBaseObject::~CGLBaseObject()
{
}


/**********************************************************/
/* Render the object
/**********************************************************/
void CGLBaseObject::Render(void)
{
	glPushMatrix(); 
	SetProperty(); 
	Transform();
	DrawObject();
	Restore();
    glPopMatrix();
}


/**********************************************************/
/* Initialize the material property and transfrom, scale,
/* rotation
/**********************************************************/
void CGLBaseObject::InitProperty(void)
{
	m_glAmbient[0] = 0.04f;
	m_glAmbient[1] = 0.04f;
	m_glAmbient[2] = 0.04f;
	m_glAmbient[3] = 0.1f;

	m_glEmission[0] = 0.5f;
	m_glEmission[1] = 0.5f;
	m_glEmission[2] = 0.5f;
	m_glEmission[3] = 0.1f;

	m_glDiffuse[0] = 0.01f;
	m_glDiffuse[1] = 0.01f;
	m_glDiffuse[2] = 0.01f;
	m_glDiffuse[3] = 0.1f;

	m_glSpecular[0] = 0.01f;
	m_glSpecular[1] = 0.01f;
	m_glSpecular[2] = 0.01f;
	m_glSpecular[3] = 1.0f;

    m_glShininess = 10.1f; 

	m_dTX = 0.0;
	m_dTY = 0.0;
	m_dTZ = 0.0;
	m_dSX = 1.0;
	m_dSY = 1.0;
	m_dSZ = 1.0;
	m_dRX = 0.0;
	m_dRY = 0.0;
	m_dRZ = 0.0;
}


/**********************************************************/
/* Set the material property of the object
/**********************************************************/
void CGLBaseObject::SetProperty(void)
{
	glEnable(GL_COLOR_MATERIAL);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &m_glShininess);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR,  m_glSpecular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,  m_glDiffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,  m_glAmbient);
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION,  m_glEmission);
    glColorMaterial(GL_FRONT_AND_BACK,  GL_DIFFUSE);
	glPolygonMode(GL_FRONT,GL_FILL);
	glPolygonMode(GL_BACK,GL_FILL);
    glShadeModel(GL_SMOOTH);
    glMatrixMode(GL_MODELVIEW);
}


/**********************************************************/
/* Set the transformation , scale, rotation of the object 
/**********************************************************/
void CGLBaseObject::Transform(void)
{
	double dX, dY, dZ;

//    glMatrixMode(GL_MODELVIEW);

    glTranslated(m_dTX, m_dTY, m_dTZ);
	
	if(m_dSX != 0.0)
	    dX = m_dSX;
	else
	    dX = 1.0;
	
	if(m_dSY != 0.0)
	    dY = m_dSY;
	else
		dY = 1.0;
	if(m_dSZ != 0.0)
	    dZ = m_dSZ;
	else
		dZ= 1.0;
	glScaled(dX, dY, dZ);

	glRotated(m_dRX, 1.0, 0.0, 0.0);
	glRotated(m_dRY, 0.0, 1.0, 0.0);
	glRotated(m_dRZ, 0.0, 0.0, 1.0);
}


/**********************************************************/
/* Set the objects to orignal space state (no any change) 
/**********************************************************/
void CGLBaseObject::Restore(void)
{
	double dX, dY, dZ;

	dX = m_dRX * -1.0;
	dY = m_dRY * -1.0;
	dZ = m_dRZ * -1.0;
	glRotated(dZ, 0.0, 0.0, 1.0);
	glRotated(dY, 0.0, 1.0, 0.0);
	glRotated(dX, 1.0, 0.0, 0.0);


	if(m_dSX != 0.0)
	    dX = 1.0/m_dSX;
	else
	    dX = 1.0;
	
	if(m_dSY != 0.0)
	    dY = 1.0/m_dSY;
	else
		dY = 1.0;
	if(m_dSZ != 0.0)
	    dZ = 1.0/m_dSZ;
	else
		dZ= 1.0;
	glScaled(dX, dY, dZ);


	dX = m_dTX * -1.0;
	dY = m_dTY * -1.0;
	dZ = m_dTZ * -1.0;
    glTranslated(dX, dY, dZ);
}


/**********************************************************/
/* Set the ambient of material 
/**********************************************************/
void CGLBaseObject::SetAmbient(float* Ambient)
{
	m_glAmbient[0] = Ambient[0];
	m_glAmbient[1] = Ambient[1];
	m_glAmbient[2] = Ambient[2];
	m_glAmbient[3] = Ambient[3];
}


/**********************************************************/
/* Get the ambient of material 
/**********************************************************/
void CGLBaseObject::GetAmbient(float* Ambient)
{
	Ambient[0] = m_glAmbient[0];
	Ambient[1] = m_glAmbient[1];
	Ambient[2] = m_glAmbient[2];
	Ambient[3] = m_glAmbient[3];
}


/**********************************************************/
/* Set the emission of material 
/**********************************************************/
void CGLBaseObject::SetEmission(float* Emission)
{
	m_glEmission[0] = Emission[0];
	m_glEmission[1] = Emission[1];
	m_glEmission[2] = Emission[2];
	m_glEmission[3] = Emission[3];
}


/**********************************************************/
/* Get the emission of material 
/**********************************************************/
void CGLBaseObject::GetEmission(float* Emission)
{
	Emission[0] = m_glEmission[0];
	Emission[1] = m_glEmission[1];
	Emission[2] = m_glEmission[2];
	Emission[3] = m_glEmission[3];
}


/**********************************************************/
/* Set the diffuse of material 
/**********************************************************/
void CGLBaseObject::SetDiffuse(float* Diffuse)
{
	m_glDiffuse[0] = Diffuse[0];
	m_glDiffuse[1] = Diffuse[1];
	m_glDiffuse[2] = Diffuse[2];
	m_glDiffuse[3] = Diffuse[3];
}


/**********************************************************/
/* Get the diffuse of material 
/**********************************************************/
void CGLBaseObject::GetDiffuse(float* Diffuse)
{
	Diffuse[0] = m_glDiffuse[0];
	Diffuse[1] = m_glDiffuse[1];
	Diffuse[2] = m_glDiffuse[2];
	Diffuse[3] = m_glDiffuse[3];
}


/**********************************************************/
/* Set the specular of material 
/**********************************************************/
void CGLBaseObject::SetSpecular(float* Specular)
{
	m_glSpecular[0] = Specular[0];
	m_glSpecular[1] = Specular[1];
	m_glSpecular[2] = Specular[2];
	m_glSpecular[3] = Specular[3];
}


/**********************************************************/
/* Get the specular of material 
/**********************************************************/
void CGLBaseObject::GetSpecular(float* Specular)
{
	Specular[0] = m_glSpecular[0];
	Specular[1] = m_glSpecular[1];
	Specular[2] = m_glSpecular[2];
	Specular[3] = m_glSpecular[3];
}


/**********************************************************/
/* Set the shininess of material 
/**********************************************************/
void CGLBaseObject::SetShininess(float Shininess)
{
    m_glShininess = Shininess; 
}


/**********************************************************/
/* Get the shininess of material 
/**********************************************************/
void CGLBaseObject::GetShininess(float* Shininess)
{
    *Shininess = m_glShininess; 
}


/**********************************************************/
/* Set the transformation of object 
/**********************************************************/
void CGLBaseObject::SetTranslation(double tx, double ty, double tz)
{
	m_dTX = tx;
	m_dTY = ty;
	m_dTZ = tz;
}


/**********************************************************/
/* Get the transformation of object 
/**********************************************************/
void CGLBaseObject::GetTranslation(double* tx, double* ty, double* tz)
{
	*tx = m_dTX;
	*ty = m_dTY;
	*tz = m_dTZ;
}


/**********************************************************/
/* Set the scale of object 
/**********************************************************/
void CGLBaseObject::SetScale(double sx, double sy, double sz)
{
	m_dSX = sx;
	m_dSY = sy;
	m_dSZ = sz;
}


/**********************************************************/
/* Get the scale of object 
/**********************************************************/
void CGLBaseObject::GetScale(double* sx, double* sy, double* sz)
{
	*sx = m_dSX;
	*sy = m_dSY;
	*sz = m_dSZ;
}


/**********************************************************/
/* Set the rotation of object 
/**********************************************************/
void CGLBaseObject::SetRotate(double rx, double ry, double rz)
{
	m_dRX = rx;
	m_dRY = ry;
	m_dRZ = rz;
}


/**********************************************************/
/* Get the rotation of object 
/**********************************************************/
void CGLBaseObject::GetRotate(double* rx, double* ry, double* rz)
{
	*rx = m_dRX;
	*ry = m_dRY;
	*rz = m_dRZ;
}




