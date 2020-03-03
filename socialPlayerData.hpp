#ifndef SOCIALPLAYERDATA_HPP
#define SOCIALPLAYERDATA_HPP

#include <QLabel>
#include <QTableWidget>
#include <QHeaderView>
#include <QLayout>
#include <QFrame>
#include "myQtObjects.hpp"

class SocialPlayerData
{
private:
	struct ComboBox {
		MyComboBox* Titel;
		MyComboBox* Profession;
		MyComboBox* SocialStatus;

		ComboBox();
	};
	struct Table {
		QTableWidget* Characteristics;
		QTableWidget* OtherSpecifications;
		QTableWidget* Advantages;
		QTableWidget* Disadvantages;
		QTableWidget* GenerallSpecialSkill;

		Table();
	};
	struct Layout {
		QHBoxLayout* hBox_Titel;
		QHBoxLayout* hBox_Profession;
		QHBoxLayout* hBox_SocialStatus;
		QHBoxLayout* hBox_TopRow;
		QHBoxLayout* hBox_BottomRow;

		QVBoxLayout* vBox_Social;
		QVBoxLayout* vBox_SocialPlayerData;

		Layout();
	};
	struct Frame {
		QFrame* Titel;
		QFrame* Profession;
		QFrame* SocialStatus;
		QFrame* Social;
		QFrame* TopRow;
		QFrame* BottomRow;
		QFrame* SocialPlayerData;

		Frame();
	};
	ComboBox m_ComboBox;
	Table m_Table;
	Layout m_Layout;
	Frame m_Frame;

	void initComboBox();
	void initTable();
	void initLayout();
	void initFrame();

	void setLabel(QLabel* obj, QString text);
	void setComboBox(QComboBox* obj, std::vector<QString> items, bool isDisabled);
	void setTable(QTableWidget* obj, QStringList titel);
	void setFont(QWidget *obj, int size);

	void initGUI();

public:
	SocialPlayerData();

	QFrame* getFrameSocialPlayerData();
};

#endif // SOCIALPLAYERDATA_HPP
