
#include "scene.h"


cScene::cScene(){

	scene_mover = SELECT;

}

void cScene::init(){

	title.init();
	select.init();
	game.init();

}

void cScene::update(){

	switch (scene_mover){
	case TITLE:		title.update();
		break;
	case SELECT:	select.update();
		break;
	case GAME:		game.update();
		break;
	case RESULT:
		break;
	default:
		break;
	}

}

void cScene::shift(){

	switch (scene_mover){
	case TITLE:		scene_mover = title.shift(scene_mover);
		break;
	case SELECT:	scene_mover = select.shift(scene_mover);
		break;
	case GAME:		game.shift();
		break;
	case RESULT:
		break;
	default:
		break;
	}

}

void cScene::draw(){

	switch (scene_mover){
	case TITLE:		title.draw();
		break;
	case SELECT:	select.draw();
		break;
	case GAME:		game.draw();
		break;
	case RESULT:
		break;
	}

}

void cScene::keyDown(KeyEvent event){

	switch (scene_mover){
	case TITLE:		title.keyDown(event);
		break;
	case SELECT:	select.keyDown(event);
		break;
	case GAME:		game.keyDown(event);
		break;
	case RESULT:
		break;
	}

}

void cScene::keyUp(KeyEvent event){

	switch (scene_mover){
	case TITLE:		title.keyUp(event);
		break;
	case SELECT:	select.keyUp(event);
		break;
	case GAME:		game.keyUp(event);
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

