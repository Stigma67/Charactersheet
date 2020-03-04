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
#include "battleTechniques.hpp"
#include "inventory.hpp"

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

class MainWindow : public QMainWindow
{
	Q_OBJECT
private:
	struct Widget {
		QTabWidget* TabWidget_MainWidget;
		QWidget* Widget_BaseData;
		QWidget* Widget_Talents;
		QWidget* Widget_BattleTechniques;
		QWidget* Widget_Inventory;

		Widget();
	};
	struct Frame {
		QFrame* Frame_TalentsAndAP;
		QFrame* Line_PropertiesAP;
		QFrame* Line_Horizontal_BaseData01;
		QFrame* Line_Horizontal_baseData02;
		QFrame* Line_Talents01;

		Frame();
	};
	struct Layout {
		QHBoxLayout* hBox_TalentsAndAP;

		QVBoxLayout* vBox_BaseData;
		QVBoxLayout* vBox_Talents;
		QVBoxLayout* vBox_BattleTechniques;
		QVBoxLayout* vBox_Inventory;

		Layout();
	};
	Widget m_Widget;
	Frame m_Frame;
	Layout m_Layout;

	EntityGUI m_Entity;
	PropertiesGUI m_Properties;
	AdventurePointsGUI m_AdventurePoints;
	BasePlayerDataGUI m_BasePlayerData;
	SocialPlayerDataGUI m_SocialPlayerData;
	TalentsGUI m_Talents;
	BattleTechniquesGUI m_BattleTechniques;
	InventoryGUI m_InventoryGUI;

	void combinePropertiesAndAP(PropertiesGUI m_Properties, AdventurePointsGUI m_AdventurePoints);

public:
	MainWindow(QWidget* parent = nullptr);
	~MainWindow();

	//private slots:
	//	void addBasePlayerData();
};
#endif // MAINWINDOW_H
