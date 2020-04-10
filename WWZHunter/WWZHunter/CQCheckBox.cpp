#include "CQCheckBox.h"

#include <QStyle>

#include <QMouseEvent>
#include <QApplication>
#include <QPropertyAnimation>
#include <QGraphicsDropShadowEffect>

CQCheckBox::CQCheckBox(QWidget* parent)
	: QCheckBox(parent)
{
	ui.setupUi(this);
	indicator = new QLabel(this);
	m_isEnable = this->isEnabled();
	// 设置样式
	
	this->setMinimumSize(size * 2, size);
	this->setMaximumSize(size * 2, size);


	this->setContentsMargins(2, 2, 2, 2);
	this->setAttribute(Qt::WA_StyledBackground, true);
	this->setProperty("class", "AnimatedCheckBox");

	indicator->setProperty("class", "AnimatedCheckBoxIndicator");
	QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect(this);
	effect->setBlurRadius(10);
	effect->setOffset(0, 1);
	indicator->setGraphicsEffect(effect);

	// 提示: 不需要在程序运行时动态改变的样式放到全局样式里通过 qApp 加载，下面的代码最好是放到 main 函数中
	// 优点: 这些样式可以保存在文件中，修改全局样式的时候不需要修改程序源码，使用 qApp 重新加载或者重启程序就能看到效果了
	qApp->setStyleSheet(R"(
                        .AnimatedCheckBox[checked=true ] { background: rgb(244,121,131) }
                        .AnimatedCheckBox[checked=false] { background: rgb(97,97,97) }
                        .AnimatedCheckBoxIndicator { background: white }
    )");

	// AnimatedCheckBox 的选中状态变化时，修改 indicator 的位置
	QPropertyAnimation* animation = new QPropertyAnimation(indicator, "pos", this);
	connect(this, &QCheckBox::toggled, [=] {
		int b = this->contentsMargins().left();
		int x = this->isChecked() ? this->width() - indicator->width() - b : b;
		int y = b;

		animation->stop();
		animation->setDuration(200);
		animation->setEndValue(QPoint(x, y));
		animation->setEasingCurve(QEasingCurve::InOutCubic);
		animation->start();

		this->style()->polish(this); // checked 属性变化了，更新样式
		});
}

CQCheckBox::~CQCheckBox()
{
}

/// <summary>
/// 设置控件启用状态
/// </summary>
/// <param name="isEnale">是否启用</param>
/// <created>FeJQ,2020/3/26</created>
/// <changed>FeJQ,2020/3/26</changed>
void CQCheckBox::SetEnable(bool isEnable)
{
	this->m_isEnable=isEnable;	
	if (this->m_isEnable)
	{
		this->setCursor(Qt::PointingHandCursor);
		resizeEvent(NULL);
	}
	else
	{
		this->setCursor(Qt::ForbiddenCursor);
	}
}

// 重写 paintEvent 方法，清除 QCheckBox 的默认样式
void CQCheckBox::paintEvent(QPaintEvent*) {}

// AnimatedCheckBox 的大小改变时调整 indicator 的位置
void CQCheckBox::resizeEvent(QResizeEvent*)
{
	int b = this->contentsMargins().left();
	int x = this->isChecked() ? this->width() - indicator->width() - b : b;
	int y = b;
	int w = height() - b - b;
	int h = w;
	indicator->setGeometry(x, y, w, h);

	// 设置 AnimatedCheckBox 的最小宽度，避免太窄的时候效果不好
	//this->setMinimumWidth(height());

	// 更新 check box 和 indicator 的圆角大小
	
	this->setStyleSheet(QString(".AnimatedCheckBox { border-radius: %1px } .AnimatedCheckBoxIndicator { border-radius: %2px }")
		.arg(this->height() / 2)
		.arg(indicator->height() / 2));
}

// 点击 AnimatedCheckBox 上的任何地方都切换选中状态，QCheckBox 默认只有点击它的 indicator 或者文字时才进行切换
void CQCheckBox::mousePressEvent(QMouseEvent* event)
{
	if (!m_isEnable)
	{
		return;
	}
	event->accept();
	setChecked(!isChecked());
}
