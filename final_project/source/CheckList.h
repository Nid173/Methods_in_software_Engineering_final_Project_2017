#pragma once
#include "Panel.h"

class CheckList : public Panel {
protected:
	vector<string> _entries;
	vector<size_t> _index;

public:
	CheckList(int width, int height, vector<string> entries);
	~CheckList() {}
	CheckList() {}
	void SelectedIndex(size_t index);
	void DeSelectedIndex(size_t index);
	wstring s2ws(const std::string& s);
	virtual bool canGetFocus() { return false; }
	virtual string className() { return "CheckList"; }
	inline virtual void setLeft(int left);
	inline virtual void setTop(int top);
	virtual void mousePressed(int x, int y, bool isLeft);
	virtual void keyDown(int keyCode, char charecter) ;
	virtual void restCursor();
	virtual void click(size_t index);
};


class Choice_button :public MouseListener {
public:
	Choice_button() {}
	virtual void MousePressed(Control &control, int x, int y, bool isLeft) {
		CheckList * tmp = static_cast<CheckList*>(&control);
		tmp->click(x);
	}
};
