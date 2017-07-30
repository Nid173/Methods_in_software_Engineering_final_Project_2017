#include "stdafx.h"
#include "NumericBox.h"
#include "Button.h"


NumericBox::NumericBox(int width, int min, int max) {
	_min = min;
	_max = max;
	_width = width;
	_height = 2;
	Button minus(2);
	Button plus(2);
	plus.setTop(this->_top);
	minus.setLeft(this->_left - 1);
	plus.setLeft(this->_left + _width + 1);
	
}

bool NumericBox::setValue(int value) {
	if(value>_max||value<_min)
	return false;
	_value = value;
	return true;

}

int NumericBox::GetValue() {
	return this->_value;

}

void NumericBox::pluse() {
	setValue(_value + 1);
}
void NumericBox::minus() {
	setValue(_value - 1);
}