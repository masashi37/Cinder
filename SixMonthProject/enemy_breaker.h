
#pragma once

#include "common.h"
#include "arrow.h"
#include <memory>


class cEnemyBreaker{

private:

	//�N���X���g����悤��-------------------------

	cRoom room;
	cCollision hit;
	cParticle particle;
	cArrow arrow;

	//�萔---------------------------------------

	const int SCORE_BREAK = 20;			//�X�R�A�̋�؂�

	//�ϐ�---------------------------------------

	TextureData level_up_pic;			//���x���A�b�v�̉摜�̃f�[�^
	TextureData gameover_pic;			//�Q�[���I�[�o�[�̉摜�̃f�[�^

	//�G�f�[�^
	struct EnemyData{
		Vec3f pos;
		Vec3f size;
		float speed;
	};
	std::list<EnemyData>enemy;					//�G
	std::list<EnemyData>::iterator enemy_it;	//�G�̃C�e���[�^�[
	EnemyData enemy_init;						//�G�̏������p

	int life;					//�ϋv��
	int time;					//�G�̏o���𐧌䂷�鎞��
	int enemy_second;			//�G�̏o��������b��
	int score;					//�X�R�A
	int aim_gage;				//�Ə����������Ă邩�̊m�F

	float enemy_speed_max;		//�G���x�̍ő�l
	float enemy_speed_min;		//�G���x�̍ŏ��l

	bool aim_is_hit;			//�Ə����������Ă邩�H
	bool level_up_is_move;		//level_up�̃A�j���[�V�������I��������H
	bool is_gameover;			//gameover���ǂ����H

	Color score_color;			//�X�R�A�̐F
	Color aim_gage_color;		//�Ə��Q�[�W�̐F

public:

	cEnemyBreaker::cEnemyBreaker();

	void init();
	void update();
	int shift(int);
	void draw();

	void keyDown(KeyEvent);
	void keyUp(KeyEvent);

};