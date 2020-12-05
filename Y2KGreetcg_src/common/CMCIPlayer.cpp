/**********************************************************/
/*   The CMCIPlayer.cpp                                    
/*                                                         
/*   Created by Xing Zhaohui (xingzhh@yahoo.com),          
/*   Feb ??, 1998                                       
/*                                                        
/*   Declare the MCI class to play Wave or MIDI file
/* 
/**********************************************************/
#include "stdafx.h"

#include "CMCIPlayer.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/*********************************************************/
/*                                                       */
/*                                                       */
/*                                                       */
/*             MCI play class                            */
/*                                                       */
/*                                                       */
/*                                                       */
/*********************************************************/

/**********************************************************/
/*   Construction                                         
/**********************************************************/
CMCIPlayer::CMCIPlayer()
{
    m_OpenParams.dwCallback = 0;
    m_OpenParams.wDeviceID = 0;
    m_OpenParams.lpstrDeviceType = NULL;
    m_OpenParams.lpstrElementName = NULL;
    m_OpenParams.lpstrAlias = NULL;
	m_sResName.Empty();
}


/**********************************************************/
/* Destruction
/**********************************************************/
CMCIPlayer::~CMCIPlayer()
{
    // Make sure the object is not in use.
    if (m_OpenParams.wDeviceID != 0) 
	{
        Close();
    }
    ASSERT(m_OpenParams.wDeviceID == 0);
}


/**********************************************************/
/* Process error information
/**********************************************************/
void CMCIPlayer::MCIError(DWORD dwErr)
{
    char buf[256];

    buf[0] = '\0';
    mciGetErrorString(dwErr, buf, sizeof(buf));
    if (!strlen(buf)) 
	{
        strcpy(buf, "Unknown error");
    }
    TRACE(buf);
}


/**********************************************************/
/* Open a media file
/**********************************************************/
BOOL CMCIPlayer::OpenFile(const char* pszFileName)
{
    DWORD dwResult;

    if(m_OpenParams.wDeviceID != 0) 
	{
        Close();
    }
    
	ASSERT(m_OpenParams.wDeviceID == 0);
    
	m_OpenParams.lpstrElementName = pszFileName;
    dwResult = mciSendCommand(0,
                              MCI_OPEN,
                              MCI_WAIT | 
							  MCI_OPEN_ELEMENT,
                              (DWORD)(LPVOID)&m_OpenParams);
    if (dwResult != 0) 
	{
        MCIError(dwResult);
        m_OpenParams.wDeviceID = 0;
        return FALSE;
    }

    // Set the time format to milliseconds.
    MCI_SET_PARMS set;
    set.dwTimeFormat = MCI_FORMAT_MILLISECONDS;
    dwResult = mciSendCommand(m_OpenParams.wDeviceID,
                              MCI_SET,
                              MCI_WAIT | 
							  MCI_SET_TIME_FORMAT,
                              (DWORD)(LPVOID)&set);
    if (dwResult != 0) 
	{
        MCIError(dwResult);
        m_OpenParams.wDeviceID = 0;
        return FALSE;
    }
    
	return TRUE;
}


/**********************************************************/
/* Load media data from resource
/**********************************************************/
BOOL CMCIPlayer::LoadMIDIFile(UINT resID)
{
	HRSRC             hSrc;
	HGLOBAL           hMem;
	void*             pData;
	CFile             file;

	//Create the MIDI file 
	if (!file.Open(m_sResName, CFile::modeCreate | CFile::modeWrite, NULL))
	{
		AfxMessageBox("Can't create temperary MIDI file");
	    return FALSE;
	}
	
	// find the resource
	hSrc = FindResource(AfxGetInstanceHandle(), MAKEINTRESOURCE(resID), "MIDI");
	if (hSrc == NULL)
	{
		AfxMessageBox("Can not find the reource");
		return FALSE;
	}

	// load the resource
	hMem = LoadResource(AfxGetInstanceHandle(), hSrc);
	if (hMem == NULL)
	{
		AfxMessageBox("Can not load the resource data");
		return FALSE;
	}

	// lock the resource
	pData = LockResource(hMem);
	if (pData == NULL)
	{
		AfxMessageBox("Can not lock the memory for resource data");
		return FALSE;		
	}

	// write the resource to the file
	file.Write(pData, SizeofResource(AfxGetInstanceHandle(), hSrc));
	file.Close();

    return OpenFile(m_sResName);
}


/**********************************************************/
/* Remove the temprary media file
/**********************************************************/
void CMCIPlayer::MoveMIDIFile(void)
{
	CFile::Remove(m_sResName);
}


/**********************************************************/
/* Set device type
/**********************************************************/
void CMCIPlayer::SetDeviceType(const char* pszFileName)
{
    m_OpenParams.lpstrDeviceType = pszFileName; 
}


/**********************************************************/
/* Close 
/**********************************************************/
void CMCIPlayer::Close(void)
{
    MCI_GENERIC_PARMS gp;
    DWORD dwResult;

    if (m_OpenParams.wDeviceID == 0) return; // Already closed.
    Stop(); // Just in case.
    dwResult = mciSendCommand(m_OpenParams.wDeviceID,
                              MCI_CLOSE,
                              MCI_WAIT,
                              (DWORD)(LPVOID)&gp);
    if (dwResult != 0) 
	{
        MCIError(dwResult);
    }
    m_OpenParams.wDeviceID = 0;
}


/**********************************************************/
/* Play
/**********************************************************/
void CMCIPlayer::Play(void)
{
    MCI_PLAY_PARMS play;
    DWORD dwResult;

    if (m_OpenParams.wDeviceID == 0)
	{	
        AfxMessageBox("Fault");
		return; // Not open
    } 
    mciSendCommand(m_OpenParams.wDeviceID,
                   MCI_SEEK,
                   MCI_WAIT | MCI_SEEK_TO_START,
                   0);
    dwResult = mciSendCommand(m_OpenParams.wDeviceID,
                              MCI_PLAY,
                              MCI_NOTIFY,
                              (DWORD)(LPVOID)&play);
    if (dwResult != 0) 
	{
        MCIError(dwResult);
	}
}


/**********************************************************/
/* Pause
/**********************************************************/
void CMCIPlayer::Stop(void)
{
    DWORD dwResult;

    if (m_OpenParams.wDeviceID == 0) 
		return; // Not open

    dwResult = mciSendCommand(m_OpenParams.wDeviceID,
                              MCI_STOP,
                              MCI_WAIT,
                              (DWORD)(LPVOID)NULL);
    if (dwResult != 0) 
	{
        MCIError(dwResult);
    }
}


/**********************************************************/
/* Set temperary media file name
/**********************************************************/
void CMCIPlayer::SetResName(char* FileName)
{
	m_sResName = FileName;
}


/**********************************************************/
/* Get current position of playing
/**********************************************************/
DWORD CMCIPlayer::GetPosition(void)
{
    if (m_OpenParams.wDeviceID == 0) 
		return 0; // Not open

    MCI_STATUS_PARMS status;
    status.dwItem = MCI_STATUS_POSITION;
    if (mciSendCommand(m_OpenParams.wDeviceID,
                       MCI_STATUS,
                       MCI_WAIT | MCI_STATUS_ITEM,
                       (DWORD)(LPVOID)&status) != 0) 
	{
        return 0; // Some error
    }
    return status.dwReturn;
}


/**********************************************************/
/* Get media data size
/**********************************************************/
DWORD CMCIPlayer::GetLength(void)
{
    if (m_OpenParams.wDeviceID == 0) 
		return 0; // Not open

    MCI_STATUS_PARMS status;
    status.dwItem = MCI_STATUS_LENGTH;
    if (mciSendCommand(m_OpenParams.wDeviceID,
                       MCI_STATUS,
                       MCI_WAIT | MCI_STATUS_ITEM,
                       (DWORD)(LPVOID)&status) != 0) 
	{
        return 0; // Some error
    }
    
	return status.dwReturn;
}
