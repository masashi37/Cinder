
#include "Arrow.h"


void Arrow::init() {

	pos.z = 0;
	aim_light_begin.z = pos.z - 50;
	aim_light_end.z = -DEPTH;

	aim_line_color = Color(1, 1, 1);

	arrow_speed = Vec3f(0.0f, 0.0f, 0.0f);
	acceleration = 0.5f;
	gravity = 0.1f;

	is_push_button = false;
	is_shoot_arrow = false;

	arrow_pic = loadImage(loadAsset("arrow/arrow.png"));

	//SE
	//--------------------------------------------------

	auto ctx = audio::Context::master();

	audio::SourceFileRef sourceFile = audio::load(loadAsset("se/arrow_shoot.wav"));
	audio::BufferRef buffer = sourceFile->loadBuffer();
	shoot_se = ctx->makeNode(new audio::BufferPlayerNode(buffer));
	gain = ctx->makeNode(new audio::GainNode(volume));

	shoot_se >> gain >> ctx->getOutput();

	ctx->enable();
}

void Arrow::update() {

	//gain->setValue(volume);

	//弓を放つ力チャージ
	if (!is_shoot_arrow) {

		if (is_push_button) {
			//チャージ中、弓の速度を変更
			arrow_speed.z += acceleration;
			if (arrow_speed.z > SPEED_MAX || arrow_speed.z < 0)
				acceleration *= -1;
		}
		else { arrow_speed.z = -arrow_speed.z; }
	}
	//弓の発射
	else {

		//チャージ後、弓に重力をかけて発射
		arrow_speed.y += gravity;
		pos += Vec3f(arrow_speed.xy(), -arrow_speed.z);

		//壁の当たり判定(奥と底)
		if (pos.z < -DEPTH || pos.y > HEIGHT / 2) {
			//当たったら、弓関係の数値を初期化
			pos = { back_arrow_pos.x, back_arrow_pos.y, 0 };
			arrow_speed = Vec3f::zero();

			is_shoot_arrow = false;
		}
	}

}

void Arrow::draw() {

	gl::enable(GL_TEXTURE_2D);
	arrow_pic.bind();

	//弓矢本体
	gl::drawCube(pos, size_vertical);
	gl::drawCube(pos, size_horizontal);

	arrow_pic.unbind();
	gl::disable(GL_TEXTURE_2D);

	//矢を見やすく
	gl::color(aim_line_color);
	gl::drawStrokedCircle(mouse_pos, 20);

	gl::color(1, 1, 1);

	//チャージ中
	if (!is_shoot_arrow) {
		//矢の照準
		gl::drawLine(aim_light_begin, aim_light_end);

		if (is_push_button) {
			//チャージゲージ
			gl::drawCube(
				pos + Vec3f((pos.x >= 0) ? -(float)GAGE_SPACE : (float)GAGE_SPACE, 0, 0),
				Vec3f(10, arrow_speed.z * 2, 10));
			//チャージゲージの枠
			gl::drawStrokedCube(
				pos + Vec3f((pos.x >= 0) ? -(float)GAGE_SPACE : (float)GAGE_SPACE, 0, 0),
				Vec3f(10, SPEED_MAX * 2, 10));
		}
	}
}


void Arrow::mouseDown(MouseEvent event) {

	//パワーチャージ
	if (event.isLeftDown()) {
		is_push_button = true;
	}

	//ボリューム
	/*
	if (event.getWheelIncrement){
	if (volume >= 0.0f){
	volume += 0.1f;
	}
	if (volume > 1.0f)volume = 1.0f;
	}
	if (event.getCode() == KeyEvent::KEY_z){
	if (volume <= 1.0f){
	volume -= 0.1f;
	}
	if (volume < 0.0f)volume = 0.0f;
	}
	//event.getWheelIncrement?
	*/

}

void Arrow::mouseMove(MouseEvent event) {

	mouse_pos = event.getPos() - getWindowSize() / 2;

	if (!is_shoot_arrow) {
		pos.x = (float)mouse_pos.x;
		pos.y = (float)mouse_pos.y;
	}

	aim_light_begin.x = aim_light_end.x = pos.x;
	aim_light_begin.y = aim_light_end.y = pos.y;

	//画面外にでたか判定

}

void Arrow::mouseUp(MouseEvent event) {

	//パワーチャージ終了
	if (!event.isLeftDown()) {

		if (!is_shoot_arrow) {
			shoot_se->start();		//SE
			back_arrow_pos.x = (float)event.getPos().x - getWindowSize().x / 2;
			back_arrow_pos.y = (float)event.getPos().y - getWindowSize().y / 2;
		}

		is_push_button = false;
		is_shoot_arrow = true;
	}

}


void Arrow::setRedColor() {
	aim_line_color = { Color(1, 0, 0) };
}

void Arrow::setWhiteColor() {
	aim_line_color = { Color(1, 1, 1) };
}

Vec3f Arrow::getPos() {
	return pos;
}

Vec3f Arrow::getSize() {
	return Vec3f(
		size_horizontal.x, size_vertical.y, 100);
}

bool Arrow::getIsShooting() {
	return is_shoot_arrow;
}