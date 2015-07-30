
#include "SceneBase.h"


void SceneBase::init() {

}

void SceneBase::roomUpdate() {

	star->updata();

	particle_time++;
	if (particle_time % PARTICLE_CREATE_TIME == 0) {
		particle->create(
			50,
			Vec3f(
				random.randFloat(-WIDTH / 2 + particle_pos_limit, WIDTH / 2 - particle_pos_limit),
				random.randFloat(-HEIGHT / 2 + particle_pos_limit, HEIGHT / 2 - particle_pos_limit),
				random.randFloat(0, -DEPTH / 2)));
	}

}

void SceneBase::update() {

}

void SceneBase::shift() {

}

void SceneBase::roomDraw() {

	star->draw();
	room->draw();
	particle->draw();

}

void SceneBase::draw() {

}


void SceneBase::mouseDown(MouseEvent event) {

}

void SceneBase::mouseMove(MouseEvent event) {

}

void SceneBase::mouseUp(MouseEvent event) {

}

