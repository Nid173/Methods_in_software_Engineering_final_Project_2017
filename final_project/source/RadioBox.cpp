#include "stdafx.h"
#include "RadioBox.h"
#include "Button.h"

RadioBox::RadioBox(int width, int height, vector<string> entries) :CheckList(width,height,entries),_index(-1){}



size_t RadioBox::GetSelectedIndex() {
	return _index;

}

void RadioBox::SetSelectedIndex(size_t index) {
	//turn off back ground for this->index
	if(index!=-1)
	_controls[index]->setBackground(Color::White);
	this->_index = index;
	//turn on back ground for this->index
	_controls[index]->setBackground(Color::Green);
}

void RadioBox::click(size_t index) {
	SetSelectedIndex(index);
}