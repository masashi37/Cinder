
#include "title.h"


void cTitle::setup(){

	logo_pic = { loadImage(loadAsset("title/logo.png")),
	{ -WIDTH - 300, -HEIGHT / 2 + 100 } };
	stage_select_pic = { loadImage(loadAsset("title/stage_select.png")),
	{ -50, 50 } };

	logo_fadein_speed = 5.0f;
	stage_logo_speed = 3.0f;

	is_ready_title_logo = false;

}

void cTitle::update(){

	//�^�C�g�����S�̏�������������
	if (!is_ready_title_logo){
		//���������邽�߂̑���

		//�ȈՃA�j���[�V����
		logo_pic.pos.x += logo_fadein_speed;
		if (logo_pic.pos.x > 0)
			logo_fadein_speed -= 1.0f;

		if (logo_fadein_speed < 0)
			if (logo_pic.pos.x < -logo_pic.pic.getWidth() / 2)
				is_ready_title_logo = true;
	}
	//�^�C�g�����S�̏���������
	else{
		//�X�e�[�W�I�����S�̓���J�n
		stage_select_pic.pos.x += stage_logo_speed;

		if (stage_select_pic.pos.x < -WIDTH / 4 ||
			stage_select_pic.pos.x + stage_select_pic.pic.getSize().x > WIDTH / 4)
			stage_logo_speed *= -1;

	}

	arrow.update();

}

void cTitle::shift(){}

void cTitle::draw(){

	//��ԕ\��
	gl::drawStrokedCube(room.pos, room.size);

	//���S
	gl::draw(logo_pic.pic, logo_pic.pos);
	if (is_ready_title_logo)
		gl::draw(stage_select_pic.pic, stage_select_pic.pos);

	//�|��
	arrow.draw();

}

void cTitle::keyDown(KeyEvent event){

	//�|�̑���
	arrow.keyDown(event);

}

void cTitle::keyUp(KeyEvent event){

	//�|�̑���
	arrow.keyUp(event);

}

/*
void cTitle::mouseDown(KeyEvent event){}

void cTitle::mouseUp(KeyEvent event){}

void cTitle::mouseMove(KeyEvent event){}
*/