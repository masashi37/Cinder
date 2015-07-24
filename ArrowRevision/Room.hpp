
#pragma once

#include "common.h"

typedef std::shared_ptr<class Room>RoomSP;
class Room{

public:

	const void draw(){

		//ïîâÆÇÃï«ÅEè∞
		gl::color(0.3f, 0.3f, 0.5f, 0.7f);
		gl::drawCube(
			Vec3f(0, HEIGHT / 2, -DEPTH / 2), Vec3f(WIDTH, 1, DEPTH));
		gl::drawCube(
			Vec3f(WIDTH / 2, 0, -DEPTH / 2), Vec3f(1, HEIGHT, DEPTH));
		gl::drawCube(
			Vec3f(-WIDTH / 2, 0, -DEPTH / 2), Vec3f(1, HEIGHT, DEPTH));
		gl::color(1, 1, 1, 1);

		//ïîâÆÇÃòg
		gl::color(0.8f, 0.8f, 0.8f);
		gl::drawStrokedCube(
			Vec3f(0, 0, -DEPTH / 2), Vec3f(WIDTH, HEIGHT, DEPTH));
		gl::color(1, 1, 1);

	}
};