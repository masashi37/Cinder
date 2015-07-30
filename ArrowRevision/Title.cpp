
#include "Title.h"


void Title::init() {

	arrow->init();

}

void Title::update() {

	SceneBase::roomUpdate();
	arrow->update();

}

void Title::shift() {

}

void Title::draw() {

	SceneBase::roomDraw();
	arrow->draw();

}


void Title::mouseDown(MouseEvent event) {

	arrow->mouseDown(event);

}

void Title::mouseMove(MouseEvent event) {

	arrow->mouseMove(event);

}

void Title::mouseUp(MouseEvent event) {

	arrow->mouseUp(event);

}

