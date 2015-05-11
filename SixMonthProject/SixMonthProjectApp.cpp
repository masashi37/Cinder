
//
// タイトル ： Arrow
//


#include "common.h"

#include "scene.h"


class Main : public AppNative {

private:

	cScene scene;

public:
	void setup();
	void update();
	void draw();
};

void Main::setup(){
	setWindowSize(WIDTH, HEIGHT);

	scene.setup();
}

void Main::update(){
	scene.update();
	scene.shift();
}

void Main::draw(){
	gl::clear(Color(0, 0, 0));

	scene.draw();
}

CINDER_APP_NATIVE(Main, RendererGl)
