
#include "enemy_breaker.h"


cEnemyBreaker::cEnemyBreaker(){

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
	score_plus = 1;
	break_count = 0;
	aim_gage = 50;
	tutorial_time = 0;

	enemy_speed_max = 3.0f;
	enemy_speed_min = 1.0f;

	level_up_is_move = false;
	gameover_is_move = false;
	is_gameover = false;
	is_end_tutorial = false;
	is_push_back_cube = false;

	aim_gage_color = { 1, 1, 1 };
	score_color_yellow = { 0.2f, 0.2f, 0 };
	score_color_red = { 0.2f, 0, 0 };

}

void cEnemyBreaker::init(){

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

}

void cEnemyBreaker::update(){

	//�`���[�g���A��
	if (!is_end_tutorial){
		tutorial_time++;

		if (tutorial_time % 60 == 0){

			enemy_init.size = Vec3f(100, 100, 100);
			enemy_init.pos = Vec3f(150, 0, -room_depth + enemy_init.size.z / 2);
			enemy_init.color = {
				Rand::randFloat(1),
				Rand::randFloat(1),
				Rand::randFloat(1)
			};

			if (!is_push_back_cube){
				enemy.push_back(enemy_init);
				is_push_back_cube = true;
			}
		}

	}
	else{
		game_start_pos.y += 2.5f;
	}

	//�̗͂��c���Ă���|��\��
	if (life >= 0)
		arrow.update();

	//---------------------------------------------------------------------
	//�G�o��
	if (is_end_tutorial){
		time++;
		if ((time % (60 * enemy_second)) == 0){

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

			enemy_init.speed = Rand::randFloat(enemy_speed_min, enemy_speed_max);

			enemy_init.color = {
				Rand::randFloat(1),
				Rand::randFloat(1),
				Rand::randFloat(1)
			};

			enemy.push_back(enemy_init);
		}
	}

	//---------------------------------------------------------------------
	//�Q�[�����x���A�b�v
	if (time == 60 * ((5 * 10) + 1)){
		enemy_second = 4;
		enemy_speed_min = 1.5f;

		score_plus = 2;

		level_up_is_move = true;
	}
	if (time == 60 * ((5 * 30) + 1)){
		enemy_second = 3;
		enemy_speed_min = 2.0f;
		enemy_speed_max = 3.5f;

		score_plus = 3;

		level_up_is_move = true;
	}
	if (time == 60 * ((5 * 50) + 1)){
		enemy_speed_min = 3.0f;
		enemy_speed_max = 4.0f;

		score_plus = 5;

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
				is_push_back_cube = false;

				//�p�[�e�B�N��
				particle.splitCubeInit(enemyes.pos);
				hit_se->start();		//��

				//���U���g
				if (is_end_tutorial){
					score += score_plus;
					break_count++;
				}

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
			break;
		}
		else{ aim_gage_color = { 1, 1, 1 }; }

		//�G���̂���0�ȉ��ɂȂ�����폜
		if (enemyes.pos.z > 0){
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

int cEnemyBreaker::shift(int mover){

	if (is_gameover)
		mover = ENEMY_BREAKER_RESULT;

	return mover;
}

void cEnemyBreaker::draw(){

	//��ԕ\��
	gl::drawStrokedCube(room.pos, room.size);

	//--------------------------------------------------------------------
	//�`���[�g���A��

	if (!is_end_tutorial){

		gl::drawStringCentered(
			"End tutorial : [Enter]",
			Vec2f(0, HEIGHT / 2 - 70), Color(0, 0, 1), font30);

		if (tutorial_time > 60 * 3){
			gl::drawStringCentered(
				"Aim hit cube : Aim lighting",
				Vec2f(0, 60), Color(1, 0, 0), font30);
			if (tutorial_time > 60 * 5){
				gl::drawStringCentered(
					"Cube  shoot",
					Vec2f(0, 90), Color(1, 0, 0), font30);
			}
		}

	}
	else{
		if (game_start_pos.y > -WIDTH / 2 - 50 &&
			game_start_pos.y < WIDTH / 2 + 50){
			gl::drawStringCentered(
				"Game Start",
				game_start_pos, Color(0, 0, 1), font50);
		}
	}

	//---------------------------------------------------------------------
	//�G
	for (auto& enemyes : enemy){
		//�G�ړ�
		enemyes.pos.z += enemyes.speed;
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

	//---------------------------------------------------------------------
	//�Ə��Q�[�W
	gl::color(aim_gage_color);

	gl::drawSolidCircle(Vec2f(WIDTH / 2.0f, HEIGHT / 2.0f), (float)aim_gage);
	gl::drawStringRight(
		"A I M",
		Vec2f(WIDTH / 2 - 50, HEIGHT / 2 - 30),
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


int cEnemyBreaker::getScore(){
	return score;
}

int cEnemyBreaker::getTime(){
	return time;
}

int cEnemyBreaker::getBreakCount(){
	return break_count;
}


void cEnemyBreaker::reStartInit(){

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
	score_plus = 1;
	break_count = 0;
	aim_gage = 50;

	enemy_speed_max = 3.0f;
	enemy_speed_min = 1.0f;

	level_up_is_move = false;
	gameover_is_move = false;
	is_gameover = false;

	aim_gage_color = { 1, 1, 1 };
	score_color_yellow = { 0.2f, 0.2f, 0 };
	score_color_red = { 0.2f, 0, 0 };

	enemy.clear();

	arrow.setInit();

}


void cEnemyBreaker::keyDown(KeyEvent event){

	//�|�̑���
	if (life >= 0)
		arrow.keyDown(event);

	//�`���[�g���A���̏I��
	if (!is_end_tutorial)
		if (event.getCode() == KeyEvent::KEY_RETURN){
			is_end_tutorial = true;
			enemy.clear();
		}

	if (event.getCode() == KeyEvent::KEY_l)
		life = -1;

}

void cEnemyBreaker::keyUp(KeyEvent event){

	//�|�̑���
	if (life >= 0)
		arrow.keyUp(event);

}

