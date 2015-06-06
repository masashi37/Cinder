
//
// �^�C�g�� �F Arrow
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

		//�V�[�����̏�����
		scene.init();

		//�E�B���h�E�T�C�Y
		setWindowSize(WIDTH, HEIGHT);

		//�����_���̃p�^�[����������
		Rand::randomize();

		//�T�E���h
		//------------------------------

		// �o�̓f�o�C�X���Q�b�g
		auto ctx = audio::Context::master();

		//BGM�J�^���O
		/*
		("bgm/city_walk.wav")
		("bgm/film_clash.wav")
		("bgm/fire_dance.wav")
		("bgm/zombie_rock.wav")
		*/

		// �I�[�f�B�I�f�[�^��ǂݍ���ŏ�����
		audio::SourceFileRef sourceFile = audio::load(loadAsset("bgm/film_clash.wav"));
		audio::BufferRef buffer = sourceFile->loadBuffer();
		bgm = ctx->makeNode(new audio::BufferPlayerNode(buffer));

		// �ǂݍ��񂾃I�[�f�B�I���o�̓f�o�C�X�Ɋ֘A�t���Ă���
		bgm >> ctx->getOutput();

		// �o�̓f�o�C�X��L���ɂ���
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
		//�w�i�F
		gl::clear(Color(0, 0, 0));
		//�摜�̓�����
		gl::enableAlphaBlending();

		//���_�ۑ��ƕύX
		gl::pushModelView();
		gl::translate(getWindowCenter());

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
