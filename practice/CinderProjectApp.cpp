
//
//	６月審査会（タイトル未定）
//

#include "common.h"
#include "enemy.h"


class CinderProjectApp : public AppNative {

	cEnemy enemy;

public:

	void setup();
	void mouseDown(MouseEvent event);
	void update();
	void draw();
};


void CinderProjectApp::setup(){

	//ウィンドウ	
	setWindowSize(WIDTH, HEIGHT);

}

void CinderProjectApp::mouseDown(MouseEvent event){
	if (event.isLeftDown())
	enemy.create();

}

void CinderProjectApp::update(){}

void CinderProjectApp::draw(){

	gl::clear(Color(0, 0, 0));

	gl::pushModelView();
	gl::translate(WIDTH / 2, HEIGHT / 2);

	enemy.draw();

	gl::popModelView();

}

CINDER_APP_NATIVE(CinderProjectApp, RendererGl)
