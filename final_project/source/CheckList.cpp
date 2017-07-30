#include "stdafx.h"
#include "CheckList.h"

CheckList::CheckList(int width, int height, vector<string> entries) {
	_width = width;
	_height = height;
	_entries = entries;

}

void CheckList::SelectedIndex(size_t index) {
	this->_index = index;

}

void CheckList::DeSelectedIndex(size_t index) {
	this->_index = index;

}