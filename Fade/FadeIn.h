
#pragma once

#include "Fade.h"


class FadeIn :public Fade {

private:

public:

	FadeIn();

	//�I��������ǂ����̔����Ԃ�
	bool getEnd();

	//�t���X�N���[���œW�J�����FadeOut
	//�i�I���܂ł̎���(�b)�j
	void fullScreenFade(int);

	void draw();

};

