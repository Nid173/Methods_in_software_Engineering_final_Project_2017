#include "stdafx.h"
#include "NumericBox.h"



NumericBox::NumericBox(int width, int min, int max) {
	this->_width = width;
	this->_min = min;
	this->_max = max;
	
}

bool NumericBox::setValue(int value) {
	this->_value = value;
	return true;

}

int NumericBox::GetValue() {
	return this->_value;

}