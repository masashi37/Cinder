
#pragma once

#include "common.h"
#include "cinder/Rand.h"
#include "arrow.h"


class cTitle{

private:

	cArrow arrow;

	gl::Texture logo_pic;			//�^�C�g�����S 128*32
	gl::Texture stage_select_pic;	//�X�e�[�W�I�����S 128*64

	struct TitleText{
		Vec2f pos;
		Vec2f size;
	};
	TitleText logo;				//�^�C�g�����S
	TitleText stage_select;		//�X�e�[�W�I���̃��S

	struct TitleObject{
		Vec3f pos;
		Vec3f size;
	};
	TitleObject arrow_tower;	//�|������
	std::vector<TitleObject>target;			//���K�p�I

	float show_z = 2;			//���̂Ɍ����邚

public:

	void setup();
	void update();
	void mouseDown(MouseEvent);
	void mouseUp(MouseEvent);
	void mouseMove(MouseEvent);
	void shift();
	void draw();

};