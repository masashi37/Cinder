
#pragma once

#include "common.h"
#include "arrow.h"


class cSelect{

	cRoom room;
	cArrow arrow;

public:

	cSelect::cSelect();

	void init();
	void update();
	void shift();
	void draw();

	void keyDown(KeyEvent);
	void keyUp(KeyEvent);

	//void mouseDown(MouseEvent);
	//void mouseUp(MouseEvent);
	//void mouseMove(MouseEvent);
};