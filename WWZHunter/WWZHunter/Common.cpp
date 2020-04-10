#include "Common.h"
#include <string.h>
#include <tlhelp32.h>
#include "psapi.h"

/// <summary>
/// 获取文件名
/// </summary>
/// <param name="fileFullName">文件全名</param>
/// <param name="fileName">文件全名缓冲区</param>
/// <returns>文件名</returns>
/// <created>FeJQ,2020/4/9</created>
/// <changed>FeJQ,2020/4/9</changed>
char* GetFileName(const char* fileFullName,char* fileName)
{
	int fileFullNameLength = strlen(fileFullName);
	int index = 0;
	strcpy_s(fileName, strlen(fileFullName) + 1, fileFullName);
	for (int i = 0; i < fileFullNameLength - 1; i++)
	{
		if (fileName[i] == '\\')
		{
			index = i;
		}
	}
	fileName = fileName + index + 1;
	return fileName;
}

/// <summary>
/// 获取模块基址
/// </summary>
/// <param name="dwProcessId">进程ID</param>
/// <param name="moduleName">模块名</param>
/// <returns>模块基址</returns>
/// <created>FeJQ,2020/4/9</created>
/// <changed>FeJQ,2020/4/9</changed>
HMODULE GeModuleBase(DWORD dwProcessId, char* moduleName)
{
	PVOID pProcessImageBase = NULL;
	MODULEENTRY32 me32 = { 0 };
	me32.dwSize = sizeof(MODULEENTRY32);
	// 获取指定进程全部模块的快照
	HANDLE hModuleSnap = ::CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, dwProcessId);
	if (INVALID_HANDLE_VALUE == hModuleSnap)
	{
		return (HMODULE)pProcessImageBase;
	}
	// 获取快照中第一条信息
	BOOL bRet = ::Module32First(hModuleSnap, &me32);
	while (strcmp((char*)me32.szModule, moduleName) != 0)
	{
		Module32Next(hModuleSnap, &me32);
	}
	pProcessImageBase = (PVOID)me32.modBaseAddr;
	// 关闭句柄
	::CloseHandle(hModuleSnap);
	return (HMODULE)pProcessImageBase;
}