#ifndef __SAVERDEF_H__
#define __SAVERDEF_H__

enum enmCMDline 
{
	 CMD_SETTING,
	 CMD_PREVIEW,
	 CMD_SAVER,
	 CMD_NONE
};


enum enmObject 
{
	 CSG_BALL,
	 CSG_WAVE,
	 CSG_BOTH 
};

enum enmBallSize
{
	 BALL_SMALL,
	 BALL_MEDIUM,
	 BALL_LARGE
};

enum enmWaveType
{
	 WAVE_RECTANGLE,
	 WAVE_ROUND
};


enum enmTexture
{
	 TEX_SINGLE,
	 TEX_CHECKER,
	 TEX_NOISE
};


typedef struct saversetting
{
    enmObject     m_enmType;
	enmBallSize   m_enmBallSize;
	enmWaveType   m_enmWaveType;
    BOOL          m_bBallLine;
    BOOL          m_bWaveLine;
	BOOL          m_bFog;
    int           m_iFDensity;
    int           m_iFColorRed;
    int           m_iFColorGreen;
    int           m_iFColorBlue;
    int           m_iFColorAlpha;
    enmTexture    m_enmTextureB;
    enmTexture    m_enmTextureW;
    BYTE          m_btTexMasterRed;    
    BYTE          m_btTexMasterGreen;    
    BYTE          m_btTexMasterBlue;
    BYTE          m_btTexSecondRed;    
    BYTE          m_btTexSecondGreen;    
    BYTE          m_btTexSecondBlue;
    BYTE          m_btTexAlpha;    
    int           m_iTexChkSizeX;
    int           m_iTexChkSizeY;
	int           m_iSpeed;    
    int           m_iGridNumber;
}SAVERSETTING;

#define WAVEUNITR  0.16f
#define WAVEUNITT  0.15f


#define MAX_GRID  4
#define MIN_GRID  1

#define MAX_FOG_DENSITY   256 
#define MIN_FOG_DENSITY   0 
#define MAX_FOG_COLOR     255 
#define MIN_FOG_COLOR     0 

#define MAX_TIME_INTERVAL  101 
#define MIN_TIME_INTERVAL  1 


#endif