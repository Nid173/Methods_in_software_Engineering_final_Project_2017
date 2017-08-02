#include"stdafx.h"
#include "MessageBox.h"

Messagebox::Messagebox(int width, int height, wstring error):Panel(height+3,width) {

	_layer = 1;
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

void Messagebox::draw(Graphics& g, int x, int y, size_t layer) {
	if (layer == getLayer()) {
		if (getVisibilty()) {
			g.setBackground(this->getBackground());
			g.setForeground(this->getForeground());
			g.write(x + getLeft() + 1, getTop() + y + 1, _message + wstring(getWidth() - _message.size(), ' '));
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