#pragma once
#include <Windows.h>
enum HotKey
{
	/// <summary>��������</summary>
	UnlimitedHealth,

	/// <summary>�޺�����</summary>
	NoRecoil,

	/// <summary>�����ӵ�</summary>
	UnlimitedAmmo,

	/// <summary>���޽�ս</summary>
	UnlimitedMelee,

	/// <summary>����λ��</summary>
	CharacterTranslate,

	/// <summary>������������</summary>
	DecreaseWeaponFireRate,

	/// <summary>������������</summary>
	IncreaseWeaponFireRate,

	/// <summary>����λ��ǰ</summary>
	TranslateFront,

	/// <summary>����λ�ƺ�</summary>
	TranslateBack,

	/// <summary>����λ����</summary>
	TranslateLeft,

	/// <summary>����λ����</summary>
	TranslateRight,

	/// <summary>����λ����</summary>
	TranslateUp,

	/// <summary>����λ����</summary>
	TranslateDown,

	/// <summary>��¼��������</summary>
	CharacterPosRecord,

	/// <summary>˲��</summary>
	CharacterPosSet
};

enum WeaponType
{
	MainWeapon,
	SecondaryWeapon,
	HeavyWeapon
};

typedef struct
{
	float characterX;
	float characterY;
	float characterZ;
}Pos3D;

/// <summary>WWZ���̾��</summary>
extern HANDLE g_hProcess;


class Hunter
{
public:
	Hunter();
	~Hunter();

	/// <summary>�ٽ������</summary>
	CRITICAL_SECTION Critical;



	/// <summary>
	/// ��ȡ�ڴ�
	/// </summary>
	/// <param name="lpBase">��ʼ��ַ</param>
	/// <param name="lpBuff">���ݻ�����</param>
	/// <param name="size">��С</param>
	/// <returns>�Ƿ�ɹ�</returns>
	/// <created>FeJQ,2020/4/9</created>
	/// <changed>FeJQ,2020/4/9</changed>
	static bool ReadMemory(HANDLE hProcess, LPVOID lpBase, LPVOID lpBuff, int size);

	/// <summary>
	/// д�ڴ�
	/// </summary>
	/// <param name="lpBase">��ʼ��ַ</param>
	/// <param name="lpBuff">Ҫд�������</param>
	/// <param name="size">��С</param>
	/// <returns>�Ƿ�ɹ�</returns>
	/// <created>FeJQ,2020/4/9</created>
	/// <changed>FeJQ,2020/4/9</changed>
	static bool WriteMemory(HANDLE hProcess, LPVOID lpBase, LPVOID lpBuff, int size);

	/// <summary>
	/// ���ظ���
	/// </summary>
	/// <param name="processName">Ŀ�������</param>
	/// <returns>�Ƿ�ɹ�</returns>
	/// <created>FeJQ,2020/4/8</created>
	/// <changed>FeJQ,2020/4/8</changed>
	bool Load(const char* processName);

	/// <summary>
	/// ��������Ѫ��
	/// </summary>
	/// <param name="isEnable">�Ƿ�����</param>
	/// <returns>�Ƿ�ɹ�</returns>
	/// <created>FeJQ,2020/4/8</created>
	/// <changed>FeJQ,2020/4/8</changed>
	bool SetUnlimitedHealth(bool isEnable);

	/// <summary>
	/// ����׼��
	/// </summary>
	/// <param name="isEnable">�Ƿ�����</param>
	/// <returns>�Ƿ�ɹ�</returns>
	/// <created>FeJQ,2020/4/9</created>
	/// <changed>FeJQ,2020/4/9</changed>
	bool SetLockSight(bool isEnable);

	/// <summary>
	/// ���������ӵ�
	/// </summary>
	/// <param name="isEnable">�Ƿ�����</param>
	/// <returns>�Ƿ�ɹ�</returns>
	/// <created>FeJQ,2020/4/8</created>
	/// <changed>FeJQ,2020/4/8</changed>
	bool SetUnlimitedAmmo(bool isEnable);

	/// <summary>
	/// �������޽�ս
	/// </summary>
	/// <param name="isEnable">�Ƿ�����</param>
	/// <returns>�Ƿ�ɹ�</returns>
	/// <created>FeJQ,2020/4/10</created>
	/// <changed>FeJQ,2020/4/10</changed>
	bool SetUnlimitedMelee(bool isEnable);

	/// <summary>
	/// ����λ��
	/// </summary>
	/// <param name="translateDirection">�ƶ�����</param>
	/// <returns>�Ƿ�ɹ�</returns>
	/// <created>FeJQ,2020/4/10</created>
	/// <changed>FeJQ,2020/4/10</changed>
	bool CharacterTranlate(HotKey translateDirection);

	/// <summary>
	/// ��ȡ��������������
	/// </summary>
	/// <param name="weapon">��������</param>
	/// <param name="operateValue">������</param>
	/// <returns>��������</returns>
	/// <created>FeJQ,2020/4/9</created>
	/// <changed>FeJQ,2020/4/9</changed>
	int WeaponFireRate(WeaponType weapon, int operateValue = 0);

private:

	/// <summary>�����ӵ���ַ��ԭʼֵ</summary>
	int oldUnlimitedAmmoValue;

	/// <summary>׼�������߳̾��</summary>
	HANDLE hThreadLockSight;

	/// <summary>�����ӵ��߳̾��</summary>
	HANDLE hThreadUnlimitedAmmo;

	/// <summary>�����������߳̾��</summary>
	HANDLE hThreadMainWeaponFireRate;

	/// <summary>�����������߳̾��</summary>
	HANDLE hThreadSecondaryWeaponFireRate;

	/// <summary>��������</summary>
	Pos3D* pos1;
	Pos3D* pos2;
};

