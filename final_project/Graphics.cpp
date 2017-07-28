#include "stdafx.h"
#include "Graphics.h"


Graphics::Graphics(DWORD stdHandle)
	: _console(GetStdHandle(stdHandle)), _background(BackgroundColor::Black), _foreground(ForegroundColor::White)
{
	updateConsoleAttributes();
}


Graphics::~Graphics()
{
}
void Graphics::clearScreen()
{
	DWORD d;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(_console, &csbi);
	auto size = csbi.dwSize.X * csbi.dwSize.Y;
	FillConsoleOutputAttribute(_console, csbi.wAttributes, size, { 0, 0 }, &d);
	FillConsoleOutputCharacter(_console, L' ', size, { 0, 0 }, &d);
}

void Graphics::moveTo(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(_console, c);
}

void Graphics::SetVisibility(bool visibility) {
	this->_visibility = visibility;
	updateConsoleAttributes();
}

void Graphics::SetForeground(ForegroundColor color) {
	this->_foreground = color;
	updateConsoleAttributes();
}

void Graphics::SetBackground(BackgroundColor color) {
	this->_background = color;
	updateConsoleAttributes();
}

void Graphics::SetBorder(BorderType border) {
	this->_border = border;
	updateConsoleAttributes();
}

/*
void Graphics::setBackground(Color color)
{
	_background = color;
	updateConsoleAttributes();
}
                                             //should be removed (what do you think?)
void Graphics::setForeground(Color color)
{
	_foreground = color;
	updateConsoleAttributes();
}
*/
void Graphics::write(string s)
{
	WriteConsoleA(_console, s.c_str(), s.size(), nullptr, nullptr);
}

void Graphics::write(wstring s)
{
	WriteConsoleW(_console, s.c_str(), s.size(), nullptr, nullptr);
}

void Graphics::write(int x, int y, string s)
{
	moveTo(x, y);
	write(s);
}

void Graphics::write(int x, int y, wstring s)
{
	moveTo(x, y);
	write(s);
}

void Graphics::setCursorVisibility(bool isVisible)
{
	CONSOLE_CURSOR_INFO cci;
	GetConsoleCursorInfo(_console, &cci);
	cci.bVisible = isVisible;
	SetConsoleCursorInfo(_console, &cci);
}

void Graphics::updateConsoleAttributes()
{
	DWORD attributes = 0;

	switch (_foreground)
	{
	case ForegroundColor::Black:	break;
	case ForegroundColor::Blue:	attributes |= FOREGROUND_BLUE; break;
	case ForegroundColor::Green:	attributes |= FOREGROUND_GREEN; break;
	case ForegroundColor::Red:	attributes |= FOREGROUND_RED; break;
	//case ForegroundColor::Cyan:	attributes |= FOREGROUND_BLUE | FOREGROUND_GREEN; break; //instead of cyan change to Teal
	case ForegroundColor::Purple:	attributes |= FOREGROUND_BLUE | FOREGROUND_RED; break;
	//.case ForegroundColor::Orange: attributes |= FOREGROUND_GREEN | FOREGROUND_RED; break; //instead of Orange change to Yellow
	case ForegroundColor::White:	attributes |= FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED; break;
	}

	switch (_background)
	{
	case BackgroundColor::Black:	break;
	case BackgroundColor::Blue:	attributes |= BACKGROUND_BLUE; break;
	case BackgroundColor::Green:	attributes |= BACKGROUND_GREEN; break;
	case BackgroundColor::Red:	attributes |= BACKGROUND_RED; break;
	//case BackgroundColor::Cyan:	attributes |= BACKGROUND_BLUE | BACKGROUND_GREEN; break; //instead of cyan change to Teal
	case BackgroundColor::Purple:	attributes |= BACKGROUND_BLUE | BACKGROUND_RED; break;
	//case BackgroundColor::Orange: attributes |= BACKGROUND_GREEN | BACKGROUND_RED; break; //instead of Orange change to Yellow
	case BackgroundColor::White:	attributes |= BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED; break;
	}
 
    /*
	switch (_visibility)
	{
	case bool::True
	case bool::False
	}
	                               //need to be coded iam not sure how
	switch (_border)
	{
	 case BorderType::Single 
	 case BorderType::Double
	 case BorderType::None
	}
	*/

	SetConsoleTextAttribute(_console, attributes);
}

bool isInside(int x, int y, int left, int top, int width, int height)
{
	x -= left;
	y -= top;
	return x >= 0 && y >= 0 && x < width && y < height;
}