/**********************************************************/
/*   The xvector.h                                          
/*                                                         
/*   Created by Xing Zhaohui (xingzhh@yahoo.com),          
/*   ?? ??, 1998                                        
/*                                                        
/*   Declare the vector class for calculation of 3D data.        
/*   Declare the texture class for RGB type texture map
/* 
/**********************************************************/

#ifndef __XVECTOR_H__
#define __XVECTOR_H__

/*********************************************************/
/*                                                       */
/*                                                       */
/*                                                       */
/*             double type vector class                  */
/*                                                       */
/*                                                       */
/*                                                       */
/*********************************************************/
class dVector
{
public:
    double x;     //x-direction vector
    double y;     //y-direction vector
    double z;     //z-direction vector

public:
    dVector();
    dVector(double v1, double v2, double v3);
    dVector(double* v);
    dVector(dVector* dV);

	double GetX();
	double GetY();
    double GetZ();
	double* GetValue();
	void SetX(double vx);
	void SetY(double vy);
    void SetZ(double vz);
	void SetValue(double* v);
	void SetValue(double v1, double v2, double v3);

	dVector& GetVector();
    double* GetXYZ()  const;
	void SetVector(dVector v);
	double Length() const;
	bool Normalize();
    void Scale(dVector v);
    void Scale(double t);

    dVector& operator = (dVector& v);
    dVector& operator += (dVector& v);
    dVector& operator -= (dVector& v);
    dVector& operator *= (double t);
    bool operator == (const dVector& v) const;
    bool operator != (const dVector& v) const;
    bool operator < (const dVector& v) const;
    bool operator <= (const dVector& v) const;
    bool operator > (const dVector& v) const;
    bool operator >= (const dVector& v) const;

	friend double Dot(dVector v1,  dVector v2);
	friend dVector Cross(dVector v1,  dVector v2);
	friend void swap(dVector v1,  dVector v2);
	friend dVector operator + (dVector v1,  dVector v2);
	friend dVector operator - (dVector v1,  dVector v2);
};


/*********************************************************/
/*                                                       */
/*                                                       */
/*                                                       */
/*             texture class                             */
/*                                                       */
/*                                                       */
/*                                                       */
/*********************************************************/
class bTexture
{
public:
    unsigned char m_red;     //Red color value, 0 - 0xFF
    unsigned char m_green;   //Green color value, 0 - 0xFF
    unsigned char m_blue;    //Blue color value, 0 - 0xFF
    unsigned char m_alpha;   //Alpha value, 0 - 0xFF

public:
    bTexture(): m_red(0), m_green(0), 
		        m_blue(0), m_alpha(0){}; 
    ~bTexture(){};

	//Set color value
	void SetColors(unsigned char red, unsigned char green, 
		           unsigned char blue, unsigned char alpha)
	{
        m_red = red; 
        m_green = green; 
        m_blue = blue; 
        m_alpha = alpha; 
	};
	
	//Get color value
	void GetColors(unsigned char *red, unsigned char *green, 
		           unsigned char *blue, unsigned char *alpha)
	{
        *red = m_red; 
        *green = m_green; 
        *blue = m_blue; 
        *alpha = m_alpha; 
	};
	
	//Get color entry index
	long GetColorIndex(void) const
	{
		return ((m_alpha << 24)|(m_red << 16)|(m_green << 8)|(m_blue));
	};

	//Overload the operator
    bTexture& operator = (bTexture& t);
    bool operator == (const bTexture& t) const;
    bool operator != (const bTexture& t) const;
    bool operator < (const bTexture& t) const;
    bool operator <= (const bTexture& t) const;
    bool operator > (const bTexture& t) const;
    bool operator >= (const bTexture& t) const;
};


#endif