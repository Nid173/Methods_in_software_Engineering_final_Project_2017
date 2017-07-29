// final_project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Graphics.h"
#include "TextBox.h"
#include "EventEngine.h"
#include "Panel.h"
#include "SimpleBorderFactory.h"


int main()
{

	Panel panel(20, 100);
	panel.setLayer(1);
	panel.setBackground(Color::Blue);
	panel.setBorder(BorderType::Double);
	TextBox textBox1(10);
	textBox1.setBackground(Color::Green);
	//textBox1.setForeground(Color::Red);
	textBox1.setText(L"heeeeee");
	textBox1.setLayer(2);
	textBox1.setBorder(BorderType::Single);
	panel.AddControl(textBox1, 7, 4);
	//panel.setFocus(textBox1);
	EventEngine engine;
	engine.run(panel);
	//g.write("hello");
	//getchar();
    return 0;
}

