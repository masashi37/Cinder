
#include "enemy_breaker_result.h"
#include "scene.h"


cEnemyBreakerResult::cEnemyBreakerResult(){

	result_pos = { -150, HEIGHT / 2 };
	play_time_pos = { -WIDTH - 300, -125 };
	score_pos = { WIDTH, -25 };
	enemy_break_pos = { -WIDTH - 300, 75 };

	time = 0;
	score = 0;
	break_count = 0;

	is_ready_count_anime = false;
	is_ready_time = false;
	is_ready_score = false;
	is_ready_break_count = false;

}

void cEnemyBreakerResult::init(){}

void cEnemyBreakerResult::update(){

	//アニメーション
	if (result_pos.y > -220)
		result_pos.y -= 5.0f;

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

	//カウントアニメ
	if (is_ready_count_anime){

		if (is_ready_time)
			if (time <= cScene::enemy_breaker.getTime())
				time += 60;
		if (is_ready_score)
			if (score <= cScene::enemy_breaker.getScore())
				score++;
		if (is_ready_break_count)
			if (break_count <= cScene::enemy_breaker.getBreakCount())
				break_count++;
	}

}

void cEnemyBreakerResult::shift(){}

void cEnemyBreakerResult::draw(){

	//result
	gl::drawString(
		("R E S U L T"),
		result_pos, Color(0, 0, 1),
		Font(loadAsset("font/HoboStd.otf"), 50)
		);

	//プレイ時間
	gl::drawString(
		("PlayTime : " + std::to_string(time / 60) + " s"),
		play_time_pos, Color(1, 1, 1),
		Font(loadAsset("font/HoboStd.otf"), 50)
		);
	//スコア
	gl::drawString(
		("Score : " + std::to_string(score) + " Point"),
		score_pos, Color(1, 1, 1),
		Font(loadAsset("font/HoboStd.otf"), 50)
		);
	//撃破数
	gl::drawString(
		("Enemy : " + std::to_string(break_count) + " Cube"),
		enemy_break_pos, Color(1, 1, 1),
		Font(loadAsset("font/HoboStd.otf"), 50)
		);

}

void cEnemyBreakerResult::keyDown(KeyEvent event){}

void cEnemyBreakerResult::keyUp(KeyEvent event){}

