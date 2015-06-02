
#include "arrow.h"


cArrow::cArrow(){

	pos = { -(size.x) / 2.0f, -(size.y) / 2.0f, 0.0f };
	aim_light_begin = { Vec3f(pos.xy(), pos.z - size.z / 2) };
	aim_light_end = { Vec3f(pos.xy(), -room_depth) };

	arrow_speed = 0;
	plus_speed = 0.5f;
	gravity = 0.0f;
	gravity_puls = 0.1f;

	key_direction = 0;

	is_push_space = false;
	is_push_left = false;
	is_push_right = false;
	is_push_up = false;
	is_push_down = false;

	is_shoot_arrow = false;

}

void cArrow::init(){
	arrow_picture = loadImage(loadAsset("arrow/arrow.png"));
}

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

			aim_light_begin.x = 0;
			aim_light_end.x = 0;
			aim_light_begin.y = 0;
			aim_light_end.y = 0;

			is_shoot_arrow = false;
		}
	}

	//---------------------------------------------------------------------
	//弓の発射位置変更
	if (!is_shoot_arrow){
		//移動
		if (is_push_left){
			pos.x -= move_speed;
			aim_light_begin.x -= move_speed;
			aim_light_end.x -= move_speed;
		}
		if (is_push_right){
			pos.x += move_speed;
			aim_light_begin.x += move_speed;
			aim_light_end.x += move_speed;
		}
		if (is_push_up){
			pos.y -= move_speed;
			aim_light_begin.y -= move_speed;
			aim_light_end.y -= move_speed;
		}
		if (is_push_down){
			pos.y += move_speed;
			aim_light_begin.y += move_speed;
			aim_light_end.y += move_speed;
		}

		//移動制限
		if (pos.x < -WIDTH / 2){
			pos.x = -WIDTH / 2;
			aim_light_begin.x = pos.x;
			aim_light_end.x = pos.x;
		}
		if (pos.x > WIDTH / 2){
			pos.x = WIDTH / 2;
			aim_light_begin.x = pos.x;
			aim_light_end.x = pos.x;
		}
		if (pos.y < -HEIGHT / 2){
			pos.y = -HEIGHT / 2;
			aim_light_begin.y = pos.y;
			aim_light_end.y = pos.y;
		}
		if (pos.y > HEIGHT / 2){
			pos.y = HEIGHT / 2;
			aim_light_begin.y = pos.y;
			aim_light_end.y = pos.y;
		}
	}

}

void cArrow::shift(){}

void cArrow::draw(){

	gl::enable(GL_TEXTURE_2D);
	arrow_picture.bind();

	//弓矢本体
	gl::drawCube(pos, size);
	gl::drawCube(pos, size1);

	arrow_picture.unbind();
	gl::disable(GL_TEXTURE_2D);

	//矢の照準
	if (!is_shoot_arrow)
		gl::drawLine(aim_light_begin, aim_light_end);

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

Vec3f cArrow::getPos(){
	return pos;
}

Vec3f cArrow::getSize(){
	return size;
}

bool cArrow::get_is_shooting(){
	return is_shoot_arrow;
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