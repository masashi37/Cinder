
#pragma once

#include "common.h"
#include "arrow.h"


class cTitle{

	//�N���X���g����悤��------------------------------

	cRoom room;
	cArrow arrow;

	Rand random;

	//�ϐ�---------------------------------------

	TextureData logo_pic;			//�^�C�g�����S
	TextureData stage_select_pic;	//�X�e�[�W�I�����S

	float logo_fadein_speed;		//�^�C�g�����S�̃t�F�[�h�C�����x
	float stage_logo_speed;			//�X�e�[�W�I�����S�̑��x

	float stage_logo_pos_z = -room_depth;
	float stage_logo_size_z = 10;

	bool is_ready_title_logo;		//�^�C�g�����S�̃t�F�[�h�C���������������H

public:

	void setup();
	void update();
	int shift(int);
	void draw();

	void keyDown(KeyEvent);
	void keyUp(KeyEvent);

	//void mouseDown(MouseEvent);
	//void mouseUp(MouseEvent);
	//void mouseMove(MouseEvent);

};