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
Talents::TalentGroup::TalentGroup(QString talentGroupName)
: TalentGroupName(talentGroupName)
, TableWidget(new QTableWidget)
{}
Talents::TalentData::TalentData(QString talentName, QString propertieOne, QString propertieTwo, QString propertieThree)
: NameTalent(talentName)
, NamePropertyOne(propertieOne)
, NamePropertyTwo(propertieTwo)
, NamePropertyThree(propertieThree)
, Value(0)
, LabelTalent(new QLabel)
, LabelPropertyOne(new QLabel)
, LabelPropertyTwo(new QLabel)
, LabelPropertyThree(new QLabel)
, LCDNumberPropertyOne(new QLCDNumber)
, LCDNumberPropertyTwo(new QLCDNumber)
, LCDNumberPropertyThree(new QLCDNumber)
, SpinBox(new QSpinBox)
, TableWidget(new QTableWidget)
{}
void Talents::initTalentGroup()
{
	m_Talents.insert(std::make_pair(GESELLSCHAFTSTALENTE, TalentGroup("Gesellschaftstalente")));
	m_Talents.insert(std::make_pair(HANDWERKSTALENTE, TalentGroup("Handwerkstalente")));
	m_Talents.insert(std::make_pair(KOERPERTALENTE, TalentGroup("Körpertalente")));
	m_Talents.insert(std::make_pair(KRIEGSKUNSTTALENTE, TalentGroup("Kriegskunsttalente")));
	m_Talents.insert(std::make_pair(NATURTALENTE, TalentGroup("Naturtalente")));
	m_Talents.insert(std::make_pair(WISSENSTALENTE, TalentGroup("Wissenstalente")));

	setTalentData(GESELLSCHAFTSTALENTE);
	setTalentData(HANDWERKSTALENTE);
	setTalentData(KOERPERTALENTE);
	setTalentData(KRIEGSKUNSTTALENTE);
	setTalentData(NATURTALENTE);
	setTalentData(WISSENSTALENTE);
}

void Talents::initLabel()
{
	for(auto& varOne : m_Talents)
	{
		for(TalentData& talentData : varOne.second.Data)
		{
			talentData.LabelTalent->setText(talentData.NameTalent);
			talentData.LabelPropertyOne->setText(talentData.NamePropertyOne);
			talentData.LabelPropertyTwo->setText(talentData.NamePropertyTwo);
			talentData.LabelPropertyThree->setText(talentData.NamePropertyThree);

			talentData.LabelTalent->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
			talentData.LabelPropertyOne->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
			talentData.LabelPropertyTwo->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
			talentData.LabelPropertyThree->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
		}
	}
}
void Talents::initSpinbox()
{
	for(auto varOne : m_Talents)
	{
		for(TalentData& talentData : varOne.second.Data)
		{
			talentData.SpinBox->setRange(0, 99);
			talentData.SpinBox->setFont(QFont("Times New Roman", 16, QFont::Bold));
		}
	}
}
void Talents::initTableTalentData()
{
	for(auto& varOne : m_Talents)
	{
		for (TalentData& talentData : varOne.second.Data) {
			setTableTalentData(talentData.TableWidget, 5, 2);

			addLabelToTalentDataTable(talentData.TableWidget, {talentData.LabelTalent, talentData.LabelPropertyOne,
			talentData.LabelPropertyTwo, talentData.LabelPropertyThree});

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

	for (auto varOne : m_Talents) {
		setTableTalentGroup(varOne.second.TableWidget, {varOne.second.TalentGroupName}, varOne.second.Data.size());
		for (TalentData& talentData : varOne.second.Data) {
			addTalentDataToTalentGroupTable(varOne.second.TableWidget, talentData.TableWidget, row);
			++row;
		}
		row = 0;
	}
}
void Talents::initGUI()
{
	initTalentGroup();
	initLabel();
	initSpinbox();
	initTableTalentData();
	initTableTalentGroup();


	m_Layout_TopRow->addWidget(m_Talents.at(HANDWERKSTALENTE).TableWidget);
	m_Layout_TopRow->addWidget(m_Talents.at(KOERPERTALENTE).TableWidget);
	m_Layout_TopRow->addWidget(m_Talents.at(WISSENSTALENTE).TableWidget);
	m_Layout_BottomRow->addWidget(m_Talents.at(GESELLSCHAFTSTALENTE).TableWidget);
	m_Layout_BottomRow->addWidget(m_Talents.at(KRIEGSKUNSTTALENTE).TableWidget);
	m_Layout_BottomRow->addWidget(m_Talents.at(NATURTALENTE).TableWidget);
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
			m_Talents.at(talentGroupName).Data.push_back(TalentData("Betören", "MU", "CH", "SE"));
			m_Talents.at(talentGroupName).Data.push_back(TalentData("Diplomatie", "CH", "KL", "SE"));
			m_Talents.at(talentGroupName).Data.push_back(TalentData("Einschüchtern", "MU", "IN", "KK"));
			m_Talents.at(talentGroupName).Data.push_back(TalentData("Etikette", "KL", "IN", "CH"));
			m_Talents.at(talentGroupName).Data.push_back(TalentData("Gassenwissen", "KL", "IN", "CH"));
			m_Talents.at(talentGroupName).Data.push_back(TalentData("Handeln", "CH", "KL", "IN"));
			m_Talents.at(talentGroupName).Data.push_back(TalentData("Menschenkenntnis", "KL", "IN", "IN"));
			m_Talents.at(talentGroupName).Data.push_back(TalentData("Singen", "CH", "KL", "KO"));
			m_Talents.at(talentGroupName).Data.push_back(TalentData("Überreden", "CH", "KL", "IN"));
			break;
		}
		case HANDWERKSTALENTE:
		{
			m_Talents.at(talentGroupName).Data.push_back(TalentData("Heilkunde Handwerk", "KL", "GE", "MU"));
			m_Talents.at(talentGroupName).Data.push_back(TalentData("Holzbearbeitung", "GE", "KK", "GE"));
			m_Talents.at(talentGroupName).Data.push_back(TalentData("Kochen", "IN", "GE", "KL"));
			m_Talents.at(talentGroupName).Data.push_back(TalentData("Lederbearbeitung", "GE", "IN", "GE"));
			m_Talents.at(talentGroupName).Data.push_back(TalentData("Malen & Zeichnen", "IN", "GE", "KL"));
			m_Talents.at(talentGroupName).Data.push_back(TalentData("Mechanik", "KL", "GE", "IN"));
			m_Talents.at(talentGroupName).Data.push_back(TalentData("Metallbearbeitung", "GE", "KO", "KK"));
			m_Talents.at(talentGroupName).Data.push_back(TalentData("Musizieren", "CH", "GE", "KL"));
			m_Talents.at(talentGroupName).Data.push_back(TalentData("Steinbearbeitung", "GE", "GE", "KK"));
			m_Talents.at(talentGroupName).Data.push_back(TalentData("Stoffbearbeitung", "GE", "IN", "KL"));
			break;
		}
		case KOERPERTALENTE:
		{
			m_Talents.at(talentGroupName).Data.push_back(TalentData("Fesseln", "KL", "GE", "KK"));
			m_Talents.at(talentGroupName).Data.push_back(TalentData("Fliegen", "MU", "IN", "GE"));
			m_Talents.at(talentGroupName).Data.push_back(TalentData("Gaukeleien", "GE", "CH", "KO"));
			m_Talents.at(talentGroupName).Data.push_back(TalentData("Klettern", "KK", "KO", "MU"));
			m_Talents.at(talentGroupName).Data.push_back(TalentData("Körperbeherrschung", "GE", "KO", "KK"));
			m_Talents.at(talentGroupName).Data.push_back(TalentData("Kraftakt", "KK", "KO", "KK"));
			m_Talents.at(talentGroupName).Data.push_back(TalentData("Reiten", "GE", "KO", "IN"));
			m_Talents.at(talentGroupName).Data.push_back(TalentData("Schwimmen", "KO", "MU", "GE"));
			m_Talents.at(talentGroupName).Data.push_back(TalentData("Taschendiebstahl", "MU", "GE", "IN"));
			m_Talents.at(talentGroupName).Data.push_back(TalentData("Zechen", "SE", "KO", "KL"));
			break;
		}
		case KRIEGSKUNSTTALENTE:
		{
			m_Talents.at(talentGroupName).Data.push_back(TalentData("Ausbildung", "KL", "CH", "SE"));
			m_Talents.at(talentGroupName).Data.push_back(TalentData("Belagern", "KL", "IN", "MU"));
			m_Talents.at(talentGroupName).Data.push_back(TalentData("Fernkämpfer führen", "MU", "IN", "CH"));
			m_Talents.at(talentGroupName).Data.push_back(TalentData("GeoStrategien", "KL", "IN", "MU"));
			m_Talents.at(talentGroupName).Data.push_back(TalentData("Infanterie führen", "MU", "IN", "CH"));
			m_Talents.at(talentGroupName).Data.push_back(TalentData("Kavalerie führen", "MU", "IN", "CH"));
			m_Talents.at(talentGroupName).Data.push_back(TalentData("Logistik", "KL", "IN", "KL"));
			m_Talents.at(talentGroupName).Data.push_back(TalentData("Waffenkunde", "KL", "KL", "IN"));
			break;
		}
		case NATURTALENTE:
		{
			m_Talents.at(talentGroupName).Data.push_back(TalentData("Fährtensuche", "IN", "KL", "SE"));
			m_Talents.at(talentGroupName).Data.push_back(TalentData("Fallenstellen", "GE", "IN", "KK"));
			m_Talents.at(talentGroupName).Data.push_back(TalentData("Fischen", "SE", "GE", "KL"));
			m_Talents.at(talentGroupName).Data.push_back(TalentData("Jagdstrategien", "KL", "IN", "MU"));
			m_Talents.at(talentGroupName).Data.push_back(TalentData("Orientiereung", "IN", "KL", "IN"));
			m_Talents.at(talentGroupName).Data.push_back(TalentData("Verstohlenheit", "KL", "IN", "GE"));
			m_Talents.at(talentGroupName).Data.push_back(TalentData("Wildnisleben", "IN", "KL", "MU"));
			break;
		}
		case WISSENSTALENTE:
		{
			m_Talents.at(talentGroupName).Data.push_back(TalentData("Dynastiekunde", "KL", "KL", "IN"));
			m_Talents.at(talentGroupName).Data.push_back(TalentData("Flora & Fauna", "KL", "KL", "IN"));
			m_Talents.at(talentGroupName).Data.push_back(TalentData("Geographie", "KL", "KL", "IN"));
			m_Talents.at(talentGroupName).Data.push_back(TalentData("Geschichtswissen", "KL", "KL", "IN"));
			m_Talents.at(talentGroupName).Data.push_back(TalentData("Götter & Kulte", "KL", "KL", "IN"));
			m_Talents.at(talentGroupName).Data.push_back(TalentData("Heilkundewissen", "KL", "KL", "IN"));
			m_Talents.at(talentGroupName).Data.push_back(TalentData("Legenden", "KL", "KL", "IN"));
			m_Talents.at(talentGroupName).Data.push_back(TalentData("Magiekunde", "KL", "KL", "IN"));
			m_Talents.at(talentGroupName).Data.push_back(TalentData("Rechtskunde", "KL", "KL", "IN"));
			m_Talents.at(talentGroupName).Data.push_back(TalentData("Sternenkunde", "KL", "KL", "IN"));
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
	for (auto var : m_Talents) {
		for (TalentData talentData : var.second.Data) {
			checkPropertyType(talentData.LabelPropertyOne, talentData.LCDNumberPropertyOne, {ch, ge, in, kk, kl, ko, mu, se});
			checkPropertyType(talentData.LabelPropertyTwo, talentData.LCDNumberPropertyTwo, {ch, ge, in, kk, kl, ko, mu, se});
			checkPropertyType(talentData.LabelPropertyThree, talentData.LCDNumberPropertyThree, {ch, ge, in, kk, kl, ko, mu, se});
		}
	}
}

void Talents::checkPropertyType(QLabel* property, QLCDNumber* display, std::vector<int> values)
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
void Talents::addLabelToTalentDataTable(QTableWidget* obj, std::vector<QLabel*> label)
{
	if(obj->columnCount()-1 == (int)label.size()) {
		for (int var = 0; var < obj->columnCount()-1; ++var) {
			obj->setCellWidget(0, var, label.at(var));
		}
	}
}
void Talents::addLCDNumberToTalentDataTable(QTableWidget* obj, std::vector<QLCDNumber*> lcdNumber)
{
	if(obj->columnCount()-2 == (int)lcdNumber.size()) {
		for (int var = 0; var < (int)lcdNumber.size(); ++var) {
			lcdNumber.at(var)->setDigitCount(2);
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
