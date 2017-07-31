#pragma once
#include "stdafx.h"
#include "Graphics.h"
#include "TextBox.h"
#include "EventEngine.h"
#include "Panel.h"
#include "Label.h"
#include"Button.h"
#include "SimpleBorderFactory.h"

class show_button :public MouseListener {
private:
public:
	virtual void MousePressed(Control &control, int x, int y, bool isLeft) {
		vector<Control*> controls;
		control.getAllControls(&controls);
		TextBox* mystr1 = static_cast<TextBox*>(controls[2]);
		TextBox* mystr2 = static_cast<TextBox*>(controls[3]);


				/*get the answer*/
		Label* tempo = static_cast<Label*> (controls[1]);
		tempo->setText(mystr1->getText()+mystr2->getText());
	}
};

show_button listener;

class Form {

public:
	Form() {}
	~Form() {}
	void start() {
		Panel main(20, 70);
		main.setBackground(Color::Black);
		main.setForeground(Color::White);
		main.setBorder(BorderType::Double);

		/* Caclculater Form
		* 2 - TextBox 2-Label 1-button
		*/

		Label title(15);
		title.setText(L"String+String");
		title.setBackground(Color::White);
		title.setForeground(Color::Black);

		Label answer(20);
		answer.setText(L"");
		answer.setBackground(Color::Black);
		answer.setForeground(Color::White);

		TextBox str1(10);
		str1.setText(L"string1!");
		str1.setBorder(BorderType::Single);


		TextBox str2(10);
		str2.setText(L"string2");
		str2.setBorder(BorderType::Single);

		Button click(15);
		click.setText(L"/show!");
		click.setBorder(BorderType::Single);
		click.setBackground(Color::White);
		click.setForeground(Color::Green);
		click.addListener(listener);


		main.AddControl(title, 8, 1);//0
		main.AddControl(answer, 8, 4);//1
		main.AddControl(str1, 1, 7);//2
		main.AddControl(str2, 16, 7);//3
		main.AddControl(click, 8, 11);//4

		/*End of Cal Form */


		//	main.AddControl(cal, 2, 2);
		Control::setFocus(str1);
		EventEngine engine;
		engine.run(main);
	}
};
