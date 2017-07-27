#pragma once
#include "Control.h"
#include <vector>

class Panel : public Control {
protected:
	vector<Control> controls;

public:
	Panel(int height=20,int width=20);
	~Panel() {}
	void AddControl(Control &control,short x,short y);

	/* Control Methods*/
	void mousePressed(int x, int y, bool isLeft);
	void keyDown(int keyCode, char charecter);
	short getLeft();
	short getTop();
	void getAllControls(vector<Control*>* controls);
	bool canGetFocus();

};

