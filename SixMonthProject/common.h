
#pragma once

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"	
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"

using namespace ci;
using namespace ci::app;

enum Window{
	WIDTH = 500,
	HALF_WIDTH = 500 / 2,
	HEIGHT = 500,
	HALF_HEIGHT = HEIGHT / 2
};

//•\Ž¦‹óŠÔ
const float room_depth = 500;
class cRoom{
public:
	Vec3f pos = { 0, 0, -room_depth / 2 };
	Vec3f size = { WIDTH, HEIGHT, room_depth };
};