
#pragma once

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"

using namespace ci;
using namespace ci::app;


//��ʃT�C�Y
enum Window{
	WIDTH = 1000,
	HEIGHT = 500,

	//��ʂ̔���
	SCREEN_HALF_X = WIDTH / 2,
	SCREEN_HALF_Y = HEIGHT / 2,
};

//�g����ʃT�C�Y
static struct UsedWindow{
	const Vec3f pos = { 0, 0, -100 };
	const Vec3f size = { WIDTH, HEIGHT, 200 };
}room;//�\�����