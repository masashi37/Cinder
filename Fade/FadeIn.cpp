
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
#pragma region case PIN_HALL_FADE:
	case PIN_HALL_FADE:

		for (unsigned int i = 0; i < mHideCube.size(); ++i) {

			//透明度追加・表示位置を中心に移動・色を変更・画像の貼り付け
			gl::pushModelView();
			gl::translate(getWindowCenter());

			gl::enableAlphaBlending();

			gl::color(mHideCube[i].mColor);

			gl::enable(GL_TEXTURE_2D);

			if (i == 0)
				mPinHallTexture.bind();

			//描画
			gl::drawCube(mHideCube[i].mPos, mHideCube[i].mSize);

			//全て元に戻す
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
		//			//透明度追加・表示位置を中心に移動・色を変更
		//			gl::pushModelView();
		//			gl::translate(getWindowCenter());
		//
		//			gl::enableAlphaBlending();
		//
		//			gl::color(mHideCube[i].mColor);
		//
		//			//描画
		//			gl::drawCube(mHideCube[i].mPos, mHideCube[i].mSize);
		//
		//			//全て元に戻す
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

