
#pragma once

#include "common.h"
#include "enemy_breaker.h"
#include "cinder/Font.h"


class cEnemyBreakerResult{

private:    

	//font
	Font font50;

	//�ϐ�---------------------------------------

	//font��pos
	Vec2f result_pos;			//���U���g
	Vec2f push_enter_pos;		//push [Enter]

	Vec2f play_time_pos;		//�v���C����
	Vec2f score_pos;			//�X�R�A
	Vec2f enemy_break_pos;		//���j��

	float font_alpha;			//font�̃��l
	float font_alpha_plus;		//font�̃��l�̉��Z�l

	int time;					//�v���C����
	int score;					//�X�R�A
	int break_count;			//���j��

	bool is_ready_count_anime;	//�J�E���g�A�j���̏������ł��Ă邩�ǂ����H

	bool is_ready_time;			//���ԃJ�E���g�̏������ł��Ă邩�ǂ����H
	bool is_ready_score;		//�X�R�A�J�E���g�̏������ł��Ă邩�ǂ����H
	bool is_ready_break_count;	//���j���J�E���g�̏������ł��Ă邩�ǂ����H

	bool is_ready_shift;		//�V�t�g���\���ǂ����H
	bool is_push_enter;			//�G���^�[�������ꂽ���ǂ����H

public:

	cEnemyBreakerResult::cEnemyBreakerResult();

	void init();
	void update();
	int shift(int);
	void draw();

	void reStartInit();

	void keyDown(KeyEvent);
	void keyUp(KeyEvent);
};