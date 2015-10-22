
#pragma once

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include <vector>

using namespace ci;
using namespace ci::app;
using namespace std;


struct ObjectBase {
	Vec3f mPos;

	ColorA mColor;
};
struct CubeDate :ObjectBase {
	Vec3f mSize;
};
struct CircleDate :ObjectBase {
	float mSize;
};
struct PolygonDate :ObjectBase {
	Vec3f mSecond_pos;
	Vec3f mThird_pos;
};

enum FadePattern {
	//�S��ʂ̃��l�ω���fade
	CUBE_FADE,
	//��ʂ̒��S����~���o�āA�g�k�ƃ��l�ω���fade
	CIRCLE_FADE,
	//��ʏォ�琂�ꖋ(Cube)���o��fade
	VEIL_FADE,
	//�T�C�h�J�[�e���̗l�ɉ�����fade
	//������
	SIDE_CURTAIN_FADE,
	//�Z���^�[�J�[�e���̗l�ɉ�����fade
	//������
	CENTER_CURTAIN_FADE,
	//�s���z�[���^��fade
	//������
	PIN_HALL_FADE,
	//��ʒ��Ɏl�p�������o�ĉ�ʂ𖄂ߐs������fade
	//������
	NOISE_FADE,
	//��ʂ̒��S����O�p���o�Đ�`�ɏ��X�ɓW�J����fade
	//�g�p�ł��Ȃ�(������)
	POLYGON_FADE,

};


class Fade {

private:

	std::vector<CubeDate>mHideCube;
	std::vector<CircleDate>mHideCircle;
	std::vector<PolygonDate>mHidePolygon;


	bool mIsReadyFadeOut;
	bool mIsEndFadeOut;

	bool mIsReadyFadeIn;
	bool mIsEndFadeIn;

	bool mIsEndInit;


	int mPattern;

	const int FADE_INTERVAL = (60 * 2);

	const float FADE_SPEED = (1.0f / FADE_INTERVAL);

public:

	Fade();


	//�uFadeout�v���g�����Ă�
	void fadeOut(const int);

	//�uFadein�v���g�����Ă�
	void fadeIn();

	void draw();

};
