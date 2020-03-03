#include "battleTechniques.hpp"
#include <QDebug>

BattleTechniquesGUI::BattleTechniquesGUI()
: m_Table_WeaponGUIMelee(new QTableWidget)
, m_Table_WeaponGUIRanged(new QTableWidget)
, m_Layout_WeaponGUI(new QHBoxLayout)
, m_Frame_WeaponGUI(new QFrame)
{
	initGUI();
}
BattleTechniquesGUI::Weapons::Weapons(QString weaponClass, std::string distance)
: SpinBoxAttack(new MySpinBox)
, SpinBoxParry(new MySpinBox)
, SpinBoxAP(new MySpinBox)
, LCDNumberValue(new QLCDNumber(2))
, LabelWeaponClass(new QLabel(weaponClass))
, Distance(distance)
{}

void BattleTechniquesGUI::initSpinBox() {
	for (auto& var : m_WeaponGUI) {
		setSpinBox(var.second.SpinBoxAttack);
		setSpinBox(var.second.SpinBoxParry);
		setSpinBox(var.second.SpinBoxAP);
	}
}
void BattleTechniquesGUI::initTableWidget() {
	int tempMelee = 0;
	int tempRanged = 0;

	m_Table_WeaponGUIMelee->setRowCount(8);
	m_Table_WeaponGUIMelee->setColumnCount(5);
	m_Table_WeaponGUIMelee->setHorizontalHeaderLabels({"Nahkampf", "Distanz", "KTW", "Attacke", "Parade", "AP"});
	m_Table_WeaponGUIMelee->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
	m_Table_WeaponGUIMelee->setColumnWidth(0, 128);
	m_Table_WeaponGUIMelee->setFont(QFont("Times New Roman", 12, QFont::Bold));
	m_Table_WeaponGUIMelee->verticalHeader()->setVisible(false);

	m_Table_WeaponGUIRanged->setRowCount(4);
	m_Table_WeaponGUIRanged->setColumnCount(5);
	m_Table_WeaponGUIRanged->setHorizontalHeaderLabels({"Fernkampf", "Distanz", "KTW", "Attacke", "Parade", "AP"});
	m_Table_WeaponGUIRanged->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
	m_Table_WeaponGUIRanged->setColumnWidth(0, 127);
	m_Table_WeaponGUIRanged->setFont(QFont("Times New Roman", 12, QFont::Bold));
	m_Table_WeaponGUIRanged->verticalHeader()->setVisible(false);

	for (auto& var : m_WeaponGUI) {
		if(var.second.Distance == "Melee") {
			addItemsToTable(m_Table_WeaponGUIMelee, {var.second.LabelWeaponClass, var.second.LCDNumberValue,
			var.second.SpinBoxAttack, var.second.SpinBoxParry, var.second.SpinBoxAP}, tempMelee);
			++tempMelee;
		} else {
			addItemsToTable(m_Table_WeaponGUIRanged, {var.second.LabelWeaponClass, var.second.LCDNumberValue,
			var.second.SpinBoxAttack, var.second.SpinBoxParry, var.second.SpinBoxAP}, tempRanged);
			++tempRanged;
		}
	}

	m_Table_WeaponGUIMelee->setSelectionMode(QTableWidget::NoSelection);
	m_Table_WeaponGUIMelee->setFocusPolicy(Qt::NoFocus);
}
void BattleTechniquesGUI::initGUI() {
	m_WeaponGUI.insert(std::make_pair(ARMBRUEST, Weapons("Armbrüste", "Ranged")));
	m_WeaponGUI.insert(std::make_pair(BOEGEN, Weapons("Bögen", "Ranged")));
	m_WeaponGUI.insert(std::make_pair(DOLCH, Weapons("Dolche", "Melee")));
	m_WeaponGUI.insert(std::make_pair(HIEBWAFFE, Weapons("Hiebwaffen", "Melee")));
	m_WeaponGUI.insert(std::make_pair(KETTENWAFFE, Weapons("Kettenwaffen", "Melee")));
	m_WeaponGUI.insert(std::make_pair(LANZE, Weapons("Lanzen", "Melee")));
	m_WeaponGUI.insert(std::make_pair(PEITSCHE, Weapons("Peitschen", "Melee")));
	m_WeaponGUI.insert(std::make_pair(RAUFEN, Weapons("Raufen", "Melee")));
	m_WeaponGUI.insert(std::make_pair(SCHILD, Weapons("Schilder", "Melee")));
	m_WeaponGUI.insert(std::make_pair(SCHLEUDER, Weapons("Schleudern", "Ranged")));
	m_WeaponGUI.insert(std::make_pair(SCHWERT, Weapons("Schwerter", "Melee")));
	m_WeaponGUI.insert(std::make_pair(WURFWAFFE, Weapons("Wurfwaffen", "Ranged")));

	for (auto& var : m_WeaponGUI) {
		setLabel(var.second.LabelWeaponClass);
	}
	initSpinBox();
	initTableWidget();

	m_Layout_WeaponGUI->addWidget(m_Table_WeaponGUIMelee);
	m_Layout_WeaponGUI->addWidget(m_Table_WeaponGUIRanged);
	m_Frame_WeaponGUI->setLayout(m_Layout_WeaponGUI);
}

void BattleTechniquesGUI::setLabel(QLabel* label) {
	label->setFont(QFont("Times New Roman", 12, QFont::Bold));
	label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
}
void BattleTechniquesGUI::setSpinBox(QSpinBox* spinBox) {
	spinBox->setRange(0, 99);
	spinBox->setFocusPolicy(Qt::StrongFocus);
	spinBox->setFont(QFont("Times New Roman", 12, QFont::Bold));
}
void BattleTechniquesGUI::addItemsToTable(QTableWidget *table, std::vector<QWidget*> items, int row) {
	for (int column = 0; column < (int)items.size(); ++column) {
		table->setCellWidget(row, column, items.at(column));
	}
}

QFrame* BattleTechniquesGUI::getFrame() {
	return m_Frame_WeaponGUI;
}
