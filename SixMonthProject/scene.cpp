
#include "scene.h"

cEnemyBreaker cScene::enemy_breaker;

cScene::cScene(){

	scene_mover = SELECT;

}

void cScene::init(){

	title.init();
	select.init();

	enemy_breaker.init();
	enemy_breaker_result.init();

}

void cScene::update(){

	switch (scene_mover){
	case TITLE:
		title.update();
		break;
	case SELECT:
		enemy_breaker.reStartInit();
		select.update();
		break;
	case ENEMY_BREAKER:
		enemy_breaker_result.reStartInit();
		enemy_breaker.update();
		break;
	case ENEMY_BREAKER_RESULT:
		select.reStartInit();
		enemy_breaker_result.update();
		break;
	default:
		break;
	}

}

void cScene::shift(){

	switch (scene_mover){
	case TITLE:					scene_mover = title.shift(scene_mover);
		break;
	case SELECT:				scene_mover = select.shift(scene_mover);
		break;
	case ENEMY_BREAKER:			scene_mover = enemy_breaker.shift(scene_mover);
		break;
	case ENEMY_BREAKER_RESULT:	scene_mover = enemy_breaker_result.shift(scene_mover);
		break;
	}

}

void cScene::draw(){

	switch (scene_mover){
	case TITLE:					title.draw();
		break;
	case SELECT:				select.draw();
		break;
	case ENEMY_BREAKER:			enemy_breaker.draw();
		break;
	case ENEMY_BREAKER_RESULT:	enemy_breaker_result.draw();
		break;
	}

}

void cScene::keyDown(KeyEvent event){

	switch (scene_mover){
	case TITLE:					title.keyDown(event);
		break;
	case SELECT:				select.keyDown(event);
		break;
	case ENEMY_BREAKER:			enemy_breaker.keyDown(event);
		break;
	case ENEMY_BREAKER_RESULT:	enemy_breaker_result.keyDown(event);
		break;
	}

}

void cScene::keyUp(KeyEvent event){

	switch (scene_mover){
	case TITLE:					title.keyUp(event);
		break;
	case SELECT:				select.keyUp(event);
		break;
	case ENEMY_BREAKER:			enemy_breaker.keyUp(event);
		break;
	case ENEMY_BREAKER_RESULT:	enemy_breaker_result.keyUp(event);
		break;
	}

}
