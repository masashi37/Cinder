
#include "scene.h"


cScene::cScene(){
	scene_mover = TITLE;
}

void cScene::setup(){

	switch (scene_mover){
	case TITLE:
		title.setup();
		break;
	case SELECT:
		break;
	case GAME:
		break;
	case RESULT:
		break;

	default:
		break;
	}

}

void cScene::update(){

	switch (scene_mover){
	case TITLE:
		title.update();
		break;
	case SELECT:
		break;
	case GAME:
		break;
	case RESULT:
		break;

	default:
		break;
	}

}

void cScene::keyDown(KeyEvent event) {

	switch (scene_mover){
	case TITLE:
		title.keyEvent(event);
		break;
	case SELECT:
		break;
	case GAME:
		break;
	case RESULT:
		break;

	default:
		break;
	}

}

void cScene::keyUp(KeyEvent event) {

	switch (scene_mover){
	case TITLE:
		title.keyEvent(event);
		break;
	case SELECT:
		break;
	case GAME:
		break;
	case RESULT:
		break;

	default:
		break;
	}

}

void cScene::shift(){

	switch (scene_mover){
	case TITLE:
		title.shift();
		break;
	case SELECT:
		break;
	case GAME:
		break;
	case RESULT:
		break;

	default:
		break;
	}

}

void cScene::draw(){

	switch (scene_mover){
	case TITLE:
		title.draw();
		break;
	case SELECT:
		break;
	case GAME:
		break;
	case RESULT:
		break;
	}

}

