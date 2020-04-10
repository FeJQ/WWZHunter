#include "Common.h"
#include <string.h>
#include <tlhelp32.h>
#include "psapi.h"

/// <summary>
/// ��ȡ�ļ���
/// </summary>
/// <param name="fileFullName">�ļ�ȫ��</param>
/// <param name="fileName">�ļ�ȫ��������</param>
/// <returns>�ļ���</returns>
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
/// ��ȡģ���ַ
/// </summary>
/// <param name="dwProcessId">����ID</param>
/// <param name="moduleName">ģ����</param>
/// <returns>ģ���ַ</returns>
/// <created>FeJQ,2020/4/9</created>
/// <changed>FeJQ,2020/4/9</changed>
HMODULE GeModuleBase(DWORD dwProcessId, char* moduleName)
{
	PVOID pProcessImageBase = NULL;
	MODULEENTRY32 me32 = { 0 };
	me32.dwSize = sizeof(MODULEENTRY32);
	// ��ȡָ������ȫ��ģ��Ŀ���
	HANDLE hModuleSnap = ::CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, dwProcessId);
	if (INVALID_HANDLE_VALUE == hModuleSnap)
	{
		return (HMODULE)pProcessImageBase;
	}
	// ��ȡ�����е�һ����Ϣ
	BOOL bRet = ::Module32First(hModuleSnap, &me32);
	while (strcmp((char*)me32.szModule, moduleName) != 0)
	{
		Module32Next(hModuleSnap, &me32);
	}
	pProcessImageBase = (PVOID)me32.modBaseAddr;
	// �رվ��
	::CloseHandle(hModuleSnap);
	return (HMODULE)pProcessImageBase;
}