
#pragma once

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"	

#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"

#include "cinder/Rand.h"
#include <ctime>

using namespace ci;
using namespace ci::app;

//ウィンドウサイズ
enum Window{
	WIDTH = 500,
	HALF_WIDTH = 500 / 2,
	HEIGHT = 500,
	HALF_HEIGHT = HEIGHT / 2
};

//表示空間
const float room_depth = 1000;
class cRoom{
public:
	Vec3f pos = { 0, 0, -room_depth / 2 };
	Vec3f size = { WIDTH, HEIGHT, room_depth };
};

//画像
struct TextureData{
	gl::Texture pic;
	Vec2f pos;
};

//オブジェクト
struct Object{
	Vec3f pos;
	Vec3f size;
};