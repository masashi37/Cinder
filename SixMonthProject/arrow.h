
#pragma once

#include "common.h"


class cArrow{

	gl::Texture arrow_picture;

	//�萔--------------------------------------

	//�|�֘A
	enum {
		SPEED_MAX = 40,		//�|�̑��x���E�l
		GAGE_SPACE = 20		//�|�̃`���[�W�Q�[�W�Ƌ|�̊Ԋu
	};

	const Vec3f size = { 1.0f, 20.0f, 100.0f };		//�|�̃T�C�Y
	const Vec3f size1 = { 20.0f, 1.0f, 100.0f };	//�|�̃T�C�Y(�\���̂�)
	const float move_speed = 3.0f;					//�|�̓����X�s�[�h

	//�ϐ�---------------------------------------

	audio::BufferPlayerNodeRef shoot_se;

	Vec2f back_arrow_pos;

	Vec3f pos;						//�|�̍��W
	Vec3f aim_light_begin;			//���C�g�̊J�n
	Vec3f aim_light_end;			//���C�g�̏I��

	float arrow_speed;				//�|�̑��x
	float plus_speed;				//�|�̑��x�̕ω��l
	float gravity;					//�d��
	float gravity_puls;				//�d�͂̕ω��l

	int key_direction;				//�|�̓�������

	//�L�[�̔���
	bool is_push_space;				//�X�y�[�X�L�[
	bool is_push_left;				//��
	bool is_push_right;				//�E
	bool is_push_up;				//��
	bool is_push_down;				//��

	bool is_shoot_arrow;			//�|�������ꂽ���H


public:

	cArrow::cArrow();

	void init();
	void update();
	void draw();

	Vec3f getPos();				//�|�̃|�W�V�����擾
	Vec3f getSize();			//�|�̃T�C�Y�擾
	bool get_is_shooting();		//�|����������ǂ����̎擾

	void keyDown(KeyEvent);
	void keyUp(KeyEvent);


};