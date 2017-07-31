#include "stdafx.h"
#include "NumericBox.h"
#include "Button.h"
#include <string>


NumericBox::NumericBox(int width, int min, int max) {
	_min = min;
	_max = max;
	_width = width;
	_height = 2;
	_value = min;
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
	value.setText(L" " + to_wstring(_value));    //the value
	value.setBackground(Color::White);
	value.setForeground(Color::Black);

	Panel box(5, 10);
	box.AddControl(minus, 0, 4);
	box.AddControl(value, 3,4);
	box.AddControl(minus, width+4, 4);

	//_controls.push_back(&box);


	
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
	//XXX.setText(L" "+to_wstring(_value));
	}
}

void NumericBox::minus() {
	if (setValue(_value - 1)) {
		//the value changed
		//XXX.setText(L" "+to_wstring(_value));
	}
}