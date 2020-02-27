#include "mainwindow.hpp"
//#include <QDebug>

MainWindow::MainWindow(QWidget* parent, Entity entity, Properties properties, AdventurePoints adventurePoints, BasePlayerData basePlayerData,
SocialPlayerData socialPlayerData)
: QMainWindow(parent)
, m_Entity(entity)
, m_Properties(properties)
, m_AdventurePoints(adventurePoints)
, m_BasePlayerData(basePlayerData)
, m_SocialPlayerData(socialPlayerData)
, m_Talents(Talents())
{
	combinePropertiesAndAP(properties, adventurePoints);

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

	m_Widget.TabWidget_MainWidget->addTab(m_Widget.Widget_FightTechniques, "Kamftechniken");
	m_Widget.TabWidget_MainWidget->addTab(m_Widget.Widget_Inventory, "Inventar");

	setCentralWidget(m_Widget.TabWidget_MainWidget);

//	connect(m_PushButton_test, SIGNAL(clicked()), this, SLOT(addBasePlayerData()));
}

void MainWindow::combinePropertiesAndAP(Properties properties, AdventurePoints adventurePoints)
{
	m_Frame.Line_PropertiesAP->setFrameStyle(QFrame::VLine | QFrame::Plain);
	m_Frame.Line_PropertiesAP->setLineWidth(3);

	m_Layout.hBox_TalentsAndAP->addWidget(properties.getFrameProperties());
	m_Layout.hBox_TalentsAndAP->addWidget(m_Frame.Line_PropertiesAP);
	m_Layout.hBox_TalentsAndAP->addWidget(adventurePoints.getFrameAdventurePoints());
	m_Frame.Frame_TalentsAndAP->setLayout(m_Layout.hBox_TalentsAndAP);
}

MainWindow::~MainWindow()
{}
