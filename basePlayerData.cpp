#include "basePlayerData.hpp"
#include <QDebug>

BasePlayerDataGUI::BasePlayerDataGUI()
: m_Label(Label())
, m_LineEdit(LineEdit())
, m_ComboBox(ComboBox())
, m_Layout(Layout())
, m_Frame(Frame())
, m_SpinBox_Age(new QSpinBox)
, m_DateTimeEdit_Birthday(new QDateTimeEdit)
{
	initGUI();
}
BasePlayerDataGUI::Label::Label()
: Birthday(new QLabel)
, Birthplace(new QLabel)
, Age(new QLabel)
, Gender(new QLabel)
, Culture(new QLabel)
{}
BasePlayerDataGUI::LineEdit::LineEdit()
: Player(new QLineEdit)
, Forename(new QLineEdit)
, Surname(new QLineEdit)
, Eyecolor(new QLineEdit)
, Haircolor(new QLineEdit)
{}
BasePlayerDataGUI::ComboBox::ComboBox()
: CultureMainGoup(new MyComboBox)
, CultureSubGoup(new MyComboBox)
, BirthplaceCity(new MyComboBox)
, BirthplaceRegion(new MyComboBox)
, BirthplaceCountry(new MyComboBox)
, Gender(new MyComboBox)
{}
BasePlayerDataGUI::Layout::Layout()
: hBox_TopRow(new QHBoxLayout)
, hBox_BottomRow(new QHBoxLayout)
, hBox_Birthday(new QHBoxLayout)
, hBox_Age(new QHBoxLayout)
, hBox_Gender(new QHBoxLayout)
, vBox_BasePlayerData(new QVBoxLayout)
, vBox_Name(new QVBoxLayout)
, vBox_Birthplace(new QVBoxLayout)
, vBox_BirthplaceComboBox(new QVBoxLayout)
, vBox_AgeAndGender(new QVBoxLayout)
, vBox_EyeAndHairColor(new QVBoxLayout)
, vBox_Culture(new QVBoxLayout)
{}
BasePlayerDataGUI::Frame::Frame()
: BasePlayerData(new QFrame)
, TopRow(new QFrame)
, Name(new QFrame)
, EyeAndHairColor(new QFrame)
, BottomRow(new QFrame)
, Birthplace(new QFrame)
, BirthplaceComboBox(new QFrame)
, Birthday(new QFrame)
, Culture(new QFrame)
, AgeAndGender(new QFrame)
, Age(new QFrame)
, Gender(new QFrame)
, Line_Horizontal01(new QFrame)
{}

void BasePlayerDataGUI::initLineEdit() {
	setLineEdit(m_LineEdit.Player, "Spielernamen eingeben");
	setLineEdit(m_LineEdit.Forename, "Vornamen eingeben");
	setLineEdit(m_LineEdit.Surname, "Nachnamen eingeben");
	setLineEdit(m_LineEdit.Eyecolor, "Augenfarbe eingeben");
	setLineEdit(m_LineEdit.Haircolor, "Haarfarbe eingeben");
}
void BasePlayerDataGUI::initLabel() {
	setLabel(m_Label.Culture, "Kultur:");
	setLabel(m_Label.Birthplace, "Geburtsort:");
	setLabel(m_Label.Birthday, "Geburtstag:");
	setLabel(m_Label.Gender, "Geschlecht:");
	setLabel(m_Label.Age, "Alter:");
}
void BasePlayerDataGUI::initComboBox() {
	setComboBox(m_ComboBox.CultureMainGoup, {"Hauptgruppe", "Drakonisch", "Zwergisch", "Elfisch"}, false);
	setComboBox(m_ComboBox.CultureSubGoup, {"Hauptgruppe Auswählen!!!"}, true);
	setComboBox(m_ComboBox.BirthplaceCity, {"TODO Stadt"}, true);
	setComboBox(m_ComboBox.BirthplaceRegion, {"TODO Region"}, true);
	setComboBox(m_ComboBox.BirthplaceCountry, {"TODO Land"}, true);
	setComboBox(m_ComboBox.Gender, {"Geschlecht", "Männlich", "Weiblich", "Divers"}, false);
}
void BasePlayerDataGUI::initLayout() {
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
void BasePlayerDataGUI::initFrame() {
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
void BasePlayerDataGUI::initGUI() {
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

void BasePlayerDataGUI::setLabel(QLabel* obj, QString text) {
	obj->setText(text);
	setFont(obj, 16);
	obj->setAlignment(Qt::AlignLeft);
	obj->setFixedSize(QSize(106, 20));
}
void BasePlayerDataGUI::setLineEdit(QLineEdit* obj, QString text) {
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
void BasePlayerDataGUI::setComboBox(QComboBox* obj, std::vector<QString> items, bool isDisabled) {
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
void BasePlayerDataGUI::setFont(QWidget *obj, int size) {
	obj->setFont(QFont("Times New Roman", size, QFont::Bold));
}

QFrame* BasePlayerDataGUI::getFrameBasePlayerData() {
	return m_Frame.BasePlayerData;
}

//-------------------------------------------------------------------------------------------------------------------------------------------

BasePlayerData::BasePlayerData()
: m_Age(0)
, m_BirthDay(0)
, m_BirthMonth(0)
, m_BirthYear(0)
, m_BirthplaceCity("")
, m_BirthplaceCountry("")
, m_BirthplaceRegion("")
, m_CultureMainGoup("")
, m_CultureSubGoup("")
, m_EyeColor("")
, m_Forename("")
, m_Gender("")
, m_HairColor("")
, m_Player("")
, m_Surname("")
{}

void BasePlayerData::setAge(int value) {
	m_Age = value;
}
void BasePlayerData::setBirthDay(int value) {
	m_BirthDay = value;
}
void BasePlayerData::setBirthMonth(int value) {
	m_BirthMonth = value;
}
void BasePlayerData::setBirthYear(int value) {
	m_BirthYear = value;
}
void BasePlayerData::setBirthplaceCity(std::string var) {
	m_BirthplaceCity = var;
}
void BasePlayerData::setBirthplaceCountry(std::string var) {
	m_BirthplaceCountry = var;
}
void BasePlayerData::setBirthplaceRegion(std::string var) {
	m_BirthplaceRegion = var;
}
void BasePlayerData::setCultureMainGoup(std::string var) {
	m_CultureMainGoup = var;
}
void BasePlayerData::setCultureSubGoup(std::string var) {
	m_CultureSubGoup = var;
}
void BasePlayerData::setEyeColor(std::string var) {
	m_EyeColor = var;
}
void BasePlayerData::setForename(std::string var) {
	m_Forename = var;
}
void BasePlayerData::setGender(std::string var) {
	m_Gender = var;
}
void BasePlayerData::setHairColor(std::string var) {
	m_HairColor = var;
}
void BasePlayerData::setPlayer(std::string var) {
	m_Player = var;
}
void BasePlayerData::setSurname(std::string var) {
	m_Surname = var;
}
int BasePlayerData::getAge() const {
	return m_Age;
}
int BasePlayerData::getBirthDay() const {
	return m_BirthDay;
}
int BasePlayerData::getBirthMonth() const {
	return m_BirthMonth;
}
int BasePlayerData::getBirthYear() const {
	return m_BirthYear;
}
std::string BasePlayerData::getBirthplaceCity() const {
	return m_BirthplaceCity;
}
std::string BasePlayerData::getBirthplaceCountry() const {
	return m_BirthplaceCountry;
}
std::string BasePlayerData::getBirthplaceRegion() const {
	return m_BirthplaceRegion;
}
std::string BasePlayerData::getCultureMainGoup() const {
	return m_CultureMainGoup;
}
std::string BasePlayerData::getCultureSubGoup() const {
	return m_CultureSubGoup;
}
std::string BasePlayerData::getEyeColor() const {
	return m_EyeColor;
}
std::string BasePlayerData::getForename() const {
	return m_Forename;
}
std::string BasePlayerData::getGender() const {
	return m_Gender;
}
std::string BasePlayerData::getHairColor() const {
	return m_HairColor;
}
std::string BasePlayerData::getPlayer() const {
	return m_Player;
}
std::string BasePlayerData::getSurname() const {
	return m_Surname;
}
