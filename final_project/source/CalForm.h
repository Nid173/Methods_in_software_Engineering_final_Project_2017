#pragma once
#include "stdafx.h"
#include "Graphics.h"
#include "TextBox.h"
#include "EventEngine.h"
#include "Panel.h"
#include "Label.h"
#include"Button.h"
#include "SimpleBorderFactory.h"

class cal_button :public MouseListener {
private:
	float number1;
	float number2;
public:
	virtual void MousePressed(Control &control, int x, int y, bool isLeft) {
		Panel* pan;
	}
};

cal_button listener;

class Form {

public:
	Form() {}
	~Form() {}
	void start() {
		Panel main(20, 30);
		main.setBackground(Color::Black);
		main.setForeground(Color::White);
		main.setBorder(BorderType::Double);

		/* Caclculater Form
		* 2 - TextBox 2-Label 1-button
		*/

		Panel cal(15, 30);
		cal.setBackground(Color::Black);
		cal.setForeground(Color::White);
		cal.setBorder(BorderType::Single);

		Label title(15);
		title.setText(L"Calculater");
		title.setBackground(Color::White);
		title.setForeground(Color::Black);

		Label answer(15);
		answer.setText(L"");
		answer.setBackground(Color::Black);
		answer.setForeground(Color::White);

		TextBox num1(10);
		num1.setText(L"Number1");
		num1.setBorder(BorderType::Single);

		Label plus(2);
		plus.setText(L"+");

		TextBox num2(10);
		num2.setText(L"Number2");
		num2.setBorder(BorderType::Single);

		Button click(15);
		click.setText(L"Calculate");
		click.setBorder(BorderType::Single);
		click.setBackground(Color::White);
		click.setForeground(Color::Green);
		click.addListener(listener);


		main.AddControl(title, 8, 1);
		main.AddControl(answer, 8, 4);
		main.AddControl(num1, 1, 7);
		main.AddControl(plus, 13, 7);
		main.AddControl(num2, 16, 7);
		main.AddControl(click, 8, 11);

		/*End of Cal Form */


		//	main.AddControl(cal, 2, 2);
		Control::setFocus(num1);
		EventEngine engine;
		engine.run(main);
	}
};
