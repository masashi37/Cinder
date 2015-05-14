
#pragma once

#include "title.h"


class cScene{

private:

	cTitle title;

	//�V�[���̖��O(No.)
	enum SceneName{
		TITLE,
		SELECT,
		GAME,
		RESULT,
	};

	int scene_mover;	//�V�[����؂�ւ���X�C�b�`

public:

	cScene();

	void setup();
	void update();
	void mouseDown(MouseEvent);
	void mouseUp(MouseEvent);
	void mouseMove(MouseEvent);
	void shift();
	void draw();
};