
#pragma once

#include "Room.hpp"
#include "Star.hpp"
#include "Particle.h"
#include "Arrow.h"


typedef std::shared_ptr<class Title>TitleSP;
class Title{

private:

	RoomSP room = RoomSP(new Room);
	StarSP star = StarSP(new Star(150));
	ArrowSP arrow = ArrowSP(new Arrow);
	ParticleSP particle = ParticleSP(new Particle);

	//----------------------------------------------------

	int particle_time = 0;

public:

	void init();
	void update();
	void shift();
	void draw();

	void mouseDown(MouseEvent);
	void mouseMove(MouseEvent);
	void mouseUp(MouseEvent);
};
