#pragma once
#include "Control.h"

class Panel : public Control {
protected:
	int _width;
	int _height; 
	Control *control;

public:
	Panel(int height,int width);
	~Panel() {}
	void AddControl(Control &control);

};