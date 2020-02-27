#include "socialPlayerData.hpp"

SocialPlayerData::SocialPlayerData()
{
	initGUI();
}

void SocialPlayerData::initComboBox()
{
	setComboBox(m_ComboBox.Titel, {"TODO Titel"}, true);
	setComboBox(m_ComboBox.Profession, {"TODO Profession"}, true);
	setComboBox(m_ComboBox.SocialStatus, {"TODO Sozialstatus"}, true);
}

void SocialPlayerData::initTable()
{
	setTable(m_Table.Characteristics, QStringList("Charakterisika"));
	setTable(m_Table.OtherSpecifications, QStringList("Sonstiges"));
	setTable(m_Table.Advantages, QStringList("Vorteile"));
	setTable(m_Table.Disadvantages, QStringList("Nachteile"));
	setTable(m_Table.GenerallSpecialSkill, QStringList("Allgemeine Sonderfertigkeiten"));
}

void SocialPlayerData::initLayout()
{
	m_Layout.hBox_Titel->addWidget(m_ComboBox.Titel);
	m_Layout.hBox_Profession->addWidget(m_ComboBox.Profession);
	m_Layout.hBox_SocialStatus->addWidget(m_ComboBox.SocialStatus);

	m_Layout.vBox_Social->addWidget(m_Frame.Titel);
	m_Layout.vBox_Social->addWidget(m_Frame.Profession);
	m_Layout.vBox_Social->addWidget(m_Frame.SocialStatus);

	m_Layout.hBox_TopRow->addWidget(m_Frame.Social);
	m_Layout.hBox_TopRow->addItem(new QSpacerItem(10, 10, QSizePolicy::Expanding, QSizePolicy::Fixed));
	m_Layout.hBox_TopRow->addWidget(m_Table.Characteristics);
	m_Layout.hBox_TopRow->addItem(new QSpacerItem(10, 10, QSizePolicy::Expanding, QSizePolicy::Fixed));
	m_Layout.hBox_TopRow->addWidget(m_Table.OtherSpecifications);

	m_Layout.hBox_BottomRow->addWidget(m_Table.Advantages);
	m_Layout.hBox_TopRow->addItem(new QSpacerItem(10, 10, QSizePolicy::Expanding, QSizePolicy::Fixed));
	m_Layout.hBox_BottomRow->addWidget(m_Table.Disadvantages);
	m_Layout.hBox_TopRow->addItem(new QSpacerItem(10, 10, QSizePolicy::Expanding, QSizePolicy::Fixed));
	m_Layout.hBox_BottomRow->addWidget(m_Table.GenerallSpecialSkill);

	m_Layout.vBox_SocialPlayerData->addWidget(m_Frame.TopRow);
	m_Layout.vBox_SocialPlayerData->addWidget(m_Frame.BottomRow);
}

void SocialPlayerData::initFrame()
{
	m_Frame.Titel->setLayout(m_Layout.hBox_Titel);
	m_Frame.Profession->setLayout(m_Layout.hBox_Profession);
	m_Frame.SocialStatus->setLayout(m_Layout.hBox_SocialStatus);
	m_Frame.Social->setLayout(m_Layout.vBox_Social);
	m_Frame.TopRow->setLayout(m_Layout.hBox_TopRow);
	m_Frame.BottomRow->setLayout(m_Layout.hBox_BottomRow);
	m_Frame.SocialPlayerData->setLayout(m_Layout.vBox_SocialPlayerData);
}

void SocialPlayerData::setComboBox(QComboBox *obj, std::vector<QString> items, bool isDisabled)
{
	obj->clear();

	for (QString var : items) {
		obj->addItem(var);
	}

	setFont(obj, 12);
	obj->setFixedSize(QSize(300, 30));
	obj->setDisabled(isDisabled);
}

void SocialPlayerData::setTable(QTableWidget *obj, QStringList titel)
{
	obj->setRowCount(5);
	for (int var = 0; var < 5; ++var)
	{
		obj->setRowHeight(var, 22);
	}

	obj->verticalHeader()->setVisible(false);

	obj->setColumnCount(1);
	obj->setColumnWidth(0, 300);
	obj->setHorizontalHeaderLabels(titel);
	obj->setSelectionMode(QTableWidget::NoSelection);

	obj->setFixedSize(300, 133);

	obj->setFont(QFont("Times New Roman", 12));
}

void SocialPlayerData::setFont(QWidget *obj, int size)
{
	obj->setFont(QFont("Times New Roman", size, QFont::Bold));
}

void SocialPlayerData::initGUI()
{
	initComboBox();
	initTable();
	initLayout();
	initFrame();
}

QFrame* SocialPlayerData::getFrameSocialPlayerData()
{
	return m_Frame.SocialPlayerData;
}
