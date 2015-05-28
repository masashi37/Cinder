
#include "arrow.h"


void cArrow::setup(){}

void cArrow::update(){

	//弓を放つ力チャージ
	if (!is_shoot_arrow){
		if (is_push_space){
			//チャージ中、弓の速度を変更
			arrow_speed += plus_speed;
			if (arrow_speed > SPEED_MAX || arrow_speed < 0)
				plus_speed *= -1;
		}
	}
	//弓の発射
	if (is_shoot_arrow){
		//チャージ後、弓に重力をかけて発射
		gravity += gravity_puls;
		pos.y += gravity;
		pos.z -= arrow_speed;

		//壁の当たり判定(奥と底)
		if (pos.z < -room_depth || pos.y > HEIGHT / 2){
			//当たったら、弓関係の数値を初期化
			pos = Vec3f::zero();
			gravity = 0.0f;
			arrow_speed = 0.0f;
			is_shoot_arrow = false;
		}
	}

	//弓の発射位置変更
	if (!is_shoot_arrow){
		if (is_push_left)
			pos.x -= move_speed;
		if (is_push_right)
			pos.x += move_speed;
		if (is_push_up)
			pos.y -= move_speed;
		if (is_push_down)
			pos.y += move_speed;

		if (pos.x < -WIDTH / 2)
			pos.x = -WIDTH / 2;
		if (pos.x + size.x > WIDTH / 2)
			pos.x = WIDTH / 2 - size.x;
		if (pos.y < -HEIGHT / 2)
			pos.y = -HEIGHT / 2;
		if (pos.y + size.y > HEIGHT / 2)
			pos.y = HEIGHT / 2 - size.y;
	}

}

void cArrow::shift(){}

void cArrow::draw(){

	//弓矢本体
	gl::drawCube(pos, size);

	//チャージ中
	if (is_push_space){
		//チャージゲージ
		gl::drawCube(
			pos + Vec3f((pos.x >= 0) ? -(float)GAGE_SPACE : (float)GAGE_SPACE, 0, 0),
			Vec3f(10, arrow_speed * 2, 10));
		//チャージゲージの枠
		gl::drawStrokedCube(
			pos + Vec3f((pos.x >= 0) ? -(float)GAGE_SPACE : (float)GAGE_SPACE, 0, 0),
			Vec3f(10, SPEED_MAX * 2, 10));
	}
}

void cArrow::keyDown(KeyEvent event){

	//弓の移動
	if (event.getCode() == KeyEvent::KEY_LEFT)
		is_push_left = true;
	if (event.getCode() == KeyEvent::KEY_RIGHT)
		is_push_right = true;
	if (event.getCode() == KeyEvent::KEY_UP)
		is_push_up = true;
	if (event.getCode() == KeyEvent::KEY_DOWN)
		is_push_down = true;

	//パワーチャージ
	if (event.getCode() == KeyEvent::KEY_SPACE){
		is_push_space = true;
	}

}

void cArrow::keyUp(KeyEvent event){

	//弓の移動終了
	if (event.getCode() == KeyEvent::KEY_LEFT)
		is_push_left = false;
	if (event.getCode() == KeyEvent::KEY_RIGHT)
		is_push_right = false;
	if (event.getCode() == KeyEvent::KEY_UP)
		is_push_up = false;
	if (event.getCode() == KeyEvent::KEY_DOWN)
		is_push_down = false;

	//パワーチャージ終了
	if (event.getCode() == KeyEvent::KEY_SPACE){
		is_push_space = false;
		is_shoot_arrow = true;
	}

}

/*
void cArrow::mouseDown(KeyEvent event){}

void cArrow::mouseUp(KeyEvent event){}

void cArrow::mouseMove(KeyEvent event){}
*/