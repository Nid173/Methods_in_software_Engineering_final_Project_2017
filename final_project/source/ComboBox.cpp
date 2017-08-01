#include "stdafx.h"
#include "ComboBox.h"
#include "Button.h"
#include <string.h>

wstring s2ws(const std::string& s)
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

ComboBox::ComboBox(int width, vector<string> entries) :Panel((2*entries.size()), width), _entries(entries) {
	wstring stemp;
	Button* list = new Button(width);
	list->setHeight(2);
	list->setBackground(Color::Blue);
	list->setForeground(Color::White);
	list->setText(L"none");
	list->addListener(*new ComboBox_button);
	this->_controls.push_back(list);

	for (int i = 0; i < entries.size(); i++) {
		Button* list = new Button(width);
		list->setHeight(2);
		list->setBackground(Color::White);
		list->setForeground(Color::Black);
		stemp = s2ws(entries[i]);
		list->setText(stemp);
		list->addListener(*new ComboBox_button);
		//list->visabilty off
		this->_controls.push_back(list);
	}
	_cursorPosition = _controls[0]->getTop() + 1;


}

void ComboBox::SetSelectedIndex(size_t index) {
	this->_index = index-1;

	wstring stemp;
	stemp = s2ws(_entries[index - 1]);
	Button* tmp = static_cast<Button*>(_controls[index]);
	tmp->setText(stemp);

}
size_t ComboBox::GetSelectedIndex() {
	return this->_index;
}

void ComboBox::clickonmain(size_t index) {
	//turn off if on , turn on if off
	for (int i = 1; i <( _entries.size()+1); i++) {
		/*
		  if(_controls[i] is visable)
			_controls[index]->setvisabilty(off)
			else
				_controls[index]->setvisabilty(on)
		*/
	}

}

void ComboBox::clickonchoice(size_t index) {
	//turn visabilty off
	for (int i = 1; i < (_entries.size()+1); i++) {
		//_controls[index]->setvisabilty(off)
	}

	SetSelectedIndex(index);
}

void ComboBox::mousePressed(int x, int y, bool isLeft) {
	Control::setFocus(*this);
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