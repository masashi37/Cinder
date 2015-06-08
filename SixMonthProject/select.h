
#pragma once

#include "common.h"
#include "arrow.h"


class cSelect{

	//�N���X���g����悤��------------------------------

	cRoom room;
	cCollision hit;
	cArrow arrow;
	cParticle particle;

	//font
	Font font;

	//�ϐ�---------------------------------------

	//font��pos
	Vec2f select_pos;			//�Z���N�g
	Vec2f left_select_pos;		//�I����(��)
	Vec2f right_select_pos;		//�I����(�E)

	enum {
		TARGET_MAX = 2,			//�^�[�Q�b�g�̍ő吔
		TARGET_DEPTH = 20		//�^�[�Q�b�g�̃T�C�Y
	};
	Object select_target[TARGET_MAX];	//�I����

	int select_number;				//�I�񂾓�Փx
	int particle_time;				//�p�[�e�B�N���̎���

	bool is_ready_shift;			//�V�t�g�ł��邩�H

public:

	cSelect::cSelect();

	void init();
	void update();
	int shift(int);
	void draw();

	void reStartInit();

	void keyDown(KeyEvent);
	void keyUp(KeyEvent);

};