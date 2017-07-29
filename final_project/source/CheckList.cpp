//#include "stdafx.h"
#include "CheckList.h"

CheckList::CheckList(int width, int height, vector<string> entries) {
	this->_width = width;
	this->_height = height;
	this->_entries = entries;

}

void CheckList::SelectedIndex(size_t index) {
	this->_index = index;

}

void CheckList::DeSelectedIndex(size_t index) {
	this->_index = index;

}