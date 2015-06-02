
#pragma once

#include "common.h"
#include "title.h"
#include "select.h"
#include "enemy_breaker.h"


class cScene{

private:

	//�N���X���g����悤��------------------------------

	cTitle title;
	cSelect select;
	cEnemyBreaker enemy_breaker;

	//�ϐ�---------------------------------------

	int scene_mover;	//�V�[����؂�ւ���X�C�b�`

public:

	cScene::cScene();

	void init();
	void update();
	void shift();
	void draw();

	void keyDown(KeyEvent);
	void keyUp(KeyEvent);
};