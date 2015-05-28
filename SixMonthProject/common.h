
#pragma once

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"	

#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"

#include "cinder/Rand.h"
#include <ctime>

using namespace ci;
using namespace ci::app;

//�E�B���h�E�T�C�Y
enum Window{
	WIDTH = 500,
	HALF_WIDTH = 500 / 2,
	HEIGHT = 500,
	HALF_HEIGHT = HEIGHT / 2
};

//�\�����
const float room_depth = 1000;
class cRoom{
public:
	Vec3f pos = { 0, 0, -room_depth / 2 };
	Vec3f size = { WIDTH, HEIGHT, room_depth };
};

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
stage_select_pic.pic.bind();
//�摜�̓\��t������
stage_select_pic.pic.unbind();
gl::disable(GL_TEXTURE_2D);*/