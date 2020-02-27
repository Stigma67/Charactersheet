#ifndef TALENTS_HPP
#define TALENTS_HPP

#include <map>
#include "adventurePoints.hpp"

#include <QTableWidget>
#include <QHeaderView>
#include <QLayout>
#include <QFrame>

class Talents
{
private:
	//	>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>GUI>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	enum TalentGroupNames
	{
		GESELLSCHAFTSTALENTE = 0,
		HANDWERKSTALENTE,
		KOERPERTALENTE,
		KRIEGSKUNSTTALENTE,
		NATURTALENTE,
		WISSENSTALENTE
	};
	struct TalentData
	{
		QString NameTalent;
		QString NamePropertyOne;
		QString NamePropertyTwo;
		QString NamePropertyThree;
		unsigned int Value;
		QLabel* LabelTalent;
		QLabel* LabelPropertyOne;
		QLabel* LabelPropertyTwo;
		QLabel* LabelPropertyThree;
		QLCDNumber* LCDNumberPropertyOne;
		QLCDNumber* LCDNumberPropertyTwo;
		QLCDNumber* LCDNumberPropertyThree;
		QSpinBox* SpinBox;
		QTableWidget* TableWidget;

		TalentData(QString talentName = "", QString propertieOne = "", QString propertieTwo = "", QString propertieThree = "");
	};
	struct TalentGroup
	{
		QString TalentGroupName;
		std::vector<TalentData> Data;
		QTableWidget* TableWidget;

		TalentGroup(QString talentGroupName = "");
	};

	std::map<TalentGroupNames, TalentGroup> m_Talents;
	QVBoxLayout* m_Layout_Talents;
	QHBoxLayout* m_Layout_TopRow;
	QHBoxLayout* m_Layout_BottomRow;
	QFrame* m_Frame_TopRow;
	QFrame* m_Frame_BottomRow;
	QFrame* m_Frame_Talents;

	void initTalentGroup();
	void setTalentData(TalentGroupNames talentGroupName);

	void initLabel();
	void initLCDNumber();
	void initSpinbox();
	void initTableTalentData();
	void initTableTalentGroup();
	void initGUI();

	void setTableTalentData(QTableWidget* obj, int columns, int rows);
	void setTableTalentGroup(QTableWidget *obj, QStringList header, int rows);

	void checkPropertyType(QLabel* property, QLCDNumber* display, std::vector<int> values);
	void addLabelToTalentDataTable(QTableWidget* obj, std::vector<QLabel*> label);
	void addLCDNumberToTalentDataTable(QTableWidget* obj, std::vector<QLCDNumber*> lcdNumber);
	void addSpinBoxToTalentDataTable(QTableWidget* obj, QSpinBox* spinBox);
	void addTalentDataToTalentGroupTable(QTableWidget* obj, QTableWidget* talentData, int row);
	void mergeTalentDataTableCells(QTableWidget* obj);
	//	<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<GUI<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

public:
	Talents();

	QFrame* getFrame() const;
	void setPropertyValues(int ch, int ge, int in, int kk, int kl, int ko, int mu, int se);
};
#endif // TALENTS_HPP
