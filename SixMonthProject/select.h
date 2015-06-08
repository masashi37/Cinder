
#pragma once

#include "common.h"
#include "arrow.h"


class cSelect{

	//クラスを使えるように------------------------------

	cRoom room;
	cCollision hit;
	cArrow arrow;
	cParticle particle;

	//font
	Font font;

	//変数---------------------------------------

	//fontのpos
	Vec2f select_pos;			//セレクト
	Vec2f left_select_pos;		//選択肢(左)
	Vec2f right_select_pos;		//選択肢(右)

	enum {
		TARGET_MAX = 2,			//ターゲットの最大数
		TARGET_DEPTH = 20		//ターゲットのサイズ
	};
	Object select_target[TARGET_MAX];	//選択肢

	int select_number;				//選んだ難易度
	int particle_time;				//パーティクルの時間

	bool is_ready_shift;			//シフトできるか？

public:

	cSelect::cSelect();

	void init();
	void update();
	int shift(int);
	void draw();

	void reStartInit();

	void keyDown(KeyEvent);
	void keyUp(KeyEvent);

};