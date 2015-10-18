
#pragma once

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include <vector>

using namespace ci;
using namespace ci::app;
using namespace std;


struct ObjectBase {
	Vec3f pos;

	ColorA color;
};
struct Cube :ObjectBase {
	Vec3f size;
};
struct Circle :ObjectBase {
	float size;
};
struct Polygon :ObjectBase {
	Vec3f second_pos;
	Vec3f third_pos;
};

enum FadePattern {
	CUBE_FADE
};


class Fade {

private:

	std::vector<Cube>hide_cube_;
	std::vector<Cube>hide_circle_;


	int time;

	int fade_pattern_;

	const float speed = (1.0f / (60 * 2));

	bool is_end_ready_fadeout_;
	bool is_ready_fadein_;

public:

	Fade();


	void fadeOut(const int);

	void fadeIn();

	bool getIsStartFadein();

};
