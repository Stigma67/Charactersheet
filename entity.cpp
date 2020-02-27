#include "entity.hpp"

Entity::Entity()
{
	initGUI();
}

void Entity::initLabel()
{
	setLabel(m_Label.Mana, "MP:");
	setLabel(m_Label.Health, "HP:");
	setLabel(m_Label.Height, "Größe:");
	setLabel(m_Label.Weight, "Gewicht:");
}

void Entity::initDoubleSpinBox()
{
	m_DoubleSpinBox.Height->setDecimals(2);
	setFont(m_DoubleSpinBox.Height, 12);

	m_DoubleSpinBox.Weight->setDecimals(2);
	setFont(m_DoubleSpinBox.Weight, 12);
}

void Entity::initLCDNumber()
{
	m_LCDNumber.Mana->setDigitCount(7);
	m_LCDNumber.Health->setDigitCount(7);
}

void Entity::initLayout()
{
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

void Entity::initFrame()
{
	m_Frame.Weight->setLayout(m_Layout.hBox_Weight);
	m_Frame.Height->setLayout(m_Layout.hBox_Height);
	m_Frame.Health->setLayout(m_Layout.hBox_Health);
	m_Frame.Mana->setLayout(m_Layout.hBox_Mana);
	m_Frame.HealthAndMana->setLayout(m_Layout.vBox_HealthAndMana);
	m_Frame.Entity->setLayout(m_Layout.hBox_Entity);
}

void Entity::initGUI()
{
	initLabel();
	initDoubleSpinBox();
	initLCDNumber();

	setCheckbox(m_CheckBox_Magical);
	setComboBox(m_ComboBox_Species, {"TODO Spezies"});

	initLayout();
	initFrame();
}

void Entity::setLabel(QLabel* obj, QString text)
{
	obj->setText(text);
	setFont(obj, 16);
	obj->setAlignment(Qt::AlignLeft);
	obj->setFixedSize(QSize(100, 20));
}

void Entity::setCheckbox(QCheckBox* obj)
{
	obj->setText("Magisch");
	setFont(obj, 12);
}

void Entity::setComboBox(QComboBox* obj, std::vector<QString> items)
{
	obj->clear();

	for (QString var : items) {
		obj->addItem(var);
	}

	setFont(obj, 12);
	obj->setFixedSize(QSize(300, 30));
}

void Entity::setFont(QWidget *obj, int size)
{
	obj->setFont(QFont("Times New Roman", size, QFont::Bold));
}

QFrame* Entity::getFrameEntity()
{
	return m_Frame.Entity;
}
