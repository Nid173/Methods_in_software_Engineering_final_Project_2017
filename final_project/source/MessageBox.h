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
	inline void setText(wstring in);
	inline virtual void draw(Graphics& g, int x, int y, size_t layer);
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
  void Messagebox::setText(wstring in) {
	  _message = in;
  }

  void Messagebox::draw(Graphics& g, int x, int y, size_t layer) {
	  if (layer == getLayer()) {
		  if (getVisibilty()) {
			  g.setBackground(this->getBackground());
			  g.setForeground(this->getForeground());
			  g.write(x + getLeft() + 1, getTop() + y + 1, _message + wstring(getWidth() - _message.size(), ' '));
			  for (int i = _controls.size(); i > 0; i--) {
				  g.setBackground(_controls[i - 1]->getBackground());
				  g.setForeground(_controls[i - 1]->getForeground());
				  this->_controls[i - 1]->draw(g, x + getLeft(), y + getTop(), _controls[i - 1]->getLayer());
			  }
			  g.setBackground(getBackground());
			  g.setForeground(getForeground());
			  Control::draw(g, x, y, layer);
		  }
	  }
  }