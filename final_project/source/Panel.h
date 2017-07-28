#pragma once
#include "Control.h"
#include <vector>

class Panel : public Control{
protected:
	vector<Control*> _controls;

public:
	Panel(int height=20,int width=20);
	~Panel() {}
	void AddControl(Control &control,short x,short y);
	//inline vector<Control*>& getControls

	/* Control Methods*/
	void draw(Graphics& g, int x, int y, size_t layer)const;
	virtual void getAllControls(vector<Control*>* controls);
};

