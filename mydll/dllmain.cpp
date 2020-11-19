// dllmain.cpp : 定义 DLL 应用程序的入口点。

//说明：x64平台只能注入64位进程，x86平台只能注入32位进程
#include "pch.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        OutputDebugString(L"mydll attach\n");
        MessageBox(NULL, L"I am a dll", L"title", MB_OK | MB_ICONINFORMATION);
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
        break;
    case DLL_PROCESS_DETACH:
        OutputDebugString(L"mydll detach\n");
		MessageBox(NULL, L"I am a dll", L"title", MB_OK | MB_ICONINFORMATION);
        break;
    }
    return TRUE;
}

