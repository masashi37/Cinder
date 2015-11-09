
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

void FadeIn::circleScalingFade(int time) {

	if (!mCanStart) {
		mCanStart = true;
		mIsEnd =
			mIsEndInit = false;
	}

	const float windowOutPos =
		((float)getWindowWidth() / 1.5f);

	if (mCanStart) {

		//�����E������
		if (!mIsEndInit) {

			//�f�[�^���p�^�[���ɍ��킹�ď�����
			mPattern = CIRCLE_SCALING_FADE;
			mInterval = (60 * time);
			mSpeed = (1.0f / mInterval);

			//�K�v�Ȍ�����
			mHideCircle.emplace_back();

			//���������I�u�W�F�N�g�̏�����
			mHideCircle[0].mPos = Vec3f::zero();

			mHideCircle[0].mSize = windowOutPos;

			mHideCircle[0].mColor = ColorA(
				0.0f, 0.0f, 0.0f, 1.0f);

			//��x���������������Ȃ��悤��
			mIsEndInit = true;
		}

		//���������I����A�X�V�J�n
		if (mIsEndInit) {

			const float sizeChangeSpeed =
				((float)getWindowWidth() / mInterval);

			if ((int)mHideCircle.size() > 0) {
				//���l�v�Z
				mHideCircle[0].mColor.a -= mSpeed;
				//�T�C�Y�v�Z
				mHideCircle[0].mSize -= sizeChangeSpeed;

				//���l���ő�l(1.0f)�ɂȂ�����
				//fadeIn���g�p�\�ɕύX
				if (mHideCircle[0].mColor.a <= 0.0f ||
					mHideCircle[0].mSize <= 0.0f) {

					mHideCircle.clear();

					mCanStart = false;
					mIsEnd = true;
				}

			}

		}

	}

}

void FadeIn::veilDownFade(int time) {

	if (!mCanStart) {
		mCanStart = true;
		mIsEnd =
			mIsEndInit = false;
	}

	if (mCanStart) {

		//�����E������
		if (!mIsEndInit) {

			//�f�[�^���p�^�[���ɍ��킹�ď�����
			mPattern = VEIL_FADE;
			mInterval = (60 * time);
			mSpeed = ((float)getWindowHeight() / mInterval);

			//�K�v�Ȍ�����
			mHideCube.emplace_back();

			//���������I�u�W�F�N�g�̏�����
			mHideCube[0].mPos =
				Vec3f(0.0f, 0.0f, 0.0f);

			mHideCube[0].mSize = Vec3f(
				(float)getWindowWidth(),
				(float)getWindowHeight(),
				0.1f);

			mHideCube[0].mColor =
				ColorA(0.0f, 0.0f, 0.0f, 1.0f);

			//��x���������������Ȃ��悤��
			mIsEndInit = true;
		}

		//���������I����A�X�V�J�n
		if (mIsEndInit) {

			if ((int)mHideCube.size() > 0) {
				//���l�v�Z
				mHideCube[0].mPos.y -= mSpeed;

				//���l���ő�l(1.0f)�ɂȂ�����
				//fadeIn���g�p�\�ɕύX
				if (mHideCube[0].mPos.y <= -(float)getWindowHeight()) {

					mHideCube.clear();

					mCanStart = false;
					mIsEnd = true;
				}

			}

		}

	}

}

void FadeIn::fromLeftCurtainFade(int time) {

	if (!mCanStart) {
		mCanStart = true;
		mIsEnd =
			mIsEndInit = false;
	}

	if (mCanStart) {

		//�����E������
		if (!mIsEndInit) {

			//�f�[�^���p�^�[���ɍ��킹�ď�����
			mPattern = FROM_LEFT_CURTAIN_FADE;
			mInterval = (60 * time);
			mSpeed = ((float)getWindowWidth() / mInterval);

			//�K�v�Ȍ�����
			mHideCube.emplace_back();

			//���������I�u�W�F�N�g�̏�����
			mHideCube[0].mPos =
				Vec3f(0.0f, 0.0f, 0.0f);

			mHideCube[0].mSize = Vec3f(
				(float)getWindowWidth(),
				(float)getWindowHeight(),
				0.1f);

			mHideCube[0].mColor =
				ColorA(0.0f, 0.0f, 0.0f, 1.0f);

			//��x���������������Ȃ��悤��
			mIsEndInit = true;
		}

		//���������I����A�X�V�J�n
		if (mIsEndInit) {

			if ((int)mHideCube.size() > 0) {
				//���l�v�Z
				mHideCube[0].mPos.x -= mSpeed;

				//���l���ő�l(1.0f)�ɂȂ�����
				//fadeIn���g�p�\�ɕύX
				if (mHideCube[0].mPos.x <= -(float)getWindowWidth()) {

					mHideCube.clear();

					mCanStart = false;
					mIsEnd = true;
				}

			}

		}

	}

}

void FadeIn::fromRightCurtainFade(int time) {

	if (!mCanStart) {
		mCanStart = true;
		mIsEnd =
			mIsEndInit = false;
	}

	if (mCanStart) {

		//�����E������
		if (!mIsEndInit) {

			//�f�[�^���p�^�[���ɍ��킹�ď�����
			mPattern = FROM_RIGHT_CURTAIN_FADE;
			mInterval = (60 * time);
			mSpeed = ((float)getWindowWidth() / mInterval);

			//�K�v�Ȍ�����
			mHideCube.emplace_back();

			//���������I�u�W�F�N�g�̏�����
			mHideCube[0].mPos =
				Vec3f(0.0f, 0.0f, 0.0f);

			mHideCube[0].mSize = Vec3f(
				(float)getWindowWidth(),
				(float)getWindowHeight(),
				0.1f);

			mHideCube[0].mColor =
				ColorA(0.0f, 0.0f, 0.0f, 1.0f);

			//��x���������������Ȃ��悤��
			mIsEndInit = true;
		}

		//���������I����A�X�V�J�n
		if (mIsEndInit) {

			if ((int)mHideCube.size() > 0) {
				//���l�v�Z
				mHideCube[0].mPos.x += mSpeed;

				//���l���ő�l(1.0f)�ɂȂ�����
				//fadeIn���g�p�\�ɕύX
				if (mHideCube[0].mPos.x >= (float)getWindowWidth()) {

					mHideCube.clear();

					mCanStart = false;
					mIsEnd = true;
				}

			}

		}

	}

}

void FadeIn::centerCurtainFade(int time) {

	if (!mCanStart) {
		mCanStart = true;
		mIsEnd =
			mIsEndInit = false;
	}

	const float quarterWindowSize = (float)(getWindowWidth() / 4);

	if (mCanStart) {

		//�����E������
		if (!mIsEndInit) {

			//�f�[�^���p�^�[���ɍ��킹�ď�����
			mPattern = CENTER_CURTAIN_FADE;
			mInterval = (60 * time);
			mSpeed =
				((float)(getWindowWidth() / 2) / mInterval);

			//�K�v�Ȍ�����
			mHideCube.emplace_back();
			mHideCube.emplace_back();

			//���������I�u�W�F�N�g�̏�����
			mHideCube[0].mPos =
				Vec3f(-quarterWindowSize, 0.0f, 0.0f);
			mHideCube[1].mPos =
				Vec3f(quarterWindowSize, 0.0f, 0.0f);

			for (unsigned int i = 0; i < mHideCube.size(); ++i) {
				mHideCube[i].mSize = Vec3f(
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

			if ((int)mHideCube.size() > 0) {
				//���l�v�Z
				mHideCube[0].mPos.x -= mSpeed;
				mHideCube[1].mPos.x += mSpeed;

				//���l���ő�l(1.0f)�ɂȂ�����
				//fadeIn���g�p�\�ɕύX
				if (mHideCube[0].mPos.x <=
					-(quarterWindowSize * 3)
					||
					mHideCube[1].mPos.x >=
					(quarterWindowSize * 3)) {

					mHideCube.clear();

					mCanStart = false;
					mIsEnd = true;
				}
			}

		}

	}

}

void FadeIn::pinHoleFade(
	int time, float space = 0.0f, const int slices = 12) {

	if (!mCanStart) {
		mCanStart = true;
		mIsEnd =
			mIsEndInit = false;
	}

	const float windowOutPos =
		((float)getWindowWidth() / 1.5f);

	if (space > windowOutPos) {
		space = 0.0f;
	}

	if (mCanStart) {

		//�����E������
		if (!mIsEndInit) {

			//�f�[�^���p�^�[���ɍ��킹�ď�����
			mPattern = PIN_HOLE_FADE;
			mInterval = (60 * time);
			mSpeed = (((float)getWindowWidth() - space) / mInterval);

			//�K�v�Ȍ�����
			mHideCylinder.emplace_back();

			//���������I�u�W�F�N�g�̏�����
			mHideCylinder[0].mStartPos = space;
			mHideCylinder[0].mEndPos = windowOutPos;
			mHideCylinder[0].mSliceCount = slices;
			mHideCylinder[0].mColor = ColorA(
				0.0f, 0.0f, 0.0f, 1.0f);

			//��x���������������Ȃ��悤��
			mIsEndInit = true;
		}

		//���������I����A�X�V�J�n
		if (mIsEndInit) {

			if ((int)mHideCylinder.size() > 0) {
				//�T�C�Y�v�Z
				mHideCylinder[0].mStartPos += mSpeed;

				//���l���ő�l(1.0f)�ɂȂ�����
				//fadeIn���g�p�\�ɕύX
				if (mHideCylinder[0].mStartPos >= windowOutPos) {

					mHideCylinder.clear();

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
#pragma region case PIN_HOLE_FADE:
	case PIN_HOLE_FADE:

		for (unsigned int i = 0; i < mHideCylinder.size(); ++i) {

			//�����x�ǉ��E�\���ʒu�𒆐S�Ɉړ��E�F��ύX�E�摜�̓\��t��
			gl::pushModelView();
			gl::translate(getWindowCenter());
			gl::rotate(Vec3f(90, 0, 0));

			gl::enableAlphaBlending();

			gl::color(mHideCylinder[i].mColor);

			//�`��
			gl::drawCylinder(
				mHideCylinder[i].mStartPos,
				mHideCylinder[i].mEndPos,
				0.1f,
				mHideCylinder[i].mSliceCount);

			//�S�Č��ɖ߂�			
			gl::color(Color(1, 1, 1));
			gl::popModelView();

		}

		break;
#pragma endregion
	}

}

