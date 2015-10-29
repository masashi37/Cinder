
#pragma once

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"

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
	
	//画面中に四角が多数出て画面を埋め尽くしてfade
	//使用できない(未完成)
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


	gl::Texture mPinHallTexture;


	bool mIsReadyFadeOut;
	bool mIsEndFadeOut;

	bool mIsReadyFadeIn;
	bool mIsEndFadeIn;

	bool mIsEndInit;


	FadePattern mPattern;

	int mFadeInterval;

	float mFadeSpeed;

	int mNoiseCubeLength;
	int mNoiseCubeWide;

public:

	Fade();


	//全画面一律のFadeOut　(終了までの秒数(int))
	void fullScreenFadeOut(const int);
	//全画面一律のFadeOut　(終了までの秒数(int))
	void fullScreenFadeIn(const int);

	//センターからサークルが広がってFadeOut　(終了までの秒数(int))
	void circleScalingFadeOut(const int);
	//センターからサークルが広がってFadeIn　(終了までの秒数(int))
	void circleScalingFadeIn(const int);

	//垂れ幕式FadeOut　(終了までの秒数(int))
	void veilMoveFadeOut(const int);
	//垂れ幕式FadeIn　(終了までの秒数(int))
	void veilMoveFadeIn(const int);

	//カーテン式(進行方向←)FadeOut　(終了までの秒数(int))
	void fromLeftCurtainFadeOut(const int);
	//カーテン式(進行方向←)FadeIn　(終了までの秒数(int))
	void fromLeftCurtainFadeIn(const int);

	//カーテン式(進行方向→)FadeOut　(終了までの秒数(int))
	void fromRightCurtainFadeOut(const int);
	//カーテン式(進行方向→)FadeIn　(終了までの秒数(int))
	void fromRightCurtainFadeIn(const int);

	//中央カーテン式(進行方向)FadeOut　(終了までの秒数(int))
	void centerCurtainFadeOut(const int);
	//中央カーテン式(進行方向)FadeIn　(終了までの秒数(int))
	void centerCurtainFadeIn(const int);

	//ピンホールFadeOut　(終了までの秒数(int),)
	void pinHallFadeOut(const int,const bool);
	//ピンホールFadeOut　(終了までの秒数(int))
	void pinHallFadeOut(const int);
	//ピンホールFadeIn　(終了までの秒数(int))
	void pinHallFadeIn(const int);

	//ノイズ(Cube)大量表示でFadeOut
	//(インターバル(int),縦のマス数(int),横のマス数(int))
	void noiseFadeOut(const int,const int,const int);
	//ノイズ(Cube)大量表示でFadeIn
	//(インターバル(int),縦のマス数(int),横のマス数(int))
	void noiseFadeIn(const int);

	
	//FadeOut/Inの描画
	void draw();

};
