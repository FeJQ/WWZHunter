#pragma once

#include <QCheckBox>
#include "ui_CQCheckBox.h"
#include <QLabel>

class CQCheckBox : public QCheckBox
{
	Q_OBJECT

public:
	CQCheckBox(QWidget* parent = Q_NULLPTR);
	~CQCheckBox();

	/// <summary>
	/// 设置控件启用状态
	/// </summary>
	/// <param name="isEnale">是否启用</param>
	/// <created>FeJQ,2020/3/26</created>
	/// <changed>FeJQ,2020/3/26</changed>
	void SetEnable(bool isEnable);
protected:
	void CQCheckBox::paintEvent(QPaintEvent*)override;
	void CQCheckBox::resizeEvent(QResizeEvent*)override;
	void CQCheckBox::mousePressEvent(QMouseEvent* event)override;
private:
	Ui::CQCheckBox ui;
	QLabel* indicator;
	const int size = 20;
	bool m_isEnable;
};
