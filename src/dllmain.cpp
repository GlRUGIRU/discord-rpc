#include <windows.h>

// outsmart GCC's missing-declarations warning
BOOL WINAPI DllMain(HMODULE, DWORD, LPVOID);
DWORD WINAPI jumpOff(LPVOID);

BOOL WINAPI DllMain(HMODULE hmodule, DWORD rs, LPVOID)
{
	switch(rs) {
		case DLL_PROCESS_ATTACH:
			CloseHandle(CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)jumpOff, NULL, NULL, NULL));
			break;
		case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
		case DLL_PROCESS_DETACH:
			break;
	}
	
    return TRUE;
}

DWORD WINAPI jumpOff(LPVOID) {
	HMODULE myDll = LoadLibraryW(L"..\\..\\..\\MordhauDerpyMod.dll");
	return 0;
}