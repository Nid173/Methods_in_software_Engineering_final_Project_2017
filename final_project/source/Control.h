#pragma once

#include "Graphics.h"
#include "SimpleBorderFactory.h"
#include "Focused.h"
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
	int _cursorPosition;
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
	inline int getHeight()const;
	inline virtual void restCursor();

	inline virtual void setLeft(int left);
	inline virtual void setTop(int top);
	inline virtual int getLeft()const;
	inline virtual int getTop()const;

	 /**/
	Control();
	static Control* getFocus();
	static void setFocus(Control& control);
	
	virtual void draw(Graphics& g, int x, int y, size_t z)const;
	virtual void mousePressed(int x, int y, bool isLeft) {};
	virtual void keyDown(int keyCode, char charecter) {};
	virtual void getAllControls(vector<Control*>* controls) {};
	virtual bool canGetFocus();
	virtual void setBorderDrawer(const BorderDrawer &borderDrawer)  {_borderDrawer = &borderDrawer;}
	virtual ~Control() = default;
	virtual string className() { return "Control"; }
};

class Focused {
public:
	static Focused* instance() {
		if (!_instance)
			_instance = new Focused;
		return _instance;
	}
	Control* getfocus() { return _focus; }
	void setFocus(Control& c) { _focus = &c; }
	void setGraph(Graphics& g) { _graph = &g; }
	Graphics* getGraph() { return _graph; }
	Focused(Focused const&) = delete;
	void operator=(Focused const&) = delete;
private:
	static Focused* _instance;
	Control* _focus;
	Graphics* _graph;
	Focused() { _focus = NULL; _graph = NULL; }
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

  int Control::getHeight()const {
	  return _height;
  }

  void Control::restCursor() {
	  _cursorPosition = 0;
  }
