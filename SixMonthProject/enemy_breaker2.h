
#pragma once

#include "common.h"
#include "arrow.h"
#include <memory>


class cEnemyBreaker2{

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

	audio::GainNodeRef hit_gain;
	audio::GainNodeRef damage_gain;

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
		Vec3f speed;
		Color color;
		int move_pattern;
		float angle;
	};
	enum MOVE_MODE{
		WAVE,
		SIDE_WAVE
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

	float aim_gage;				//照準のサイズ
	float enemy_speed_max;		//敵速度の最大値
	float enemy_speed_min;		//敵速度の最小値
	float wave_spped;			//敵の速度
	float angle_plus;			//敵の移動変化速度
	float font_alpha;			//fontのα値
	float font_alpha_plus;		//fontのα値の加算値

	bool level_up_is_move;		//level_upのアニメーションができるか？
	bool gameover_is_move;		//gameoverのアニメーションができるか？
	bool is_gameover;			//gameoverかどうか？

	Color aim_gage_color;		//照準ゲージの色

public:

	float volume = 0.5f;

	cEnemyBreaker2::cEnemyBreaker2();

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
