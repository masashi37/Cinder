
#pragma once

#include "common.h"
#include "arrow.h"


class cTitle{

	//�N���X���g����悤��------------------------------

	cRoom room;
	cArrow arrow;

	Rand random;

	//�ϐ�---------------------------------------

	TextureData logo_pic;			//�^�C�g�����S 128*32
	TextureData stage_select_pic;	//�X�e�[�W�I�����S 128*64

	float logo_fadein_speed;		//�^�C�g�����S�̃t�F�[�h�C�����x
	float stage_logo_speed;			//�X�e�[�W�I�����S�̑��x

	bool is_ready_title_logo;		//�^�C�g�����S�̃t�F�[�h�C���������������H

public:

	void setup();
	void update();
	void shift();
	void draw();

	void keyDown(KeyEvent);
	void keyUp(KeyEvent);

	//void mouseDown(MouseEvent);
	//void mouseUp(MouseEvent);
	//void mouseMove(MouseEvent);

};