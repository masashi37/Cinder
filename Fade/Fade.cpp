
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

	//選んだパターンが動くように変更
	mPattern = fadePattern;

	//この関数が呼ばれた時fadeOutが終了しているなら動かせない
	//終了していないならfadeOutを動かす準備が完了
	if (mIsEndFadeOut)return;
	mIsReadyFadeOut = true;

	if (mIsReadyFadeOut) {

		switch (mPattern) {
#pragma region case CUBE_FADE:
		case CUBE_FADE:

			//生成・初期化
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

				//一度だけしか処理しないように
				mIsEndInit = true;
			}

			//初期化が終了後、更新開始
			if (mIsEndInit) {

				for (unsigned int i = 0; i < mHideCube.size(); ++i) {
					//α値計算
					mHideCube[i].mColor.a += FADE_SPEED;

					//α値が最大値(1.0f)になったら
					//fadeInを使用可能に変更
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

			//生成・初期化
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

				//一度だけしか処理しないように
				mIsEndInit = true;
			}

			//初期化が終了後、更新開始
			if (mIsEndInit) {

				const float sizeChangeSpeed =
					((float)getWindowWidth() / FADE_INTERVAL);

				for (unsigned int i = 0; i < mHideCircle.size(); ++i) {
					//α値計算
					mHideCircle[i].mColor.a += FADE_SPEED;
					//サイズ計算
					mHideCircle[i].mSize += sizeChangeSpeed;

					//α値が最大値(1.0f)になったら
					//fadeInを使用可能に変更
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

			//生成・初期化
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

				//一度だけしか処理しないように
				mIsEndInit = true;
			}

			//初期化が終了後、更新開始
			if (mIsEndInit) {

				const float cubeMoveSpeed =
					(float)getWindowHeight() / FADE_INTERVAL;

				for (unsigned int i = 0; i < mHideCube.size(); ++i) {
					//α値計算
					mHideCube[i].mPos.y += cubeMoveSpeed;

					//α値が最大値(1.0f)になったら
					//fadeInを使用可能に変更
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

			//生成・初期化
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

				//一度だけしか処理しないように
				mIsEndInit = true;
			}

			//初期化が終了後、更新開始
			if (mIsEndInit) {

				const float cubeMoveSpeed =
					(float)getWindowHeight() / FADE_INTERVAL;

				for (unsigned int i = 0; i < mHideCube.size(); ++i) {
					//α値計算
					mHideCube[i].mPos.y += cubeMoveSpeed;

					//α値が最大値(1.0f)になったら
					//fadeInを使用可能に変更
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

			//生成・初期化
			if (!mIsEndInit) {
				//分割数
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

				//一度だけしか処理しないように
				mIsEndInit = true;
			}

			//初期化が終了後、更新開始
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

				//α値が最大値(1.0f)になったら
				//fadeInを使用可能に変更
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

	//この関数が呼ばれた時fadeInが終了しているなら動かせない
	//同じくFadeoutが終了してないと使えない
	//両方の条件が成立しているならfadeInを動かす準備が完了
	if (mIsEndFadeIn)return;
	if (!mIsEndFadeOut)return;
	mIsReadyFadeIn = true;

	if (mIsReadyFadeIn) {

		switch (mPattern) {
#pragma region case CUBE_FADE:
		case CUBE_FADE:

			for (unsigned int i = 0; i < mHideCube.size(); ++i) {

				//α値加算
				mHideCube[i].mColor.a -= FADE_SPEED;

				//α値が最小値(0.0f)になったら
				//fadeOutを使用可能に変更
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

				//α値加算
				mHideCircle[i].mColor.a -= FADE_SPEED;
				//サイズ計算
				mHideCircle[i].mSize -= sizeChangeSpeed;

				//α値が最小値(0.0f)になったら
				//fadeOutを使用可能に変更
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

				//α値加算
				mHideCube[i].mPos.y -= cubeMoveSpeed;

				//α値が最小値(0.0f)になったら
				//fadeOutを使用可能に変更
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

				//α値加算
				mHidePolygon[i].mColor.a -= FADE_SPEED;

				//α値が最小値(0.0f)になったら
				//fadeOutを使用可能に変更
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

#pragma region case CIRCLE_FADE:
	case CIRCLE_FADE:

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

#pragma region case POLYGON_FADE:
	case POLYGON_FADE:

		for (unsigned int i = 0; i < mHidePolygon.size(); ++i) {

			//透明度追加・表示位置を中心に移動・色を変更
			gl::pushModelView();
			gl::translate(getWindowCenter());

			gl::enableAlphaBlending();

			gl::color(mHidePolygon[i].mColor);

			//描画
			gl::drawStrokedTriangle(
				mHidePolygon[i].mPos.xy(),
				mHidePolygon[i].mSecond_pos.xy(),
				mHidePolygon[i].mThird_pos.xy()
				);

			//全て元に戻す
			gl::color(1.0f, 1.0f, 1.0f, 1.0f);

			gl::disableAlphaBlending();

			gl::popModelView();

		}

		break;
#pragma endregion
	}

}

