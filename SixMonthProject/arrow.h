
#pragma once

#include "common.h"


class cArrow{

	gl::Texture arrow_picture;

	//�萔--------------------------------------

	//�|�֘A
	enum {
		SPEED_MAX = 40,
		GAGE_SPACE = 20
	};

	const Vec3f size = { 1.0f, 20.0f, 100.0f };	//�|�̃T�C�Y
	const Vec3f size1 = { 20.0f, 1.0f, 100.0f };
	const float move_speed = 3.0f;				//�|�̓����X�s�[�h

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

	cArrow::cArrow();

	void init();
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