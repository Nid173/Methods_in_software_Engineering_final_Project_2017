#include "stdafx.h"
#include "Control.h"


Control::Control()
{
	this->setForeground(Color::White);
	this->setBackground(Color::Black);
	_layer = 1;
	_borderDrawer = new NullBorderDrawer;
}


Control::~Control()
{
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
		this->_borderDrawer = new SingleBorderDrawer;
	}
	else if (border == BorderType::Double) {
		this->_borderDrawer = new DoubleBorderDrawer;
	}
	else {
		this->_borderDrawer = new NullBorderDrawer;
	}

}
