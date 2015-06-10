
#include "enemy_breaker2.h"


cEnemyBreaker2::cEnemyBreaker2(){

	levelup_pos = { WIDTH, 0 };
	gameover_pos = { 0, -HEIGHT };
	game_start_pos = { 0, -HEIGHT / 2 - 30 };

	enemy_init = {
		Vec3f(0, 0, 0), Vec3f(0, 0, 0)
	};

	life = 5;
	time = 0;
	enemy_second = 5;
	score = 0;
	score_plus = 2;
	break_count = 0;
	aim_gage = 0;

	enemy_speed_max = 1.0f;
	enemy_speed_min = 0.5f;
	wave_spped = 3.0f;
	angle_plus = 0.05f;

	level_up_is_move = false;
	gameover_is_move = false;
	is_gameover = false;

	aim_gage_color = { 1, 1, 1 };

}

void cEnemyBreaker2::init(){

	arrow.init();

	//font
	font50 = Font(loadAsset("font/HoboStd.otf"), 50);
	font30 = Font(loadAsset("font/HoboStd.otf"), 30);

	//SE
	//--------------------------------------------------

	// �o�̓f�o�C�X���Q�b�g
	auto ctx = audio::Context::master();

	// �I�[�f�B�I�f�[�^��ǂݍ���ŏ�����
	audio::SourceFileRef sourceFile = audio::load(loadAsset("se/arrow_hit.wav"));
	audio::BufferRef buffer = sourceFile->loadBuffer();
	hit_se = ctx->makeNode(new audio::BufferPlayerNode(buffer));

	// �ǂݍ��񂾃I�[�f�B�I���o�̓f�o�C�X�Ɋ֘A�t���Ă���
	hit_se >> ctx->getOutput();

	// �o�̓f�o�C�X��L���ɂ���
	ctx->enable();



	// �o�̓f�o�C�X���Q�b�g
	auto ctx1 = audio::Context::master();

	// �I�[�f�B�I�f�[�^��ǂݍ���ŏ�����
	audio::SourceFileRef sourceFile1 = audio::load(loadAsset("se/explosion.wav"));
	audio::BufferRef buffer1 = sourceFile->loadBuffer();
	damage_se = ctx1->makeNode(new audio::BufferPlayerNode(buffer));

	// �ǂݍ��񂾃I�[�f�B�I���o�̓f�o�C�X�Ɋ֘A�t���Ă���
	damage_se >> ctx1->getOutput();

	// �o�̓f�o�C�X��L���ɂ���
	ctx1->enable();

}

void cEnemyBreaker2::update(){

	game_start_pos.y += 2.5f;

	//�̗͂��c���Ă���|��\��
	if (life >= 0)
		arrow.update();

	//---------------------------------------------------------------------
	//�G�o��
	time++;
	if ((time % (60 * enemy_second)) == 0){

		enemy_init.size = Vec3f(50, 50, 50);

		enemy_init.move_pattern =
			Rand::randInt(0, 2);
		
		int a = 0;
		a++;

		enemy_init.angle = 1;

		switch (enemy_init.move_pattern){
		case WAVE:
			enemy_init.pos = Vec3f(
				Rand::randFloat(-WIDTH / 2 + enemy_init.size.y / 2,
				WIDTH / 2 - enemy_init.size.y / 2),
				0,
				-room_depth + enemy_init.size.z / 2
				);

			enemy_init.speed = {
				0, wave_spped,
				Rand::randFloat(enemy_speed_min, enemy_speed_max)
			};
			break;
		case SIDE_WAVE:
			enemy_init.pos = Vec3f(
				0,
				Rand::randFloat(-HEIGHT / 2 + enemy_init.size.x / 2,
				HEIGHT / 2 - enemy_init.size.x / 2),
				-room_depth + enemy_init.size.z / 2
				);

			enemy_init.speed = {
				wave_spped, 0,
				Rand::randFloat(enemy_speed_min, enemy_speed_max)
			};
			break;
		}

		enemy_init.color = {
			Rand::randFloat(1),
			Rand::randFloat(1),
			Rand::randFloat(1)
		};

		enemy.push_back(enemy_init);
	}

	//---------------------------------------------------------------------
	//�Q�[�����x���A�b�v
	if (time == 60 * (60 + 1)){
		enemy_second = 3;
		enemy_speed_min = 1.0f;
		enemy_speed_max = 1.5f;

		score_plus = 3;

		life++;

		level_up_is_move = true;
	}
	if (time == 60 * (120 + 1)){
		enemy_second = 3;
		enemy_speed_min = 2.0f;
		enemy_speed_max = 3.0f;

		score_plus = 5;

		life++;

		level_up_is_move = true;
	}
	if (time == 60 * (180 + 1)){
		enemy_second = 2;

		score_plus = 10;

		life++;

		level_up_is_move = true;
	}

	//---------------------------------------------------------------------
	//levelup�A�j��
	if (levelup_pos.x < -WIDTH)
		level_up_is_move = false;
	if (level_up_is_move)
		levelup_pos.x -= 2.0f;
	else{ levelup_pos.x = WIDTH; }

	//---------------------------------------------------------------------
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

				//�p�[�e�B�N��
				particle.splitCubeInit(enemyes.pos);
				hit_se->start();		//��

				//���U���g
				score += score_plus;
				break_count++;

				continue;

			}
		}

		//�Ə��Ƃ̓����蔻��
		if (hit.aim_is_hit_cube(
			Vec2f(arrow.getPos().x, arrow.getPos().y),
			Vec2f(arrow.getSize().x, arrow.getSize().y),
			Vec2f(enemyes.pos.x, enemyes.pos.y),
			Vec2f(enemyes.size.x, enemyes.size.y))){
			aim_gage_color = enemyes.color;
			arrow.setRedColor();
			break;
		}
		else{ 
			aim_gage_color = { 1, 1, 1 };
			arrow.setWhiteColor();
		}

		//�G���̂���0�ȉ��ɂȂ�����폜
		if (enemyes.pos.z > 0){
			hit.explosionUpData(Vec2f(enemyes.pos.x, enemyes.pos.y));
			damage_se->start();
			enemy_it = enemy.erase(enemy_it);
			life--;
			continue;
		}

		++enemy_it;
	}

	//---------------------------------------------------------------------
	//life��0��gameover
	if (life < 0){
		gameover_is_move = true;
		gameover_pos.y += 2.0f;
	}
	if (gameover_pos.y > HEIGHT / 2)
		is_gameover = true;

}

int cEnemyBreaker2::shift(int mover){

	if (is_gameover)
		mover = ENEMY_BREAKER_RESULT2;

	return mover;
}

void cEnemyBreaker2::draw(){

	//��ԕ\��
	gl::drawStrokedCube(room.pos, room.size);

	//��Փx
	gl::drawStringCentered(
		"H A R D",
		Vec2f(0, -HEIGHT / 2), Color(1, 1, 1), font30);

	//�Q�[���X�^�[�g�̍��}
	if (game_start_pos.y > -WIDTH / 2 - 50 &&
		game_start_pos.y < WIDTH / 2 + 50){
		gl::drawStringCentered(
			"Game Start",
			game_start_pos, Color(0, 1, 1), font50);
	}

	//---------------------------------------------------------------------
	//�G
	for (auto& enemyes : enemy){
		//�G�ړ�
		enemyes.angle += angle_plus;
		enemyes.pos += Vec3f(
			sin(enemyes.angle) * enemyes.speed.x,
			sin(enemyes.angle) * enemyes.speed.y,
			enemyes.speed.z);
		gl::color(enemyes.color);
		gl::drawCube(enemyes.pos, enemyes.size);
		gl::color(0.5f, 0.5f, 0.5f);
		gl::drawStrokedCube(enemyes.pos, enemyes.size);
		gl::color(1, 1, 1);
	}

	//---------------------------------------------------------------------
	//���C�t�|�C���g
	gl::color(0, 1, 0);

	gl::drawSolidCircle(Vec2f(-WIDTH / 2.0f, -HEIGHT / 2.0f), life * 10.0f);
	gl::drawString(
		"LIFE " + std::to_string(life),
		Vec2f(-WIDTH / 2, -HEIGHT / 2 + life * 10.0f),
		Color(0, 1, 0), font30);

	gl::color(1, 1, 1);

	//���C�t�|�C���g�����₷��
	for (int i = 0; i < life + 1; ++i){
		gl::drawStrokedCircle(Vec2f(-WIDTH / 2.0f, -HEIGHT / 2.0f), 10.0f * i);
	}

	//�_���[�W���o
	hit.explosionDraw();

	//---------------------------------------------------------------------
	//�Ə��Q�[�W
	gl::color(aim_gage_color);

	gl::drawSolidCircle(Vec2f(WIDTH / 2.0f, HEIGHT / 2.0f), aim_gage);
	gl::drawStringRight(
		"A I M",
		Vec2f(WIDTH / 2 - aim_gage, HEIGHT / 2 - 30),
		Color(1, 0, 0), font30);

	gl::color(1, 1, 1);

	//---------------------------------------------------------------------

	//�X�R�A
	gl::drawStringRight(
		"SCORE " + std::to_string(score),
		Vec2f(WIDTH / 2, -HEIGHT / 2),
		Color(1, 1, 0), font30);

	//---------------------------------------------------------------------
	//levelup�A�j��
	if (level_up_is_move){
		gl::drawString(
			("LEVEL UP"), levelup_pos, Color(1, 0, 0), font30
			);
	}

	//gameover�A�j��
	if (gameover_is_move){
		gl::drawStringCentered(
			("GAME OVER"), gameover_pos, Color(1, 0, 0), font50
			);
	}

	//---------------------------------------------------------------------
	//�p�[�e�B�N��
	particle.splitCubeDraw();

	//---------------------------------------------------------------------
	//�|��
	if (life >= 0)
		arrow.draw();

}


int cEnemyBreaker2::getScore(){
	return score;
}

int cEnemyBreaker2::getTime(){
	return time;
}

int cEnemyBreaker2::getBreakCount(){
	return break_count;
}


void cEnemyBreaker2::reStartInit(){

	levelup_pos = { WIDTH, 0 };
	gameover_pos = { 0, -HEIGHT };
	game_start_pos = { 0, -HEIGHT / 2 - 30 };

	enemy_init = {
		Vec3f(0, 0, 0), Vec3f(0, 0, 0)
	};

	life = 5;
	time = 0;
	enemy_second = 5;
	score = 0;
	score_plus = 2;
	break_count = 0;
	aim_gage = 100;

	enemy_speed_max = 1.0f;
	enemy_speed_min = 0.5f;

	level_up_is_move = false;
	gameover_is_move = false;
	is_gameover = false;

	aim_gage_color = { 1, 1, 1 };


	enemy.clear();

	arrow.setInit();

}


void cEnemyBreaker2::keyDown(KeyEvent event){

	//�|�̑���
	if (life >= 0)
		arrow.keyDown(event);

}

void cEnemyBreaker2::keyUp(KeyEvent event){

	//�|�̑���
	if (life >= 0)
		arrow.keyUp(event);

}

