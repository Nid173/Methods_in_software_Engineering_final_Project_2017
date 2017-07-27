// final_project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Graphics.h"
#include "Panel.h"
#include "TextBox.h"
#include "EventEngine.h"
#include "SimpleBorderFactory.h"


int main()
{
	//Graphics g = Graphics();
	TextBox textBox1(10);
	textBox1.setForeground(Color::Red);
	textBox1.setText(L"hello");
	textBox1.setBorderDrawer(SimpleBorderFactory::instance().getSingle());
	Panel panel(10, 10);
	panel.AddControl(textBox1);
	EventEngine engine;
	engine.run(panel);
	//g.write("hello");
	//getchar();
    return 0;
}

