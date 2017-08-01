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

CheckList::CheckList(int width, int height, vector<string> entries) :Panel((height*entries.size()), width), _entries(entries){
	wstring stemp;

	for (int i = 0; i < entries.size(); i++) {
	Button* list = new Button(width);
	list->setHeight(height);
	list->setBackground(Color::White);
	list->setForeground(Color::Black);
		stemp = s2ws(entries[i]);
		list->setText(stemp);
		list->addListener(*new Choice_button);
		this->_controls.push_back(list);
	}


}

void CheckList::SelectedIndex(size_t index) {

	_index.push_back(index);
	//turn on background
	_controls[index]->setBackground(Color::Green);

}

void CheckList::DeSelectedIndex(size_t index) {
	
	for (int i = 0; i < _index.size(); i++) {
		if (_index[i] == index) {
			_index.erase(_index.begin() + i);
		//turn off backgound
			_controls[index]->setBackground(Color::White);
		}

	}

}


void CheckList::mousePressed(int x, int y, bool isLeft) {
	x -= _left;
	y -= _top;
	for (int i = 0; i < _controls.size(); i++) {
		int myy = _controls[i]->getTop() + _controls[i]->getHeight();
		int y_l = _controls[i]->getTop();
		if (y >= y_l && y <= myy) {
			Button* tmp = static_cast<Button*>(_controls[i]);
			tmp->getListener().MousePressed(*this, i, y, isLeft);
		}
	}
}

void CheckList::click(size_t index) {
	int lock = 0;

	for (int i = 0; i < _index.size(); i++) {
		if (_index[i] == index) {
			DeSelectedIndex(index);
			lock = 1;
		}
	}
	if(lock==0)
		SelectedIndex(index);
}