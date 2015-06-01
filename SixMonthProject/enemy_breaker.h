
#pragma once

#include "common.h"
#include "arrow.h"
#include <memory>


class cEnemyBreaker{

private:

	//�N���X���g����悤��-------------------------

	cRoom room;
	cCollision hit;
	cArrow arrow;

	//�ϐ�---------------------------------------

	struct EnemyData{
		Vec3f pos;
		Vec3f size;
		float speed;
	};
	std::list<EnemyData>enemy;					//�G
	std::list<EnemyData>::iterator enemy_it;	//�G�̃C�e���[�^�[
	EnemyData enemy_init;						//�G�̏������p

	int life;				//�ϋv��
	int time;				//�G�̏o���𐧌䂷�鎞��
	int score;				//�X�R�A
	int aim_gage;			//�Ə����������Ă邩�̊m�F

	bool aim_is_hit;		//�Ə����������Ă邩�H

	Color aim_gage_color;	//�Ə��Q�[�W�̐F

public:

	cEnemyBreaker::cEnemyBreaker();

	void init();
	void update();
	int shift(int);
	void draw();

	void keyDown(KeyEvent);
	void keyUp(KeyEvent);

};