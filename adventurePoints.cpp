#include "adventurePoints.hpp"

AdventurePointsGUI::AdventurePointsGUI()
: m_Layout(Layout())
, m_Frame(Frame())
, m_Label(Label())
, m_LCD(LCDNumber())
, m_SpinBox_APAll(new MySpinBox)
{
	initGUI();
}
AdventurePointsGUI::Layout::Layout()
: hBox_AP(new QHBoxLayout)
, vBox_APAll(new QVBoxLayout)
, vBox_APUsed(new QVBoxLayout)
, vBox_APRemaining(new QVBoxLayout)
{}
AdventurePointsGUI::Frame::Frame()
: APAll(new QFrame)
, APUsed(new QFrame)
, APRemaining(new QFrame)
, AP(new QFrame)
{}
AdventurePointsGUI::Label::Label()
: APAll(new QLabel)
, APUsed(new QLabel)
, APRemaining(new QLabel)
{}
AdventurePointsGUI::LCDNumber::LCDNumber()
: APUsed(new QLCDNumber)
, APRemaining(new QLCDNumber)
{}

void AdventurePointsGUI::initLabel() {
	m_Label.APAll->setText("AP Gesamt");
	setFont(m_Label.APAll);

	m_Label.APUsed->setText("AP Verbraucht");
	setFont(m_Label.APUsed);

	m_Label.APRemaining->setText("AP Verbleibende");
	setFont(m_Label.APRemaining);
}
void AdventurePointsGUI::initSpinBoxAndLCD() {
	m_LCD.APUsed->setDigitCount(6);
	m_LCD.APRemaining->setDigitCount(6);
	m_SpinBox_APAll->setRange(0, 999999);
	setFont(m_SpinBox_APAll);
}
void AdventurePointsGUI::initLayout() {
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
void AdventurePointsGUI::initFrame() {
	m_Frame.APAll->setLayout(m_Layout.vBox_APAll);
	m_Frame.APUsed->setLayout(m_Layout.vBox_APUsed);
	m_Frame.APRemaining->setLayout(m_Layout.vBox_APRemaining);

	m_Frame.AP->setLayout(m_Layout.hBox_AP);
}
void AdventurePointsGUI::initGUI() {
	initLabel();
	initSpinBoxAndLCD();
	initLayout();
	initFrame();
}

void AdventurePointsGUI::setFont(QWidget* obj) {
	obj->setFont(QFont("Times New Roman", 14));
}

QFrame* AdventurePointsGUI::getFrameAdventurePoints() {
	return m_Frame.AP;
}
