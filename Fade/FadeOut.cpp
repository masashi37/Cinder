
#include "FadeOut.h"


FadeOut::FadeOut() {
	mPattern = FULL_SCREEN_FADE;

	mCanStart =
		mIsEnd =
		mIsEndInit =
		mIsEndEasing = false;
}

bool FadeOut::getIsEnd() {
	return mIsEnd;
}

//---------------------------------------------

void FadeOut::setType(FadeType type,
	int time, Color color, bool isUseEasing) {

	switch (type) {
	case FullScreen:
		fade = [=] {
			fullScreenFade(time, color, isUseEasing);
		};
		break;

	case Circle:
		fade = [=] {
			circleScalingFade(time, color, isUseEasing);
		};
		break;

	case Vell:
		fade = [=] {
			veilDownFade(time, color, isUseEasing);
		};
		break;

	case FromLeft:
		fade = [=] {
			fromLeftCurtainFade(time, color, isUseEasing);
		};
		break;

	case FromRight:
		fade = [=] {
			fromRightCurtainFade(time, color, isUseEasing);
		};
		break;

	case BothSide:
		fade = [=] {
			centerCurtainFade(time, color, isUseEasing);
		};
		break;

	case Hole:
		fade = [=] {
			pinHoleFade(time, 0.0f, 50, color, isUseEasing);
		};
		break;
	}

	fade();
}

//---------------------------------------------------
//TODO:Easing‚ðŽg‚Á‚½’†g‚ÌŽÀ‘•
//---------------------------------------------------

void FadeOut::fullScreenFade(int time, Color color, bool isUseEasing) {

	if (!mCanStart) {
		mCanStart = true;
		mIsEnd =
			mIsEndInit =
			mIsUseEasing =
			mIsEndEasing = false;
	}

	if (mCanStart) {

		if (!mIsEndInit) {

			mPattern = FULL_SCREEN_FADE;

			if (!isUseEasing) {
				mInterval = (60 * time);
				mSpeed = (1.0f / mInterval);

				mHideCube.emplace_back();

				mHideCube[0].mPos = Vec3f::zero();

				mHideCube[0].mSize = Vec3f(
					(float)getWindowWidth(),
					(float)getWindowHeight(),
					0);

				mHideCube[0].mColor = ColorA(color, 0.0f);
			}
			if (isUseEasing) {
				mIsUseEasing = true;

				mHideEasingCube.emplace_back();

				mHideEasingCube[0].mPos = Vec2f::zero();

				mHideEasingCube[0].mSize = Vec2f(
					(float)getWindowWidth(),
					(float)getWindowHeight());

				mHideEasingCube[0].mAlpha = 0.0f;
				mHideEasingCube[0].mEndAlpha = 1.0f;

				mHideEasingCube[0].mColor = ColorA(
					color, mHideEasingCube[0].mAlpha);
			}

			mIsEndInit = true;
		}

		if (mIsEndInit) {

			if (!isUseEasing) {
				if ((int)mHideCube.size() > 0) {
					mHideCube[0].mColor.a += mSpeed;

					if (mHideCube[0].mColor.a >= 1.0f) {

						mHideCube.clear();

						mCanStart = false;
						mIsEnd = true;
					}
				}
			}
			if (isUseEasing) {
				if ((int)mHideEasingCube.size() > 0) {
					mHideEasingCube[0].mColor.a =
						mHideEasingCube[0].mAlpha;

					if (!mIsEndEasing) {
						timeline().apply(
							&mHideEasingCube[0].mAlpha,
							mHideEasingCube[0].mEndAlpha.value(),
							(float)time, easeOutInCirc);
						mIsEndEasing = true;
					}

					if (mHideEasingCube[0].mColor.a >= 1.0f) {

						mHideEasingCube.clear();

						mCanStart =
							mIsUseEasing = false;
						mIsEnd = true;
					}
				}
			}
			//console() << mHideEasingCube[0].mColor.a << std::endl;
		}
	}

}

void FadeOut::circleScalingFade(int time, Color color, bool isUseEasing) {

	if (!mCanStart) {
		mCanStart = true;
		mIsEnd =
			mIsEndInit = false;
	}

	const float windowOutPos =
		((float)getWindowWidth() / 1.5f);

	if (mCanStart) {

		if (!mIsEndInit) {

			mPattern = CIRCLE_SCALING_FADE;
			mInterval = (60 * time);
			mSpeed = (1.0f / mInterval);

			mHideCircle.emplace_back();

			mHideCircle[0].mPos = Vec3f::zero();
			mHideCircle[0].mSize = 0.0f;
			mHideCircle[0].mColor = ColorA(color, 0.0f);

			mIsEndInit = true;
		}

		if (mIsEndInit) {

			const float sizeChangeSpeed =
				((float)getWindowWidth() / mInterval);

			if ((int)mHideCircle.size() > 0) {
				mHideCircle[0].mColor.a += mSpeed;
				mHideCircle[0].mSize += sizeChangeSpeed;

				if (mHideCircle[0].mColor.a >= 1.0f ||
					mHideCircle[0].mSize >= windowOutPos) {

					mHideCircle.clear();

					mCanStart = false;
					mIsEnd = true;
				}
			}
		}
	}

}

void FadeOut::veilDownFade(int time, Color color, bool isUseEasing) {

	if (!mCanStart) {
		mCanStart = true;
		mIsEnd =
			mIsEndInit = false;
	}

	if (mCanStart) {

		if (!mIsEndInit) {

			mPattern = VEIL_FADE;
			mInterval = (60 * time);
			mSpeed = ((float)getWindowHeight() / mInterval);

			mHideCube.emplace_back();

			mHideCube[0].mPos =
				Vec3f(0.0f, -(float)getWindowHeight(), 0.0f);

			mHideCube[0].mSize = Vec3f(
				(float)getWindowWidth(),
				(float)getWindowHeight(),
				0.1f);

			mHideCube[0].mColor = ColorA(color, 1.0f);

			mIsEndInit = true;
		}

		if (mIsEndInit) {

			if ((int)mHideCube.size() > 0) {
				mHideCube[0].mPos.y += mSpeed;

				if (mHideCube[0].mPos.y >= 0.0f) {

					mHideCube.clear();

					mCanStart = false;
					mIsEnd = true;
				}

			}

		}

	}

}

void FadeOut::fromLeftCurtainFade(int time, Color color, bool isUseEasing) {

	if (!mCanStart) {
		mCanStart = true;
		mIsEnd =
			mIsEndInit = false;
	}

	if (mCanStart) {

		if (!mIsEndInit) {

			mPattern = FROM_LEFT_CURTAIN_FADE;
			mInterval = (60 * time);
			mSpeed = ((float)getWindowWidth() / mInterval);

			mHideCube.emplace_back();

			mHideCube[0].mPos =
				Vec3f(-(float)getWindowWidth(), 0.0f, 0.0f);

			mHideCube[0].mSize = Vec3f(
				(float)getWindowWidth(),
				(float)getWindowHeight(),
				0.1f);

			mHideCube[0].mColor = ColorA(color, 1.0f);

			mIsEndInit = true;
		}

		if (mIsEndInit) {

			if ((int)mHideCube.size() > 0) {
				mHideCube[0].mPos.x += mSpeed;

				if (mHideCube[0].mPos.x >= 0.0f) {

					mHideCube.clear();

					mCanStart = false;
					mIsEnd = true;
				}

			}

		}

	}

}

void FadeOut::fromRightCurtainFade(int time, Color color, bool isUseEasing) {

	if (!mCanStart) {
		mCanStart = true;
		mIsEnd =
			mIsEndInit = false;
	}

	if (mCanStart) {


		if (!mIsEndInit) {

			mPattern = FROM_RIGHT_CURTAIN_FADE;
			mInterval = (60 * time);
			mSpeed = ((float)getWindowWidth() / mInterval);

			mHideCube.emplace_back();

			mHideCube[0].mPos =
				Vec3f((float)getWindowWidth(), 0.0f, 0.0f);

			mHideCube[0].mSize = Vec3f(
				(float)getWindowWidth(),
				(float)getWindowHeight(),
				0.1f);

			mHideCube[0].mColor =
				ColorA(color, 1.0f);

			mIsEndInit = true;
		}

		if (mIsEndInit) {

			if ((int)mHideCube.size() > 0) {
				mHideCube[0].mPos.x -= mSpeed;

				if (mHideCube[0].mPos.x <= 0.0f) {

					mHideCube.clear();

					mCanStart = false;
					mIsEnd = true;
				}

			}

		}

	}

}

void FadeOut::centerCurtainFade(int time, Color color, bool isUseEasing) {

	if (!mCanStart) {
		mCanStart = true;
		mIsEnd =
			mIsEndInit = false;
	}

	const float quarterWindowSize = (float)(getWindowWidth() / 4);

	if (mCanStart) {

		if (!mIsEndInit) {

			mPattern = CENTER_CURTAIN_FADE;
			mInterval = (60 * time);
			mSpeed =
				((float)(getWindowWidth() / 2) / mInterval);

			mHideCube.emplace_back();
			mHideCube.emplace_back();

			mHideCube[0].mPos =
				Vec3f(-(quarterWindowSize * 3), 0.0f, 0.0f);
			mHideCube[1].mPos =
				Vec3f((quarterWindowSize * 3), 0.0f, 0.0f);

			for (unsigned int i = 0; i < mHideCube.size(); ++i) {
				mHideCube[i].mSize = Vec3f(
					(float)getWindowWidth() / 2,
					(float)getWindowHeight(),
					0.1f);

				mHideCube[i].mColor = ColorA(color, 1.0f);
			}

			mIsEndInit = true;
		}

		if (mIsEndInit) {

			if ((int)mHideCube.size() > 0) {
				mHideCube[0].mPos.x += mSpeed;
				mHideCube[1].mPos.x -= mSpeed;

				if (mHideCube[0].mPos.x >=
					-quarterWindowSize
					||
					mHideCube[1].mPos.x <=
					quarterWindowSize) {

					mHideCube.clear();

					mCanStart = false;
					mIsEnd = true;
				}
			}

		}

	}

}

void FadeOut::pinHoleFade(
	int time, float space, const int slices,
	Color color, bool isUseEasing) {

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


		if (!mIsEndInit) {

			mPattern = PIN_HOLE_FADE;
			mInterval = (60 * time);
			mSpeed = (((float)getWindowWidth() - space) / mInterval);

			mHideCylinder.emplace_back();

			mHideCylinder[0].mStartPos = windowOutPos;
			mHideCylinder[0].mEndPos = windowOutPos;
			mHideCylinder[0].mSliceCount = slices;
			mHideCylinder[0].mColor = ColorA(color, 1.0f);

			mIsEndInit = true;
		}

		if (mIsEndInit) {

			if ((int)mHideCylinder.size() > 0) {
				mHideCylinder[0].mStartPos -= mSpeed;

				if (mHideCylinder[0].mStartPos <= space) {

					mHideCylinder.clear();

					mCanStart = false;
					mIsEnd = true;
				}

			}

		}

	}

}

//---------------------------------------------

void FadeOut::draw() {

	gl::pushModelView();
	gl::translate(getWindowCenter());
	gl::enableAlphaBlending();

	switch (mPattern) {

	case FULL_SCREEN_FADE:
		for (unsigned int i = 0; i < mHideCube.size(); ++i) {
			if (!mIsUseEasing) {
				gl::color(mHideCube[i].mColor);
				gl::drawCube(mHideCube[i].mPos, mHideCube[i].mSize);
				gl::color(1.0f, 1.0f, 1.0f, 1.0f);
			}
		}
		for (unsigned int i = 0; i < mHideEasingCube.size(); ++i) {
			if (mIsUseEasing) {
				gl::color(mHideEasingCube[i].mColor);
				gl::drawCube(Vec3f(mHideEasingCube[i].mPos, 0),
					Vec3f(mHideEasingCube[i].mSize, 0));
				gl::color(1.0f, 1.0f, 1.0f, 1.0f);
			}
		}
		break;

	case CIRCLE_SCALING_FADE:
		for (unsigned int i = 0; i < mHideCircle.size(); ++i) {
			gl::color(mHideCircle[i].mColor);
			gl::drawSolidCircle(
				mHideCircle[i].mPos.xy(), mHideCircle[i].mSize);
			gl::color(1.0f, 1.0f, 1.0f, 1.0f);
		}
		break;

	case VEIL_FADE:
		for (unsigned int i = 0; i < mHideCube.size(); ++i) {
			gl::color(mHideCube[i].mColor);
			gl::drawCube(mHideCube[i].mPos, mHideCube[i].mSize);
			gl::color(1.0f, 1.0f, 1.0f, 1.0f);
		}
		break;

	case FROM_LEFT_CURTAIN_FADE:
		for (unsigned int i = 0; i < mHideCube.size(); ++i) {
			gl::color(mHideCube[i].mColor);
			gl::drawCube(mHideCube[i].mPos, mHideCube[i].mSize);
			gl::color(1.0f, 1.0f, 1.0f, 1.0f);
		}
		break;

	case FROM_RIGHT_CURTAIN_FADE:
		for (unsigned int i = 0; i < mHideCube.size(); ++i) {
			gl::color(mHideCube[i].mColor);
			gl::drawCube(mHideCube[i].mPos, mHideCube[i].mSize);
			gl::color(1.0f, 1.0f, 1.0f, 1.0f);
		}
		break;

	case CENTER_CURTAIN_FADE:
		for (unsigned int i = 0; i < mHideCube.size(); ++i) {
			gl::color(mHideCube[i].mColor);
			gl::drawCube(mHideCube[i].mPos, mHideCube[i].mSize);
			gl::color(1.0f, 1.0f, 1.0f, 1.0f);
		}
		break;

	case PIN_HOLE_FADE:
		for (unsigned int i = 0; i < mHideCylinder.size(); ++i) {
			gl::rotate(Vec3f(90, 0, 0));
			gl::color(mHideCylinder[i].mColor);
			gl::drawCylinder(
				mHideCylinder[i].mStartPos,
				mHideCylinder[i].mEndPos,
				0.1f,
				mHideCylinder[i].mSliceCount);
			gl::color(Color(1, 1, 1));
		}
		break;
	}

	gl::disableAlphaBlending();
	gl::popModelView();

}

