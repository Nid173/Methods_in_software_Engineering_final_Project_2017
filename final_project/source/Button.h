#pragma once
#include "Label.h"


struct MouseListener
{
	virtual void MousePressed(Control &control, int x, int y, bool isLeft) = 0;
};


class Button : public Label{
private:

public:
	Button(int width);
	void addListener(MouseListener &listener);
	virtual bool canGetFocus() { return false; }
};