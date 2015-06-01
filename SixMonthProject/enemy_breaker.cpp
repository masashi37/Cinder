
#include "enemy_breaker.h"


cEnemyBreaker::cEnemyBreaker(){

	enemy_init = {
		Vec3f(0, 0, 0), Vec3f(0, 0, 0)
	};

	life = 5;
	time = 0;
	score = 0;
	aim_gage = 50;

	aim_is_hit = false;

	aim_gage_color = { 1, 1, 1 };

}

void cEnemyBreaker::init(){

	arrow.init();

}

void cEnemyBreaker::update(){

	arrow.update();

	//�G�o��
	time++;
	if ((time % (60 * 5)) == 0){

		enemy_init.size = Vec3f(
			Rand::randFloat(30, 80),
			Rand::randFloat(30, 80),
			Rand::randFloat(30, 80)
			);
		enemy_init.pos = Vec3f(
			Rand::randFloat(-WIDTH / 2 + enemy_init.size.x / 2, WIDTH / 2 - enemy_init.size.x / 2),
			Rand::randFloat(-HEIGHT / 2 + enemy_init.size.y / 2, HEIGHT / 2 - enemy_init.size.y / 2),
			-room_depth + enemy_init.size.z / 2
			);

		enemy_init.speed = Rand::randFloat(1.0f, 2.0f);

		enemy.push_back(enemy_init);
	}

	//�G�̃C�e���[�^�[�쐬
	enemy_it = enemy.begin();

	while (enemy_it != enemy.end()){
		//�G�̏�����
		auto enemyes = *(enemy_it);

		//�G�Ɩ�̓�����
		if (arrow.get_is_shooting()){
			if (hit.arrow_is_hit_cube(
				arrow.getPos(), arrow.getSize(),
				enemyes.pos, enemyes.size)){

				//�G���폜
				enemy_it = enemy.erase(enemy_it);
				continue;

			}
		}

		if (hit.aim_is_hit_cube(
			Vec2f(arrow.getPos().x, arrow.getPos().y),
			Vec2f(arrow.getSize().x, arrow.getSize().y),
			Vec2f(enemyes.pos.x, enemyes.pos.y),
			Vec2f(enemyes.size.x, enemyes.size.y))){
			aim_is_hit = true;
		}
		else{ aim_is_hit = false; }

		//�G���̂���0�ȉ��ɂȂ�����폜
		if (enemyes.pos.z > 0){
			enemy_it = enemy.erase(enemy_it);
			life--;
			continue;
		}

		++enemy_it;
	}

	if (aim_is_hit)
		aim_gage_color = { 1, 0, 0 };
	else{ aim_gage_color = { 1, 1, 1 }; }

}

int cEnemyBreaker::shift(int mover){
	
		if (life == 0)
		mover = RESULT;
		
	return mover;
}

void cEnemyBreaker::draw(){

	//��ԕ\��
	gl::drawStrokedCube(room.pos, room.size);

	//�G
	for (auto& enemyes : enemy){
		//�G�ړ�
		enemyes.pos.z += enemyes.speed;

		gl::drawCube(enemyes.pos, enemyes.size);
		gl::color(0.5f, 0.5f, 0.5f);
		gl::drawStrokedCube(enemyes.pos, enemyes.size);
		gl::color(1, 1, 1);
	}

	//���C�t�|�C���g
	gl::color(0, 1, 0);
	gl::drawSolidCircle(Vec2f(-WIDTH / 2.0f, -HEIGHT / 2.0f), life * 10.0f);
	gl::color(1, 1, 1);

	//�Ə��Q�[�W
	gl::color(aim_gage_color);
	gl::drawSolidCircle(Vec2f(WIDTH / 2.0f, HEIGHT / 2.0f), (float)aim_gage);
	gl::color(1, 1, 1);

	//�|��
	arrow.draw();

}

void cEnemyBreaker::keyDown(KeyEvent event){

	//�|�̑���
	arrow.keyDown(event);

}

void cEnemyBreaker::keyUp(KeyEvent event){

	//�|�̑���
	arrow.keyUp(event);

}