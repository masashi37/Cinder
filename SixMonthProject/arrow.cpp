
#include "arrow.h"

void cArrow::setup(){

	arrow.pos = { -WIDTH / 2 + 150, 100, 0 };
	arrow.radian = { 0, 0, 0 };
	arrow.spped = 0;

	is_press_space = false;
	is_shooting_arrow = false;

}

void cArrow::update(){

	//ƒtƒ‰ƒO“à‘€ì

}

void cArrow::mouseDown(MouseEvent event){

	//isLeftDown -> isPress ON

}

void cArrow::mouseUp(MouseEvent event){

	//isLeftUp -> 
	//		isPress OFF
	//		isShooting ON

}

void cArrow::mouseMove(MouseEvent event){

	mouse_pos = event.getPos();
	
	arrow.radian.z =
		move.direction(event, Vec2f(arrow.pos.x, arrow.pos.y));

}

void cArrow::draw(){

	gl::pushModelView();
	gl::translate(Vec2f(arrow.pos.x, arrow.pos.y));
	gl::rotate(arrow.radian);

	gl::drawCube(Vec3f::zero(), arrow.size);

	gl::popModelView();

}