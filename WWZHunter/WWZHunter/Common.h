#pragma once
#include <Windows.h>

/// <summary>
/// ��ȡ�ļ���
/// </summary>
/// <param name="fileFullName">�ļ�ȫ��</param>
/// <param name="fileName">�ļ�ȫ��������</param>
/// <returns>�ļ���</returns>
/// <created>FeJQ,2020/4/9</created>
/// <changed>FeJQ,2020/4/9</changed>
char*GetFileName(const char* fileFullName,char* fileName);

/// <summary>
/// ��ȡģ���ַ
/// </summary>
/// <param name="dwProcessId">����ID</param>
/// <param name="moduleName">ģ����</param>
/// <returns>ģ���ַ</returns>
/// <created>FeJQ,2020/4/9</created>
/// <changed>FeJQ,2020/4/9</changed>
HMODULE GeModuleBase(DWORD dwProcessId, char* moduleName);