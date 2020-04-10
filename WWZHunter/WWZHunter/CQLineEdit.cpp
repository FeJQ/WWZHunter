#include "CQLineEdit.h"

CQLineEdit::CQLineEdit(QWidget* parent)
	: QLineEdit(parent)
{
	ui.setupUi(this);

	this->setReadOnly(true);
	this->setStyleSheet(
		"border:1px solid gray;background-color:rgb(98, 98, 98);padding-left:5px;"
	);
	this->setAlignment(Qt::AlignHCenter);
}

CQLineEdit::~CQLineEdit()
{
}

/// <summary>
/// 设置控件启用状态
/// </summary>
/// <param name="isEnale">是否启用</param>
/// <created>FeJQ,2020/3/26</created>
/// <changed>FeJQ,2020/3/26</changed>
void CQLineEdit::SetEnable(bool isEnale)
{
	this->setEnabled(isEnale);
	if (this->isEnabled())
	{
		this->setStyleSheet(
			"CQLineEdit{background-color:rgb(98,98,98);}"
			"CQLineEdit:hover{background-color:rgb(244,121,131);}"
		);
	}
	else
	{
		this->setStyleSheet(
			"CQLineEdit{background-color:rgb(50,50,50);}"
		);
	}
}
