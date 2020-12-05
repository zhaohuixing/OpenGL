/**********************************************************/
/*   The xvector.cpp                                         
/*                                                         
/*   Created by Xing Zhaohui (xingzhh@yahoo.com),          
/*   ?? ??, 1998                                           
/*                                                        
/*   Declare the vector class for calculation of 3D data.        
/*   Declare the texture class for RGB type texture map
/* 
/**********************************************************/

#include "stdafx.h"

#include <math.h>

#include "xvector.h"


/*********************************************************/
/*                                                       */
/*                                                       */
/*                                                       */
/*             double type vector class                  */
/*                                                       */
/*                                                       */
/*                                                       */
/*********************************************************/

/**********************************************************/
/*   Construction                                         
/**********************************************************/
dVector::dVector()
{
    x = 1.0;
    y = 0.0;
    z = 0.0;
}


/**********************************************************/
/*   Construction                                         
/**********************************************************/
dVector::dVector(double v1, double v2, double v3)
{
	x = v1;
	y = v2;
	z = v3;
}


/**********************************************************/
/*   Construction                                         
/**********************************************************/
dVector::dVector(double* v)
{
    x = v[0];
	y = v[1];
	z = v[2];
}


/**********************************************************/
/*   Construction                                         
/**********************************************************/
dVector::dVector(dVector* dV)
{
	x = dV->GetX();
	y = dV->GetY();
    z = dV->GetZ();
}


/**********************************************************/
/*   Get x value                                         
/**********************************************************/
double dVector::GetX()
{
	double temp = x;
    return temp;
}


/**********************************************************/
/*   Get y value                                         
/**********************************************************/
double dVector::GetY()
{
	double temp = y;

    return temp;
}


/**********************************************************/
/*   Get z value                                         
/**********************************************************/
double dVector::GetZ()
{
	double temp = z;

    return temp;
}


/**********************************************************/
/*   Get x, y, z value                                         
/**********************************************************/
double* dVector::GetValue()
{
	double* temp = new double[3];

	temp[0] = x;
	temp[1] = y;
	temp[2] = z;

    return temp;
}


/**********************************************************/
/*   Set x value                                         
/**********************************************************/
void dVector::SetX(double vx) 
{
	x = vx;
}


/**********************************************************/
/*   Set y value                                         
/**********************************************************/
void dVector::SetY(double vy)
{
	y = vy;
}


/**********************************************************/
/*   Set z value                                         
/**********************************************************/
void dVector::SetZ(double vz)
{
	z = vz;
}


/**********************************************************/
/*   Set x, y, z value                                         
/**********************************************************/
void dVector::SetValue(double* v)
{
	x = v[0];
	y = v[1];
	z = v[2];
}


/**********************************************************/
/*   Get vector value                                         
/**********************************************************/
dVector& dVector::GetVector()
{
	return *this;
}


/**********************************************************/
/*   Get vector value                                         
/**********************************************************/
double* dVector::GetXYZ() const
{
	static double temp[3];

	temp[0] = x;
	temp[1] = y;
	temp[2] = z;

	return temp;
}


/**********************************************************/
/*   Set vector value                                         
/**********************************************************/
void dVector::SetVector(dVector v)
{
    x = v.GetX();
    y = v.GetY();
    z = v.GetZ();
}


/**********************************************************/
/*   Set vector value                                         
/**********************************************************/
void dVector::SetValue(double v1, double v2, double v3)
{
    x = v1;
    y = v2;
    z = v3;
}


/**********************************************************/
/*   Get lenght of the vector                                         
/**********************************************************/
double dVector::Length() const
{
    double temp;

	temp = sqrt(x*x + y*y + z*z);

	return temp;
}


/**********************************************************/
/*   Normalize the vector                                         
/**********************************************************/
bool dVector::Normalize()
{
    double temp;

	temp = Length();

	if(temp != 0.0)
    {
       x = x/temp;
       y = y/temp;
       z = z/temp;
	   
	   return true;
    }
	else
    {
	   return false;
	}
}


/**********************************************************/
/*   Scale the vector                                         
/**********************************************************/
void dVector::Scale(dVector v)
{
    x *= v.GetX();
    y *= v.GetY();
    z *= v.GetZ();
}


/**********************************************************/
/*   Scale the vector                                         
/**********************************************************/
void dVector::Scale(double t)
{
    x *= t;
    y *= t;
    z *= t;
}


/**********************************************************/
/*   Overload the operator "="                                         
/**********************************************************/
dVector& dVector::operator = (dVector& v)	
{
    x = v.GetX();
    y = v.GetY();
    z = v.GetZ();

	return *this; 
}


/**********************************************************/
/*   Overload the operator "+="                                         
/**********************************************************/
dVector& dVector::operator += (dVector& v)
{
	x += v.GetX();
	y += v.GetY();
	z += v.GetZ();

	return *this;
}


/**********************************************************/
/*   Overload the operator "-="                                         
/**********************************************************/
dVector& dVector::operator -= (dVector& v)
{
	x -= v.GetX();
	y -= v.GetY();
	z -= v.GetZ();

	return *this;
}


/**********************************************************/
/*   Overload the operator "*="                                         
/**********************************************************/
dVector& dVector::operator *= (double t)
{
	x *= t;
	y *= t;
	z *= t;

	return *this;
}


/**********************************************************/
/*   Overload the operator "=="                                         
/**********************************************************/
bool dVector::operator == (const dVector& v) const
{
	double temp;

	temp = v.x;
	if(x != temp)
       return false;

	temp = v.y;
	if(y != temp)
       return false;

	temp = v.z;
	if(z != temp)
       return false;
    
	return true;
}


/**********************************************************/
/*   Overload the operator "!="                                         
/**********************************************************/
bool dVector::operator != (const dVector& v) const
{
	return (!(*this == v));
}


/**********************************************************/
/*   Overload the operator "<"                                         
/**********************************************************/
bool dVector::operator < (const dVector& v) const
{
	double d1 = Length();
	double d2 = v.Length();
	return (d1 < d2);
}


/**********************************************************/
/*   Overload the operator "<="                                         
/**********************************************************/
bool dVector::operator <= (const dVector& v) const
{
	return (this->Length() <= v.Length());
}


/**********************************************************/
/*   Overload the operator ">"                                         
/**********************************************************/
bool dVector::operator > (const dVector& v) const
{
	return (this->Length() > v.Length());
}


/**********************************************************/
/*   Overload the operator ">="                                         
/**********************************************************/
bool dVector::operator >= (const dVector& v) const
{
	return (this->Length() >= v.Length());
}


/**********************************************************/
/*   Dot of two vectors                                         
/**********************************************************/
double Dot(dVector v1, dVector v2)
{
    return(v1.GetX() * v2.GetX() +
           v1.GetY() * v2.GetY() +
		   v1.GetZ() * v2.GetZ());
}


/**********************************************************/
/*   Cross of two vectors                                         
/**********************************************************/
dVector Cross(dVector v1, dVector v2)
{
    dVector temp;

	temp.SetX(v1.GetY()*v2.GetZ() - v1.GetZ()*v2.GetY());
	temp.SetY(v1.GetZ()*v2.GetX() - v1.GetX()*v2.GetZ());
	temp.SetZ(v1.GetX()*v2.GetY() - v1.GetY()*v2.GetX());

	return temp;
}


/**********************************************************/
/*   Swap two vectors                                         
/**********************************************************/
void swap(dVector v1,  dVector v2)
{
    double temp;
    
	temp = v1.GetX();
	v1.SetX(v2.GetX());
	v2.SetX(temp);

	temp = v1.GetY();
	v1.SetY(v2.GetY());
	v2.SetY(temp);

	temp = v1.GetZ();
	v1.SetZ(v2.GetZ());
	v2.SetZ(temp);
}


/**********************************************************/
/*   Sum of two vectors                                         
/**********************************************************/
dVector operator + (dVector v1,  dVector v2)
{
    dVector temp;

	temp.SetX(v1.GetX() + v2.GetX());
	temp.SetY(v1.GetY() + v2.GetY());
	temp.SetZ(v1.GetZ() + v2.GetZ());

    return temp;
}


/**********************************************************/
/*   Difference of two vectors                                         
/**********************************************************/
dVector operator - (dVector v1,  dVector v2)
{
    dVector temp;

	temp.SetX(v1.GetX() - v2.GetX());
	temp.SetY(v1.GetY() - v2.GetY());
	temp.SetZ(v1.GetZ() - v2.GetZ());

    return temp;
}



/*********************************************************/
/*                                                       */
/*                                                       */
/*                                                       */
/*             texture class                             */
/*                                                       */
/*                                                       */
/*                                                       */
/*********************************************************/

/**********************************************************/
/*   Overload the operator "="                                         
/**********************************************************/
bTexture& bTexture::operator = (bTexture& t)
{
    m_red = t.m_red; 
    m_green = t.m_green; 
    m_blue = t.m_blue; 
    m_alpha = t.m_alpha; 

	return *this;
}


/**********************************************************/
/*   Overload the operator "=="                                         
/**********************************************************/
bool bTexture::operator == (const bTexture& t) const
{
    if(m_red != t.m_red)
		return false; 
    if(m_green != t.m_green)
		return false; 
    if(m_blue != t.m_blue)
		return false; 
    if(m_alpha != t.m_alpha)
		return false;
	
	return true;
}


/**********************************************************/
/*   Overload the operator "!="                                         
/**********************************************************/
bool bTexture::operator != (const bTexture& t) const
{
    if(m_red != t.m_red)
		return true; 
    if(m_green != t.m_green)
		return true; 
    if(m_blue != t.m_blue)
		return true; 
    if(m_alpha != t.m_alpha)
		return true;
	
	return false;
}


/**********************************************************/
/*   Overload the operator "<"                                         
/**********************************************************/
bool bTexture::operator < (const bTexture& t) const
{
	long clrIndex = GetColorIndex();
	long TclrIndex = t.GetColorIndex();

	if(clrIndex < TclrIndex)
		return true;
	else
		return false;
}


/**********************************************************/
/*   Overload the operator "<="                                         
/**********************************************************/
bool bTexture::operator <= (const bTexture& t) const
{
	long clrIndex = GetColorIndex();
	long TclrIndex = t.GetColorIndex();

	if(clrIndex <= TclrIndex)
		return true;
	else
		return false;
}


/**********************************************************/
/*   Overload the operator ">"                                         
/**********************************************************/
bool bTexture::operator > (const bTexture& t) const
{
	long clrIndex = GetColorIndex();
	long TclrIndex = t.GetColorIndex();

	if(clrIndex > TclrIndex)
		return true;
	else
		return false;
}


/**********************************************************/
/*   Overload the operator ">="                                         
/**********************************************************/
bool bTexture::operator >= (const bTexture& t) const
{
	long clrIndex = GetColorIndex();
	long TclrIndex = t.GetColorIndex();

	if(clrIndex >= TclrIndex)
		return true;
	else
		return false;
}

