
#include "arrow.h"


void cArrow::setup(){}

void cArrow::update(){

	if (is_push_space){
		this->speed += this->plus_speed;

	}

}

void cArrow::shift(){}

void cArrow::draw(){

	gl::drawCube(this->pos, this->size);

}

void cArrow::keyDown(KeyEvent event){

	//�|�̈ړ�
	if (event.getCode() == KeyEvent::KEY_KP4)
		this->pos.x -= this->move;
	if (event.getCode() == KeyEvent::KEY_KP6)
		this->pos.x += this->move;
	if (event.getCode() == KeyEvent::KEY_KP8)
		this->pos.y -= this->move;
	if (event.getCode() == KeyEvent::KEY_KP2)
		this->pos.y += this->move;

	//�p���[�`���[�W
	if (event.getCode() == KeyEvent::KEY_SPACE){
		is_push_space = true;
	}

}

void cArrow::keyUp(KeyEvent event){

	//�p���[�`���[�W
	if (event.getCode() == KeyEvent::KEY_SPACE){
		is_push_space = false;
		is_shoot_arrow = true;
	}

}

/*
void cArrow::mouseDown(KeyEvent event){}

void cArrow::mouseUp(KeyEvent event){}

void cArrow::mouseMove(KeyEvent event){}
*/