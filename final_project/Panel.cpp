#include "stdafx.h"
#include "Panel.h"

void Panel::AddControl(Control &control,short x,short y) {
	control.setTop(y);
	control.setLeft(x);
	controls.push_back(control);

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

void Panel::getAllControls(vector<Control*>* controls) {

}
bool Panel::canGetFocus() {
	return false;
}