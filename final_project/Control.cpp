#include "stdafx.h"
#include "Control.h"


Control::Control()
{
}


Control::~Control()
{
}

void Control:: draw(Graphics& g, int x, int y, size_t z) const {
	if (z > _layer) return;
}

