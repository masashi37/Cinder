
#include "enemy_breaker_result.h"
#include "scene.h"


cEnemyBreakerResult::cEnemyBreakerResult(){

	result_pos = { 0, HEIGHT / 2 };
	push_enter_pos = { 0, 175 };

	play_time_pos = { -WIDTH - 300, -125 };
	score_pos = { WIDTH, -25 };
	enemy_break_pos = { -WIDTH - 300, 75 };

	font_alpha = 1.0f;
	font_alpha_plus = 0.1f;

	time = 0;
	score = 0;
	break_count = 0;

	is_ready_count_anime = false;

	is_ready_time = false;
	is_ready_score = false;
	is_ready_break_count = false;

	is_ready_shift = false;
	is_push_enter = false;

}

void cEnemyBreakerResult::init(){

	//font
	font50 = Font(loadAsset("font/HoboStd.otf"), 50);

}

void cEnemyBreakerResult::update(){

	//アニメーション
	if (result_pos.y > -220)
		result_pos.y -= 5.0f;

	font_alpha += font_alpha_plus;
	if (font_alpha > 1 || font_alpha < 0)
		font_alpha_plus *= -1;

	if (result_pos.y < play_time_pos.y){
		if (play_time_pos.x < -WIDTH / 2 + 50)
			play_time_pos.x += 8.0f;
		else if (play_time_pos.x == -WIDTH / 2 + 50)
		{
			is_ready_time = true;
		}
	}
	if (result_pos.y < score_pos.y){
		if (score_pos.x > -WIDTH / 2 + 50)
			score_pos.x -= 10.0f;
		else if (score_pos.x == -WIDTH / 2 + 50)
		{
			is_ready_score = true;
		}
	}
	if (result_pos.y < enemy_break_pos.y){
		if (enemy_break_pos.x < -WIDTH / 2 + 50)
			enemy_break_pos.x += 8.0f;
		else if (enemy_break_pos.x == -WIDTH / 2 + 50)
		{
			is_ready_break_count = true;
		}
	}

	if (is_ready_time && is_ready_score && is_ready_break_count)
		is_ready_count_anime = true;

	//カウント
	if (is_ready_count_anime){

		if (is_ready_time)
			if (time < cScene::enemy_breaker.getTime())
				time += 60;
		if (is_ready_score)
			if (score < cScene::enemy_breaker.getScore())
				score++;
		if (is_ready_break_count)
			if (break_count < cScene::enemy_breaker.getBreakCount())
				break_count++;

		if (time >= cScene::enemy_breaker.getTime() &&
			score >= cScene::enemy_breaker.getScore() &&
			break_count >= cScene::enemy_breaker.getBreakCount()){
			is_ready_shift = true;
		}

	}
}

int cEnemyBreakerResult::shift(int mover){

	if (is_push_enter)
		mover = SELECT;

	return mover;
}

void cEnemyBreakerResult::draw(){

	//result
	gl::drawStringCentered(
		("R E S U L T"),
		result_pos, Color(0, 1, 1), font50
		);
	if (is_ready_count_anime){
		//push [Enter]
		gl::drawStringCentered(
			("push [Enter]"),
			push_enter_pos, ColorA(0, 1, 1, font_alpha), font50
			);
	}

	//プレイ時間
	gl::drawString(
		("PlayTime : " + std::to_string(time / 60) + " s"),
		play_time_pos, Color(1, 1, 1), font50
		);
	//スコア
	gl::drawString(
		("Score : " + std::to_string(score) + " Point"),
		score_pos, Color(1, 1, 1), font50
		);
	//撃破数
	gl::drawString(
		("Enemy : " + std::to_string(break_count) + " Cube"),
		enemy_break_pos, Color(1, 1, 1), font50
		);



}


void cEnemyBreakerResult::reStartInit(){

	result_pos = { 0, HEIGHT / 2 };
	push_enter_pos = { 0, 175 };

	play_time_pos = { -WIDTH - 300, -125 };
	score_pos = { WIDTH, -25 };
	enemy_break_pos = { -WIDTH - 300, 75 };

	font_alpha = 1.0f;
	font_alpha_plus = 0.1f;

	time = 0;
	score = 0;
	break_count = 0;

	is_ready_count_anime = false;

	is_ready_time = false;
	is_ready_score = false;
	is_ready_break_count = false;

	is_ready_shift = false;
	is_push_enter = false;

}


void cEnemyBreakerResult::keyDown(KeyEvent event){

	//Enterを押したら選択画面へ
	if (event.getCode() == KeyEvent::KEY_RETURN)
		if (is_ready_shift)
			is_push_enter = true;

}

void cEnemyBreakerResult::keyUp(KeyEvent event){}

