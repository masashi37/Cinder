
#pragma once

#include "common.h"


class cArrow{

	gl::Texture arrow_picture;

	//定数--------------------------------------

	//弓関連
	enum {
		SPEED_MAX = 40,
		GAGE_SPACE = 20
	};

	const Vec3f size = { 1.0f, 20.0f, 100.0f };	//弓のサイズ
	const Vec3f size1 = { 20.0f, 1.0f, 100.0f };
	const float move_speed = 3.0f;				//弓の動くスピード

	//変数---------------------------------------

	Vec3f pos = { -(size.x) / 2.0f, -(size.y) / 2.0f, 0.0f };	//弓の座標

	float arrow_speed = 0;			//弓の速度
	float plus_speed = 0.5f;		//弓の速度の変化値
	float gravity = 0.0f;			//重力
	float gravity_puls = 0.1f;		//重力の変化値

	int key_direction = 0;			//弓の動く向き

	//キーの判定
	bool is_push_space = false;		//スペースキー
	bool is_push_left = false;		//左
	bool is_push_right = false;		//右
	bool is_push_up = false;		//上
	bool is_push_down = false;		//下

	bool is_shoot_arrow = false;	//弓が放たれたか？


public:

	cArrow::cArrow();

	void init();
	void update();
	void shift();
	void draw();

	Vec3f getPos();
	Vec3f getSize();
	bool get_is_shooting();

	void keyDown(KeyEvent);
	void keyUp(KeyEvent);

	//void mouseDown(MouseEvent);
	//void mouseUp(MouseEvent);
	//void mouseMove(MouseEvent);

};