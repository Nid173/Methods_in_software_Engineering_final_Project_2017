#pragma once
#include "Control.h"

class TextBox : public Control {
protected:
	wstring _text;
	//int _cursorPosition;
public:
	TextBox(int width);
	~TextBox() {}
	inline void setText(wstring value);
	inline wstring getText() const;
	//inline int cursorPosition();
	virtual void restCursor() {_cursorPosition = _text.size() + this->getLeft() + 2;}


	/* Control Methods*/
	virtual void draw(Graphics& g, int x, int y, size_t z)const;
	 virtual void mousePressed(int x, int y, bool isLeft);
	 void keyDown(int keyCode, char charecter);
	 virtual bool canGetFocus();
};

void TextBox::setText(wstring value) {
	this->_text = value;
	_cursorPosition = _text.size() + this->getLeft()+2 ;
}

wstring TextBox::getText() const {
	return this->_text;
}
/*
int TextBox:: cursorPosition() {
	return _cursorPosition;
}*/