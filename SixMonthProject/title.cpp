
#include "title.h"


void cTitle::setup(){

	logo_pic = loadImage(loadAsset("title/logo.png"));
	stage_select_pic = loadImage(loadAsset("title/stage_select.png"));

	logo.size = { logo_pic.getSize() };
	logo.pos = { -logo.size.x / 2, -SCREEN_HALF_Y + logo.size.y };

	stage_select.size = { stage_select_pic.getSize() };
	stage_select.pos = {
		-stage_select.size.x / 2,
		SCREEN_HALF_Y - stage_select.size.y * 3
	};


	arrow_tower.size = { 100, 100, 200 };
	arrow_tower.pos = {
		-SCREEN_HALF_X + arrow_tower.size.x / 2,
		SCREEN_HALF_Y - arrow_tower.size.y / 2,
		-arrow_tower.size.z / 2
	};

}

void cTitle::update(){

	target.push_back({
		{ SCREEN_HALF_X - 100, 0, 0 },
		{ -25, 50, 50 }
	});
	target.push_back({
		{ SCREEN_HALF_X - 200, 200, 0 },
		{ -25, 50, 50 }
	});
	target.push_back({
		{ SCREEN_HALF_X - 50, 100, 0 },
		{ -25, 50, 50 }
	});

}

void cTitle::shift(){}

void cTitle::draw(){

	gl::pushModelView();							//原点保存
	gl::translate(SCREEN_HALF_X, SCREEN_HALF_Y);	//原点変更

	//タイトルロゴ(赤)
	gl::color(1, 0, 0);
	gl::draw(logo_pic, logo.pos);

	//ステージ選択ロゴ(黄)
	gl::color(1, 1, 0);
	gl::draw(stage_select_pic, stage_select.pos);

	//表示空間 ＆ 弓の発射台(白)
	gl::color(1, 1, 1);
	gl::drawStrokedCube(room.pos, room.size);
	gl::drawStrokedCube(arrow_tower.pos, arrow_tower.size);

	for (unsigned int i = 0; i < target.size(); ++i){
		gl::drawColorCube(target[i].pos, target[i].size);
	}

	gl::popModelView();							//原点回帰

}

