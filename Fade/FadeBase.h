
#pragma once

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include "cinder/Timeline.h"
#include "cinder/Tween.h"

#include <vector>
#include <functional>

using namespace ci;
using namespace ci::app;
using namespace std;


enum FadeType {
None,

FullScreen,
Circle,
Vell,
FromLeft,
FromRight,
BothSide,
Hole
};

class FadeBase {

protected:

	enum FadeTypeName {
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
		PIN_HOLE_FADE,
	};
	FadeTypeName mPattern;

	//-----------------------------------------------

	//Objects
	struct ObjectBase {
		Vec3f mPos;
		ColorA mColor;
	};

	struct CubeDate :ObjectBase {
		Vec3f mSize;
	};
	std::vector<CubeDate>mHideCube;
	struct CircleDate :ObjectBase {
		float mSize;
	};
	std::vector<CircleDate>mHideCircle;
	struct CylinderDate {
		float mStartPos;
		float mEndPos;
		int mSliceCount;
		ColorA mColor;
	};
	std::vector<CylinderDate>mHideCylinder;

	//EasingObjects
	struct EasingObjectBase {
		Anim<Vec2f>mPos;
		Anim<Vec2f>mEndPos;
		ColorA mColor;
		Anim<float>mAlpha;
		Anim<float>mEndAlpha;
	};

	struct EasingCubeDate :EasingObjectBase {
		Anim<Vec2f>mSize;
		Anim<Vec2f>mEndSize;
	};
	std::vector<EasingCubeDate>mHideEasingCube;
	struct EasingCircleDate :EasingObjectBase {
		Anim<float>mSize;
		Anim<float>mEndSize;
	};
	std::vector<EasingCircleDate>mHideEasingCircle;
	struct EasingCylinderDate {
		Anim<float>mStartPos;
		Anim<float>mEndPos;
		int mSliceCount;
		ColorA mColor;
	};
	std::vector<EasingCylinderDate>mHideEasingCylinder;

	//Control of the function
	bool mCanStart;
	bool mIsEnd;
	bool mIsEndInit;

	bool mIsUseEasing;
	bool mIsEndEasing;

	int mInterval;
	float mSpeed;

};

//-----------------------------------------------------

static void lightUp(Rectf rectState, Color color) {

	ColorA lightColor =
		ColorA(color, 0.2f);

	gl::pushModelView();

	gl::translate(getWindowCenter());
	gl::enableAlphaBlending();
	gl::color(lightColor);

	gl::drawSolidRect(rectState);

	gl::color(1.0f, 1.0f, 1.0f, 1.0f);
	gl::disableAlphaBlending();

	gl::popModelView();

}