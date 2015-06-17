
#include "select.h"


cSelect::cSelect(){

	select_pos = { 0, -HEIGHT / 2 + 50 };
	left_select_pos = { -WIDTH / 2 + 20, 0 };
	right_select_pos = { WIDTH / 2 - 20, 0 };
	now_select_pos = { 0, -100 };

	for (int i = 0; i < TARGET_MAX; ++i){
		select_target[i] = {
			Vec3f(
			-WIDTH / 4.0f + (WIDTH / 2 * i), 0, -room_depth
			),
			Vec3f(WIDTH / 2, HEIGHT, TARGET_DEPTH)
		};
	}

	select_number = -1;

	is_ready_shift = false;
}

void cSelect::init(){

	arrow.init();

	//font
	font = Font(loadAsset("font/HoboStd.otf"), 50);

}

void cSelect::update(){

	arrow.update();

	for (int i = 0; i < TARGET_MAX; ++i){
		if (hit.arrow_is_hit_cube(arrow.getPos(), arrow.getSize(),
			select_target[i].pos, select_target[i].size)){

			select_number = i;
			is_ready_shift = true;

		}
	}

	//パーティクル
	particle_time++;
	if (particle_time % (60 * 2) == 0){
		particle.splitCubeInit(Vec3f(
			Rand::randFloat(-WIDTH / 2, WIDTH / 2),
			Rand::randFloat(-HEIGHT / 2, HEIGHT / 2),
			Rand::randFloat(0, -room_depth / 2))
			);
	}

}

int cSelect::shift(int mover){

	if (is_ready_shift){
		if (select_number == 0)
			mover = ENEMY_BREAKER;
		if (select_number == 1)
			mover = ENEMY_BREAKER2;
	}

	return mover;
}

void cSelect::draw(){

	//空間表示
	gl::drawStrokedCube(room.pos, room.size);

	gl::color(0, 0, 0);
	gl::drawCube(Vec3f(0, HEIGHT / 2 + 1, -500), Vec3f(WIDTH, -1, 1000));
	gl::color(1, 1, 1);

	//選択肢
	for (int i = 0; i < TARGET_MAX; ++i){
		gl::color(0.5f, 0.5f, 0.5f);
		gl::drawCube(select_target[i].pos, select_target[i].size);
		gl::color(1, 1, 1);
		gl::drawStrokedCube(select_target[i].pos, select_target[i].size);

		if (arrow.getPos().x < 0)now_select_pos.x = -WIDTH / 4;
		if (arrow.getPos().x >= 0)now_select_pos.x = WIDTH / 4;
	}

	//フォント
	gl::drawStringCentered("S E L E C T",
		select_pos, Color(1, 0, 0), font);

	gl::translate(0, 0, -room_depth);

	gl::drawStringCentered("NOW",
		now_select_pos, Color(1, 0, 0), font);

	gl::drawString("NORMAL",
		left_select_pos, Color(0, 1, 1), font);
	gl::drawStringRight("H A R D",
		right_select_pos, Color(0, 1, 1), font);

	gl::translate(0, 0, room_depth);

	//弓矢
	arrow.draw();

	//----------------------------------------------
	//パーティクル
	particle.splitCubeDraw();

}


void cSelect::reStartInit(){
	is_ready_shift = false;
	select_number = -1;
	arrow.setInit();
}


void cSelect::keyDown(KeyEvent event){

	//弓の操作
	arrow.keyDown(event);

}

void cSelect::keyUp(KeyEvent event){

	//弓の操作
	arrow.keyUp(event);

}