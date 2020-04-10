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
	/// <summary>��������</summary>
	Hunter* hunter;

	/// <summary>��Ϸ�Ƿ���������</summary>
	bool isGameRunning;

	/// <summary>��Ϸ������</summary>
	const char* gameProcessName;
	

private:

	Ui::WWZHunterClass ui;

	/// <summary>
	/// ��ʼ������
	/// </summary>
	/// <created>FeJQ,2020/4/8</created>
	/// <changed>FeJQ,2020/4/8</changed>
	void GUIInit();

	/// <summary>
	/// ��ʼ���ź�
	/// </summary>
	/// <created>FeJQ,2020/4/8</created>
	/// <changed>FeJQ,2020/4/8</changed>
	void SignalInit();

	/// <summary>
	/// �󶨿�ݼ�
	/// </summary>
	/// <created>FeJQ,2020/4/10</created>
	/// <changed>FeJQ,2020/4/10</changed>
	void BindHotKey();


	/// <summary>
	/// ȡ����ݼ�
	/// </summary>
	/// <created>FeJQ,2020/4/10</created>
	/// <changed>FeJQ,2020/4/10</changed>
	void UnBindHotKey();


	/// <summary>
	/// ��Ϣ����
	/// </summary>
	/// <param name="eventType">��Ϣ����</param>
	/// <param name="message">��Ϣ</param>
	/// <param name="result">���</param>
	/// <returns>������</returns>
	/// <created>FeJQ,2020/4/10</created>
	/// <changed>FeJQ,2020/4/10</changed>
	bool nativeEvent(const QByteArray& eventType, void* message, long* result);

	
	/// <summary>
	/// ��������
	/// </summary>
	/// <param name="pszSound"></param>
	/// <param name="hmod"></param>
	/// <param name="fdwSound"></param>
	/// <returns></returns>
	/// <created>FeJQ,2020/4/10</created>
	/// <changed>FeJQ,2020/4/10</changed>
	bool PlayMusic(LPCSTR pszSound, HMODULE hmod, DWORD fdwSound);


	/// <summary>
	/// ��������λ�ƿ�ݼ�
	/// </summary>
	/// <param name="isEnable">�Ƿ����ÿ�ݼ�</param>
	/// <created>FeJQ,2020/4/10</created>
	/// <changed>FeJQ,2020/4/10</changed>
	void SetCharacterTranslation(bool isEnable);
};
