
#pragma once

#include "common.h"
#include "title.h"
#include "select.h"

#include "enemy_breaker.h"
#include "enemy_breaker_result.h"


class cScene{

private:

	//�N���X���g����悤��------------------------------

	cTitle title;
	cSelect select;

	cEnemyBreakerResult enemy_breaker_result;

	//�ϐ�---------------------------------------

	int scene_mover;	//�V�[����؂�ւ���X�C�b�`

public:

	static cEnemyBreaker enemy_breaker;

	cScene::cScene();

	void init();
	void update();
	void shift();
	void draw();

	void keyDown(KeyEvent);
	void keyUp(KeyEvent);
};