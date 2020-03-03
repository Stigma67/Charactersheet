#include "talents.hpp"
#include <QDebug>

TalentsGUI::TalentsGUI()
: m_Layout_Talents(new QVBoxLayout)
, m_Layout_TopRow(new QHBoxLayout)
, m_Layout_BottomRow(new QHBoxLayout)
, m_Frame_TopRow(new QFrame)
, m_Frame_BottomRow(new QFrame)
, m_Frame_Talents(new QFrame)
{
	initGUI();
}

TalentsGUI::TalentGroup::TalentGroup(QString talentGroupName)
: TalentGroupName(talentGroupName)
, TableWidget(new QTableWidget)
{}
TalentsGUI::Talent::Talent(QString talentName, QString propertieOne, QString propertieTwo, QString propertieThree)
: NameTalent(talentName)
, NamePropertyOne(propertieOne)
, NamePropertyTwo(propertieTwo)
, NamePropertyThree(propertieThree)
, LabelTalent(new QLabel)
, LabelPropertyOne(new QLabel)
, LabelPropertyTwo(new QLabel)
, LabelPropertyThree(new QLabel)
, LCDNumberPropertyOne(new QLCDNumber)
, LCDNumberPropertyTwo(new QLCDNumber)
, LCDNumberPropertyThree(new QLCDNumber)
, SpinBox(new MySpinBox)
, TableWidget(new QTableWidget)
{}

void TalentsGUI::initTalentGroup() {
	m_TalentGUI.insert(std::make_pair(GESELLSCHAFTSTALENTE, TalentGroup("Gesellschaftstalente")));
	m_TalentGUI.insert(std::make_pair(HANDWERKSTALENTE, TalentGroup("Handwerkstalente")));
	m_TalentGUI.insert(std::make_pair(KOERPERTALENTE, TalentGroup("Körpertalente")));
	m_TalentGUI.insert(std::make_pair(KRIEGSKUNSTTALENTE, TalentGroup("Kriegskunsttalente")));
	m_TalentGUI.insert(std::make_pair(NATURTALENTE, TalentGroup("Naturtalente")));
	m_TalentGUI.insert(std::make_pair(WISSENSTALENTE, TalentGroup("Wissenstalente")));

	setTalentData(GESELLSCHAFTSTALENTE);
	setTalentData(HANDWERKSTALENTE);
	setTalentData(KOERPERTALENTE);
	setTalentData(KRIEGSKUNSTTALENTE);
	setTalentData(NATURTALENTE);
	setTalentData(WISSENSTALENTE);
}
void TalentsGUI::initLabel() {
	for(auto& varOne : m_TalentGUI)
	{
		for(Talent& talentData : varOne.second.Data)
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
void TalentsGUI::initSpinbox() {
	for(auto varOne : m_TalentGUI) {
		for(Talent& talentData : varOne.second.Data) {
			talentData.SpinBox->setRange(0, 99);
			talentData.SpinBox->setFocusPolicy(Qt::StrongFocus);
			talentData.SpinBox->setFont(QFont("Times New Roman", 16, QFont::Bold));
		}
	}
}
void TalentsGUI::initTableTalentData() {
	for(auto& varOne : m_TalentGUI)
	{
		for (Talent& talentData : varOne.second.Data) {
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
void TalentsGUI::initTableTalentGroup() {
	int row = 0;

	for (auto varOne : m_TalentGUI) {
		setTableTalentGroup(varOne.second.TableWidget, {varOne.second.TalentGroupName}, varOne.second.Data.size());
		for (Talent& talentData : varOne.second.Data) {
			addTalentDataToTalentGroupTable(varOne.second.TableWidget, talentData.TableWidget, row);
			++row;
		}
		row = 0;
	}
}
void TalentsGUI::initGUI() {
	initTalentGroup();
	initLabel();
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

void TalentsGUI::setTalentData(TalentGroupNames talentGroupName) {
	switch (talentGroupName) {
		case GESELLSCHAFTSTALENTE: {
			m_TalentGUI.at(talentGroupName).Data.push_back(Talent("Betören", "MU", "CH", "SE"));
			m_TalentGUI.at(talentGroupName).Data.push_back(Talent("Diplomatie", "CH", "KL", "SE"));
			m_TalentGUI.at(talentGroupName).Data.push_back(Talent("Einschüchtern", "MU", "IN", "KK"));
			m_TalentGUI.at(talentGroupName).Data.push_back(Talent("Etikette", "KL", "IN", "CH"));
			m_TalentGUI.at(talentGroupName).Data.push_back(Talent("Gassenwissen", "KL", "IN", "CH"));
			m_TalentGUI.at(talentGroupName).Data.push_back(Talent("Handeln", "CH", "KL", "IN"));
			m_TalentGUI.at(talentGroupName).Data.push_back(Talent("Menschenkenntnis", "KL", "IN", "IN"));
			m_TalentGUI.at(talentGroupName).Data.push_back(Talent("Singen", "CH", "KL", "KO"));
			m_TalentGUI.at(talentGroupName).Data.push_back(Talent("Überreden", "CH", "KL", "IN"));
			break;
		}
		case HANDWERKSTALENTE: {
			m_TalentGUI.at(talentGroupName).Data.push_back(Talent("Heilkunde Handwerk", "KL", "GE", "MU"));
			m_TalentGUI.at(talentGroupName).Data.push_back(Talent("Holzbearbeitung", "GE", "KK", "GE"));
			m_TalentGUI.at(talentGroupName).Data.push_back(Talent("Kochen", "IN", "GE", "KL"));
			m_TalentGUI.at(talentGroupName).Data.push_back(Talent("Lederbearbeitung", "GE", "IN", "GE"));
			m_TalentGUI.at(talentGroupName).Data.push_back(Talent("Malen & Zeichnen", "IN", "GE", "KL"));
			m_TalentGUI.at(talentGroupName).Data.push_back(Talent("Mechanik", "KL", "GE", "IN"));
			m_TalentGUI.at(talentGroupName).Data.push_back(Talent("Metallbearbeitung", "GE", "KO", "KK"));
			m_TalentGUI.at(talentGroupName).Data.push_back(Talent("Musizieren", "CH", "GE", "KL"));
			m_TalentGUI.at(talentGroupName).Data.push_back(Talent("Steinbearbeitung", "GE", "GE", "KK"));
			m_TalentGUI.at(talentGroupName).Data.push_back(Talent("Stoffbearbeitung", "GE", "IN", "KL"));
			break;
		}
		case KOERPERTALENTE: {
			m_TalentGUI.at(talentGroupName).Data.push_back(Talent("Fesseln", "KL", "GE", "KK"));
			m_TalentGUI.at(talentGroupName).Data.push_back(Talent("Fliegen", "MU", "IN", "GE"));
			m_TalentGUI.at(talentGroupName).Data.push_back(Talent("Gaukeleien", "GE", "CH", "KO"));
			m_TalentGUI.at(talentGroupName).Data.push_back(Talent("Klettern", "KK", "KO", "MU"));
			m_TalentGUI.at(talentGroupName).Data.push_back(Talent("Körperbeherrschung", "GE", "KO", "KK"));
			m_TalentGUI.at(talentGroupName).Data.push_back(Talent("Kraftakt", "KK", "KO", "KK"));
			m_TalentGUI.at(talentGroupName).Data.push_back(Talent("Reiten", "GE", "KO", "IN"));
			m_TalentGUI.at(talentGroupName).Data.push_back(Talent("Schwimmen", "KO", "MU", "GE"));
			m_TalentGUI.at(talentGroupName).Data.push_back(Talent("Taschendiebstahl", "MU", "GE", "IN"));
			m_TalentGUI.at(talentGroupName).Data.push_back(Talent("Zechen", "SE", "KO", "KL"));
			break;
		}
		case KRIEGSKUNSTTALENTE: {
			m_TalentGUI.at(talentGroupName).Data.push_back(Talent("Ausbildung", "KL", "CH", "SE"));
			m_TalentGUI.at(talentGroupName).Data.push_back(Talent("Belagern", "KL", "IN", "MU"));
			m_TalentGUI.at(talentGroupName).Data.push_back(Talent("Fernkämpfer führen", "MU", "IN", "CH"));
			m_TalentGUI.at(talentGroupName).Data.push_back(Talent("GeoStrategien", "KL", "IN", "MU"));
			m_TalentGUI.at(talentGroupName).Data.push_back(Talent("Infanterie führen", "MU", "IN", "CH"));
			m_TalentGUI.at(talentGroupName).Data.push_back(Talent("Kavalerie führen", "MU", "IN", "CH"));
			m_TalentGUI.at(talentGroupName).Data.push_back(Talent("Logistik", "KL", "IN", "KL"));
			m_TalentGUI.at(talentGroupName).Data.push_back(Talent("Waffenkunde", "KL", "KL", "IN"));
			break;
		}
		case NATURTALENTE: {
			m_TalentGUI.at(talentGroupName).Data.push_back(Talent("Fährtensuche", "IN", "KL", "SE"));
			m_TalentGUI.at(talentGroupName).Data.push_back(Talent("Fallenstellen", "GE", "IN", "KK"));
			m_TalentGUI.at(talentGroupName).Data.push_back(Talent("Fischen", "SE", "GE", "KL"));
			m_TalentGUI.at(talentGroupName).Data.push_back(Talent("Jagdstrategien", "KL", "IN", "MU"));
			m_TalentGUI.at(talentGroupName).Data.push_back(Talent("Orientiereung", "IN", "KL", "IN"));
			m_TalentGUI.at(talentGroupName).Data.push_back(Talent("Verstohlenheit", "KL", "IN", "GE"));
			m_TalentGUI.at(talentGroupName).Data.push_back(Talent("Wildnisleben", "IN", "KL", "MU"));
			break;
		}
		case WISSENSTALENTE: {
			m_TalentGUI.at(talentGroupName).Data.push_back(Talent("Dynastiekunde", "KL", "KL", "IN"));
			m_TalentGUI.at(talentGroupName).Data.push_back(Talent("Flora & Fauna", "KL", "KL", "IN"));
			m_TalentGUI.at(talentGroupName).Data.push_back(Talent("Geographie", "KL", "KL", "IN"));
			m_TalentGUI.at(talentGroupName).Data.push_back(Talent("Geschichtswissen", "KL", "KL", "IN"));
			m_TalentGUI.at(talentGroupName).Data.push_back(Talent("Götter & Kulte", "KL", "KL", "IN"));
			m_TalentGUI.at(talentGroupName).Data.push_back(Talent("Heilkundewissen", "KL", "KL", "IN"));
			m_TalentGUI.at(talentGroupName).Data.push_back(Talent("Legenden", "KL", "KL", "IN"));
			m_TalentGUI.at(talentGroupName).Data.push_back(Talent("Magiekunde", "KL", "KL", "IN"));
			m_TalentGUI.at(talentGroupName).Data.push_back(Talent("Rechtskunde", "KL", "KL", "IN"));
			m_TalentGUI.at(talentGroupName).Data.push_back(Talent("Sternenkunde", "KL", "KL", "IN"));
			break;
		}
		default: {
			break;
		}
	}
}
void TalentsGUI::setTableTalentData(QTableWidget* obj, int columns, int rows) {
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
void TalentsGUI::setTableTalentGroup(QTableWidget* obj, QStringList header, int rows) {
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
void TalentsGUI::setPropertyValues(int ch, int ge, int in, int kk, int kl, int ko, int mu, int se) {
	for (auto var : m_TalentGUI) {
		for (Talent talentData : var.second.Data) {
			checkPropertyType(talentData.LabelPropertyOne, talentData.LCDNumberPropertyOne, {ch, ge, in, kk, kl, ko, mu, se});
			checkPropertyType(talentData.LabelPropertyTwo, talentData.LCDNumberPropertyTwo, {ch, ge, in, kk, kl, ko, mu, se});
			checkPropertyType(talentData.LabelPropertyThree, talentData.LCDNumberPropertyThree, {ch, ge, in, kk, kl, ko, mu, se});
		}
	}
}

void TalentsGUI::checkPropertyType(QLabel* property, QLCDNumber* display, std::vector<int> values) {
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
void TalentsGUI::addLabelToTalentDataTable(QTableWidget* obj, std::vector<QLabel*> label) {
	if(obj->columnCount()-1 == (int)label.size()) {
		for (int var = 0; var < obj->columnCount()-1; ++var) {
			obj->setCellWidget(0, var, label.at(var));
		}
	}
}
void TalentsGUI::addLCDNumberToTalentDataTable(QTableWidget* obj, std::vector<QLCDNumber*> lcdNumber) {
	if(obj->columnCount()-2 == (int)lcdNumber.size()) {
		for (int var = 0; var < (int)lcdNumber.size(); ++var) {
			lcdNumber.at(var)->setDigitCount(2);
			lcdNumber.at(var)->setSegmentStyle(QLCDNumber::Flat);
			obj->setCellWidget(1, var+1, lcdNumber.at(var));
		}
	}
}
void TalentsGUI::addSpinBoxToTalentDataTable(QTableWidget* obj, QSpinBox* spinBox) {
	obj->setCellWidget(0, obj->columnCount()-1, spinBox);
}
void TalentsGUI::addTalentDataToTalentGroupTable(QTableWidget* obj, QTableWidget* talentData, int row) {
	if(row <= obj->rowCount()) {
		obj->setCellWidget(row, 0, talentData);
	}
}
void TalentsGUI::mergeTalentDataTableCells(QTableWidget *obj) {
	obj->setSpan(0, 0, 2, 1);
	obj->setSpan(0, obj->columnCount()-1, 2, 1);
}

QFrame* TalentsGUI::getFrame() const {
	return m_Frame_Talents;
}
