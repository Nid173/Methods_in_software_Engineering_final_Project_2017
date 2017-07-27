#pragma once
#include "CheckList.h"

class RadioBox : public CheckList {
protected:

	vector<string> _entries;
	size_t _index;

public:
	RadioBox(int width, int height, vector<string> entries);
	~RadioBox() {}
	size_t GetSelectedIndex();
	void SetSelectedIndex(size_t index);

};