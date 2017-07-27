#pragma once

#include "Graphics.h"
#include <vector>

using namespace std;



struct BorderDrawer {
	virtual void draw(Graphics &g, short left, short top, int width, int height) const = 0;
};

class SingleBorderDrawer : public BorderDrawer {
	virtual void draw(Graphics &g, short left, short top, int width, int height) const {
		
		char box[6] = {'\xDA','\xC4', '\xBF','\xB3','\xc0','\xd9' };
		char* c;

		//first button
		c = &box[0];
		g.write(left, top, c);
		short i;
		c = &box[1];
		for (i = 1; i <= width; i++) {
			g.write(left + i, top, c);
		}
		c = &box[2];
		g.write(c);

		c = &box[3];
		for (i = 1; i < height; i++) {
			g.write(left,top+i,c); 
			g.write(left + width + 1, top + i, c);
		}

		c = &box[4];
		g.write(left, top + i, c);

		c = &box[1];
		for (i = 0; i < width; i++) {
			g.write(left + i, top, c);
		}

		c = &box[5];
		g.write(c);
		//end first button
		//SetConsoleTextAttribute(g, FOREGROUND_GREEN | FOREGROUND_INTENSITY);

		//c = { left + 1,top + 1 };
		//SetConsoleCursorPosition(h, c);

	}
};

class NullBorderDrawer : public BorderDrawer {
	virtual void draw(Graphics &g, short left, short top, int width, int height) const { }
};

class DoubleBorderDrawer : public BorderDrawer {
	virtual void draw(Graphics &g, short left, short top, int width, int height) const { }
};

/**************************************************************/


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
	inline void setLeft(short left);
	inline void setTop(short top);
	static Control* getFocus() { return NULL; };
	static void setFocus(Control& control) {};

	virtual void draw(Graphics& g, int x, int y, size_t z)const;
	virtual void mousePressed(int x, int y, bool isLeft) {};
	virtual void keyDown(int keyCode, char charecter) {};
	inline virtual short getLeft()const;
	inline virtual short getTop()const;
	virtual void getAllControls(vector<Control*>* controls) {};
	virtual bool canGetFocus() { return FALSE; };

	virtual void setBorderDrawer(const BorderDrawer &borderDrawer)  {_borderDrawer = &borderDrawer;}
	~Control();
};

/* 
 * Inline Methods 
 * (More Faster and much effective). 
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

  void Control:: setTop(short top) {
	  _top = top;
 }
  void Control:: setLeft(short left) {
	  _left = left;
 }
 
