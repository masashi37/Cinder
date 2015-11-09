
#include "FadeOut.h"
#include "FadeIn.h"

class FadeProjectApp : public AppNative {

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
			//fadeOut.fullScreenFade(2);
			//fadeOut.circleScalingFade(2);
			//fadeOut.veilDownFade(2);
			//fadeOut.fromLeftCurtainFade(2);
			//fadeOut.fromRightCurtainFade(2);
			//fadeOut.centerCurtainFade(2);
			fadeOut.pinHoleFade(2, 100, 50);
		}
		if (isActiveIn) {
			//fadeIn.fullScreenFade(2);
			//fadeIn.circleScalingFade(2);
			//fadeIn.veilDownFade(2);
			//fadeIn.fromLeftCurtainFade(2);
			//fadeIn.fromRightCurtainFade(2);
			//fadeIn.centerCurtainFade(2);
			fadeIn.pinHoleFade(2, 100, 50);
		}

		if (fadeOut.getEnd())
			isActiveOut = false;
		if (fadeIn.getEnd())
			isActiveIn = false;
	}

	void draw() {
		gl::clear(Color(0.5f, 0.5f, 0.5f));

		//分かりやすくするために箱を3つ描画
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
CINDER_APP_NATIVE(FadeProjectApp, RendererGl)
