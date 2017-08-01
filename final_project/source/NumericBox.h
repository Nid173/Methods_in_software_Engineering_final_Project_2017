#pragma once
#include "Panel.h"
#include"Button.h"

class Plus_button :public MouseListener{
public:
	virtual void MousePressed(Control &control, int x, int y, bool isLeft) {
	}
};

class Minus_button :public MouseListener {
public:
	virtual void MousePressed(Control &control, int x, int y, bool isLeft) {
	}
};
class NumericBox : public Panel {
protected:

	int _min;
	int _max;
	int _value;
	MouseListener* listener;
public:
	NumericBox(int width, int min, int max);
	~NumericBox() {}
	bool setValue(int value);
	int GetValue();
	inline virtual void setLeft(int left);
	inline virtual void setTop(int top);
};

void NumericBox:: setTop(int top) {
	_top = top;

}

void NumericBox::setLeft(int left) {
	_left = left;

}
