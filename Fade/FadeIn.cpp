
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

		//生成・初期化
		if (!mIsEndInit) {

			//データをパターンに合わせて初期化
			mPattern = FULL_SCREEN_FADE;
			mInterval = (60 * time);
			mSpeed = (1.0f / mInterval);

			//必要な個数生成
			mHideCube.emplace_back();

			//生成したオブジェクトの初期化
			mHideCube[0].mPos = Vec3f::zero();

			mHideCube[0].mSize = Vec3f(
				(float)getWindowWidth(),
				(float)getWindowHeight(),
				0);

			mHideCube[0].mColor = ColorA(
				0, 0, 0, 1.0f);

			//一度のみ初期化
			mIsEndInit = true;
		}

		//初期化が終了後、更新開始
		if (mIsEndInit) {

			//α値計算
			if ((int)mHideCube.size() > 0)
				mHideCube[0].mColor.a -= mSpeed;

			//α値が最大値(1.0f)になったら
			//fadeInを使用可能に変更
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

		//生成・初期化
		if (!mIsEndInit) {

			//データをパターンに合わせて初期化
			mPattern = CIRCLE_SCALING_FADE;
			mInterval = (60 * time);
			mSpeed = (1.0f / mInterval);

			//必要な個数生成
			mHideCircle.emplace_back();

			//生成したオブジェクトの初期化
			mHideCircle[0].mPos = Vec3f::zero();

			mHideCircle[0].mSize = windowOutPos;

			mHideCircle[0].mColor = ColorA(
				0.0f, 0.0f, 0.0f, 1.0f);

			//一度だけしか処理しないように
			mIsEndInit = true;
		}

		//初期化が終了後、更新開始
		if (mIsEndInit) {

			const float sizeChangeSpeed =
				((float)getWindowWidth() / mInterval);

			if ((int)mHideCircle.size() > 0) {
				//α値計算
				mHideCircle[0].mColor.a -= mSpeed;
				//サイズ計算
				mHideCircle[0].mSize -= sizeChangeSpeed;

				//α値が最大値(1.0f)になったら
				//fadeInを使用可能に変更
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

		//生成・初期化
		if (!mIsEndInit) {

			//データをパターンに合わせて初期化
			mPattern = VEIL_FADE;
			mInterval = (60 * time);
			mSpeed = ((float)getWindowHeight() / mInterval);

			//必要な個数生成
			mHideCube.emplace_back();

			//生成したオブジェクトの初期化
			mHideCube[0].mPos =
				Vec3f(0.0f, 0.0f, 0.0f);

			mHideCube[0].mSize = Vec3f(
				(float)getWindowWidth(),
				(float)getWindowHeight(),
				0.1f);

			mHideCube[0].mColor =
				ColorA(0.0f, 0.0f, 0.0f, 1.0f);

			//一度だけしか処理しないように
			mIsEndInit = true;
		}

		//初期化が終了後、更新開始
		if (mIsEndInit) {

			if ((int)mHideCube.size() > 0) {
				//α値計算
				mHideCube[0].mPos.y -= mSpeed;

				//α値が最大値(1.0f)になったら
				//fadeInを使用可能に変更
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

		//生成・初期化
		if (!mIsEndInit) {

			//データをパターンに合わせて初期化
			mPattern = FROM_LEFT_CURTAIN_FADE;
			mInterval = (60 * time);
			mSpeed = ((float)getWindowWidth() / mInterval);

			//必要な個数生成
			mHideCube.emplace_back();

			//生成したオブジェクトの初期化
			mHideCube[0].mPos =
				Vec3f(0.0f, 0.0f, 0.0f);

			mHideCube[0].mSize = Vec3f(
				(float)getWindowWidth(),
				(float)getWindowHeight(),
				0.1f);

			mHideCube[0].mColor =
				ColorA(0.0f, 0.0f, 0.0f, 1.0f);

			//一度だけしか処理しないように
			mIsEndInit = true;
		}

		//初期化が終了後、更新開始
		if (mIsEndInit) {

			if ((int)mHideCube.size() > 0) {
				//α値計算
				mHideCube[0].mPos.x -= mSpeed;

				//α値が最大値(1.0f)になったら
				//fadeInを使用可能に変更
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

		//生成・初期化
		if (!mIsEndInit) {

			//データをパターンに合わせて初期化
			mPattern = FROM_RIGHT_CURTAIN_FADE;
			mInterval = (60 * time);
			mSpeed = ((float)getWindowWidth() / mInterval);

			//必要な個数生成
			mHideCube.emplace_back();

			//生成したオブジェクトの初期化
			mHideCube[0].mPos =
				Vec3f(0.0f, 0.0f, 0.0f);

			mHideCube[0].mSize = Vec3f(
				(float)getWindowWidth(),
				(float)getWindowHeight(),
				0.1f);

			mHideCube[0].mColor =
				ColorA(0.0f, 0.0f, 0.0f, 1.0f);

			//一度だけしか処理しないように
			mIsEndInit = true;
		}

		//初期化が終了後、更新開始
		if (mIsEndInit) {

			if ((int)mHideCube.size() > 0) {
				//α値計算
				mHideCube[0].mPos.x += mSpeed;

				//α値が最大値(1.0f)になったら
				//fadeInを使用可能に変更
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

		//生成・初期化
		if (!mIsEndInit) {

			//データをパターンに合わせて初期化
			mPattern = CENTER_CURTAIN_FADE;
			mInterval = (60 * time);
			mSpeed =
				((float)(getWindowWidth() / 2) / mInterval);

			//必要な個数生成
			mHideCube.emplace_back();
			mHideCube.emplace_back();

			//生成したオブジェクトの初期化
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

			//一度だけしか処理しないように
			mIsEndInit = true;
		}

		//初期化が終了後、更新開始
		if (mIsEndInit) {

			if ((int)mHideCube.size() > 0) {
				//α値計算
				mHideCube[0].mPos.x -= mSpeed;
				mHideCube[1].mPos.x += mSpeed;

				//α値が最大値(1.0f)になったら
				//fadeInを使用可能に変更
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

		//生成・初期化
		if (!mIsEndInit) {

			//データをパターンに合わせて初期化
			mPattern = PIN_HOLE_FADE;
			mInterval = (60 * time);
			mSpeed = (((float)getWindowWidth() - space) / mInterval);

			//必要な個数生成
			mHideCylinder.emplace_back();

			//生成したオブジェクトの初期化
			mHideCylinder[0].mStartPos = space;
			mHideCylinder[0].mEndPos = windowOutPos;
			mHideCylinder[0].mSliceCount = slices;
			mHideCylinder[0].mColor = ColorA(
				0.0f, 0.0f, 0.0f, 1.0f);

			//一度だけしか処理しないように
			mIsEndInit = true;
		}

		//初期化が終了後、更新開始
		if (mIsEndInit) {

			if ((int)mHideCylinder.size() > 0) {
				//サイズ計算
				mHideCylinder[0].mStartPos += mSpeed;

				//α値が最大値(1.0f)になったら
				//fadeInを使用可能に変更
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

			//表示位置を中心に移動・透明度追加・色を変更
			gl::pushModelView();
			gl::translate(getWindowCenter());

			gl::enableAlphaBlending();

			gl::color(mHideCube[i].mColor);

			//描画
			gl::drawCube(mHideCube[i].mPos, mHideCube[i].mSize);

			//全て元に戻す
			gl::color(1.0f, 1.0f, 1.0f, 1.0f);

			gl::disableAlphaBlending();

			gl::popModelView();

		}

		break;
#pragma endregion
#pragma region case CIRCLE_SCALING_FADE:
	case CIRCLE_SCALING_FADE:

		for (unsigned int i = 0; i < mHideCircle.size(); ++i) {

			//透明度追加・表示位置を中心に移動・色を変更
			gl::pushModelView();
			gl::translate(getWindowCenter());

			gl::enableAlphaBlending();

			gl::color(mHideCircle[i].mColor);

			//描画
			gl::drawSolidCircle(mHideCircle[i].mPos.xy(), mHideCircle[i].mSize);

			//全て元に戻す
			gl::color(1.0f, 1.0f, 1.0f, 1.0f);

			gl::disableAlphaBlending();

			gl::popModelView();

		}

		break;
#pragma endregion
#pragma region case VEIL_FADE:
	case VEIL_FADE:

		for (unsigned int i = 0; i < mHideCube.size(); ++i) {

			//透明度追加・表示位置を中心に移動・色を変更
			gl::pushModelView();
			gl::translate(getWindowCenter());

			gl::enableAlphaBlending();

			gl::color(mHideCube[i].mColor);

			//描画
			gl::drawCube(mHideCube[i].mPos, mHideCube[i].mSize);

			//全て元に戻す
			gl::color(1.0f, 1.0f, 1.0f, 1.0f);

			gl::disableAlphaBlending();

			gl::popModelView();

		}

		break;
#pragma endregion
#pragma region case FROM_LEFT_CURTAIN_FADE:
	case FROM_LEFT_CURTAIN_FADE:

		for (unsigned int i = 0; i < mHideCube.size(); ++i) {

			//透明度追加・表示位置を中心に移動・色を変更
			gl::pushModelView();
			gl::translate(getWindowCenter());

			gl::enableAlphaBlending();

			gl::color(mHideCube[i].mColor);

			//描画
			gl::drawCube(mHideCube[i].mPos, mHideCube[i].mSize);

			//全て元に戻す
			gl::color(1.0f, 1.0f, 1.0f, 1.0f);

			gl::disableAlphaBlending();

			gl::popModelView();

		}

		break;
#pragma endregion
#pragma region case FROM_RIGHT_CURTAIN_FADE:
	case FROM_RIGHT_CURTAIN_FADE:

		for (unsigned int i = 0; i < mHideCube.size(); ++i) {

			//透明度追加・表示位置を中心に移動・色を変更
			gl::pushModelView();
			gl::translate(getWindowCenter());

			gl::enableAlphaBlending();

			gl::color(mHideCube[i].mColor);

			//描画
			gl::drawCube(mHideCube[i].mPos, mHideCube[i].mSize);

			//全て元に戻す
			gl::color(1.0f, 1.0f, 1.0f, 1.0f);

			gl::disableAlphaBlending();

			gl::popModelView();

		}

		break;
#pragma endregion
#pragma region case CENTER_CURTAIN_FADE:
	case CENTER_CURTAIN_FADE:

		for (unsigned int i = 0; i < mHideCube.size(); ++i) {

			//透明度追加・表示位置を中心に移動・色を変更
			gl::pushModelView();
			gl::translate(getWindowCenter());

			gl::enableAlphaBlending();

			gl::color(mHideCube[i].mColor);

			//描画
			gl::drawCube(mHideCube[i].mPos, mHideCube[i].mSize);

			//全て元に戻す
			gl::color(1.0f, 1.0f, 1.0f, 1.0f);

			gl::disableAlphaBlending();

			gl::popModelView();

		}

		break;
#pragma endregion
#pragma region case PIN_HOLE_FADE:
	case PIN_HOLE_FADE:

		for (unsigned int i = 0; i < mHideCylinder.size(); ++i) {

			//透明度追加・表示位置を中心に移動・色を変更・画像の貼り付け
			gl::pushModelView();
			gl::translate(getWindowCenter());
			gl::rotate(Vec3f(90, 0, 0));

			gl::enableAlphaBlending();

			gl::color(mHideCylinder[i].mColor);

			//描画
			gl::drawCylinder(
				mHideCylinder[i].mStartPos,
				mHideCylinder[i].mEndPos,
				0.1f,
				mHideCylinder[i].mSliceCount);

			//全て元に戻す			
			gl::color(Color(1, 1, 1));
			gl::popModelView();

		}

		break;
#pragma endregion
	}

}

