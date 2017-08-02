#pragma once
#include "Button.h"

/*
struct MouseListener
{
	virtual void MousePressed(Control &control, int x, int y, bool isLeft) = 0;
};
*/


class Focuslist : public Button {

public:
	Focuslist(int width);
	virtual bool canGetFocus() { return true; }
	virtual string className() { return "Focuslist"; }

};

