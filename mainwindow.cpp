#include "mainwindow.hpp"
//#include <QDebug>

MainWindow::MainWindow(QWidget* parent)
: QMainWindow(parent)
, m_Entity(EntityGUI())
, m_Properties(Properties())
, m_AdventurePoints(AdventurePointsGUI())
, m_BasePlayerData(BasePlayerDataGUI())
, m_SocialPlayerData(SocialPlayerData())
, m_Talents(TalentsGUI())
, m_BattleTechniques(BattleTechniquesGUI())
, m_InventoryGUI(InventoryGUI())
{
	combinePropertiesAndAP(m_Properties, m_AdventurePoints);

	m_Frame.Line_Horizontal_BaseData01->setFrameStyle(QFrame::HLine | QFrame::Plain);
	m_Frame.Line_Horizontal_BaseData01->setLineWidth(3);
	m_Frame.Line_Horizontal_baseData02->setFrameStyle(QFrame::HLine | QFrame::Plain);
	m_Frame.Line_Horizontal_baseData02->setLineWidth(3);
	m_Frame.Line_Talents01->setFrameStyle(QFrame::HLine | QFrame::Plain);
	m_Frame.Line_Talents01->setLineWidth(3);

	m_Layout.vBox_BaseData->addWidget(m_BasePlayerData.getFrameBasePlayerData());
	m_Layout.vBox_BaseData->addWidget(m_Frame.Line_Horizontal_BaseData01);
	m_Layout.vBox_BaseData->addWidget(m_Entity.getFrameEntity());
	m_Layout.vBox_BaseData->addWidget(m_Frame.Line_Horizontal_baseData02);
	m_Layout.vBox_BaseData->addWidget(m_SocialPlayerData.getFrameSocialPlayerData());
	m_Layout.vBox_BaseData->addItem(new QSpacerItem(1, 1, QSizePolicy::Fixed, QSizePolicy::Expanding));
	m_Widget.Widget_BaseData->setLayout(m_Layout.vBox_BaseData);
	m_Widget.TabWidget_MainWidget->addTab(m_Widget.Widget_BaseData, "Basisdaten");

	m_Layout.vBox_Talents->addWidget(m_Frame.Frame_TalentsAndAP);
	m_Layout.vBox_Talents->addWidget(m_Frame.Line_Talents01);
	m_Layout.vBox_Talents->addWidget(m_Talents.getFrame());
	m_Widget.Widget_Talents->setLayout(m_Layout.vBox_Talents);
	m_Widget.TabWidget_MainWidget->addTab(m_Widget.Widget_Talents, "Talente");

	m_Layout.vBox_BattleTechniques->addWidget(m_BattleTechniques.getFrame());
	m_Layout.vBox_BattleTechniques->addWidget(m_InventoryGUI.getTableEquipmentMelee());
	m_Layout.vBox_BattleTechniques->addWidget(m_InventoryGUI.getTableEquipmentRanged());
	m_Widget.Widget_BattleTechniques->setLayout(m_Layout.vBox_BattleTechniques);
	m_Widget.TabWidget_MainWidget->addTab(m_Widget.Widget_BattleTechniques, "Kamftechniken");

	m_Layout.vBox_Inventory->addWidget(m_InventoryGUI.getTableInventoryItems());
	m_Layout.vBox_Inventory->addWidget(m_InventoryGUI.getTableInventoryWAC());
	m_Widget.Widget_Inventory->setLayout(m_Layout.vBox_Inventory);
	m_Widget.TabWidget_MainWidget->addTab(m_Widget.Widget_Inventory, "Inventar");

	setCentralWidget(m_Widget.TabWidget_MainWidget);

//	connect(m_PushButton_test, SIGNAL(clicked()), this, SLOT(addBasePlayerData()));
}
MainWindow::Widget::Widget()
: TabWidget_MainWidget(new QTabWidget)
, Widget_BaseData(new QWidget)
, Widget_Talents(new QWidget)
, Widget_BattleTechniques(new QWidget)
, Widget_Inventory(new QWidget)
{}
MainWindow::Frame::Frame()
: Frame_TalentsAndAP(new QFrame)
, Line_PropertiesAP(new QFrame)
, Line_Horizontal_BaseData01(new QFrame)
, Line_Horizontal_baseData02(new QFrame)
, Line_Talents01(new QFrame)
{}
MainWindow::Layout::Layout()
: hBox_TalentsAndAP(new QHBoxLayout)
, vBox_BaseData(new QVBoxLayout)
, vBox_Talents(new QVBoxLayout)
, vBox_BattleTechniques(new QVBoxLayout)
, vBox_Inventory(new QVBoxLayout)
{}

void MainWindow::combinePropertiesAndAP(Properties properties, AdventurePointsGUI adventurePoints) {
	m_Frame.Line_PropertiesAP->setFrameStyle(QFrame::VLine | QFrame::Plain);
	m_Frame.Line_PropertiesAP->setLineWidth(3);

	m_Layout.hBox_TalentsAndAP->addWidget(properties.getFrameProperties());
	m_Layout.hBox_TalentsAndAP->addWidget(m_Frame.Line_PropertiesAP);
	m_Layout.hBox_TalentsAndAP->addWidget(adventurePoints.getFrameAdventurePoints());
	m_Frame.Frame_TalentsAndAP->setLayout(m_Layout.hBox_TalentsAndAP);
}

MainWindow::~MainWindow()
{}
