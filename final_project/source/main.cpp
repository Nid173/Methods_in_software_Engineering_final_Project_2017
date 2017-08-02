// final_project.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include "Graphics.h"
#include "TextBox.h"
#include "EventEngine.h"
#include "Panel.h"
#include "Label.h"
#include"Button.h"
#include "SimpleBorderFactory.h"
#include "CalForm.h"

Focused* Focused::_instance = 0;
int main()
{
	Form calform;
	calform.start();
	return 0;
}

