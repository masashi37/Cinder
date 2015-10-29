
#pragma once

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"

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
	FULL_SCREEN_FADE,

	//��ʂ̒��S����~���o�āA�g�k�ƃ��l�ω���fade
	CIRCLE_SCALING_FADE,
	
	//��ʏォ�琂�ꖋ(Cube)���o��fade
	VEIL_FADE,
	
	//������J�[�e���̗l��fade
	FROM_LEFT_CURTAIN_FADE,
	
	//�E����J�[�e���̗l��fade
	FROM_RIGHT_CURTAIN_FADE,

	//�Z���^�[�J�[�e���̗l�ɉ�����fade
	CENTER_CURTAIN_FADE,
	
	//�s���z�[���^��fade(���P�̗]�n�L)
	PIN_HALL_FADE,
	
	//��ʒ��Ɏl�p�������o�ĉ�ʂ𖄂ߐs������fade
	//�g�p�ł��Ȃ�(������)
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


	gl::Texture mPinHallTexture;


	bool mIsReadyFadeOut;
	bool mIsEndFadeOut;

	bool mIsReadyFadeIn;
	bool mIsEndFadeIn;

	bool mIsEndInit;


	FadePattern mPattern;

	int mFadeInterval;

	float mFadeSpeed;

	int mNoiseCubeLength;
	int mNoiseCubeWide;

public:

	Fade();


	//�S��ʈꗥ��FadeOut�@(�I���܂ł̕b��(int))
	void fullScreenFadeOut(const int);
	//�S��ʈꗥ��FadeOut�@(�I���܂ł̕b��(int))
	void fullScreenFadeIn(const int);

	//�Z���^�[����T�[�N�����L������FadeOut�@(�I���܂ł̕b��(int))
	void circleScalingFadeOut(const int);
	//�Z���^�[����T�[�N�����L������FadeIn�@(�I���܂ł̕b��(int))
	void circleScalingFadeIn(const int);

	//���ꖋ��FadeOut�@(�I���܂ł̕b��(int))
	void veilMoveFadeOut(const int);
	//���ꖋ��FadeIn�@(�I���܂ł̕b��(int))
	void veilMoveFadeIn(const int);

	//�J�[�e����(�i�s������)FadeOut�@(�I���܂ł̕b��(int))
	void fromLeftCurtainFadeOut(const int);
	//�J�[�e����(�i�s������)FadeIn�@(�I���܂ł̕b��(int))
	void fromLeftCurtainFadeIn(const int);

	//�J�[�e����(�i�s������)FadeOut�@(�I���܂ł̕b��(int))
	void fromRightCurtainFadeOut(const int);
	//�J�[�e����(�i�s������)FadeIn�@(�I���܂ł̕b��(int))
	void fromRightCurtainFadeIn(const int);

	//�����J�[�e����(�i�s����)FadeOut�@(�I���܂ł̕b��(int))
	void centerCurtainFadeOut(const int);
	//�����J�[�e����(�i�s����)FadeIn�@(�I���܂ł̕b��(int))
	void centerCurtainFadeIn(const int);

	//�s���z�[��FadeOut�@(�I���܂ł̕b��(int),)
	void pinHallFadeOut(const int,const bool);
	//�s���z�[��FadeOut�@(�I���܂ł̕b��(int))
	void pinHallFadeOut(const int);
	//�s���z�[��FadeIn�@(�I���܂ł̕b��(int))
	void pinHallFadeIn(const int);

	//�m�C�Y(Cube)��ʕ\����FadeOut
	//(�C���^�[�o��(int),�c�̃}�X��(int),���̃}�X��(int))
	void noiseFadeOut(const int,const int,const int);
	//�m�C�Y(Cube)��ʕ\����FadeIn
	//(�C���^�[�o��(int),�c�̃}�X��(int),���̃}�X��(int))
	void noiseFadeIn(const int);

	
	//FadeOut/In�̕`��
	void draw();

};
