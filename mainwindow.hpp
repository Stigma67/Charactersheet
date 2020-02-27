#include <QMainWindow>
#include <QLayout>
#include <QTabWidget>
#include <QComboBox>
#include <QLCDNumber>

#include "entity.hpp"
#include "properties.hpp"
#include "adventurePoints.hpp"
#include "basePlayerData.hpp"
#include "socialPlayerData.hpp"
#include "talents.hpp"

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

class MainWindow : public QMainWindow
{
	Q_OBJECT
private:
	struct Widget
	{
		QTabWidget* TabWidget_MainWidget = new QTabWidget;
		QWidget* Widget_BaseData = new QWidget;
		QWidget* Widget_Talents = new QWidget;
		QWidget* Widget_FightTechniques = new QWidget;
		QWidget* Widget_Inventory = new QWidget;
	} m_Widget;

	struct Frame
	{
		QFrame* Frame_TalentsAndAP = new QFrame;
		QFrame* Line_PropertiesAP = new QFrame;
		QFrame* Line_Horizontal_BaseData01 = new QFrame;
		QFrame* Line_Horizontal_baseData02 = new QFrame;
		QFrame* Line_Talents01 = new QFrame;
	} m_Frame;

	struct Layout
	{
		QHBoxLayout* hBox_TalentsAndAP = new QHBoxLayout;

		QVBoxLayout* vBox_BaseData = new QVBoxLayout;
		QVBoxLayout* vBox_Talents = new QVBoxLayout;
		QVBoxLayout* vBox_FightingTechniques = new QVBoxLayout;
		QVBoxLayout* vBox_Inventory = new QVBoxLayout;
	} m_Layout;

	Entity m_Entity;
	Properties m_Properties;
	AdventurePoints m_AdventurePoints;
	BasePlayerData m_BasePlayerData;
	SocialPlayerData m_SocialPlayerData;
	Talents m_Talents;

	void combinePropertiesAndAP(Properties m_Properties, AdventurePoints m_AdventurePoints);

public:
	MainWindow(QWidget* parent = nullptr, Entity entity = Entity(), Properties talents = Properties(),
	AdventurePoints adventurePoints = AdventurePoints(), BasePlayerData basePlayerData = BasePlayerData(),
	SocialPlayerData socialPlayerData = SocialPlayerData());
	~MainWindow();

//private slots:
//	void addBasePlayerData();
};
#endif // MAINWINDOW_H
