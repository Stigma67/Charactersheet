#ifndef ADVENTURPOINTS_HPP
#define ADVENTURPOINTS_HPP

#include <QWidget>
#include <QLayout>
#include <QFrame>
#include <QLabel>
#include <QLCDNumber>
#include <QSpinBox>

class AdventurePoints
{
private:
	QSpinBox* m_SpinBox_APAll = new QSpinBox;

	struct Layout
	{
		QHBoxLayout* hBox_AP = new QHBoxLayout;

		QVBoxLayout* vBox_APAll = new QVBoxLayout;
		QVBoxLayout* vBox_APUsed = new QVBoxLayout;
		QVBoxLayout* vBox_APRemaining = new QVBoxLayout;
	} m_Layout;

	struct Frame
	{
		QFrame* APAll = new QFrame;
		QFrame* APUsed = new QFrame;
		QFrame* APRemaining = new QFrame;
		QFrame* AP = new QFrame;
	} m_Frame;

	struct Label
	{
		QLabel* APAll = new QLabel;
		QLabel* APUsed = new QLabel;
		QLabel* APRemaining = new QLabel;
	} m_Label;

	struct LCDNumber
	{
		QLCDNumber* APUsed = new QLCDNumber;
		QLCDNumber* APRemaining = new QLCDNumber;
	} m_LCD;

	void initLabel();
	void initSpinBoxAndLCD();
	void initLayout();
	void initFrame();
	void initGUI();

	void setFont(QWidget* obj);

public:
	AdventurePoints();

	QFrame* getFrameAdventurePoints();
};

#endif // ADVENTURPOINTS_HPP
