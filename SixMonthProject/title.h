
#pragma once

#include "common.h"
#include "arrow.h"


class cTitle{

	cRoom room;
	cArrow arrow;

	TextureData logo_pic;			//�^�C�g�����S 128*32
	TextureData stage_select_pic;	//�X�e�[�W�I�����S 128*64

	bool is_ready_title_logo = false;
	float logo_speed = 5.0f;

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