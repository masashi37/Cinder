
#include "arrowMove.h"


float cArrowMove::direction(MouseEvent event, Vec2f& arrow_pos){

	mouse_pos = event.getPos();
	Vec2f vec1 = Vec2f(0, -1.0f);		//
	Vec2f vec2 = mouse_pos - arrow_pos;		//�}�E�X�Ƌ|�̃x�N�g��

	//�m�[�}���C�Y
	vec2.normalize();

	//���σx�N�g��
	float d = vec1.dot(vec2);

	// ���ς̃A�[�N�R�T�C���Ŋp�x
	float radian = acos(d);

	//console() << d << std::endl;

	return radian;


}

void cArrowMove::shoot(MouseEvent event){}