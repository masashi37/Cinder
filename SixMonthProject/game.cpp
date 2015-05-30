
#include "game.h"


cGame::cGame(){

}

void cGame::init(){

	arrow.init();

}

void cGame::update(){

	arrow.update();

	//–¢Š®¬•”
	/*
		selection_number = select.get_select_number(selection_number);

		console() << selection_number << std::endl;
		*/
}

void cGame::shift(){}

void cGame::draw(){

	//‹óŠÔ•\¦
	gl::drawStrokedCube(room.pos, room.size);

	//‹|–î
	arrow.draw();

}

void cGame::keyDown(KeyEvent event){

	//‹|‚Ì‘€ì
	arrow.keyDown(event);

}

void cGame::keyUp(KeyEvent event){

	//‹|‚Ì‘€ì
	arrow.keyUp(event);

}

/*
void cSelect::mouseDown(KeyEvent event){}

void cSelect::mouseUp(KeyEvent event){}

void cSelect::mouseMove(KeyEvent event){}
*/