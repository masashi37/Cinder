
//
// �^�C�g�� �F Arrow
//

#include "common.h"
#include "scene.h"


class Main : public AppNative {

private:

	audio::BufferPlayerNodeRef bgm;
	audio::GainNodeRef gain;

	Font font;

	Vec2f volume_pos = { -WIDTH / 2, HEIGHT / 2 };

	bool volume_is_show = false;
	bool is_start_bgm = false;

	int show_time = 0;

	float volume = 0.5f;

	cScene scene;
	cArrow arrow;

public:

	void setup(){

		//�V�[�����̏�����
		scene.init();

		//�E�B���h�E�T�C�Y
		setWindowSize(WIDTH, HEIGHT);

		//�����_���̃p�^�[����������
		Rand::randomize();

		//�t�H���g
		font = Font(loadAsset("font/HoboStd.otf"), 20);

		//�T�E���h
		//------------------------------

		// �o�̓f�o�C�X���Q�b�g
		auto ctx = audio::Context::master();

		// �I�[�f�B�I�f�[�^��ǂݍ���ŏ�����
		audio::SourceFileRef sourceFile = audio::load(loadAsset("bgm/zombie_rock.wav"));
		audio::BufferRef buffer = sourceFile->loadBuffer();
		bgm = ctx->makeNode(new audio::BufferPlayerNode(buffer));
		gain = ctx->makeNode(new audio::GainNode(volume));
		// �ǂݍ��񂾃I�[�f�B�I���o�̓f�o�C�X�Ɋ֘A�t���Ă���
		bgm >> gain >> ctx->getOutput();

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

		gain->setValue(volume);

		if (volume_is_show){
			show_time++;
			if (show_time > 60){
				show_time = 0;
				volume_is_show = false;
			}
		}

	};

	void draw(){
		//�w�i�F
		gl::clear(Color(0.1f, 0.1f, 0.1f));
		//�摜�̓�����
		gl::enableAlphaBlending();

		//���_�ۑ��ƕύX
		gl::pushModelView();
		gl::translate(getWindowCenter());

		scene.draw();

		//�{�����[��
		if (volume_is_show){
			gl::drawSolidCircle(volume_pos, volume * 100);
			gl::drawString("volume",
				Vec2f(volume_pos.x, HEIGHT / 2 - 30), Color(1, 0, 0), font);
		}
		else{
			gl::drawString("volume : [z] & [x]",
				Vec2f(volume_pos.x, HEIGHT / 2 - 30), Color(1, 0, 0), font);
		}

		//���_��A
		gl::popModelView();
	};

	void keyDown(KeyEvent event){

		if (event.getCode() == KeyEvent::KEY_x){
			if (volume >= 0.0f){
				volume_is_show = true;
				volume += 0.1f;
				scene.enemy_breaker.volume += 0.1f;
				scene.enemy_breaker2.volume += 0.1f;
			}
			if (volume > 1.0f)volume = 1.0f;
			if (scene.enemy_breaker.volume > 1.0f)scene.enemy_breaker.volume = 1.0f;
			if (scene.enemy_breaker2.volume > 1.0f)scene.enemy_breaker2.volume = 1.0f;
		}

		if (event.getCode() == KeyEvent::KEY_z){
			if (volume <= 1.0f){
				volume_is_show = true;
				volume -= 0.1f;
				scene.enemy_breaker.volume -= 0.1f;
				scene.enemy_breaker2.volume -= 0.1f;
			}
			if (volume < 0.0f)volume = 0.0f;
			if (scene.enemy_breaker.volume < 0.0f)scene.enemy_breaker.volume = 0.0f;
			if (scene.enemy_breaker2.volume < 0.0f)scene.enemy_breaker2.volume = 0.0f;
		}

		scene.keyDown(event);
	};

	void keyUp(KeyEvent event){
		scene.keyUp(event);
	};

};

CINDER_APP_NATIVE(Main, RendererGl)
