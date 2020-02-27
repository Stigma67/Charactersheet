#ifndef BASEPLAYERDATA_HPP
#define BASEPLAYERDATA_HPP

#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QSpinBox>
#include <QLayout>
#include <QDateTimeEdit>

class BasePlayerData
{
private:
	struct Label
	{
		QLabel* Birthday = new QLabel;
		QLabel* Birthplace = new QLabel;
		QLabel* Age = new QLabel;
		QLabel* Gender = new QLabel;
		QLabel* Culture = new QLabel;
	} m_Label;

	struct LineEdit
	{
		QLineEdit* Player = new QLineEdit;
		QLineEdit* Forename = new QLineEdit;
		QLineEdit* Surname = new QLineEdit;
		QLineEdit* Eyecolor = new QLineEdit;
		QLineEdit* Haircolor = new QLineEdit;
	} m_LineEdit;

	struct ComboBox
	{
		QComboBox* CultureMainGoup = new QComboBox;
		QComboBox* CultureSubGoup = new QComboBox;
		QComboBox* BirthplaceCity = new QComboBox;
		QComboBox* BirthplaceRegion = new QComboBox;
		QComboBox* BirthplaceCountry = new QComboBox;
		QComboBox* Gender = new QComboBox;
	} m_ComboBox;

	struct Layout
	{
		QHBoxLayout* hBox_TopRow = new QHBoxLayout;
		QHBoxLayout* hBox_BottomRow = new QHBoxLayout;
		QHBoxLayout* hBox_Birthday = new QHBoxLayout;
		QHBoxLayout* hBox_Age = new QHBoxLayout;
		QHBoxLayout* hBox_Gender = new QHBoxLayout;

		QVBoxLayout* vBox_BasePlayerData = new QVBoxLayout;
		QVBoxLayout* vBox_Name = new QVBoxLayout;
		QVBoxLayout* vBox_Birthplace = new QVBoxLayout;
		QVBoxLayout* vBox_BirthplaceComboBox = new QVBoxLayout;
		QVBoxLayout* vBox_AgeAndGender = new QVBoxLayout;
		QVBoxLayout* vBox_EyeAndHairColor = new QVBoxLayout;
		QVBoxLayout* vBox_Culture = new QVBoxLayout;
	} m_Layout;

	struct Frame
	{
		QFrame* BasePlayerData = new QFrame;

		QFrame* TopRow = new QFrame;
		QFrame* Name = new QFrame;
		QFrame* EyeAndHairColor = new QFrame;

		QFrame* BottomRow = new QFrame;
		QFrame* Birthplace = new QFrame;
		QFrame* BirthplaceComboBox = new QFrame;
		QFrame* Birthday = new QFrame;
		QFrame* Culture = new QFrame;

		QFrame* AgeAndGender = new QFrame;
		QFrame* Age = new QFrame;
		QFrame* Gender = new QFrame;

		QFrame* Line_Horizontal01 = new QFrame;
	} m_Frame;

	QSpinBox* m_SpinBox_Age = new QSpinBox;
	QDateTimeEdit* m_DateTimeEdit_Birthday = new QDateTimeEdit;

	void initLabel();
	void initLineEdit();
	void initComboBox();
	void initSpinBox();
	void initLayout();
	void initFrame();

	void setLabel(QLabel* obj, QString text);
	void setLineEdit(QLineEdit* obj, QString text);
	void setComboBox(QComboBox* obj, std::vector<QString> items, bool isDisabled);
	void setFrame(QFrame* obj, int size);
	void setFont(QWidget* obj, int size);

public:
	BasePlayerData();

	void initGUI();

	QFrame* getFrameBasePlayerData();
};

#endif // BASEPLAYERDATA_HPP
