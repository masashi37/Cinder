
#include "select.h"


void cSelect::setup(){}

void cSelect::update(){

	arrow.update();

}

void cSelect::shift(){}

void cSelect::draw(){

	//��ԕ\��
	gl::drawStrokedCube(room.pos, room.size);

	//�|��
	arrow.draw();

}

void cSelect::keyDown(KeyEvent event){

	//�|�̑���
	arrow.keyDown(event);

}

void cSelect::keyUp(KeyEvent event){

	//�|�̑���
	arrow.keyUp(event);

}

/*
void cSelect::mouseDown(KeyEvent event){}

void cSelect::mouseUp(KeyEvent event){}

void cSelect::mouseMove(KeyEvent event){}
*/