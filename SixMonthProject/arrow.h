
#pragma once

#include "common.h"


class cArrow{

	const Vec3f size = { 10.0f, 10.0f, 100.0f };
	Vec3f pos = { -(this->size.x) / 2.0f, -(this->size.y) / 2.0f, 0.0f };
	const float move = 3.0f;

	float speed = 0;
	const float plus_speed = 1.0f;
	bool is_push_space = false;
	bool is_shoot_arrow = false;

public:

	void setup();
	void update();
	void shift();
	void draw();

	void keyDown(KeyEvent);
	void keyUp(KeyEvent);

	//void mouseDown(MouseEvent);
	//void mouseUp(MouseEvent);
	//void mouseMove(MouseEvent);

};