
#include "select.h"


cSelect::cSelect(){

	for (int i = 0; i < TARGET_MAX; ++i){
		select_target[i] = {
			Vec3f(
			-WIDTH / 2.0f + TARGET_SIZE / 2.0f + (100 * i),
			-HEIGHT / 2.0f + TARGET_SIZE / 2.0f + (100 * i),
			-room_depth + TARGET_SIZE / 2.0f
			),
			Vec3f(TARGET_SIZE, TARGET_SIZE, TARGET_SIZE)
		};
	}

	select_target_number = 0;
}

void cSelect::init(){

	arrow.init();

}

void cSelect::update(){

	arrow.update();

}

int cSelect::shift(int mover){

	for (int i = 0; i < TARGET_MAX; ++i){
		if (arrow.get_is_shooting()){
			if (hit.arrow_is_hit_cube(arrow.getPos(), arrow.getSize(),
				select_target[i].pos, select_target[i].size)){

				select_target_number = i;
				mover = GAME;

			}
		}
	}

	return mover;
}

void cSelect::draw(){

	//‹óŠÔ•\Ž¦
	gl::drawStrokedCube(room.pos, room.size);

	for (int i = 0; i < TARGET_MAX; ++i){
		gl::color(0.5f, 0.5f, 0.5f);
		gl::drawCube(select_target[i].pos, select_target[i].size);
		gl::color(1, 1, 1);
		gl::drawStrokedCube(select_target[i].pos, select_target[i].size);
	}

	//‹|–î
	arrow.draw();

}

int cSelect::get_select_number(int number){
	number = select_target_number;
	return number;
}

void cSelect::keyDown(KeyEvent event){

	//‹|‚Ì‘€ì
	arrow.keyDown(event);

}

void cSelect::keyUp(KeyEvent event){

	//‹|‚Ì‘€ì
	arrow.keyUp(event);

}

/*
void cSelect::mouseDown(KeyEvent event){}

void cSelect::mouseUp(KeyEvent event){}

void cSelect::mouseMove(KeyEvent event){}
*/