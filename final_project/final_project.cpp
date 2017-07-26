// final_project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Graphics.h"
#include "TextBox.h"
#include "SimpleBorderFactory.h"


int main()
{
	Graphics g = Graphics();
	TextBox textBox1(10);
	textBox1.setForeground(Color::Red);
	textBox1.setText(L"hello");
	textBox1.setBorderDrawer(SimpleBorderFactory::instance().getSingle());
	//g.write("hello");
	getchar();
    return 0;
}

