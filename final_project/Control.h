#pragma once

#include "Graphics.h"
#include <vector>

using namespace std;




struct BorderDrawer {
	virtual void draw(Graphics &g, short left, short top, int width, int height) const = 0;
};

class SingleBorderDrawer : public BorderDrawer {
	virtual void draw(Graphics &g, short left, short top, int width, int height) const;
};

class NullBorderDrawer : public BorderDrawer {
	virtual void draw(Graphics &g, short left, short top, int width, int height) const {/*Without Border*/}
};

class DoubleBorderDrawer : public BorderDrawer {
	virtual void draw(Graphics &g, short left, short top, int width, int height) const;
};

/**************************************************************/

enum class BorderType { Single, Double, None };

class Control
{
protected:
	short _left;
	short _top;
	int _width;
	int _height;
	size_t _layer;
	Color _forgroundcolor;
	Color _backgroundcolor;

private:
	const BorderDrawer *_borderDrawer;

public:
	/* main methods for the graphic */
	void setVisibility(bool visibility);
	void setForeground(Color color);
	void setBackground(Color color);
	inline Color getBackground()const;
	inline Color getForeground()const;
	void setBorder(BorderType border);

	/* setters and getters */
	inline Graphics& getGraphics();
	inline size_t getLayer() const;
	inline void setLayer(size_t layer);
	inline int getWidth()const;
	inline void setLeft(short left);
	inline void setTop(short top);
	inline virtual short getLeft()const;
	inline virtual short getTop()const;

	static Control* getFocus() { return NULL; };
	static void setFocus(Control& control) {};
	 /**/
	Control();
	
	virtual void draw(Graphics& g, int x, int y, size_t z)const;
	virtual void mousePressed(int x, int y, bool isLeft) {};
	virtual void keyDown(int keyCode, char charecter) {};
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
 
  Color Control:: getBackground()const {
	  return _backgroundcolor;
  }
  Color Control:: getForeground()const {
	  return _forgroundcolor;
  }
