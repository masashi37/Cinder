
#pragma once

#include "common.h"


//��
class cArrowStatus{

public:

	struct ArrowStatus{
		Vec3f pos = { -WIDTH / 2 + 150, 100, 0 };
		Vec3f radian = { 0, 0, 0 };
		const Vec3f size = { 5, 100, 5 };
		float speed = 0;
	}arrow_status;

	Vec3f mouse_pos;						//�}�E�X�|�W�V���� �v��Ȃ�
	float speed_plus = 0.1f;				//��̑��x�̕ύX�l
	float degree;							//
	bool is_press_left_button = false;		//������Ă��邩�H
	bool is_shooting_arrow = false;			//�|�������Ă��邩�H

};