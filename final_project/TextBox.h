#pragma once
#include "Control.h"
#include "Graphics.h"

class TextBox : public Control, public Graphics {
protected:
	wstring _text;
public:
	TextBox(int width);
	~TextBox() {}
	inline void setText(wstring value);
	inline wstring getText() const;

	/* Control Methods*/
	virtual void draw(Graphics& g, int x, int y, size_t z)const;
	 void mousePressed(int x, int y, bool isLeft);
	 void keyDown(int keyCode, char charecter);
	 void getAllControls(vector<Control*>* controls);
	 bool canGetFocus();
};

void TextBox::setText(wstring value) {
	this->_text = value;
}

wstring TextBox::getText() const {
	return this->_text;
}