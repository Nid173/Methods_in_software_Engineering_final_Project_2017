#pragma once
#include "Label.h"


struct MouseListener
{
	virtual void MousePressed(Control &control, int x, int y, bool isLeft) = 0;
};


class Button : public Label{

public:
	Button(int width);

	inline void setText(string value);

	void addListener(MouseListener &listener);


};