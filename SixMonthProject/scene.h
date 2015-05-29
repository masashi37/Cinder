
#pragma once

#include "common.h"
#include "title.h"
#include "select.h"


class cScene{

private:

	cTitle title;
	cSelect select;

	int scene_mover;	//�V�[����؂�ւ���X�C�b�`

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