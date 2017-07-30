#pragma once
#include "Panel.h"

class CheckList : public Panel {
protected:
	vector<string> _entries;
	vector<size_t> _index;

public:
	CheckList(int width, int height, vector<string> entries);
	~CheckList() {}
	CheckList() {}
	void SelectedIndex(size_t index);
	void DeSelectedIndex(size_t index);
	wstring s2ws(const std::string& s);
	void click(size_t index);

};