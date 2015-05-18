
#pragma once

#include "common.h"


//矢
class cArrowStatus{

public:

	struct ArrowStatus{
		Vec3f pos = { -WIDTH / 2 + 150, 100, 0 };
		Vec3f radian = { 0, 0, 0 };
		const Vec3f size = { 5, 100, 5 };
		float speed = 0;
	}arrow_status;

	Vec3f mouse_pos;						//マウスポジション 要らない
	float speed_plus = 0.1f;				//矢の速度の変更値
	float degree;							//
	bool is_press_left_button = false;		//押されているか？
	bool is_shooting_arrow = false;			//弓矢が放たれているか？

};