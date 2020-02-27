#ifndef BATTLETECHNIQUES_HPP
#define BATTLETECHNIQUES_HPP

#include <QLabel>
#include <QTableWidget>
#include <QSpinBox>
#include <QLayout>

class BattleTechniques
{
private:
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

	//	>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> GUI >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	struct Weapons
	{
		QTableWidgetItem* WidgetItemWeaponType;
		QTableWidgetItem* WidgetItemSkill;
		QTableWidgetItem* WidgetItemAttack;
		QTableWidgetItem* WidgetItemParry;
		QSpinBox* SpinBoxAP;
		QString WeaponType;

		Weapons(WeaponTypes weaponType = ARMBRUEST);
	};

	std::map<WeaponTypes, Weapons> m_WeaponGUI;
	QTableWidget* m_Table_WeaponGUIOne;
	QTableWidget* m_Table_WeaponGUITwo;
	QHBoxLayout* m_Layout_WeaponGUI;
	QFrame* m_Frame_WeaponGUI;

	void initTableWidgetItem();
	void initTableWidget();
	void initGUI();

	void setWeaponType(WeaponTypes weaponType);
	//	<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< GUI <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

	unsigned int m_SkillValue;
	unsigned int m_AttackValue;
	unsigned int m_ParryValue;
	unsigned int m_UsedAP;
	bool m_CanParry;

public:
	BattleTechniques();
};

#endif // BATTLETECHNIQUES_HPP
