#pragma once
#include "Control.h"
#include <vector>

class Panel : public Control {
protected:
	vector<Control*> _controls;

public:
	Panel(int height=20,int width=20);
	~Panel() {}
	void AddControl(Control &control,short x,short y);

	/* Control Methods*/
	void draw(Graphics& g, int x, int y, size_t layer)const;
	void mousePressed(int x, int y, bool isLeft);
	void keyDown(int keyCode, char charecter);
	void getAllControls(vector<Control*>* controls);
	bool canGetFocus();

};

