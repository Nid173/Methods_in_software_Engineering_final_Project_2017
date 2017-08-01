#pragma once
#include "Button.h"

/*
struct MouseListener
{
	virtual void MousePressed(Control &control, int x, int y, bool isLeft) = 0;
};
*/


class Focuslist : public Button {
private:
	MouseListener* _listener;
public:
	Focuslist(int width);
	void addListener(MouseListener &listener);
	virtual bool canGetFocus() { return true; }
	virtual void mousePressed(int x, int y, bool isLeft);
	inline MouseListener& getListener();
	virtual string className() { return "Focuslist"; }

};

MouseListener& Focuslist::getListener() { 
	return *_listener;
}
