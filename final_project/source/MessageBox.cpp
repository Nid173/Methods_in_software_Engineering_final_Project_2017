#include"stdafx.h"
#include "MessageBox.h"

Messagebox::Messagebox(string error) {
	this->setBorder(BorderType::Single);
	this->setForeground(Color::White);
	Button* ok = new Button(7);
	ok->setText(L"OK");
	ok->setTop(_height-3);
	ok->setLeft(2);
	ok->setForeground(Color::Green);
	ok->setBorder(BorderType::Single);
	_controls.push_back(ok);
	Button* cancel = new Button(7);
	cancel->setText(L"cancel");
	cancel->setTop(7);
	cancel->setLeft(12);
	cancel->setForeground(Color::Red);
	cancel->setBorder(BorderType::Single);
	_controls.push_back(cancel);
}