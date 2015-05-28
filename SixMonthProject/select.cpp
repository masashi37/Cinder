
#include "select.h"


void cSelect::setup(){}

void cSelect::update(){

	arrow.update();

}

void cSelect::shift(){}

void cSelect::draw(){

	//‹óŠÔ•\¦
	gl::drawStrokedCube(room.pos, room.size);

	//‹|–î
	arrow.draw();

}

void cSelect::keyDown(KeyEvent event){

	//‹|‚Ì‘€ì
	arrow.keyDown(event);

}

void cSelect::keyUp(KeyEvent event){

	//‹|‚Ì‘€ì
	arrow.keyUp(event);

}

/*
void cSelect::mouseDown(KeyEvent event){}

void cSelect::mouseUp(KeyEvent event){}

void cSelect::mouseMove(KeyEvent event){}
*/