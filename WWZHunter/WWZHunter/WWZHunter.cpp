#include "WWZHunter.h"
#include <QTimer>
#include <QDir>
#include <mmsystem.h> 
#include <QTextCodec>
#pragma comment(lib, "winmm.lib")

//设置编码
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#define CKBRollBackTime 300
#define FireRateGrowth 500


WWZHunter::WWZHunter(QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	hunter = new Hunter;
	isGameRunning = false;
	gameProcessName = "wwzRetailEgs.exe";
	GUIInit();
	SignalInit();
	BindHotKey();

	QTimer* timer = new QTimer(this);
	connect(timer, &QTimer::timeout, [=]() {
		//设置状态指示灯颜色
		QString strBackColor = isGameRunning ? "Green" : "Red";
		ui.labState->setStyleSheet(
			"border-radius:8px;"
			"background-color:" + strBackColor
		);
		if (!isGameRunning)
		{
			//游戏结束后,应主动取消选中
			if (ui.ckbOfflineUnlimitedAmmo->isChecked())
			{
				ui.ckbOfflineUnlimitedAmmo->setChecked(false);
			}
			if (ui.ckbOfflineUnlimitedHealth->isChecked())
			{
				ui.ckbOfflineUnlimitedHealth->setChecked(false);
			}
		}
		ui.ckbOfflineUnlimitedAmmo->setCheckable(isGameRunning);
		ui.ckbOfflineUnlimitedAmmo->setCursor(isGameRunning ? Qt::PointingHandCursor : Qt::ForbiddenCursor);
		ui.ckbLockSight->setCheckable(isGameRunning);
		ui.ckbLockSight->setCursor(isGameRunning ? Qt::PointingHandCursor : Qt::ForbiddenCursor);
		ui.ckbOfflineUnlimitedHealth->setCheckable(isGameRunning);
		ui.ckbOfflineUnlimitedHealth->setCursor(isGameRunning ? Qt::PointingHandCursor : Qt::ForbiddenCursor);
		ui.ckbUnlimitedMelee->setCheckable(isGameRunning);
		ui.ckbUnlimitedMelee->setCursor(isGameRunning ? Qt::PointingHandCursor : Qt::ForbiddenCursor);
		ui.ckbAdjustPos->setCheckable(isGameRunning);
		ui.ckbAdjustPos->setCursor(isGameRunning ? Qt::PointingHandCursor : Qt::ForbiddenCursor);

		});
	timer->start(1000);
}

WWZHunter::~WWZHunter()
{
	//注销快捷键
	UnregisterHotKey((HWND)this->winId(), HotKey::UnlimitedHealth);
	UnregisterHotKey((HWND)this->winId(), HotKey::NoRecoil);
	UnregisterHotKey((HWND)this->winId(), HotKey::UnlimitedAmmo);
	UnregisterHotKey((HWND)this->winId(), HotKey::UnlimitedMelee);
	UnregisterHotKey((HWND)this->winId(), HotKey::CharacterTranslate);
	UnregisterHotKey((HWND)this->winId(), HotKey::DecreaseWeaponFireRate);
	UnregisterHotKey((HWND)this->winId(), HotKey::IncreaseWeaponFireRate);
	SetCharacterTranslation(false);
}

QString QByteToQString(const QByteArray& byte)
{
	QString result;
	if (byte.size() > 0) {
		QTextCodec* codec = QTextCodec::codecForName("utf-8");
		result = codec->toUnicode(byte);
	}
	return result;
}
QByteArray qstringToByte(const QString& strInfo)
{
	QByteArray result;
	if (strInfo.length() > 0) {
		QTextCodec* codec = QTextCodec::codecForName("utf-8");
		result = codec->fromUnicode(strInfo);
	}
	return result;
}
QString EncryptionStr(QString str)
{
	std::wstring wString = str.toStdWString();
	static QByteArray key = "WWZHunter";
	for (int i = 0; i < wString.size(); i++)
	{
		wString[i] = wString[i] ^ key[i % key.size()];
	}
	return QString::fromStdWString(wString).toUtf8();
}

/// <summary>
/// 初始化界面
/// </summary>
/// <created>FeJQ,2020/4/8</created>
/// <changed>FeJQ,2020/4/8</changed>
void WWZHunter::GUIInit()
{
	QFont font;
	font.setFamily("Microsoft YaHei");
	font.setPointSize(15);
	font.setBold(true);
	ui.labTitle->setFont(font);

	QPalette palette(this->palette());
	palette.setColor(QPalette::Background, qRgb(50, 50, 50));
	this->setPalette(palette);

	ui.labTitle->setText(tr("WORLD WAR Z HUNTER"));
	ui.tabCard->setTabText(0, tr("游戏"));
	ui.tabCard->setTabText(1, tr("选项"));
	ui.labOfflineUnlimitedHealth->setText(tr("无限血量"));
	ui.labLockSight->setText(tr("无后座力"));
	ui.labOfflineUnlimitedAmmo->setText(tr("无限子弹"));
	ui.labUnlimitedMelee->setText(tr("无限近战"));
	ui.labAdjustPos->setText(tr("人物位移"));
	ui.labAdjustMainWeaponFireRate->setText(tr("主武器射速"));
	ui.labAdjustSencondWeaponFireRate->setText(tr("副武器射速"));
	ui.txtAdjustMainWeaponFireRateValue->setText("NULL");
	ui.txtAdjustSencondWeaponFireRateValue->setText("NULL");
	ui.labMusic->setText(tr("音效"));
	ui.labHotKey->setText(tr("启用快捷键"));
	ui.ckbMusic->setChecked(true);
	ui.txtMusic->setText(tr("没有快捷键"));
	ui.txtHotKey->setText(tr("无效的选项"));
	ui.tabCard->setTabText(2, tr("声明"));
	ui.txtAbout->setReadOnly(true);
	//ui.txtAbout->setEnabled(false);

	////打印密文
	//QByteArray sourceTxt = "1.此软件仅供单机娱乐使用,禁止用于PVP.\n\n2.此软件免费提供, 无需登录, 无毒, 无广告.\n\n\t\t//\tAuthor:FeJQ";
	//QByteArray cryptTxt = qstringToByte(EncryptionStr(QByteToQString(sourceTxt)));
	//QByteArray base64Txt = cryptTxt.toBase64();

	//由上述三行代码计算出密文:
	QByteArray code = "ZnnmrL7ovKfkuoPkuqvkv6/ljLDmnYjlqabkuIfkvKXnlaBZ56ev5qyW55WN5Lu8BwEKZn9kRkvmrJbovLjkuqHlhJfotbHmjqXkv7VYReaWkumdl+eYrOW8j2RV5paO5q6mSVLmlrfluKjlkJBmf2R9bHsWIi4gGhxOIxcdBg==";
	//解密
	QByteArray b = QByteArray::fromBase64(code);
	QString result=EncryptionStr(QByteToQString(b));
	
	ui.txtAbout->setText(
		result
	);


	//状态指示灯
	ui.labState->setText("");
	ui.labState->setStyleSheet(
		"background-color:red;"
		"border-radius:8px;"
	);
	QString strRateValueStyle = "background-color:rgb(50,50,50);color:white;border:1px solid gray;border-radius:5px;";
	ui.txtAdjustMainWeaponFireRateValue->setStyleSheet(strRateValueStyle);
	ui.txtAdjustSencondWeaponFireRateValue->setStyleSheet(strRateValueStyle);


	this->setStyleSheet(
		//All
		"*{color:white;}"
		//QPushButton,QToolButton
		"QPushButton,QToolButton{background-color:rgb(244,121,131);border-radius:3px;}"
		"QPushButton:hover,QToolButton:hover{background-color:rgb(254,161,161);}"
		"QPushButton:pressed,QToolButton:pressed{background-color:rgb(176,48,96);}"
		//QProgressBar
		"QProgressBar{background-color:rgb(50,50,50);border:1px solid gray;border-radius: 5px;}"
		"QProgressBar::chunk{border-radius:5px;border:1px solid black;\
		background-color:rgb(244,121,131);width:8px;margin:0.2px;}"
		//QTabWidget
		"QTabWidget::pane {border: 1px solid gray;}"
		"QTabBar:tab{background:rgb(50,50,50);border:1px solid gray;width:50px;height:25px;\
         top:3px;border-top-left-radius:3px;border-top-right-radius:3px;}"
		"QTabBar:tab:hover{background:rgb(254,161,161);}"
		"QTabBar:tab:selected{background:rgb(244,121,131);top:0px;}"
		//QTextEdit
		"QTextEdit{background-color:rgb(50,50,50);border:none;}"
	);
}

/// <summary>
/// 扫描游戏线程回调
/// </summary>
/// <param name="lpParam"></param>
/// <returns></returns>
/// <created>FeJQ,2020/4/9</created>
/// <changed>FeJQ,2020/4/9</changed>
DWORD WINAPI ScanGameProcess(LPVOID lpParam)
{
	while (true)
	{
		WWZHunter* wwzHunter = (WWZHunter*)lpParam;
		bool bRet = wwzHunter->hunter->Load(wwzHunter->gameProcessName);
		wwzHunter->isGameRunning = bRet;
		Sleep(1000);
	}
}


/// <summary>
/// 初始化信号
/// </summary>
/// <created>FeJQ,2020/4/8</created>
/// <changed>FeJQ,2020/4/8</changed>
void WWZHunter::SignalInit()
{
	//扫描游戏进程
	CreateThread(NULL, 0, ScanGameProcess, this, 0, NULL);


	//开启\关闭无限血量
	connect(ui.ckbOfflineUnlimitedHealth, &QCheckBox::stateChanged, [=]() {
		bool bRet = PlayMusic(ui.ckbOfflineUnlimitedHealth->isChecked() ? "Sound\\turn on.wav" : "Sound\\turn off.wav",
			NULL, SND_ASYNC | SND_NODEFAULT);
		if (!hunter->SetUnlimitedHealth(ui.ckbOfflineUnlimitedHealth->isChecked()))
		{
			QTimer* timer = new QTimer;
			timer->setSingleShot(true);
			connect(timer, &QTimer::timeout, [=]() {
				ui.ckbOfflineUnlimitedHealth->setChecked(false);
				});
			timer->start(CKBRollBackTime);
		}

		});

	//开启\关闭无后座力
	connect(ui.ckbLockSight, &QCheckBox::stateChanged, [=]() {
		bool bRet = PlayMusic(ui.ckbLockSight->isChecked() ? "Sound\\turn on.wav" : "Sound\\turn off.wav", NULL, SND_ASYNC | SND_NODEFAULT);
		if (!hunter->SetLockSight(ui.ckbLockSight->isChecked()))
		{
			QTimer* timer = new QTimer;
			timer->setSingleShot(true);
			connect(timer, &QTimer::timeout, [=]() {
				ui.ckbLockSight->setChecked(false);
				});
			timer->start(CKBRollBackTime);
		}
		});

	//开启\关闭无限子弹
	connect(ui.ckbOfflineUnlimitedAmmo, &QCheckBox::stateChanged, [=]() {
		bool bRet = PlayMusic(ui.ckbOfflineUnlimitedAmmo->isChecked() ? "Sound\\turn on.wav" : "Sound\\turn off.wav", NULL, SND_ASYNC | SND_NODEFAULT);
		if (!hunter->SetUnlimitedAmmo(ui.ckbOfflineUnlimitedAmmo->isChecked()))
		{
			QTimer* timer = new QTimer;
			timer->setSingleShot(true);
			connect(timer, &QTimer::timeout, [=]() {
				ui.ckbOfflineUnlimitedAmmo->setChecked(false);
				});
			timer->start(CKBRollBackTime);
		}
		});

	//开启\关闭无限近战
	connect(ui.ckbUnlimitedMelee, &QCheckBox::stateChanged, [=]() {
		bool bRet = PlayMusic(ui.ckbUnlimitedMelee->isChecked() ? "Sound\\turn on.wav" : "Sound\\turn off.wav", NULL, SND_ASYNC | SND_NODEFAULT);
		if (!hunter->SetUnlimitedMelee(ui.ckbUnlimitedMelee->isChecked()))
		{
			QTimer* timer = new QTimer;
			timer->setSingleShot(true);
			connect(timer, &QTimer::timeout, [=]() {
				ui.ckbUnlimitedMelee->setChecked(false);
				});
			timer->start(CKBRollBackTime);
		}
		});

	//开启\关闭人物位移
	connect(ui.ckbAdjustPos, &QCheckBox::stateChanged, [=]() {
		bool bRet = PlayMusic(ui.ckbAdjustPos->isChecked() ? "Sound\\turn on.wav" : "Sound\\turn off.wav", NULL, SND_ASYNC | SND_NODEFAULT);
		SetCharacterTranslation(ui.ckbAdjustPos->isChecked());
		});


	//减少主武器射速
	connect(ui.btnAdjustMainWeaponFireRateDown, &QPushButton::clicked, [=]() {
		if (!isGameRunning) return;
		PlayMusic("Sound\\turn off.wav", NULL, SND_ASYNC | SND_NODEFAULT);
		int fireRateValue = hunter->WeaponFireRate(WeaponType::MainWeapon, 0 - FireRateGrowth);
		if (fireRateValue == 0)
		{
			ui.txtAdjustMainWeaponFireRateValue->setText(tr("NULL"));
			return;
		}
		ui.txtAdjustMainWeaponFireRateValue->setText(QString::number(fireRateValue));
		});

	//增加主武器射速
	connect(ui.btnAdjustMainWeaponFireRateUp, &QPushButton::clicked, [=]() {
		if (!isGameRunning) return;
		PlayMusic("Sound\\turn on.wav", NULL, SND_ASYNC | SND_NODEFAULT);
		int fireRateValue = hunter->WeaponFireRate(WeaponType::MainWeapon, FireRateGrowth);
		if (fireRateValue == 0)
		{
			ui.txtAdjustMainWeaponFireRateValue->setText(tr("NULL"));
			return;
		}
		ui.txtAdjustMainWeaponFireRateValue->setText(QString::number(fireRateValue));
		});

	//减少副武器射速
	connect(ui.btnAdjustSencondWeaponFireRateDown, &QPushButton::clicked, [=]() {
		if (!isGameRunning) return;
		PlayMusic("Sound\\turn off.wav", NULL, SND_ASYNC | SND_NODEFAULT);
		int fireRateValue = hunter->WeaponFireRate(WeaponType::SecondaryWeapon, 0 - FireRateGrowth);
		if (fireRateValue == 0)
		{
			ui.txtAdjustSencondWeaponFireRateValue->setText(tr("NULL"));
			return;
		}
		ui.txtAdjustSencondWeaponFireRateValue->setText(QString::number(fireRateValue));
		});

	//增加副武器射速
	connect(ui.btnAdjustSencondWeaponFireRateUp, &QPushButton::clicked, [=]() {
		if (!isGameRunning) return;
		PlayMusic("Sound\\turn on.wav", NULL, SND_ASYNC | SND_NODEFAULT);
		int fireRateValue = hunter->WeaponFireRate(WeaponType::SecondaryWeapon, FireRateGrowth);
		if (fireRateValue == 0)
		{
			ui.txtAdjustSencondWeaponFireRateValue->setText(tr("NULL"));
			return;
		}
		ui.txtAdjustSencondWeaponFireRateValue->setText(QString::number(fireRateValue));
		});

}

/// <summary>
/// 绑定快捷键
/// </summary>
/// <created>FeJQ,2020/4/10</created>
/// <changed>FeJQ,2020/4/10</changed>
void WWZHunter::BindHotKey()
{
	bool bRet = RegisterHotKey((HWND)this->winId(), HotKey::UnlimitedHealth, NULL, VK_F1);
	ui.txtOfflineUnlimitedHealth->setText(bRet ? "F1" : tr("热键被占用"));

	bRet = RegisterHotKey((HWND)this->winId(), HotKey::NoRecoil, NULL, VK_F2);
	ui.txtLockSight->setText(bRet ? "F2" : tr("热键被占用"));

	bRet = RegisterHotKey((HWND)this->winId(), HotKey::UnlimitedAmmo, NULL, VK_F3);
	ui.txtOfflineUnlimitedAmmo->setText(bRet ? "F3" : tr("热键被占用"));

	bRet = RegisterHotKey((HWND)this->winId(), HotKey::UnlimitedMelee, NULL, VK_F4);
	ui.txtUnlimitedMelee->setText(bRet ? "F4" : tr("热键被占用"));

	bRet = RegisterHotKey((HWND)this->winId(), HotKey::CharacterTranslate, NULL, VK_F5);
	ui.txtAdjustPos->setText(bRet ? "F5" : tr("热键被占用"));

	bool bRetMinus = RegisterHotKey((HWND)this->winId(), HotKey::DecreaseWeaponFireRate, NULL, VK_SUBTRACT);
	bool bRetPlus = RegisterHotKey((HWND)this->winId(), HotKey::IncreaseWeaponFireRate, NULL, VK_ADD);

	ui.txtAdjustMainWeaponFireRate->setText(bRetMinus && bRetPlus ? "- | +" : tr("热键被占用"));
	ui.txtAdjustSencondWeaponFireRate->setText(bRetMinus && bRetPlus ? "- | +" : tr("热键被占用"));


}

/// <summary>
/// 取消快捷键
/// </summary>
/// <created>FeJQ,2020/4/10</created>
/// <changed>FeJQ,2020/4/10</changed>
void WWZHunter::UnBindHotKey()
{

}


/// <summary>
/// 消息处理
/// </summary>
/// <param name="eventType">消息类型</param>
/// <param name="message">消息</param>
/// <param name="result">结果</param>
/// <returns></returns>
/// <created>FeJQ,2020/4/10</created>
/// <changed>FeJQ,2020/4/10</changed>
bool WWZHunter::nativeEvent(const QByteArray& eventType, void* message, long* result)
{
	MSG* pMsg = reinterpret_cast<MSG*>(message);
	if (pMsg->message == WM_HOTKEY)
	{
		switch (pMsg->wParam)
		{
		case UnlimitedHealth:
			ui.ckbOfflineUnlimitedHealth->setChecked(!ui.ckbOfflineUnlimitedHealth->isChecked());
			break;
		case NoRecoil:
			ui.ckbLockSight->setChecked(!ui.ckbLockSight->isChecked());
			break;
		case UnlimitedAmmo:
			ui.ckbOfflineUnlimitedAmmo->setChecked(!ui.ckbOfflineUnlimitedAmmo->isChecked());
			break;
		case UnlimitedMelee:
			ui.ckbUnlimitedMelee->setChecked(!ui.ckbUnlimitedMelee->isChecked());
			break;
		case CharacterTranslate:
			ui.ckbAdjustPos->setChecked(!ui.ckbOfflineUnlimitedHealth->isChecked());
			break;
		case DecreaseWeaponFireRate:
			emit ui.btnAdjustMainWeaponFireRateDown->clicked();
			emit ui.btnAdjustSencondWeaponFireRateDown->clicked();
			break;
		case IncreaseWeaponFireRate:
			emit ui.btnAdjustMainWeaponFireRateUp->clicked();
			emit ui.btnAdjustSencondWeaponFireRateUp->clicked();
			break;
		case TranslateFront:
			hunter->CharacterTranlate(HotKey::TranslateFront);
			break;
		case TranslateBack:
			hunter->CharacterTranlate(HotKey::TranslateBack);
			break;
		case TranslateLeft:
			hunter->CharacterTranlate(HotKey::TranslateLeft);
			break;
		case TranslateRight:
			hunter->CharacterTranlate(HotKey::TranslateRight);
			break;
		case TranslateUp:
			hunter->CharacterTranlate(HotKey::TranslateUp);
			break;
		case TranslateDown:
			hunter->CharacterTranlate(HotKey::TranslateDown);
			break;
		case CharacterPosRecord:
			hunter->CharacterTranlate(HotKey::CharacterPosRecord);
			break;
		case CharacterPosSet:
			hunter->CharacterTranlate(HotKey::CharacterPosSet);
			break;
		default:
			break;
		}
	}

	return QWidget::nativeEvent(eventType, message, result);;
}

/// <summary>
/// 播放音乐
/// </summary>
/// <param name="pszSound"></param>
/// <param name="hmod"></param>
/// <param name="fdwSound"></param>
/// <returns></returns>
/// <created>FeJQ,2020/4/10</created>
/// <changed>FeJQ,2020/4/10</changed>
bool WWZHunter::PlayMusic(LPCSTR pszSound, HMODULE hmod, DWORD fdwSound)
{
	if (ui.ckbMusic->isChecked())
	{
		return PlaySoundA(pszSound, hmod, fdwSound);
	}
	return false;
}

/// <summary>
/// 设置人物位移快捷键
/// </summary>
/// <param name="isEnable">是否启用快捷键</param>
/// <created>FeJQ,2020/4/10</created>
/// <changed>FeJQ,2020/4/10</changed>
void WWZHunter::SetCharacterTranslation(bool isEnable)
{
	if (isEnable)
	{
		RegisterHotKey((HWND)this->winId(), HotKey::TranslateFront, NULL, VK_UP);
		RegisterHotKey((HWND)this->winId(), HotKey::TranslateBack, NULL, VK_DOWN);
		RegisterHotKey((HWND)this->winId(), HotKey::TranslateLeft, NULL, VK_LEFT);
		RegisterHotKey((HWND)this->winId(), HotKey::TranslateRight, NULL, VK_RIGHT);
		RegisterHotKey((HWND)this->winId(), HotKey::TranslateUp, NULL, VK_PRIOR);
		RegisterHotKey((HWND)this->winId(), HotKey::TranslateDown, NULL, VK_NEXT);
		RegisterHotKey((HWND)this->winId(), HotKey::CharacterPosRecord, NULL, VK_INSERT);
		RegisterHotKey((HWND)this->winId(), HotKey::CharacterPosSet, NULL, VK_DELETE);
	}
	else
	{
		UnregisterHotKey((HWND)this->winId(), HotKey::TranslateFront);
		UnregisterHotKey((HWND)this->winId(), HotKey::TranslateBack);
		UnregisterHotKey((HWND)this->winId(), HotKey::TranslateLeft);
		UnregisterHotKey((HWND)this->winId(), HotKey::TranslateRight);
		UnregisterHotKey((HWND)this->winId(), HotKey::TranslateUp);
		UnregisterHotKey((HWND)this->winId(), HotKey::TranslateDown);
		UnregisterHotKey((HWND)this->winId(), HotKey::CharacterPosRecord);
		UnregisterHotKey((HWND)this->winId(), HotKey::CharacterPosSet);
	}
}

