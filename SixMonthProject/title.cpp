
#include "title.h"


cTitle::cTitle(){

	logo_fadein_speed = 5.0f;
	arrow_fadein_speed = 7.5f;
	stage_logo_speed = 3.0f;

	is_ready_title_logo = false;
	is_in_arrow_pic = false;

}

void cTitle::init(){

	logo_pic = { loadImage(loadAsset("title/logo.png")),
	{ -WIDTH - 300, -HEIGHT / 2 + 100 } };

	stage_select_pic = { loadImage(loadAsset("title/stage_select.png")),
	{ -0, 0 } };

	arrow_pic = { loadImage(loadAsset("title/arrow.png")),
	{ WIDTH / 2 + 100, -HEIGHT / 2 + 120 } };

	arrow.init();

}

void cTitle::update(){

	//�^�C�g�����S�̏�������������
	if (!is_ready_title_logo){

		//�ȈՃA�j���[�V�������I����ɏ�������

		//�^�C�g�����S�̃A�j��
		logo_pic.pos.x += logo_fadein_speed;
		if (logo_pic.pos.x > 0)
			logo_fadein_speed -= 1.0f;

		if (logo_fadein_speed < 0)
			if (logo_pic.pos.x < -logo_pic.pic.getWidth() / 2){
				logo_fadein_speed = 0;
				is_in_arrow_pic = true;
			}

		//��̃A�j��
		if (is_in_arrow_pic){
			arrow_pic.pos.x -= arrow_fadein_speed;
			if (arrow_pic.pos.x < -arrow_pic.pic.getSize().x / 2 + 5)
				is_ready_title_logo = true;
		}
	}
	//�^�C�g�����S�̏���������
	else{
		//�X�e�[�W�I�����S�̓���J�n
		stage_select_pic.pos.x += stage_logo_speed;

		if (stage_select_pic.pos.x - stage_select_pic.pic.getSize().x / 2 < -WIDTH / 2 ||
			stage_select_pic.pos.x + stage_select_pic.pic.getSize().x / 2 > WIDTH / 2)
			stage_logo_speed *= -1;

	}

	arrow.update();

}

int cTitle::shift(int mover){

	if (arrow.get_is_shooting()){
		if (hit.arrow_is_hit_cube(
			arrow.getPos(), arrow.getSize(),
			Vec3f(stage_select_pic.pos, stage_logo_pos_z),
			Vec3f(stage_select_pic.pic.getSize(), stage_logo_size_z))){
			
			mover = SELECT;
		
		}
	}

	return mover;
}

void cTitle::draw(){

	//��ԕ\��
	gl::drawStrokedCube(room.pos, room.size);

	//���S
	gl::draw(logo_pic.pic, logo_pic.pos);
	//��
	gl::draw(arrow_pic.pic, arrow_pic.pos);

	if (is_ready_title_logo){

		//�X�e�[�W�I�����S�̓����蔻������p�̔�
		gl::color(0.5f, 0.5f, 0.5f);
		gl::drawCube(
			Vec3f(stage_select_pic.pos, stage_logo_pos_z),
			Vec3f(stage_select_pic.pic.getSize(), stage_logo_size_z)
			);
		gl::color(1, 1, 1);

		//�X�e�[�W�I�����S
		gl::pushModelView();
		gl::translate(
			-stage_select_pic.pic.getSize().x / 2.0f,
			-stage_select_pic.pic.getSize().y / 2.0f,
			stage_logo_pos_z
			);

		gl::draw(stage_select_pic.pic, stage_select_pic.pos);

		gl::popModelView();

	}

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