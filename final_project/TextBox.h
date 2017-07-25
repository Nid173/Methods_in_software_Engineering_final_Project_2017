#pragma once
#include "Control.h"

class TextBox : public Control {
protected:
	int _width;
	int _text;
public:
	TextBox(int width);
	~TextBox() {}
	void setText(string value);
	inline string getText();

};