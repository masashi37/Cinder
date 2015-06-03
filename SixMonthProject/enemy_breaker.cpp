
#include "enemy_breaker.h"


cEnemyBreaker::cEnemyBreaker(){

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

	aim_is_hit = false;
	level_up_is_move = false;
	is_gameover = false;

	aim_gage_color = { 1, 1, 1 };
	score_color_yellow = { 0.2f, 0.2f, 0 };
	score_color_red = { 0.2f, 0, 0 };

}

void cEnemyBreaker::init(){

	level_up_pic = {
		loadImage(loadAsset("enemy_breaker/levelup.png")),
		Vec2f(WIDTH, 0)
	};

	gameover_pic = {
		loadImage(loadAsset("enemy_breaker/gameover.png")),
		Vec2f(-WIDTH / 2, -HEIGHT)
	};

	arrow.init();

}

void cEnemyBreaker::update(){

	if (life >= 0)
		arrow.update();

	//---------------------------------------------------------------------
	//敵出現
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

		enemy.push_back(enemy_init);
	}

	//---------------------------------------------------------------------
	//ゲームレベルアップ
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

	//---------------------------------------------------------------------
	//levelupアニメ
	if (level_up_pic.pos.x < -WIDTH)
		level_up_is_move = false;
	if (level_up_is_move)
		level_up_pic.pos.x--;
	else{ level_up_pic.pos.x = WIDTH; }

	//---------------------------------------------------------------------
	//敵のイテレーター作成
	enemy_it = enemy.begin();

	while (enemy_it != enemy.end()){
		//敵の情報を代入
		auto enemyes = *(enemy_it);

		//敵と矢の当たり
		if (arrow.get_is_shooting()){
			if (hit.arrow_is_hit_cube(
				arrow.getPos(), arrow.getSize(),
				enemyes.pos, enemyes.size)){

				//敵を削除
				enemy_it = enemy.erase(enemy_it);
				score += score_plus;
				break_count++;

				//パーティクル
				particle.splitCubeInit(enemyes.pos);

				continue;

			}
		}

		//照準との当たり判定
		if (hit.aim_is_hit_cube(
			Vec2f(arrow.getPos().x, arrow.getPos().y),
			Vec2f(arrow.getSize().x, arrow.getSize().y),
			Vec2f(enemyes.pos.x, enemyes.pos.y),
			Vec2f(enemyes.size.x, enemyes.size.y))){
			aim_is_hit = true;
		}
		else{ aim_is_hit = false; }

		//敵がのｚが0以下になったら削除
		if (enemyes.pos.z > 0){
			enemy_it = enemy.erase(enemy_it);
			//life--;
			score += 10;
			continue;
		}

		++enemy_it;
	}

	//---------------------------------------------------------------------
	//lifeが0でgameover
	if (life < 0)
		gameover_pic.pos.y++;
	if (gameover_pic.pos.y > HEIGHT / 2)
		is_gameover = true;

	//---------------------------------------------------------------------
	//一番最後に出てきた敵にのみ反応する照準
	if (aim_is_hit)
		aim_gage_color = { 1, 0, 0 };
	else{ aim_gage_color = { 1, 1, 1 }; }

}

int cEnemyBreaker::shift(int mover){

	if (is_gameover)
		mover = ENEMY_BREAKER_RESULT;

	return mover;
}

void cEnemyBreaker::draw(){

	//空間表示
	gl::drawStrokedCube(room.pos, room.size);

	//---------------------------------------------------------------------
	//敵
	for (auto& enemyes : enemy){
		//敵移動
		enemyes.pos.z += enemyes.speed;

		gl::drawCube(enemyes.pos, enemyes.size);
		gl::color(0.5f, 0.5f, 0.5f);
		gl::drawStrokedCube(enemyes.pos, enemyes.size);
		gl::color(1, 1, 1);
	}

	//---------------------------------------------------------------------
	//ライフポイント
	gl::color(0, 1, 0);
	gl::drawSolidCircle(Vec2f(-WIDTH / 2.0f, -HEIGHT / 2.0f), life * 10.0f);
	gl::color(1, 1, 1);

	//ライフポイントを見やすく
	for (int i = 0; i < life + 1; ++i){
		gl::drawStrokedCircle(Vec2f(-WIDTH / 2.0f, -HEIGHT / 2.0f), 10.0f * i);
	}

	//---------------------------------------------------------------------
	//照準ゲージ
	gl::color(aim_gage_color);
	gl::drawSolidCircle(Vec2f(WIDTH / 2.0f, HEIGHT / 2.0f), (float)aim_gage);
	gl::color(1, 1, 1);

	//---------------------------------------------------------------------
	//スコア
	if (score <= SCORE_BREAK){
		gl::color(score_color_yellow);
		gl::drawSolidCircle(
			Vec2f(WIDTH / 2.0f, -HEIGHT / 2.0f), (float)score * 5);
	}
	else if (score <= SCORE_BREAK * 2){
		gl::color(score_color_red);
		gl::drawSolidCircle(
			Vec2f(WIDTH / 2.0f, -HEIGHT / 2.0f), (float)((score - SCORE_BREAK) * 5));
	}
	else if (score <= SCORE_BREAK * 3){
		gl::color(score_color_yellow * 2);
		gl::drawSolidCircle(
			Vec2f(WIDTH / 2.0f, -HEIGHT / 2.0f), (float)((score - SCORE_BREAK * 2) * 5));
	}
	else if (score <= SCORE_BREAK * 4){
		gl::color(score_color_red * 2);
		gl::drawSolidCircle(
			Vec2f(WIDTH / 2.0f, -HEIGHT / 2.0f), (float)((score - SCORE_BREAK * 3) * 5));
	}
	else if (score <= SCORE_BREAK * 5){
		gl::color(score_color_yellow * 3);
		gl::drawSolidCircle(
			Vec2f(WIDTH / 2.0f, -HEIGHT / 2.0f), (float)((score - SCORE_BREAK * 4) * 5));
	}
	else if (score <= SCORE_BREAK * 6){
		gl::color(score_color_red * 3);
		gl::drawSolidCircle(
			Vec2f(WIDTH / 2.0f, -HEIGHT / 2.0f), (float)((score - SCORE_BREAK * 5) * 5));
	}
	else if (score <= SCORE_BREAK * 7){
		gl::color(score_color_yellow * 4);
		gl::drawSolidCircle(
			Vec2f(WIDTH / 2.0f, -HEIGHT / 2.0f), (float)((score - SCORE_BREAK * 6) * 5));
	}
	else if (score <= SCORE_BREAK * 8){
		gl::color(score_color_red * 4);
		gl::drawSolidCircle(
			Vec2f(WIDTH / 2.0f, -HEIGHT / 2.0f), (float)((score - SCORE_BREAK * 7) * 5));
	}
	else if (score <= SCORE_BREAK * 9){
		gl::color(score_color_yellow * 5);
		gl::drawSolidCircle(
			Vec2f(WIDTH / 2.0f, -HEIGHT / 2.0f), (float)((score - SCORE_BREAK * 8) * 5));
	}
	else if (score <= SCORE_BREAK * 10){
		gl::color(score_color_red * 5);
		gl::drawSolidCircle(
			Vec2f(WIDTH / 2.0f, -HEIGHT / 2.0f), (float)((score - SCORE_BREAK * 9) * 5));
	}
	gl::color(1, 1, 1);

	//スコアを分かりやすく
	for (int i = 0; i < 21; ++i){
		gl::drawStrokedCircle(Vec2f(WIDTH / 2.0f, -HEIGHT / 2.0f), (float)(5.0f * i));
	}

	//---------------------------------------------------------------------
	//levelupアニメ
	gl::draw(level_up_pic.pic, level_up_pic.pos);

	//gameoverアニメ
	gl::draw(gameover_pic.pic, gameover_pic.pos);

	//---------------------------------------------------------------------
	//パーティクル
	particle.splitCubeDraw();

	//---------------------------------------------------------------------
	//弓矢
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


void cEnemyBreaker::keyDown(KeyEvent event){

	//弓の操作
	if (life >= 0)
		arrow.keyDown(event);

}

void cEnemyBreaker::keyUp(KeyEvent event){

	//弓の操作
	if (life >= 0)
		arrow.keyUp(event);

}