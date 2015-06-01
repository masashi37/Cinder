
#include "scene.h"


cScene::cScene(){

	scene_mover = ENEMY_BREAKER;

}

void cScene::init(){

	title.init();
	select.init();
	enemy_breaker.init();

}

void cScene::update(){

	switch (scene_mover){
	case TITLE:				title.update();
		break;
	case SELECT:			select.update();
		break;
	case ENEMY_BREAKER:		enemy_breaker.update();
		break;
	case RESULT:
		break;
	default:
		break;
	}

}

void cScene::shift(){

	switch (scene_mover){
	case TITLE:				scene_mover = title.shift(scene_mover);
		break;
	case SELECT:			scene_mover = select.shift(scene_mover);
		break;
	case ENEMY_BREAKER:		scene_mover = enemy_breaker.shift(scene_mover);
		break;
	case RESULT:
		break;
	default:
		break;
	}

}

void cScene::draw(){

	switch (scene_mover){
	case TITLE:				title.draw();
		break;
	case SELECT:			select.draw();
		break;
	case ENEMY_BREAKER:		enemy_breaker.draw();
		break;
	case RESULT:
		break;
	}

}

void cScene::keyDown(KeyEvent event){

	switch (scene_mover){
	case TITLE:				title.keyDown(event);
		break;
	case SELECT:			select.keyDown(event);
		break;
	case ENEMY_BREAKER:		enemy_breaker.keyDown(event);
		break;
	case RESULT:
		break;
	}

}

void cScene::keyUp(KeyEvent event){

	switch (scene_mover){
	case TITLE:				title.keyUp(event);
		break;
	case SELECT:			select.keyUp(event);
		break;
	case ENEMY_BREAKER:		enemy_breaker.keyUp(event);
		break;
	case RESULT:
		break;
	}

}

