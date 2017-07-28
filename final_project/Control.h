#pragma once

#include "Graphics.h"
#include <vector>

using namespace std;

enum class ForegroundColor { Red, Blue, Green, Purple, Teal, Yellow, White, Black };
enum class BackgroundColor { Red, Blue, Green, Purple, Teal, Yellow, White, Black };
enum class BorderType { Single, Double, None };


struct BorderDrawer {
	virtual void draw(Graphics &g, short left, short top, int width, int height) const = 0;
};

class SingleBorderDrawer : public BorderDrawer {
	virtual void draw(Graphics &g, short left, short top, int width, int height) const {
		
		char box[6] = {'\xDA','\xC4', '\xBF','\xB3','\xc0','\xd9' };
		string s;
		s.push_back(box[0]);
		g.write(left, top, s);
		short i;

		s.pop_back();
		s.push_back(box[1]);
		for (i = 1; i <= width; i++) {
			g.write(left + i, top, s);
		}

		s.pop_back();
		s.push_back(box[2]);
		g.write(left+i,top,s);

		s.pop_back();
		s.push_back(box[3]);

		for (i = 1; i < height; i++) {
			g.write(left,top+i,s); 
			g.write(left + width + 1, top + i, s);
		}

		s.pop_back();
		s.push_back(box[4]);
		g.write(left, top + i, s);

		s.pop_back();
		s.push_back(box[1]);
		for (i = 1; i <= width; i++) {
			g.write(left + i, top + height, s);
		}

		s.pop_back();
		s.push_back(box[5]);
		g.write(left+i,top+height,s);

	}
};

class NullBorderDrawer : public BorderDrawer {
	virtual void draw(Graphics &g, short left, short top, int width, int height) const {/*Without Border*/}
};

class DoubleBorderDrawer : public BorderDrawer {
	virtual void draw(Graphics &g, short left, short top, int width, int height) const {
		char box[6] = { '\xC9','\xCD', '\xBB','\xBA','\xC8','\xBC' };
		string s;
		s.push_back(box[0]);
		g.write(left, top, s);
		short i;

		s.pop_back();
		s.push_back(box[1]);
		for (i = 1; i <= width; i++) {
			g.write(left + i, top, s);
		}

		s.pop_back();
		s.push_back(box[2]);
		g.write(left + i, top, s);

		s.pop_back();
		s.push_back(box[3]);

		for (i = 1; i < height; i++) {
			g.write(left, top + i, s);
			g.write(left + width + 1, top + i, s);
		}

		s.pop_back();
		s.push_back(box[4]);
		g.write(left, top + i, s);

		s.pop_back();
		s.push_back(box[1]);
		for (i = 1; i <= width; i++) {
			g.write(left + i, top + height, s);
		}

		s.pop_back();
		s.push_back(box[5]);
		g.write(left + i, top + height, s);

	}

};

/**************************************************************/


class Control
{
protected:
	short _left;
	short _top;
	int _width;
	int _height;
	size_t _layer;
	Graphics _graphics;

private:
	const BorderDrawer *_borderDrawer;

public:
	void SetVisibility(bool visibility);
	void SetForeground(ForegroundColor color);
	void SetBackground(BackgroundColor color);
	void SetBorder(BorderType border);
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
 
