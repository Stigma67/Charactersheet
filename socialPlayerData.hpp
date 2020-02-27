#ifndef SOCIALPLAYERDATA_HPP
#define SOCIALPLAYERDATA_HPP

#include <QLabel>
#include <QComboBox>
#include <QTableWidget>
#include <QHeaderView>
#include <QLayout>
#include <QFrame>

class SocialPlayerData
{
private:
	struct ComboBox
	{
		QComboBox* Titel = new QComboBox;
		QComboBox* Profession = new QComboBox;
		QComboBox* SocialStatus = new QComboBox;
	} m_ComboBox;

	struct Table
	{
		QTableWidget* Characteristics = new QTableWidget;
		QTableWidget* OtherSpecifications = new QTableWidget;
		QTableWidget* Advantages = new QTableWidget;
		QTableWidget* Disadvantages = new QTableWidget;
		QTableWidget* GenerallSpecialSkill = new QTableWidget;
	} m_Table;

	struct Layout
	{
		QHBoxLayout* hBox_Titel = new QHBoxLayout;
		QHBoxLayout* hBox_Profession = new QHBoxLayout;
		QHBoxLayout* hBox_SocialStatus = new QHBoxLayout;
		QHBoxLayout* hBox_TopRow = new QHBoxLayout;
		QHBoxLayout* hBox_BottomRow = new QHBoxLayout;

		QVBoxLayout* vBox_Social = new QVBoxLayout;
		QVBoxLayout* vBox_SocialPlayerData = new QVBoxLayout;
	} m_Layout;

	struct Frame
	{
		QFrame* Titel = new QFrame;
		QFrame* Profession = new QFrame;
		QFrame* SocialStatus = new QFrame;
		QFrame* Social = new QFrame;
		QFrame* TopRow = new QFrame;
		QFrame* BottomRow = new QFrame;
		QFrame* SocialPlayerData = new QFrame;
	} m_Frame;

	void initComboBox();
	void initTable();
	void initLayout();
	void initFrame();

	void setLabel(QLabel* obj, QString text);
	void setComboBox(QComboBox* obj, std::vector<QString> items, bool isDisabled);
	void setTable(QTableWidget* obj, QStringList titel);
	void setFont(QWidget *obj, int size);

public:
	SocialPlayerData();

	void initGUI();

	QFrame* getFrameSocialPlayerData();
};

#endif // SOCIALPLAYERDATA_HPP
