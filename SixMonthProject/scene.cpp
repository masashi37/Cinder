
#include "scene.h"


void cScene::setup(){

	scene_mover = TITLE;

	switch (scene_mover){
	case TITLE:
		title.setup();
		break;
	case SELECT:
		select.setup();
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
		select.update();
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
		select.shift();
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
		select.draw();
		break;
	case GAME:
		break;
	case RESULT:
		break;
	}

}

void cScene::keyDown(KeyEvent event){

	switch (scene_mover){
	case TITLE:
		title.keyDown(event);
		break;
	case SELECT:
		select.keyDown(event);
		break;
	case GAME:
		break;
	case RESULT:
		break;
	}

}

void cScene::keyUp(KeyEvent event){

	switch (scene_mover){
	case TITLE:
		title.keyUp(event);
		break;
	case SELECT:
		select.keyUp(event);
		break;
	case GAME:
		break;
	case RESULT:
		break;
	}

}

/*
void cScene::mouseDown(KeyEvent event){}

void cScene::mouseUp(KeyEvent event){}

void cScene::mouseMove(KeyEvent event){}
*/

