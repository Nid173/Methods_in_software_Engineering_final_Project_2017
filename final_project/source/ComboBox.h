#pragma once
#include "Panel.h"

class ComboBox : public Panel {
protected:
	vector<string> _entries;
	size_t _index;

public:
	ComboBox(int width, vector<string> entries);
	~ComboBox() {}
	size_t GetSelectedIndex();
	void SetSelectedIndex(size_t index);
	void clickonmain(size_t index);
	void clickonchoice(size_t index);
};