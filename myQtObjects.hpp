#ifndef MYQTOBJECTS_HPP
#define MYQTOBJECTS_HPP

#include <QSpinBox>
#include <QComboBox>
#include <QWheelEvent>

class MySpinBox : public QSpinBox {

	Q_OBJECT

public:
	MySpinBox(QWidget *parent = 0);

protected:
	virtual void wheelEvent(QWheelEvent *event);
};

class MyDoubleSpinBox : public QDoubleSpinBox {
	Q_OBJECT

public:
	MyDoubleSpinBox(QWidget *parent = 0);

protected:
	virtual void wheelEvent(QWheelEvent *event);
};

class MyComboBox : public QComboBox {
	Q_OBJECT

public:
	MyComboBox(QWidget *parent = 0);

protected:
	virtual void wheelEvent(QWheelEvent *event);
};

#endif // MYQTOBJECTS_HPP
