#pragma once
#include "RadioBox.h"

class CheckList : public Panel {
protected:
	int _width;
	int _height;
	vector<string> _entries;
	size_t _index;

public:
	CheckList(int width, int _height, vector<string> entries);
	~CheckList() {}
	void SelectedIndex(size_t index);
	void DeSelectedIndex(size_t index);

};