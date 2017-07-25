#pragma once
#include "Panel.h"

class NumericBox : public Panel {
protected:
	int _width;
	int _min;
	int _max;
	int _value;
public:
	NumericBox(int width, int min, int max);
	~NumericBox() {}
	bool setValue(int value);
	int GetValue();

};