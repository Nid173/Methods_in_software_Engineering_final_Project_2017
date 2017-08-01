#include"stdafx.h"
#include "MessageBox.h"

Messagebox::Messagebox(wstring error) :Panel(10, 20) {

	this->setBorder(BorderType::Single);
	this->setForeground(Color::White);

	Label* message = new Label(15);
	message->setText(error);
	message->setHeight(5);
	message->setTop(1);
	message->setLeft(1);
	message->setForeground(Color::White);
	_controls.push_back(message);

	Button* ok = new Button(7);
	ok->setText(L"OK");
	ok->setTop(7);
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