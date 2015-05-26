
#include "title.h"


void cTitle::setup(){

	logo_pic = { loadImage(loadAsset("title/logo.png")),
	{ -WIDTH - 300, -HEIGHT / 2 + 100 } };
	stage_select_pic = { loadImage(loadAsset("title/stage_select.png")),
	{ -50, 50 } };

	logo_fadein_speed = 5.0f;
	stage_logo_speed = 3.0f;

	is_ready_title_logo = false;

}

void cTitle::update(){

	//タイトルロゴの準備が未完了時
	if (!is_ready_title_logo){
		//完了させるための操作

		//簡易アニメーション
		logo_pic.pos.x += logo_fadein_speed;
		if (logo_pic.pos.x > 0)
			logo_fadein_speed -= 1.0f;

		if (logo_fadein_speed < 0)
			if (logo_pic.pos.x < -logo_pic.pic.getWidth() / 2)
				is_ready_title_logo = true;
	}
	//タイトルロゴの準備が完了
	else{
		//ステージ選択ロゴの動作開始
		stage_select_pic.pos.x += stage_logo_speed;

		if (stage_select_pic.pos.x < -WIDTH / 4 ||
			stage_select_pic.pos.x + stage_select_pic.pic.getSize().x > WIDTH / 4)
			stage_logo_speed *= -1;

	}

	arrow.update();

}

void cTitle::shift(){}

void cTitle::draw(){

	//空間表示
	gl::drawStrokedCube(room.pos, room.size);

	//ロゴ
	gl::draw(logo_pic.pic, logo_pic.pos);
	if (is_ready_title_logo)
		gl::draw(stage_select_pic.pic, stage_select_pic.pos);

	//弓矢
	arrow.draw();

}

void cTitle::keyDown(KeyEvent event){

	//弓の操作
	arrow.keyDown(event);

}

void cTitle::keyUp(KeyEvent event){

	//弓の操作
	arrow.keyUp(event);

}

/*
void cTitle::mouseDown(KeyEvent event){}

void cTitle::mouseUp(KeyEvent event){}

void cTitle::mouseMove(KeyEvent event){}
*/