
#pragma once

#include "common.h"
#include "title.h"
#include "select.h"

#include "enemy_breaker.h"
#include "enemy_breaker_result.h"
#include "enemy_breaker2.h"
#include "enemy_breaker_result2.h"


class cScene{

private:

	//クラスを使えるように------------------------------

	cTitle title;
	cSelect select;

	cEnemyBreakerResult enemy_breaker_result;
	cEnemyBreakerResult2 enemy_breaker_result2;

	//変数---------------------------------------

	int scene_mover;	//シーンを切り替えるスイッチ

public:

	static cEnemyBreaker enemy_breaker;
	static cEnemyBreaker2 enemy_breaker2;

	cScene::cScene();

	void init();
	void update();
	void shift();
	void draw();

	void keyDown(KeyEvent);
	void keyUp(KeyEvent);
};