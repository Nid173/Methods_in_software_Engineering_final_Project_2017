#include "stdafx.h"
#include "Panel.h"

void Panel::AddControl(Control &control,short x,short y) {
	control.setTop(y);
	control.setLeft(x);
	_controls.push_back(&control);

}

Panel::Panel(int height, int width) {
	this->_height = height;
	this->_width = width;
	_top = 0;
	_left = 0;
}

void Panel::getAllControls(vector<Control*>* controls ) {
	/*
	for (int i = 0; i < controls->size(); i++) {
		Control *ctmp;
		ctmp = controls->at(i);
		
	}*/
}

void Panel::draw(Graphics& g, int x, int y, size_t layer)const {
	if (layer == getLayer()) {
		Control::draw(g, _left, _top, layer);
		for (int i = 0; i < _controls.size(); i++) {
			g.setBackground(_controls[i]->getBackground());
			g.setForeground(_controls[i]->getForeground());
			_controls[i]->draw(g, _controls[i]->getLeft(), _controls[i]->getTop(), _controls[i]->getLayer());
		}
	}
	else if (layer == getLayer() + 1 && this == getFocus()) {
		Control::draw(g, x, y, layer);
		g.setCursorVisibility(true);
		//g.moveTo(getLeft() + x + _cursorPosition, getTop() + y);
		g.moveTo(getLeft() + x, getTop() + y);

	}

}