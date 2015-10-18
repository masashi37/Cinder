
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
			//個数追加と初期化

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

			//追加処理と初期化を一回だけやる
			is_end_ready_fadeout_ = true;
		}


		for (unsigned int i = 0; i < hide_cube_.size(); ++i) {
			//α値加算計算
			hide_cube_[i].color.a +=
				(hide_cube_[i].color.a <= 1.0f) ? speed : 0.0f;

			//透明度追加・表示位置を中心に移動・色を変更
			gl::pushModelView();
			gl::translate(getWindowCenter());

			gl::enableAlphaBlending();

			gl::color(hide_cube_[i].color);

			//描画
			gl::drawCube(hide_cube_[i].pos, hide_cube_[i].size);

			//全て元に戻す
			gl::color(1.0f, 1.0f, 1.0f, 1.0f);

			gl::disableAlphaBlending();

			gl::popModelView();

			//α値が最大値(1.0f)になったら
			//fadeInを使用可能に変更
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

				//α値加算
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
