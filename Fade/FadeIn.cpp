
#include "FadeIn.h"


FadeIn::FadeIn() {
	mPattern = FULL_SCREEN_FADE;

	mCanStart =
		mIsEnd =
		mIsEndInit = false;
}

bool FadeIn::getEnd() {
	return mIsEnd;
}

//---------------------------------------------

void FadeIn::fullScreenFade(int time) {

	if (!mCanStart) {
		mCanStart = true;
		mIsEnd =
			mIsEndInit = false;
	}

	if (mCanStart) {

		//�����E������
		if (!mIsEndInit) {

			//�f�[�^���p�^�[���ɍ��킹�ď�����
			mPattern = FULL_SCREEN_FADE;
			mInterval = (60 * time);
			mSpeed = (1.0f / mInterval);

			//�K�v�Ȍ�����
			mHideCube.emplace_back();

			//���������I�u�W�F�N�g�̏�����
			mHideCube[0].mPos = Vec3f::zero();

			mHideCube[0].mSize = Vec3f(
				(float)getWindowWidth(),
				(float)getWindowHeight(),
				0);

			mHideCube[0].mColor = ColorA(
				0, 0, 0, 1.0f);

			//��x�̂ݏ�����
			mIsEndInit = true;
		}

		//���������I����A�X�V�J�n
		if (mIsEndInit) {

			//���l�v�Z
			if ((int)mHideCube.size() > 0)
				mHideCube[0].mColor.a -= mSpeed;

			//���l���ő�l(1.0f)�ɂȂ�����
			//fadeIn���g�p�\�ɕύX
			if ((int)mHideCube.size() > 0) {
				if (mHideCube[0].mColor.a <= 0.0f) {

					mHideCube.clear();

					mCanStart = false;
					mIsEnd = true;
				}
			}

		}

	}

}

//---------------------------------------------

void FadeIn::draw() {

	switch (mPattern) {
#pragma region case FULL_SCREEN_FADE:
	case FULL_SCREEN_FADE:

		for (unsigned int i = 0; i < mHideCube.size(); ++i) {

			//�\���ʒu�𒆐S�Ɉړ��E�����x�ǉ��E�F��ύX
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

			if (i == 0)
				mPinHallTexture.bind();

			//�`��
			gl::drawCube(mHideCube[i].mPos, mHideCube[i].mSize);

			//�S�Č��ɖ߂�
			if (i == 0)
				mPinHallTexture.unbind();
			gl::disable(GL_TEXTURE_2D);

			gl::color(1.0f, 1.0f, 1.0f, 1.0f);

			gl::disableAlphaBlending();

			gl::popModelView();

		}

		break;
#pragma endregion
		//#pragma region case NOISE_FADE:
		//	case NOISE_FADE:
		//
		//		for (unsigned int i = 0; i < mHideCube.size(); ++i) {
		//
		//			//�����x�ǉ��E�\���ʒu�𒆐S�Ɉړ��E�F��ύX
		//			gl::pushModelView();
		//			gl::translate(getWindowCenter());
		//
		//			gl::enableAlphaBlending();
		//
		//			gl::color(mHideCube[i].mColor);
		//
		//			//�`��
		//			gl::drawCube(mHideCube[i].mPos, mHideCube[i].mSize);
		//
		//			//�S�Č��ɖ߂�
		//			gl::color(1.0f, 1.0f, 1.0f, 1.0f);
		//
		//			gl::disableAlphaBlending();
		//
		//			gl::popModelView();
		//
		//		}
		//
		//		break;
		//#pragma endregion
	}

}

