/**********************************************************/
/*   The glObj.h                                          
/*                                                         
/*   Created by Xing Zhaohui (xingzhh@yahoo.com),          
/*   Oct 4, 1999                                           
/*                                                        
/*   Declare a basic OpenGL object class from which different
/*   kinds of objects can be derived        
/*        
/**********************************************************/

#ifndef __GLOBJ_H__
#define __GLOBJ_H__

#include "xvector.h"
#include "gldef.h"


/*********************************************************/
/*                                                       */
/*                                                       */
/*                                                       */
/*           The basic 3D OpenGL object clasee           */
/*                                                       */
/*                                                       */
/*                                                       */
/*********************************************************/
class CGLBaseObject 
{
public:
	CGLBaseObject();
	virtual ~CGLBaseObject();

public:
	void Render(void);
	void SetObjectType(BYTE ObjType){m_ObjType = ObjType;};
	BYTE GetObjectType(void){return m_ObjType;};
	void SetAmbient(float* Ambient);
	void GetAmbient(float* Ambient);
	void SetEmission(float* Emission);
	void GetEmission(float* Emission);
	void SetDiffuse(float* Diffuse);
	void GetDiffuse(float* Diffuse);
	void SetSpecular(float* Specular);
	void GetSpecular(float* Specular);
	void SetShininess(float Shininess);
	void GetShininess(float* Shininess);
    void SetTranslation(double tx, double ty, double tz);
    void GetTranslation(double* tx, double* ty, double* tz);
	void SetScale(double sx, double sy, double sz);
	void GetScale(double* sx, double* sy, double* sz);
	void SetRotate(double rx, double ry, double rz);
	void GetRotate(double* rx, double* ry, double* rz);

private:
	BYTE         m_ObjType;       //object type

	//Material property
	float        m_glAmbient[4];
	float        m_glEmission[4];
	float        m_glDiffuse[4];
	float        m_glSpecular[4];
    float        m_glShininess; 
	
	double       m_dTX, m_dTY, m_dTZ;  //Transform
	double       m_dSX, m_dSY, m_dSZ;  //Scale
	double       m_dRX, m_dRY, m_dRZ;  //Rotate
    
protected:
	void InitProperty(void);
	void SetProperty(void);
	void Transform(void);
	void Restore(void);
	virtual void DrawObject(void) = 0;
};



#endif