
#pragma once

#include "Fade.h"


class FadeOut :public Fade {

private:

public:

	FadeOut();

	//�I��������ǂ����̔����Ԃ�
	bool getEnd();

	//�t���X�N���[���œW�J�����FadeOut
	//�i�I���܂ł̎��ԁi�b�j�j
	void fullScreenFade(int);
	//��ʒ��S�̉~�̊g�k�ƃ��l�ω���FadeOut
	//�i�I���܂ł̎��ԁi�b�j�j
	void circleScalingFade(int);
	//���ꖋ��FadeOut
	//(�I���܂ł̕b��(int))
	void veilDownFade(int);
	//�J�[�e����(�i�s������)FadeOut
	//(�I���܂ł̕b��(int))
	void fromLeftCurtainFade(int);
	//�J�[�e����(�i�s������)FadeOut
	//(�I���܂ł̕b��(int))
	void fromRightCurtainFade(int);
	//�����J�[�e����FadeOut
	//(�I���܂ł̕b��(int))
	void centerCurtainFade(int);
	//�s���z�[����FadeOut
	//(�I���܂ł̕b��(int))
	void pinHallFade(int);

	void draw();

};