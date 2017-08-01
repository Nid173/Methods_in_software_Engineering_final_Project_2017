#include "stdafx.h"
#include "TextBox.h"

TextBox::TextBox(int width) {
	_width = width;
	_height = 2;
	_top = 0;
	_left = 0;
	_layer = 0;
	_cursorPosition = 0;
}


void TextBox::mousePressed(int x, int y, bool isLeft) {
	Control::getFocus()->restCursor();
	Control::setFocus(*this);
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
			if(_text.size()!=0)
				_text.pop_back();
		}
		if (_cursorPosition > _left+1)
			Focused::instance()->getGraph()->moveTo(_cursorPosition--, _pos.dwCursorPosition.Y);
		else
			Focused::instance()->getGraph()->moveTo(_cursorPosition, _pos.dwCursorPosition.Y);
	}
	else {
		if (_cursorPosition < _left + getWidth()) {
			char temp[1];
			temp[0] = charecter;
			if (_text.size() == 0) {
				_text = (temp[0], temp[0]);
			}
			else
				_text += (temp[0], temp[0]);
			_cursorPosition++;
		}
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