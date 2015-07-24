
#include "Title.h"


void Title::init(){

	arrow->init();

}

void Title::update(){

	star->updata();
	arrow->update();

	particle_time++;
	if (particle_time % 60 == 0) {
		particle->create(5, Vec3f::zero());
	}

}

void Title::shift(){

}

void Title::draw(){

	star->draw();
	room->draw();
	arrow->draw();
	particle->draw();

}


void Title::mouseDown(MouseEvent event){

	arrow->mouseDown(event);

}

void Title::mouseMove(MouseEvent event){

	arrow->mouseMove(event);

}

void Title::mouseUp(MouseEvent event){

	arrow->mouseUp(event);

}

