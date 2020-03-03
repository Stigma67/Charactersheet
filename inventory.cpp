#include "inventory.hpp"
#include <QDebug>

InventoryGUI::InventoryGUI()
: m_Table(Table())
, m_LayoutAndFrame(LayoutAndFrame())
{
	initGUI();
}

InventoryGUI::Table::Table()
: MeleeWeapons(new QTableWidget)
, RangedWeapons(new QTableWidget)
, Armor(new QTableWidget)
, SchildOrParade(new QTableWidget)
, InventoryItems(new QTableWidget)
, InventoryWAC(new QTableWidget)
{}
InventoryGUI::LayoutAndFrame::LayoutAndFrame()
: vBox_Equipment(new QVBoxLayout)
, hBox_Inventory(new QHBoxLayout)
, Frame_Equipment(new QFrame)
, Frame_Inventory(new QFrame)
{}
InventoryGUI::MeleeWeaponItems::MeleeWeaponItems()
: Weapon(new MyComboBox)
, BattleTechnique(new MyComboBox)
, Damage(new QLineEdit)
, AtatckModification(new MySpinBox)
, ParadeModification(new MySpinBox)
, Attack(new MySpinBox)
, Parade(new MySpinBox)
, Weight(new QLCDNumber)
{}
InventoryGUI::RangedWeaponItems::RangedWeaponItems()
: Weapon(new MyComboBox)
, BattleTechnique(new MyComboBox)
, ReloadTime(new MySpinBox)
, Munition(new QLCDNumber)
, Range(new QLineEdit)
, Attack(new MySpinBox)
, Weight(new QLCDNumber)
{}
InventoryGUI::InventoryItems::InventoryItems()
: Item(new QLineEdit)
, Ammount(new MySpinBox)
, Value(new MyDoubleSpinBox)
, Weight(new MyDoubleSpinBox)
, CarryPlace(new MyComboBox)
{}
InventoryGUI::InventoryWAC::InventoryWAC()
: Item(new QLineEdit)
, ItemType(new MyComboBox)
, Value(new MyDoubleSpinBox)
, Weight(new MyDoubleSpinBox)
, CarryPlace(new MyComboBox)
{}

void InventoryGUI::initTableWidget() {
	setTableWiget(m_Table.MeleeWeapons, 10, 8, 25, {200, 200, 210, 90, 90, 80, 80, 131},
	{"Nahkampfwaffe", "Kampftechnik", "Schaden", "AT Mod.", "PA Mod.", "AT", "PA", "Gewicht (Stein)"});
	setTableWiget(m_Table.RangedWeapons, 10, 7, 25, {200, 200, 150, 100, 220, 80, 131},
	{"Fernkampfwaffe", "Kampftechnik", "Nachladezeit", "Munition", "Reichweite", "AT", "Gewicht (Stein)"});
	setTableWiget(m_Table.InventoryItems, 16, 5, 25, {400, 220, 120, 120, 221},
	{"Gegenstand", "Anzahl", "Wert", "Gewicht", "Tragplatz"});
	setTableWiget(m_Table.InventoryWAC, 16, 5, 25, {400, 220, 120, 120, 221},
	{"Gegenstand", "Typ", "Wert", "Gewicht", "Tragplatz"});
}
void InventoryGUI::initMeleeWeaponItems() {
	for (int items = 0; items < m_Table.MeleeWeapons->rowCount(); ++items) {
		m_MeleeWeaponItems.push_back(MeleeWeaponItems());
		setComboBox(m_MeleeWeaponItems.at(items).Weapon, /*getMeleeWeaponsInventory()*/{"TODO"});
		setComboBox(m_MeleeWeaponItems.at(items).BattleTechnique, {"Nahkampfart", "Dolch", "Hiebwaffe", "Kettenwaffe", "Lanze", "Peitsche", "Raufen", "Schild", "Schwert"});
		setLineEdit(m_MeleeWeaponItems.at(items).Damage, "[Anzahl][Würfel]+...+[Zahl]");
		setSpinBox(m_MeleeWeaponItems.at(items).AtatckModification, "", -99, 99);
		setSpinBox(m_MeleeWeaponItems.at(items).ParadeModification, "", -99, 99);
		setSpinBox(m_MeleeWeaponItems.at(items).Attack, "", -99, 99);
		setSpinBox(m_MeleeWeaponItems.at(items).Parade, "", -99, 99);
		setLCDNumber(m_MeleeWeaponItems.at(items).Weight);
	}

	addItemsToMeleeWaponTable(m_Table.MeleeWeapons, &m_MeleeWeaponItems);
}
void InventoryGUI::initRangedWeaponItems() {
	for (int items = 0; items < m_Table.RangedWeapons->rowCount(); ++items) {
		m_RangedWeaponItems.push_back(RangedWeaponItems());
		setComboBox(m_RangedWeaponItems.at(items).Weapon, /*getRangedWeaponsInventory()*/{"TODO"});
		setComboBox(m_RangedWeaponItems.at(items).BattleTechnique, {"Fernkampfart", "Armbruest", "Boegen", "Schleuder", "Wurfwaffe"});
		setSpinBox(m_RangedWeaponItems.at(items).ReloadTime, " Züge.", 0, 10);
		setLCDNumber(m_RangedWeaponItems.at(items).Munition);
		setLineEdit(m_RangedWeaponItems.at(items).Range, "Reichweite nah / mittel / fern");
		setSpinBox(m_RangedWeaponItems.at(items).Attack, "", -99, 99);
		setLCDNumber(m_RangedWeaponItems.at(items).Weight);
	}

	addItemsToRangedWaponTable(m_Table.RangedWeapons, &m_RangedWeaponItems);
}
void InventoryGUI::initInventoryItems() {
	for (int items = 0; items < m_Table.InventoryItems->rowCount(); ++items) {
		m_InventoryItems.push_back(InventoryItems());
		setLineEdit(m_InventoryItems.at(items).Item, "Gegenstand");
		setSpinBox(m_InventoryItems.at(items).Ammount, " Stück", 0, 999);
		setDoubleSpinBox(m_InventoryItems.at(items).Value, " Silber");
		setDoubleSpinBox(m_InventoryItems.at(items).Weight, " Stein");
		setComboBox(m_InventoryItems.at(items).CarryPlace, /*getCarryPlacesItem()*/{"TODO"});
	}

	addItemsToInventoryItemTable(m_Table.InventoryItems, &m_InventoryItems);
}
void InventoryGUI::initInventoryWAC() {
	for (int items = 0; items < m_Table.InventoryWAC->rowCount(); ++items) {
		m_InventoryWAC.push_back(InventoryWAC());
		setLineEdit(m_InventoryWAC.at(items).Item, "Waffe / Kleidung / Rüstung");
		setComboBox(m_InventoryWAC.at(items).ItemType, {"Gegenstandstyp" , "Nahkampfwaffe", "Fernkampfwaffe", "Munition",
		"Handschuhe (Kleidung)", "Handschuhe (Rüstung)", "Hose (Kleidung)", "Hose (Rüstung)", "Kopfbedeckung (Kleidung)",
		"Kopfbedeckung (Rüstung)", "Oberteil (Kleidung)", "Oberteil (Rüstung)", "Schuhe (Kleidung)", "Schuhe (Rüstung)"});
		setDoubleSpinBox(m_InventoryWAC.at(items).Value, " Silber");
		setDoubleSpinBox(m_InventoryWAC.at(items).Weight, " Stein");
		setComboBox(m_InventoryWAC.at(items).CarryPlace, /*getCarryPlacesWAC()*/{"TODO"});
	}

	addItemsToInventoryWACTable(m_Table.InventoryWAC, &m_InventoryWAC);
}
void InventoryGUI::initLayout() {
	m_LayoutAndFrame.vBox_Equipment->addWidget(m_Table.MeleeWeapons);
	m_LayoutAndFrame.vBox_Equipment->addWidget(m_Table.RangedWeapons);
	m_LayoutAndFrame.hBox_Inventory->addWidget(m_Table.InventoryItems);
	m_LayoutAndFrame.hBox_Inventory->addWidget(m_Table.InventoryWAC);
}
void InventoryGUI::InitFrame() {
	m_LayoutAndFrame.Frame_Equipment->setLayout(m_LayoutAndFrame.vBox_Equipment);
	m_LayoutAndFrame.Frame_Inventory->setLayout(m_LayoutAndFrame.hBox_Inventory);
}
void InventoryGUI::initGUI() {
	initTableWidget();
	initMeleeWeaponItems();
	initRangedWeaponItems();
	initInventoryItems();
	initInventoryWAC();
	initLayout();
	InitFrame();
}

void InventoryGUI::setLCDNumber(QLCDNumber* lcdNumber) {
	lcdNumber->setSegmentStyle(QLCDNumber::Flat);
}
void InventoryGUI::setLineEdit(QLineEdit* lineEdit, QString placeholderText) {
	lineEdit->setFont(QFont("Times New Roman", 12, QFont::Bold));
	lineEdit->setPlaceholderText(placeholderText);

}
void InventoryGUI::setComboBox(QComboBox* comboBox, QStringList items) {
	comboBox->addItems(items);
	comboBox->setFont(QFont("Times New Roman", 12, QFont::Bold));
}
void InventoryGUI::setSpinBox(QSpinBox* spinBox, QString suffix, int minRange, int maxRang) {
	spinBox->setRange(minRange, maxRang);
	spinBox->setSuffix(suffix);
	spinBox->setSingleStep(1);
	spinBox->setFont(QFont("Times New Roman", 12, QFont::Bold));
}
void InventoryGUI::setDoubleSpinBox(QDoubleSpinBox* doubleSpinBox, QString suffix) {
	doubleSpinBox->setRange(0, 10000);
	doubleSpinBox->setSuffix(suffix);
	doubleSpinBox->setSingleStep(0.01);
	doubleSpinBox->setFont(QFont("Times New Roman", 12, QFont::Bold));
}
void InventoryGUI::setTableWiget(QTableWidget* tableWidget, int rows, int columns, int height, std::vector<int> widthColumns, QStringList labels) {
	tableWidget->setRowCount(rows);
	tableWidget->setColumnCount(columns);
	tableWidget->setHorizontalHeaderLabels(labels);
	tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
	tableWidget->horizontalHeader()->setFont(QFont("Times New Roman", 14, QFont::Bold));
	tableWidget->verticalHeader()->setVisible(false);

	for (int var = 0; var < rows; ++var) {
		tableWidget->setRowHeight(var, height);
	}
	int totalWidth = 0;
	for (int var = 0; var < columns; ++var) {
		tableWidget->setColumnWidth(var, widthColumns.at(var));
		totalWidth += widthColumns.at(var);
	}

	tableWidget->setFixedSize(totalWidth+2, ((rows+1)*height)+2);
}

void InventoryGUI::addItemsToMeleeWaponTable(QTableWidget *tableWidget, std::vector<MeleeWeaponItems>* items) {
	int rows = 0;
	for (auto& item : *items) {
		tableWidget->setCellWidget(rows, 0, item.Weapon);
		tableWidget->setCellWidget(rows, 1, item.BattleTechnique);
		tableWidget->setCellWidget(rows, 2, item.Damage);
		tableWidget->setCellWidget(rows, 3, item.AtatckModification);
		tableWidget->setCellWidget(rows, 4, item.ParadeModification);
		tableWidget->setCellWidget(rows, 5, item.Attack);
		tableWidget->setCellWidget(rows, 6, item.Parade);
		tableWidget->setCellWidget(rows, 7, item.Weight);

		++rows;
	}
}
void InventoryGUI::addItemsToRangedWaponTable(QTableWidget *tableWidget, std::vector<RangedWeaponItems>* items) {
	int rows = 0;
	for (auto& item : *items) {
		tableWidget->setCellWidget(rows, 0, item.Weapon);
		tableWidget->setCellWidget(rows, 1, item.BattleTechnique);
		tableWidget->setCellWidget(rows, 2, item.ReloadTime);
		tableWidget->setCellWidget(rows, 3, item.Munition);
		tableWidget->setCellWidget(rows, 4, item.Range);
		tableWidget->setCellWidget(rows, 5, item.Attack);
		tableWidget->setCellWidget(rows, 6, item.Weight);

		++rows;
	}

	qDebug() << rows;
}
void InventoryGUI::addItemsToInventoryItemTable(QTableWidget *tableWidget, std::vector<InventoryItems>* items) {
	int rows = 0;
	for (auto& item : *items) {
		tableWidget->setCellWidget(rows, 0, item.Item);
		tableWidget->setCellWidget(rows, 1, item.Ammount);
		tableWidget->setCellWidget(rows, 2, item.Value);
		tableWidget->setCellWidget(rows, 3, item.Weight);
		tableWidget->setCellWidget(rows, 4, item.CarryPlace);

		++rows;
	}
}
void InventoryGUI::addItemsToInventoryWACTable(QTableWidget *tableWidget, std::vector<InventoryWAC>* items) {
	int rows = 0;
	for (auto& item : *items) {
		tableWidget->setCellWidget(rows, 0, item.Item);
		tableWidget->setCellWidget(rows, 1, item.ItemType);
		tableWidget->setCellWidget(rows, 2, item.Value);
		tableWidget->setCellWidget(rows, 3, item.Weight);
		tableWidget->setCellWidget(rows, 4, item.CarryPlace);

		++rows;
	}
}

//QStringList InventoryGUI::getMeleeWeaponsInventory() {

//}
//QStringList InventoryGUI::getRangedWeaponsInventory() {

//}
//QStringList InventoryGUI::getCarryPlacesItem() {

//}
//QStringList InventoryGUI::getCarryPlacesWAC() {

//}
QTableWidget* InventoryGUI::getTableEquipmentMelee() {
	return m_Table.MeleeWeapons;
}
QTableWidget* InventoryGUI::getTableEquipmentRanged() {
	return m_Table.RangedWeapons;
}
QTableWidget* InventoryGUI::getTableInventoryItems() {
	return m_Table.InventoryItems;
}
QTableWidget* InventoryGUI::getTableInventoryWAC() {
	return m_Table.InventoryWAC;
}
