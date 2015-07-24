
#include "Particle.h"


void Particle::create(int number, Vec3f particle_pos) {

	particle.clear();
	clear_time = 0;
	is_ready = false;

	for (int i = 0; i < number; ++i) {
		particle.emplace_back();
	}

	if (!is_ready) {
		for (unsigned int i = 0; i < particle.size(); ++i) {
			particle[i].pos = particle_pos;
			particle[i].size = { 10, 10, 10 };
			particle[i].speed = {
				Rand::randFloat(-5, 5),
				Rand::randFloat(-5, 5),
				Rand::randFloat(-5, 5)
			};
			particle[i].color = {
				Rand::randFloat(0, 1),
				Rand::randFloat(0, 1),
				Rand::randFloat(0, 1),
				1
			};
		}
		is_ready = true;
	}

}

void Particle::draw() {

	if (is_ready) {
		if (clear_time <= 60) {
			for (unsigned int i = 0; i < particle.size(); ++i) {
				gl::color(particle[i].color);
				gl::drawCube(particle[i].pos, particle[i].size);
				gl::color(1, 1, 1);

				particle[i].pos += particle[i].speed;
				if (particle[i].color.a >= 0)
					particle[i].color.a -= 0.02f;
			}

			clear_time++;

		}
	}

}
