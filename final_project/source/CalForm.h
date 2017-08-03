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

class Submit :public MouseListener {
private:
public:
	virtual void MousePressed(Control &control, int x, int y, bool isLeft) {
		vector<Control*> myvec;
		control.getAllControls(&myvec);
		wstring answer=L" name: " ;
		for (int i = 0; i < 2; i++) {
			TextBox *tmp = static_cast<Button*>(myvec[i]);
			answer += L" " + tmp->getText;
		}
		NumericBox *tmp = static_cast<NumericBox*>(myvec[2]);
		answer += L"\n" + to_wstring(tmp->getValue());

		CheckList* temp = static_cast<CheckList*>(myvec[3]);
		vector<string> en;


	}
};
// 0->textbox first name (wstring::getText())
// 1->textbox last name  (wstring::getText())
// 2-> numricbox age (size_t::getValue())
// 3-Checklist hobby (vector<size_t> GetallIndex())
// 4->Radiobox gender (size_t::GetSelectedIndex())
// 5->Combobox eduaction (size_t::GetSelectedIndex)

Submit listener;
class Form {

public:
	Form() {}
	~Form() {}
	void start() {
		//the main panel
		Panel main(29, 70);
		main.setBackground(Color::Black);
		main.setForeground(Color::White);
		main.setBorder(BorderType::Double);

		//box exampales
		TextBox str1(10);
		str1.setText(L"first");
		str1.setBorder(BorderType::Single);
		main.AddControl(str1, 5, 7);

		TextBox str2(10);
		str2.setText(L"last");
		str2.setBorder(BorderType::Single);
		main.AddControl(str2, 20, 7);

		NumericBox age(4, 0, 18);
		age.setBorder(BorderType::Single);
		main.AddControl(age, 5, 14);

		vector<string> hobbies;
		hobbies.push_back("sport");
		hobbies.push_back("movies");
		hobbies.push_back("swiming");
		hobbies.push_back("vidiogames");

		CheckList hobby(10, 2, hobbies);
		hobby.setBorder(BorderType::Single);
		main.AddControl(hobby,50, 14);

		vector<string> genders;
		genders.push_back("male");
		genders.push_back("female");
		genders.push_back("others");

		RadioBox gender(7, 2, genders);
		gender.setBorder(BorderType::Single);
		main.AddControl(gender, 50, 5);

		vector<string> educations;
		educations.push_back("collage");
		educations.push_back("highschool");
		educations.push_back("droped");

		ComboBox education(10, educations);
		education.setBorder(BorderType::Single);
		main.AddControl(education, 25, 14);

		//titles
		Label title(12);
		title.setText(L"   survey");
		title.setBackground(Color::White);
		title.setForeground(Color::Black);
		main.AddControl(title, 27, 1);

		Label name(15);
		name.setText(L"full name");
		name.setBackground(Color::Black);
		name.setForeground(Color::Orange);
		main.AddControl(name, 13, 5);


		Label agetest(15);
		agetest.setText(L"age(0-18)");
		agetest.setBackground(Color::Black);
		agetest.setForeground(Color::Orange);
		main.AddControl(agetest, 5, 12);

		Label educattest(15);
		educattest.setText(L"education");
		educattest.setBackground(Color::Black);
		educattest.setForeground(Color::Orange);
		main.AddControl(educattest, 25, 12);

		Label hobbytest(15);
		hobbytest.setText(L"hobby");
		hobbytest.setBackground(Color::Black);
		hobbytest.setForeground(Color::Orange);
		main.AddControl(hobbytest, 52, 12);

		Label gendertest(15);
		gendertest.setText(L"gender");
		gendertest.setBackground(Color::Black);
		gendertest.setForeground(Color::Orange);
		main.AddControl(gendertest, 50, 3);


		Button click(10);
		click.setText(L" submit!");
		click.setBorder(BorderType::Single);
		click.setBackground(Color::White);
		click.setForeground(Color::Green);
		click.addListener(listener);
		main.AddControl(click, 30, 25);

		/*End of the Form */

		Control::setFocus(str1);
		EventEngine engine;
		engine.run(main);
	}
};
