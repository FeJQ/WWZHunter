#pragma once
#include <Windows.h>

/// <summary>
/// 获取文件名
/// </summary>
/// <param name="fileFullName">文件全名</param>
/// <param name="fileName">文件全名缓冲区</param>
/// <returns>文件名</returns>
/// <created>FeJQ,2020/4/9</created>
/// <changed>FeJQ,2020/4/9</changed>
char*GetFileName(const char* fileFullName,char* fileName);

/// <summary>
/// 获取模块基址
/// </summary>
/// <param name="dwProcessId">进程ID</param>
/// <param name="moduleName">模块名</param>
/// <returns>模块基址</returns>
/// <created>FeJQ,2020/4/9</created>
/// <changed>FeJQ,2020/4/9</changed>
HMODULE GeModuleBase(DWORD dwProcessId, char* moduleName);