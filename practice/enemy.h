
#pragma once

#include "common.h"
#include "cinder/Rand.h"


class cEnemy{

private:

	struct enemy{
		Vec3f pos;
		Vec3f size;

		enemy();
	};

	std::vector<enemy> enemys;	//�G�l�~�[

public:

	cEnemy();

	void create();
	void draw();

};