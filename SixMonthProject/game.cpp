
#include "game.h"


cGame::cGame(){

}

void cGame::init(){

	arrow.init();

}

void cGame::update(){

	arrow.update();

	//��������
	/*
		selection_number = select.get_select_number(selection_number);

		console() << selection_number << std::endl;
		*/
}

void cGame::shift(){}

void cGame::draw(){

	//��ԕ\��
	gl::drawStrokedCube(room.pos, room.size);

	//�|��
	arrow.draw();

}

void cGame::keyDown(KeyEvent event){

	//�|�̑���
	arrow.keyDown(event);

}

void cGame::keyUp(KeyEvent event){

	//�|�̑���
	arrow.keyUp(event);

}

/*
void cSelect::mouseDown(KeyEvent event){}

void cSelect::mouseUp(KeyEvent event){}

void cSelect::mouseMove(KeyEvent event){}
*/