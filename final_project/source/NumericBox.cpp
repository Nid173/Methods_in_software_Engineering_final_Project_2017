#include "stdafx.h"
#include "NumericBox.h"
#include "Button.h"


NumericBox::NumericBox(int width, int min, int max) {
	_min = min;
	_max = max;
	_width = width;
	_height = 2;
	Button minus(2);
	minus.setText(L"-");
	minus.setBorder(BorderType::Single);
	minus.setLeft(this->_left - 1);
	//minus.addListener(listener);

	Button plus(2);
	plus.setBorder(BorderType::Single);
	plus.setText(L"+");
	plus.setTop(this->_top);
	plus.setLeft(this->_left + _width + 1);
	//plus.addListener(listener);

	Label value(15);
	value.setText(L"0");    //the value
	value.setBackground(Color::White);
	value.setForeground(Color::Black);

	Panel box(5, 10);
	box.AddControl(minus, 0, 0);
	box.AddControl(value, 3,0);
	box.AddControl(minus, width+4, 0);

	//_controls.AddControl(box., 0, 0);


	
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

void NumericBox::plus() {
	if (setValue(_value + 1)) {
	//the value changed
	}
}
void NumericBox::minus() {
	if (setValue(_value - 1)) {
		//the value changed
	}
}