
#include "Fade.h"


Fade::Fade() {
	mPattern = FULL_SCREEN_FADE;

	mIsReadyFadeOut =
		mIsEndFadeIn = true;

	mIsReadyFadeIn =
		mIsEndInit =
		mIsEndFadeOut = false;
}


void Fade::fullScreenFadeOut(const int time) {

	//���̊֐����Ă΂ꂽ��fadeOut���I�����Ă���Ȃ瓮�����Ȃ�
	//�I�����Ă��Ȃ��Ȃ�fadeOut�𓮂�������������
	if (mIsEndFadeOut)return;
	mIsReadyFadeOut = true;

	if (mIsReadyFadeOut) {

		//�����E������
		if (!mIsEndInit) {

			mPattern = FULL_SCREEN_FADE;
			mFadeInterval = (60 * time);
			mFadeSpeed = (1.0f / mFadeInterval);

			mHideCube.emplace_back();

			for (unsigned int i = 0; i < mHideCube.size(); ++i) {
				mHideCube[i].mPos =
					Vec3f::zero();
				mHideCube[i].mSize =
					Vec3f(
						(float)getWindowWidth(),
						(float)getWindowHeight(),
						0.1f);
				mHideCube[i].mColor =
					ColorA::zero();
			}

			//��x���������������Ȃ��悤��
			mIsEndInit = true;
		}

		//���������I����A�X�V�J�n
		if (mIsEndInit) {

			for (unsigned int i = 0; i < mHideCube.size(); ++i) {
				//���l�v�Z
				mHideCube[i].mColor.a += mFadeSpeed;

				//���l���ő�l(1.0f)�ɂȂ�����
				//fadeIn���g�p�\�ɕύX
				if (mHideCube[i].mColor.a >= 1.0f) {
					mHideCube[i].mColor.a = 1.0f;
					mIsEndFadeOut = true;
					mIsEndFadeIn = false;
					return;
				}

			}

		}

	}

}
void Fade::fullScreenFadeIn(const int time) {

	//���̊֐����Ă΂ꂽ��fadeIn���I�����Ă���Ȃ瓮�����Ȃ�
	//������Fadeout���I�����ĂȂ��Ǝg���Ȃ�
	//�����̏������������Ă���Ȃ�fadeIn�𓮂�������������
	if (mIsEndFadeIn)return;
	if (!mIsEndFadeOut)return;
	mIsReadyFadeIn = true;

	mFadeInterval = (60 * time);
	mFadeSpeed = (1.0f / mFadeInterval);

	if (mIsReadyFadeIn) {

		for (unsigned int i = 0; i < mHideCube.size(); ++i) {

			//���l���Z
			mHideCube[i].mColor.a -= mFadeSpeed;

			//���l���ŏ��l(0.0f)�ɂȂ�����
			//fadeOut���g�p�\�ɕύX
			if (mHideCube[i].mColor.a <= 0.0f) {

				mHideCube.clear();

				mIsReadyFadeOut =
					mIsEndFadeIn = true;

				mIsReadyFadeIn =
					mIsEndInit =
					mIsEndFadeOut = false;

				return;
			}

		}

	}

}

void Fade::circleScalingFadeOut(const int time) {

	//���̊֐����Ă΂ꂽ��fadeOut���I�����Ă���Ȃ瓮�����Ȃ�
	//�I�����Ă��Ȃ��Ȃ�fadeOut�𓮂�������������
	if (mIsEndFadeOut)return;
	mIsReadyFadeOut = true;

	if (mIsReadyFadeOut) {

		//�����E������
		if (!mIsEndInit) {

			mPattern = CIRCLE_SCALING_FADE;
			mFadeInterval = (60 * time);
			mFadeSpeed = (1.0f / mFadeInterval);

			mHideCircle.emplace_back();

			for (unsigned int i = 0; i < mHideCircle.size(); ++i) {
				mHideCircle[i].mPos =
					Vec3f::zero();
				mHideCircle[i].mSize =
					0.0f;
				mHideCircle[i].mColor =
					ColorA::zero();
			}

			//��x���������������Ȃ��悤��
			mIsEndInit = true;
		}

		//���������I����A�X�V�J�n
		if (mIsEndInit) {

			const float sizeChangeSpeed =
				((float)getWindowWidth() / mFadeInterval);

			for (unsigned int i = 0; i < mHideCircle.size(); ++i) {
				//���l�v�Z
				mHideCircle[i].mColor.a += mFadeSpeed;
				//�T�C�Y�v�Z
				mHideCircle[i].mSize += sizeChangeSpeed;

				//���l���ő�l(1.0f)�ɂȂ�����
				//fadeIn���g�p�\�ɕύX
				if (mHideCircle[i].mColor.a >= 1.0f ||
					mHideCircle[i].mSize >= getWindowWidth()) {

					mHideCircle[i].mColor.a = 1.0f;
					mHideCircle[i].mSize =
						(float)getWindowWidth();
					mIsEndFadeOut = true;
					mIsEndFadeIn = false;
					return;
				}

			}

		}

	}

}
void Fade::circleScalingFadeIn(const int time) {

	//���̊֐����Ă΂ꂽ��fadeIn���I�����Ă���Ȃ瓮�����Ȃ�
	//������Fadeout���I�����ĂȂ��Ǝg���Ȃ�
	//�����̏������������Ă���Ȃ�fadeIn�𓮂�������������
	if (mIsEndFadeIn)return;
	if (!mIsEndFadeOut)return;
	mIsReadyFadeIn = true;

	mFadeInterval = (60 * time);
	mFadeSpeed = (1.0f / mFadeInterval);

	if (mIsReadyFadeIn) {

		for (unsigned int i = 0; i < mHideCircle.size(); ++i) {

			const float sizeChangeSpeed =
				((float)getWindowWidth() / mFadeInterval);

			//���l���Z
			mHideCircle[i].mColor.a -= mFadeSpeed;
			//�T�C�Y�v�Z
			mHideCircle[i].mSize -= sizeChangeSpeed;

			//���l���ŏ��l(0.0f)�ɂȂ�����
			//fadeOut���g�p�\�ɕύX
			if (mHideCircle[i].mColor.a <= 0.0f ||
				mHideCircle[i].mSize <= 0.0f) {

				mHideCircle.clear();

				mIsReadyFadeOut =
					mIsEndFadeIn = true;

				mIsReadyFadeIn =
					mIsEndInit =
					mIsEndFadeOut = false;

				return;
			}

		}

	}

}

void Fade::veilMoveFadeOut(const int time) {

	//���̊֐����Ă΂ꂽ��fadeOut���I�����Ă���Ȃ瓮�����Ȃ�
	//�I�����Ă��Ȃ��Ȃ�fadeOut�𓮂�������������
	if (mIsEndFadeOut)return;
	mIsReadyFadeOut = true;

	if (mIsReadyFadeOut) {

		//�����E������
		if (!mIsEndInit) {

			mPattern = VEIL_FADE;
			mFadeInterval = (60 * time);
			mFadeSpeed = ((float)getWindowHeight() / mFadeInterval);

			mHideCube.emplace_back();

			for (unsigned int i = 0; i < mHideCube.size(); ++i) {
				mHideCube[i].mPos =
					Vec3f(0.0f, -(float)getWindowHeight(), 0.0f);
				mHideCube[i].mSize =
					Vec3f(
						(float)getWindowWidth(),
						(float)getWindowHeight(),
						0.1f);
				mHideCube[i].mColor =
					ColorA(0.0f, 0.0f, 0.0f, 1.0f);
			}

			//��x���������������Ȃ��悤��
			mIsEndInit = true;
		}

		//���������I����A�X�V�J�n
		if (mIsEndInit) {

			for (unsigned int i = 0; i < mHideCube.size(); ++i) {
				//���l�v�Z
				mHideCube[i].mPos.y += mFadeSpeed;

				//���l���ő�l(1.0f)�ɂȂ�����
				//fadeIn���g�p�\�ɕύX
				if (mHideCube[i].mPos.y >= 0.0f) {
					mHideCube[i].mPos.y = 0.0f;
					mIsEndFadeOut = true;
					mIsEndFadeIn = false;
					return;
				}

			}

		}

	}

}
void Fade::veilMoveFadeIn(const int time) {

	//���̊֐����Ă΂ꂽ��fadeIn���I�����Ă���Ȃ瓮�����Ȃ�
	//������Fadeout���I�����ĂȂ��Ǝg���Ȃ�
	//�����̏������������Ă���Ȃ�fadeIn�𓮂�������������
	if (mIsEndFadeIn)return;
	if (!mIsEndFadeOut)return;
	mIsReadyFadeIn = true;

	mFadeInterval = (60 * time);
	mFadeSpeed = ((float)getWindowHeight() / mFadeInterval);

	if (mIsReadyFadeIn) {

		for (unsigned int i = 0; i < mHideCube.size(); ++i) {

			//���l���Z
			mHideCube[i].mPos.y -= mFadeSpeed;

			//���l���ŏ��l(0.0f)�ɂȂ�����
			//fadeOut���g�p�\�ɕύX
			if (mHideCube[i].mPos.y <=
				-(float)getWindowHeight()) {

				mHideCube.clear();

				mIsReadyFadeOut =
					mIsEndFadeIn = true;

				mIsReadyFadeIn =
					mIsEndInit =
					mIsEndFadeOut = false;

				return;
			}

		}

	}

}

void Fade::fromLeftCurtainFadeOut(const int time) {

	//���̊֐����Ă΂ꂽ��fadeOut���I�����Ă���Ȃ瓮�����Ȃ�
	//�I�����Ă��Ȃ��Ȃ�fadeOut�𓮂�������������
	if (mIsEndFadeOut)return;
	mIsReadyFadeOut = true;

	if (mIsReadyFadeOut) {

		//�����E������
		if (!mIsEndInit) {

			mPattern = FROM_LEFT_CURTAIN_FADE;
			mFadeInterval = (60 * time);
			mFadeSpeed = ((float)getWindowWidth() / mFadeInterval);

			mHideCube.emplace_back();

			for (unsigned int i = 0; i < mHideCube.size(); ++i) {
				mHideCube[i].mPos =
					Vec3f(-(float)getWindowWidth(), 0.0f, 0.0f);
				mHideCube[i].mSize =
					Vec3f(
						(float)getWindowWidth(),
						(float)getWindowHeight(),
						0.1f);
				mHideCube[i].mColor =
					ColorA(0.0f, 0.0f, 0.0f, 1.0f);
			}

			//��x���������������Ȃ��悤��
			mIsEndInit = true;
		}

		//���������I����A�X�V�J�n
		if (mIsEndInit) {

			for (unsigned int i = 0; i < mHideCube.size(); ++i) {
				//���l�v�Z
				mHideCube[i].mPos.x += mFadeSpeed;

				//���l���ő�l(1.0f)�ɂȂ�����
				//fadeIn���g�p�\�ɕύX
				if (mHideCube[i].mPos.x >= 0.0f) {
					mHideCube[i].mPos.x = 0.0f;
					mIsEndFadeOut = true;
					mIsEndFadeIn = false;
					return;
				}

			}

		}

	}

}
void Fade::fromLeftCurtainFadeIn(const int time) {

	//���̊֐����Ă΂ꂽ��fadeIn���I�����Ă���Ȃ瓮�����Ȃ�
	//������Fadeout���I�����ĂȂ��Ǝg���Ȃ�
	//�����̏������������Ă���Ȃ�fadeIn�𓮂�������������
	if (mIsEndFadeIn)return;
	if (!mIsEndFadeOut)return;
	mIsReadyFadeIn = true;

	mFadeInterval = (60 * time);
	mFadeSpeed = ((float)getWindowWidth() / mFadeInterval);

	if (mIsReadyFadeIn) {

		for (unsigned int i = 0; i < mHideCube.size(); ++i) {

			//���l���Z
			mHideCube[i].mPos.x -= mFadeSpeed;

			//���l���ŏ��l(0.0f)�ɂȂ�����
			//fadeOut���g�p�\�ɕύX
			if (mHideCube[i].mPos.x <=
				-(float)getWindowWidth()) {

				mHideCube.clear();

				mIsReadyFadeOut =
					mIsEndFadeIn = true;

				mIsReadyFadeIn =
					mIsEndInit =
					mIsEndFadeOut = false;

				return;
			}

		}

	}

}

void Fade::fromRightCurtainFadeOut(const int time) {

	//���̊֐����Ă΂ꂽ��fadeOut���I�����Ă���Ȃ瓮�����Ȃ�
	//�I�����Ă��Ȃ��Ȃ�fadeOut�𓮂�������������
	if (mIsEndFadeOut)return;
	mIsReadyFadeOut = true;

	if (mIsReadyFadeOut) {

		//�����E������
		if (!mIsEndInit) {

			mPattern = FROM_LEFT_CURTAIN_FADE;
			mFadeInterval = (60 * time);
			mFadeSpeed = ((float)getWindowWidth() / mFadeInterval);

			mHideCube.emplace_back();

			for (unsigned int i = 0; i < mHideCube.size(); ++i) {
				mHideCube[i].mPos =
					Vec3f((float)getWindowWidth(), 0.0f, 0.0f);
				mHideCube[i].mSize =
					Vec3f(
						(float)getWindowWidth(),
						(float)getWindowHeight(),
						0.1f);
				mHideCube[i].mColor =
					ColorA(0.0f, 0.0f, 0.0f, 1.0f);
			}

			//��x���������������Ȃ��悤��
			mIsEndInit = true;
		}

		//���������I����A�X�V�J�n
		if (mIsEndInit) {

			for (unsigned int i = 0; i < mHideCube.size(); ++i) {
				//���l�v�Z
				mHideCube[i].mPos.x -= mFadeSpeed;

				//���l���ő�l(1.0f)�ɂȂ�����
				//fadeIn���g�p�\�ɕύX
				if (mHideCube[i].mPos.x <= 0.0f) {
					mHideCube[i].mPos.x = 0.0f;
					mIsEndFadeOut = true;
					mIsEndFadeIn = false;
					return;
				}

			}

		}

	}

}
void Fade::fromRightCurtainFadeIn(const int time) {

	//���̊֐����Ă΂ꂽ��fadeIn���I�����Ă���Ȃ瓮�����Ȃ�
	//������Fadeout���I�����ĂȂ��Ǝg���Ȃ�
	//�����̏������������Ă���Ȃ�fadeIn�𓮂�������������
	if (mIsEndFadeIn)return;
	if (!mIsEndFadeOut)return;
	mIsReadyFadeIn = true;

	mFadeInterval = (60 * time);
	mFadeSpeed = ((float)getWindowWidth() / mFadeInterval);

	if (mIsReadyFadeIn) {

		for (unsigned int i = 0; i < mHideCube.size(); ++i) {

			//���l���Z
			mHideCube[i].mPos.x += mFadeSpeed;

			//���l���ŏ��l(0.0f)�ɂȂ�����
			//fadeOut���g�p�\�ɕύX
			if (mHideCube[i].mPos.x >=
				(float)getWindowWidth()) {

				mHideCube.clear();

				mIsReadyFadeOut =
					mIsEndFadeIn = true;

				mIsReadyFadeIn =
					mIsEndInit =
					mIsEndFadeOut = false;

				return;
			}

		}

	}

}

void Fade::centerCurtainFadeOut(const int time) {

	//���̊֐����Ă΂ꂽ��fadeOut���I�����Ă���Ȃ瓮�����Ȃ�
	//�I�����Ă��Ȃ��Ȃ�fadeOut�𓮂�������������
	if (mIsEndFadeOut)return;
	mIsReadyFadeOut = true;

	const float quarterWindowSize = (float)(getWindowWidth() / 4);

	if (mIsReadyFadeOut) {

		//�����E������
		if (!mIsEndInit) {

			mPattern = CENTER_CURTAIN_FADE;
			mFadeInterval = (60 * time);
			mFadeSpeed =
				((float)(getWindowWidth() / 2) / mFadeInterval);

			mHideCube.emplace_back();
			mHideCube.emplace_back();


			mHideCube[0].mPos =
				Vec3f(-(quarterWindowSize * 3), 0.0f, 0.0f);
			mHideCube[1].mPos =
				Vec3f((quarterWindowSize * 3), 0.0f, 0.0f);

			for (unsigned int i = 0; i < mHideCube.size(); ++i) {
				mHideCube[i].mSize =
					Vec3f(
						(float)getWindowWidth() / 2,
						(float)getWindowHeight(),
						0.1f);
				mHideCube[i].mColor =
					ColorA(0.0f, 0.0f, 0.0f, 1.0f);
			}

			//��x���������������Ȃ��悤��
			mIsEndInit = true;
		}

		//���������I����A�X�V�J�n
		if (mIsEndInit) {

			//���l�v�Z
			mHideCube[0].mPos.x += mFadeSpeed;
			mHideCube[1].mPos.x -= mFadeSpeed;

			//���l���ő�l(1.0f)�ɂȂ�����
			//fadeIn���g�p�\�ɕύX
			if (mHideCube[0].mPos.x >=
				-quarterWindowSize) {

				mHideCube[0].mPos.x =
					-quarterWindowSize;
				mIsEndFadeOut = true;
				mIsEndFadeIn = false;
				return;
			}
			if (mHideCube[1].mPos.x <=
				quarterWindowSize) {

				mHideCube[1].mPos.x =
					quarterWindowSize;
				mIsEndFadeOut = true;
				mIsEndFadeIn = false;
				return;
			}

		}

	}

}
void Fade::centerCurtainFadeIn(const int time) {

	//���̊֐����Ă΂ꂽ��fadeIn���I�����Ă���Ȃ瓮�����Ȃ�
	//������Fadeout���I�����ĂȂ��Ǝg���Ȃ�
	//�����̏������������Ă���Ȃ�fadeIn�𓮂�������������
	if (mIsEndFadeIn)return;
	if (!mIsEndFadeOut)return;
	mIsReadyFadeIn = true;

	const float quarterWindowSize = (float)(getWindowWidth() / 4);

	mFadeInterval = (60 * time);
	mFadeSpeed = ((float)(getWindowWidth() / 2) / mFadeInterval);

	if (mIsReadyFadeIn) {

		//���l�v�Z
		mHideCube[0].mPos.x -= mFadeSpeed;
		mHideCube[1].mPos.x += mFadeSpeed;

		//���l���ŏ��l(0.0f)�ɂȂ�����
		//fadeOut���g�p�\�ɕύX
		if (mHideCube[0].mPos.x <=
			-(quarterWindowSize * 3)
			||
			mHideCube[1].mPos.x >=
			(quarterWindowSize * 3)) {

			mHideCube.clear();

			mIsReadyFadeOut =
				mIsEndFadeIn = true;

			mIsReadyFadeIn =
				mIsEndInit =
				mIsEndFadeOut = false;

			return;
		}

	}

}

void Fade::pinHallFadeOut(const int time) {

	//���̊֐����Ă΂ꂽ��fadeOut���I�����Ă���Ȃ瓮�����Ȃ�
	//�I�����Ă��Ȃ��Ȃ�fadeOut�𓮂�������������
	if (mIsEndFadeOut)return;
	mIsReadyFadeOut = true;

	const float fadeSpeedY
		= (((float)getWindowHeight() * 5) / mFadeInterval);

	if (mIsReadyFadeOut) {

		//�����E������
		if (!mIsEndInit) {

			mPinHallTexture =
				loadImage(loadAsset("PinHallFade.png"));

			mPattern = PIN_HALL_FADE;
			mFadeInterval = (60 * time);
			mFadeSpeed = (((float)getWindowWidth() * 5) / mFadeInterval);
			
			mHideCube.emplace_back();

			for (unsigned int i = 0; i < mHideCube.size(); ++i) {
				mHideCube[i].mPos =
					Vec3f::zero();
				mHideCube[i].mSize =
					Vec3f(
						(float)getWindowWidth() * 5,
						(float)getWindowHeight() * 5,
						0.1f);
				mHideCube[i].mColor =
					ColorA(0.0f, 0.0f, 0.0f, 1.0f);
			}

			//��x���������������Ȃ��悤��
			mIsEndInit = true;
		}

		//���������I����A�X�V�J�n
		if (mIsEndInit) {

			for (unsigned int i = 0; i < mHideCube.size(); ++i) {
				mHideCube[i].mSize.x -= mFadeSpeed;
				mHideCube[i].mSize.y -= fadeSpeedY;

				//���l���ő�l(1.0f)�ɂȂ�����
				//fadeIn���g�p�\�ɕύX
				if (mHideCube[i].mSize.x <= (float)getWindowWidth() ||
					mHideCube[i].mSize.y <= (float)getWindowHeight()) {

					mHideCube[i].mSize.x = (float)getWindowWidth();
					mHideCube[i].mSize.y = (float)getWindowHeight();
					mIsEndFadeOut = true;
					mIsEndFadeIn = false;
					return;
				}

			}

		}

	}

}
void Fade::pinHallFadeIn(const int time) {

	//���̊֐����Ă΂ꂽ��fadeIn���I�����Ă���Ȃ瓮�����Ȃ�
	//������Fadeout���I�����ĂȂ��Ǝg���Ȃ�
	//�����̏������������Ă���Ȃ�fadeIn�𓮂�������������
	if (mIsEndFadeIn)return;
	if (!mIsEndFadeOut)return;
	mIsReadyFadeIn = true;

	mFadeInterval = (60 * time);
	mFadeSpeed = (((float)getWindowWidth() * 5) / mFadeInterval);

	float fadeSpeedY =
		(((float)getWindowHeight() * 5) / mFadeInterval);

	if (mIsReadyFadeIn) {

		for (unsigned int i = 0; i < mHideCube.size(); ++i) {

			mHideCube[i].mSize.x += mFadeSpeed;
			mHideCube[i].mSize.y += fadeSpeedY;

			//���l���ŏ��l(0.0f)�ɂȂ�����
			//fadeOut���g�p�\�ɕύX
			if (mHideCube[i].mSize.x >= ((float)getWindowWidth() * 5) ||
				mHideCube[i].mSize.y >= ((float)getWindowHeight() * 5)) {

				mHideCube.clear();

				mIsReadyFadeOut =
					mIsEndFadeIn = true;

				mIsReadyFadeIn =
					mIsEndInit =
					mIsEndFadeOut = false;

				return;
			}

		}

	}

}


void Fade::draw() {

	switch (mPattern) {
#pragma region case FULL_SCREEN_FADE:
	case FULL_SCREEN_FADE:

		for (unsigned int i = 0; i < mHideCube.size(); ++i) {

			//�����x�ǉ��E�\���ʒu�𒆐S�Ɉړ��E�F��ύX
			gl::pushModelView();
			gl::translate(getWindowCenter());

			gl::enableAlphaBlending();

			gl::color(mHideCube[i].mColor);

			//�`��
			gl::drawCube(mHideCube[i].mPos, mHideCube[i].mSize);

			//�S�Č��ɖ߂�
			gl::color(1.0f, 1.0f, 1.0f, 1.0f);

			gl::disableAlphaBlending();

			gl::popModelView();

		}

		break;
#pragma endregion

#pragma region case CIRCLE_SCALING_FADE:
	case CIRCLE_SCALING_FADE:

		for (unsigned int i = 0; i < mHideCircle.size(); ++i) {

			//�����x�ǉ��E�\���ʒu�𒆐S�Ɉړ��E�F��ύX
			gl::pushModelView();
			gl::translate(getWindowCenter());

			gl::enableAlphaBlending();

			gl::color(mHideCircle[i].mColor);

			//�`��
			gl::drawSolidCircle(mHideCircle[i].mPos.xy(), mHideCircle[i].mSize);

			//�S�Č��ɖ߂�
			gl::color(1.0f, 1.0f, 1.0f, 1.0f);

			gl::disableAlphaBlending();

			gl::popModelView();

		}

		break;
#pragma endregion

#pragma region case VEIL_FADE:
	case VEIL_FADE:

		for (unsigned int i = 0; i < mHideCube.size(); ++i) {

			//�����x�ǉ��E�\���ʒu�𒆐S�Ɉړ��E�F��ύX
			gl::pushModelView();
			gl::translate(getWindowCenter());

			gl::enableAlphaBlending();

			gl::color(mHideCube[i].mColor);

			//�`��
			gl::drawCube(mHideCube[i].mPos, mHideCube[i].mSize);

			//�S�Č��ɖ߂�
			gl::color(1.0f, 1.0f, 1.0f, 1.0f);

			gl::disableAlphaBlending();

			gl::popModelView();

		}

		break;
#pragma endregion

#pragma region case FROM_LEFT_CURTAIN_FADE:
	case FROM_LEFT_CURTAIN_FADE:

		for (unsigned int i = 0; i < mHideCube.size(); ++i) {

			//�����x�ǉ��E�\���ʒu�𒆐S�Ɉړ��E�F��ύX
			gl::pushModelView();
			gl::translate(getWindowCenter());

			gl::enableAlphaBlending();

			gl::color(mHideCube[i].mColor);

			//�`��
			gl::drawCube(mHideCube[i].mPos, mHideCube[i].mSize);

			//�S�Č��ɖ߂�
			gl::color(1.0f, 1.0f, 1.0f, 1.0f);

			gl::disableAlphaBlending();

			gl::popModelView();

		}

		break;
#pragma endregion

#pragma region case FROM_RIGHT_CURTAIN_FADE:
	case FROM_RIGHT_CURTAIN_FADE:

		for (unsigned int i = 0; i < mHideCube.size(); ++i) {

			//�����x�ǉ��E�\���ʒu�𒆐S�Ɉړ��E�F��ύX
			gl::pushModelView();
			gl::translate(getWindowCenter());

			gl::enableAlphaBlending();

			gl::color(mHideCube[i].mColor);

			//�`��
			gl::drawCube(mHideCube[i].mPos, mHideCube[i].mSize);

			//�S�Č��ɖ߂�
			gl::color(1.0f, 1.0f, 1.0f, 1.0f);

			gl::disableAlphaBlending();

			gl::popModelView();

		}

		break;
#pragma endregion

#pragma region case CENTER_CURTAIN_FADE:
	case CENTER_CURTAIN_FADE:

		for (unsigned int i = 0; i < mHideCube.size(); ++i) {

			//�����x�ǉ��E�\���ʒu�𒆐S�Ɉړ��E�F��ύX
			gl::pushModelView();
			gl::translate(getWindowCenter());

			gl::enableAlphaBlending();

			gl::color(mHideCube[i].mColor);

			//�`��
			gl::drawCube(mHideCube[i].mPos, mHideCube[i].mSize);

			//�S�Č��ɖ߂�
			gl::color(1.0f, 1.0f, 1.0f, 1.0f);

			gl::disableAlphaBlending();

			gl::popModelView();

		}

		break;
#pragma endregion

#pragma region case PIN_HALL_FADE:
	case PIN_HALL_FADE:

		for (unsigned int i = 0; i < mHideCube.size(); ++i) {

			//�����x�ǉ��E�\���ʒu�𒆐S�Ɉړ��E�F��ύX�E�摜�̓\��t��
			gl::pushModelView();
			gl::translate(getWindowCenter());

			gl::enableAlphaBlending();

			gl::color(mHideCube[i].mColor);

			gl::enable(GL_TEXTURE_2D);
			mPinHallTexture.bind();

			//�`��
			gl::drawCube(mHideCube[i].mPos, mHideCube[i].mSize);

			//�S�Č��ɖ߂�
			mPinHallTexture.unbind();
			gl::disable(GL_TEXTURE_2D);

			gl::color(1.0f, 1.0f, 1.0f, 1.0f);

			gl::disableAlphaBlending();

			gl::popModelView();

		}

		break;
#pragma endregion
	}

}

