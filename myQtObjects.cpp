#include "myQtObjects.hpp"

MySpinBox::MySpinBox(QWidget* parent)
: QSpinBox(parent)
{
	setFocusPolicy(Qt::StrongFocus);
}
void MySpinBox::wheelEvent(QWheelEvent *event)
{
	if (!hasFocus()) {
		event->ignore();
	} else {
		QSpinBox::wheelEvent(event);
	}
}

MyDoubleSpinBox::MyDoubleSpinBox(QWidget* parent)
: QDoubleSpinBox(parent)
{
	setFocusPolicy(Qt::StrongFocus);
}
void MyDoubleSpinBox::wheelEvent(QWheelEvent *event)
{
	if (!hasFocus()) {
		event->ignore();
	} else {
		QDoubleSpinBox::wheelEvent(event);
	}
}

MyComboBox::MyComboBox(QWidget* parent)
: QComboBox(parent)
{
	setFocusPolicy(Qt::StrongFocus);
}
void MyComboBox::wheelEvent(QWheelEvent *event)
{
	if (!hasFocus()) {
		event->ignore();
	} else {
		QComboBox::wheelEvent(event);
	}
}
