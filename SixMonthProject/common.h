
#pragma once

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"	

//画像
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"

//音
#include "cinder/audio/Context.h"
#include "cinder/audio/SamplePlayerNode.h"
//音量
#include "cinder/audio/NodeEffects.h"

#include "cinder/Rand.h"
#include <ctime>

//フォント
#include "cinder/Font.h"

using namespace ci;
using namespace ci::app;


//enum-定数
//-----------------------------------------------

//ウィンドウサイズ
enum Window{
	WIDTH = 500,
	HALF_WIDTH = 500 / 2,
	HEIGHT = 500,
	HALF_HEIGHT = HEIGHT / 2
};

//シーンの名前(No.)
enum SceneName{
	TITLE,				//タイトル

	SELECT,				//選択

	ENEMY_BREAKER,		//ゲーム画面1
	ENEMY_BREAKER2,		//ゲーム画面2

	ENEMY_BREAKER_RESULT,		//リザルト1
	ENEMY_BREAKER_RESULT2,		//リザルト2
};


//class-クラス
//-----------------------------------------------

//表示空間
const float room_depth = 1000;		//部屋のサイズｚ(奥行)
class cRoom{
private:
	enum { STAR_MAX = 150 };

	struct Star{
		Vec3f star_pos;
		Color star_color;
		float angle = 0;
		float star_move_speed = 50.0f;
		const float angle_plus = 0.1f;
		const float star_size = 3.0f;
	};
	Star star[STAR_MAX];

	int star_change_time = 0;


public:
	Vec3f pos = { 0, 0, -room_depth / 2 };			//空間ポジション
	Vec3f size = { WIDTH*1.5f, HEIGHT, room_depth };		//空間サイズ

	void starUpdata(){
		star_change_time++;	

		for (auto& stars : star){

			//位置と色の変更
			if (star_change_time % 60 * 2 == 0){
				stars.star_pos = {
					Rand::randFloat(-WIDTH / 2 * 3, WIDTH / 2 * 3),
					Rand::randFloat(-HEIGHT / 2 * 3, HEIGHT / 2 * 3),
					Rand::randFloat(0, -room_depth)
				};
				stars.star_color = { Color(
					Rand::randFloat(0, 1),
					Rand::randFloat(0, 1),
					Rand::randFloat(0, 1))
				};
			}

			//移動
			stars.star_pos.z += stars.star_move_speed;
			if (stars.star_pos.z > -room_depth / 2)
				stars.star_pos.z = -room_depth;

			//回転
			stars.angle += stars.angle_plus;
		}

	}

	void starDraw(){
		for (auto& stars : star){
			//描画
			gl::rotate(Vec3f(0, 0, stars.angle));
			gl::color(stars.star_color);

			//gl::drawSphere(stars.star_pos, stars.star_size);
			gl::drawLine(stars.star_pos,
				Vec3f(stars.star_pos.x, stars.star_pos.y, stars.star_pos.z - 100));

			gl::color(1, 1, 1);
			gl::rotate(Vec3f(0, 0, -stars.angle));
		}
	}

};

//当たり判定
class cCollision{
private:
	Vec2f explosion_pos;
	float explosion_size;
	bool is_damage;
public:
	cCollision::cCollision(){
		explosion_size = 0;
		is_damage = false;
	}

	//Cube & Arrow
	bool arrow_is_hit_cube(
		Vec3f arrow_pos, Vec3f arrow_size,
		Vec3f cube_pos, Vec3f cube_size){

		bool is_hit = false;

		if (arrow_pos.x - arrow_size.x / 2 < cube_pos.x + cube_size.x / 2 &&
			arrow_pos.x + arrow_size.x / 2 > cube_pos.x - cube_size.x / 2 &&
			arrow_pos.y - arrow_size.y / 2 < cube_pos.y + cube_size.y / 2 &&
			arrow_pos.y + arrow_size.y / 2 > cube_pos.y - cube_size.y / 2 &&
			arrow_pos.z - arrow_size.z / 2 < cube_pos.z + cube_size.z / 2 &&
			arrow_pos.z + arrow_size.z / 2 > cube_pos.z - cube_size.z / 2){
			is_hit = true;
		}

		return is_hit;
	}
	//Cube & Aim
	bool aim_is_hit_cube(
		Vec2f arrow_pos, Vec2f arrow_size,
		Vec2f cube_pos, Vec2f cube_size){

		bool is_hit = false;

		if (arrow_pos.x - arrow_size.x / 2 < cube_pos.x + cube_size.x / 2 &&
			arrow_pos.x + arrow_size.x / 2 > cube_pos.x - cube_size.x / 2 &&
			arrow_pos.y - arrow_size.y / 2 < cube_pos.y + cube_size.y / 2 &&
			arrow_pos.y + arrow_size.y / 2 > cube_pos.y - cube_size.y / 2){
			is_hit = true;
		}

		return is_hit;
	}

	//Cube Erase
	void explosionUpData(Vec2f cube_pos){
		if (!is_damage){
			explosion_pos = Vec2f(cube_pos.x, cube_pos.y);
			is_damage = true;
		}
	}
	void explosionDraw(){

		if (is_damage){

			if (explosion_size < 50.0f){

				explosion_size++;

				gl::color(0.8f, 0, 0);
				gl::drawSolidCircle(
					explosion_pos, explosion_size);
				gl::color(1, 1, 1);

			}
			else if (explosion_size >= 50.0f){
				is_damage = false;
				explosion_size = 0;
			}
		}
	}

};

//パーティクル
class cParticle{
private:
	enum{ PARTICLE_MAX = 50 };		//パーティクルの最大数

	Vec3f pos[PARTICLE_MAX];		//パーティクルポジション
	Vec3f size[PARTICLE_MAX];		//パーティクルサイズ
	Vec3f speed[PARTICLE_MAX];		//パーティクル速度
	ColorA color[PARTICLE_MAX];		//パーティクル色

	int clear_time;					//パーティクルを消す時間制御

	bool is_ready;					//パーティクルの準備ができているかどうか？

public:

	cParticle::cParticle(){

		clear_time = 0;

		is_ready = false;

		for (int i = 0; i < PARTICLE_MAX; ++i){
			pos[i] = Vec3f::zero();
			size[i] = Vec3f::zero();
			speed[i] = Vec3f::zero();
			color[i] = { 0, 0, 0, 1 };
		}

	}

	//パーティクル準備
	void splitCubeInit(Vec3f particle_pos){

		if (!is_ready){
			for (int i = 0; i < PARTICLE_MAX; ++i){
				pos[i] = particle_pos;
				size[i] = { 10, 10, 10 };
				speed[i] = {
					Rand::randFloat(-5, 5),
					Rand::randFloat(-5, 5),
					Rand::randFloat(-5, 5)
				};
				color[i] = {
					Rand::randFloat(0, 1),
					Rand::randFloat(0, 1),
					Rand::randFloat(0, 1),
					1
				};
			}
			is_ready = true;
		}

	}
	//パーティクル
	void splitCubeDraw(){

		if (is_ready){
			if (clear_time <= 60){
				for (int i = 0; i < PARTICLE_MAX; ++i){
					gl::color(color[i]);
					gl::drawCube(pos[i], size[i]);
					gl::color(1, 1, 1);

					pos[i] += speed[i];
					if (color[i].a >= 0)
						color[i].a -= 0.02f;
				}

				clear_time++;

			}
			else{
				clear_time = 0;
				is_ready = false;
			}
		}

	}

};


//struct-構造体
//-----------------------------------------------

//画像
struct TextureData{
	gl::Texture pic;	//画像
	Vec2f pos;			//表示位置
};

//オブジェクト
struct Object{
	Vec3f pos;			//ポジション
	Vec3f size;			//サイズ
};

