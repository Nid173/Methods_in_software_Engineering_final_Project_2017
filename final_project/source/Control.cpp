#include "stdafx.h"
#include "Control.h"


Control::Control()
{
	this->setForeground(Color::White);
	this->setBackground(Color::Black);
	_layer = 0;
	setBorderDrawer(SimpleBorderFactory::instance().getNull());
}
 

Control::~Control()
{
}

void Control:: setFocus(Control& control) {
	if (control.canGetFocus()) {
		Focused::instance()->setFocus(control);
		if (Focused::instance()->getGraph()) {
			Focused::instance()->getGraph()->setCursorVisibility(true);
			Focused::instance()->getGraph()->moveTo(control._cursorPosition , control.getTop() + control.getHeight() - 1);
		}
	}
}


 Control* Control:: getFocus() {
	 return Focused::instance()->getfocus();
}
bool Control::canGetFocus() {
	return false;
}

void Control:: draw(Graphics& g, int x, int y, size_t z) const {
	if (z > _layer) return;
	_borderDrawer->draw(g, _left + x, _top + y, _width, _height);
}

void Control::setVisibility(bool visibility) {
	
}

void Control::setForeground(Color color) {
	this->_forgroundcolor = color;
}

void Control::setBackground(Color color) {
	this->_backgroundcolor = color;
}

void Control::setBorder(BorderType border) {
	if (border == BorderType::Single) {
		setBorderDrawer(SimpleBorderFactory::instance().getSingle());
	}
	else if (border == BorderType::Double) {
		setBorderDrawer(SimpleBorderFactory::instance().getDouble());
	}
	else {
		setBorderDrawer(SimpleBorderFactory::instance().getNull());
	}

}
