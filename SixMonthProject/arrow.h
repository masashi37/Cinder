
#pragma once

#include "common.h"


class cArrow{

	const Vec3f size = { 10.0f, 10.0f, 100.0f };
	Vec3f pos = { -(this->size.x) / 2.0f, -(this->size.y) / 2.0f, 0.0f };
	const float move_speed = 3.0f;

	enum {
		SPEED_MAX = 30,
		GAGE_SPACE = 30
	};
	float speed = 0;
	float plus_speed = 0.5f;
	bool is_press_space = false;
	bool is_shoot_arrow = false;
	float gravity = 0.0f;
	float gravity_puls = 0.1f;

	//ÉLÅ[ëÄçÏ
	enum Key{
		NONE,
		LEFT, RIGHT,
		UP, DOWN
	};
	int key_direction = 0;

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