
#include "enemy.h"


cEnemy::cEnemy(){
		/*enemy_plus = {
		Vec3f(
		randFloat(-WIDTH / 2, WIDTH / 2),
		randFloat(-HEIGHT / 2, HEIGHT / 2),
		randFloat(0, 30)),
		Vec3f(
		randFloat(50, 100),
		randFloat(50, 100),
		randFloat(5, 10))
		};

		for (int i = 0; i < enemys.size(); ++i){
		enemys[i] = enemy_plus;
		}*/
}

cEnemy::enemy::enemy(){

	pos = Vec3f::zero();
	size = Vec3f(10, 10, 10);
}

void cEnemy::create(){

	enemys.emplace_back();

	enemy enemy_plus;

	for (unsigned int i = 0; i < enemys.size(); ++i){

		enemy_plus.pos = Vec3f(
			randFloat(-WIDTH / 2, WIDTH / 2),
			randFloat(-HEIGHT / 2, HEIGHT / 2),
			randFloat(0, 30));
		enemy_plus.size = Vec3f(
			randFloat(50, 100),
			randFloat(50, 100),
			randFloat(5, 10));

		enemys[i] = enemy_plus;

	}

}

void cEnemy::draw(){

	for (unsigned int i = 0; i < enemys.size(); ++i){
		gl::color(Color(1, 1, 1));
		gl::drawCube(enemys[i].pos, enemys[i].size);
	}

}