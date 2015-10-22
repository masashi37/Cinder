
#include "Fade.h"


class DowaProject_fadeIn_fadeOutApp :
	public AppNative {

private:

	Fade fade;

	bool mIsDownAKey = false;
	bool mIsDownSKey = false;

public:

	void setup() {
		setWindowSize(700, 700);
	}

	void keyDown(KeyEvent event) {
		if (event.getCode() == KeyEvent::KEY_a) {
			mIsDownAKey = true;
			mIsDownSKey = false;
		}
		if (event.getCode() == KeyEvent::KEY_s) {
			mIsDownAKey = false;
			mIsDownSKey = true;
		}
	}

	void update() {
		if (mIsDownAKey)
			fade.fadeOut(VEIL_FADE);
		if (mIsDownSKey)
			fade.fadeIn();
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

		fade.draw();
	}

};
CINDER_APP_NATIVE(DowaProject_fadeIn_fadeOutApp, RendererGl)
