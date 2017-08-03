#include "stdafx.h"
#include "MessageBox.h"

Messagebox::Messagebox(int width, int height, wstring error):Panel(height+3,width) {

	_layer = 1;
	if (error.size() > width) {
		_width = error.size();
	}
	if (width < 20) 
		_width = 20;

	this->setBorder(BorderType::Single);
	this->setBackground(Color::White);
	this->setForeground(Color::Black);


	Button* ok = new Button(7);
	ok->setText(L"OK");
	ok->setBackground(Color::Blue);
	ok->setForeground(Color::Green);
	ok->setBorder(BorderType::Single);
	_controls.push_back(ok);
	

	Button* cancel = new Button(7);
	cancel->setText(L"cancel");
	cancel->setBackground(Color::Blue);
	cancel->setForeground(Color::Red);
	cancel->setBorder(BorderType::Single);
	_controls.push_back(cancel);

	_message = error;
	value = false;
}

void Messagebox:: mousePressed(int x, int y, bool isLeft) {
	value=false;
	if (isInside(x, y, _controls[0]->getLeft(), _controls[0]->getTop(), _controls[0]->getWidth(), _controls[0]->getHeight())) 
		this->value = true;
}

void Messagebox::draw(Graphics& g, int x, int y, size_t layer) {
	if (layer == getLayer()) {
		if (getVisibilty()) {
			g.setBackground(this->getBackground());
			g.setForeground(this->getForeground());

			for (int i = 0; i < _height; i++) {
				g.write(x + getLeft(), y + getTop() + i, wstring(getWidth() + 1, ' '));
			}
			int j = 0;
			for (int i = 0; i < _message.size(); i++) {
				int z = 0;
				wstring temp;
				while (_message[i] != '\n' && i < _message.size()) {
					temp += _message[i];
					i++;
				}
				z = i;
				g.write(x + getLeft() + 1, getTop() + y + j + 1, L" " + temp + wstring(getWidth() - temp.size(), ' '));
				j += 1;
			}
			for (int i = _controls.size(); i > 0; i--) {
				g.setBackground(_controls[i - 1]->getBackground());
				g.setForeground(_controls[i - 1]->getForeground());
				this->_controls[i - 1]->draw(g, x + getLeft(), y + getTop(), _controls[i - 1]->getLayer());
			}
			g.setBackground(getBackground());
			g.setForeground(getForeground());
			Control::draw(g, x, y, layer);
		}
	}
}