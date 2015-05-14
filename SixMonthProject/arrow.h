
#pragma once

#include "common.h"
#include "cinder/Matrix.h"

class cArrow : public AppNative {

private:

	//��
	struct Arrow{
		Vec3f pos;
		Vec3f radian;
		const Vec3f size = { 100, 5, 5 };
		float spped;
	}arrow;//�|��

	float speed_plus = 0.1f;		//��̑��x��ς���萔�l
	bool is_press_space;		//�X�y�[�X�L�[��������Ă��邩�H
	bool is_shooting_arrow;		//�|�������Ă��邩�H

public:

	void setup();
	void update();
	void keyDown(KeyEvent);
	void keyUp(KeyEvent);
	void draw();

};

