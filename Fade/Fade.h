
#pragma once

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include <vector>

using namespace ci;
using namespace ci::app;
using namespace std;


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

enum FadePattern {
	//全画面のα値変化でfade
	CUBE_FADE,
	//画面の中心から円が出て、拡縮とα値変化でfade
	CIRCLE_FADE,
	//画面上から垂れ幕(Cube)が出てfade
	VEIL_FADE,
	//サイドカーテンの様に横からfade
	//未実装
	SIDE_CURTAIN_FADE,
	//センターカーテンの様に横からfade
	//未実装
	CENTER_CURTAIN_FADE,
	//ピンホール型のfade
	//未実装
	PIN_HALL_FADE,
	//画面中に四角が多数出て画面を埋め尽くしてfade
	//未実装
	NOISE_FADE,
	//画面の中心から三角が出て扇形に徐々に展開してfade
	//使用できない(未完成)
	POLYGON_FADE,

};


class Fade {

private:

	std::vector<CubeDate>mHideCube;
	std::vector<CircleDate>mHideCircle;
	std::vector<PolygonDate>mHidePolygon;


	bool mIsReadyFadeOut;
	bool mIsEndFadeOut;

	bool mIsReadyFadeIn;
	bool mIsEndFadeIn;

	bool mIsEndInit;


	int mPattern;

	const int FADE_INTERVAL = (60 * 2);

	const float FADE_SPEED = (1.0f / FADE_INTERVAL);

public:

	Fade();


	//「Fadeout」を使う時呼ぶ
	void fadeOut(const int);

	//「Fadein」を使う時呼ぶ
	void fadeIn();

	void draw();

};
