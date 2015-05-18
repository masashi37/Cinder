
#include "arrowMove.h"


float cArrowMove::direction(MouseEvent event){

	Vec3f vec1 = Vec3f(0, -1.0f, 0);		//���̊
	Vec3f vec2 =
		Vec3f(event.getPos(), 0) - Vec3f(getWindowCenter() + arrow_status.pos.xy(), 0);		//�}�E�X�Ƌ|�̃x�N�g��

	//�m�[�}���C�Y
	vec2.normalize();

	//���σx�N�g��
	float d = vec1.dot(vec2);

	// ���ς̃A�[�N�R�T�C���Ŋp�x
	float radian = acosf(d);

	return radian;

}

void cArrowMove::shootPrepare(){

	if (is_press_left_button){

		arrow_status.speed += speed_plus;
		if (arrow_status.speed >= 10
			|| arrow_status.speed == 0)
			speed_plus = -speed_plus;

	}

}

void cArrowMove::shootArrow(){

	if (is_shooting_arrow)
		arrow_status.pos.x += arrow_status.speed;
	else arrow_status.speed = 0;

}