
#pragma once

#include "common.h"


typedef std::shared_ptr<class Arrow>ArrowSP;
class Arrow{

private:

	gl::Texture arrow_pic;

	//�萔--------------------------------------

	//�|�֘A
	enum {
		SPEED_MAX = 40,		//�|�̑��x���E�l
		GAGE_SPACE = 20		//�|�̃`���[�W�Q�[�W�Ƌ|�̊Ԋu
	};

	const Vec3f size_vertical = Vec3f(1.0f, 20.0f, 100.0f);		//�����|�̃T�C�Y
	const Vec3f size_horizontal = Vec3f(20.0f, 1.0f, 100.0f);	//�����|�̃T�C�Y

	//�ϐ�---------------------------------------

	audio::BufferPlayerNodeRef shoot_se;	//�|����������ʉ�
	audio::GainNodeRef gain;				//�{�����[��

	Vec2f back_arrow_pos;		//�|���߂��ė���Ƃ��̈ʒu

	Vec3f pos;					//�|�̍��W
	Vec3f aim_light_begin;		//���C�g�̊J�n
	Vec3f aim_light_end;		//���C�g�̏I��

	Color aim_line_color;		//�Ə��Q�[�W�̐F

	float arrow_speed;			//�|�̑��x
	float acceleration;			//�|�̉����x
	float gravity;				//�d��

	float volume;				//se�̃{�����[��

	bool is_push_button;		//�{�^����push����
	bool is_shoot_arrow;		//�|�������ꂽ���H

public:

	void init();
	void update();
	void draw();

	void mouseDown(MouseEvent);
	void mouseMove(MouseEvent);
	void mouseUp(MouseEvent);

	void setRedColor();			//�|�̏Ə��F�ύX
	void setWhiteColor();		//�|�̏Ə��F�ύX

	Vec3f getPos();				//�|�̃|�W�V�����擾
	Vec3f getSize();			//�|�̃T�C�Y�擾

	bool getIsShooting();		//�|����������ǂ����̎擾

};