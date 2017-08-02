#pragma once
#include "Panel.h"


class Messagebox : public Panel {
	wstring _message;

public:
	Messagebox(int width,int height ,wstring error);
	inline void setOkListener(MouseListener& ok);
	inline void setCancelListener(MouseListener& cancel);
	inline virtual void setTop(int top);
	inline  virtual void setLeft(int left);

};

void Messagebox::setOkListener(MouseListener& ok) {
	Button* b = static_cast<Button*>(_controls[0]);
	b->addListener(ok);
 }
void Messagebox::setCancelListener(MouseListener& cancel) {
	Button* b = static_cast<Button*>(_controls[1]);
	b->addListener(cancel);

 }

void Messagebox:: setTop(int top) {
	_top = top;
	_controls[0]->setTop(top+_height-1);
	_controls[1]->setTop(top + _height - 1);
  }
  void Messagebox::setLeft(int left) {
	  _left = left;
	  _controls[0]->setLeft(left + 2);
	  _controls[1]->setLeft(left + _width - 2);
  }
