#pragma once
#include "Panel.h"

class ComboBox : public Panel {
protected:
	vector<string> _entries;
	size_t _index;

public:
	ComboBox(int width, vector<string> entries);
	~ComboBox() {}
	size_t GetSelectedIndex();
	void SetSelectedIndex(size_t index);
	virtual bool canGetFocus() { return true; }
	virtual string className() { return "ComboBox"; }
	inline virtual void setLeft(int left);
	inline virtual void setTop(int top);
	inline virtual void setBorder(BorderType border);
	virtual void mousePressed(int x, int y, bool isLeft);
	void clickonmain(size_t index);
	void clickonchoice(size_t index);
};

void ComboBox::setBorder(BorderType border) {

		setBorderDrawer(SimpleBorderFactory::instance().getNull());

		if (border == BorderType::Single)
			_controls[0]->setBorder(BorderType::Single);
		else if (border == BorderType::Double)
			_controls[0]->setBorder(BorderType::Double);
		else
			_controls[0]->setBorder(BorderType::None);

}
void ComboBox::setLeft(int left) {
	_left = left;
	for (int i = 0; i < _controls.size(); i++) {
		_controls[i]->setLeft(0);
	}

}

void ComboBox::setTop(int top) {
	_top = top;
	for (int i = 0; i < _controls.size(); i++) {
		if (i == 0) {
			_controls[i]->setTop(0);
		}
		else {
			_controls[i]->setTop(_controls[i - 1]->getHeight() + _controls[i - 1]->getTop());
		}
	}

}


class ComboBox_button :public MouseListener {
public:
	ComboBox_button() {}
	virtual void MousePressed(Control &control, int x, int y, bool isLeft) {
		ComboBox * tmp = static_cast<ComboBox*>(&control);
		if(x==0)
		tmp->clickonmain(x);
		else
		tmp->clickonchoice(x);
	}
};
