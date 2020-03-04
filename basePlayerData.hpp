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

class BasePlayerData {
private:
	int m_Age;
	int m_BirthDay;
	int m_BirthMonth;
	int m_BirthYear;
	std::string m_BirthplaceCity;
	std::string m_BirthplaceCountry;
	std::string m_BirthplaceRegion;
	std::string m_CultureMainGoup;
	std::string m_CultureSubGoup;
	std::string m_EyeColor;
	std::string m_Forename;
	std::string m_Gender;
	std::string m_HairColor;
	std::string m_Player;
	std::string m_Surname;

public:
	BasePlayerData();

	void setAge(int value);
	void setBirthDay(int value);
	void setBirthMonth(int value);
	void setBirthYear(int value);
	void setBirthplaceCity(std::string var);
	void setBirthplaceCountry(std::string var);
	void setBirthplaceRegion(std::string var);
	void setCultureMainGoup(std::string var);
	void setCultureSubGoup(std::string var);
	void setEyeColor(std::string var);
	void setForename(std::string var);
	void setGender(std::string var);
	void setHairColor(std::string var);
	void setPlayer(std::string var);
	void setSurname(std::string var);
	int getAge() const;
	int getBirthDay() const;
	int getBirthMonth() const;
	int getBirthYear() const;
	std::string getBirthplaceCity() const;
	std::string getBirthplaceCountry() const;
	std::string getBirthplaceRegion() const;
	std::string getCultureMainGoup() const;
	std::string getCultureSubGoup() const;
	std::string getEyeColor() const;
	std::string getForename() const;
	std::string getGender() const;
	std::string getHairColor() const;
	std::string getPlayer() const;
	std::string getSurname() const;
};

#endif // BASEPLAYERDATA_HPP
