
#pragma once

#include "common.h"
#include "arrow.h"


class cSelect{

	//ÉNÉâÉXÇégÇ¶ÇÈÇÊÇ§Ç…------------------------------

	cRoom room;
	cCollision hit;
	cArrow arrow;

	//ïœêî---------------------------------------

	enum {
		TARGET_MAX = 3,
		TARGET_SIZE = 150
	};
	Object select_target[TARGET_MAX];

public:

	cSelect::cSelect();

	void init();
	void update();
	int shift(int);
	void draw();

	void keyDown(KeyEvent);
	void keyUp(KeyEvent);

};