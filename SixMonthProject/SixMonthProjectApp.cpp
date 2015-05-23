
//
// タイトル ： Arrow
//

#include "common.h"
#include "scene.h"


class Main : public AppNative {

private:

	cScene scene;

public:

	void setup(){

		//ウィンドウサイズ
		setWindowSize(WIDTH, HEIGHT);

		scene.setup();

	};

	void update(){
		scene.update();
		scene.shift();
	};

	void draw(){
		//背景色
		gl::clear(Color(0, 0, 0));

		//原点保存と変更
		gl::pushModelView();
		gl::translate(getWindowSize() / 2);

		scene.draw();

		//原点回帰
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
