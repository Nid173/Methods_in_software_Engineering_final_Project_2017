#pragma once
#include "Panel.h"

class RadioBox : public Panel {
protected:
	int _width;
	int _height;
	vector<string> _entries;
	size_t _index;

public:
	RadioBox(int width, int _height, vector<string> entries);
	~RadioBox() {}
	size_t GetSelectedIndex();
	void SetSelectedIndex(size_t index);

};