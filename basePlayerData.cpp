#include "basePlayerData.hpp"
#include <QDebug>

BasePlayerData::BasePlayerData()
{
	initGUI();
}

void BasePlayerData::initLineEdit()
{
	setLineEdit(m_LineEdit.Player, "Spielernamen eingeben");
	setLineEdit(m_LineEdit.Forename, "Vornamen eingeben");
	setLineEdit(m_LineEdit.Surname, "Nachnamen eingeben");
	setLineEdit(m_LineEdit.Eyecolor, "Augenfarbe eingeben");
	setLineEdit(m_LineEdit.Haircolor, "Haarfarbe eingeben");
}

void BasePlayerData::initLabel()
{
	setLabel(m_Label.Culture, "Kultur:");
	setLabel(m_Label.Birthplace, "Geburtsort:");
	setLabel(m_Label.Birthday, "Geburtstag:");
	setLabel(m_Label.Gender, "Geschlecht:");
	setLabel(m_Label.Age, "Alter:");
}

void BasePlayerData::initComboBox()
{
	setComboBox(m_ComboBox.CultureMainGoup, {"Hauptgruppe", "Drakonisch", "Zwergisch", "Elfisch"}, false);
	setComboBox(m_ComboBox.CultureSubGoup, {"Hauptgruppe Auswählen!!!"}, true);
	setComboBox(m_ComboBox.BirthplaceCity, {"TODO Stadt"}, true);
	setComboBox(m_ComboBox.BirthplaceRegion, {"TODO Region"}, true);
	setComboBox(m_ComboBox.BirthplaceCountry, {"TODO Land"}, true);
	setComboBox(m_ComboBox.Gender, {"Geschlecht", "Männlich", "Weiblich", "Divers"}, false);
}

void BasePlayerData::initLayout()
{
	m_Layout.vBox_Name->addWidget(m_LineEdit.Forename);
	m_Layout.vBox_Name->addWidget(m_LineEdit.Surname);

	m_Layout.vBox_EyeAndHairColor->addWidget(m_LineEdit.Eyecolor);
	m_Layout.vBox_EyeAndHairColor->addWidget(m_LineEdit.Haircolor);

	m_Layout.vBox_Culture->addWidget(m_Label.Culture);
	m_Layout.vBox_Culture->addWidget(m_ComboBox.CultureMainGoup);
	m_Layout.vBox_Culture->addWidget(m_ComboBox.CultureSubGoup);

	m_Layout.vBox_BirthplaceComboBox->addWidget(m_ComboBox.BirthplaceCountry);
	m_Layout.vBox_BirthplaceComboBox->addWidget(m_ComboBox.BirthplaceRegion);
	m_Layout.vBox_BirthplaceComboBox->addWidget(m_ComboBox.BirthplaceCity);
	m_Layout.vBox_Birthplace->addWidget(m_Label.Birthplace);
	m_Layout.vBox_Birthplace->addWidget(m_Frame.BirthplaceComboBox);

	m_Layout.hBox_Birthday->addWidget(m_Label.Birthday);
	m_Layout.hBox_Birthday->addWidget(m_DateTimeEdit_Birthday);

	m_Layout.hBox_Gender->addWidget(m_Label.Gender);
	m_Layout.hBox_Gender->addWidget(m_ComboBox.Gender);
	m_Layout.hBox_Age->addWidget(m_Label.Age);
	m_Layout.hBox_Age->addWidget(m_SpinBox_Age);
	m_Layout.vBox_AgeAndGender->addWidget(m_Frame.Birthday);
	m_Layout.vBox_AgeAndGender->addWidget(m_Frame.Age);
	m_Layout.vBox_AgeAndGender->addWidget(m_Frame.Gender);

	m_Layout.hBox_TopRow->addWidget(m_LineEdit.Player);
	m_Layout.hBox_TopRow->addWidget(m_Frame.Name);
	m_Layout.hBox_TopRow->addWidget(m_Frame.EyeAndHairColor);

	m_Layout.hBox_BottomRow->addWidget(m_Frame.Birthplace);
	m_Layout.hBox_BottomRow->addWidget(m_Frame.AgeAndGender);
	m_Layout.hBox_BottomRow->addWidget(m_Frame.Culture);

	m_Layout.vBox_BasePlayerData->addWidget(m_Frame.TopRow);
	m_Layout.vBox_BasePlayerData->addWidget(m_Frame.Line_Horizontal01);
	m_Layout.vBox_BasePlayerData->addWidget(m_Frame.BottomRow);
}

void BasePlayerData::initFrame()
{
	m_Frame.Line_Horizontal01->setFrameStyle(QFrame::HLine | QFrame::Plain);
	m_Frame.Line_Horizontal01->setLineWidth(3);

	m_Frame.Name->setLayout(m_Layout.vBox_Name);
	m_Frame.EyeAndHairColor->setLayout(m_Layout.vBox_EyeAndHairColor);
	m_Frame.TopRow->setLayout(m_Layout.hBox_TopRow);

	m_Frame.BirthplaceComboBox->setLayout(m_Layout.vBox_BirthplaceComboBox);
	m_Frame.Birthplace->setLayout(m_Layout.vBox_Birthplace);

	m_Frame.Birthday->setLayout(m_Layout.hBox_Birthday);
	m_Frame.Age->setLayout(m_Layout.hBox_Age);
	m_Frame.Gender->setLayout(m_Layout.hBox_Gender);
	m_Frame.AgeAndGender->setLayout(m_Layout.vBox_AgeAndGender);

	m_Frame.Culture->setLayout(m_Layout.vBox_Culture);

	m_Frame.BottomRow->setLayout(m_Layout.hBox_BottomRow);

	m_Frame.BasePlayerData->setLayout(m_Layout.vBox_BasePlayerData);
}

void BasePlayerData::initGUI()
{
	initLabel();
	initLineEdit();
	initComboBox();

	m_SpinBox_Age->setRange(0, 9999);
	setFont(m_SpinBox_Age, 12);
	m_SpinBox_Age->setFixedSize(QSize(66, 30));

	m_DateTimeEdit_Birthday->setDisplayFormat("dd.MM.yyyy");
	m_DateTimeEdit_Birthday->setDateRange(QDate(1, 1, 1), QDate(9999, 12, 31));
	m_DateTimeEdit_Birthday->setDate(QDate(3550, 1, 1));
	setFont(m_DateTimeEdit_Birthday, 12);
	m_DateTimeEdit_Birthday->setFixedSize(QSize(106, 30));
	initLayout();
	initFrame();
}

void BasePlayerData::setLabel(QLabel* obj, QString text)
{
	obj->setText(text);
	setFont(obj, 16);
	obj->setAlignment(Qt::AlignLeft);
	obj->setFixedSize(QSize(106, 20));
}

void BasePlayerData::setLineEdit(QLineEdit* obj, QString text)
{
	if(text == "Spielernamen eingeben")
	{
		obj->setPlaceholderText(text);
		setFont(obj, 20);
		obj->setFixedSize(QSize(300, 50));
	} else
	{
		obj->setPlaceholderText(text);
		setFont(obj, 12);
		obj->setFixedSize(QSize(300, 30));
	}
}

void BasePlayerData::setComboBox(QComboBox* obj, std::vector<QString> items, bool isDisabled)
{
	for (QString var : items)
	{
		obj->addItem(var);
	}

	if(items[0] == "Geschlecht")
	{
		setFont(obj, 12);
		obj->setFixedSize(QSize(100, 30));
		obj->setDisabled(isDisabled);
	} else
	{
		setFont(obj, 12);
		obj->setFixedSize(QSize(300, 30));
		obj->setDisabled(isDisabled);
	}
}

void BasePlayerData::setFont(QWidget *obj, int size)
{
	obj->setFont(QFont("Times New Roman", size, QFont::Bold));
}

QFrame* BasePlayerData::getFrameBasePlayerData()
{
	return m_Frame.BasePlayerData;
}
