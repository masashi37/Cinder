
#include "Fade.h"


Fade::Fade() {
	mPattern = 0;

	mIsReadyFadeOut =
		mIsEndFadeIn = true;

	mIsReadyFadeIn =
		mIsEndInit =
		mIsEndFadeOut = false;
}


void Fade::fadeOut(const int fadePattern) {

	//�I�񂾃p�^�[���������悤�ɕύX
	mPattern = fadePattern;

	//���̊֐����Ă΂ꂽ��fadeOut���I�����Ă���Ȃ瓮�����Ȃ�
	//�I�����Ă��Ȃ��Ȃ�fadeOut�𓮂�������������
	if (mIsEndFadeOut)return;
	mIsReadyFadeOut = true;

	if (mIsReadyFadeOut) {

		switch (mPattern) {
#pragma region case CUBE_FADE:
		case CUBE_FADE:

			//�����E������
			if (!mIsEndInit) {

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
					mHideCube[i].mColor.a += FADE_SPEED;

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

			break;
#pragma endregion

#pragma region case CIRCLE_FADE:
		case CIRCLE_FADE:

			//�����E������
			if (!mIsEndInit) {

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
					((float)getWindowWidth() / FADE_INTERVAL);

				for (unsigned int i = 0; i < mHideCircle.size(); ++i) {
					//���l�v�Z
					mHideCircle[i].mColor.a += FADE_SPEED;
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

			break;
#pragma endregion

#pragma region case VEIL_FADE:
		case VEIL_FADE:

			//�����E������
			if (!mIsEndInit) {

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

				const float cubeMoveSpeed =
					(float)getWindowHeight() / FADE_INTERVAL;

				for (unsigned int i = 0; i < mHideCube.size(); ++i) {
					//���l�v�Z
					mHideCube[i].mPos.y += cubeMoveSpeed;

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

			break;
#pragma endregion

#pragma region case SIDE_CURTAIN_FADE:
		case SIDE_CURTAIN_FADE:

			//�����E������
			if (!mIsEndInit) {

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

				const float cubeMoveSpeed =
					(float)getWindowHeight() / FADE_INTERVAL;

				for (unsigned int i = 0; i < mHideCube.size(); ++i) {
					//���l�v�Z
					mHideCube[i].mPos.y += cubeMoveSpeed;

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

			break;
#pragma endregion

#pragma region case POLYGON_FADE:
		case POLYGON_FADE:

			//�����E������
			if (!mIsEndInit) {
				//������
				const int divisionCount = 8;

				for (int i = 0; i < divisionCount; ++i) {
					mHidePolygon.emplace_back();
				}

				for (unsigned int i = 0; i < mHidePolygon.size(); ++i) {

					mHidePolygon[i].mPos =
						Vec3f::zero();

					auto rate = i / divisionCount;
					mHidePolygon[i].mSecond_pos =
						Vec3f(
							0.5f * cos(2.0 * M_PI * rate),
							0.5f * sin(2.0 * M_PI * rate),
							0.0f);

					rate = i + 1 / divisionCount;
					mHidePolygon[i].mThird_pos =
						Vec3f(
							0.5f * cos(2.0 * M_PI * rate),
							0.5f * sin(2.0 * M_PI * rate),
							0.0f);

					mHidePolygon[i].mColor =
						ColorA::zero();

				}

				//��x���������������Ȃ��悤��
				mIsEndInit = true;
			}

			//���������I����A�X�V�J�n
			if (mIsEndInit) {

				float makeTime = 0;
				const float  mekeInterval = 8 / (float)FADE_INTERVAL;

				makeTime++;

				if (makeTime / mekeInterval == 1)
					mHidePolygon[0].mColor.a = 1.0f;
				else if (makeTime / mekeInterval == 2)
					mHidePolygon[1].mColor.a = 1.0f;
				else if (makeTime / mekeInterval == 3)
					mHidePolygon[2].mColor.a = 1.0f;
				else if (makeTime / mekeInterval == 4)
					mHidePolygon[3].mColor.a = 1.0f;
				else if (makeTime / mekeInterval == 5)
					mHidePolygon[4].mColor.a = 1.0f;
				else if (makeTime / mekeInterval == 6)
					mHidePolygon[5].mColor.a = 1.0f;
				else if (makeTime / mekeInterval == 7)
					mHidePolygon[6].mColor.a = 1.0f;
				else if (makeTime / mekeInterval == 8)
					mHidePolygon[7].mColor.a = 1.0f;

				//���l���ő�l(1.0f)�ɂȂ�����
				//fadeIn���g�p�\�ɕύX
				if (mHidePolygon[7].mColor.a == 1.0f) {
					mIsEndFadeOut = true;
					mIsEndFadeIn = false;
					return;

				}

			}

			break;
#pragma endregion
		}

	}

}

void Fade::fadeIn() {

	//���̊֐����Ă΂ꂽ��fadeIn���I�����Ă���Ȃ瓮�����Ȃ�
	//������Fadeout���I�����ĂȂ��Ǝg���Ȃ�
	//�����̏������������Ă���Ȃ�fadeIn�𓮂�������������
	if (mIsEndFadeIn)return;
	if (!mIsEndFadeOut)return;
	mIsReadyFadeIn = true;

	if (mIsReadyFadeIn) {

		switch (mPattern) {
#pragma region case CUBE_FADE:
		case CUBE_FADE:

			for (unsigned int i = 0; i < mHideCube.size(); ++i) {

				//���l���Z
				mHideCube[i].mColor.a -= FADE_SPEED;

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

			break;
#pragma endregion

#pragma region case CIRCLE_FADE:
		case CIRCLE_FADE:

			for (unsigned int i = 0; i < mHideCircle.size(); ++i) {

				const float sizeChangeSpeed =
					((float)getWindowWidth() / FADE_INTERVAL);

				//���l���Z
				mHideCircle[i].mColor.a -= FADE_SPEED;
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

			break;
#pragma endregion

#pragma region case VEIL_FADE:
		case VEIL_FADE:

			for (unsigned int i = 0; i < mHideCube.size(); ++i) {

				const float cubeMoveSpeed =
					(float)getWindowHeight() / FADE_INTERVAL;

				//���l���Z
				mHideCube[i].mPos.y -= cubeMoveSpeed;

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

			break;
#pragma endregion

#pragma region case POLYGON_FADE:
		case POLYGON_FADE:

			for (unsigned int i = 0; i < mHidePolygon.size(); ++i) {

				//���l���Z
				mHidePolygon[i].mColor.a -= FADE_SPEED;

				//���l���ŏ��l(0.0f)�ɂȂ�����
				//fadeOut���g�p�\�ɕύX
				if (mHidePolygon[i].mColor.a <= 0.0f) {

					mHidePolygon.clear();

					mIsReadyFadeOut =
						mIsEndFadeIn = true;

					mIsReadyFadeIn =
						mIsEndInit =
						mIsEndFadeOut = false;

					return;
				}

			}

			break;
#pragma endregion
		}

	}

}

void Fade::draw() {

	switch (mPattern) {
#pragma region case CUBE_FADE:
	case CUBE_FADE:

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

#pragma region case CIRCLE_FADE:
	case CIRCLE_FADE:

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

#pragma region case POLYGON_FADE:
	case POLYGON_FADE:

		for (unsigned int i = 0; i < mHidePolygon.size(); ++i) {

			//�����x�ǉ��E�\���ʒu�𒆐S�Ɉړ��E�F��ύX
			gl::pushModelView();
			gl::translate(getWindowCenter());

			gl::enableAlphaBlending();

			gl::color(mHidePolygon[i].mColor);

			//�`��
			gl::drawStrokedTriangle(
				mHidePolygon[i].mPos.xy(),
				mHidePolygon[i].mSecond_pos.xy(),
				mHidePolygon[i].mThird_pos.xy()
				);

			//�S�Č��ɖ߂�
			gl::color(1.0f, 1.0f, 1.0f, 1.0f);

			gl::disableAlphaBlending();

			gl::popModelView();

		}

		break;
#pragma endregion
	}

}

