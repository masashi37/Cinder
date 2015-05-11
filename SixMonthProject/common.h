
#pragma once

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"

using namespace ci;
using namespace ci::app;


//画面サイズ
enum Window{
	WIDTH = 1000,
	HEIGHT = 500,

	//画面の半分
	SCREEN_HALF_X = WIDTH / 2,
	SCREEN_HALF_Y = HEIGHT / 2,
};

//使う画面サイズ
static struct UsedWindow{
	const Vec3f pos = { 0, 0, -100 };
	const Vec3f size = { WIDTH, HEIGHT, 200 };
}room;//表示空間