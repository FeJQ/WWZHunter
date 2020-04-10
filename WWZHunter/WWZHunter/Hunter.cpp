#include "Hunter.h"
#include "Common.h"
#include <QList>
#include <Psapi.h>

#define TranslationGrowth 2
HANDLE g_hProcess = NULL;

Hunter::Hunter()
{
	g_hProcess = NULL;
	pos1 = new Pos3D;
	pos1->characterX = 0;
	pos1->characterY = 0;
	pos1->characterZ = 0;

	pos2 = new Pos3D;
	pos2->characterX = 0;
	pos2->characterY = 0;
	pos2->characterZ = 0;
}

Hunter::~Hunter()
{
}




/// <summary>
/// ���ظ���
/// </summary>
/// <param name="char*processName">Ŀ�������</param>
/// <returns>�Ƿ�ɹ�</returns>
/// <created>FeJQ,2020/4/8</created>
/// <changed>FeJQ,2020/4/8</changed>
bool Hunter::Load(const char* processName)
{
	//��ʼ��Ԥ�ȷ���ϴ�Ļ�������������Ž���ID
	DWORD dwProcessID[0x100] = { 0 };
	DWORD dwNeeded = 0;
	BOOL bEnumRes = EnumProcesses(dwProcessID, sizeof(dwProcessID), &dwNeeded);
	//ö�ٵ����̵�����
	UINT uCount = dwNeeded / sizeof(DWORD);
	//QList<QString> list;
	for (int i = 0; i < uCount; i++)
	{
		HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwProcessID[i]);
		if (NULL != hProcess)
		{
			CHAR szProcessName[MAX_PATH] = { 0 };
			DWORD dwNameLen = MAX_PATH;
			BOOL bRet = QueryFullProcessImageNameA(hProcess, 0, szProcessName, &dwNameLen);
			if (!bRet)
				continue;
			//list.append(szProcessName);
			char szName[MAX_PATH] = { 0 };
			char* fileName = GetFileName(szProcessName, szName);
			if (strcmp(processName, fileName) == 0)
			{
				g_hProcess = hProcess;
				return true;
			}
		}
	}
	return false;
}

bool Hunter::SetUnlimitedHealth(bool isEnable)
{
	return false;
}


/// <summary>
/// ��ȡ�ڴ�
/// </summary
/// <param name="lpBase">��ʼ��ַ</param>
/// <param name="lpBuff">���ݻ�����</param>
/// <param name="size">��С</param>
/// <returns>�Ƿ�ɹ�</returns>
/// <created>FeJQ,2020/4/9</created>
/// <changed>FeJQ,2020/4/9</changed>
bool Hunter::ReadMemory(HANDLE hProcess, LPVOID lpBase, LPVOID lpBuff, int size)
{
	MEMORY_BASIC_INFORMATION mbi;
	//��ѯ�ڴ��Ƿ�ɷ���
	bool bRet = VirtualQueryEx(hProcess, lpBase, &mbi, sizeof(MEMORY_BASIC_INFORMATION));
	if (!bRet)
	{
		return false;
		DWORD dwOldProtect;
		//�����ڴ�ҳ����Ϊ�ɶ���д��ִ��
		bRet = VirtualProtectEx(hProcess, lpBase, sizeof(ULONG_PTR), PAGE_EXECUTE_READWRITE, &dwOldProtect);
		if (!bRet)
		{
			return false;
		}
	}
	bRet = ReadProcessMemory(hProcess, lpBase, lpBuff, size, NULL);
	//VirtualProtectEx(m_hProcess,lpBase, sizeof(ULONG_PTR), dwOldProtect, &dwOldProtect);
	return bRet;
}

/// <summary>
/// д�ڴ�
/// </summary>
/// <param name="lpBase">��ʼ��ַ</param>
/// <param name="lpBuff">Ҫд�������</param>
/// <param name="size">��С</param>
/// <returns>�Ƿ�ɹ�</returns>
/// <created>FeJQ,2020/4/9</created>
/// <changed>FeJQ,2020/4/9</changed>
bool Hunter::WriteMemory(HANDLE hProcess, LPVOID lpBase, LPVOID lpBuff, int size)
{
	MEMORY_BASIC_INFORMATION mbi;
	//��ѯ�ڴ��Ƿ�ɷ���
	bool bRet = VirtualQueryEx(hProcess, lpBase, &mbi, sizeof(MEMORY_BASIC_INFORMATION));
	if (!bRet)
	{
		return false;
	}
	bRet = WriteProcessMemory(hProcess, lpBase, lpBuff, size, NULL);
	return bRet;
}
/// <summary>
/// ����׼���̻߳ص�
/// </summary>
/// <param name="lpParam">��Ϸ���̾��</param>
/// <returns></returns>
/// <created>FeJQ,2020/4/9</created>
/// <changed>FeJQ,2020/4/9</changed>
DWORD WINAPI ThreadProcLockSight(LPVOID lpParam)
{
	while (true)
	{
		Sleep(5);
		//Ŀ��ģ���ַ
		HMODULE tagetModule = NULL;
		//��ȡ����ID
		int PID = GetProcessId(g_hProcess);
		//��ȡģ���ַ
		tagetModule = GeModuleBase(PID, "wwzRetailEgs.exe");
		if (tagetModule == NULL)
			continue;
		//ȡ���ݵ�ַ
		ULONG_PTR ulOffset = 0;
		if (!Hunter::ReadMemory(g_hProcess, (char*)tagetModule + 0x03368BE8, &ulOffset, sizeof(ULONG_PTR)))
			continue;
		if (!Hunter::ReadMemory(g_hProcess, (LPVOID)(ulOffset + 0x98), &ulOffset, sizeof(ULONG_PTR)))
			continue;
		if (!Hunter::ReadMemory(g_hProcess, (LPVOID)(ulOffset + 0x50), &ulOffset, sizeof(ULONG_PTR)))
			continue;
		if (!Hunter::ReadMemory(g_hProcess, (LPVOID)(ulOffset + 0xA8), &ulOffset, sizeof(ULONG_PTR)))
			continue;
		if (!Hunter::ReadMemory(g_hProcess, (LPVOID)(ulOffset + 0x50), &ulOffset, sizeof(ULONG_PTR)))
			continue;
		if (!Hunter::ReadMemory(g_hProcess, (LPVOID)(ulOffset + 0x1A8), &ulOffset, sizeof(ULONG_PTR)))
			continue;
		if (!Hunter::ReadMemory(g_hProcess, (LPVOID)(ulOffset + 0x268), &ulOffset, sizeof(ULONG_PTR)))
			continue;
		if (!Hunter::ReadMemory(g_hProcess, (LPVOID)(ulOffset + 0x48), &ulOffset, sizeof(ULONG_PTR)))
			continue;
		//�޸�ֵ
		DWORD value = 0;
		while (true)
		{
			Sleep(5);
			//׼��X��
			//if (!Hunter::WriteMemory(g_hProcess, (LPVOID)(ulOffset + 0x80), &value, sizeof(DWORD)))
			//	break;
			////׼��Y��
			//if (!Hunter::WriteMemory(g_hProcess, (LPVOID)(ulOffset + 0x84), &value, sizeof(DWORD)))
			//	break;
			//��Ϸ����Ҫ>����>��ͷ>��ͷ�ζ�>��
			if (!Hunter::WriteMemory(g_hProcess, (LPVOID)(ulOffset + 0xA4), &value, sizeof(DWORD)))
				break;
		}
	}
	return 1;
}



/// <summary>
/// �����ӵ��̻߳ص�
/// </summary>
/// <param name="lpParam">��Ϸ���̾��</param>
/// <returns></returns>
/// <created>FeJQ,2020/4/9</created>
/// <changed>FeJQ,2020/4/9</changed>
DWORD WINAPI ThreadProcUnlimitedAmmo(LPVOID lpParam)
{
	while (true)
	{
		Sleep(5);
		//Ŀ��ģ���ַ
		HMODULE tagetModule = NULL;
		//��ȡ����ID
		int PID = GetProcessId(g_hProcess);
		//��ȡģ���ַ
		tagetModule = GeModuleBase(PID, "wwzRetailEgs.exe");
		if (tagetModule == NULL)
			return 0;
		//ȡ���ݵ�ַ
		ULONG_PTR ulOffset = 0;

		if (!Hunter::ReadMemory(g_hProcess, (char*)tagetModule + 0x03368D00, &ulOffset, sizeof(ULONG_PTR)))
			continue;
		if (!Hunter::ReadMemory(g_hProcess, (LPVOID)(ulOffset + 0x8), &ulOffset, sizeof(ULONG_PTR)))
			continue;
		if (!Hunter::ReadMemory(g_hProcess, (LPVOID)(ulOffset + 0x80), &ulOffset, sizeof(ULONG_PTR)))
			continue;
		if (!Hunter::ReadMemory(g_hProcess, (LPVOID)(ulOffset + 0x0), &ulOffset, sizeof(ULONG_PTR)))
			continue;
		if (!Hunter::ReadMemory(g_hProcess, (LPVOID)(ulOffset + 0x120), &ulOffset, sizeof(ULONG_PTR)))
			continue;
		if (!Hunter::ReadMemory(g_hProcess, (LPVOID)(ulOffset + 0x218), &ulOffset, sizeof(ULONG_PTR)))
			continue;
		if (!Hunter::ReadMemory(g_hProcess, (LPVOID)(ulOffset + 0x3B8), &ulOffset, sizeof(ULONG_PTR)))
			continue;
		if (!Hunter::ReadMemory(g_hProcess, (LPVOID)(ulOffset + 0x4D8), &ulOffset, sizeof(ULONG_PTR)))
			continue;

		//�޸�ֵ
		DWORD value = 0;
		while (true)
		{
			Sleep(5);
			if (!Hunter::WriteMemory(g_hProcess, (LPVOID)(ulOffset + 0x180), &value, sizeof(DWORD)))
				break;
		}
	}
	return 1;
}


/// <summary>
/// 
/// </summary>
/// <param name="lpParam"></param>
/// <returns></returns>
/// <created>FeJQ,2020/4/9</created>
/// <changed>FeJQ,2020/4/9</changed>
DWORD WINAPI ThreadProcMainWeaponFireRate(LPVOID lpParam)
{

	return 0;
}

/// <summary>
/// ����׼��
/// </summary>
/// <param name="isEnable">�Ƿ�����</param>
/// <returns>�Ƿ�ɹ�</returns>
/// <created>FeJQ,2020/4/9</created>
/// <changed>FeJQ,2020/4/9</changed>
bool Hunter::SetLockSight(bool isEnable)
{
	if (!isEnable)
	{
		if (hThreadLockSight != NULL)
		{
			if (TerminateThread(hThreadLockSight, 1))
			{
				hThreadLockSight = NULL;
				return true;
			}
		}
		return false;
	}
	hThreadLockSight = CreateThread(NULL, 0, ThreadProcLockSight, NULL, 0, NULL);
	if (hThreadLockSight == NULL)
	{
		return false;
	}
	return true;
}

/// <summary>
/// ���������ӵ�
/// </summary>
/// <param name="isEnable">�Ƿ�����</param>
/// <returns>�Ƿ�ɹ�</returns>
/// <created>FeJQ,2020/4/8</created>
/// <changed>FeJQ,2020/4/8</changed>
bool Hunter::SetUnlimitedAmmo(bool isEnable)
{
	if (!isEnable)
	{
		if (hThreadUnlimitedAmmo != NULL)
		{
			if (TerminateThread(hThreadUnlimitedAmmo, 1))
			{
				hThreadUnlimitedAmmo = NULL;
				return true;
			}
		}
		return false;
	}
	hThreadUnlimitedAmmo = CreateThread(NULL, 0, ThreadProcUnlimitedAmmo, NULL, 0, NULL);
	if (hThreadUnlimitedAmmo == NULL)
	{
		return false;
	}
	return true;
}

/// <summary>
/// �������޽�ս
/// </summary>
/// <param name="isEnable">�Ƿ�����</param>
/// <returns>�Ƿ�ɹ�</returns>
/// <created>FeJQ,2020/4/10</created>
/// <changed>FeJQ,2020/4/10</changed>
bool Hunter::SetUnlimitedMelee(bool isEnable)
{

	return false;
}


/// <summary>
/// ����λ��
/// </summary>
/// <param name="translateDirection">�ƶ�����</param>
/// <returns>�Ƿ�ɹ�</returns>
/// <created>FeJQ,2020/4/10</created>
/// <changed>FeJQ,2020/4/10</changed>
bool Hunter::CharacterTranlate(HotKey translateDirection)
{
	//Ŀ��ģ���ַ
	HMODULE tagetModule = NULL;
	//��ȡ����ID
	int PID = GetProcessId(g_hProcess);
	//��ȡģ���ַ
	tagetModule = GeModuleBase(PID, "wwzRetailEgs.exe");
	if (tagetModule == NULL)
		return 0;
	//ȡ���ݵ�ַ
	ULONG_PTR ulOffset = 0;

	if (!Hunter::ReadMemory(g_hProcess, (char*)tagetModule + 0x031720B8, &ulOffset, sizeof(ULONG_PTR)))
		return 0;
	if (!Hunter::ReadMemory(g_hProcess, (LPVOID)(ulOffset + 0x30), &ulOffset, sizeof(ULONG_PTR)))
		return 0;
	if (!Hunter::ReadMemory(g_hProcess, (LPVOID)(ulOffset + 0x20), &ulOffset, sizeof(ULONG_PTR)))
		return 0;
	if (!Hunter::ReadMemory(g_hProcess, (LPVOID)(ulOffset + 0x10), &ulOffset, sizeof(ULONG_PTR)))
		return 0;
	if (!Hunter::ReadMemory(g_hProcess, (LPVOID)(ulOffset + 0x8), &ulOffset, sizeof(ULONG_PTR)))
		return 0;
	if (!Hunter::ReadMemory(g_hProcess, (LPVOID)(ulOffset + 0x8), &ulOffset, sizeof(ULONG_PTR)))
		return 0;
	if (!Hunter::ReadMemory(g_hProcess, (LPVOID)(ulOffset + 0xF0), &ulOffset, sizeof(ULONG_PTR)))
		return 0;
	if (!Hunter::ReadMemory(g_hProcess, (LPVOID)(ulOffset + 0x20), &ulOffset, sizeof(ULONG_PTR)))
		return 0;
	float value = 0;
	switch (translateDirection)
	{
	case TranslateFront:
	{
		bool bRet1 = Hunter::ReadMemory(g_hProcess, (LPVOID)(ulOffset + 0x1A8), &value, sizeof(float));
		value -= TranslationGrowth;
		bool bRet2 = Hunter::WriteMemory(g_hProcess, (LPVOID)(ulOffset + 0x1A8), &value, sizeof(float));
		bool bRet3 = Hunter::ReadMemory(g_hProcess, (LPVOID)(ulOffset + 0x1C8), &value, sizeof(float));
		value -= TranslationGrowth;
		bool bRet4 = Hunter::WriteMemory(g_hProcess, (LPVOID)(ulOffset + 0x1C8), &value, sizeof(float));
		return bRet1 & bRet2 & bRet3 & bRet4;
	}
	case TranslateBack:
	{
		bool bRet1 = Hunter::ReadMemory(g_hProcess, (LPVOID)(ulOffset + 0x1A8), &value, sizeof(float));
		value += TranslationGrowth;
		bool bRet2 = Hunter::WriteMemory(g_hProcess, (LPVOID)(ulOffset + 0x1A8), &value, sizeof(float));
		bool bRet3 = Hunter::ReadMemory(g_hProcess, (LPVOID)(ulOffset + 0x1C8), &value, sizeof(float));
		value += TranslationGrowth;
		bool bRet4 = Hunter::WriteMemory(g_hProcess, (LPVOID)(ulOffset + 0x1C8), &value, sizeof(float));
		return bRet1 & bRet2 & bRet3 & bRet4;
	}
	case TranslateLeft:
	{
		bool bRet1 = Hunter::ReadMemory(g_hProcess, (LPVOID)(ulOffset + 0x1A0), &value, sizeof(float));
		value -= TranslationGrowth;
		bool bRet2 = Hunter::WriteMemory(g_hProcess, (LPVOID)(ulOffset + 0x1A0), &value, sizeof(float));
		bool bRet3 = Hunter::ReadMemory(g_hProcess, (LPVOID)(ulOffset + 0x1C0), &value, sizeof(float));
		value -= TranslationGrowth;
		bool bRet4 = Hunter::WriteMemory(g_hProcess, (LPVOID)(ulOffset + 0x1C0), &value, sizeof(float));
		return bRet1 & bRet2 & bRet3 & bRet4;
	}
	case TranslateRight:
	{
		bool bRet1 = Hunter::ReadMemory(g_hProcess, (LPVOID)(ulOffset + 0x1A0), &value, sizeof(float));
		value += TranslationGrowth;
		bool bRet2 = Hunter::WriteMemory(g_hProcess, (LPVOID)(ulOffset + 0x1A0), &value, sizeof(float));
		bool bRet3 = Hunter::ReadMemory(g_hProcess, (LPVOID)(ulOffset + 0x1C0), &value, sizeof(float));
		value += TranslationGrowth;
		bool bRet4 = Hunter::WriteMemory(g_hProcess, (LPVOID)(ulOffset + 0x1C0), &value, sizeof(float));
		return bRet1 & bRet2 & bRet3 & bRet4;
	}
	case TranslateUp:
	{
		bool bRet1 = Hunter::ReadMemory(g_hProcess, (LPVOID)(ulOffset + 0x1A4), &value, sizeof(float));
		value += TranslationGrowth;
		bool bRet2 = Hunter::WriteMemory(g_hProcess, (LPVOID)(ulOffset + 0x1A4), &value, sizeof(float));
		bool bRet3 = Hunter::ReadMemory(g_hProcess, (LPVOID)(ulOffset + 0x1C4), &value, sizeof(float));
		value += TranslationGrowth;
		bool bRet4 = Hunter::WriteMemory(g_hProcess, (LPVOID)(ulOffset + 0x1C4), &value, sizeof(float));
		return bRet1 & bRet2 & bRet3 & bRet4;
	}
	case TranslateDown:
	{
		bool bRet1 = Hunter::ReadMemory(g_hProcess, (LPVOID)(ulOffset + 0x1A4), &value, sizeof(float));
		value -= TranslationGrowth;
		bool bRet2 = Hunter::WriteMemory(g_hProcess, (LPVOID)(ulOffset + 0x1A4), &value, sizeof(float));
		bool bRet3 = Hunter::ReadMemory(g_hProcess, (LPVOID)(ulOffset + 0x1C4), &value, sizeof(float));
		value -= TranslationGrowth;
		bool bRet4 = Hunter::WriteMemory(g_hProcess, (LPVOID)(ulOffset + 0x1C4), &value, sizeof(float));
		return bRet1 & bRet2 & bRet3 & bRet4;
	}
	case CharacterPosRecord:
	{
		bool bRet1 = Hunter::ReadMemory(g_hProcess, (LPVOID)(ulOffset + 0x1A8), &pos1->characterX, sizeof(float));
		bool bRet2 = Hunter::ReadMemory(g_hProcess, (LPVOID)(ulOffset + 0x1A0), &pos1->characterY, sizeof(float));
		bool bRet3 = Hunter::ReadMemory(g_hProcess, (LPVOID)(ulOffset + 0x1A4), &pos1->characterZ, sizeof(float));
		bool bRet4 = Hunter::ReadMemory(g_hProcess, (LPVOID)(ulOffset + 0x1C8), &pos2->characterX, sizeof(float));
		bool bRet5 = Hunter::ReadMemory(g_hProcess, (LPVOID)(ulOffset + 0x1C0), &pos2->characterY, sizeof(float));
		bool bRet6 = Hunter::ReadMemory(g_hProcess, (LPVOID)(ulOffset + 0x1C4), &pos2->characterZ, sizeof(float));
		return bRet1 & bRet2 & bRet3 & bRet4 & bRet5 & bRet6;
	}
	case CharacterPosSet:
	{
		if (pos1->characterX == 0 && pos1->characterY == 0 && pos1->characterZ == 0) return false;
		bool bRet1 = Hunter::WriteMemory(g_hProcess, (LPVOID)(ulOffset + 0x1A8), &pos1->characterX, sizeof(float));
		bool bRet2 = Hunter::WriteMemory(g_hProcess, (LPVOID)(ulOffset + 0x1A0), &pos1->characterY, sizeof(float));
		bool bRet3 = Hunter::WriteMemory(g_hProcess, (LPVOID)(ulOffset + 0x1A4), &pos1->characterZ, sizeof(float));
		bool bRet4 = Hunter::WriteMemory(g_hProcess, (LPVOID)(ulOffset + 0x1C8), &pos2->characterX, sizeof(float));
		bool bRet5 = Hunter::WriteMemory(g_hProcess, (LPVOID)(ulOffset + 0x1C0), &pos2->characterY, sizeof(float));
		bool bRet6 = Hunter::WriteMemory(g_hProcess, (LPVOID)(ulOffset + 0x1C4), &pos2->characterZ, sizeof(float));
		return bRet1 & bRet2 & bRet3 & bRet4 & bRet5 & bRet6;
	}
	default:
		break;
	}

	return false;
}

/// <summary>
/// ��ȡ��������������
/// </summary>
/// <param name="weapon">��������</param>
/// <param name="operateValue">������</param>
/// <returns>��������</returns>
/// <created>FeJQ,2020/4/9</created>
/// <changed>FeJQ,2020/4/9</changed>
int Hunter::WeaponFireRate(WeaponType weapon, int operateValue)
{
	//Ŀ��ģ���ַ
	HMODULE tagetModule = NULL;
	//��ȡ����ID
	int PID = GetProcessId(g_hProcess);
	//��ȡģ���ַ
	tagetModule = GeModuleBase(PID, "wwzRetailEgs.exe");
	if (tagetModule == NULL)
		return 0;
	//ȡ���ݵ�ַ
	ULONG_PTR ulOffset = 0;

	if (!Hunter::ReadMemory(g_hProcess, (char*)tagetModule + 0x030C7E98, &ulOffset, sizeof(ULONG_PTR)))
		return 0;
	if (!Hunter::ReadMemory(g_hProcess, (LPVOID)(ulOffset + 0x50), &ulOffset, sizeof(ULONG_PTR)))
		return 0;
	if (!Hunter::ReadMemory(g_hProcess, (LPVOID)(ulOffset + 0x48), &ulOffset, sizeof(ULONG_PTR)))
		return 0;
	if (!Hunter::ReadMemory(g_hProcess, (LPVOID)(ulOffset + 0x18), &ulOffset, sizeof(ULONG_PTR)))
		return 0;
	if (!Hunter::ReadMemory(g_hProcess, (LPVOID)(ulOffset + 0x218), &ulOffset, sizeof(ULONG_PTR)))
		return 0;
	if (!Hunter::ReadMemory(g_hProcess, (LPVOID)(ulOffset + 0x4D8), &ulOffset, sizeof(ULONG_PTR)))
		return 0;
	if (!Hunter::ReadMemory(g_hProcess, (LPVOID)(ulOffset + 0x50), &ulOffset, sizeof(ULONG_PTR)))
		return 0;
	//�����������
	switch (weapon)
	{
	case MainWeapon:
		if (!Hunter::ReadMemory(g_hProcess, (LPVOID)(ulOffset + 0x8), &ulOffset, sizeof(ULONG_PTR)))
		{
			return 0;
		}
		break;
	case SecondaryWeapon:
		if (!Hunter::ReadMemory(g_hProcess, (LPVOID)(ulOffset + 0x28), &ulOffset, sizeof(ULONG_PTR)))
		{
			return 0;
		}
		break;
	case HeavyWeapon:
		break;
	default:
		break;
	}
	//��ȡ��������
	float value = 0;
	if (!ReadMemory(g_hProcess, (LPVOID)(ulOffset + 0x5F8), &value, sizeof(float)))
		return 0;
	if (operateValue != 0)
	{
		//��������
		float newRate = value + operateValue;
		if (!WriteMemory(g_hProcess, (LPVOID)(ulOffset + 0x5F8), &newRate, sizeof(float)))
			return 0;
		value = newRate;
	}
	if (value == 0)
	{
		value = 1;
	}
	return value;
}






