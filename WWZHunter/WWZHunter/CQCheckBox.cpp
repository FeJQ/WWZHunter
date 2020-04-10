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
	// ������ʽ
	
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

	// ��ʾ: ����Ҫ�ڳ�������ʱ��̬�ı����ʽ�ŵ�ȫ����ʽ��ͨ�� qApp ���أ�����Ĵ�������Ƿŵ� main ������
	// �ŵ�: ��Щ��ʽ���Ա������ļ��У��޸�ȫ����ʽ��ʱ����Ҫ�޸ĳ���Դ�룬ʹ�� qApp ���¼��ػ�������������ܿ���Ч����
	qApp->setStyleSheet(R"(
                        .AnimatedCheckBox[checked=true ] { background: rgb(244,121,131) }
                        .AnimatedCheckBox[checked=false] { background: rgb(97,97,97) }
                        .AnimatedCheckBoxIndicator { background: white }
    )");

	// AnimatedCheckBox ��ѡ��״̬�仯ʱ���޸� indicator ��λ��
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

		this->style()->polish(this); // checked ���Ա仯�ˣ�������ʽ
		});
}

CQCheckBox::~CQCheckBox()
{
}

/// <summary>
/// ���ÿؼ�����״̬
/// </summary>
/// <param name="isEnale">�Ƿ�����</param>
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

// ��д paintEvent ��������� QCheckBox ��Ĭ����ʽ
void CQCheckBox::paintEvent(QPaintEvent*) {}

// AnimatedCheckBox �Ĵ�С�ı�ʱ���� indicator ��λ��
void CQCheckBox::resizeEvent(QResizeEvent*)
{
	int b = this->contentsMargins().left();
	int x = this->isChecked() ? this->width() - indicator->width() - b : b;
	int y = b;
	int w = height() - b - b;
	int h = w;
	indicator->setGeometry(x, y, w, h);

	// ���� AnimatedCheckBox ����С��ȣ�����̫խ��ʱ��Ч������
	//this->setMinimumWidth(height());

	// ���� check box �� indicator ��Բ�Ǵ�С
	
	this->setStyleSheet(QString(".AnimatedCheckBox { border-radius: %1px } .AnimatedCheckBoxIndicator { border-radius: %2px }")
		.arg(this->height() / 2)
		.arg(indicator->height() / 2));
}

// ��� AnimatedCheckBox �ϵ��κεط����л�ѡ��״̬��QCheckBox Ĭ��ֻ�е������ indicator ��������ʱ�Ž����л�
void CQCheckBox::mousePressEvent(QMouseEvent* event)
{
	if (!m_isEnable)
	{
		return;
	}
	event->accept();
	setChecked(!isChecked());
}
