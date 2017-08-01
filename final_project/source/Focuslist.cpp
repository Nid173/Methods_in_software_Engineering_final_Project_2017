#include "stdafx.h"
#include "Focuslist.h"

Focuslist::Focuslist(int width) :Button(width) {}

void Focuslist::addListener(MouseListener &listener) {
	_listener = &listener;
}


void Focuslist::mousePressed(int x, int y, bool isLeft) {
	_listener->MousePressed(*this, x, y, isLeft);
}
