#include "stdafx.h"
#include "Button.h"

Button::Button(int width) :Label(width) {}

void Button:: addListener(MouseListener &listener) {
	_listener = &listener;
}

