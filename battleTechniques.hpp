#ifndef BATTLETECHNIQUES_HPP
#define BATTLETECHNIQUES_HPP

#include <QLCDNumber>
#include <QLabel>
#include <QTableWidget>
#include <QHeaderView>
#include <QLayout>
#include "myQtObjects.hpp"

enum WeaponTypes
{
	ARMBRUEST = 0,
	BOEGEN,
	DOLCH,
	HIEBWAFFE,
	KETTENWAFFE,
	LANZE,
	PEITSCHE,
	RAUFEN,
	SCHILD,
	SCHLEUDER,
	SCHWERT,
	WURFWAFFE,
};
class BattleTechniquesGUI
{
private:
	struct Weapons {
		MySpinBox* SpinBoxAttack;
		MySpinBox* SpinBoxParry;
		MySpinBox* SpinBoxAP;
		QLCDNumber* LCDNumberValue;
		QLabel* LabelWeaponClass;
		std::string Distance;

		Weapons(QString weaponClass = "", std::string distance = "");
	};
	std::map<WeaponTypes, Weapons> m_WeaponGUI;
	QTableWidget* m_Table_WeaponGUIMelee;
	QTableWidget* m_Table_WeaponGUIRanged;
	QHBoxLayout* m_Layout_WeaponGUI;
	QFrame* m_Frame_WeaponGUI;

	void initSpinBox();
	void initTableWidgetItem();
	void initTableWidget();
	void initGUI();

	void setLabel(QLabel* label);
	void setSpinBox(QSpinBox* spinBox);
	void addItemsToTable(QTableWidget* table, std::vector<QWidget*> items, int row);


public:
	BattleTechniquesGUI();

	QFrame* getFrame();
};

//unsigned int m_SkillValue;
//unsigned int m_AttackValue;
//unsigned int m_ParryValue;
//unsigned int m_UsedAP;
//bool m_CanParry;
#endif // BATTLETECHNIQUES_HPP
