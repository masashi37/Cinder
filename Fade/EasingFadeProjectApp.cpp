
#include "FadeOut.h"
#include "FadeIn.h"


class EasingFadeProjectApp : public AppNative {

	bool isActiveOut;
	bool isActiveIn;

	FadeOut fadeOut;
	FadeIn fadeIn;

public:

	void setup() {
		isActiveOut =
			isActiveIn = false;
	}

	void keyDown(KeyEvent event) {
		if (event.getCode() == KeyEvent::KEY_SPACE)
			isActiveOut = true;
		if (event.getCode() == KeyEvent::KEY_RETURN)
			isActiveIn = true;
	}

	void update() {
		if (isActiveOut) {
			fadeOut.setType(
				FullScreen, 2, Color::black(), true);
		}
		if (isActiveIn) {
			fadeIn.setType(FullScreen);
		}

		if (fadeOut.getIsEnd())
			isActiveOut = false;
		if (fadeIn.getIsEnd())
			isActiveIn = false;
	}

	void draw() {
		gl::clear(Color(0.5f, 0.5f, 0.5f));

		// draw a box to make it plain
		for (int i = -1; i < 2; ++i) {
			gl::drawCube(
				Vec3f(getWindowSize().x / 2.0f + (100.0f * i),
					getWindowSize().y / 2.0f + (100.0f * i),
					0.0f + (50.0f * i)),
				Vec3f(70, 70, 70));
		}

		fadeOut.draw();
		fadeIn.draw();
	}
};
CINDER_APP_NATIVE( EasingFadeProjectApp, RendererGl )
