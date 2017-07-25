#include "stdafx.h"
#include "TextBox.h"

TextBox::TextBox(int width) :_width(width) {}


void TextBox::mousePressed(int x, int y, bool isLeft) {

}
void TextBox::keyDown(int keyCode, char charecter) {

}
short TextBox::getLeft() {
	return left;
}
short TextBox::getTop() {
	return top;
}
void TextBox::getAllControls(vector<Control*>* controls) {

}
bool TextBox::canGetFocus() {
	return false;
}