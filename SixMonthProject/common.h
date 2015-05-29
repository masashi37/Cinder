
#pragma once

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"	

#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"

#include "cinder/Rand.h"
#include <ctime>

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
	TITLE,
	SELECT,
	GAME,
	RESULT,
};


//class-�N���X
//-----------------------------------------------

//�\�����
const float room_depth = 1000;		//������z��
class cRoom{
public:
	Vec3f pos = { 0, 0, -room_depth / 2 };
	Vec3f size = { WIDTH, HEIGHT, room_depth };
};

//�����蔻��
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
};


//struct-�\����
//-----------------------------------------------

//�摜
struct TextureData{
	gl::Texture pic;
	Vec2f pos;
};

//�I�u�W�F�N�g
struct Object{
	Vec3f pos;
	Vec3f size;
};



//�摜�̓\��t��
/*gl::enable(GL_TEXTURE_2D);
cube_pic.bind();
//�摜�̓\��t������
cube_pic.unbind();
gl::disable(GL_TEXTURE_2D);*/