#include "stdafx.h"
#include "RadioBox.h"
#include "Button.h"


RadioBox::RadioBox(int width, int height, vector<string> entries){
	_width = width;
	_height = height;
	_entries = entries;
	int size = 0;
	size = entries.size();
	wstring stemp;
	Panel box(5, 10);
	//Button* list=new Button(size);
	Button list(4);
	list.setBorder(BorderType::Single);
	for (int i = 0; i < size; i++) {
		stemp = s2ws(entries[i]);
		list.setText(stemp);
		//list[i].setTop(this->_top);
		//list[i].setLeft(this->_left + _width + 1);
		//plus.addListener(listener);
		box.AddControl(list, i*height, 0);
	}

}

size_t RadioBox::GetSelectedIndex() {
	return index;

}

void RadioBox::SetSelectedIndex(size_t index) {
	//turn off back ground for this->index
	this->index = index;
	//turn on back ground for this->index
}

void RadioBox::click(size_t index) {
	SetSelectedIndex(index);
}