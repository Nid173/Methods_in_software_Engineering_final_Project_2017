#include "stdafx.h"
#include "NumericBox.h"



NumericBox::NumericBox(int width, int min, int max) {

	_min = min;
	_max = max;
	_width = width;
	_height = 2;
	_top = 0;
	_left = 0;

	
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