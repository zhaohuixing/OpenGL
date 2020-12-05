/**********************************************************/
/*   The CMCIPlayer.h                                    
/*                                                         
/*   Created by Xing Zhaohui (xingzhh@yahoo.com),          
/*   Feb ??, 1998                                       
/*                                                        
/*   Declare the MCI class to play Wave or MIDI file
/* 
/**********************************************************/

#ifndef __CMCIPLAYER__
#define __CMCIPLAYER__

#include "mmsystem.h"

/*********************************************************/
/*                                                       */
/*                                                       */
/*                                                       */
/*             MCI play class                            */
/*                                                       */
/*                                                       */
/*                                                       */
/*********************************************************/
class CMCIPlayer
{
public:
    CMCIPlayer();     
    ~CMCIPlayer();
    BOOL OpenFile(const char* pszFileName);
	BOOL LoadMIDIFile(UINT resID);
	void MoveMIDIFile(void);
    void SetDeviceType(const char* pszFileName);
    void Close(void);
    void Play(void);
    void Stop(void);
    void SetResName(char* FileName);
    DWORD GetPosition(void);
    DWORD GetLength(void);
// Implementation
private:
    void MCIError(DWORD dwErr);

    MCI_OPEN_PARMS m_OpenParams; 

	CString  m_sResName;

};


#endif
