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

		vector<string> hobbies;
		hobbies.push_back("sport");
		hobbies.push_back("movies");
		hobbies.push_back("swiming");
		hobbies.push_back("vidiogames");


		vector<string> genders;
		genders.push_back("male");
		genders.push_back("female");
		genders.push_back("others");

		vector<string> educations;
		educations.push_back("collage");
		educations.push_back("highschool");
		educations.push_back("droped");

		Panel main(30, 30);
		main.setBackground(Color::Black);
		main.setForeground(Color::White);
		main.setBorder(BorderType::Double);

		NumericBox age(4, 0, 18);
		age.setBorder(BorderType::Single);

		
		main.AddControl(age, 2, 4);

		CheckList hobby(10,2, hobbies);
		hobby.setBorder(BorderType::Single);
		main.AddControl(hobby, 15, 4);

		RadioBox gender(7, 2, genders);
		gender.setBorder(BorderType::Single);
		main.AddControl(gender, 3, 15);
		
		ComboBox education(10,educations);
		education.setBorder(BorderType::Single);
		main.AddControl(education, 16, 15);
		
		EventEngine engine;

		engine.run(main);
		
	}
};

