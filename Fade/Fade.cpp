
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

	//この関数が呼ばれた時fadeOutが終了しているなら動かせない
	//終了していないならfadeOutを動かす準備が完了
	if (mIsEndFadeOut)return;
	mIsReadyFadeOut = true;

	if (mIsReadyFadeOut) {

		//生成・初期化
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

			//一度だけしか処理しないように
			mIsEndInit = true;
		}

		//初期化が終了後、更新開始
		if (mIsEndInit) {

			for (unsigned int i = 0; i < mHideCube.size(); ++i) {
				//α値計算
				mHideCube[i].mColor.a += mFadeSpeed;

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

	}

}
void Fade::fullScreenFadeIn(const int time) {

	//この関数が呼ばれた時fadeInが終了しているなら動かせない
	//同じくFadeoutが終了してないと使えない
	//両方の条件が成立しているならfadeInを動かす準備が完了
	if (mIsEndFadeIn)return;
	if (!mIsEndFadeOut)return;
	mIsReadyFadeIn = true;

	mFadeInterval = (60 * time);
	mFadeSpeed = (1.0f / mFadeInterval);

	if (mIsReadyFadeIn) {

		for (unsigned int i = 0; i < mHideCube.size(); ++i) {

			//α値加算
			mHideCube[i].mColor.a -= mFadeSpeed;

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

	}

}

void Fade::circleScalingFadeOut(const int time) {

	//この関数が呼ばれた時fadeOutが終了しているなら動かせない
	//終了していないならfadeOutを動かす準備が完了
	if (mIsEndFadeOut)return;
	mIsReadyFadeOut = true;

	if (mIsReadyFadeOut) {

		//生成・初期化
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

			//一度だけしか処理しないように
			mIsEndInit = true;
		}

		//初期化が終了後、更新開始
		if (mIsEndInit) {

			const float sizeChangeSpeed =
				((float)getWindowWidth() / mFadeInterval);

			for (unsigned int i = 0; i < mHideCircle.size(); ++i) {
				//α値計算
				mHideCircle[i].mColor.a += mFadeSpeed;
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

	}

}
void Fade::circleScalingFadeIn(const int time) {

	//この関数が呼ばれた時fadeInが終了しているなら動かせない
	//同じくFadeoutが終了してないと使えない
	//両方の条件が成立しているならfadeInを動かす準備が完了
	if (mIsEndFadeIn)return;
	if (!mIsEndFadeOut)return;
	mIsReadyFadeIn = true;

	mFadeInterval = (60 * time);
	mFadeSpeed = (1.0f / mFadeInterval);

	if (mIsReadyFadeIn) {

		for (unsigned int i = 0; i < mHideCircle.size(); ++i) {

			const float sizeChangeSpeed =
				((float)getWindowWidth() / mFadeInterval);

			//α値加算
			mHideCircle[i].mColor.a -= mFadeSpeed;
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

	}

}

void Fade::veilMoveFadeOut(const int time) {

	//この関数が呼ばれた時fadeOutが終了しているなら動かせない
	//終了していないならfadeOutを動かす準備が完了
	if (mIsEndFadeOut)return;
	mIsReadyFadeOut = true;

	if (mIsReadyFadeOut) {

		//生成・初期化
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

			//一度だけしか処理しないように
			mIsEndInit = true;
		}

		//初期化が終了後、更新開始
		if (mIsEndInit) {

			for (unsigned int i = 0; i < mHideCube.size(); ++i) {
				//α値計算
				mHideCube[i].mPos.y += mFadeSpeed;

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

	}

}
void Fade::veilMoveFadeIn(const int time) {

	//この関数が呼ばれた時fadeInが終了しているなら動かせない
	//同じくFadeoutが終了してないと使えない
	//両方の条件が成立しているならfadeInを動かす準備が完了
	if (mIsEndFadeIn)return;
	if (!mIsEndFadeOut)return;
	mIsReadyFadeIn = true;

	mFadeInterval = (60 * time);
	mFadeSpeed = ((float)getWindowHeight() / mFadeInterval);

	if (mIsReadyFadeIn) {

		for (unsigned int i = 0; i < mHideCube.size(); ++i) {

			//α値加算
			mHideCube[i].mPos.y -= mFadeSpeed;

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

	}

}

void Fade::fromLeftCurtainFadeOut(const int time) {

	//この関数が呼ばれた時fadeOutが終了しているなら動かせない
	//終了していないならfadeOutを動かす準備が完了
	if (mIsEndFadeOut)return;
	mIsReadyFadeOut = true;

	if (mIsReadyFadeOut) {

		//生成・初期化
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

			//一度だけしか処理しないように
			mIsEndInit = true;
		}

		//初期化が終了後、更新開始
		if (mIsEndInit) {

			for (unsigned int i = 0; i < mHideCube.size(); ++i) {
				//α値計算
				mHideCube[i].mPos.x += mFadeSpeed;

				//α値が最大値(1.0f)になったら
				//fadeInを使用可能に変更
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

	//この関数が呼ばれた時fadeInが終了しているなら動かせない
	//同じくFadeoutが終了してないと使えない
	//両方の条件が成立しているならfadeInを動かす準備が完了
	if (mIsEndFadeIn)return;
	if (!mIsEndFadeOut)return;
	mIsReadyFadeIn = true;

	mFadeInterval = (60 * time);
	mFadeSpeed = ((float)getWindowWidth() / mFadeInterval);

	if (mIsReadyFadeIn) {

		for (unsigned int i = 0; i < mHideCube.size(); ++i) {

			//α値加算
			mHideCube[i].mPos.x -= mFadeSpeed;

			//α値が最小値(0.0f)になったら
			//fadeOutを使用可能に変更
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

	//この関数が呼ばれた時fadeOutが終了しているなら動かせない
	//終了していないならfadeOutを動かす準備が完了
	if (mIsEndFadeOut)return;
	mIsReadyFadeOut = true;

	if (mIsReadyFadeOut) {

		//生成・初期化
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

			//一度だけしか処理しないように
			mIsEndInit = true;
		}

		//初期化が終了後、更新開始
		if (mIsEndInit) {

			for (unsigned int i = 0; i < mHideCube.size(); ++i) {
				//α値計算
				mHideCube[i].mPos.x -= mFadeSpeed;

				//α値が最大値(1.0f)になったら
				//fadeInを使用可能に変更
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

	//この関数が呼ばれた時fadeInが終了しているなら動かせない
	//同じくFadeoutが終了してないと使えない
	//両方の条件が成立しているならfadeInを動かす準備が完了
	if (mIsEndFadeIn)return;
	if (!mIsEndFadeOut)return;
	mIsReadyFadeIn = true;

	mFadeInterval = (60 * time);
	mFadeSpeed = ((float)getWindowWidth() / mFadeInterval);

	if (mIsReadyFadeIn) {

		for (unsigned int i = 0; i < mHideCube.size(); ++i) {

			//α値加算
			mHideCube[i].mPos.x += mFadeSpeed;

			//α値が最小値(0.0f)になったら
			//fadeOutを使用可能に変更
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

	//この関数が呼ばれた時fadeOutが終了しているなら動かせない
	//終了していないならfadeOutを動かす準備が完了
	if (mIsEndFadeOut)return;
	mIsReadyFadeOut = true;

	const float quarterWindowSize = (float)(getWindowWidth() / 4);

	if (mIsReadyFadeOut) {

		//生成・初期化
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

			//一度だけしか処理しないように
			mIsEndInit = true;
		}

		//初期化が終了後、更新開始
		if (mIsEndInit) {

			//α値計算
			mHideCube[0].mPos.x += mFadeSpeed;
			mHideCube[1].mPos.x -= mFadeSpeed;

			//α値が最大値(1.0f)になったら
			//fadeInを使用可能に変更
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

	//この関数が呼ばれた時fadeInが終了しているなら動かせない
	//同じくFadeoutが終了してないと使えない
	//両方の条件が成立しているならfadeInを動かす準備が完了
	if (mIsEndFadeIn)return;
	if (!mIsEndFadeOut)return;
	mIsReadyFadeIn = true;

	const float quarterWindowSize = (float)(getWindowWidth() / 4);

	mFadeInterval = (60 * time);
	mFadeSpeed = ((float)(getWindowWidth() / 2) / mFadeInterval);

	if (mIsReadyFadeIn) {

		//α値計算
		mHideCube[0].mPos.x -= mFadeSpeed;
		mHideCube[1].mPos.x += mFadeSpeed;

		//α値が最小値(0.0f)になったら
		//fadeOutを使用可能に変更
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

void Fade::pinHallFadeOut(const int time, const bool canClose) {

	//この関数が呼ばれた時fadeOutが終了しているなら動かせない
	//終了していないならfadeOutを動かす準備が完了
	if (mIsEndFadeOut)return;
	mIsReadyFadeOut = true;

	const float fadeSpeedY
		= (((float)getWindowHeight() * 5) / mFadeInterval);
	const float quarterWindowWidth
		= ((float)getWindowWidth() / 4);
	const float quarterWindowHeight
		= ((float)getWindowHeight() / 4);

	if (mIsReadyFadeOut) {

		//生成・初期化
		if (!mIsEndInit) {

			mPinHallTexture =
				loadImage(loadAsset("PinHallFade.png"));

			mPattern = PIN_HALL_FADE;
			mFadeInterval = (60 * time);
			mFadeSpeed = (((float)getWindowWidth() * 5) / mFadeInterval);

			mCanMoveHideBox = false;

			for (int i = 0; i < 5; ++i) {
				mHideCube.emplace_back();
			}

			//PosInit--------------------------
			mHideCube[0].mPos =
				Vec3f::zero();
			mHideCube[1].mPos = Vec3f(
				-(quarterWindowWidth * 3),
				0.0f,
				0.0f);
			mHideCube[2].mPos = Vec3f(
				(quarterWindowWidth * 3),
				0.0f,
				0.0f);
			mHideCube[3].mPos = Vec3f(
				0.0f,
				-(quarterWindowHeight * 3),
				0.0f);
			mHideCube[4].mPos = Vec3f(
				0.0f,
				(quarterWindowHeight * 3),
				0.0f);

			//SizeInit------------------------------
			mHideCube[0].mSize = Vec3f(
				(float)getWindowWidth() * 5,
				(float)getWindowHeight() * 5,
				0.0f);
			mHideCube[1].mSize = Vec3f(
				(float)getWindowWidth() / 2,
				(float)getWindowHeight(),
				0.0f);
			mHideCube[2].mSize = Vec3f(
				(float)getWindowWidth() / 2,
				(float)getWindowHeight(),
				0.0f);
			mHideCube[3].mSize = Vec3f(
				(float)getWindowWidth(),
				(float)getWindowHeight() / 2,
				0.0f);
			mHideCube[4].mSize = Vec3f(
				(float)getWindowWidth(),
				(float)getWindowHeight() / 2,
				0.0f);

			//ColorInit---------------------------------
			for (int i = 0; i < 5; ++i) {
				mHideCube[i].mColor =
					ColorA(0.0f, 0.0f, 0.0f, 1.0f);
			}

			//一度だけしか処理しないように
			mIsEndInit = true;
		}

		//初期化が終了後、更新開始
		if (mIsEndInit) {

			if (mCanMoveHideBox) {
				mHideCube[0].mSize.x -= mFadeSpeed;
				mHideCube[0].mSize.y -= fadeSpeedY;

				mHideCube[1].mPos.x += mFadeSpeed;
				mHideCube[2].mPos.x -= mFadeSpeed;
				mHideCube[3].mPos.y += fadeSpeedY;
				mHideCube[4].mPos.y -= fadeSpeedY;
			}
			else {
				mHideCube[0].mSize.x -= mFadeSpeed;
				mHideCube[0].mSize.y -= fadeSpeedY;
			}

			//α値が最大値(1.0f)になったら
			//fadeInを使用可能に変更
			if (mHideCube[0].mSize.x <= (float)getWindowWidth() ||
				mHideCube[0].mSize.y <= (float)getWindowHeight()) {

				if (canClose) {
					mCanMoveHideBox = true;

					//閉じる場合
					if (mHideCube[1].mPos.x >= -quarterWindowWidth) {
						mIsEndFadeOut = true;
						mIsEndFadeIn = false;
						return;
					}
				}
				else {
					mHideCube[0].mSize.x = (float)getWindowWidth();
					mHideCube[0].mSize.y = (float)getWindowHeight();
					mIsEndFadeOut = true;
					mIsEndFadeIn = false;
					return;
				}
			}
		}

	}
}
void Fade::pinHallFadeIn(const int time) {

	//この関数が呼ばれた時fadeInが終了しているなら動かせない
	//同じくFadeoutが終了してないと使えない
	//両方の条件が成立しているならfadeInを動かす準備が完了
	if (mIsEndFadeIn)return;
	if (!mIsEndFadeOut)return;
	mIsReadyFadeIn = true;

	mFadeInterval = (60 * time);
	mFadeSpeed = (((float)getWindowWidth() * 5) / mFadeInterval);

	float fadeSpeedY =
		(((float)getWindowHeight() * 5) / mFadeInterval);
	const float quarterWindowWidth
		= ((float)getWindowWidth() / 4);
	const float quarterWindowHeight
		= ((float)getWindowHeight() / 4);

	if (mIsReadyFadeIn) {

		if (mCanMoveHideBox) {
			mHideCube[0].mSize.x += mFadeSpeed;
			mHideCube[0].mSize.y += fadeSpeedY;

			mHideCube[1].mPos.x -= mFadeSpeed;
			mHideCube[2].mPos.x += mFadeSpeed;
			mHideCube[3].mPos.y -= fadeSpeedY;
			mHideCube[4].mPos.y += fadeSpeedY;
		}
		else {
			mHideCube[0].mSize.x += mFadeSpeed;
			mHideCube[0].mSize.y += fadeSpeedY;
		}

		//α値が最小値(0.0f)になったら
		//fadeOutを使用可能に変更a
		if (mHideCube[0].mSize.x >= ((float)getWindowWidth() * 5) ||
			mHideCube[0].mSize.y >= ((float)getWindowHeight() * 5)) {

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

//----------------------------------
//TODO:ノイズフェードの計算を完成させる
//forをxとyでやる方が簡単？
//----------------------------------

void Fade::noiseFadeOut(
	const int time, const int length, const int wide) {

	//この関数が呼ばれた時fadeOutが終了しているなら動かせない
	//終了していないならfadeOutを動かす準備が完了
	if (mIsEndFadeOut)return;
	mIsReadyFadeOut = true;

	const Vec2f cubeSize = Vec2f(
		((float)getWindowWidth() / wide),
		((float)getWindowHeight() / length));

	const int cubeMax = wide * length;

	int timer = 0;

	if (mIsReadyFadeOut) {

		//生成・初期化
		if (!mIsEndInit) {

			mPattern = NOISE_FADE;
			mFadeInterval = (60 * time);
			mFadeSpeed = ((float)cubeMax / mFadeInterval);

			mNoiseCubeLength = length;
			mNoiseCubeWide = wide;

			for (int y = 0; y < mNoiseCubeLength; ++y) {
				for (int x = 0; x < mNoiseCubeWide; ++x) {
					mHideCube.emplace_back();
				}
			}

			int cubeNumber;
			for (int y = 0; y < mNoiseCubeLength; ++y) {
				for (int x = 0; x < mNoiseCubeWide; ++x) {

					cubeNumber = x + (mNoiseCubeWide * y);
					console() << cubeNumber << std::endl;

					mHideCube[cubeNumber].mPos = Vec3f(
						-((float)getWindowWidth() / 2) +
						(cubeSize.x / 2) + (cubeSize.x * (x % y)),
						-((float)getWindowHeight() / 2) +
						(cubeSize.y / 2) + (cubeSize.y * y),
						0.0f);

					mHideCube[cubeNumber].mSize =
						Vec3f(
							cubeSize.x,
							cubeSize.y,
							0.1f);

					mHideCube[cubeNumber].mColor =
						ColorA(0.0f, 0.0f, 0.0f, 1.0f);
				}
			}

			//一度だけしか処理しないように
			mIsEndInit = true;
		}

		//初期化が終了後、更新開始
		if (mIsEndInit) {

			//α値計算
			timer++;

			for (int i = 0; i < cubeMax;) {
				mHideCube[i].mColor.a = 1.0f;
			}

			//α値が最大値(1.0f)になったら
			//fadeInを使用可能に変更
			if (mHideCube[cubeMax].mColor.a == 1.0f) {
				mIsEndFadeOut = true;
				mIsEndFadeIn = false;
				return;
			}

		}

	}

}
void Fade::noiseFadeIn(const int time) {

	//この関数が呼ばれた時fadeInが終了しているなら動かせない
	//同じくFadeoutが終了してないと使えない
	//両方の条件が成立しているならfadeInを動かす準備が完了
	if (mIsEndFadeIn)return;
	if (!mIsEndFadeOut)return;
	mIsReadyFadeIn = true;

	const int cubeMax = mNoiseCubeWide * mNoiseCubeLength;

	int timer = 0;
	int y = 0;

	mFadeInterval = (60 * time);
	mFadeSpeed =
		((float)cubeMax / mFadeInterval);

	if (mIsReadyFadeIn) {

		//α値計算
		timer++;

		for (int i = (cubeMax + 1); i > -1;) {
			if ((timer / mFadeInterval) == 0)--i;

			if (i <= (int)mHideCube.size())
				mHideCube[i].mColor.a = 0.0f;
		}

		//α値が最小値(0.0f)になったら
		//fadeOutを使用可能に変更
		if (mHideCube[0].mColor.a == 0.0f) {

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


void Fade::draw() {

	switch (mPattern) {
#pragma region case FULL_SCREEN_FADE:
	case FULL_SCREEN_FADE:

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

#pragma region case NOISE_FADE:
	case NOISE_FADE:

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
	}

}

