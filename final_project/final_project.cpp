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
	textBox1.SetForeground(ForegroundColor::Red);
	textBox1.setText(L"hello");
	textBox1.setLayer(2);
	textBox1.setBorderDrawer(SimpleBorderFactory::instance().getSingle());
	Panel panel(50,50);
	//panel.setLayer(1);
	//panel.AddControl(textBox1, 4, 16);
	EventEngine engine;
	engine.run(textBox1);
	//g.write("hello");
	//getchar();
    return 0;
}

