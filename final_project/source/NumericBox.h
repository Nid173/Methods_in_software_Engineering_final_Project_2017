#pragma once
#include "Panel.h"
#include"Button.h"

class NumericBox : public Panel {
protected:

	int _min;
	int _max;
	int _value;
public:
	NumericBox(int width, int min, int max);
	~NumericBox() {}
	bool setValue(int value);
	int getValue();
	virtual bool canGetFocus() { return false; }
	virtual string className() { return "NumericBox"; }
	inline virtual void setLeft(int left);
	inline virtual void setTop(int top);

	virtual void mousePressed(int x, int y, bool isLeft) { 
		x -= _left;
		y -= _top;
		for (int i = 0; i < _controls.size(); i++) {
			int myx = _controls[i]->getLeft() + _controls[i]->getWidth();
			//int myy = _controls[i]->getTop() + _controls[i]->getHeight();
			int x_l = _controls[i]->getLeft();
			//int y_t = _controls[i]->getTop();
			if ((x >= x_l && x <= myx) && (_controls[i]->className() == "Button")) {
				Button* tmp = static_cast<Button*>(_controls[i]);
				tmp->getListener().MousePressed(*this,x,y,isLeft);
			}
		}
	}

};

void NumericBox::setTop(int top) {
	_top = top;
	for (int i = 0; i < _controls.size(); i++) {
		_controls[i]->setTop(0);
	}

}

void NumericBox::setLeft(int left) {
	_left = left;
	for (int i = 0; i < _controls.size(); i++) {
		if (i == 0) {
			_controls[i]->setLeft(0);
		}
		else {
			_controls[i]->setLeft(_controls[i - 1]->getWidth() + _controls[i - 1]->getLeft());
		}
	}

}

class Plus_button :public MouseListener {
public:
	Plus_button() {}
	virtual void MousePressed(Control &control, int x, int y, bool isLeft) {
		NumericBox * tmp = static_cast<NumericBox*>(&control);
		tmp->setValue(tmp->getValue() + 1);
	}
};

class Minus_button :public MouseListener {
public:
	virtual void MousePressed(Control &control, int x, int y, bool isLeft) {
		NumericBox * tmp = static_cast<NumericBox*>(&control);
		tmp->setValue(tmp->getValue() - 1);
	}
};
