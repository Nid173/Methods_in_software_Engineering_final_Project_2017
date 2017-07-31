#include "stdafx.h"
#include "NumericBox.h"
#include "Button.h"
#include <string>


NumericBox::NumericBox(int width, int min, int max) :Panel(5,width+8),_min(min),_max(max){

	_value = min;
	Button minus(2);
	minus.setText(L"-");
	minus.setTop(3);
	minus.setLeft(5);
	//minus.setBorder(BorderType::Single);
	minus.setBackground(Color::Blue);
	minus.setForeground(Color::White);
	//minus.addListener(listener);

	Button plus(2);
	//plus.setBorder(BorderType::Single);
	plus.setText(L"+");
	plus.setLeft(13);
	plus.setTop(3);
	plus.setBackground(Color::Blue);
	plus.setForeground(Color::White);
	//plus.addListener(Plus_button );

	Label value(width);
	value.setLeft(8);
	value.setTop(3);
	value.setText(L" " + to_wstring(_value));    //the value
	value.setBackground(Color::White);
	value.setForeground(Color::Black);

	_controls.push_back(&minus);
	_controls.push_back(&value);
	_controls.push_back(&plus);

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

