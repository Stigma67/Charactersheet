#ifndef PROPERTIES_H
#define PROPERTIES_H

#include <QLayout>
#include <QLabel>
#include <QSpinBox>

class Properties
{
private:
	struct Label
	{
		QLabel* MU = new QLabel;
		QLabel* KL = new QLabel;
		QLabel* IN = new QLabel;
		QLabel* CH = new QLabel;
		QLabel* SE = new QLabel;
		QLabel* GE = new QLabel;
		QLabel* KO = new QLabel;
		QLabel* KK = new QLabel;
	} m_Label;

	struct SpinBox
	{
		QSpinBox* MU = new QSpinBox;
		QSpinBox* KL = new QSpinBox;
		QSpinBox* IN = new QSpinBox;
		QSpinBox* CH = new QSpinBox;
		QSpinBox* SE = new QSpinBox;
		QSpinBox* GE = new QSpinBox;
		QSpinBox* KO = new QSpinBox;
		QSpinBox* KK = new QSpinBox;
	} m_SpinBox;

	struct Layout
	{
		QHBoxLayout* hBox_Talents = new QHBoxLayout;

		QVBoxLayout* vBox_MU = new QVBoxLayout;
		QVBoxLayout* vBox_KL = new QVBoxLayout;
		QVBoxLayout* vBox_IN = new QVBoxLayout;
		QVBoxLayout* vBox_CH = new QVBoxLayout;
		QVBoxLayout* vBox_SE = new QVBoxLayout;
		QVBoxLayout* vBox_GE = new QVBoxLayout;
		QVBoxLayout* vBox_KO = new QVBoxLayout;
		QVBoxLayout* vBox_KK = new QVBoxLayout;
	} m_Layout;

	struct Frame
	{
		QFrame* MU = new QFrame;
		QFrame* KL = new QFrame;
		QFrame* IN = new QFrame;
		QFrame* CH = new QFrame;
		QFrame* SE = new QFrame;
		QFrame* GE = new QFrame;
		QFrame* KO = new QFrame;
		QFrame* KK = new QFrame;
		QFrame* Talents = new QFrame;
	} m_Frame;

	void initLabels();
	void initSpinBoxes();
	void initLayouts();
	void initFrames();
	void initGUI();

	void setFrameColor(QFrame* obj, QString red, QString green, QString blue);
	void setFont(QWidget* obj);

public:
	Properties();

	QFrame* getFrameProperties();

};

#endif // PROPERTIES_H
