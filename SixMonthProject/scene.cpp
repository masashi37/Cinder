
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

void cScene::mouseDown(MouseEvent event) {

	switch (scene_mover){
	case TITLE:
		title.mouseDown(event);
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

void cScene::mouseUp(MouseEvent event) {

	switch (scene_mover){
	case TITLE:
		title.mouseUp(event);
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

void cScene::mouseMove(MouseEvent event) {

	switch (scene_mover){
	case TITLE:
		title.mouseMove(event);
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

