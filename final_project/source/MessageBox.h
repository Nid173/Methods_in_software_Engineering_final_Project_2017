#pragma once
#include "Panel.h"


class Messagebox : public Panel {
	wstring _message;

public:
	Messagebox(int width, int height, wstring error);
	inline void setOkListener(MouseListener& ok);
	inline void setCancelListener(MouseListener& cancel);
	inline virtual void setTop(int top);
	inline  virtual void setLeft(int left);
	inline void setText(wstring in);
	virtual void draw(Graphics& g, int x, int y, size_t layer);
};

void Messagebox::setOkListener(MouseListener& ok) {
	Button* b = static_cast<Button*>(_controls[0]);
	b->addListener(ok);
}
void Messagebox::setCancelListener(MouseListener& cancel) {
	Button* b = static_cast<Button*>(_controls[1]);
	b->addListener(cancel);

}

void Messagebox::setTop(int top) {
	_top = top;
	_controls[0]->setTop(_height - 3);
	_controls[1]->setTop(_height - 3);
}
void Messagebox::setLeft(int left) {
	_left = left;
	_controls[0]->setLeft(2);
	_controls[1]->setLeft(_width - 9);
}
void Messagebox::setText(wstring in) {
	_message = in;
}

