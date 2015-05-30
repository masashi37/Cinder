
#pragma once

#include "common.h"
#include "arrow.h"


class cSelect{

	//クラスを使えるように------------------------------

	cRoom room;
	cCollision hit;
	cArrow arrow;

	//変数---------------------------------------

	enum {
		TARGET_MAX = 5,
		TARGET_SIZE = 80
	};
	Object select_target[TARGET_MAX];
	int select_target_number;

public:

	cSelect::cSelect();

	void init();
	void update();
	int shift(int);
	void draw();

	int get_select_number(int);

	void keyDown(KeyEvent);
	void keyUp(KeyEvent);

	//void mouseDown(MouseEvent);
	//void mouseUp(MouseEvent);
	//void mouseMove(MouseEvent);
};