
//
// �^�C�g�� �F Arrow
//

#include "common.h"
#include "scene.h"


class Main : public AppNative {

private:

	cScene scene;

public:

	void setup(){

		//�E�B���h�E�T�C�Y
		setWindowSize(WIDTH, HEIGHT);

		scene.setup();

	};

	void update(){
		scene.update();
		scene.shift();
	};

	void draw(){
		//�w�i�F
		gl::clear(Color(0, 0, 0));

		//���_�ۑ��ƕύX
		gl::pushModelView();
		gl::translate(getWindowSize() / 2);

		scene.draw();

		//���_��A
		gl::popModelView();
	};

	void keyDown(KeyEvent event){
	scene.keyDown(event);
	};

	void keyUp(KeyEvent event){
	scene.keyUp(event);
	};
	
};

CINDER_APP_NATIVE(Main, RendererGl)
