#include "stdafx.h"
#include "Control.h"


Control::Control()
{
	this->setForeground(Color::White);
	this->setBackground(Color::Black);
}


Control::~Control()
{
}

void Control:: draw(Graphics& g, int x, int y, size_t z) const {
	if (z > _layer) return;
	_borderDrawer->draw(g, _left + x, _top + y, _width, _height);
}

void Control::setVisibility(bool visibility) {
	//_graphics.setCursorVisibility(visibility);
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

/**************************************************************/
/* Drawer Functions */

void SingleBorderDrawer:: draw(Graphics &g, short left, short top, int width, int height) const {

	char box[6] = { '\xDA','\xC4', '\xBF','\xB3','\xc0','\xd9' };
	string s;
	s.push_back(box[0]);
	g.write(left, top, s);
	short i;

	s.pop_back();
	s.push_back(box[1]);
	for (i = 1; i <= width; i++) {
		g.write(left + i, top, s);
	}

	s.pop_back();
	s.push_back(box[2]);
	g.write(left + i, top, s);

	s.pop_back();
	s.push_back(box[3]);

	for (i = 1; i < height; i++) {
		g.write(left, top + i, s);
		g.write(left + width + 1, top + i, s);
	}

	s.pop_back();
	s.push_back(box[4]);
	g.write(left, top + i, s);

	s.pop_back();
	s.push_back(box[1]);
	for (i = 1; i <= width; i++) {
		g.write(left + i, top + height, s);
	}

	s.pop_back();
	s.push_back(box[5]);
	g.write(left + i, top + height, s);

}

void DoubleBorderDrawer::draw(Graphics &g, short left, short top, int width, int height) const {
	char box[6] = { '\xC9','\xCD', '\xBB','\xBA','\xC8','\xBC' };
	string s;
	s.push_back(box[0]);
	g.write(left, top, s);
	short i;

	s.pop_back();
	s.push_back(box[1]);
	for (i = 1; i <= width; i++) {
		g.write(left + i, top, s);
	}

	s.pop_back();
	s.push_back(box[2]);
	g.write(left + i, top, s);

	s.pop_back();
	s.push_back(box[3]);

	for (i = 1; i < height; i++) {
		g.write(left, top + i, s);
		g.write(left + width + 1, top + i, s);
	}

	s.pop_back();
	s.push_back(box[4]);
	g.write(left, top + i, s);

	s.pop_back();
	s.push_back(box[1]);
	for (i = 1; i <= width; i++) {
		g.write(left + i, top + height, s);
	}

	s.pop_back();
	s.push_back(box[5]);
	g.write(left + i, top + height, s);

}