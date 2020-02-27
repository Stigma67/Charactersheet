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
	struct TalentGUI
	{
		QString NameTalent;
		QString NamePropertyOne;
		QString NamePropertyTwo;
		QString NamePropertyThree;
		QTableWidgetItem* TableWidgetItemTalent;
		QTableWidgetItem* TableWidgetItemPropertyOne;
		QTableWidgetItem* TableWidgetItemPropertyTwo;
		QTableWidgetItem* TableWidgetItemPropertyThree;
		QLCDNumber* LCDNumberPropertyOne;
		QLCDNumber* LCDNumberPropertyTwo;
		QLCDNumber* LCDNumberPropertyThree;
		QSpinBox* SpinBox;
		QTableWidget* TableWidget;

		TalentGUI(QString talentName = "", QString propertieOne = "", QString propertieTwo = "", QString propertieThree = "");
	};
	struct TalentGroupGUI
	{
		QString TalentGroupName;
		std::vector<TalentGUI> Data;
		QTableWidget* TableWidget;

		TalentGroupGUI(QString talentGroupName = "");
	};

	std::map<TalentGroupNames, TalentGroupGUI> m_TalentGUI;
	QVBoxLayout* m_Layout_Talents;
	QHBoxLayout* m_Layout_TopRow;
	QHBoxLayout* m_Layout_BottomRow;
	QFrame* m_Frame_TopRow;
	QFrame* m_Frame_BottomRow;
	QFrame* m_Frame_Talents;

	void initTalentGroup();
	void setTalentData(TalentGroupNames talentGroupName);

	void initTableWidgetItem();
	void initLCDNumber();
	void initSpinbox();
	void initTableTalentData();
	void initTableTalentGroup();
	void initGUI();

	void setTableTalentData(QTableWidget* obj, int columns, int rows);
	void setTableTalentGroup(QTableWidget *obj, QStringList header, int rows);

	void checkPropertyType(QTableWidgetItem* property, QLCDNumber* display, std::vector<int> values);
	void addLabelToTalentDataTable(QTableWidget* obj, std::vector<QTableWidgetItem*> label);
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
