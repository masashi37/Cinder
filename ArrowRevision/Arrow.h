
#pragma once

#include "common.h"


typedef std::shared_ptr<class Arrow>ArrowSP;
class Arrow{

private:

	gl::Texture arrow_pic;

	//定数--------------------------------------

	//弓関連
	enum {
		SPEED_MAX = 40,		//弓の速度限界値
		GAGE_SPACE = 20		//弓のチャージゲージと弓の間隔
	};

	const Vec3f size_vertical = Vec3f(1.0f, 20.0f, 100.0f);		//垂直弓のサイズ
	const Vec3f size_horizontal = Vec3f(20.0f, 1.0f, 100.0f);	//水平弓のサイズ

	//変数---------------------------------------

	audio::BufferPlayerNodeRef shoot_se;	//弓を放った効果音
	audio::GainNodeRef gain;				//ボリューム

	Vec2f back_arrow_pos;		//弓が戻って来るときの位置

	Vec3f pos;					//弓の座標
	Vec3f aim_light_begin;		//ライトの開始
	Vec3f aim_light_end;		//ライトの終了

	Color aim_line_color;		//照準ゲージの色

	float arrow_speed;			//弓の速度
	float acceleration;			//弓の加速度
	float gravity;				//重力

	float volume;				//seのボリューム

	bool is_push_button;		//ボタンのpush判定
	bool is_shoot_arrow;		//弓が放たれたか？

public:

	void init();
	void update();
	void draw();

	void mouseDown(MouseEvent);
	void mouseMove(MouseEvent);
	void mouseUp(MouseEvent);

	void setRedColor();			//弓の照準色変更
	void setWhiteColor();		//弓の照準色変更

	Vec3f getPos();				//弓のポジション取得
	Vec3f getSize();			//弓のサイズ取得

	bool getIsShooting();		//弓を放ったかどうかの取得

};