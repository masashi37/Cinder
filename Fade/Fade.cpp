
#include "Fade.h"


Fade::Fade() {
	time = 0;
	is_end_ready_fadeout_ = false;
	is_ready_fadein_ = false;
}


void Fade::fadeOut(const int fade_pattern) {

	switch (fade_pattern) {
#pragma region case CUBE_FADE:
	case CUBE_FADE:

		if (!is_end_ready_fadeout_) {
			//���ǉ��Ə�����

			fade_pattern_ = fade_pattern;

			for (int i = 0; i < 1; ++i) {
				hide_cube_.emplace_back();
			}

			for (unsigned int i = 0; i < hide_cube_.size(); ++i) {
				hide_cube_[i].pos =
					Vec3f::zero();

				hide_cube_[i].size =
					Vec3f(
						(float)getWindowSize().x,
						(float)getWindowSize().y,
						0.1f);

				hide_cube_[i].color =
					ColorA(0, 0, 0, 0);
			}

			//�ǉ������Ə���������񂾂����
			is_end_ready_fadeout_ = true;
		}


		for (unsigned int i = 0; i < hide_cube_.size(); ++i) {
			//���l���Z�v�Z
			hide_cube_[i].color.a +=
				(hide_cube_[i].color.a <= 1.0f) ? speed : 0.0f;

			//�����x�ǉ��E�\���ʒu�𒆐S�Ɉړ��E�F��ύX
			gl::pushModelView();
			gl::translate(getWindowCenter());

			gl::enableAlphaBlending();

			gl::color(hide_cube_[i].color);

			//�`��
			gl::drawCube(hide_cube_[i].pos, hide_cube_[i].size);

			//�S�Č��ɖ߂�
			gl::color(1.0f, 1.0f, 1.0f, 1.0f);

			gl::disableAlphaBlending();

			gl::popModelView();

			//���l���ő�l(1.0f)�ɂȂ�����
			//fadeIn���g�p�\�ɕύX
			if (hide_cube_[i].color.a >= 1.0f) {
				is_ready_fadein_ = true;
			}

		}

		break;
#pragma endregion
	}

}

void Fade::fadeIn() {

	if (is_ready_fadein_) {

		switch (fade_pattern_) {
#pragma region case CUBE_FADE:
		case CUBE_FADE:

			for (unsigned int i = 0; i < hide_cube_.size(); ++i) {

				//���l���Z
				hide_cube_[i].color.a -= speed;

				console() << hide_cube_[i].color.a << std::endl;

				if (hide_cube_[i].color.a <= 0.0f) {
					hide_cube_.clear();
					is_end_ready_fadeout_ = false;
					is_ready_fadein_ = false;
				}

			}

			break;
#pragma endregion
		}

	}

}

bool Fade::getIsStartFadein() {
	return is_ready_fadein_;
}
