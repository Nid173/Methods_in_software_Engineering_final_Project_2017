#pragma once
#include "TextBox.h"

class Label :public TextBox {
public:
	Label(int width);

	inline void setText(string value);
};

void Label::setText(string value){
	this->_text = value;
}