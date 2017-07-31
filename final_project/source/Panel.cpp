#include "stdafx.h"
#include "Panel.h"

void Panel::AddControl(Control &control, int x, int y) {
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
	for (int i = _controls.size();i>0 ; i--) {
		controls->push_back(_controls[i-1]);
	}
}

void Panel::mousePressed(int x, int y, bool isLeft) {
	Button* tmp;
	for (int i = 0; i < _controls.size(); i++) {
		if(isInside(x, y, _controls[i]->getLeft(), _controls[i]->getTop(), _controls[i]->getWidth(), 2)){
			if (tmp = static_cast<Button*>(_controls[i])) {
				tmp->getListener().MousePressed(*this, x, y, isLeft);
			}
	//		if(static_cast)
			_controls[i]->mousePressed(x, y, isLeft);
			break;
		}
	}
}


void Panel::draw(Graphics& g, int x, int y, size_t layer)const {
	if (layer == getLayer()) {
		Control::draw(g, x, y, layer);
		g.setBackground(getBackground());
		g.setForeground(getForeground());
		for (int i = 0; i < _controls.size(); i++) {
			g.setBackground(_controls[i]->getBackground());
			g.setForeground(_controls[i]->getForeground());
			_controls[i]->draw(g, x+getLeft() ,y+ getTop() , _controls[i]->getLayer());
		}
	}
	else if (layer == getLayer() + 1 && this == getFocus()) {
		Control::draw(g, x, y, layer);
		g.setCursorVisibility(true);
		//g.moveTo(getLeft() + x + _cursorPosition, getTop() + y);
		g.moveTo(getLeft() + x, getTop() + y);

	}
	g.setBackground(getBackground());
	g.setForeground(getForeground());

}

bool Panel::canGetFocus() {
	return false;
}
