
#pragma once

#include "common.h"
#include "cinder/Matrix.h"

class cArrow : public AppNative {

private:

	//矢
	struct Arrow{
		Vec3f pos;
		Vec3f radian;
		const Vec3f size = { 100, 5, 5 };
		float spped;
	}arrow;//弓矢

	float speed_plus = 0.1f;		//矢の速度を変える定数値
	bool is_press_space;		//スペースキーが押されているか？
	bool is_shooting_arrow;		//弓矢が放たれているか？

public:

	void setup();
	void update();
	void keyDown(KeyEvent);
	void keyUp(KeyEvent);
	void draw();

};

