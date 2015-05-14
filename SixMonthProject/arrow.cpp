
#include "arrow.h"

void cArrow::setup(){

	arrow.pos = { -WIDTH / 2 + 150, 100, 0 };
	arrow.radian = { 0, 0, 0 };

	is_press_space = false;
	is_shooting_arrow = false;

}

void cArrow::update(){

	//��̑��x��ύX����
	if (is_press_space){

		arrow.spped += speed_plus;

		if (arrow.spped > 3 || arrow.spped < 0)
			speed_plus *= -1;


	}
	else arrow.spped = 0;

	//
	if (is_shooting_arrow){

		arrow.pos.x += arrow.spped;

	}

	arrow.pos.x += arrow.spped;

}

void cArrow::keyDown(KeyEvent event){

	if (arrow.radian.z > -70)
		if (event.getCode() == KeyEvent::KEY_w)
			arrow.radian.z -= 1;
	if (arrow.radian.z < 10)
		if (event.getCode() == KeyEvent::KEY_s)
			arrow.radian.z += 1;

	if (event.getCode() == KeyEvent::KEY_SPACE){
		is_press_space = true;
	}

}

void cArrow::keyUp(KeyEvent event){

	if (event.getCode() == KeyEvent::KEY_SPACE){
		is_press_space = false;
		is_shooting_arrow = true;
	}

}

void cArrow::draw(){

	gl::pushModelView();
	gl::translate(Vec2f(arrow.pos.x, arrow.pos.y));
	gl::rotate(arrow.radian);

	gl::drawCube(Vec3f::zero(), arrow.size);

	gl::popModelView();

}