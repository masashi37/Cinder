
#include "title.h"


void cTitle::setup(){

	//ƒ^ƒCƒgƒ‹ƒƒS‰Šú‰»
	logo_pic = { loadImage(loadAsset("title/logo.png")),
		Vec2f(-WIDTH - 300, -HEIGHT / 2 + 100) };
	stage_select_pic = { loadImage(loadAsset("title/stage_select.png")),
		Vec2f(-100, HEIGHT / 2 - 100) };

}

void cTitle::update(){

	if (!is_ready_title_logo){
		logo_pic.pos.x += logo_speed;
		if (logo_pic.pos.x > 0)
			logo_speed -= 1.0f;

		if (logo_speed < 0)
			if (logo_pic.pos.x < -logo_pic.pic.getWidth() / 2)
				is_ready_title_logo = true;
	}
	else{
		stage_select_pic.pos.x += Rand::randFloat(-1, 1);
		stage_select_pic.pos.y += Rand::randFloat(-1, 1);
	}

	arrow.update();

}

void cTitle::shift(){}

void cTitle::draw(){

	//‹óŠÔ•\Ž¦
	gl::drawStrokedCube(room.pos, room.size);

	//ƒƒS
	gl::draw(logo_pic.pic, logo_pic.pos);
	if (is_ready_title_logo)
		gl::draw(stage_select_pic.pic, stage_select_pic.pos);

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