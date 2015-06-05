
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
		TARGET_MAX = 2,			//ターゲットの最大数
		TARGET_DEPTH = 20		//ターゲットのサイズ
	};
	Object select_target[TARGET_MAX];	//選択肢

public:

	cSelect::cSelect();

	void init();
	void update();
	int shift(int);
	void draw();

	void keyDown(KeyEvent);
	void keyUp(KeyEvent);

};