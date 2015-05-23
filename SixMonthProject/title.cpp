
#include "title.h"


void cTitle::setup(){}

void cTitle::update(){

	arrow.update();

}

void cTitle::shift(){}

void cTitle::draw(){
	
	//‹óŠÔ•\¦
	gl::drawStrokedCube(room.pos,room.size);
	//‹|–î
	arrow.draw();

}

void cTitle::keyDown(KeyEvent event){

	//‹|‚Ì‘€ì
	arrow.keyDown(event);

}

void cTitle::keyUp(KeyEvent event){

	//‹|‚Ì‘€ì
	arrow.keyUp(event);

}

/*
void cTitle::mouseDown(KeyEvent event){}

void cTitle::mouseUp(KeyEvent event){}

void cTitle::mouseMove(KeyEvent event){}
*/