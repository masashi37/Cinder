
#include "title.h"


void cTitle::setup(){}

void cTitle::update(){

	arrow.update();

}

void cTitle::shift(){}

void cTitle::draw(){
	
	//��ԕ\��
	gl::drawStrokedCube(room.pos,room.size);
	//�|��
	arrow.draw();

}

void cTitle::keyDown(KeyEvent event){

	//�|�̑���
	arrow.keyDown(event);

}

void cTitle::keyUp(KeyEvent event){}

/*
void cTitle::mouseDown(KeyEvent event){}

void cTitle::mouseUp(KeyEvent event){}

void cTitle::mouseMove(KeyEvent event){}
*/