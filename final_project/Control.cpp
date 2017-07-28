#include "stdafx.h"
#include "Control.h"


Control::Control()
{

}


Control::~Control()
{
}

void Control:: draw(Graphics& g, int x, int y, size_t z) const {
	if (z > _layer) return;
	_borderDrawer->draw(g, _left + x, _top + y, _width, _height);
}

void Control::SetVisibility(bool visibility) {
	_graphics.setCursorVisibility(visibility);
}

void Control::SetForeground(ForegroundColor color) {
	//_graphics.setForeground(Color);
	
}

void Control::SetBackground(BackgroundColor color) {
	//this->_background = color;

}

void Control::SetBorder(BorderType border) {

	
}