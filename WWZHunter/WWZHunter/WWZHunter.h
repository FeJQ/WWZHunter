#pragma once

#include <QtWidgets/QWidget>
#include "ui_WWZHunter.h"
#include "Hunter.h"



class WWZHunter : public QWidget
{
	Q_OBJECT

public:

	WWZHunter(QWidget *parent = Q_NULLPTR);	
	~WWZHunter();
	/// <summary>辅助对象</summary>
	Hunter* hunter;

	/// <summary>游戏是否正在运行</summary>
	bool isGameRunning;

	/// <summary>游戏进程名</summary>
	const char* gameProcessName;
	

private:

	Ui::WWZHunterClass ui;

	/// <summary>
	/// 初始化界面
	/// </summary>
	/// <created>FeJQ,2020/4/8</created>
	/// <changed>FeJQ,2020/4/8</changed>
	void GUIInit();

	/// <summary>
	/// 初始化信号
	/// </summary>
	/// <created>FeJQ,2020/4/8</created>
	/// <changed>FeJQ,2020/4/8</changed>
	void SignalInit();

	/// <summary>
	/// 绑定快捷键
	/// </summary>
	/// <created>FeJQ,2020/4/10</created>
	/// <changed>FeJQ,2020/4/10</changed>
	void BindHotKey();


	/// <summary>
	/// 取消快捷键
	/// </summary>
	/// <created>FeJQ,2020/4/10</created>
	/// <changed>FeJQ,2020/4/10</changed>
	void UnBindHotKey();


	/// <summary>
	/// 消息处理
	/// </summary>
	/// <param name="eventType">消息类型</param>
	/// <param name="message">消息</param>
	/// <param name="result">结果</param>
	/// <returns>处理结果</returns>
	/// <created>FeJQ,2020/4/10</created>
	/// <changed>FeJQ,2020/4/10</changed>
	bool nativeEvent(const QByteArray& eventType, void* message, long* result);

	
	/// <summary>
	/// 播放音乐
	/// </summary>
	/// <param name="pszSound"></param>
	/// <param name="hmod"></param>
	/// <param name="fdwSound"></param>
	/// <returns></returns>
	/// <created>FeJQ,2020/4/10</created>
	/// <changed>FeJQ,2020/4/10</changed>
	bool PlayMusic(LPCSTR pszSound, HMODULE hmod, DWORD fdwSound);


	/// <summary>
	/// 设置人物位移快捷键
	/// </summary>
	/// <param name="isEnable">是否启用快捷键</param>
	/// <created>FeJQ,2020/4/10</created>
	/// <changed>FeJQ,2020/4/10</changed>
	void SetCharacterTranslation(bool isEnable);
};
