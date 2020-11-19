// dllmain.cpp : 定义 DLL 应用程序的入口点。

//说明：x64平台只能注入64位进程，x86平台只能注入32位进程

#define WIN32_LEAN_AND_MEAN             // 从 Windows 头文件中排除极少使用的内容
// Windows 头文件
#include <windows.h>

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        OutputDebugString(L"mydll attach\n");
        MessageBox(NULL, L"dll attach", L"title", MB_OK | MB_ICONINFORMATION);
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
        break;
    case DLL_PROCESS_DETACH:
        OutputDebugString(L"mydll detach\n");
		MessageBox(NULL, L"dll detach", L"title", MB_OK | MB_ICONINFORMATION);
        break;
    }
    return TRUE;
}

