
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

	//FadeTypeの番号
	enum FadeType {
		//全画面のα値変化でfade
		FULL_SCREEN_FADE,
		//画面の中心から円が出て、拡縮とα値変化でfade
		CIRCLE_SCALING_FADE,
		//画面上から垂れ幕(Cube)が出てfade
		VEIL_FADE,
		//左からカーテンの様にfade
		FROM_LEFT_CURTAIN_FADE,
		//右からカーテンの様にfade
		FROM_RIGHT_CURTAIN_FADE,
		//センターカーテンの様に横からfade
		CENTER_CURTAIN_FADE,
		//ピンホール型のfade(改善の余地有)
		PIN_HALL_FADE,
	};

	//どのパターンを使うのか制御するスイッチで使用
	FadeType mPattern;

	//Fadeさせるオブジェクトの形
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

	//オブジェクトを形毎にvectorで宣言
	std::vector<CubeDate>mHideCube;
	std::vector<CircleDate>mHideCircle;
	std::vector<PolygonDate>mHidePolygon;

	//開始を制御
	bool mCanStart;
	//終わったか確認用
	bool mIsEnd;
	//Initの制御
	bool mIsEndInit;

	//PinHallFadeの画像
	gl::Texture mPinHallTexture;

	//Fadeが終わるまでの時間
	int mInterval;
	//オブジェクトを変化させる速度
	// → mFadeIntervalを見て計算
	float mSpeed;

};