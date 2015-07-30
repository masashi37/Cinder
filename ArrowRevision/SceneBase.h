
#pragma once

#include "Room.hpp"
#include "Star.hpp"
#include "Particle.h"


class SceneBase {

protected:

	RoomSP room = RoomSP(new Room);
	StarSP star = StarSP(new Star(150));
	ParticleSP particle = ParticleSP(new Particle);

	Rand random;

	//----------------------------------------------------

	int particle_time = 0;
	const int PARTICLE_CREATE_TIME = 60 * 2;

	float particle_pos_limit = 50;

public:
	
	virtual void init();
	void roomUpdate();
	virtual void update();
	virtual void shift();
	void roomDraw();
	virtual void draw();

	virtual void mouseDown(MouseEvent);
	virtual void mouseMove(MouseEvent);
	virtual void mouseUp(MouseEvent);
};
