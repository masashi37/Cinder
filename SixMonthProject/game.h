
#pragma once

#include "common.h"
#include "arrow.h"

#include "select.h"


class cGame{

private:

	//ƒNƒ‰ƒX‚ğg‚¦‚é‚æ‚¤‚É-------------------------

	cRoom room;
	cArrow arrow;

	cSelect select;

	//•Ï”---------------------------------------

	int selection_number;

public:

	cGame::cGame();

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