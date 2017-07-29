// final_project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Graphics.h"
#include "TextBox.h"
#include "EventEngine.h"
#include "Panel.h"
#include "Label.h"
#include"Button.h"
#include "SimpleBorderFactory.h"


int main()
{

	Panel panel(29, 100);
	panel.setLayer(1);
	panel.setBackground(Color::Blue);
	panel.setBorder(BorderType::Double);
	TextBox textBox1(10);
	textBox1.setBackground(Color::Green);
	textBox1.setForeground(Color::Red);
	textBox1.setText(L"hello");
	textBox1.setLayer(2);
	textBox1.setBorder(BorderType::Single);
	Label label1(11);
	label1.setBackground(Color::Red);
	label1.setForeground(Color::Green);
	label1.setBorder(BorderType::None);
	label1.setText(L"Label test");

	Button Button1(15);
	Button1.setBackground(Color::Orange);
	Button1.setForeground(Color::Purple);
	Button1.setBorder(BorderType::Double);
	Button1.setText(L"Button test");
	panel.AddControl(textBox1, 1, 3);
	panel.AddControl(label1, 5, 5);
	panel.AddControl(Button1, 10, 9);
	//panel.setFocus(textBox1);
	EventEngine engine;
	engine.run(panel);
	//g.write("hello");
	//getchar();
    return 0;
}

