
#pragma once

#include "common.h"
#include "cinder/Rand.h"
#include "arrow.h"


class cTitle{

private:

	cArrow arrow;

	gl::Texture logo_pic;			//タイトルロゴ 128*32
	gl::Texture stage_select_pic;	//ステージ選択ロゴ 128*64

	struct TitleText{
		Vec2f pos;
		Vec2f size;
	};
	TitleText logo;				//タイトルロゴ
	TitleText stage_select;		//ステージ選択のロゴ

	struct TitleObject{
		Vec3f pos;
		Vec3f size;
	};
	TitleObject arrow_tower;	//弓を撃つ台
	std::vector<TitleObject>target;			//練習用的

	float show_z = 2;			//立体に見せるｚ

public:

	void setup();
	void update();
	void mouseDown(MouseEvent);
	void mouseUp(MouseEvent);
	void mouseMove(MouseEvent);
	void shift();
	void draw();

};