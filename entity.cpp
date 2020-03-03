#include "entity.hpp"

EntityGUI::EntityGUI()
: m_Label(Label())
, m_DoubleSpinBox(DoubleSpinBox())
, m_LCDNumber(LCDNumber())
, m_Layout(Layout())
, m_Frame(Frame())
, m_ComboBox_Species(new QComboBox)
, m_CheckBox_Magical(new QCheckBox)
{
	initGUI();
}
EntityGUI::Label::Label()
: Weight(new QLabel)
, Height(new QLabel)
, Health(new QLabel)
, Mana(new QLabel)
{}
EntityGUI::DoubleSpinBox::DoubleSpinBox()
: Weight(new QDoubleSpinBox)
, Height(new QDoubleSpinBox)
{}
EntityGUI::LCDNumber::LCDNumber()
: Health(new QLCDNumber)
, Mana(new QLCDNumber)
{}
EntityGUI::Layout::Layout()
: hBox_Weight(new QHBoxLayout)
, hBox_Height(new QHBoxLayout)
, hBox_Health(new QHBoxLayout)
, hBox_Mana(new QHBoxLayout)
, hBox_Entity(new QHBoxLayout)
, vBox_HealthAndMana(new QVBoxLayout)
{}
EntityGUI::Frame::Frame()
: Weight(new QFrame)
, Height(new QFrame)
, Health(new QFrame)
, Mana(new QFrame)
, HealthAndMana(new QFrame)
, Entity(new QFrame)
{}

void EntityGUI::initLabel() {
	setLabel(m_Label.Mana, "Manaenergie:", 140, 25);
	setLabel(m_Label.Health, "Lebensenergie:", 140, 25);
	setLabel(m_Label.Height, "Größe:", 80, 25);
	setLabel(m_Label.Weight, "Gewicht:", 80, 25);
}
void EntityGUI::initDoubleSpinBox() {
	m_DoubleSpinBox.Height->setDecimals(2);
	setFont(m_DoubleSpinBox.Height, 12);

	m_DoubleSpinBox.Weight->setDecimals(2);
	setFont(m_DoubleSpinBox.Weight, 12);
}
void EntityGUI::initLCDNumber() {
	m_LCDNumber.Mana->setDigitCount(7);
	m_LCDNumber.Health->setDigitCount(7);
}
void EntityGUI::initLayout() {
	m_Layout.hBox_Weight->addWidget(m_Label.Weight);
	m_Layout.hBox_Weight->addWidget(m_DoubleSpinBox.Weight);

	m_Layout.hBox_Height->addWidget(m_Label.Height);
	m_Layout.hBox_Height->addWidget(m_DoubleSpinBox.Height);

	m_Layout.hBox_Health->addWidget(m_Label.Health);
	m_Layout.hBox_Health->addWidget(m_LCDNumber.Health);

	m_Layout.hBox_Mana->addWidget(m_Label.Mana);
	m_Layout.hBox_Mana->addWidget(m_LCDNumber.Mana);

	m_Layout.vBox_HealthAndMana->addWidget(m_Frame.Health);
	m_Layout.vBox_HealthAndMana->addWidget(m_Frame.Mana);

	m_Layout.hBox_Entity->addWidget(m_Frame.Weight);
	m_Layout.hBox_Entity->addWidget(m_Frame.Height);
	m_Layout.hBox_Entity->addWidget(m_ComboBox_Species);
	m_Layout.hBox_Entity->addWidget(m_Frame.HealthAndMana);
	m_Layout.hBox_Entity->addWidget(m_CheckBox_Magical);
}
void EntityGUI::initFrame() {
	m_Frame.Weight->setLayout(m_Layout.hBox_Weight);
	m_Frame.Height->setLayout(m_Layout.hBox_Height);
	m_Frame.Health->setLayout(m_Layout.hBox_Health);
	m_Frame.Mana->setLayout(m_Layout.hBox_Mana);
	m_Frame.HealthAndMana->setLayout(m_Layout.vBox_HealthAndMana);
	m_Frame.Entity->setLayout(m_Layout.hBox_Entity);
}
void EntityGUI::initGUI() {
	initLabel();
	initDoubleSpinBox();
	initLCDNumber();

	setCheckbox(m_CheckBox_Magical);
	setComboBox(m_ComboBox_Species, {"TODO Spezies"});

	initLayout();
	initFrame();
}

void EntityGUI::setLabel(QLabel* obj, QString text, int width, int height) {
	obj->setText(text);
	setFont(obj, 16);
	obj->setAlignment(Qt::AlignLeft);
	obj->setFixedSize(QSize(width, height));
}
void EntityGUI::setCheckbox(QCheckBox* obj) {
	obj->setText("Magisch");
	setFont(obj, 12);
}
void EntityGUI::setComboBox(QComboBox* obj, std::vector<QString> items) {
	obj->clear();

	for (QString var : items) {
		obj->addItem(var);
	}

	setFont(obj, 12);
	obj->setFixedSize(QSize(300, 30));
}
void EntityGUI::setFont(QWidget *obj, int size) {
	obj->setFont(QFont("Times New Roman", size, QFont::Bold));
}

QFrame* EntityGUI::getFrameEntity() {
	return m_Frame.Entity;
}
