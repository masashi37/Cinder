
#include "SceneManager.h"


void SceneManager::init(){

	title->init();

}

void SceneManager::update(){

	title->update();

}

void SceneManager::shift(){

}

void SceneManager::draw(){

	title->draw();

}


void SceneManager::mouseDown(MouseEvent event){

	title->mouseDown(event);

}

void SceneManager::mouseMove(MouseEvent event){

	title->mouseMove(event);

}

void SceneManager::mouseUp(MouseEvent event){

	title->mouseUp(event);

}
