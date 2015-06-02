
#pragma once

#include "common.h"
#include "arrow.h"


class cSelect{

	//�N���X���g����悤��------------------------------

	cRoom room;
	cCollision hit;
	cArrow arrow;

	//�ϐ�---------------------------------------

	enum {
		TARGET_MAX = 3,			//�^�[�Q�b�g�̍ő吔
		TARGET_SIZE = 150		//�^�[�Q�b�g�̃T�C�Y
	};
	Object select_target[TARGET_MAX];	//�I����

public:

	cSelect::cSelect();

	void init();
	void update();
	int shift(int);
	void draw();

	void keyDown(KeyEvent);
	void keyUp(KeyEvent);

};