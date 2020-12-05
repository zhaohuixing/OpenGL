// RegKey.h: interface for the CRegisterKey class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_REGKEY_H__BCD721EF_CDB8_11D2_8F19_00805FBDCBE4__INCLUDED_)
#define AFX_REGKEY_H__BCD721EF_CDB8_11D2_8F19_00805FBDCBE4__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CRegisterKey  
{
public:
	CRegisterKey();
	virtual ~CRegisterKey();

	LONG Open(HKEY hRootKey, LPSTR pszPath);
	void Close();
	
	
	LONG Write(LPSTR pName, BOOL iData);

	LONG Read(LPSTR pName,  BOOL* iData);

private:
	HKEY 	m_hKey;
};

#endif // !defined(AFX_REGKEY_H__BCD721EF_CDB8_11D2_8F19_00805FBDCBE4__INCLUDED_)
