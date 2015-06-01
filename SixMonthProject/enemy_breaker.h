
#pragma once

#include "common.h"
#include "arrow.h"
#include <memory>


class cEnemyBreaker{

private:

	//クラスを使えるように-------------------------

	cRoom room;
	cCollision hit;
	cArrow arrow;

	//変数---------------------------------------

	struct EnemyData{
		Vec3f pos;
		Vec3f size;
		float speed;
	};
	std::list<EnemyData>enemy;					//敵
	std::list<EnemyData>::iterator enemy_it;	//敵のイテレーター
	EnemyData enemy_init;						//敵の初期化用

	int life;				//耐久力
	int time;				//敵の出現を制御する時間
	int score;				//スコア
	int aim_gage;			//照準が当たってるかの確認

	bool aim_is_hit;		//照準が当たってるか？

	Color aim_gage_color;	//照準ゲージの色

public:

	cEnemyBreaker::cEnemyBreaker();

	void init();
	void update();
	int shift(int);
	void draw();

	void keyDown(KeyEvent);
	void keyUp(KeyEvent);

};