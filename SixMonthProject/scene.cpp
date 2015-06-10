
#include "scene.h"

cEnemyBreaker cScene::enemy_breaker;
cEnemyBreaker2 cScene::enemy_breaker2;

cScene::cScene(){

	scene_mover = TITLE;

}

void cScene::init(){

	title.init();
	select.init();

	enemy_breaker.init();
	enemy_breaker_result.init();
	enemy_breaker2.init();
	enemy_breaker_result2.init();

}

void cScene::update(){

	//êØ
	room.starUpdata();

	switch (scene_mover){
	case TITLE:
		title.update();
		break;
	case SELECT:
		enemy_breaker.reStartInit();
		enemy_breaker2.reStartInit();
		select.update();
		break;
	case ENEMY_BREAKER:
		enemy_breaker_result.reStartInit();
		enemy_breaker.update();
	case ENEMY_BREAKER2:
		enemy_breaker_result2.reStartInit();
		enemy_breaker2.update();
		break;
	case ENEMY_BREAKER_RESULT:
		select.reStartInit();
		enemy_breaker_result.update();
		break;
	case ENEMY_BREAKER_RESULT2:
		select.reStartInit();
		enemy_breaker_result2.update();
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
	case ENEMY_BREAKER2:		scene_mover = enemy_breaker2.shift(scene_mover);
		break;
	case ENEMY_BREAKER_RESULT:	scene_mover = enemy_breaker_result.shift(scene_mover);
		break;
	case ENEMY_BREAKER_RESULT2:	scene_mover = enemy_breaker_result2.shift(scene_mover);
		break;
	}

}

void cScene::draw(){

	//êØ
	room.starDraw();

	switch (scene_mover){
	case TITLE:					title.draw();
		break;
	case SELECT:				select.draw();
		break;
	case ENEMY_BREAKER:			enemy_breaker.draw();
		break;
	case ENEMY_BREAKER2:		enemy_breaker2.draw();
		break;
	case ENEMY_BREAKER_RESULT:	enemy_breaker_result.draw();
		break;
	case ENEMY_BREAKER_RESULT2:	enemy_breaker_result2.draw();
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
	case ENEMY_BREAKER2:		enemy_breaker2.keyDown(event);
		break;
	case ENEMY_BREAKER_RESULT:	enemy_breaker_result.keyDown(event);
		break;
	case ENEMY_BREAKER_RESULT2:	enemy_breaker_result2.keyDown(event);
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
	case ENEMY_BREAKER2:		enemy_breaker2.keyUp(event);
		break;
	case ENEMY_BREAKER_RESULT:	enemy_breaker_result.keyUp(event);
		break;
	case ENEMY_BREAKER_RESULT2:	enemy_breaker_result2.keyUp(event);
		break;
	}

}
