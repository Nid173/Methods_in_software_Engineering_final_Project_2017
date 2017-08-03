#include "stdafx.h"
#include "Panel.h"

void Panel::AddControl(Control &control, int x, int y) {
	control.setTop(y);
	control.setLeft(x);
	_controls.push_back(&control);
	_layer = 0;
}

Panel::Panel(int height, int width):Control() {
	this->_height = height;
	this->_width = width;
	_top = 0;
	_left = 0;
}

void Panel::getAllControls(vector<Control*>* controls ) {
	for (int i = 0; i < _controls.size(); i++) {
		controls->push_back(_controls[i]);
	}
}

void Panel::mousePressed(int x, int y, bool isLeft) {
	Button* tmp;
	TextBox* tempo;
	for (int i = 0; i < _controls.size(); i++) {
		if (isInside(x, y, _controls[i]->getLeft(), _controls[i]->getTop(), _controls[i]->getWidth(), _controls[i]->getHeight())) {
			if (_controls[i]->className() == "Button") {
				tmp = static_cast<Button*>(_controls[i]);
				tmp->getListener().MousePressed(*this, x, y, isLeft);
			}
			else
				_controls[i]->mousePressed(x, y, isLeft);
		}
	}
}


void Panel::draw(Graphics& g, int x, int y, size_t layer) {
	if (layer == getLayer()) {
		for (int i = _controls.size(); i > 0; i--) {
			g.setBackground(_controls[i-1]->getBackground());
			g.setForeground(_controls[i-1]->getForeground());
			this->_controls[i-1]->draw(g, x + getLeft(), y + getTop(), _controls[i-1]->getLayer());
		}
		g.setBackground(getBackground());
		g.setForeground(getForeground());
		Control::draw(g,x,y,layer);
	}
	else if (layer == getLayer() + 1 && this == getFocus()) {
		Control::draw(g, x, y, layer);
		g.setCursorVisibility(true);
		g.moveTo(getLeft() + x, getTop() + y);
	}
}

bool Panel::canGetFocus() {
	return false;
}