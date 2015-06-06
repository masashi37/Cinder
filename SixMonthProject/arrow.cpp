
#include "arrow.h"


cArrow::cArrow(){

	pos = { -(size.x) / 2.0f, -(size.y) / 2.0f, 0.0f };
	aim_light_begin = { Vec3f(pos.xy(), pos.z - size.z / 2) };
	aim_light_end = { Vec3f(pos.xy(), -room_depth) };

	arrow_speed = 0;
	plus_speed = 0.5f;
	gravity = 0.0f;
	gravity_puls = 0.1f;

	key_direction = 0;

	is_push_space = false;
	is_push_left = false;
	is_push_right = false;
	is_push_up = false;
	is_push_down = false;

	is_shoot_arrow = false;

}

void cArrow::init(){
	//�摜
	arrow_picture = loadImage(loadAsset("arrow/arrow.png"));

	//SE
	//--------------------------------------------------

	// �o�̓f�o�C�X���Q�b�g
	auto ctx = audio::Context::master();

	// �I�[�f�B�I�f�[�^��ǂݍ���ŏ�����
	audio::SourceFileRef sourceFile = audio::load(loadAsset("se/arrow_shoot.wav"));
	audio::BufferRef buffer = sourceFile->loadBuffer();
	shoot_se = ctx->makeNode(new audio::BufferPlayerNode(buffer));

	// �ǂݍ��񂾃I�[�f�B�I���o�̓f�o�C�X�Ɋ֘A�t���Ă���
	shoot_se >> ctx->getOutput();

	// �o�̓f�o�C�X��L���ɂ���
	ctx->enable();
}

void cArrow::update(){

	//�|����̓`���[�W
	if (!is_shoot_arrow){

		if (is_push_space){
			//�`���[�W���A�|�̑��x��ύX
			arrow_speed += plus_speed;
			if (arrow_speed > SPEED_MAX || arrow_speed < 0)
				plus_speed *= -1;
		}
		else{ back_arrow_pos = Vec2f(pos.x, pos.y); }
	}
	//�|�̔���
	if (is_shoot_arrow){

		//�`���[�W��A�|�ɏd�͂������Ĕ���
		gravity += gravity_puls;
		pos.y += gravity;
		pos.z -= arrow_speed;

		//�ǂ̓����蔻��(���ƒ�)
		if (pos.z < -room_depth || pos.y > HEIGHT / 2){
			//����������A�|�֌W�̐��l��������
			pos = { back_arrow_pos.x, back_arrow_pos.y, 0 };
			gravity = 0;
			arrow_speed = 0;

			aim_light_begin.x =
				aim_light_end.x = pos.x;
			aim_light_begin.y =
				aim_light_end.y = pos.y;

			is_shoot_arrow = false;
		}
	}

	//---------------------------------------------------------------------
	//�|�̔��ˈʒu�ύX
	if (!is_shoot_arrow){
#pragma region move
		//�ړ�
		if (is_push_left){
			pos.x -= move_speed;
			aim_light_begin.x -= move_speed;
			aim_light_end.x -= move_speed;
		}
		if (is_push_right){
			pos.x += move_speed;
			aim_light_begin.x += move_speed;
			aim_light_end.x += move_speed;
		}
		if (is_push_up){
			pos.y -= move_speed;
			aim_light_begin.y -= move_speed;
			aim_light_end.y -= move_speed;
		}
		if (is_push_down){
			pos.y += move_speed;
			aim_light_begin.y += move_speed;
			aim_light_end.y += move_speed;
		}
#pragma endregion

#pragma region move_limit
		//�ړ�����
		if (pos.x < -WIDTH / 2){
			pos.x = -WIDTH / 2;
			aim_light_begin.x = pos.x;
			aim_light_end.x = pos.x;
		}
		if (pos.x > WIDTH / 2){
			pos.x = WIDTH / 2;
			aim_light_begin.x = pos.x;
			aim_light_end.x = pos.x;
		}
		if (pos.y < -HEIGHT / 2){
			pos.y = -HEIGHT / 2;
			aim_light_begin.y = pos.y;
			aim_light_end.y = pos.y;
		}
		if (pos.y > HEIGHT / 2){
			pos.y = HEIGHT / 2;
			aim_light_begin.y = pos.y;
			aim_light_end.y = pos.y;
		}
#pragma endregion		
	}

}

void cArrow::draw(){

	//�\��t��
	gl::enable(GL_TEXTURE_2D);
	arrow_picture.bind();

	//�|��{��
	gl::drawCube(pos, size);
	gl::drawCube(pos, size1);

	//�\��t������
	arrow_picture.unbind();
	gl::disable(GL_TEXTURE_2D);

	//������₷��
	gl::drawStrokedCircle(pos.xy(), 20);

	//��̏Ə�
	if (!is_shoot_arrow)
		gl::drawLine(aim_light_begin, aim_light_end);

	//�`���[�W��
	if (is_push_space){
		//�`���[�W�Q�[�W
		gl::drawCube(
			pos + Vec3f((pos.x >= 0) ? -(float)GAGE_SPACE : (float)GAGE_SPACE, 0, 0),
			Vec3f(10, arrow_speed * 2, 10));
		//�`���[�W�Q�[�W�̘g
		gl::drawStrokedCube(
			pos + Vec3f((pos.x >= 0) ? -(float)GAGE_SPACE : (float)GAGE_SPACE, 0, 0),
			Vec3f(10, SPEED_MAX * 2, 10));
	}
}

Vec3f cArrow::getPos(){
	return pos;
}

Vec3f cArrow::getSize(){
	return size;
}

bool cArrow::get_is_shooting(){
	return is_shoot_arrow;
}

void cArrow::keyDown(KeyEvent event){

	//�|�̈ړ�
	if (event.getCode() == KeyEvent::KEY_LEFT)
		is_push_left = true;
	if (event.getCode() == KeyEvent::KEY_RIGHT)
		is_push_right = true;
	if (event.getCode() == KeyEvent::KEY_UP)
		is_push_up = true;
	if (event.getCode() == KeyEvent::KEY_DOWN)
		is_push_down = true;

	//�p���[�`���[�W
	if (event.getCode() == KeyEvent::KEY_SPACE){
		is_push_space = true;
	}

}

void cArrow::keyUp(KeyEvent event){

	//�|�̈ړ��I��
	if (event.getCode() == KeyEvent::KEY_LEFT)
		is_push_left = false;
	if (event.getCode() == KeyEvent::KEY_RIGHT)
		is_push_right = false;
	if (event.getCode() == KeyEvent::KEY_UP)
		is_push_up = false;
	if (event.getCode() == KeyEvent::KEY_DOWN)
		is_push_down = false;

	//�p���[�`���[�W�I��
	if (event.getCode() == KeyEvent::KEY_SPACE){
		//SE
		shoot_se->start();

		is_push_space = false;
		is_shoot_arrow = true;
	}

}