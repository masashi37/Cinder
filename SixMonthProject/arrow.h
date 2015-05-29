
#pragma once

#include "common.h"


class cArrow{

	//�萔--------------------------------------

	//�|�֘A
	enum {
		SPEED_MAX = 40,
		GAGE_SPACE = 20
	};

	//�L�[����
	enum Key{
		NONE,
		LEFT, RIGHT,
		UP, DOWN
	};

	const Vec3f size = { 10.0f, 10.0f, 100.0f };	//�|�̃T�C�Y
	const float move_speed = 3.0f;					//�|�̓����X�s�[�h

	//�ϐ�---------------------------------------

	Vec3f pos = { -(size.x) / 2.0f, -(size.y) / 2.0f, 0.0f };	//�|�̍��W

	float arrow_speed = 0;			//�|�̑��x
	float plus_speed = 0.5f;		//�|�̑��x�̕ω��l
	float gravity = 0.0f;			//�d��
	float gravity_puls = 0.1f;		//�d�͂̕ω��l

	int key_direction = 0;			//�|�̓�������

	//�L�[�̔���
	bool is_push_space = false;		//�X�y�[�X�L�[
	bool is_push_left = false;		//��
	bool is_push_right = false;		//�E
	bool is_push_up = false;		//��
	bool is_push_down = false;		//��

	bool is_shoot_arrow = false;	//�|�������ꂽ���H


public:

	void setup();
	void update();
	void shift();
	void draw();

	Vec3f getPos();
	Vec3f getSize();
	bool get_is_shooting();

	void keyDown(KeyEvent);
	void keyUp(KeyEvent);

	//void mouseDown(MouseEvent);
	//void mouseUp(MouseEvent);
	//void mouseMove(MouseEvent);

};