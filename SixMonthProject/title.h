
#pragma once

#include "common.h"
#include "arrow.h"


class cTitle{

	cRoom room;	
	cArrow arrow;

public:

	void setup();
	void update();
	void shift();
	void draw();

	void keyDown(KeyEvent);
	void keyUp(KeyEvent);

	//void mouseDown(MouseEvent);
	//void mouseUp(MouseEvent);
	//void mouseMove(MouseEvent);

};