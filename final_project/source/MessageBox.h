#pragma once
#include "Panel.h"

class Ok :public MouseListener {
public:
	virtual void draw(Control &control, int	x, int y, bool isleft) {

	}
};

class Messagebox : public Panel {

public:
	Messagebox(wstring error);
};

