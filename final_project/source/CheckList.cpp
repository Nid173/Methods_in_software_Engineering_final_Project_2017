#include "stdafx.h"
#include "CheckList.h"
#include "Button.h"
#include <string.h>

wstring CheckList::s2ws(const std::string& s)
{
	int len;
	int slength = (int)s.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
	wstring r(buf);
	delete[] buf;
	return r;
}

CheckList::CheckList(int width, int height, vector<string> entries) {
	_width = width;
	_height = height;
	_entries = entries;
	int size = 0;
	size= entries.size();
	wstring stemp;
	Panel box(5, 10);
	//Button* list=new Button(size);
	Button list(4);
	list.setBorder(BorderType::Single);
	for (int i = 0; i < size; i++){
		stemp = s2ws(entries[i]);
		list.setText(stemp);
		//list[i].setTop(this->_top);
		//list[i].setLeft(this->_left + _width + 1);
		//plus.addListener(listener);
		box.AddControl(list, i*height, 0);
	}


}

void CheckList::SelectedIndex(size_t index) {

	_index.push_back(index);
	//turn on background

}

void CheckList::DeSelectedIndex(size_t index) {
	
	for (int i = 0; i < _index.size(); i++) {
		if (_index[i] == index) {
			_index.erase(_index.begin() + i);
		//turn off backgound
		}

	}

}


void CheckList::mousePressed(int x, int y, bool isLeft) {
	x -= _left;
	y -= _top;
	for (int i = 0; i < _controls.size(); i++) {
		//int myx = _controls[i]->getLeft() + _controls[i]->getWidth();
		int myy = _controls[i]->getTop() + _controls[i]->getHeight();
		//int x_l = _controls[i]->getLeft();
		int y_l = _controls[i]->getTop();
		if ((y >= y_l && y <= myy) && (_controls[i]->className() == "Button")) {
			Button* tmp = static_cast<Button*>(_controls[i]);
			tmp->getListener().MousePressed(*this, x, y, isLeft);
		}
	}
}

void CheckList::click(size_t index) {

	for (int i = 0; i < _index.size(); i++) {

		if (_index[i] == index) 
			DeSelectedIndex(index);

		}

	SelectedIndex(index);
}