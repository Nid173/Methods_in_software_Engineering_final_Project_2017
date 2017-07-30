#include "stdafx.h"
#include "TextBox.h"

TextBox::TextBox(int width) {
	_width = width;
	_height = 2;
	_top = 0;
	_left = 0;
	_cursorPosition = 0;
}


void TextBox::mousePressed(int x, int y, bool isLeft) {
	Focused::instance()->getGraph()->setCursorVisibility(true);
	if (x<_text.size() && x>_left) {
		Focused::instance()->getGraph()->moveTo(x, _top+1);
		_cursorPosition = x;
	}
	else if (x > _text.size()) {
		Focused::instance()->getGraph()->moveTo(_text.size()+_left+1, _top+1);
		_cursorPosition = _text.size()+_left+1;
	}
	else {
		Focused::instance()->getGraph()->moveTo(_left+1, _top + 1);
		_cursorPosition = _left + 1;
	}

}
void TextBox::keyDown(int keyCode, char charecter) {
	auto _pos = Focused::instance()->getGraph()->getInfo();
	this->_cursorPosition = _pos.dwCursorPosition.X;

	if (keyCode == VK_LEFT) {
		if (_pos.dwCursorPosition.X > this->getLeft()+1) {
			this->_cursorPosition--;
			Focused::instance()->getGraph()->moveTo(_cursorPosition, _pos.dwCursorPosition.Y);
		}
	}
	else if (keyCode == VK_RIGHT) {
		if (_pos.dwCursorPosition.X <= _text.size()+_left)
			this->_cursorPosition++;
			Focused::instance()->getGraph()->moveTo(_cursorPosition, _pos.dwCursorPosition.Y);
	}
	else if (keyCode== VK_BACK) {
		if (_pos.dwCursorPosition.X == this->getText().size()+_left+1) {
			 this->getText().pop_back();
			 this->_cursorPosition--;
		}
		Focused::instance()->getGraph()->moveTo(_cursorPosition, _pos.dwCursorPosition.Y);
	}
}

bool TextBox::canGetFocus() {
	return true;
}

void TextBox::draw(Graphics& g, int x, int y, size_t layer)const {
	if (layer == getLayer()) {
		Control::draw(g, x , y , layer);
		g.write(x+getLeft()+1, getTop() + y+1,_text + wstring(getWidth() - _text.size(), ' '));
	}
	//Control::setFocus(*(Control::getFocus()));
	/*else if (layer == getLayer() + 1 && this == getFocus()) {
		Control::draw(g, x, y, layer);
		g.setCursorVisibility(true);
		g.moveTo( x + _cursorPosition, getTop() + y);
		//g.moveTo(getLeft() + x , getTop() + y);	

	}*/

}