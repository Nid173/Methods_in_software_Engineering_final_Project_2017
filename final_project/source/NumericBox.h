#pragma once
#include "Panel.h"
#include"Button.h"
class cal_button :public MouseListener {
private:
	float number1;
	float number2;
public:
	virtual void MousePressed(Control &control, int x, int y, bool isLeft) {

	}
};

class NumericBox : public Panel {
protected:

	int _min;
	int _max;
	int _value;
public:
	NumericBox(int width, int min, int max);
	~NumericBox() {}
	bool setValue(int value);
	int GetValue();
	void plus();
	void minus();
};