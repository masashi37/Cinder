
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
	void keyDown(KeyEvent);
	void keyUp(KeyEvent);
	void draw();
};


void Main::setup(){

	setWindowSize(WIDTH, HEIGHT);
	/*setWindowPos(Vec2i::zero());
	Vec2i offset = {
		static_cast<int>(getWindowCenter().x) - WIDTH / 2,
		static_cast<int>(getWindowCenter().y) - HEIGHT / 2
	};
	setWindowPos(getWindowCenter());*/

	scene.setup();
}

void Main::update(){
	scene.update();
	scene.shift();
}

void Main::keyDown(KeyEvent event){
	scene.keyDown(event);
}

void Main::keyUp(KeyEvent event){
	scene.keyUp(event);
}

void Main::draw(){
	gl::clear(Color(0, 0, 0));

	scene.draw();
}

CINDER_APP_NATIVE(Main, RendererGl)
