
#pragma once

#include "common.h"
#include "title.h"
#include "select.h"
#include "enemy_breaker.h"


class cScene{

private:

	cTitle title;
	cSelect select;
	cEnemyBreaker enemy_breaker;

	int scene_mover;	//シーンを切り替えるスイッチ

public:

	cScene::cScene();

	void init();
	void update();
	void shift();
	void draw();

	void keyDown(KeyEvent);
	void keyUp(KeyEvent);
};