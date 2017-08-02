#pragma once
#include "CheckList.h"


class RadioBox : public CheckList {
	size_t _index;
public:
	RadioBox(int width, int height, vector<string> entries);
	~RadioBox() {}
	virtual string className() { return "RadioBox"; }
	virtual void click(size_t index);
	size_t GetSelectedIndex();
	void SetSelectedIndex(size_t index);
};
