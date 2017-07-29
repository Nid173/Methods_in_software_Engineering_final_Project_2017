#pragma once
#include "Graphics.h"
#include <string>
using namespace std;

struct BorderDrawer {
	virtual void draw(Graphics &g, int left, int top, int width, int height) const = 0;
};

class SingleBorderDrawer : public BorderDrawer {
	virtual void draw(Graphics &g, int left, int top, int width, int height) const;
};

class NullBorderDrawer : public BorderDrawer {
	virtual void draw(Graphics &g, int left, int top, int width, int height) const {/*Without Border*/ }
};

class DoubleBorderDrawer : public BorderDrawer {
	virtual void draw(Graphics &g, int left, int top, int width, int height) const;
};

/**************************************************************/

class SimpleBorderFactory {
public:
	const BorderDrawer& getNull() { return _null; }
	const BorderDrawer& getSingle() { return _single; }
	const BorderDrawer& getDouble() { return _double; }
	static SimpleBorderFactory& instance();
	SimpleBorderFactory(SimpleBorderFactory const&) = delete;
	void operator=(SimpleBorderFactory const&) = delete;
private:
	SimpleBorderFactory();
	NullBorderDrawer _null;
	SingleBorderDrawer _single;
	DoubleBorderDrawer _double;
};

