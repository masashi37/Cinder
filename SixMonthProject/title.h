
#pragma once

#include "common.h"
#include "arrow.h"


class cTitle{

	//クラスを使えるように------------------------------

	cRoom room;
	cCollision hit;
	cArrow arrow;

	Rand random;

	//変数---------------------------------------

	TextureData logo_pic;			//タイトルロゴ
	TextureData stage_select_pic;	//ステージ選択ロゴ

	TextureData arrow_pic;			//矢

	float logo_fadein_speed;		//タイトルロゴのフェードイン速度
	float arrow_fadein_speed;		//矢のフェードイン速度
	float stage_logo_speed;			//ステージ選択ロゴの速度

	float stage_logo_pos_z;			//選択ロゴのz座標
	float stage_logo_size_z;		//選択ロゴのzサイズ

	bool is_in_arrow_pic;			//矢を飛ばすアニメーション
	bool is_ready_title_logo;		//タイトルロゴのフェードインが完了したか？

public:

	cTitle::cTitle();

	void init();
	void update();
	int shift(int);
	void draw();

	void keyDown(KeyEvent);
	void keyUp(KeyEvent);

};