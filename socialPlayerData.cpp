#include "socialPlayerData.hpp"

SocialPlayerData::SocialPlayerData()
{
	initGUI();
}
SocialPlayerData::ComboBox::ComboBox()
: Titel(new MyComboBox)
, Profession(new MyComboBox)
, SocialStatus(new MyComboBox)
{}
SocialPlayerData::Table::Table()
: Characteristics(new QTableWidget)
, OtherSpecifications(new QTableWidget)
, Advantages(new QTableWidget)
, Disadvantages(new QTableWidget)
, GenerallSpecialSkill(new QTableWidget)
{}
SocialPlayerData::Layout::Layout()
: hBox_Titel(new QHBoxLayout)
, hBox_Profession(new QHBoxLayout)
, hBox_SocialStatus(new QHBoxLayout)
, hBox_TopRow(new QHBoxLayout)
, hBox_BottomRow(new QHBoxLayout)
, vBox_Social(new QVBoxLayout)
, vBox_SocialPlayerData(new QVBoxLayout)
{}
SocialPlayerData::Frame::Frame()
: Titel(new QFrame)
, Profession(new QFrame)
, SocialStatus(new QFrame)
, Social(new QFrame)
, TopRow(new QFrame)
, BottomRow(new QFrame)
, SocialPlayerData(new QFrame)
{}

void SocialPlayerData::initComboBox() {
	setComboBox(m_ComboBox.Titel, {"TODO Titel"}, true);
	setComboBox(m_ComboBox.Profession, {"TODO Profession"}, true);
	setComboBox(m_ComboBox.SocialStatus, {"TODO Sozialstatus"}, true);
}
void SocialPlayerData::initTable() {
	setTable(m_Table.Characteristics, QStringList("Charakterisika"));
	setTable(m_Table.OtherSpecifications, QStringList("Sonstiges"));
	setTable(m_Table.Advantages, QStringList("Vorteile"));
	setTable(m_Table.Disadvantages, QStringList("Nachteile"));
	setTable(m_Table.GenerallSpecialSkill, QStringList("Allgemeine Sonderfertigkeiten"));
}
void SocialPlayerData::initLayout() {
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
void SocialPlayerData::initFrame() {
	m_Frame.Titel->setLayout(m_Layout.hBox_Titel);
	m_Frame.Profession->setLayout(m_Layout.hBox_Profession);
	m_Frame.SocialStatus->setLayout(m_Layout.hBox_SocialStatus);
	m_Frame.Social->setLayout(m_Layout.vBox_Social);
	m_Frame.TopRow->setLayout(m_Layout.hBox_TopRow);
	m_Frame.BottomRow->setLayout(m_Layout.hBox_BottomRow);
	m_Frame.SocialPlayerData->setLayout(m_Layout.vBox_SocialPlayerData);
}
void SocialPlayerData::initGUI() {
	initComboBox();
	initTable();
	initLayout();
	initFrame();
}

void SocialPlayerData::setComboBox(QComboBox *obj, std::vector<QString> items, bool isDisabled) {
	obj->clear();

	for (QString var : items) {
		obj->addItem(var);
	}

	setFont(obj, 12);
	obj->setFixedSize(QSize(300, 30));
	obj->setDisabled(isDisabled);
}
void SocialPlayerData::setTable(QTableWidget *obj, QStringList titel) {
	obj->setColumnCount(1);
	obj->setColumnWidth(0, 300);
	obj->setHorizontalHeaderLabels(titel);
	obj->setRowCount(5);
	obj->verticalHeader()->setVisible(false);

	for (int var = 0; var < 5; ++var)
	{
		obj->setRowHeight(var, 22);
	}

	obj->setFixedSize(300, 133);
	obj->setFont(QFont("Times New Roman", 12));
	obj->setSelectionMode(QTableWidget::NoSelection);
}
void SocialPlayerData::setFont(QWidget *obj, int size) {
	obj->setFont(QFont("Times New Roman", size, QFont::Bold));
}

QFrame* SocialPlayerData::getFrameSocialPlayerData() {
	return m_Frame.SocialPlayerData;
}
