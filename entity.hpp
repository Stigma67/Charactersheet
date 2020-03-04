#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <string>
#include <vector>

#include <QLabel>
#include <QDoubleSpinBox>
#include <QLCDNumber>
#include <QComboBox>
#include <QCheckBox>
#include <QLayout>

class EntityGUI
{
private:
	struct Label {
		QLabel* Weight;
		QLabel* Height;
		QLabel* Health;
		QLabel* Mana;

		Label();
	};
	struct DoubleSpinBox {
		QDoubleSpinBox* Weight;
		QDoubleSpinBox* Height;

		DoubleSpinBox();
	};
	struct LCDNumber {
		QLCDNumber* Health;
		QLCDNumber* Mana;

		LCDNumber();
	};
	struct Layout {
		QHBoxLayout* hBox_Weight;
		QHBoxLayout* hBox_Height;
		QHBoxLayout* hBox_Health;
		QHBoxLayout* hBox_Mana;
		QHBoxLayout* hBox_Entity;

		QVBoxLayout* vBox_HealthAndMana;

		Layout();
	};
	struct Frame
	{
		QFrame* Weight;
		QFrame* Height;
		QFrame* Health;
		QFrame* Mana;
		QFrame* HealthAndMana;
		QFrame* Entity;

		Frame();
	};
	Label m_Label;
	DoubleSpinBox m_DoubleSpinBox;
	LCDNumber m_LCDNumber;
	Layout m_Layout;
	Frame m_Frame;
	QComboBox* m_ComboBox_Species;
	QCheckBox* m_CheckBox_Magical;

	void initLabel();
	void initDoubleSpinBox();
	void initLCDNumber();
	void initLayout();
	void initFrame();
	void initGUI();

	void setLabel(QLabel* obj, QString text, int width, int height);
	void setCheckbox(QCheckBox* obj);
	void setComboBox(QComboBox* obj, std::vector<QString> items);

	void setFont(QWidget *obj, int size);

public:
	EntityGUI();

	QFrame* getFrameEntity();
};


class Entity {
public:

private:

};

#endif // ENTITY_HPP
