
#include "Fade.h"


class DowaProject_fadeIn_fadeOutApp :
	public AppNative {

private:

	Fade fade;

	bool is_start_fadeout_;
	bool is_start_fadein_;

public:

	void setup() {
		is_start_fadeout_ = false;
		is_start_fadein_ = false;

		setWindowSize(700, 700);
	}

	void keyDown(KeyEvent event) {

		if (event.getCode() == KeyEvent::KEY_a) {
			is_start_fadeout_ = true;
		}
		if (event.getCode() == KeyEvent::KEY_s) {
			is_start_fadein_ = true;
		}

	}

	void update() {
		if (is_start_fadein_) {
			fade.fadeIn();
		}
	}

	void draw() {
		gl::clear(Color(0.5f, 0.5f, 0.5f));

		//•ª‚©‚è‚â‚·‚­‚·‚é‚½‚ß‚É” ‚ð3‚Â•`‰æ
		for (int i = -1; i < 2; ++i) {
			gl::drawCube(
				Vec3f(getWindowSize().x / 2.0f + (100.0f * i),
					getWindowSize().y / 2.0f + (100.0f * i),
					0.0f + (50.0f * i)),
				Vec3f(70, 70, 70));
		}

		if (is_start_fadeout_) {
			fade.fadeOut(CUBE_FADE);
		}
	}

};
CINDER_APP_NATIVE(DowaProject_fadeIn_fadeOutApp, RendererGl)
