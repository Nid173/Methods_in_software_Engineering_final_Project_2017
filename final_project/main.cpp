// final_project.cpp : Defines the entry point for the console application.
//

#include "Console_Utilites/stdafx.h"
#include "Console_Utilites/Graphics.h"
#include "Console_Utilites/TextBox.h"
#include "Console_Utilites/EventEngine.h"
#include "Console_Utilites/Panel.h"
#include "Console_Utilites/SimpleBorderFactory.h"


int main()
{

	Panel panel(20, 100);
	panel.setLayer(2);
	panel.setBackground(Color::Blue);
	panel.setBorder(BorderType::Double);
	TextBox textBox1(10);
	textBox1.setBackground(Color::Green);
	textBox1.setForeground(Color::Red);
	textBox1.setText(L"hello");
	textBox1.setLayer(1);
	textBox1.setBorder(BorderType::Single);
	panel.AddControl(textBox1, 4, 4);
	panel.setFocus(textBox1);
	EventEngine engine;
	engine.run(panel);
	//g.write("hello");
	//getchar();
    return 0;
}

