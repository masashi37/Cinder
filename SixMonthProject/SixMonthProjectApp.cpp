
//
// タイトル ： Arrow
//

#include "common.h"
#include "scene.h"


class Main : public AppNative {

private:

	audio::BufferPlayerNodeRef bgm;
	bool is_start_bgm = false;

	cScene scene;

public:

	void setup(){

		//シーン毎の初期化
		scene.init();

		//ウィンドウサイズ
		setWindowSize(WIDTH, HEIGHT);

		//ランダムのパターン化を解除
		Rand::randomize();

		//サウンド
		//------------------------------

		// 出力デバイスをゲット
		auto ctx = audio::Context::master();

		//BGMカタログ
		/*
		("bgm/city_walk.wav")
		("bgm/film_clash.wav")
		("bgm/fire_dance.wav")
		("bgm/zombie_rock.wav")
		*/

		// オーディオデータを読み込んで初期化
		audio::SourceFileRef sourceFile = audio::load(loadAsset("bgm/film_clash.wav"));
		audio::BufferRef buffer = sourceFile->loadBuffer();
		bgm = ctx->makeNode(new audio::BufferPlayerNode(buffer));

		// 読み込んだオーディオを出力デバイスに関連付けておく
		bgm >> ctx->getOutput();

		// 出力デバイスを有効にする
		ctx->enable();

	};

	void update(){

		scene.update();
		scene.shift();

		if (!is_start_bgm){
			bgm->start();
			is_start_bgm = true;
		}
		if (bgm->isEof())
			is_start_bgm = false;

	};

	void draw(){
		//背景色
		gl::clear(Color(0, 0, 0));
		//画像の透明化
		gl::enableAlphaBlending();

		//原点保存と変更
		gl::pushModelView();
		gl::translate(getWindowCenter());

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
