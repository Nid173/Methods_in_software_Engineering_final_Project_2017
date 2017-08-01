#pragma once
#include "stdafx.h"
#include "Graphics.h"
#include "TextBox.h"
#include "EventEngine.h"
#include "Panel.h"
#include "Label.h"
#include"Button.h"
#include "SimpleBorderFactory.h"
#include "NumericBox.h"
#include "RadioBox.h"
#include "CheckList.h"
#include "ComboBox.h"
#include "MessageBox.h"

class Choices_button :public MouseListener {
private:
public:
	/*
	virtual void MousePressed(Control &control, int x, int y, bool isLeft) {
		int num1 = 0, num2 = 0, ans = 0;
		vector<Control*> controls;
		control.getAllControls(&controls);
		TextBox* mynum1 = static_cast<TextBox*>(controls[2]);
		TextBox* mynum2 = static_cast<TextBox*>(controls[4]);
		num1 = stoi(mynum1->getText());
		num2 = stoi(mynum2->getText());


		(get the answer)
		ans = num1 + num2;
		Label* tempo = static_cast<Label*> (controls[1]);
		tempo->setText(to_wstring(ans));
	}
*/

};

//Choice_button listener;

class ChoiceForm {

public:
	ChoiceForm() {}
	~ChoiceForm() {}
	void start() {
		
		vector<string> genders;
		genders.push_back("sport");
		genders.push_back("movies");
		genders.push_back("swiming");
		genders.push_back("vidiogames");
		Panel main(30, 30);
		main.setBackground(Color::Black);
		main.setForeground(Color::White);
		main.setBorder(BorderType::Double);

		NumericBox age(4, 0, 18);
		age.setBorder(BorderType::Single);
		CheckList gender(10,2, genders);
		gender.setBorder(BorderType::Single);
		

		Messagebox m(L"Error message");
		main.AddControl(age, 2, 4);
		main.AddControl(gender, 15,4);

		main.AddControl(m, 4, 15);
		EventEngine engine;

		engine.run(main);
		
	}
};

