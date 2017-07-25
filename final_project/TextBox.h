#pragma once
#include "Control.h"

class TextBox : public Control {
protected:
	int _width;
	string _text;
public:
	TextBox(int width);
	~TextBox() {}
	inline void setText(string value);
	inline string getText() const;

	/* Control Methods*/
	 void mousePressed(int x, int y, bool isLeft);
	 void keyDown(int keyCode, char charecter);
	 short getLeft() ;
	 short getTop() ;
	 void getAllControls(vector<Control*>* controls);
	 bool canGetFocus();
};

void TextBox::setText(string value) {
	this->_text = value;
}

string TextBox::getText() const {
	return this->_text;
}