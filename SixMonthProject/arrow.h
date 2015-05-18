
#pragma once

#include "arrowMove.h"


class cArrow:public cArrowStatus{

private:

	cArrowMove move;

public:

	void setup();
	void update();
	void mouseDown(MouseEvent);
	void mouseUp(MouseEvent);
	void mouseMove(MouseEvent);
	void draw();

};

