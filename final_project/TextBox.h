#pragma once
#include "Control.h"

class TextBox : public Control {
protected:
	string _text;
public:
	TextBox(int width);
	~TextBox() {}
	inline void setText(string value);
	inline string getText() const;

	/* Control Methods*/
	virtual void draw(Graphics& g, int x, int y, size_t z)const;
	 void mousePressed(int x, int y, bool isLeft);
	 void keyDown(int keyCode, char charecter);
	 void getAllControls(vector<Control*>* controls);
	 bool canGetFocus();
};

void TextBox::setText(string value) {
	this->_text = value;
}

string TextBox::getText() const {
	return this->_text;
}