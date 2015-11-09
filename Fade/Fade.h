
#pragma once

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"

#include <vector>

using namespace ci;
using namespace ci::app;
using namespace std;


class Fade {

protected:

	//FadeType�̔ԍ�
	enum FadeType {
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
	};

	//�ǂ̃p�^�[�����g���̂����䂷��X�C�b�`�Ŏg�p
	FadeType mPattern;

	//Fade������I�u�W�F�N�g�̌`
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

	//�I�u�W�F�N�g���`����vector�Ő錾
	std::vector<CubeDate>mHideCube;
	std::vector<CircleDate>mHideCircle;
	std::vector<PolygonDate>mHidePolygon;

	//�J�n�𐧌�
	bool mCanStart;
	//�I��������m�F�p
	bool mIsEnd;
	//Init�̐���
	bool mIsEndInit;

	//PinHallFade�̉摜
	gl::Texture mPinHallTexture;

	//Fade���I���܂ł̎���
	int mInterval;
	//�I�u�W�F�N�g��ω������鑬�x
	// �� mFadeInterval�����Čv�Z
	float mSpeed;

};