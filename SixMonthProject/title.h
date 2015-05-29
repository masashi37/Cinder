
#pragma once

#include "common.h"
#include "arrow.h"


class cTitle{

	//クラスを使えるように------------------------------

	cRoom room;
	cArrow arrow;

	Rand random;

	//変数---------------------------------------

	TextureData logo_pic;			//タイトルロゴ
	TextureData stage_select_pic;	//ステージ選択ロゴ

	float logo_fadein_speed;		//タイトルロゴのフェードイン速度
	float stage_logo_speed;			//ステージ選択ロゴの速度

	float stage_logo_pos_z = -room_depth;
	float stage_logo_size_z = 10;

	bool is_ready_title_logo;		//タイトルロゴのフェードインが完了したか？

public:

	void setup();
	void update();
	int shift(int);
	void draw();

	void keyDown(KeyEvent);
	void keyUp(KeyEvent);

	//void mouseDown(MouseEvent);
	//void mouseUp(MouseEvent);
	//void mouseMove(MouseEvent);

};