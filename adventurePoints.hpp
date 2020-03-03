#ifndef ADVENTURPOINTS_HPP
#define ADVENTURPOINTS_HPP

#include <QWidget>
#include <QLayout>
#include <QFrame>
#include <QLabel>
#include <QLCDNumber>
#include "myQtObjects.hpp"

class AdventurePointsGUI
{
private:
	struct Layout {
		QHBoxLayout* hBox_AP;

		QVBoxLayout* vBox_APAll;
		QVBoxLayout* vBox_APUsed;
		QVBoxLayout* vBox_APRemaining;

		Layout();
	};
	struct Frame {
		QFrame* APAll;
		QFrame* APUsed;
		QFrame* APRemaining;
		QFrame* AP;

		Frame();
	};
	struct Label {
		QLabel* APAll;
		QLabel* APUsed;
		QLabel* APRemaining;

		Label();
	};
	struct LCDNumber {
		QLCDNumber* APUsed;
		QLCDNumber* APRemaining;

		LCDNumber();
	};
	Layout m_Layout;
	Frame m_Frame;
	Label m_Label;
	LCDNumber m_LCD;
	MySpinBox* m_SpinBox_APAll;

	void initLabel();
	void initSpinBoxAndLCD();
	void initLayout();
	void initFrame();
	void initGUI();

	void setFont(QWidget* obj);

public:
	AdventurePointsGUI();

	QFrame* getFrameAdventurePoints();
};

#endif // ADVENTURPOINTS_HPP
