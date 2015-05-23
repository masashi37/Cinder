
#include "arrow.h"


void cArrow::setup(){}

void cArrow::update(){

	if (is_press_space)
		this->speed += this->plus_speed;

	switch (key_direction){
	case NONE:
		break;
	case LEFT:
		this->pos.x -= this->move;
		break;
	case RIGHT:
		this->pos.x += this->move;
		break;
	case UP:
		this->pos.y -= this->move;
		break;
	case DOWN:
		this->pos.y += this->move;
		break;
	}

}

void cArrow::shift(){}

void cArrow::draw(){

	gl::drawCube(this->pos, this->size);

}

void cArrow::keyDown(KeyEvent event){

	//弓の移動
	if (event.getCode() == KeyEvent::KEY_KP4)
		key_direction = Key::LEFT;
	if (event.getCode() == KeyEvent::KEY_KP6)
		key_direction = Key::RIGHT;
	if (event.getCode() == KeyEvent::KEY_KP8)
		key_direction = Key::UP;
	if (event.getCode() == KeyEvent::KEY_KP2)
		key_direction = Key::DOWN;

	//パワーチャージ
	if (event.getCode() == KeyEvent::KEY_SPACE){
		is_press_space = true;
	}

}

void cArrow::keyUp(KeyEvent event){

	//弓の移動
	if (event.getCode() != KeyEvent::KEY_KP4)
		key_direction = Key::NONE;
	if (event.getCode() != KeyEvent::KEY_KP6)
		key_direction = Key::NONE;
	if (event.getCode() != KeyEvent::KEY_KP8)
		key_direction = Key::NONE;
	if (event.getCode() != KeyEvent::KEY_KP2)
		key_direction = Key::NONE;

	//パワーチャージ
	if (event.getCode() != KeyEvent::KEY_SPACE){
		is_press_space = false;
		is_shoot_arrow = true;
	}

}

/*
void cArrow::mouseDown(KeyEvent event){}

void cArrow::mouseUp(KeyEvent event){}

void cArrow::mouseMove(KeyEvent event){}
*/