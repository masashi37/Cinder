
#include "title.h"


void cTitle::setup(){

	logo_pic = { loadImage(loadAsset("title/logo.png")),
	{ -WIDTH - 300, -HEIGHT / 2 + 100 } };
	stage_select_pic = { loadImage(loadAsset("title/stage_select.png")),
	{ -0, 0 } };

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

		if (stage_select_pic.pos.x - stage_select_pic.pic.getSize().x / 2 < -WIDTH / 2 ||
			stage_select_pic.pos.x + stage_select_pic.pic.getSize().x / 2 > WIDTH / 2)
			stage_logo_speed *= -1;

	}

	arrow.update();

}

int cTitle::shift(int mover){

	if (arrow.get_is_shooting()){
		if (arrow.getPos().x - arrow.getSize().x / 2 <
			stage_select_pic.pos.x + stage_select_pic.pic.getSize().x / 2 &&
			arrow.getPos().x + arrow.getSize().x / 2 >
			stage_select_pic.pos.x - stage_select_pic.pic.getSize().x / 2 &&
			arrow.getPos().y - arrow.getSize().y / 2 <
			stage_select_pic.pos.y + stage_select_pic.pic.getSize().y / 2 &&
			arrow.getPos().y + arrow.getSize().y / 2 >
			stage_select_pic.pos.y - stage_select_pic.pic.getSize().y / 2 &&
			arrow.getPos().z - arrow.getSize().z / 2 <
			stage_logo_pos_z + stage_logo_size_z / 2 &&
			arrow.getPos().z + arrow.getSize().z / 2 >
			stage_logo_pos_z - stage_logo_size_z / 2){
			mover = SELECT;
		}
	}

	return mover;
}

void cTitle::draw(){

	console() << stage_select_pic.pic.getSize() << std::endl;
	console() << getWindowSize() << std::endl;

	//空間表示
	gl::drawStrokedCube(room.pos, room.size);

	//ロゴ
	gl::draw(logo_pic.pic, logo_pic.pos);

	if (is_ready_title_logo){

		//ステージ選択ロゴの当たり判定可視化用の箱
		gl::color(0.5f, 0.5f, 0.5f);
		gl::drawCube(
			Vec3f(stage_select_pic.pos, stage_logo_pos_z),
			Vec3f(stage_select_pic.pic.getSize(), stage_logo_size_z)
			);
		gl::color(1, 1, 1);

		gl::pushModelView();
		gl::translate(
			-stage_select_pic.pic.getSize().x / 2,
			-stage_select_pic.pic.getSize().y / 2,
			stage_logo_pos_z
			);

		//ステージ選択ロゴ
		gl::draw(stage_select_pic.pic, stage_select_pic.pos);

		gl::popModelView();

	}

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