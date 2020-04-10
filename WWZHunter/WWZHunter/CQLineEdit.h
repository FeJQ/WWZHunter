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
	/// 设置控件启用状态
	/// </summary>
	/// <param name="isEnale">是否启用</param>
	/// <created>FeJQ,2020/3/26</created>
	/// <changed>FeJQ,2020/3/26</changed>
	void SetEnable(bool isEnale);
private:
	Ui::CQLineEdit ui;
protected:
};
