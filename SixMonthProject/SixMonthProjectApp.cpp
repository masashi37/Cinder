
#include "common.h"

#include "scene.h"


class Main : public AppNative {

public:
	void setup();
	void update();
	void draw();
};

void Main::setup(){
	setWindowSize(WIDTH, HEIGHT);
}

void Main::update(){}

void Main::draw(){
	gl::clear(Color(0, 0, 0));
}

CINDER_APP_NATIVE(Main, RendererGl)
