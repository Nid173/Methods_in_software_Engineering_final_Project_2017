#pragma once
#include "Panel.h"

class ComboBox : public Panel {
protected:
	int _width;
	vector<string> _entries;
	size_t _index;

public:
	ComboBox(int width, vector<string> entries);
	~ComboBox() {}
	size_t GetSelectedIndex();
	void SetSelectedIndex(size_t index);

};