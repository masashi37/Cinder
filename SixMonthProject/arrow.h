
#pragma once

#include "common.h"


class cArrow{

	gl::Texture arrow_picture;

	//定数--------------------------------------

	//弓関連
	enum {
		SPEED_MAX = 40,		//弓の速度限界値
		GAGE_SPACE = 20		//弓のチャージゲージと弓の間隔
	};

	const Vec3f size = { 1.0f, 20.0f, 100.0f };		//弓のサイズ
	const Vec3f size1 = { 20.0f, 1.0f, 100.0f };	//弓のサイズ(表示のみ)
	const float move_speed = 3.0f;					//弓の動くスピード

	//変数---------------------------------------

	audio::BufferPlayerNodeRef shoot_se;

	Vec2f back_arrow_pos;

	Vec3f pos;						//弓の座標
	Vec3f aim_light_begin;			//ライトの開始
	Vec3f aim_light_end;			//ライトの終了

	float arrow_speed;				//弓の速度
	float plus_speed;				//弓の速度の変化値
	float gravity;					//重力
	float gravity_puls;				//重力の変化値

	int key_direction;				//弓の動く向き

	//キーの判定
	bool is_push_space;				//スペースキー
	bool is_push_left;				//左
	bool is_push_right;				//右
	bool is_push_up;				//上
	bool is_push_down;				//下

	bool is_shoot_arrow;			//弓が放たれたか？


public:

	cArrow::cArrow();

	void init();
	void update();
	void draw();

	Vec3f getPos();				//弓のポジション取得
	Vec3f getSize();			//弓のサイズ取得
	bool get_is_shooting();		//弓を放ったかどうかの取得

	void keyDown(KeyEvent);
	void keyUp(KeyEvent);


};