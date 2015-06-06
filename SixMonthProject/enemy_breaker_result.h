
#pragma once

#include "common.h"
#include "enemy_breaker.h"
#include "cinder/Font.h"


class cEnemyBreakerResult{

private:

	//font
	Font font50;

	//変数---------------------------------------

	//fontのpos
	Vec2f result_pos;			//リザルト
	Vec2f push_enter_pos;		//push [Enter]

	Vec2f play_time_pos;		//プレイ時間
	Vec2f score_pos;			//スコア
	Vec2f enemy_break_pos;		//撃破数

	int time;					//プレイ時間
	int score;					//スコア
	int break_count;			//撃破数
	int push_enter_show_time;	//push [Enter]

	bool is_ready_count_anime;	//カウントアニメの準備ができてるかどうか？
	bool is_ready_time;			//時間カウントの準備ができてるかどうか？
	bool is_ready_score;		//スコアカウントの準備ができてるかどうか？
	bool is_ready_break_count;	//撃破数カウントの準備ができてるかどうか？
	bool is_push_enter;			//エンターが押されたかどうか？


public:

	cEnemyBreakerResult::cEnemyBreakerResult();

	void init();
	void update();
	int shift(int);
	void draw();

	void keyDown(KeyEvent);
	void keyUp(KeyEvent);
};