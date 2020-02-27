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

class Entity
{
private:
	struct Label
	{
		QLabel* Weight = new QLabel;
		QLabel* Height = new QLabel;
		QLabel* Health = new QLabel;
		QLabel* Mana = new QLabel;
	} m_Label;

	struct DoubleSpinBox
	{
		QDoubleSpinBox* Weight = new QDoubleSpinBox;
		QDoubleSpinBox* Height = new QDoubleSpinBox;
	} m_DoubleSpinBox;

	struct LCDNumber
	{
		QLCDNumber* Health = new QLCDNumber;
		QLCDNumber* Mana = new QLCDNumber;
	} m_LCDNumber;

	QComboBox* m_ComboBox_Species = new QComboBox;
	QCheckBox* m_CheckBox_Magical = new QCheckBox;

	struct Layout
	{
		QHBoxLayout* hBox_Weight = new QHBoxLayout;
		QHBoxLayout* hBox_Height = new QHBoxLayout;
		QHBoxLayout* hBox_Health = new QHBoxLayout;
		QHBoxLayout* hBox_Mana = new QHBoxLayout;
		QHBoxLayout* hBox_Entity = new QHBoxLayout;

		QVBoxLayout* vBox_HealthAndMana = new QVBoxLayout;
	} m_Layout;

	struct Frame
	{
		QFrame* Weight = new QFrame;
		QFrame* Height = new QFrame;
		QFrame* Health = new QFrame;
		QFrame* Mana = new QFrame;
		QFrame* HealthAndMana = new QFrame;
		QFrame* Entity = new QFrame;
	} m_Frame;

	double m_Weight, m_Height, m_Health, m_Mana;
	std::string m_Species;
	bool m_Magical;

	void initLabel();
	void initDoubleSpinBox();
	void initLCDNumber();
	void initLayout();
	void initFrame();
	void initGUI();

	void setLabel(QLabel* obj, QString text);
	void setCheckbox(QCheckBox* obj);
	void setComboBox(QComboBox* obj, std::vector<QString> items);

	void setFont(QWidget *obj, int size);

public:
	Entity();

	QFrame* getFrameEntity();
};

#endif // ENTITY_HPP
