#pragma once

#include <string>
#include <Windows.h>


using namespace std;

enum class ForegroundColor { Red, Blue, Green, Purple, Teal, Yellow, White, Black };
enum class BackgroundColor { Red, Blue, Green, Purple, Teal, Yellow, White, Black };
enum class BorderType { Single, Double, None };

//enum class Color { Black, Blue, Green, Red, Cyan, Purple, Orange, White }; //should be removed (what do you think?)

class Graphics
{
public:
	Graphics(DWORD stdHandle = STD_OUTPUT_HANDLE);
	void clearScreen();
	void moveTo(int x, int y);
	
	void SetVisibility(bool visibility);
	void SetForeground(ForegroundColor color);
	void SetBackground(BackgroundColor color);
	void SetBorder(BorderType border);
	//void setBackground(Color color);//should be removed (what do you think?)
	//void setForeground(Color color);//should be removed (what do you think?)
	void write(string s);
	void write(int x, int y, string s);
	void write(wstring s);
	void write(int x, int y, wstring s);
	void setCursorVisibility(bool isVisible);
	~Graphics();

private:
	HANDLE _console;
	bool _visibility;
	BorderType	_border;
	ForegroundColor _foreground;
	BackgroundColor _background;
	//Color _background, _foreground;//should be removed (what do you think?)

	void updateConsoleAttributes();
};

bool isInside(int x, int y, int left, int top, int width, int height);
