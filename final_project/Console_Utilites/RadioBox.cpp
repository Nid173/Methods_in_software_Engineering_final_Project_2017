#include "stdafx.h"
#include "RadioBox.h"


RadioBox::RadioBox(int width, int height, vector<string> entries){
	this->_width = width;
	this->_height = height;
	this->_entries = entries;
}

size_t RadioBox::GetSelectedIndex() {
	return this->_index;

}

void RadioBox::SetSelectedIndex(size_t index) {
	this->_index = index;

}