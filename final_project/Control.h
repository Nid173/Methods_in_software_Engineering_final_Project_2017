#pragma once

#include "Graphics.h"
#include <vector>

using namespace std;

class Control :public Graphics
{
protected:
	short _left;
	short _top;
	int _width;
	int _height;
	size_t _layer;

private:
	const BorderDrawer *_borderDrawer;

public:
	Control();
	inline size_t getLayer() const;
	inline void setLayer(size_t layer);
	inline int getWidth()const;
	static Control* getFocus() { return NULL; };
	static void setFocus(Control& control) {};

	virtual void draw(Graphics& g, int x, int y, size_t z)const;
	virtual void mousePressed(int x, int y, bool isLeft) {};
	virtual void keyDown(int keyCode, char charecter) {};
	inline virtual short getLeft()const;
	inline virtual short getTop()const;
	virtual void getAllControls(vector<Control*>* controls) {};
	virtual bool canGetFocus() { return FALSE; };
	~Control();
};

/* 
 * Inline Methods 
 * "More Faster and much effective" 
 */

 size_t Control:: getLayer() const {
	 return _layer;
}
 void Control:: setLayer(size_t layer) {
	 this->_layer = layer;
}

 int Control::getWidth() const {
	 return _width;
 }

 short Control:: getLeft()const {
	 return _left;
 }
 short Control:: getTop()const {
	 return _top;
 }
 /**************************************************************/
struct BorderDrawer {
	virtual void draw(Graphics &g, short left, short top, int width, int height) const = 0;
};

class SingleBorderDrawer : public BorderDrawer {
	virtual void draw(Graphics &g, short left, short top, int width, int height) const { }
};

class NullBorderDrawer : public BorderDrawer {
	virtual void draw(Graphics &g, short left, short top, int width, int height) const { }
};

class DoubleBorderDrawer : public BorderDrawer {
	virtual void draw(Graphics &g, short left, short top, int width, int height) const { }
};