#pragma once
#include "Control.h"

class TextBox : public Control {
protected:
	int _width;
	string _text;
public:
	TextBox(int width);
	~TextBox() {}
	void setText(string value);
	inline string getText();

};