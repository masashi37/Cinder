
#pragma once

#include "common.h"
#include "arrow.h"
#include <memory>


class cEnemyBreaker{

private:

	//�N���X���g����悤��-------------------------

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

	//�ϐ�---------------------------------------

	Vec2f levelup_pos;			//���x���A�b�v��pos
	Vec2f gameover_pos;			//�Q�[���I�[�o�[��pos
	Vec2f game_start_pos;		//�Q�[���X�^�[�g��pos

	//�G�f�[�^
	struct EnemyData{
		Vec3f pos;
		Vec3f size;
		float speed;
		Color color;
	};
	std::list<EnemyData>enemy;					//�G
	std::list<EnemyData>::iterator enemy_it;	//�G�̃C�e���[�^�[
	EnemyData enemy_init;						//�G�̏������p

	int life;					//�ϋv��
	int time;					//�G�̏o���𐧌䂷�鎞��
	int enemy_second;			//�G�̏o��������b��
	int score;					//�X�R�A
	int score_plus;				//�X�R�A�̉��Z��
	int break_count;			//���j��

	int tutorial_time;			//tutorial�̎���

	float aim_gage;				//�Ə��̃T�C�Y
	float enemy_speed_max;		//�G���x�̍ő�l
	float enemy_speed_min;		//�G���x�̍ŏ��l
	float font_alpha;			//font�̃��l
	float font_alpha_plus;		//font�̃��l�̉��Z�l

	bool level_up_is_move;		//level_up�̃A�j���[�V�������ł��邩�H
	bool gameover_is_move;		//gameover�̃A�j���[�V�������ł��邩�H
	bool is_gameover;			//gameover���ǂ����H

	bool is_end_tutorial;		//tutorial�͏I��������H
	bool is_push_back_cube;		//cube�����ꂽ���ǂ����H

	Color score_color_yellow;	//�X�R�A�̐F(��)
	Color score_color_red;		//�X�R�A�̐F(��)
	Color aim_gage_color;		//�Ə��Q�[�W�̐F

public:

	cEnemyBreaker::cEnemyBreaker();

	void init();
	void update();
	int shift(int);
	void draw();

	int getScore();			//�X�R�A�̎擾
	int getTime();			//�ϋv���Ԃ̎擾
	int getBreakCount();	//���j���̎擾

	void reStartInit();

	void keyDown(KeyEvent);
	void keyUp(KeyEvent);

};
