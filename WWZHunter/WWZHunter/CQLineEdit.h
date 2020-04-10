#pragma once

#include <QLineEdit>
#include "ui_CQLineEdit.h"
#include <QResizeEvent>

class CQLineEdit : public QLineEdit
{
	Q_OBJECT

public:
	CQLineEdit(QWidget* parent = Q_NULLPTR);
	~CQLineEdit();

	/// <summary>
	/// ���ÿؼ�����״̬
	/// </summary>
	/// <param name="isEnale">�Ƿ�����</param>
	/// <created>FeJQ,2020/3/26</created>
	/// <changed>FeJQ,2020/3/26</changed>
	void SetEnable(bool isEnale);
private:
	Ui::CQLineEdit ui;
protected:
};
