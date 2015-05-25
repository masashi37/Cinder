
#include "arrow.h"


void cArrow::setup(){}

void cArrow::update(){

	//�|����̓`���[�W
	if (is_press_space){
		speed += plus_speed;
		if (speed > SPEED_MAX || speed < 0)
			plus_speed *= -1;
	}
	//�|�̔���
	if (is_shoot_arrow){
		gravity += gravity_puls;
		pos.y += gravity;
		pos.z -= speed;
	}
	//�ǂ̓����蔻��(z��)
	if (pos.z < -room_depth ||
		pos.y > HEIGHT / 2){
		pos = Vec3f::zero();
		gravity = 0.0f;
		speed = 0.0f;
		is_shoot_arrow = false;
	}

	//�|�̔��ˈʒu�ύX
	if (!is_shoot_arrow){
		switch (key_direction){
		case NONE:
			break;
		case LEFT:
			pos.x -= move_speed;
			break;
		case RIGHT:
			pos.x += move_speed;
			break;
		case UP:
			pos.y -= move_speed;
			break;
		case DOWN:
			pos.y += move_speed;
			break;
		}
	}

}

void cArrow::shift(){}

void cArrow::draw(){

	gl::drawCube(this->pos, this->size);

	if (is_press_space){
		gl::drawCube(pos + Vec3f(-GAGE_SPACE, 0, 0), Vec3f(10, speed * 2, 10));
		gl::drawStrokedCube(pos + Vec3f(-GAGE_SPACE, 0, 0), Vec3f(10, SPEED_MAX * 2, 10));
	}
}

void cArrow::keyDown(KeyEvent event){

	//�|�̈ړ�
	if (event.getCode() == KeyEvent::KEY_LEFT)
		key_direction = Key::LEFT;
	if (event.getCode() == KeyEvent::KEY_RIGHT)
		key_direction = Key::RIGHT;
	if (event.getCode() == KeyEvent::KEY_UP)
		key_direction = Key::UP;
	if (event.getCode() == KeyEvent::KEY_DOWN)
		key_direction = Key::DOWN;

	//�p���[�`���[�W
	if (event.getCode() == KeyEvent::KEY_SPACE){
		is_press_space = true;
	}

}

void cArrow::keyUp(KeyEvent event){

	//�|�̈ړ�
	if (event.getCode() == KeyEvent::KEY_LEFT)
		key_direction = Key::NONE;
	if (event.getCode() == KeyEvent::KEY_RIGHT)
		key_direction = Key::NONE;
	if (event.getCode() == KeyEvent::KEY_UP)
		key_direction = Key::NONE;
	if (event.getCode() == KeyEvent::KEY_DOWN)
		key_direction = Key::NONE;

	//�p���[�`���[�W
	if (event.getCode() == KeyEvent::KEY_SPACE){
		is_press_space = false;
		is_shoot_arrow = true;
	}

}

/*
void cArrow::mouseDown(KeyEvent event){}

void cArrow::mouseUp(KeyEvent event){}

void cArrow::mouseMove(KeyEvent event){}
*/