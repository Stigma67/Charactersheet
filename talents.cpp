#include "talents.hpp"
#include <QDebug>

Talents::Talents()
: m_Layout_Talents(new QVBoxLayout)
, m_Layout_TopRow(new QHBoxLayout)
, m_Layout_BottomRow(new QHBoxLayout)
, m_Frame_TopRow(new QFrame)
, m_Frame_BottomRow(new QFrame)
, m_Frame_Talents(new QFrame)
{
	initGUI();
}

//	>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>GUI>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
Talents::TalentGroupGUI::TalentGroupGUI(QString talentGroupName)
: TalentGroupName(talentGroupName)
, TableWidget(new QTableWidget)
{}
Talents::TalentGUI::TalentGUI(QString talentName, QString propertieOne, QString propertieTwo, QString propertieThree)
: NameTalent(talentName)
, NamePropertyOne(propertieOne)
, NamePropertyTwo(propertieTwo)
, NamePropertyThree(propertieThree)
, TableWidgetItemTalent(new QTableWidgetItem)
, TableWidgetItemPropertyOne(new QTableWidgetItem)
, TableWidgetItemPropertyTwo(new QTableWidgetItem)
, TableWidgetItemPropertyThree(new QTableWidgetItem)
, LCDNumberPropertyOne(new QLCDNumber)
, LCDNumberPropertyTwo(new QLCDNumber)
, LCDNumberPropertyThree(new QLCDNumber)
, SpinBox(new QSpinBox)
, TableWidget(new QTableWidget)
{}

void Talents::initTalentGroup()
{
	m_TalentGUI.insert(std::make_pair(GESELLSCHAFTSTALENTE, TalentGroupGUI("Gesellschaftstalente")));
	m_TalentGUI.insert(std::make_pair(HANDWERKSTALENTE, TalentGroupGUI("Handwerkstalente")));
	m_TalentGUI.insert(std::make_pair(KOERPERTALENTE, TalentGroupGUI("Körpertalente")));
	m_TalentGUI.insert(std::make_pair(KRIEGSKUNSTTALENTE, TalentGroupGUI("Kriegskunsttalente")));
	m_TalentGUI.insert(std::make_pair(NATURTALENTE, TalentGroupGUI("Naturtalente")));
	m_TalentGUI.insert(std::make_pair(WISSENSTALENTE, TalentGroupGUI("Wissenstalente")));

	setTalentData(GESELLSCHAFTSTALENTE);
	setTalentData(HANDWERKSTALENTE);
	setTalentData(KOERPERTALENTE);
	setTalentData(KRIEGSKUNSTTALENTE);
	setTalentData(NATURTALENTE);
	setTalentData(WISSENSTALENTE);
}
void Talents::initTableWidgetItem()
{
	for(auto& varOne : m_TalentGUI)
	{
		for(TalentGUI& talentData : varOne.second.Data)
		{
			talentData.TableWidgetItemTalent->setText(talentData.NameTalent);
			talentData.TableWidgetItemPropertyOne->setText(talentData.NamePropertyOne);
			talentData.TableWidgetItemPropertyTwo->setText(talentData.NamePropertyTwo);
			talentData.TableWidgetItemPropertyThree->setText(talentData.NamePropertyThree);

			talentData.TableWidgetItemTalent->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
			talentData.TableWidgetItemPropertyOne->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
			talentData.TableWidgetItemPropertyTwo->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
			talentData.TableWidgetItemPropertyThree->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
		}
	}
}
void Talents::initSpinbox()
{
	for(auto varOne : m_TalentGUI) {
		for(TalentGUI& talentData : varOne.second.Data) {
			talentData.SpinBox->setRange(0, 99);
			talentData.SpinBox->setFocusPolicy(Qt::StrongFocus);
			talentData.SpinBox->setFont(QFont("Times New Roman", 16, QFont::Bold));
		}
	}
}
void Talents::initTableTalentData()
{
	for(auto& varOne : m_TalentGUI)
	{
		for (TalentGUI& talentData : varOne.second.Data) {
			setTableTalentData(talentData.TableWidget, 5, 2);

			addLabelToTalentDataTable(talentData.TableWidget, {talentData.TableWidgetItemTalent, talentData.TableWidgetItemPropertyOne,
			talentData.TableWidgetItemPropertyTwo, talentData.TableWidgetItemPropertyThree});

			addLCDNumberToTalentDataTable(talentData.TableWidget, {talentData.LCDNumberPropertyOne,
			talentData.LCDNumberPropertyTwo, talentData.LCDNumberPropertyThree});

			addSpinBoxToTalentDataTable(talentData.TableWidget, talentData.SpinBox);
			mergeTalentDataTableCells(talentData.TableWidget);
		}
	}
}
void Talents::initTableTalentGroup()
{
	int row = 0;

	for (auto varOne : m_TalentGUI) {
		setTableTalentGroup(varOne.second.TableWidget, {varOne.second.TalentGroupName}, varOne.second.Data.size());
		for (TalentGUI& talentData : varOne.second.Data) {
			addTalentDataToTalentGroupTable(varOne.second.TableWidget, talentData.TableWidget, row);
			++row;
		}
		row = 0;
	}
}
void Talents::initGUI()
{
	initTalentGroup();
	initTableWidgetItem();
	initSpinbox();
	initTableTalentData();
	initTableTalentGroup();


	m_Layout_TopRow->addWidget(m_TalentGUI.at(HANDWERKSTALENTE).TableWidget);
	m_Layout_TopRow->addWidget(m_TalentGUI.at(KOERPERTALENTE).TableWidget);
	m_Layout_TopRow->addWidget(m_TalentGUI.at(WISSENSTALENTE).TableWidget);
	m_Layout_BottomRow->addWidget(m_TalentGUI.at(GESELLSCHAFTSTALENTE).TableWidget);
	m_Layout_BottomRow->addWidget(m_TalentGUI.at(KRIEGSKUNSTTALENTE).TableWidget);
	m_Layout_BottomRow->addWidget(m_TalentGUI.at(NATURTALENTE).TableWidget);
	m_Layout_Talents->addWidget(m_Frame_TopRow);
	m_Layout_Talents->addWidget(m_Frame_BottomRow);

	m_Frame_TopRow->setLayout(m_Layout_TopRow);
	m_Frame_BottomRow->setLayout(m_Layout_BottomRow);
	m_Frame_Talents->setLayout(m_Layout_Talents);
}

void Talents::setTalentData(TalentGroupNames talentGroupName)
{
	switch (talentGroupName)
	{
		case GESELLSCHAFTSTALENTE:
		{
			m_TalentGUI.at(talentGroupName).Data.push_back(TalentGUI("Betören", "MU", "CH", "SE"));
			m_TalentGUI.at(talentGroupName).Data.push_back(TalentGUI("Diplomatie", "CH", "KL", "SE"));
			m_TalentGUI.at(talentGroupName).Data.push_back(TalentGUI("Einschüchtern", "MU", "IN", "KK"));
			m_TalentGUI.at(talentGroupName).Data.push_back(TalentGUI("Etikette", "KL", "IN", "CH"));
			m_TalentGUI.at(talentGroupName).Data.push_back(TalentGUI("Gassenwissen", "KL", "IN", "CH"));
			m_TalentGUI.at(talentGroupName).Data.push_back(TalentGUI("Handeln", "CH", "KL", "IN"));
			m_TalentGUI.at(talentGroupName).Data.push_back(TalentGUI("Menschenkenntnis", "KL", "IN", "IN"));
			m_TalentGUI.at(talentGroupName).Data.push_back(TalentGUI("Singen", "CH", "KL", "KO"));
			m_TalentGUI.at(talentGroupName).Data.push_back(TalentGUI("Überreden", "CH", "KL", "IN"));
			break;
		}
		case HANDWERKSTALENTE:
		{
			m_TalentGUI.at(talentGroupName).Data.push_back(TalentGUI("Heilkunde Handwerk", "KL", "GE", "MU"));
			m_TalentGUI.at(talentGroupName).Data.push_back(TalentGUI("Holzbearbeitung", "GE", "KK", "GE"));
			m_TalentGUI.at(talentGroupName).Data.push_back(TalentGUI("Kochen", "IN", "GE", "KL"));
			m_TalentGUI.at(talentGroupName).Data.push_back(TalentGUI("Lederbearbeitung", "GE", "IN", "GE"));
			m_TalentGUI.at(talentGroupName).Data.push_back(TalentGUI("Malen & Zeichnen", "IN", "GE", "KL"));
			m_TalentGUI.at(talentGroupName).Data.push_back(TalentGUI("Mechanik", "KL", "GE", "IN"));
			m_TalentGUI.at(talentGroupName).Data.push_back(TalentGUI("Metallbearbeitung", "GE", "KO", "KK"));
			m_TalentGUI.at(talentGroupName).Data.push_back(TalentGUI("Musizieren", "CH", "GE", "KL"));
			m_TalentGUI.at(talentGroupName).Data.push_back(TalentGUI("Steinbearbeitung", "GE", "GE", "KK"));
			m_TalentGUI.at(talentGroupName).Data.push_back(TalentGUI("Stoffbearbeitung", "GE", "IN", "KL"));
			break;
		}
		case KOERPERTALENTE:
		{
			m_TalentGUI.at(talentGroupName).Data.push_back(TalentGUI("Fesseln", "KL", "GE", "KK"));
			m_TalentGUI.at(talentGroupName).Data.push_back(TalentGUI("Fliegen", "MU", "IN", "GE"));
			m_TalentGUI.at(talentGroupName).Data.push_back(TalentGUI("Gaukeleien", "GE", "CH", "KO"));
			m_TalentGUI.at(talentGroupName).Data.push_back(TalentGUI("Klettern", "KK", "KO", "MU"));
			m_TalentGUI.at(talentGroupName).Data.push_back(TalentGUI("Körperbeherrschung", "GE", "KO", "KK"));
			m_TalentGUI.at(talentGroupName).Data.push_back(TalentGUI("Kraftakt", "KK", "KO", "KK"));
			m_TalentGUI.at(talentGroupName).Data.push_back(TalentGUI("Reiten", "GE", "KO", "IN"));
			m_TalentGUI.at(talentGroupName).Data.push_back(TalentGUI("Schwimmen", "KO", "MU", "GE"));
			m_TalentGUI.at(talentGroupName).Data.push_back(TalentGUI("Taschendiebstahl", "MU", "GE", "IN"));
			m_TalentGUI.at(talentGroupName).Data.push_back(TalentGUI("Zechen", "SE", "KO", "KL"));
			break;
		}
		case KRIEGSKUNSTTALENTE:
		{
			m_TalentGUI.at(talentGroupName).Data.push_back(TalentGUI("Ausbildung", "KL", "CH", "SE"));
			m_TalentGUI.at(talentGroupName).Data.push_back(TalentGUI("Belagern", "KL", "IN", "MU"));
			m_TalentGUI.at(talentGroupName).Data.push_back(TalentGUI("Fernkämpfer führen", "MU", "IN", "CH"));
			m_TalentGUI.at(talentGroupName).Data.push_back(TalentGUI("GeoStrategien", "KL", "IN", "MU"));
			m_TalentGUI.at(talentGroupName).Data.push_back(TalentGUI("Infanterie führen", "MU", "IN", "CH"));
			m_TalentGUI.at(talentGroupName).Data.push_back(TalentGUI("Kavalerie führen", "MU", "IN", "CH"));
			m_TalentGUI.at(talentGroupName).Data.push_back(TalentGUI("Logistik", "KL", "IN", "KL"));
			m_TalentGUI.at(talentGroupName).Data.push_back(TalentGUI("Waffenkunde", "KL", "KL", "IN"));
			break;
		}
		case NATURTALENTE:
		{
			m_TalentGUI.at(talentGroupName).Data.push_back(TalentGUI("Fährtensuche", "IN", "KL", "SE"));
			m_TalentGUI.at(talentGroupName).Data.push_back(TalentGUI("Fallenstellen", "GE", "IN", "KK"));
			m_TalentGUI.at(talentGroupName).Data.push_back(TalentGUI("Fischen", "SE", "GE", "KL"));
			m_TalentGUI.at(talentGroupName).Data.push_back(TalentGUI("Jagdstrategien", "KL", "IN", "MU"));
			m_TalentGUI.at(talentGroupName).Data.push_back(TalentGUI("Orientiereung", "IN", "KL", "IN"));
			m_TalentGUI.at(talentGroupName).Data.push_back(TalentGUI("Verstohlenheit", "KL", "IN", "GE"));
			m_TalentGUI.at(talentGroupName).Data.push_back(TalentGUI("Wildnisleben", "IN", "KL", "MU"));
			break;
		}
		case WISSENSTALENTE:
		{
			m_TalentGUI.at(talentGroupName).Data.push_back(TalentGUI("Dynastiekunde", "KL", "KL", "IN"));
			m_TalentGUI.at(talentGroupName).Data.push_back(TalentGUI("Flora & Fauna", "KL", "KL", "IN"));
			m_TalentGUI.at(talentGroupName).Data.push_back(TalentGUI("Geographie", "KL", "KL", "IN"));
			m_TalentGUI.at(talentGroupName).Data.push_back(TalentGUI("Geschichtswissen", "KL", "KL", "IN"));
			m_TalentGUI.at(talentGroupName).Data.push_back(TalentGUI("Götter & Kulte", "KL", "KL", "IN"));
			m_TalentGUI.at(talentGroupName).Data.push_back(TalentGUI("Heilkundewissen", "KL", "KL", "IN"));
			m_TalentGUI.at(talentGroupName).Data.push_back(TalentGUI("Legenden", "KL", "KL", "IN"));
			m_TalentGUI.at(talentGroupName).Data.push_back(TalentGUI("Magiekunde", "KL", "KL", "IN"));
			m_TalentGUI.at(talentGroupName).Data.push_back(TalentGUI("Rechtskunde", "KL", "KL", "IN"));
			m_TalentGUI.at(talentGroupName).Data.push_back(TalentGUI("Sternenkunde", "KL", "KL", "IN"));
			break;
		}
		default:
		{
			break;
		}
	}
}
void Talents::setTableTalentData(QTableWidget* obj, int columns, int rows)
{
	obj->verticalHeader()->setVisible(false);
	obj->horizontalHeader()->setVisible(false);
	obj->setColumnCount(columns);
	obj->setRowCount(rows);

	for (int var = 0; var < columns; ++var)
	{
		if(var == 0) {
			obj->setColumnWidth(var, 160);
		}
		else if((columns - var) == 1) {
			obj->setColumnWidth(var, 50);
		}
		else {
			obj->setColumnWidth(var, 40);
		}
	}

	for (int var = 0; var < rows; ++var) {
		obj->setRowHeight(var, 25);
	}

	obj->setSelectionMode(QTableWidget::NoSelection);
	obj->setFocusPolicy(Qt::NoFocus);
}
void Talents::setTableTalentGroup(QTableWidget* obj, QStringList header, int rows)
{
	obj->verticalHeader()->setVisible(false);
	obj->setColumnCount(1);
	obj->setRowCount(rows);
	obj->setHorizontalHeaderLabels(header);
	obj->horizontalHeader()->setFont(QFont("Times New Roman", 14, QFont::Bold));
	obj->setColumnWidth(0, 350);

	for (int var = 0; var < obj->rowCount(); ++var) {
		obj->setRowHeight(var, 54);
	}

	obj->setFixedSize(345, 350);
	obj->setFont(QFont("Times New Roman", 12, QFont::Bold));

}
void Talents::setPropertyValues(int ch, int ge, int in, int kk, int kl, int ko, int mu, int se)
{
	for (auto var : m_TalentGUI) {
		for (TalentGUI talentData : var.second.Data) {
			checkPropertyType(talentData.TableWidgetItemPropertyOne, talentData.LCDNumberPropertyOne, {ch, ge, in, kk, kl, ko, mu, se});
			checkPropertyType(talentData.TableWidgetItemPropertyTwo, talentData.LCDNumberPropertyTwo, {ch, ge, in, kk, kl, ko, mu, se});
			checkPropertyType(talentData.TableWidgetItemPropertyThree, talentData.LCDNumberPropertyThree, {ch, ge, in, kk, kl, ko, mu, se});
		}
	}
}

void Talents::checkPropertyType(QTableWidgetItem* property, QLCDNumber* display, std::vector<int> values)
{
	if(property->text() == "CH") {
		display->setDigitCount(values.at(0));
	}
	else if(property->text() == "GE") {
		display->setDigitCount(values.at(1));
	}
	else if(property->text() == "IN") {
		display->setDigitCount(values.at(2));
	}
	else if(property->text() == "KK") {
		display->setDigitCount(values.at(3));
	}
	else if(property->text() == "KL") {
		display->setDigitCount(values.at(4));
	}
	else if(property->text() == "KO") {
		display->setDigitCount(values.at(5));
	}
	else if(property->text() == "MU") {
		display->setDigitCount(values.at(6));
	}
	else if(property->text() == "SE") {
		display->setDigitCount(values.at(7));
	}
}
void Talents::addLabelToTalentDataTable(QTableWidget* obj, std::vector<QTableWidgetItem*> label)
{
	if(obj->columnCount()-1 == (int)label.size()) {
		for (int var = 0; var < obj->columnCount()-1; ++var) {
			obj->setItem(0, var, label.at(var));
		}
	}
}
void Talents::addLCDNumberToTalentDataTable(QTableWidget* obj, std::vector<QLCDNumber*> lcdNumber)
{
	if(obj->columnCount()-2 == (int)lcdNumber.size()) {
		for (int var = 0; var < (int)lcdNumber.size(); ++var) {
			lcdNumber.at(var)->setDigitCount(2);
			lcdNumber.at(var)->setSegmentStyle(QLCDNumber::Flat);
			obj->setCellWidget(1, var+1, lcdNumber.at(var));
		}
	}
}
void Talents::addSpinBoxToTalentDataTable(QTableWidget* obj, QSpinBox* spinBox)
{
	obj->setCellWidget(0, obj->columnCount()-1, spinBox);
}
void Talents::addTalentDataToTalentGroupTable(QTableWidget* obj, QTableWidget* talentData, int row)
{
	if(row <= obj->rowCount()) {
		obj->setCellWidget(row, 0, talentData);
	}
}
void Talents::mergeTalentDataTableCells(QTableWidget *obj)
{
	obj->setSpan(0, 0, 2, 1);
	obj->setSpan(0, obj->columnCount()-1, 2, 1);
}

QFrame* Talents::getFrame() const
{
	return m_Frame_Talents;
}
//	<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<GUI<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
