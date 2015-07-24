
#include "common.h"

#include "SceneManager.h"


class SixMonthRevisionApp : public ci::app::AppNative {

private:

	SceneManagerSP scene = SceneManagerSP(new SceneManager);

public:

	void setup() override{
		setWindowSize(WIDTH, HEIGHT);
		scene->init();
	};

	void update() override{
		scene->update();
		scene->shift();
	};

	void draw() override{

		gl::clear(Color(0.1f, 0.1f, 0.1f));
		gl::enableAlphaBlending();

		gl::pushModelView();
		gl::translate(getWindowCenter());

		scene->draw();

		gl::popModelView();

	};

	void mouseDown(MouseEvent event) override{
		scene->mouseDown(event);
	};

	void mouseUp(MouseEvent event) override{
		scene->mouseUp(event);
	};

	void mouseMove(MouseEvent event) override{
		scene->mouseMove(event);
	};

};

CINDER_APP_NATIVE(SixMonthRevisionApp, RendererGl)
