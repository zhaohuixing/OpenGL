// RegKey.cpp: implementation of the CRegisterKey class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "RegKey.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CRegisterKey::CRegisterKey()
{
	m_hKey = NULL;
}

CRegisterKey::~CRegisterKey()
{
    Close();
}


LONG CRegisterKey::Open(HKEY hRootKey, LPSTR pszPath)
{
	DWORD dwTemp;

	return RegCreateKeyEx (hRootKey, pszPath, 0L, NULL,
		REG_OPTION_VOLATILE, KEY_ALL_ACCESS, NULL, 
		&m_hKey, &dwTemp);
}


void CRegisterKey::Close()
{	
	if (m_hKey)
	{
		RegCloseKey(m_hKey);
		m_hKey = NULL;
	}
}


LONG CRegisterKey::Write(LPSTR pName, SAVERSETTING iData)
{
	if(m_hKey == NULL)
		return 0L;
	if(pName == NULL)
		return 0L;

	return RegSetValueEx(m_hKey, pName, 0L, REG_NONE,
		(CONST BYTE*)&iData, sizeof(SAVERSETTING));
}


LONG CRegisterKey::Read(LPSTR pName, SAVERSETTING* iData)
{
	if(m_hKey == NULL)
		return 0L;
	if(pName == NULL)
		return 0L;

	DWORD dwType;
	DWORD dwSize = sizeof(SAVERSETTING);

	LONG Result = RegQueryValueEx(m_hKey, pName, NULL, 
		&dwType,  (BYTE *)iData, &dwSize);

	
	return Result;
}


