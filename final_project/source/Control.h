#pragma once

#include "Graphics.h"
#include "SimpleBorderFactory.h"
#include <vector>

using namespace std;
enum class BorderType { Single, Double, None };

class Control
{
protected:
	int _left;
	int _top;
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
	inline size_t getLayer() const;
	inline void setLayer(size_t layer);
	inline int getWidth()const;
	inline void setLeft(int left);
	inline void setTop(int top);
	inline virtual int getLeft()const;
	inline virtual int getTop()const;

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

 int Control:: getLeft()const {
	 return _left;
 }
 int Control:: getTop()const {
	 return _top;
 }

  void Control:: setTop(int top) {
	  _top = top;
 }
  void Control:: setLeft(int left) {
	  _left = left;
 }
 
  Color Control:: getBackground()const {
	  return _backgroundcolor;
  }
  Color Control:: getForeground()const {
	  return _forgroundcolor;
  }
