#include "stdafx.h"
#include "TextBox.h"

TextBox::TextBox(int width) {
	_width = width;
}


void TextBox::mousePressed(int x, int y, bool isLeft) {

}
void TextBox::keyDown(int keyCode, char charecter) {

}

void TextBox::getAllControls(vector<Control*>* controls) {

}
bool TextBox::canGetFocus() {
	return false;
}
void TextBox::draw(Graphics& g, int x, int y, size_t layer)const {
	if (layer == getLayer()) {
		Control::draw(g, _left, _top, layer);
		g.write(getLeft() + x, getTop() + y,_text + wstring(getWidth() - _text.size(), ' '));
	}
	else if (layer == getLayer() + 1 && this == getFocus()) {
		Control::draw(g, x, y, layer);
		g.setCursorVisibility(true);
		//g.moveTo(getLeft() + x + _cursorPosition, getTop() + y);
		g.moveTo(getLeft() + x , getTop() + y);

	}

}