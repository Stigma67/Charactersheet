#ifndef BASEPLAYERDATA_HPP
#define BASEPLAYERDATA_HPP

#include <QLabel>
#include <QLineEdit>
#include <QLayout>
#include <QDateTimeEdit>
#include "myQtObjects.hpp"

enum TalentGroupNames
{
	GESELLSCHAFTSTALENTE = 0,
	HANDWERKSTALENTE,
	KOERPERTALENTE,
	KRIEGSKUNSTTALENTE,
	NATURTALENTE,
	WISSENSTALENTE
};
class BasePlayerDataGUI {
private:
	struct Label {
		QLabel* Birthday;
		QLabel* Birthplace;
		QLabel* Age;
		QLabel* Gender;
		QLabel* Culture;

		Label();
	};
	struct LineEdit {
		QLineEdit* Player;
		QLineEdit* Forename;
		QLineEdit* Surname;
		QLineEdit* Eyecolor;
		QLineEdit* Haircolor;

		LineEdit();
	};
	struct ComboBox {
		MyComboBox* CultureMainGoup;
		MyComboBox* CultureSubGoup;
		MyComboBox* BirthplaceCity;
		MyComboBox* BirthplaceRegion;
		MyComboBox* BirthplaceCountry;
		MyComboBox* Gender;

		ComboBox();
	};
	struct Layout {
		QHBoxLayout* hBox_TopRow;
		QHBoxLayout* hBox_BottomRow;
		QHBoxLayout* hBox_Birthday;
		QHBoxLayout* hBox_Age;
		QHBoxLayout* hBox_Gender;

		QVBoxLayout* vBox_BasePlayerData;
		QVBoxLayout* vBox_Name;
		QVBoxLayout* vBox_Birthplace;
		QVBoxLayout* vBox_BirthplaceComboBox;
		QVBoxLayout* vBox_AgeAndGender;
		QVBoxLayout* vBox_EyeAndHairColor;
		QVBoxLayout* vBox_Culture;

		Layout();
	};
	struct Frame {
		QFrame* BasePlayerData;

		QFrame* TopRow;
		QFrame* Name;
		QFrame* EyeAndHairColor;

		QFrame* BottomRow;
		QFrame* Birthplace;
		QFrame* BirthplaceComboBox;
		QFrame* Birthday;
		QFrame* Culture;

		QFrame* AgeAndGender;
		QFrame* Age;
		QFrame* Gender;

		QFrame* Line_Horizontal01;

		Frame();
	};
	Label m_Label;
	LineEdit m_LineEdit;
	ComboBox m_ComboBox;
	Layout m_Layout;
	Frame m_Frame;
	QSpinBox* m_SpinBox_Age;
	QDateTimeEdit* m_DateTimeEdit_Birthday;

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

	void initGUI();

public:
	BasePlayerDataGUI();
	QFrame* getFrameBasePlayerData();
};

#endif // BASEPLAYERDATA_HPP
