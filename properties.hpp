#ifndef PROPERTIES_H
#define PROPERTIES_H

#include <QLayout>
#include <QLabel>
#include "myQtObjects.hpp"

class PropertiesGUI
{
private:
	struct Label {
		QLabel* MU;
		QLabel* KL;
		QLabel* IN;
		QLabel* CH;
		QLabel* SE;
		QLabel* GE;
		QLabel* KO;
		QLabel* KK;

		Label();
	};
	struct SpinBox {
		MySpinBox* MU;
		MySpinBox* KL;
		MySpinBox* IN;
		MySpinBox* CH;
		MySpinBox* SE;
		MySpinBox* GE;
		MySpinBox* KO;
		MySpinBox* KK;

		SpinBox();
	};
	struct Layout {
		QHBoxLayout* hBox_Talents;

		QVBoxLayout* vBox_MU;
		QVBoxLayout* vBox_KL;
		QVBoxLayout* vBox_IN;
		QVBoxLayout* vBox_CH;
		QVBoxLayout* vBox_SE;
		QVBoxLayout* vBox_GE;
		QVBoxLayout* vBox_KO;
		QVBoxLayout* vBox_KK;

		Layout();
	};
	struct Frame {
		QFrame* MU;
		QFrame* KL;
		QFrame* IN;
		QFrame* CH;
		QFrame* SE;
		QFrame* GE;
		QFrame* KO;
		QFrame* KK;
		QFrame* Properties;

		Frame();
	};
	Label m_Label;
	SpinBox m_SpinBox;
	Layout m_Layout;
	Frame m_Frame;

	void initLabels();
	void initSpinBoxes();
	void initLayouts();
	void initFrames();
	void initGUI();

	void setFrameColor(QFrame* obj, QString red, QString green, QString blue);
	void setFont(QWidget* obj);

public:
	PropertiesGUI();

	QFrame* getFrameProperties();

};

#endif // PROPERTIES_H
