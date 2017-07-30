#pragma once
#include "TextBox.h"

class Label :public TextBox {
public:
	Label(int width);
	virtual bool canGetFocus();

};
