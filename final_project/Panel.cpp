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


void Panel::mousePressed(int x, int y, bool isLeft) {

}
void Panel::keyDown(int keyCode, char charecter) {

}

void Panel::getAllControls(vector<Control*>& controls) {
	int i = this->_controls.size();
	for (int j = 0; j < i; j++) {
		controls.push_back(this->_controls[j]);
	}
}
bool Panel::canGetFocus() {
	return false;
}


void Panel::draw(Graphics& g, int x, int y, size_t layer)const {
	if (layer == getLayer()) {
		Control::draw(g, _left, _top, layer);
	}
	else if (layer == getLayer() + 1 && this == getFocus()) {
		Control::draw(g, x, y, layer);
		g.setCursorVisibility(true);
		//g.moveTo(getLeft() + x + _cursorPosition, getTop() + y);
		g.moveTo(getLeft() + x, getTop() + y);

	}

}