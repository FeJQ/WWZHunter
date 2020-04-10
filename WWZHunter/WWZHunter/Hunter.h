#pragma once
#include <Windows.h>
enum HotKey
{
	/// <summary>无限生命</summary>
	UnlimitedHealth,

	/// <summary>无后坐力</summary>
	NoRecoil,

	/// <summary>无限子弹</summary>
	UnlimitedAmmo,

	/// <summary>无限近战</summary>
	UnlimitedMelee,

	/// <summary>人物位移</summary>
	CharacterTranslate,

	/// <summary>减少武器射速</summary>
	DecreaseWeaponFireRate,

	/// <summary>增加武器射速</summary>
	IncreaseWeaponFireRate,

	/// <summary>人物位移前</summary>
	TranslateFront,

	/// <summary>人物位移后</summary>
	TranslateBack,

	/// <summary>人物位移左</summary>
	TranslateLeft,

	/// <summary>人物位移右</summary>
	TranslateRight,

	/// <summary>人物位移上</summary>
	TranslateUp,

	/// <summary>人物位移下</summary>
	TranslateDown,

	/// <summary>记录人物坐标</summary>
	CharacterPosRecord,

	/// <summary>瞬移</summary>
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

/// <summary>WWZ进程句柄</summary>
extern HANDLE g_hProcess;


class Hunter
{
public:
	Hunter();
	~Hunter();

	/// <summary>临界区句柄</summary>
	CRITICAL_SECTION Critical;



	/// <summary>
	/// 读取内存
	/// </summary>
	/// <param name="lpBase">起始地址</param>
	/// <param name="lpBuff">数据缓冲区</param>
	/// <param name="size">大小</param>
	/// <returns>是否成功</returns>
	/// <created>FeJQ,2020/4/9</created>
	/// <changed>FeJQ,2020/4/9</changed>
	static bool ReadMemory(HANDLE hProcess, LPVOID lpBase, LPVOID lpBuff, int size);

	/// <summary>
	/// 写内存
	/// </summary>
	/// <param name="lpBase">起始地址</param>
	/// <param name="lpBuff">要写入的数据</param>
	/// <param name="size">大小</param>
	/// <returns>是否成功</returns>
	/// <created>FeJQ,2020/4/9</created>
	/// <changed>FeJQ,2020/4/9</changed>
	static bool WriteMemory(HANDLE hProcess, LPVOID lpBase, LPVOID lpBuff, int size);

	/// <summary>
	/// 加载辅助
	/// </summary>
	/// <param name="processName">目标进程名</param>
	/// <returns>是否成功</returns>
	/// <created>FeJQ,2020/4/8</created>
	/// <changed>FeJQ,2020/4/8</changed>
	bool Load(const char* processName);

	/// <summary>
	/// 设置无限血量
	/// </summary>
	/// <param name="isEnable">是否启用</param>
	/// <returns>是否成功</returns>
	/// <created>FeJQ,2020/4/8</created>
	/// <changed>FeJQ,2020/4/8</changed>
	bool SetUnlimitedHealth(bool isEnable);

	/// <summary>
	/// 锁定准星
	/// </summary>
	/// <param name="isEnable">是否启用</param>
	/// <returns>是否成功</returns>
	/// <created>FeJQ,2020/4/9</created>
	/// <changed>FeJQ,2020/4/9</changed>
	bool SetLockSight(bool isEnable);

	/// <summary>
	/// 设置无限子弹
	/// </summary>
	/// <param name="isEnable">是否启用</param>
	/// <returns>是否成功</returns>
	/// <created>FeJQ,2020/4/8</created>
	/// <changed>FeJQ,2020/4/8</changed>
	bool SetUnlimitedAmmo(bool isEnable);

	/// <summary>
	/// 设置无限近战
	/// </summary>
	/// <param name="isEnable">是否启用</param>
	/// <returns>是否成功</returns>
	/// <created>FeJQ,2020/4/10</created>
	/// <changed>FeJQ,2020/4/10</changed>
	bool SetUnlimitedMelee(bool isEnable);

	/// <summary>
	/// 人物位移
	/// </summary>
	/// <param name="translateDirection">移动方向</param>
	/// <returns>是否成功</returns>
	/// <created>FeJQ,2020/4/10</created>
	/// <changed>FeJQ,2020/4/10</changed>
	bool CharacterTranlate(HotKey translateDirection);

	/// <summary>
	/// 获取或设置武器射速
	/// </summary>
	/// <param name="weapon">武器类型</param>
	/// <param name="operateValue">增加数</param>
	/// <returns>武器射速</returns>
	/// <created>FeJQ,2020/4/9</created>
	/// <changed>FeJQ,2020/4/9</changed>
	int WeaponFireRate(WeaponType weapon, int operateValue = 0);

private:

	/// <summary>无限子弹地址的原始值</summary>
	int oldUnlimitedAmmoValue;

	/// <summary>准星锁定线程句柄</summary>
	HANDLE hThreadLockSight;

	/// <summary>无限子弹线程句柄</summary>
	HANDLE hThreadUnlimitedAmmo;

	/// <summary>主武器射速线程句柄</summary>
	HANDLE hThreadMainWeaponFireRate;

	/// <summary>副武器射速线程句柄</summary>
	HANDLE hThreadSecondaryWeaponFireRate;

	/// <summary>人物坐标</summary>
	Pos3D* pos1;
	Pos3D* pos2;
};

