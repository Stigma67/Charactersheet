#include "properties.hpp"
#include <QDebug>

Properties::Properties()
: m_Label(Label())
, m_SpinBox(SpinBox())
, m_Layout(Layout())
, m_Frame(Frame())
{
	initGUI();
}
Properties::Label::Label()
: MU(new QLabel)
, KL(new QLabel)
, IN(new QLabel)
, CH(new QLabel)
, SE(new QLabel)
, GE(new QLabel)
, KO(new QLabel)
, KK(new QLabel)
{}
Properties::SpinBox::SpinBox()
: MU(new MySpinBox)
, KL(new MySpinBox)
, IN(new MySpinBox)
, CH(new MySpinBox)
, SE(new MySpinBox)
, GE(new MySpinBox)
, KO(new MySpinBox)
, KK(new MySpinBox)
{}
Properties::Layout::Layout()
: hBox_Talents(new QHBoxLayout)
, vBox_MU(new QVBoxLayout)
, vBox_KL(new QVBoxLayout)
, vBox_IN(new QVBoxLayout)
, vBox_CH(new QVBoxLayout)
, vBox_SE(new QVBoxLayout)
, vBox_GE(new QVBoxLayout)
, vBox_KO(new QVBoxLayout)
, vBox_KK(new QVBoxLayout)
{}
Properties::Frame::Frame()
: MU(new QFrame)
, KL(new QFrame)
, IN(new QFrame)
, CH(new QFrame)
, SE(new QFrame)
, GE(new QFrame)
, KO(new QFrame)
, KK(new QFrame)
, Properties(new QFrame)
{}

void Properties::initLabels() {
	m_Label.MU->setText("MU");
	setFont(m_Label.MU);

	m_Label.KL->setText("KL");
	setFont(m_Label.KL);

	m_Label.IN->setText("IN");
	setFont(m_Label.IN);

	m_Label.CH->setText("CH");
	setFont(m_Label.CH);

	m_Label.SE->setText("SE");
	setFont(m_Label.SE);

	m_Label.GE->setText("GE");
	setFont(m_Label.GE);

	m_Label.KO->setText("KO");
	setFont(m_Label.KO);

	m_Label.KK->setText("KK");
	setFont(m_Label.KK);
}
void Properties::initSpinBoxes() {
	m_SpinBox.MU->setRange(0, 30);
	setFont(m_SpinBox.MU);

	m_SpinBox.KL->setRange(0, 30);
	setFont(m_SpinBox.KL);

	m_SpinBox.IN->setRange(0, 30);
	setFont(m_SpinBox.IN);

	m_SpinBox.CH->setRange(0, 30);
	setFont(m_SpinBox.CH);

	m_SpinBox.SE->setRange(0, 30);
	setFont(m_SpinBox.SE);

	m_SpinBox.GE->setRange(0, 30);
	setFont(m_SpinBox.GE);

	m_SpinBox.KO->setRange(0, 30);
	setFont(m_SpinBox.KO);

	m_SpinBox.KK->setRange(0, 30);
	setFont(m_SpinBox.KK);
}
void Properties::initLayouts() {
	m_Layout.vBox_MU->addWidget(m_Label.MU);
	m_Layout.vBox_KL->addWidget(m_Label.KL);
	m_Layout.vBox_IN->addWidget(m_Label.IN);
	m_Layout.vBox_CH->addWidget(m_Label.CH);
	m_Layout.vBox_SE->addWidget(m_Label.SE);
	m_Layout.vBox_GE->addWidget(m_Label.GE);
	m_Layout.vBox_KO->addWidget(m_Label.KO);
	m_Layout.vBox_KK->addWidget(m_Label.KK);

	m_Layout.vBox_MU->addWidget(m_SpinBox.MU);
	m_Layout.vBox_KL->addWidget(m_SpinBox.KL);
	m_Layout.vBox_IN->addWidget(m_SpinBox.IN);
	m_Layout.vBox_CH->addWidget(m_SpinBox.CH);
	m_Layout.vBox_SE->addWidget(m_SpinBox.SE);
	m_Layout.vBox_GE->addWidget(m_SpinBox.GE);
	m_Layout.vBox_KO->addWidget(m_SpinBox.KO);
	m_Layout.vBox_KK->addWidget(m_SpinBox.KK);

	m_Layout.hBox_Talents->addWidget(m_Frame.MU);
	m_Layout.hBox_Talents->addWidget(m_Frame.KL);
	m_Layout.hBox_Talents->addWidget(m_Frame.IN);
	m_Layout.hBox_Talents->addWidget(m_Frame.CH);
	m_Layout.hBox_Talents->addWidget(m_Frame.SE);
	m_Layout.hBox_Talents->addWidget(m_Frame.GE);
	m_Layout.hBox_Talents->addWidget(m_Frame.KO);
	m_Layout.hBox_Talents->addWidget(m_Frame.KK);
}
void Properties::initFrames() {
	m_Frame.MU->setLayout(m_Layout.vBox_MU);
	setFrameColor(m_Frame.MU, "230", "0", "0");

	m_Frame.KL->setLayout(m_Layout.vBox_KL);
	setFrameColor(m_Frame.KL, "180", "0", "130");

	m_Frame.IN->setLayout(m_Layout.vBox_IN);
	setFrameColor(m_Frame.IN, "0", "150", "50");

	m_Frame.CH->setLayout(m_Layout.vBox_CH);
	setFrameColor(m_Frame.CH, "0", "0", "0");

	m_Frame.SE->setLayout(m_Layout.vBox_SE);
	setFrameColor(m_Frame.SE, "20", "80", "255");

	m_Frame.GE->setLayout(m_Layout.vBox_GE);
	setFrameColor(m_Frame.GE, "200", "200", "0");

	m_Frame.KO->setLayout(m_Layout.vBox_KO);
	setFrameColor(m_Frame.KO, "80", "40", "0");

	m_Frame.KK->setLayout(m_Layout.vBox_KK);
	setFrameColor(m_Frame.KK, "255", "100", "0");

	m_Frame.Properties->setLayout(m_Layout.hBox_Talents);
}
void Properties::initGUI() {
	initLabels();
	initSpinBoxes();
	initLayouts();
	initFrames();
}

void Properties::setFont(QWidget* obj) {
	obj->setFont(QFont("Times New Roman", 14));
}
void Properties::setFrameColor(QFrame* obj, QString red, QString green, QString blue) {
	obj->setStyleSheet("border-color: rgb("+red+", "+green+", "+blue+"); border-width: 2px; border-style: inset;");
}

QFrame* Properties::getFrameProperties() {
	return m_Frame.Properties;
}
