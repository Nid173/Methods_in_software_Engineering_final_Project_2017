#include"stdafx.h"
#include "MessageBox.h"

Messagebox::Messagebox(int width, int height, wstring error):Panel(height+3,width) {

	if (width <= 20) 
		_width = 20;

	this->setBorder(BorderType::Single);
	this->setBackground(Color::White);
	this->setForeground(Color::Black);


	Button* ok = new Button(7);
	ok->setText(L"OK");
	this->setBackground(Color::White);
	ok->setForeground(Color::Green);
	ok->setBorder(BorderType::Single);
	_controls.push_back(ok);
	

	Button* cancel = new Button(7);
	cancel->setText(L"cancel");
	this->setBackground(Color::White);
	cancel->setForeground(Color::Red);
	cancel->setBorder(BorderType::Single);
	_controls.push_back(cancel);

	_message = error;
}
