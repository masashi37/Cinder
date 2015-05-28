
#include "arrow.h"


void cArrow::setup(){}

void cArrow::update(){

	//�|����̓`���[�W
	if (!is_shoot_arrow){
		if (is_push_space){
			//�`���[�W���A�|�̑��x��ύX
			arrow_speed += plus_speed;
			if (arrow_speed > SPEED_MAX || arrow_speed < 0)
				plus_speed *= -1;
		}
	}
	//�|�̔���
	if (is_shoot_arrow){
		//�`���[�W��A�|�ɏd�͂������Ĕ���
		gravity += gravity_puls;
		pos.y += gravity;
		pos.z -= arrow_speed;

		//�ǂ̓����蔻��(���ƒ�)
		if (pos.z < -room_depth || pos.y > HEIGHT / 2){
			//����������A�|�֌W�̐��l��������
			pos = Vec3f::zero();
			gravity = 0.0f;
			arrow_speed = 0.0f;
			is_shoot_arrow = false;
		}
	}

	//�|�̔��ˈʒu�ύX
	if (!is_shoot_arrow){
		if (is_push_left)
			pos.x -= move_speed;
		if (is_push_right)
			pos.x += move_speed;
		if (is_push_up)
			pos.y -= move_speed;
		if (is_push_down)
			pos.y += move_speed;

		if (pos.x < -WIDTH / 2)
			pos.x = -WIDTH / 2;
		if (pos.x + size.x > WIDTH / 2)
			pos.x = WIDTH / 2 - size.x;
		if (pos.y < -HEIGHT / 2)
			pos.y = -HEIGHT / 2;
		if (pos.y + size.y > HEIGHT / 2)
			pos.y = HEIGHT / 2 - size.y;
	}

}

void cArrow::shift(){}

void cArrow::draw(){

	//�|��{��
	gl::drawCube(pos, size);

	//�`���[�W��
	if (is_push_space){
		//�`���[�W�Q�[�W
		gl::drawCube(
			pos + Vec3f((pos.x >= 0) ? -(float)GAGE_SPACE : (float)GAGE_SPACE, 0, 0),
			Vec3f(10, arrow_speed * 2, 10));
		//�`���[�W�Q�[�W�̘g
		gl::drawStrokedCube(
			pos + Vec3f((pos.x >= 0) ? -(float)GAGE_SPACE : (float)GAGE_SPACE, 0, 0),
			Vec3f(10, SPEED_MAX * 2, 10));
	}
}

void cArrow::keyDown(KeyEvent event){

	//�|�̈ړ�
	if (event.getCode() == KeyEvent::KEY_LEFT)
		is_push_left = true;
	if (event.getCode() == KeyEvent::KEY_RIGHT)
		is_push_right = true;
	if (event.getCode() == KeyEvent::KEY_UP)
		is_push_up = true;
	if (event.getCode() == KeyEvent::KEY_DOWN)
		is_push_down = true;

	//�p���[�`���[�W
	if (event.getCode() == KeyEvent::KEY_SPACE){
		is_push_space = true;
	}

}

void cArrow::keyUp(KeyEvent event){

	//�|�̈ړ��I��
	if (event.getCode() == KeyEvent::KEY_LEFT)
		is_push_left = false;
	if (event.getCode() == KeyEvent::KEY_RIGHT)
		is_push_right = false;
	if (event.getCode() == KeyEvent::KEY_UP)
		is_push_up = false;
	if (event.getCode() == KeyEvent::KEY_DOWN)
		is_push_down = false;

	//�p���[�`���[�W�I��
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