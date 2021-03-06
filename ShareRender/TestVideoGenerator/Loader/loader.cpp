#include "../VideoUtility/log.h"
//#include "VideoUtility/log.h"
#include <Windows.h>
#include <queue>
#include "detours/detours.h"
#include <stdlib.h>

#pragma comment(lib, "detours//detours.lib")

void startGameProcessWithDll(char * gameName){
	PROCESS_INFORMATION pi = { 0 };
	STARTUPINFO si = { 0 };
	si.cb = sizeof(si);

	HANDLE hnd = GetCurrentProcess();

	LPSECURITY_ATTRIBUTES lp_attributes;
	LPSECURITY_ATTRIBUTES lpThreadAttributes;
	STARTUPINFO startupInfo = { sizeof(startupInfo) };
	memset(&startupInfo, 0, sizeof(STARTUPINFO));
	startupInfo.cb = sizeof(STARTUPINFO);
	startupInfo.dwFlags = 0;
	startupInfo.wShowWindow = SW_HIDE;

	PROCESS_INFORMATION processInformation;
	char cmdLine[100];

	DWORD id = GetCurrentProcessId();
	sprintf(cmdLine, "%s %d %d %d %d", gameName, 0, NULL, NULL, id);
	printf("cmd line is %s\n", cmdLine);
	bool ret = DetourCreateProcessWithDll(NULL, cmdLine, NULL, NULL, TRUE, CREATE_DEFAULT_ERROR_MODE,
		NULL, NULL, &si, &pi, "GameVideoGenerator.dll", NULL);

	if (!ret) {
		char err_str[200];
		sprintf(err_str, "Game Start %s Failed", gameName);
		MessageBox(NULL, err_str, "Error", MB_OK);
	}
}

int main(int argc, char** argv) {


	PROCESS_INFORMATION pi = {0};
	STARTUPINFO si = {0};
	si.cb = sizeof(si);

	HANDLE hnd = GetCurrentProcess();

	//printf("Listening\nhandle %d\n", hnd);

	LPSECURITY_ATTRIBUTES lp_attributes;
	LPSECURITY_ATTRIBUTES lpThreadAttributes;
	STARTUPINFO startupInfo = {sizeof(startupInfo)};
	memset(&startupInfo,0,sizeof(STARTUPINFO));
	startupInfo.cb = sizeof(STARTUPINFO);
	startupInfo.dwFlags=0;
	startupInfo.wShowWindow = SW_HIDE;

	PROCESS_INFORMATION processInformation;
	char cmdLine[100];
	string AppName;
	int recv_len = 0;
	char RecvB[100];
	
	DWORD id = GetCurrentProcessId();
		printf("[Loader]: game name is '%s'.\n", "trine.exe");

		bool ret = DetourCreateProcessWithDll(NULL,"trine.exe", NULL, NULL, TRUE, CREATE_DEFAULT_ERROR_MODE, NULL, NULL, &si, &pi, "GameVideoGenerator.dll", NULL);

		if(!ret) {
			char err_str[200];
			sprintf(err_str, "Game Start %s Failed", "trine");
			MessageBox(NULL, err_str, "Error", MB_OK);
		}

		return 0;

	if(argc == 1){
		DWORD id = GetCurrentProcessId();
		printf("[Loader]: game name is '%s'.\n", "trine.exe");

		bool ret = DetourCreateProcessWithDll(NULL,"trine.exe", NULL, NULL, TRUE, CREATE_DEFAULT_ERROR_MODE,
			NULL, NULL, &si, &pi, "GameVideoGenerator.dll", NULL);

		if(!ret) {
			char err_str[200];
			sprintf(err_str, "Game Start %s Failed", "trine");
			MessageBox(NULL, err_str, "Error", MB_OK);
		}

		return 0;
	}else if(argc == 2 || argc == 3) {
		//Æô¶¯ÓÎÏ·½ø³Ì
		DWORD id = GetCurrentProcessId();
		printf("[Loader]: game name is '%s'.\n", argv[1]);

		bool ret = DetourCreateProcessWithDll(NULL,argv[1], NULL, NULL, TRUE, CREATE_DEFAULT_ERROR_MODE,
			NULL, NULL, &si, &pi, "GameVideoGenerator.dll", NULL);

		if(!ret) {
			char err_str[200];
			sprintf(err_str, "Game Start %s Failed", AppName.c_str());
			MessageBox(NULL, err_str, "Error", MB_OK);
		}

		return 0;
	}
	return 1;
}