
#pragma once

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"	

#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"

#include "cinder/audio/Context.h"
#include "cinder/audio/SamplePlayerNode.h"

#include "cinder/Rand.h"
#include <ctime>

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

	ENEMY_BREAKER_RESULT,		//リザルト1
};


//class-クラス
//-----------------------------------------------

//表示空間
const float room_depth = 1000;		//部屋のサイズｚ(奥行)
class cRoom{
public:
	Vec3f pos = { 0, 0, -room_depth / 2 };			//空間ポジション
	Vec3f size = { WIDTH, HEIGHT, room_depth };		//空間サイズ
};

//当たり判定
class cCollision{

public:
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

