#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include <QFrame>
#include <QLayout>
#include <QTableWidget>
#include <QHeaderView>
#include <QLabel>
#include <QLineEdit>
#include <QLCDNumber>
#include <QCheckBox>
#include "myQtObjects.hpp"

class InventoryGUI
{
private:
	struct Table {
		QTableWidget* MeleeWeapons;
		QTableWidget* RangedWeapons;
		QTableWidget* Armor;
		QTableWidget* SchildOrParade;
		QTableWidget* InventoryItems;
		QTableWidget* InventoryWAC;

		Table();
	};
	struct LayoutAndFrame {
		QVBoxLayout* vBox_Equipment;
		QHBoxLayout* hBox_Inventory;

		QFrame* Frame_Equipment;
		QFrame* Frame_Inventory;

		LayoutAndFrame();
	};
	struct MeleeWeaponItems {
		MyComboBox* Weapon;
		MyComboBox* BattleTechnique;
		QLineEdit* Damage;
		MySpinBox* AtatckModification;
		MySpinBox* ParadeModification;
		QLCDNumber* Attack;
		QLCDNumber* Parade;
		QLCDNumber* Weight;

		MeleeWeaponItems();
	};
	struct RangedWeaponItems {
		MyComboBox* Weapon;
		MyComboBox* BattleTechnique;
		MySpinBox* ReloadTime;
		QLCDNumber* Munition;
		QLineEdit* Range;
		MySpinBox* Attack;
		QLCDNumber* Weight;

		RangedWeaponItems();
	};
	//	struct Armortable {
	//		MyComboBox* Armortable;
	//	};
	//	struct SchildOrParryTable {
	//		MyComboBox* SchildOrParry;
	//	};
	struct InventoryItems {
		QLineEdit* Item;
		QCheckBox* IsCarryPlace;
		MySpinBox* Ammount;
		MyDoubleSpinBox* Value;
		MyDoubleSpinBox* Weight;
		MyComboBox* CarryPlace;
		QVBoxLayout* Layout_IsCarryPlace;
		QWidget* Widget_IsCarryPlace;

		InventoryItems();
	};
	struct InventoryWAC {
		QLineEdit* Item;
		MyComboBox* ItemType;
		MyDoubleSpinBox* Value;
		MyDoubleSpinBox* Weight;
		MyComboBox* CarryPlace;

		InventoryWAC();
	};
	Table m_Table;
	LayoutAndFrame m_LayoutAndFrame;
	std::vector<MeleeWeaponItems> m_MeleeWeaponItems;
	std::vector<RangedWeaponItems> m_RangedWeaponItems;
	std::vector<InventoryItems> m_InventoryItems;
	std::vector<InventoryWAC> m_InventoryWAC;

	void initTableWidget();
	void initMeleeWeaponItems();
	void initRangedWeaponItems();
	void initInventoryItems();
	void initInventoryWAC();
	void initLayout();
	void InitFrame();
	void initGUI();

	void setLCDNumber(QLCDNumber* lcdNumber);
	void setLineEdit(QLineEdit* lineEdit, QString placeholderText);
	void setComboBox(QComboBox* comboBox, QStringList items);
	void setSpinBox(QSpinBox* spinBox, QString suffix, int minRange, int maxRang);
	void setDoubleSpinBox(QDoubleSpinBox* doubleSpinBox, QString suffix);
	void setTableWiget(QTableWidget* tableWidget, int rows, int collumns, int height, std::vector<int> widthColumns, QStringList labels);

	void addItemsToMeleeWaponTable(QTableWidget* tableWidget, std::vector<MeleeWeaponItems>* items);
	void addItemsToRangedWaponTable(QTableWidget* tableWidget, std::vector<RangedWeaponItems>* items);
	void addItemsToInventoryItemTable(QTableWidget* tableWidget, std::vector<InventoryItems>* items);
	void addItemsToInventoryWACTable(QTableWidget* tableWidget, std::vector<InventoryWAC>* items);

public:
	InventoryGUI();

	QStringList getMeleeWeaponsInventory();
	QStringList getRangedWeaponsInventory();
	QStringList getCarryPlacesItem();
	QStringList getCarryPlacesWAC();

	QTableWidget* getTableEquipmentMelee();
	QTableWidget* getTableEquipmentRanged();
	QTableWidget* getTableInventoryItems();
	QTableWidget* getTableInventoryWAC();
};

#endif // INVENTORY_HPP
