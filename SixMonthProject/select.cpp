
#include "select.h"


cSelect::cSelect(){

	for (int i = 0; i < TARGET_MAX; ++i){
		select_target[i] = {
			Vec3f(
			-WIDTH / 4.0f + (WIDTH / 2 * i), 0, -room_depth
			),
			Vec3f(WIDTH / 2, HEIGHT, TARGET_DEPTH)
		};
	}

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

				switch (i){
				case 0:		mover = ENEMY_BREAKER;
					break;
				case 1:
					break;
				case 2:
					break;
				}

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

void cSelect::keyDown(KeyEvent event){

	//‹|‚Ì‘€ì
	arrow.keyDown(event);

}

void cSelect::keyUp(KeyEvent event){

	//‹|‚Ì‘€ì
	arrow.keyUp(event);

}