#include "adventurePoints.hpp"

AdventurePoints::AdventurePoints()
{
	initGUI();
}

void AdventurePoints::initLabel()
{
	m_Label.APAll->setText("AP Gesamt");
	setFont(m_Label.APAll);

	m_Label.APUsed->setText("AP Verbraucht");
	setFont(m_Label.APUsed);

	m_Label.APRemaining->setText("AP Verbleibende");
	setFont(m_Label.APRemaining);
}

void AdventurePoints::initSpinBoxAndLCD()
{
	m_LCD.APUsed->setDigitCount(6);
	m_LCD.APRemaining->setDigitCount(6);
	m_SpinBox_APAll->setRange(0, 999999);
	setFont(m_SpinBox_APAll);
}

void AdventurePoints::initLayout()
{
	m_Layout.vBox_APAll->addWidget(m_Label.APAll);
	m_Layout.vBox_APUsed->addWidget(m_Label.APUsed);
	m_Layout.vBox_APRemaining->addWidget(m_Label.APRemaining);

	m_Layout.vBox_APAll->addWidget(m_SpinBox_APAll);
	m_Layout.vBox_APUsed->addWidget(m_LCD.APUsed);
	m_Layout.vBox_APRemaining->addWidget(m_LCD.APRemaining);

	m_Layout.hBox_AP->addWidget(m_Frame.APAll);
	m_Layout.hBox_AP->addWidget(m_Frame.APUsed);
	m_Layout.hBox_AP->addWidget(m_Frame.APRemaining);
}

void AdventurePoints::initFrame()
{
	m_Frame.APAll->setLayout(m_Layout.vBox_APAll);
	m_Frame.APUsed->setLayout(m_Layout.vBox_APUsed);
	m_Frame.APRemaining->setLayout(m_Layout.vBox_APRemaining);

	m_Frame.AP->setLayout(m_Layout.hBox_AP);
}

void AdventurePoints::initGUI()
{
	initLabel();
	initSpinBoxAndLCD();
	initLayout();
	initFrame();
}

void AdventurePoints::setFont(QWidget* obj)
{
	obj->setFont(QFont("Times New Roman", 14));
}

QFrame* AdventurePoints::getFrameAdventurePoints()
{
	return m_Frame.AP;
}
