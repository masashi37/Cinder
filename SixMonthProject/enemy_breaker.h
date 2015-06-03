
#pragma once

#include "common.h"
#include "arrow.h"
#include <memory>


class cEnemyBreaker{

private:

	//クラスを使えるように-------------------------

	cRoom room;
	cCollision hit;
	cParticle particle;
	cArrow arrow;

	//定数---------------------------------------

	const int SCORE_BREAK = 20;			//スコアの区切り

	//変数---------------------------------------

	TextureData level_up_pic;			//レベルアップの画像のデータ
	TextureData gameover_pic;			//ゲームオーバーの画像のデータ

	//敵データ
	struct EnemyData{
		Vec3f pos;
		Vec3f size;
		float speed;
	};
	std::list<EnemyData>enemy;					//敵
	std::list<EnemyData>::iterator enemy_it;	//敵のイテレーター
	EnemyData enemy_init;						//敵の初期化用

	int life;					//耐久力
	int time;					//敵の出現を制御する時間
	int enemy_second;			//敵の出現させる秒数
	int score;					//スコア
	int score_plus;				//スコアの加算数
	int break_count;			//撃破数
	int aim_gage;				//照準が当たってるかの確認

	float enemy_speed_max;		//敵速度の最大値
	float enemy_speed_min;		//敵速度の最小値

	bool aim_is_hit;			//照準が当たってるか？
	bool level_up_is_move;		//level_upのアニメーションが終わったか？
	bool is_gameover;			//gameoverかどうか？

	Color score_color_yellow;	//スコアの色(黄)
	Color score_color_red;		//スコアの色(赤)
	Color aim_gage_color;		//照準ゲージの色

public:

	cEnemyBreaker::cEnemyBreaker();

	void init();
	void update();
	int shift(int);
	void draw();

	int getScore();			//スコアの取得
	int getTime();			//耐久時間の取得
	int getBreakCount();	//撃破数の取得

	void keyDown(KeyEvent);
	void keyUp(KeyEvent);

};