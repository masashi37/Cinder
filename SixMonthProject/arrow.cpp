
#include "arrow.h"

void cArrow::setup(){}

void cArrow::update(){

	move.shootPrepare();
	move.shootArrow();

}

void cArrow::mouseDown(MouseEvent event){

	if (event.isLeftDown())
		is_press_left_button = true;

}

void cArrow::mouseUp(MouseEvent event){

	if (!event.isLeftDown()){
		is_press_left_button = false;
		is_shooting_arrow = true;
	}

}

void cArrow::mouseMove(MouseEvent event){

	mouse_pos = Vec3f(event.getPos().xy(), 0);

	degree = toDegrees(move.direction(event));
	arrow_status.radian = { 0, 0, degree };

}

void cArrow::draw(){

	gl::pushModelView();
	gl::translate(arrow_status.pos.xy());

	//if (mouse_pos.x <= arrow_status.pos.x)
	//	arrow_status.radian.z = -arrow_status.radian.z;

	gl::rotate(arrow_status.radian);

	gl::drawCube(Vec3f::zero(), arrow_status.size);

	gl::popModelView();

}