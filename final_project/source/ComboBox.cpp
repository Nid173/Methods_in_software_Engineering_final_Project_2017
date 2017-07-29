#include "stdafx.h"
#include "ComboBox.h"



ComboBox::ComboBox(int width, vector<string> entries){
	this->_entries = entries;
	this->_width = width;

}

size_t ComboBox::GetSelectedIndex() {
	return this->_index;

}

void ComboBox::SetSelectedIndex(size_t index) {
	this->_index = index;

}