
#pragma once

#include "common.h"
#include "arrow.h"
#include <memory>


class cEnemyBreaker{

private:

	//クラスを使えるように-------------------------

	//creat
	cRoom room;
	cCollision hit;
	cParticle particle;
	cArrow arrow;

	//sound
	audio::BufferPlayerNodeRef hit_se;
	audio::BufferPlayerNodeRef damage_se;

	//font
	Font font50;
	Font font30;

	//変数---------------------------------------

	Vec2f levelup_pos;			//レベルアップのpos
	Vec2f gameover_pos;			//ゲームオーバーのpos
	Vec2f game_start_pos;		//ゲームスタートのpos

	//敵データ
	struct EnemyData{
		Vec3f pos;
		Vec3f size;
		float speed;
		Color color;
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

	int tutorial_time;			//tutorialの時間

	float aim_gage;				//照準のサイズ
	float enemy_speed_max;		//敵速度の最大値
	float enemy_speed_min;		//敵速度の最小値
	float font_alpha;			//fontのα値
	float font_alpha_plus;		//fontのα値の加算値

	bool level_up_is_move;		//level_upのアニメーションができるか？
	bool gameover_is_move;		//gameoverのアニメーションができるか？
	bool is_gameover;			//gameoverかどうか？

	bool is_end_tutorial;		//tutorialは終わったか？
	bool is_push_back_cube;		//cubeが作られたかどうか？

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

	void reStartInit();

	void keyDown(KeyEvent);
	void keyUp(KeyEvent);

};
