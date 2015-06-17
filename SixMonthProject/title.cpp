
#include "title.h"


cTitle::cTitle(){

	logo_fadein_speed = 5.0f;
	arrow_fadein_speed = 7.5f;
	stage_logo_speed = 3.0f;

	stage_logo_pos_z = -room_depth;
	stage_logo_size_z = 10;

	is_ready_title_logo = false;
	is_in_arrow_pic = false;

}

void cTitle::init(){

	logo_pic = { loadImage(loadAsset("title/logo.png")),
	{ -WIDTH - 300, -HEIGHT / 2 + 100 } };

	stage_select_pic = { loadImage(loadAsset("title/stage_select.png")),
	{ -0, 0 } };

	arrow_pic = { loadImage(loadAsset("title/arrow.png")),
	{ WIDTH / 2 + 100, -HEIGHT / 2 + 120 } };

	//font
	font = Font(loadAsset("font/HoboStd.otf"), 30);
	font_ = Font(loadAsset("font/HoboStd.otf"), 30.5f);

	arrow.init();

}

void cTitle::update(){

	//タイトルロゴの準備が未完了時
	if (!is_ready_title_logo){

		//簡易アニメーションが終了後に準備完了

		//タイトルロゴのアニメ
		logo_pic.pos.x += logo_fadein_speed;
		if (logo_pic.pos.x > 0)
			logo_fadein_speed -= 1.0f;

		if (logo_fadein_speed < 0)
			if (logo_pic.pos.x < -logo_pic.pic.getWidth() / 2){
				logo_fadein_speed = 0;
				is_in_arrow_pic = true;
			}

		//矢のアニメ
		if (is_in_arrow_pic){
			arrow_pic.pos.x -= arrow_fadein_speed;
			if (arrow_pic.pos.x < -arrow_pic.pic.getSize().x / 2 + 5)
				is_ready_title_logo = true;
		}
	}

	//パーティクル
	particle_time++;
	if (particle_time % (60 * 2) == 0){
		particle.splitCubeInit(Vec3f(
			Rand::randFloat(-WIDTH / 2, WIDTH / 2),
			Rand::randFloat(-HEIGHT / 2, HEIGHT / 2),
			Rand::randFloat(0, -room_depth / 2))
			);
	}

	arrow.update();

}

int cTitle::shift(int mover){

	if (is_ready_title_logo){
		if (arrow.get_is_shooting()){
			if (hit.arrow_is_hit_cube(
				arrow.getPos(), arrow.getSize(),
				Vec3f(0, 0, stage_logo_pos_z),
				Vec3f(WIDTH, HEIGHT, stage_logo_size_z))){

				mover = SELECT;

			}
		}
	}

	return mover;
}

void cTitle::draw(){

	//空間表示

	gl::drawStrokedCube(room.pos, room.size);

	gl::color(0, 0, 0);
	gl::drawCube(Vec3f(0, HEIGHT / 2 + 1, -500), Vec3f(WIDTH*1.5f, -1, 1000));
	gl::color(1, 1, 1, 1);

	//ロゴ
	gl::draw(logo_pic.pic, logo_pic.pos);

	//------------------------------------------------
	//アニメーション

	//矢
	gl::draw(arrow_pic.pic, arrow_pic.pos);

	if (is_ready_title_logo){

		//ステージ選択ロゴの当たり判定可視化用の箱
		gl::color(0.5f, 0.5f, 0.5f);
		gl::drawCube(
			Vec3f(stage_select_pic.pos, stage_logo_pos_z),
			Vec3f(WIDTH, HEIGHT, stage_logo_size_z)
			);
		gl::color(1, 1, 1);

		//ステージ選択ロゴ
		gl::pushModelView();
		gl::translate(
			-stage_select_pic.pic.getSize().x / 2.0f,
			-stage_select_pic.pic.getSize().y / 2.0f,
			stage_logo_pos_z
			);

		gl::draw(stage_select_pic.pic, stage_select_pic.pos);

		gl::popModelView();

	}

	//---------------------------------------------------
	//font	
	gl::drawStringCentered(
		"<Arrow operate>",
		Vec2f(0, 70), Color(1, 1, 0), font_);
	gl::drawStringCentered(
		"Move : Press [CROSS KEY]",
		Vec2f(0, 100), Color(1, 1, 0), font_);
	gl::drawStringCentered(
		"Shooting : Press [SPACE KEY]",
		Vec2f(0, 130), Color(1, 1, 0), font_);

	gl::drawStringCentered(
		"<Arrow operate>",
		Vec2f(0, 70), Color(1, 0, 0), font);
	gl::drawStringCentered(
		"Move : Press [CROSS KEY]",
		Vec2f(0, 100), Color(1, 0, 0), font);
	gl::drawStringCentered(
		"Shooting : Press [SPACE KEY]",
		Vec2f(0, 130), Color(1, 0, 0), font);

	//------------------------------------------------
	//弓矢
	arrow.draw();

	//----------------------------------------------
	//パーティクル
	particle.splitCubeDraw();

}

void cTitle::keyDown(KeyEvent event){

	//弓の操作
	arrow.keyDown(event);

}

void cTitle::keyUp(KeyEvent event){

	//弓の操作
	arrow.keyUp(event);

}