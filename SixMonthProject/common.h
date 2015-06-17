
#pragma once

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"	

//�摜
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"

//��
#include "cinder/audio/Context.h"
#include "cinder/audio/SamplePlayerNode.h"
//����
#include "cinder/audio/NodeEffects.h"

#include "cinder/Rand.h"
#include <ctime>

//�t�H���g
#include "cinder/Font.h"

using namespace ci;
using namespace ci::app;


//enum-�萔
//-----------------------------------------------

//�E�B���h�E�T�C�Y
enum Window{
	WIDTH = 500,
	HALF_WIDTH = 500 / 2,
	HEIGHT = 500,
	HALF_HEIGHT = HEIGHT / 2
};

//�V�[���̖��O(No.)
enum SceneName{
	TITLE,				//�^�C�g��

	SELECT,				//�I��

	ENEMY_BREAKER,		//�Q�[�����1
	ENEMY_BREAKER2,		//�Q�[�����2

	ENEMY_BREAKER_RESULT,		//���U���g1
	ENEMY_BREAKER_RESULT2,		//���U���g2
};


//class-�N���X
//-----------------------------------------------

//�\�����
const float room_depth = 1000;		//�����̃T�C�Y��(���s)
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
	Vec3f pos = { 0, 0, -room_depth / 2 };			//��ԃ|�W�V����
	Vec3f size = { WIDTH*1.5f, HEIGHT, room_depth };		//��ԃT�C�Y

	void starUpdata(){
		star_change_time++;	

		for (auto& stars : star){

			//�ʒu�ƐF�̕ύX
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

			//�ړ�
			stars.star_pos.z += stars.star_move_speed;
			if (stars.star_pos.z > -room_depth / 2)
				stars.star_pos.z = -room_depth;

			//��]
			stars.angle += stars.angle_plus;
		}

	}

	void starDraw(){
		for (auto& stars : star){
			//�`��
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

//�����蔻��
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

//�p�[�e�B�N��
class cParticle{
private:
	enum{ PARTICLE_MAX = 50 };		//�p�[�e�B�N���̍ő吔

	Vec3f pos[PARTICLE_MAX];		//�p�[�e�B�N���|�W�V����
	Vec3f size[PARTICLE_MAX];		//�p�[�e�B�N���T�C�Y
	Vec3f speed[PARTICLE_MAX];		//�p�[�e�B�N�����x
	ColorA color[PARTICLE_MAX];		//�p�[�e�B�N���F

	int clear_time;					//�p�[�e�B�N�����������Ԑ���

	bool is_ready;					//�p�[�e�B�N���̏������ł��Ă��邩�ǂ����H

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

	//�p�[�e�B�N������
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
	//�p�[�e�B�N��
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


//struct-�\����
//-----------------------------------------------

//�摜
struct TextureData{
	gl::Texture pic;	//�摜
	Vec2f pos;			//�\���ʒu
};

//�I�u�W�F�N�g
struct Object{
	Vec3f pos;			//�|�W�V����
	Vec3f size;			//�T�C�Y
};

