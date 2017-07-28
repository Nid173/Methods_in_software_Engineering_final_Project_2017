#pragma once
#include "Panel.h"

class CheckList : public Panel {
protected:
	vector<string> _entries;
	size_t _index;

public:
	CheckList(int width, int height, vector<string> entries);
	~CheckList() {}
	CheckList() {}
	void SelectedIndex(size_t index);
	void DeSelectedIndex(size_t index);

};