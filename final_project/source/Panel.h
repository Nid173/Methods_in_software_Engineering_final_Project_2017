#pragma once
#include "Button.h"
#include <typeinfo>
#include <vector>

class Panel : public Control{
protected:
	vector<Control*> _controls;

public:
	Panel(int height=20,int width=20);
	~Panel() {}
	void AddControl(Control &control, int x, int y);
	//inline vector<Control*>& getControls

	/* Control Methods*/
	void draw(Graphics& g, int x, int y, size_t layer)const;
	virtual void getAllControls(vector<Control*>* controls);
	virtual bool canGetFocus();
	virtual void mousePressed(int x, int y, bool isLeft);

};

