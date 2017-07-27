#pragma once
#include "Control.h"
#include <vector>

class Panel : public Control {
protected:

	Control *control;

public:
	Panel(int height,int width);
	~Panel() {}
	void AddControl(Control &control);

	/* Control Methods*/
	void mousePressed(int x, int y, bool isLeft);
	void keyDown(int keyCode, char charecter);
	short getLeft();
	short getTop();
	void getAllControls(vector<Control*>* controls);
	bool canGetFocus();

};

